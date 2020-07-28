(* This script parses the logs in out/{coreutils,single-thread} and prints the results as CSV. *)
(* Dependencies: opam install ocamlfind batteries *)
(* Run with: ocaml parallel-csv.ml *)
#use "topfind"
#require "str"
#require "batteries"
open Batteries

let list_files ?suffix dir =
  Sys.readdir dir |> Array.to_list |> List.sort compare |> List.map (Filename.concat dir)
  |> match suffix with None -> fun x -> x | Some suffix -> let l = String.length suffix in List.filter (fun x -> Str.last_chars x l = suffix)

type run = { file: string; lines: string; start_time: string; cpu_time: string; cpu_per: string; max_mem: string; vars: string; evals: string; rho: string; stable: string; infl: string; wpoint: string; error: string }
let empty_run = { file = ""; lines = ""; start_time = ""; cpu_time = ""; cpu_per = ""; max_mem = ""; vars = ""; evals = ""; rho = ""; stable = ""; infl = ""; wpoint = ""; error = "" }

let print_csv xs = print_endline (String.concat ", " xs)
let print_headers () = print_csv ["file"; "lines (_comb.c)"; "start_time"; "cpu_time (hh:mm:ss)"; "cpu_per"; "max_mem (kb)"; "vars"; "evals"; "rho"; "stable"; "infl"; "wpoint"; "error"]
let print_run x = print_csv [x.file; x.lines; x.start_time; x.cpu_time; x.cpu_per; x.max_mem; x.vars; x.evals; x.rho; x.stable; x.infl; x.wpoint; x.error]

let re_vars = Str.regexp "vars = \\([0-9]+\\).*"
let re_evals = Str.regexp ".*evals = \\([0-9]+\\).*"

let csv file =
  let open String in
  let c_file = "../" ^ fst (split file ".c.") ^ ".c" in
  let loc = fst @@ split (snd @@ Unix.run_and_read ("wc -l " ^ c_file)) " " in
  let lines = File.lines_of file in
  let run = { empty_run with file; lines = loc; start_time = Option.get (Enum.get lines) } in
  let parse_line run line =
    if starts_with line "\tElapsed (wall clock) time" then
      let cpu_time = snd @@ split line "): " in
      let cpu_time = try fst @@ split cpu_time "." with Not_found -> cpu_time in (* LibreOffice does not treat it as time with .12 sub-second part, so we remove it *)
      let cpu_time = rchop ~n:(String.length cpu_time) "00:00:00" ^ cpu_time in (* LibreOffice parses 1:23 as 1:23:00, so we left-pad zeros *)
      { run with cpu_time }
    else if starts_with line "\tPercent of CPU this job got" then
      { run with cpu_per = snd @@ split line ": " }
    else if starts_with line "\tMaximum resident set size" then (* https://stackoverflow.com/questions/774556/peak-memory-usage-of-a-linux-unix-process *)
      { run with max_mem = snd @@ split line "): " }
    (* sequence 'Fatal error: out of memory\nCommand terminated by signal 6' should be saved as first line, so we only overwrite error if it's empty. *)
    else if run.error = "" && starts_with line "Command terminated by signal" then
      { run with error = line }
    else if starts_with line "Fatal error" then
      { run with error = line }
    else if starts_with line "vars = " then
      let open Str in
      let vars = replace_first re_vars "\\1" line in
      let evals = replace_first re_evals "\\1" line in
      { run with vars; evals }
    else if starts_with line "|rho|=" then { run with rho = snd @@ split line "=" }
    else if starts_with line "|stable|=" then { run with stable = snd @@ split line "=" }
    else if starts_with line "|infl|=" then { run with infl = snd @@ split line "=" }
    else if starts_with line "|wpoint|=" then { run with wpoint = snd @@ split line "=" }
    else
      run
  in
  print_run @@ Enum.fold parse_line run lines

let () =
  (* let input_files = list_files ~suffix:".c" "coreutils" @ list_files ~suffix:".c" "single-thread" in *)
  (* List.iter print_endline input_files; *)
  Sys.chdir "out";
  let input_files = list_files ~suffix:".log" "coreutils" @ list_files ~suffix:".log" "single-thread" in
  print_headers ();
  List.iter csv input_files
