# C Shell

# Running the shell

* To run the shell run the following commands
 1. Run make command
 2. Run ./a.out command

# Overview

* This shell is like a original working shell,It supports the commands which are separated by semicolon also.

* It supports the,

  1. ls command along with multiple flags and directories to list the files and directories

    * ls 
    * ls -a
    * ls -l
    * ls -al/-la
    * ls <directory> 

   2. cd command to change the directory
    

     * cd 
     * cd .
     * cd ..
     * cd /
     * cd ~
     * cd <directory>
     * cd -

   3. pwd to print the present working directory

     * pwd

   4. echo to print the given content on the terminal

     * examples
     * echo "Hi there am Nithin"

   5. pinfo/pinfo Pid to print the information about the process based on the Process id.


     * pinfo 
     * pinfo ID

   6. Bagorund processes,to run the command in the baground


      * examples
      * sleep 20 &
      * gedit &

    7. foreground processes, to run the command in the foreground that is we can not run another command until this foreground process finished.


      * examples
      * Sleep 2
      * vi

    8. Printing message if process exited normally or abnormally

    9. Input/output redirection ,it sends or recives the content to file or from file respectively according to given commands

      * examples
      * cat < nithin.txt

      * ls > out.txt

    10. Pipes: can handle any number of pipes 

       * examples
       * cat test.txt | wc


    11. Pipes with input output redirection

       * examples

       * cat < test.txt | wc -l > nithin.txt

    
    12. jobs, prints all the baground processes which are running and stopped.

       * command : jobs

    13.  killing jobs,using sig command shell can kill the process to the given appropriate job number

      * command example : sig 1 9


    14. fg: This brings the stopped or running baground process to foregroung in running mode using its job number

      * command example : fg 2



    15. bg: It changes the state of the stopped baground process to running

       * command example : bg 2

 
    16. Ctrl_z: It moves the currently running foreground process to baground process and changes the state to stopped.

      

    17. Ctrl_c: It interupts the currently running foreground process.


    18. Ctrl_d: It logs out of the shell





    16. History/history number ,This command prints the last 20 commands executed by us And history with number prints the those number of commands previously we executed that number should be 0 < number <= 20.


        * History
   
        * History 3


  # Header files and code files


  * Headers.h : it contains all the header files used to make this shell

  * functions.h : It contains all the function declarations

  * main.c: It has the main function,

          1. cd function executes all cd commands
          2. comdline function prints the commandline in every line
          3. plhandle function prints the message when bg process ends.
          4. siginter function is also for executing ctrl_z.
          5. sigint function is for ctrl_c which interupts the curently running foreground process.

  * ls.c : 
          1. lscommand function executes all ls commands
          2. filefun and filefunctioning functions are used to execute some ls commands

   * history.c :
          
           1. history and historyl function prints the history

    * pinfo.c :

          1. spec4 function prints the process information

    * processes.c :

          1. proc function executes the baground and foreground processes.

          2. sigintering function is for ctrl z which moves the current foreground process to baground and state to stopped.


    * pipe.c :

          1. pipe.c and pips.c functions executes the pipe commands.

    * jobs.c:
         
          1. makenode,pret,insertr,statuser,printlist,Getpid,deleteall functions are linked functions which i used to store the baground jobs information.

    * kjob.c :
        
          1. kjobs function is kills the currently running process by sending the signal

    * fg.c:

          1. fgprocess function brings the running or stopped baground job to foreground.


    * bg.c:
      
         1. bgprocess function changes the state of the stopped baground job to running.

  
  


    



    
      
     


 