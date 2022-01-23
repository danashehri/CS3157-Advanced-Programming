
 - Name: Dana AlShehri
 - ID: da2975
 - Lab: #5
 - Description for Part 1:
  - a) The script works exactly as specified
  - b) The program runs exactly as specified. The process tree is below:

3140 27572 27572 27572 ?           -1 Ss       0   0:00  \_ sshd: da2975 [priv]
27572  5888 27572 27572 ?           -1 S     4891   0:00  |   \_ sshd: da2975@pts/255
 5888  6424  6424  6424 pts/255  10642 Ss    4891   0:00  |       \_ -bash
 6424 10642 10642  6424 pts/255  10642 S+    4891   0:00  |           \_ ./mdb-lookup-server-nc-1 11891
10642 10653 10642  6424 pts/255  10642 S+    4891   0:00  |               \_ /bin/sh ./mdb-lookup-server-nc.sh 11891
10653 10670 10642  6424 pts/255  10642 S+    4891   0:00  |                   \_ cat mypipe-10653
10653 10671 10642  6424 pts/255  10642 S+    4891   0:00  |                   \_ nc -l 11891
10653 10672 10642  6424 pts/255  10642 S+    4891   0:00  |                   \_ /bin/sh /home/jae/cs3157-pub/bin/mdb-lookup-cs3157
10672 10683 10642  6424 pts/255  10642 S+    4891   0:00  |                       \_ /home/jae/cs3157-pub/bin/mdb-lookup /home/jae/cs3157-pub/bin/mdb-cs3157


The files that are shell scripts are as follows: 
	1. /bin/sh ./mdb-lookup-server-nc.sh 11891
This is the child process with pid=0 as a result of a successful return value of fork() system call. This child process runs the shell script mdb-lookup-server-nc.sh that takes in one argument, the port number 11891. 

	
  - c) I tried my best to make the program run as specified by the lab. Initially, I had difficulties with exiting an infinite loop upon hitting ctrl-c but I worked out by leaning on a signal handler function to exit the loop. Also, my code doesn't update in terms of showing terminated child processes as the user presses Enter rather than typing an integer. I tried to address this issue but unfortunately I didn't come to a solid solution for it.  
