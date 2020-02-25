/*
 * CS 170 - Theory of Operating Systems
 * By: Matthew Iglesias (ID: 80591632)
 * By: Matthew S Montoya (ID: 88606727)
 * Purpose: 
 * Last Modified: 25 February 2020
 * 
 * NOTES: DUE TO ISSUES WITH GUTHUB CLASSROOM, THIS REPOSITORY IS PRIVATE UNTIL 01 MARCH 2020
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX 100
char *change_dir_cmd = "cd", *exit_cmd = "exit";

/**
 * Execute User Commands
 * @parse: 
 **/
void execute_command(char **parse)
{
    pid_t p = fork();
    int command_not_found;

    if (command_not_found == 1)
    {
        printf("Command Not Found\n");
    }
}


/**
 * Runner executing the program
 * @argc: Number of Arguments
 * @argv: Pointer to $PS1 Prompt
 * @env: PATH / Environment Variables
 **/ 
int main(int argc, char **argv, char **env)
{
    char *buffer, **cmds, *parameter[20];
    int length, char_string;

    /* Store $PS1 Value */
    char *ps1_prompt , *ps1_value;
    ps1_prompt = argv[1];
    ps1_value = getenv(ps1_prompt);


    if(ps1_value){
        printf("Variable %s has value %s", ps1_prompt, ps1_value);
    }
    else{
        printf("Variable %s has no value");
    }
    

    char *envp = {(char *) "PATH=/bin",0};

    /* Loop through shell until user exits*/
    while(1){
        /* Prompt Shell to User */
        shell_greeting(*ps1_prompt);
        while ((char_string = getline(&buffer, &length, stdin)))




        user_input(parameter); //Reads User Input
        if(fork() != 0){ //Parent process
            wait(NULL); //Waits for child process
        }
        if(strcmp(argv, "exit") == 0){
            break;
        }
        else{
            strcpy(argc, "/bin/");
            strcat(argc, argv);

            execve(argc,parameter,envp); //Execute Command
        }
    }
    return 0;
}
