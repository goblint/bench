>[Warning][Race] Memory location (struct worker).result.size (race with conf. 100):
  write with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1802:5-1802:72)
  write with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1802:5-1802:72)
  read with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1802:5-1802:72)
  read with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1802:5-1802:72)
  read with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1802:5-1802:72)
  read with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1802:5-1802:72)
[Warning][Race] Memory location (struct result_list).size (race with conf. 100):
  write with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1783:10-1783:26)
  write with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1783:10-1783:26)
  read with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1781:10-1781:63)
  read with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1781:10-1781:63)
  read with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1782:10-1782:85)
  read with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1782:10-1782:85)
  read with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1783:10-1783:26)
  read with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1783:10-1783:26)
  read with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1788:3-1788:88)
  read with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1788:3-1788:88)

Data race identified incorrectly, the thread is tied to a struct

---

>[Warning][Race] Memory location (struct worker).result.size (race with conf. 100):
  write with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1802:5-1802:72)
  write with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1802:5-1802:72)
  read with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1802:5-1802:72)
  read with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1802:5-1802:72)
  read with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1802:5-1802:72)
  read with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1802:5-1802:72)

Data race identified incorrectly, the thread is tied to a struct

---

>[Warning][Race] Memory location choices.size@/home/evalpet/bench/concrat/fzy/main.c:548:13-548:21 (race with conf. 110):
  read with [symblock:{p-lock:*.lock}, mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}}] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1674:7-1674:44)
  read with [symblock:{p-lock:*.lock}, mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1674:7-1674:44)
  read with [symblock:{p-lock:*.lock}, mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}}] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1675:5-1675:42)
  read with [symblock:{p-lock:*.lock}, mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1675:5-1675:42)
  write with [mhp:{tid=[main]; created={[main, handle_sigwinch@/home/evalpet/bench/concrat/fzy/main.c:1188:3-1188:32], [main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/fzy/main.c:1633:3-1633:16)

Data race identified incorrectly, the data is written in the end of the code where a thread can be already joined

---

>[Warning][Race] Memory location (struct worker).result.list (race with conf. 100):
  write with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1802:5-1802:72)
  write with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1802:5-1802:72)
  read with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1802:5-1802:72)
  read with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1802:5-1802:72)
  read with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1802:5-1802:72)
  read with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1802:5-1802:72)

Data race identified incorrectly, the thread is tied to a struct

---

>[Warning][Race] Memory location ((alloc@sid:801@tid:\[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64](#top)), /home/evalpet/bench/concrat/fzy/main.c:1705:3-1705:44)[?]@/home/evalpet/bench/concrat/fzy/main.c:1705:3-1705:44 (race with conf. 100):
  write with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (lib/libc/stub/src/stdlib.c:25:11-25:18)
  write with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (lib/libc/stub/src/stdlib.c:25:11-25:18)
  write with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (lib/libc/stub/src/stdlib.c:26:11-26:17)
  write with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (lib/libc/stub/src/stdlib.c:26:11-26:17)
  read with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1724:7-1724:57)
  read with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1724:7-1724:57)
  read with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1730:7-1730:57)
  read with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1730:7-1730:57)
  read with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1738:5-1738:55)
  read with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1738:5-1738:55)
  read with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1745:5-1745:55)
  read with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1745:5-1745:55)
  read with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (lib/libc/stub/src/stdlib.c:24:16-24:22)
  read with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (lib/libc/stub/src/stdlib.c:24:16-24:22)
  read with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (lib/libc/stub/src/stdlib.c:25:11-25:18)
  read with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (lib/libc/stub/src/stdlib.c:25:11-25:18)

Data race identified incorrectly, as the memory that is being read is isolated to a thread

---

>[Warning][Race] Memory location ((alloc@sid:942@tid:\[main](#top)), /home/evalpet/bench/concrat/fzy/main.c:1841:6-1841:65)[?].str@/home/evalpet/bench/concrat/fzy/main.c:1841:6-1841:65 (race with conf. 100):
  write with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1781:10-1781:63)
  write with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1781:10-1781:63)
  read with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1480:9-1480:56)
  read with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1480:9-1480:56)
  read with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1480:9-1480:56)
  read with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1480:9-1480:56)
  read with [mhp:{tid=[main]; created={[main, handle_sigwinch@/home/evalpet/bench/concrat/fzy/main.c:1188:3-1188:32], [main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}}, thread:[main]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1872:5-1872:35)
  read with [mhp:{tid=[main]; created={[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}}, thread:[main]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1872:5-1872:35)

Data race identified incorrectly, the thread is tied to a struct

---

>[Warning][Race] Memory location ((alloc@sid:801@tid:[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}(#top)), /home/evalpet/bench/concrat/fzy/main.c:1705:3-1705:44)[?].score@/home/evalpet/bench/concrat/fzy/main.c:1705:3-1705:44 (race with conf. 100):
  write with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1782:10-1782:85)
  write with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1782:10-1782:85)
  read with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1479:7-1479:27)
  read with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1479:7-1479:27)
  read with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1479:7-1479:27)
  read with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1479:7-1479:27)
  read with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1486:7-1486:26)
  read with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1486:7-1486:26)
  read with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1486:7-1486:26)
  read with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1486:7-1486:26)
  read with [mhp:{tid=[main]; created={[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}}, thread:[main]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1883:3-1883:35)

Data race identified incorrectly, the thread is tied to a struct

---

>[Warning][Race] Memory location tty_interface.search[?]@/home/evalpet/bench/concrat/fzy/main.c:560:19-560:33 (race with conf. 110):
  read with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 80) (/home/evalpet/bench/concrat/fzy/main.c:796:3-796:23)
  read with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 80) (/home/evalpet/bench/concrat/fzy/main.c:796:3-796:23)
  write with [mhp:{tid=[main]; created={[main, handle_sigwinch@/home/evalpet/bench/concrat/fzy/main.c:1188:3-1188:32], [main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}}, thread:[main]] (conf. 90) (/home/evalpet/bench/concrat/fzy/main.c:2344:3-2345:44)
  write with [mhp:{tid=[main]; created={[main, handle_sigwinch@/home/evalpet/bench/concrat/fzy/main.c:1188:3-1188:32], [main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}}, thread:[main]] (conf. 90) (/home/evalpet/bench/concrat/fzy/main.c:2383:3-2384:45)
  write with [mhp:{tid=[main]; created={[main, handle_sigwinch@/home/evalpet/bench/concrat/fzy/main.c:1188:3-1188:32], [main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}}, thread:[main]] (conf. 90) (/home/evalpet/bench/concrat/fzy/main.c:2395:3-2396:39)
  write with [mhp:{tid=[main]; created={[main, handle_sigwinch@/home/evalpet/bench/concrat/fzy/main.c:1188:3-1188:32], [main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}}, thread:[main]] (conf. 90) (/home/evalpet/bench/concrat/fzy/main.c:2571:5-2572:49)
  spawn with [mhp:{tid=[main]; created={[main, handle_sigwinch@/home/evalpet/bench/concrat/fzy/main.c:1188:3-1188:32], [main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}}, thread:[main]] (conf. 90) (/home/evalpet/bench/concrat/fzy/main.c:2344:3-2345:44)
  spawn with [mhp:{tid=[main]; created={[main, handle_sigwinch@/home/evalpet/bench/concrat/fzy/main.c:1188:3-1188:32], [main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}}, thread:[main]] (conf. 90) (/home/evalpet/bench/concrat/fzy/main.c:2383:3-2384:45)
  spawn with [mhp:{tid=[main]; created={[main, handle_sigwinch@/home/evalpet/bench/concrat/fzy/main.c:1188:3-1188:32], [main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}}, thread:[main]] (conf. 90) (/home/evalpet/bench/concrat/fzy/main.c:2395:3-2396:39)
  spawn with [mhp:{tid=[main]; created={[main, handle_sigwinch@/home/evalpet/bench/concrat/fzy/main.c:1188:3-1188:32], [main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}}, thread:[main]] (conf. 90) (/home/evalpet/bench/concrat/fzy/main.c:2571:5-2572:49)
  read with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:751:10-751:17)
  read with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:751:10-751:17)
  read with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:754:5-754:22)
  read with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:754:5-754:22)
  read with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:808:9-808:36)
  read with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:808:9-808:36)
  read with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:812:7-812:54)
  read with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:812:7-812:54)
  read with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:918:7-918:16)
  read with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:918:7-918:16)
  write with [mhp:{tid=[main]; created={[main, handle_sigwinch@/home/evalpet/bench/concrat/fzy/main.c:1188:3-1188:32], [main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/fzy/main.c:2542:5-2543:27)
  write with [mhp:{tid=[main]; created={[main, handle_sigwinch@/home/evalpet/bench/concrat/fzy/main.c:1188:3-1188:32], [main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/fzy/main.c:2573:5-2573:35)

Data race identified possibly correctly, the thread joining scheme is too complex for manual check

---

>[Warning][Race] Memory location (struct scored_result).score (race with conf. 100):
  write with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1782:10-1782:85)
  write with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1782:10-1782:85)
  read with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1479:7-1479:27)
  read with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1479:7-1479:27)
  read with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1479:7-1479:27)
  read with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1479:7-1479:27)
  read with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1486:7-1486:26)
  read with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1486:7-1486:26)
  read with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1486:7-1486:26)
  read with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1486:7-1486:26)
  read with [mhp:{tid=[main]; created={[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}}, thread:[main]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1883:3-1883:35)

Data race identified possibly correctly, the thread joining scheme is too complex for manual check

---

>[Warning][Race] Memory location ((alloc@sid:801@tid:\[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64](#top)), /home/evalpet/bench/concrat/fzy/main.c:1705:3-1705:44)[?].str@/home/evalpet/bench/concrat/fzy/main.c:1705:3-1705:44 (race with conf. 100):
  write with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1781:10-1781:63)
  write with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1781:10-1781:63)
  read with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1480:9-1480:56)
  read with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1480:9-1480:56)
  read with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1480:9-1480:56)
  read with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1480:9-1480:56)
  read with [mhp:{tid=[main]; created={[main, handle_sigwinch@/home/evalpet/bench/concrat/fzy/main.c:1188:3-1188:32], [main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}}, thread:[main]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1872:5-1872:35)
  read with [mhp:{tid=[main]; created={[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}}, thread:[main]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1872:5-1872:35)

Data race identified possibly correctly, the thread joining scheme is too complex for manual check

---

>[Warning][Race] Memory location choices.strings@/home/evalpet/bench/concrat/fzy/main.c:548:13-548:21 (race with conf. 110):
  read with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1779:7-1779:54)
  read with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1779:7-1779:54)
  read with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1781:10-1781:63)
  read with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1781:10-1781:63)
  read with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1782:10-1782:85)
  read with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1782:10-1782:85)
  write with [mhp:{tid=[main]; created={[main, handle_sigwinch@/home/evalpet/bench/concrat/fzy/main.c:1188:3-1188:32], [main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/fzy/main.c:1631:3-1631:42)

Data race identified possibly correctly, the thread joining scheme is too complex for manual check

---

>[Warning][Race] Memory location ((alloc@sid:801@tid:\[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64](#top)), /home/evalpet/bench/concrat/fzy/main.c:1705:3-1705:44)[?].score@/home/evalpet/bench/concrat/fzy/main.c:1705:3-1705:44 (race with conf. 100):
  write with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1782:10-1782:85)
  write with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1782:10-1782:85)
  read with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1479:7-1479:27)
  read with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1479:7-1479:27)
  read with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1479:7-1479:27)
  read with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1479:7-1479:27)
  read with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1486:7-1486:26)
  read with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1486:7-1486:26)
  read with mhp:{tid=[main], {choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64}} (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1486:7-1486:26)
  read with [mhp:{tid=[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}, thread:[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1486:7-1486:26)
  read with [mhp:{tid=[main]; created={[main, choices_search_worker@/home/evalpet/bench/concrat/fzy/main.c:1843:5-1845:64]}}, thread:[main]] (conf. 100) (/home/evalpet/bench/concrat/fzy/main.c:1883:3-1883:35)

Data race identified possibly correctly, the thread joining scheme is too complex for manual check

---

Option *--disable ana.race.free* was used for Goblint execution.