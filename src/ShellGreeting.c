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
 * Initial Shell Greeting
 * @ps1_prompt: ps1 shell variable
 * @ps1_value: numerical representation of ps1_prompt
 * 
 **/
void shell_greeting(char *ps1_prompt, char *ps1_value)
{
    /* Display Initial Greeting */
    clear(); // Clear console for user
    printf("Welcome to our Unix Shell\n\t – TheMatts™\n");
    printf("'Luck is what happens when preparation meets opportunity.'\n\t – Seneca.™\n");

    /* Display $PS1 or Valid Prompt String */
    if ((ps1_prompt != NULL) && (ps1_prompt[0] == '\0'))
    {
        char *default_prompt = "$";
        write(STDOUT_FILENO, default_prompt, 2);
    }
    else
    {
        write(STDOUT_FILENO, ps1_prompt, 2);
    }

    ////////// OR //////////

    /* Display $PS1 String */
    if (ps1_value)
    {
        write(STDOUT_FILENO, ps1_prompt, 2);
    }
    /* Display Default Prompt String */
    else
    {
        char *default_prompt = "$";
        write(STDOUT_FILENO, default_prompt, 2);
    }
}