/*
 * CS 170 - Theory of Operating Systems
 * By: Matthew Iglesias (ID: 80591632)
 * By: Matthew S Montoya (ID: 88606727)
 * Purpose: 
 * Last Modified: 24 February 2020
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

/* Initial Shell Greeting */
void shell_greeting()
{
    clear();    // Clear Console Window Upon Shell initalization
    printf("Welcome to our Unix Shell\n\t – TheMatts™\n");
    printf("'Luck is what happens when preparation meets opportunity.' – Seneca.™\n");
}

/**
 * Retrieve User Shell Commands 
 * @input_value: user shell command
 **/
int user_input(char *input_value)
{
    char *line;
    line = readline("\n$ "); //Command line user input
    if (strlen(line) != 0)
    {                      //Length of string
        add_history(line); //Adds to the history for tabbing back to previous command
        strcpy(input_value, line);
        return 0;
    }
    return 1;
}

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
 * @argc:
 * @argv:
 * @env:
 **/ 
int main(int argc, char **argv, char **env){
    char argc[MAX], argv[MAX], *parameter[20];
    char *envp = {(char *) "PATH=/bin",0};

    while(1){
        shell_greeting(); //Optional, opens greeting
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