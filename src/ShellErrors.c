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

char *cmd_not_found_prompt = "command not found", *cmd_fail_prompt = "Program terminated with exit code %s";


/* Prints Commmand  */
void command_not_found(char *error_message, char *cmd)
{
    printf("%s: %s", cmd, cmd_not_found_prompt);
}

/*  */
void command_failure(int exit_code)
{
    printf("%s: %i", cmd_fail_prompt, exit_code);
}