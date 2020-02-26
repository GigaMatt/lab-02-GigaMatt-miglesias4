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
void execute_command(char **cmds)
{
    /* Call Fork Command */
    execve("p1fork.c",parameter,envp);

    // Check for "exit" and "cd"

    int command_not_found;

    if (command_not_found == 1)
    {
        printf("Command Not Found\n");
    }
}