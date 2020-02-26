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
#include <stdio.h>
#define LSH_RL_BUFSIZE 1024

/**
 * Retrieve User Shell Commands and perform the parse function by each line. Then this function will return the command
 * which then will be sent to the ExecuteCommand.c file under the execute_command function to execute the user's desired command.
 * @input_value: user command
 **/
char *user_input(char *input_value)
{

    char *user_line = NULL;
    ssize_t buffer_size = 0; //ssize_t integrates return value of valid size (includes negative values)
    getline(&user_line, &buffer_size, stdin); //getline() will allocate memory using buffer_
    //user_line is the read line

    //Performing parse on each line of the user_input value
    parse_user_input(user_line);

    //Switch case statements in execute_command in ExecuteCommand.c file
    return 1;
}

char *parse_user_input(char *line){
    //code here

    return ;
}