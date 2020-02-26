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
 * Retrieve User Shell Commands 
 * @input_value: user command
 **/
char *user_input(char *input_value)
{

    char *user_line = NULL;
    ssize_t buffer_size = 0; //ssize_t integrates return value of valid size (includes negative values)
    getline(&user_line, &buffer_size, stdin);
    //user_line is the read line


    // NEED LATER GIVE OR TAKE
    /*
    char *line;
    line = readline("\n$ "); //Command line user input
    if (strlen(line) != 0)
    {                      //Length of string
        add_history(line); //Adds to the history for tabbing back to previous command
        strcpy(input_value, line);
        return 0;
    }

    */ 

    //parse here
    parse_user_input(user_line);

    //then move onto switch

    /* Swicth case that performs the necessary commands based on user input_value */
    
    /* **********TO BE FIXED************
    switch(*input_value){
        case "exit":
            break;
        case "ls":
            break;
        case "clear":
            break;
        case "cd":
            break;
        default:
            *cmd_not_found_prompt;
            break;
    }

    ************************************** */
    return 1;
}

char *parse_user_input(char *line){
    //code here

    return ;
}