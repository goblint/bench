>[Warning][Race] Memory location buf_is_full@/home/evalpet/bench/concrat/EasyLogger/main.c:1277:14-1277:36 (race with conf. 110):
  write with [region:{buf_is_full}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1325:5-1325:27)
  write with [region:{buf_is_full}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, lock:{output_lock}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1325:5-1325:27)
  write with [region:{buf_is_full}, mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1374:3-1374:25)
  write with [region:{buf_is_full}, mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, lock:{output_lock}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1374:3-1374:25)
  read with [region:{buf_is_full}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1288:7-1288:20)
  read with [region:{buf_is_full}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, lock:{output_lock}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1288:7-1288:20)
  read with [region:{buf_is_full}, mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1288:7-1288:20)
  read with [region:{buf_is_full}, mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, lock:{output_lock}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1288:7-1288:20)
  read with [region:{buf_is_full}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1296:7-1296:18)
  read with [region:{buf_is_full}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, lock:{output_lock}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1296:7-1296:18)
  read with [region:{buf_is_full}, mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1296:7-1296:18)
  read with [region:{buf_is_full}, mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, lock:{output_lock}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1296:7-1296:18)

Data race identified potentially correctly. The thread waits for a semaphore that is not yet enabled, but the semaphore is not analyzed so it is hard to say for sure.

---

>[Warning][Race] Memory location fp@/home/evalpet/bench/concrat/EasyLogger/main.c:1505:13-1505:38 (race with conf. 110):
  write with [region:{fp}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1577:3-1577:87)
  write with [region:{fp}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, lock:{output_lock}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1577:3-1577:87)
  write with [region:{fp}, mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1577:3-1577:87)
  write with [region:{fp}, mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, lock:{output_lock}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1577:3-1577:87)
  read with [region:{fp}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1548:3-1548:13)
  read with [region:{fp}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, lock:{output_lock}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1548:3-1548:13)
  read with [region:{fp}, mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1548:3-1548:13)
  read with [region:{fp}, mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, lock:{output_lock}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1548:3-1548:13)
  read with [region:{fp}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1615:3-1615:19)
  read with [region:{fp}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, lock:{output_lock}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1615:3-1615:19)
  read with [region:{fp}, mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1615:3-1615:19)
  read with [region:{fp}, mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, lock:{output_lock}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1615:3-1615:19)
  read with [region:{fp}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1616:3-1616:18)
  read with [region:{fp}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, lock:{output_lock}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1616:3-1616:18)
  read with [region:{fp}, mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1616:3-1616:18)
  read with [region:{fp}, mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, lock:{output_lock}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1616:3-1616:18)
  read with [region:{fp}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1625:3-1625:82)
  read with [region:{fp}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, lock:{output_lock}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1625:3-1625:82)
  read with [region:{fp}, mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1625:3-1625:82)
  read with [region:{fp}, mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, lock:{output_lock}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1625:3-1625:82)
  read with [region:{fp}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1626:3-1626:13)
  read with [region:{fp}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, lock:{output_lock}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1626:3-1626:13)
  read with [region:{fp}, mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1626:3-1626:13)
  read with [region:{fp}, mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, lock:{output_lock}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1626:3-1626:13)

Data race identified incorrectly. Program uses library function semop() for mutex locking, unlocking and initialization.

---

>[Warning][Race] Memory location read_index@/home/evalpet/bench/concrat/EasyLogger/main.c:1276:15-1276:38 (race with conf. 110):
  write with [region:{read_index}, mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1366:5-1366:23)
  write with [region:{read_index}, mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, lock:{output_lock}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1366:5-1366:23)
  write with [region:{read_index}, mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1372:5-1372:33)
  write with [region:{read_index}, mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, lock:{output_lock}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1372:5-1372:33)
  read with [region:{read_index}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1285:7-1285:31)
  read with [region:{read_index}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, lock:{output_lock}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1285:7-1285:31)
  read with [region:{read_index}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1286:5-1286:38)
  read with [region:{read_index}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, lock:{output_lock}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1286:5-1286:38)
  read with [region:{read_index}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1290:7-1290:52)
  read with [region:{read_index}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, lock:{output_lock}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1290:7-1290:52)

Data race identified potentially correctly. The thread waits for a semaphore that is not yet enabled, but the semaphore is not analysed so it is hard to say for sure.

---

>[Warning][Race] Memory location elog.output_is_locked_before_disable@/home/evalpet/bench/concrat/EasyLogger/main.c:248:19-248:24 (race with conf. 110):
  write with [region:{elog}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:279:3-279:50)
  write with [region:{elog}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, lock:{output_lock}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:279:3-279:50)
  write with [region:{elog}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, lock:{output_lock}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:474:5-474:52)
  write with [region:{elog}, mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, lock:{output_lock}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:474:5-474:52)
  write with [region:{elog}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:488:5-488:52)
  write with [region:{elog}, mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:488:5-488:52)
  read with [region:{elog}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:929:9-929:47)
  read with [region:{elog}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:937:9-937:45)

Data race identified potentially correctly. The thread waits for a semaphore that is not yet enabled, but the semaphore is not analysed so it is hard to say for sure.

---

>[Warning][Race] Memory location elog.output_is_locked_before_enable@/home/evalpet/bench/concrat/EasyLogger/main.c:248:19-248:24 (race with conf. 110):
  write with [region:{elog}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:278:3-278:49)
  write with [region:{elog}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, lock:{output_lock}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:278:3-278:49)
  write with [region:{elog}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:476:5-476:51)
  write with [region:{elog}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, lock:{output_lock}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:476:5-476:51)
  write with [region:{elog}, mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:476:5-476:51)
  write with [region:{elog}, mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, lock:{output_lock}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:476:5-476:51)
  write with [region:{elog}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:490:5-490:51)
  write with [region:{elog}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, lock:{output_lock}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:490:5-490:51)
  write with [region:{elog}, mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:490:5-490:51)
  write with [region:{elog}, mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, lock:{output_lock}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:490:5-490:51)
  read with [region:{elog}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:930:11-930:46)
  read with [region:{elog}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:938:11-938:48)

Data race identified potentially correctly. The thread waits for a semaphore that is not yet enabled, but the semaphore is not analysed so it is hard to say for sure.

---

>[Warning][Race] Memory location log_buf___0[?]@/home/evalpet/bench/concrat/EasyLogger/main.c:1274:13-1274:43 (race with conf. 110):
  write with [mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1328:5-1329:17)
  write with [mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, lock:{output_lock}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1328:5-1329:17)
  write with [mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1332:5-1333:34)
  write with [mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, lock:{output_lock}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1332:5-1333:34)
  write with [mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1334:5-1335:43)
  write with [mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, lock:{output_lock}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1334:5-1335:43)
  read with [mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1364:5-1365:17)
  read with [mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, lock:{output_lock}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1364:5-1365:17)
  read with [mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1368:5-1369:33)
  read with [mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, lock:{output_lock}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1368:5-1369:33)
  read with [mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1370:5-1371:42)
  read with [mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, lock:{output_lock}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1370:5-1371:42)

Data race identified potentially correctly. The thread waits for a semaphore that is not yet enabled, but the semaphore is not analysed so it is hard to say for sure.

---

>[Warning][Race] Memory location write_index@/home/evalpet/bench/concrat/EasyLogger/main.c:1275:15-1275:39 (race with conf. 110):
  write with [region:{write_index}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1330:5-1330:24)
  write with [region:{write_index}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, lock:{output_lock}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1330:5-1330:24)
  write with [region:{write_index}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1336:5-1336:34)
  write with [region:{write_index}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, lock:{output_lock}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1336:5-1336:34)
  read with [region:{write_index}, mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1285:7-1285:31)
  read with [region:{write_index}, mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, lock:{output_lock}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1285:7-1285:31)
  read with [region:{write_index}, mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1286:5-1286:38)
  read with [region:{write_index}, mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, lock:{output_lock}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1286:5-1286:38)
  read with [region:{write_index}, mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1290:7-1290:52)
  read with [region:{write_index}, mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, lock:{output_lock}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1290:7-1290:52)


Data race identified potentially correctly. The thread waits for a semaphore that is not yet enabled, but the semaphore is not analysed so it is hard to say for sure.

---

>[Warning][Race] Memory location buf_is_empty@/home/evalpet/bench/concrat/EasyLogger/main.c:1278:14-1278:37 (race with conf. 110):
  write with [region:{buf_is_empty}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1338:3-1338:26)
  write with [region:{buf_is_empty}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, lock:{output_lock}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1338:3-1338:26)
  write with [region:{buf_is_empty}, mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1361:5-1361:28)
  write with [region:{buf_is_empty}, mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, lock:{output_lock}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1361:5-1361:28)
  read with [region:{buf_is_empty}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1289:9-1289:23)
  read with [region:{buf_is_empty}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, lock:{output_lock}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1289:9-1289:23)
  read with [region:{buf_is_empty}, mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1289:9-1289:23)
  read with [region:{buf_is_empty}, mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, lock:{output_lock}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:1289:9-1289:23)

Data race identified potentially correctly. The thread waits for a semaphore that is not yet enabled, but the semaphore is not analysed so it is hard to say for sure.

---

>[Warning][Race] Memory location elog.output_lock_enabled@/home/evalpet/bench/concrat/EasyLogger/main.c:248:19-248:24 (race with conf. 110):
  write with [region:{elog}, mhp:{tid=[main]; created={[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}}, thread:[main]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:927:3-927:37)
  read with [region:{elog}, mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:472:7-472:31)
  read with [region:{elog}, mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, lock:{output_lock}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:472:7-472:31)
  read with [region:{elog}, mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:486:7-486:31)
  read with [region:{elog}, mhp:{tid=[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]}, lock:{output_lock}, thread:[main, async_output@/home/evalpet/bench/concrat/EasyLogger/main.c:1460:3-1461:66]] (conf. 110) (/home/evalpet/bench/concrat/EasyLogger/main.c:486:7-486:31)

Data race identified potentially correctly. The thread waits for a semaphore that is not yet enabled, but the semaphore is not analysed so it is hard to say for sure.

---

Option *--disable ana.race.free* was used for Goblint execution.