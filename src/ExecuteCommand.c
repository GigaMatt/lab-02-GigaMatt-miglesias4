/*
 * CS 170 - Theory of Operating Systems
 * By: Matthew Iglesias (ID: 80591632)
 * By: Matthew S Montoya (ID: 88606727)
 * Purpose: 
 * Last Modified: 25 February 2020
 * 
 * NOTES: DUE TO ISSUES WITH GUTHUB CLASSROOM, THIS REPOSITORY IS PRIVATE UNTIL 01 MARCH 2020
*/
#include "UnixShell.h"

/**
 * Execute User Commands
 * @cmds: user command
 **/

int pipe_cmd = 0; //Refers to the (|) command in user input

void execute_command(char **cmds){
    int rc = fork();
    char *parsed_usr_input;
    /* Create Pipe */
        int pid[2];
        pipe(pid);

    /* An issue occured while piping */
    if(pid < 0){
        printf("Pipe Failed. Quitting Program.\n");
        exit(1);
    }

    if (rc < 0)
    {
    /* An issue occured while piping */
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        // child (new process)
        printf("Child (pid:%d)\n", (int)getpid());
        close(pid[1]);                                  // Close the write end of the pipe
        read(pid[0], parsed_usr_input, sizeof(parsed_usr_input));   // Read the user input
        close(pid[0]);                                  // Close the read end of the pipe
        exit(0);

        //call everything in the commands 

        //Switch cases hereeeeeeeeee
        //Include the $PATH
    }
    else
    {
        // Parent goes down this path (original process)
        printf("Parent of %d (pid:%d)\n",
                rc, (int)getpid());
        close(pid[0]);                                  // Close the read end of the pipe
        write(pid[1], parsed_usr_input, sizeof(parsed_usr_input));  // Write the user enput
        close(pid[1]); 
    }
}