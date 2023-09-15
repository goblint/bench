>[Warning][Race] Memory location threadCountAliveNow@/home/evalpet/bench/concrat/snoopy/main.c:3067:5-3067:28 (race with conf. 110):
  write with [region:{threadCountAliveNow}, mhp:{tid=[main], {snoopyTestCli_action_stress_threads_threadMain@/home/evalpet/bench/concrat/snoopy/main.c:3131:5-3133:55}}, lock:{threadCountMutex}] (conf. 110) (/home/evalpet/bench/concrat/snoopy/main.c:3213:3-3213:25)
  write with [region:{threadCountAliveNow}, mhp:{tid=[main, snoopyTestCli_action_stress_threads_threadMain@/home/evalpet/bench/concrat/snoopy/main.c:3131:5-3133:55]}, lock:{threadCountMutex}, thread:[main, snoopyTestCli_action_stress_threads_threadMain@/home/evalpet/bench/concrat/snoopy/main.c:3131:5-3133:55]] (conf. 110) (/home/evalpet/bench/concrat/snoopy/main.c:3213:3-3213:25)
  write with [region:{threadCountAliveNow}, mhp:{tid=[main], {snoopyTestCli_action_stress_threads_threadMain@/home/evalpet/bench/concrat/snoopy/main.c:3131:5-3133:55}}, lock:{threadCountMutex}] (conf. 110) (/home/evalpet/bench/concrat/snoopy/main.c:3268:3-3268:25)
  write with [region:{threadCountAliveNow}, mhp:{tid=[main, snoopyTestCli_action_stress_threads_threadMain@/home/evalpet/bench/concrat/snoopy/main.c:3131:5-3133:55]}, lock:{threadCountMutex}, thread:[main, snoopyTestCli_action_stress_threads_threadMain@/home/evalpet/bench/concrat/snoopy/main.c:3131:5-3133:55]] (conf. 110) (/home/evalpet/bench/concrat/snoopy/main.c:3268:3-3268:25)
  read with [region:{threadCountAliveNow}, mhp:{tid=[main]; created={[main, snoopyTestCli_action_stress_threads_threadMain@/home/evalpet/bench/concrat/snoopy/main.c:3131:5-3133:55]}}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/snoopy/main.c:3137:3-3138:30)

Data race was identified correctly.

---

>[Warning][Race] Memory location ((alloc@sid:2236@tid:\[main](#top)), /home/evalpet/bench/concrat/snoopy/main.c:3364:5-3364:27).seqNr@/home/evalpet/bench/concrat/snoopy/main.c:3364:5-3364:27 (race with conf. 110):
  free with mhp:{tid=[main], {snoopyTestCli_action_stress_threadsexec_threadMain@/home/evalpet/bench/concrat/snoopy/main.c:3367:5-3369:55}} (conf. 90) (/home/evalpet/bench/concrat/snoopy/main.c:3416:3-3416:22)
  free with [mhp:{tid=[main, snoopyTestCli_action_stress_threadsexec_threadMain@/home/evalpet/bench/concrat/snoopy/main.c:3367:5-3369:55]}, thread:[main, snoopyTestCli_action_stress_threadsexec_threadMain@/home/evalpet/bench/concrat/snoopy/main.c:3367:5-3369:55]] (conf. 90) (/home/evalpet/bench/concrat/snoopy/main.c:3416:3-3416:22)
  read with mhp:{tid=[main], {snoopyTestCli_action_stress_threadsexec_threadMain@/home/evalpet/bench/concrat/snoopy/main.c:3367:5-3369:55}} (conf. 110) (/home/evalpet/bench/concrat/snoopy/main.c:3396:3-3397:27)
  read with [mhp:{tid=[main, snoopyTestCli_action_stress_threadsexec_threadMain@/home/evalpet/bench/concrat/snoopy/main.c:3367:5-3369:55]}, thread:[main, snoopyTestCli_action_stress_threadsexec_threadMain@/home/evalpet/bench/concrat/snoopy/main.c:3367:5-3369:55]] (conf. 110) (/home/evalpet/bench/concrat/snoopy/main.c:3396:3-3397:27)
  read with mhp:{tid=[main], {snoopyTestCli_action_stress_threadsexec_threadMain@/home/evalpet/bench/concrat/snoopy/main.c:3367:5-3369:55}} (conf. 110) (/home/evalpet/bench/concrat/snoopy/main.c:3401:5-3401:91)
  read with [mhp:{tid=[main, snoopyTestCli_action_stress_threadsexec_threadMain@/home/evalpet/bench/concrat/snoopy/main.c:3367:5-3369:55]}, thread:[main, snoopyTestCli_action_stress_threadsexec_threadMain@/home/evalpet/bench/concrat/snoopy/main.c:3367:5-3369:55]] (conf. 110) (/home/evalpet/bench/concrat/snoopy/main.c:3401:5-3401:91)
  read with mhp:{tid=[main], {snoopyTestCli_action_stress_threadsexec_threadMain@/home/evalpet/bench/concrat/snoopy/main.c:3367:5-3369:55}} (conf. 110) (/home/evalpet/bench/concrat/snoopy/main.c:3404:5-3404:92)
  read with [mhp:{tid=[main, snoopyTestCli_action_stress_threadsexec_threadMain@/home/evalpet/bench/concrat/snoopy/main.c:3367:5-3369:55]}, thread:[main, snoopyTestCli_action_stress_threadsexec_threadMain@/home/evalpet/bench/concrat/snoopy/main.c:3367:5-3369:55]] (conf. 110) (/home/evalpet/bench/concrat/snoopy/main.c:3404:5-3404:92)
  read with mhp:{tid=[main], {snoopyTestCli_action_stress_threadsexec_threadMain@/home/evalpet/bench/concrat/snoopy/main.c:3367:5-3369:55}} (conf. 110) (/home/evalpet/bench/concrat/snoopy/main.c:3407:5-3407:90)
  read with [mhp:{tid=[main, snoopyTestCli_action_stress_threadsexec_threadMain@/home/evalpet/bench/concrat/snoopy/main.c:3367:5-3369:55]}, thread:[main, snoopyTestCli_action_stress_threadsexec_threadMain@/home/evalpet/bench/concrat/snoopy/main.c:3367:5-3369:55]] (conf. 110) (/home/evalpet/bench/concrat/snoopy/main.c:3407:5-3407:90)
  read with mhp:{tid=[main], {snoopyTestCli_action_stress_threadsexec_threadMain@/home/evalpet/bench/concrat/snoopy/main.c:3367:5-3369:55}} (conf. 110) (/home/evalpet/bench/concrat/snoopy/main.c:3410:5-3411:29)
  read with [mhp:{tid=[main, snoopyTestCli_action_stress_threadsexec_threadMain@/home/evalpet/bench/concrat/snoopy/main.c:3367:5-3369:55]}, thread:[main, snoopyTestCli_action_stress_threadsexec_threadMain@/home/evalpet/bench/concrat/snoopy/main.c:3367:5-3369:55]] (conf. 110) (/home/evalpet/bench/concrat/snoopy/main.c:3410:5-3411:29)
  read with mhp:{tid=[main], {snoopyTestCli_action_stress_threadsexec_threadMain@/home/evalpet/bench/concrat/snoopy/main.c:3367:5-3369:55}} (conf. 110) (/home/evalpet/bench/concrat/snoopy/main.c:3414:5-3414:81)
  read with [mhp:{tid=[main, snoopyTestCli_action_stress_threadsexec_threadMain@/home/evalpet/bench/concrat/snoopy/main.c:3367:5-3369:55]}, thread:[main, snoopyTestCli_action_stress_threadsexec_threadMain@/home/evalpet/bench/concrat/snoopy/main.c:3367:5-3369:55]] (conf. 110) (/home/evalpet/bench/concrat/snoopy/main.c:3414:5-3414:81)

Data race identified incorrectly, as there are structs created per thread, which means that one thread cant access a struct of another thread

---

>[Warning][Race] Memory location threadCountCreated@/home/evalpet/bench/concrat/snoopy/main.c:3066:5-3066:27 (race with conf. 110):
  write with [region:{threadCountCreated}, mhp:{tid=[main], {snoopyTestCli_action_stress_threads_threadMain@/home/evalpet/bench/concrat/snoopy/main.c:3131:5-3133:55}}, lock:{threadCountMutex}] (conf. 110) (/home/evalpet/bench/concrat/snoopy/main.c:3212:3-3212:24)
  write with [region:{threadCountCreated}, mhp:{tid=[main, snoopyTestCli_action_stress_threads_threadMain@/home/evalpet/bench/concrat/snoopy/main.c:3131:5-3133:55]}, lock:{threadCountMutex}, thread:[main, snoopyTestCli_action_stress_threads_threadMain@/home/evalpet/bench/concrat/snoopy/main.c:3131:5-3133:55]] (conf. 110) (/home/evalpet/bench/concrat/snoopy/main.c:3212:3-3212:24)
  read with [region:{threadCountCreated}, mhp:{tid=[main]; created={[main, snoopyTestCli_action_stress_threads_threadMain@/home/evalpet/bench/concrat/snoopy/main.c:3131:5-3133:55]}}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/snoopy/main.c:3161:3-3162:29)

Data race identified correctly

---

>[Warning][Race] Memory location threadCountAliveMax@/home/evalpet/bench/concrat/snoopy/main.c:3068:5-3068:28 (race with conf. 110):
  write with [region:{threadCountAliveMax}, mhp:{tid=[main], {snoopyTestCli_action_stress_threads_threadMain@/home/evalpet/bench/concrat/snoopy/main.c:3131:5-3133:55}}, lock:{threadCountMutex}] (conf. 110) (/home/evalpet/bench/concrat/snoopy/main.c:3215:5-3215:46)
  write with [region:{threadCountAliveMax}, mhp:{tid=[main, snoopyTestCli_action_stress_threads_threadMain@/home/evalpet/bench/concrat/snoopy/main.c:3131:5-3133:55]}, lock:{threadCountMutex}, thread:[main, snoopyTestCli_action_stress_threads_threadMain@/home/evalpet/bench/concrat/snoopy/main.c:3131:5-3133:55]] (conf. 110) (/home/evalpet/bench/concrat/snoopy/main.c:3215:5-3215:46)
  read with [region:{threadCountAliveMax}, mhp:{tid=[main]; created={[main, snoopyTestCli_action_stress_threads_threadMain@/home/evalpet/bench/concrat/snoopy/main.c:3131:5-3133:55]}}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/snoopy/main.c:3163:3-3164:30)

Data race identified correctly

---

>[Warning][Race] Memory location ((alloc@sid:2050@tid:\[main](#top)), /home/evalpet/bench/concrat/snoopy/main.c:3126:5-3126:31).seqNr@/home/evalpet/bench/concrat/snoopy/main.c:3126:5-3126:31 (race with conf. 110):
  free with mhp:{tid=[main], {snoopyTestCli_action_stress_threads_threadMain@/home/evalpet/bench/concrat/snoopy/main.c:3131:5-3133:55}} (conf. 90) (/home/evalpet/bench/concrat/snoopy/main.c:3270:3-3270:22)
  free with [mhp:{tid=[main, snoopyTestCli_action_stress_threads_threadMain@/home/evalpet/bench/concrat/snoopy/main.c:3131:5-3133:55]}, thread:[main, snoopyTestCli_action_stress_threads_threadMain@/home/evalpet/bench/concrat/snoopy/main.c:3131:5-3133:55]] (conf. 90) (/home/evalpet/bench/concrat/snoopy/main.c:3270:3-3270:22)
  read with mhp:{tid=[main], {snoopyTestCli_action_stress_threads_threadMain@/home/evalpet/bench/concrat/snoopy/main.c:3131:5-3133:55}} (conf. 110) (/home/evalpet/bench/concrat/snoopy/main.c:3208:3-3208:23)
  read with [mhp:{tid=[main, snoopyTestCli_action_stress_threads_threadMain@/home/evalpet/bench/concrat/snoopy/main.c:3131:5-3133:55]}, thread:[main, snoopyTestCli_action_stress_threads_threadMain@/home/evalpet/bench/concrat/snoopy/main.c:3131:5-3133:55]] (conf. 110) (/home/evalpet/bench/concrat/snoopy/main.c:3208:3-3208:23)

Data race identified incorrectly, as there are structs created per thread, which means that one thread can not access a struct of another thread

---

Option *--disable ana.race.free* was used for Goblint execution.