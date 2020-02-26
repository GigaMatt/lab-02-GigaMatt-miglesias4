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
#define MAX 100
char *change_dir_cmd = "cd", *exit_cmd = "exit";

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
    char *ps1_prompt, *ps1_value;
    ps1_prompt = argv[1];
    ps1_value = getenv(ps1_prompt);

    char *envp = {(char *) "PATH=/bin",0};

    /* Loop through shell until user exits*/
    while(1){
        /* Display Shell to User */
        shell_greeting(*ps1_prompt, *ps1_value);

        /* Read/Parses User Input*/
        user_input(buffer);

        /* Execute Use Command */
        execute_command(cmds);  // Will also 

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
