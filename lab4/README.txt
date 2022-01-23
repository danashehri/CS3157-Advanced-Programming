This file should contain:

  - Name: Dana AlShehri
  - UNI: da2975
  - Lab4
  - Description for Part 1:
My code works exactly as specified in the lab for mdb-lookup, however I have ran into some issues with valgrind output in which it would display me this message "Conditional jump or move depends on uninitialised value(s)" whenever it reads from keyboard input a string greater than 5 characters. I tried to address this issue by re-arranging and modifying my definiton for the search string and buffer used and it did the trick, but I'm not sure if this would still work regardless of the length of keyboard input string.  

  - List for Part 1(a):
 389: {Dana} said {Hello AP!}
 584: {Dana AlShehri} said {I love programming <3}

Valgrind Output for Part1:

==9416== Memcheck, a memory error detector
==9416== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==9416== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==9416== Command: ./mdb-lookup my-mdb
==9416== 
lookup:  1: {Dana AlShehri} said {First record!} 
 2: {Dana AlShehri} said {record 3} 
 3: {Dana AlShehri} said {Hello!!!!} 

lookup:  1: {Dana AlShehri} said {First record!} 
 2: {Dana AlShehri} said {record 3} 
 3: {Dana AlShehri} said {Hello!!!!} 

lookup:  1: {Dana AlShehri} said {First record!} 
 2: {Dana AlShehri} said {record 3} 
 3: {Dana AlShehri} said {Hello!!!!} 

lookup:  3: {Dana AlShehri} said {Hello!!!!} 

lookup:  1: {Dana AlShehri} said {First record!} 
 2: {Dana AlShehri} said {record 3} 
 3: {Dana AlShehri} said {Hello!!!!} 
 4: {Sarah} said {hello world hello world} 
 5: {Adam} said {This is Adam} 
 6: {Amal} said {Testing message} 

lookup: ==9416== 
==9416== HEAP SUMMARY:
==9416==     in use at exit: 0 bytes in 0 blocks
==9416==   total heap usage: 16 allocs, 16 frees, 3,448 bytes allocated
==9416== 
==9416== All heap blocks were freed -- no leaks are possible
==9416== 
==9416== For counts of detected and suppressed errors, rerun with: -v
==9416== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
