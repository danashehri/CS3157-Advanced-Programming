This file should contain:

  - Dana AlShehri
  - da2975
  - Lab #3
  - Description for Part 1:
My code works works exactly as specified in the lab. 
 
  - Description for Part 2:
My code works works exactly as specified in the lab. In an attempt to make the program print "dude found" or "dude not found" I wrote a function called CompareString() that's taken as a paramter into findNode() function. Inside CompareString(), I had strcmp work there in which it would update a global variable "result" and depending on the value of that global variable the program prints either "dude found" or "dude not found". 

  - Valgrind Output for Part 1:
 
==13769== Memcheck, a memory error detector
==13769== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==13769== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==13769== Command: ./mylist-test
==13769== 
testing addFront(): 9.0 8.0 7.0 6.0 5.0 4.0 3.0 2.0 1.0 
testing flipSignDouble(): -9.0 -8.0 -7.0 -6.0 -5.0 -4.0 -3.0 -2.0 -1.0 
testing flipSignDouble() again: 9.0 8.0 7.0 6.0 5.0 4.0 3.0 2.0 1.0 
testing findNode(): OK
popped 9.0, the rest is: [ 8.0 7.0 6.0 5.0 4.0 3.0 2.0 1.0 ]
popped 8.0, the rest is: [ 7.0 6.0 5.0 4.0 3.0 2.0 1.0 ]
popped 7.0, the rest is: [ 6.0 5.0 4.0 3.0 2.0 1.0 ]
popped 6.0, the rest is: [ 5.0 4.0 3.0 2.0 1.0 ]
popped 5.0, the rest is: [ 4.0 3.0 2.0 1.0 ]
popped 4.0, the rest is: [ 3.0 2.0 1.0 ]
popped 3.0, the rest is: [ 2.0 1.0 ]
popped 2.0, the rest is: [ 1.0 ]
popped 1.0, the rest is: [ ]
testing addAfter(): 1.0 2.0 3.0 4.0 5.0 6.0 7.0 8.0 9.0 
popped 1.0, and reversed the rest: [ 9.0 8.0 7.0 6.0 5.0 4.0 3.0 2.0 ]
popped 9.0, and reversed the rest: [ 2.0 3.0 4.0 5.0 6.0 7.0 8.0 ]
popped 2.0, and reversed the rest: [ 8.0 7.0 6.0 5.0 4.0 3.0 ]
popped 8.0, and reversed the rest: [ 3.0 4.0 5.0 6.0 7.0 ]
popped 3.0, and reversed the rest: [ 7.0 6.0 5.0 4.0 ]
popped 7.0, and reversed the rest: [ 4.0 5.0 6.0 ]
popped 4.0, and reversed the rest: [ 6.0 5.0 ]
popped 6.0, and reversed the rest: [ 5.0 ]
popped 5.0, and reversed the rest: [ ]
==13769== 
==13769== HEAP SUMMARY:
==13769==     in use at exit: 0 bytes in 0 blocks
==13769==   total heap usage: 19 allocs, 19 frees, 1,312 bytes allocated
==13769== 
==13769== All heap blocks were freed -- no leaks are possible
==13769== 
==13769== For counts of detected and suppressed errors, rerun with: -v
==13769== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

  - Valgrind Output for Part 2:

    1) When command runs: ./revecho

==5712== Memcheck, a memory error detector
==5712== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==5712== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==5712== Command: ./revecho
==5712== 

dude not found
==5712== 
==5712== HEAP SUMMARY:
==5712==     in use at exit: 0 bytes in 0 blocks
==5712==   total heap usage: 1 allocs, 1 frees, 3,072 bytes allocated
==5712== 
==5712== All heap blocks were freed -- no leaks are possible
==5712== 
==5712== For counts of detected and suppressed errors, rerun with: -v
==5712== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

    2) When command runs: ./revecho hello world dude

==8143== Memcheck, a memory error detector
==8143== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==8143== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==8143== Command: ./revecho hello world dude
==8143== 
dude 
world 
hello 

dude found
==8143== 
==8143== HEAP SUMMARY:
==8143==     in use at exit: 0 bytes in 0 blocks
==8143==   total heap usage: 4 allocs, 4 frees, 3,632 bytes allocated
==8143== 
==8143== All heap blocks were freed -- no leaks are possible
==8143== 
==8143== For counts of detected and suppressed errors, rerun with: -v
==8143== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

    3) When command runs: ./revecho hello world friend

==11811== Memcheck, a memory error detector
==11811== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==11811== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==11811== Command: ./revecho hello world friend
==11811== 
friend 
world 
hello 

dude not found
==11811== 
==11811== HEAP SUMMARY:
==11811==     in use at exit: 0 bytes in 0 blocks
==11811==   total heap usage: 4 allocs, 4 frees, 4,656 bytes allocated
==11811== 
==11811== All heap blocks were freed -- no leaks are possible
==11811== 
==11811== For counts of detected and suppressed errors, rerun with: -v
==11811== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
