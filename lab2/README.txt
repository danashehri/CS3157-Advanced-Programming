This file should contain:

  - Name: Dana AlShehri
  - UNI: da2975
  - lab#: Lab2
  - Description For Part 1: 
My code for part1 works exactly as specified in the lab. I have utilized two sources from the internet to write the sorting algorithm for both ascending and descending order as cited below. I have used only one c file to have all my code.  

References:
1. Sanfoundry Global Education & Learning Series. (2018). C Program to Sort the Array in an Ascending Order. Retrieved from https://www.sanfoundry.com/c-program-sort-array-ascending-order/

2. Sanfoundry Global Education & Learning Series. (2018). C Program to Sort the Array in an Ascending Order. Retrieved from https://www.sanfoundry.com/c-program-sort-array-descending-order/

  - Description For Part 2:
 I have written the code for part2 but kept having multiple different errors, including segmentation fault errors. I have tried to understand the warnings I have been getting to fix my code and make it work by utilizing the textbook and pre-recorded lectures. The first thing I did in duplicateArgs() is to create a pointer to a memory region that’s the size of the vertical array of type char *. Then in a for loop, I have written code to make a copy of the argv array elements into the new array that’s allocated in memory via malloc() function. I have tested that part of the code via printf() to check that the correct character strings are returned and it worked. After that, I tried to access each character string in the copied version of argv to perform the toupper() operation on. However, I struggled in addressing the warning titled “assignment makes integer from pointer without a cast”. By trial and error, I managed to modify my code without receiving that same warning again. However, the executable code gave a null value and segmentation fault error that I was not sure how to fix. Moreover, I didn't understand when and where to address the null pointer in the code and I feel that might be one of the reasons why my code was not a solution for part 2 of lab 2.  

  - Valgrind Clean for Part1:
==2152== Memcheck, a memory error detector
==2152== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==2152== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==2152== Command: ./isort
==2152== 
==2152== Conditional jump or move depends on uninitialised value(s)
==2152==    at 0x10895C: intcpy (isort.c:11)
==2152==    by 0x108D94: main (isort.c:87)
==2152== 
==2152== Conditional jump or move depends on uninitialised value(s)
==2152==    at 0x10895C: intcpy (isort.c:11)
==2152==    by 0x108EB7: main (isort.c:112)
==2152== 
enter size of array: original: 53 16 12 44 
ascending: 12 16 44 53 
descending: 53 44 16 12 
==2152== 
==2152== HEAP SUMMARY:
==2152==     in use at exit: 0 bytes in 0 blocks
==2152==   total heap usage: 5 allocs, 5 frees, 3,632 bytes allocated
==2152== 
==2152== All heap blocks were freed -- no leaks are possible
==2152== 
==2152== For counts of detected and suppressed errors, rerun with: -v
==2152== Use --track-origins=yes to see where uninitialised values come from
==2152== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)

 - Valgrind Clean for Part2:

==9065== Memcheck, a memory error detector
==9065== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==9065== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==9065== Command: ./twecho hello world dude
==9065== 
==9065== Invalid write of size 8
==9065==    at 0x1087E6: duplicateArgs (twecho.c:18)
==9065==    by 0x10895B: main (twecho.c:61)
==9065==  Address 0x522f068 is 0 bytes after a block of size 40 alloc'd
==9065==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==9065==    by 0x10878D: duplicateArgs (twecho.c:14)
==9065==    by 0x10895B: main (twecho.c:61)
==9065== 
==9065== Invalid read of size 8
==9065==    at 0x108876: duplicateArgs (twecho.c:25)
==9065==    by 0x10895B: main (twecho.c:61)
==9065==  Address 0x522f068 is 0 bytes after a block of size 40 alloc'd
==9065==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==9065==    by 0x10878D: duplicateArgs (twecho.c:14)
==9065==    by 0x10895B: main (twecho.c:61)
==9065== 
==9065== Invalid read of size 8
==9065==    at 0x108825: duplicateArgs (twecho.c:26)
==9065==    by 0x10895B: main (twecho.c:61)
==9065==  Address 0x522f068 is 0 bytes after a block of size 40 alloc'd
==9065==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==9065==    by 0x10878D: duplicateArgs (twecho.c:14)
==9065==    by 0x10895B: main (twecho.c:61)
==9065== 
==9065== Conditional jump or move depends on uninitialised value(s)
==9065==    at 0x4E6E72F: toupper (ctype.c:52)
==9065==    by 0x108838: duplicateArgs (twecho.c:27)
==9065==    by 0x10895B: main (twecho.c:61)
==9065== 
==9065== Use of uninitialised value of size 8
==9065==    at 0x4E6E743: toupper (ctype.c:52)
==9065==    by 0x108838: duplicateArgs (twecho.c:27)
==9065==    by 0x10895B: main (twecho.c:61)
==9065== 
==9065== Invalid read of size 8
==9065==    at 0x108850: duplicateArgs (twecho.c:28)
==9065==    by 0x10895B: main (twecho.c:61)
==9065==  Address 0x522f068 is 0 bytes after a block of size 40 alloc'd
==9065==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==9065==    by 0x10878D: duplicateArgs (twecho.c:14)
==9065==    by 0x10895B: main (twecho.c:61)
==9065== 
==9065== Invalid write of size 8
==9065==    at 0x108800: duplicateArgs (twecho.c:20)
==9065==    by 0x10895B: main (twecho.c:61)
==9065==  Address 0x522f068 is 0 bytes after a block of size 40 alloc'd
==9065==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==9065==    by 0x10878D: duplicateArgs (twecho.c:14)
==9065==    by 0x10895B: main (twecho.c:61)
==9065== 
==9065== Invalid read of size 8
==9065==    at 0x108807: duplicateArgs (twecho.c:20)
==9065==    by 0x10895B: main (twecho.c:61)
==9065==  Address 0x522f068 is 0 bytes after a block of size 40 alloc'd
==9065==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==9065==    by 0x10878D: duplicateArgs (twecho.c:14)
==9065==    by 0x10895B: main (twecho.c:61)
==9065== 
==9065== Invalid read of size 1
==9065==    at 0x108828: duplicateArgs (twecho.c:26)
==9065==    by 0x10895B: main (twecho.c:61)
==9065==  Address 0x50 is not stack'd, malloc'd or (recently) free'd
==9065== 
==9065== 
==9065== Process terminating with default action of signal 11 (SIGSEGV)
==9065==  Access not within mapped region at address 0x50
==9065==    at 0x108828: duplicateArgs (twecho.c:26)
==9065==    by 0x10895B: main (twecho.c:61)
==9065==  If you believe this happened as a result of a stack
==9065==  overflow in your program's main thread (unlikely but
==9065==  possible), you can try to increase the size of the
==9065==  main thread stack using the --main-stacksize= flag.
==9065==  The main thread stack size used in this run was 8388608.
==9065== 
==9065== HEAP SUMMARY:
==9065==     in use at exit: 93 bytes in 4 blocks
==9065==   total heap usage: 4 allocs, 0 frees, 93 bytes allocated
==9065== 
==9065== 40 bytes in 1 blocks are definitely lost in loss record 1 of 2
==9065==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==9065==    by 0x10878D: duplicateArgs (twecho.c:14)
==9065==    by 0x10895B: main (twecho.c:61)
==9065== 
==9065== 53 bytes in 3 blocks are definitely lost in loss record 2 of 2
==9065==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==9065==    by 0x1087E5: duplicateArgs (twecho.c:18)
==9065==    by 0x10895B: main (twecho.c:61)
==9065== 
==9065== LEAK SUMMARY:
==9065==    definitely lost: 93 bytes in 4 blocks
==9065==    indirectly lost: 0 bytes in 0 blocks
==9065==      possibly lost: 0 bytes in 0 blocks
==9065==    still reachable: 0 bytes in 0 blocks
==9065==         suppressed: 0 bytes in 0 blocks
==9065== 
==9065== For counts of detected and suppressed errors, rerun with: -v
==9065== Use --track-origins=yes to see where uninitialised values come from
==9065== ERROR SUMMARY: 20 errors from 11 contexts (suppressed: 0 from 0)
