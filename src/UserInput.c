/*
 * CS 4375 - Theory of Operating Systems
 * By: Matthew Iglesias (ID: 80591632)
 * By: Matthew S Montoya (ID: 88606727)
 * Purpose: To build a user shell for a Unix operating system
 * Last Modified: 28 February 2020
*/

#include "UnixShell.h"


/**
 * execute_single_cmd - executes single user command, invoking 'execvp'.
 * @tokens: the list of words (command + flags) the user wants to run
 * 
 * Return: exit/error code associated with running the users command(s)
 */
int execute_single_cmd(char **tokens)
{

    /* User wants to change directories */
    if(strcmp(tokens[0], "cd") == 0){
        //int exit_code = change_dir(tokens);
        int exit_code = chdir(tokens[1]);

        /* Return error code associated with failed command*/
        if(exit_code != 0) return exit_code;
    }

    //execvp

    // /* Fork the process */
    // pid_t subprocess = fork();

    // /* An issue occured while forking */
    // if (subprocess < 0)
    // {
    //     printf("Fork Failed. Quitting Program.\n");
    //     return (1);
    // }

    // /* Run the child process */
    // else if (subprocess == 0)
    // {

    //     /* Execute User Command*/
    //     execvp(tokens[0], tokens);
    //     char *error = strerror(errno);
    //     //printf("unknown command\n");
    //     return 0;
    // }

    // /* Run the parent process */
    // else
    // {
    //     int childstatus;
    //     waitpid(subprocess, &childstatus, 0);
    //     return 1;
    // }
}

/**
 * execute_dual_cmd - executes two (2) user commands by piping (system call) the processes, invoking 'execvp'.
 * @first_shell_command: the first command (command+flags) the user wants to run
 * @second_shell_command: the second command (command+flags) the user wants to run
 * 
 * Return: exit/error code associated with running the users command(s)
 */
int execute_dual_cmd(char ** first_shell_command, char ** second_shell_command)
{

    /* Create Pipe */
    int pid[2];
    pipe(pid);

    /* An issue occured while piping */
    if(pid < 0){
        printf("Pipe Failed. Quitting Program.\n");
        return(1);
    }

    /* Fork the process */
    pid_t subprocess = fork();

    /* An issue occured while forking */
    if (subprocess < 0)
    {
        printf("Fork Failed. Quitting Program.\n");
        return (1);
    }

    /* Run the child process */
    else if (subprocess == 0)
    {
        close(pid[1]);
        dup2(pid[0], 0);
        //close(pid[0]);

        if(execvp(second_shell_command[0], second_shell_command) == -1){
            printf("error");
        }
        char *error = strerror(errno);
        return 0;
    }

    /* Run the parent process */
    else
    {
        close(pid[0]);
        dup2(pid[1], 1);
        //close(pid[1]);

        if(execvp(second_shell_command[0], second_shell_command) == -1){
            printf("error");
        }

        char *error = strerror(errno);
        return 0;
    }
}

// /**
//  * change_dir - changes the current working directory path specified by the user
//  * @tokens: the list of words (command + flags) the user wants to run
//  * 
//  * Return: exit/error code associated with running the users command(s)
//  */
// int change_dir(char ** tokens){
//     int exit_code = chdir(tokens[1]);
//     return exit_code;
// }