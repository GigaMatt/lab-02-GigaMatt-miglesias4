/*
 * CS 4375 - Theory of Operating Systems
 * By: Matthew Iglesias (ID: 80591632)
 * By: Matthew S Montoya (ID: 88606727)
 * Purpose: To build a user shell for a Unix operating system
 * Last Modified: 28 February 2020
*/

#include "UnixShell.h"

/**
 * shell_greeting - greets user similar to UTEP CS 3432 VM greeting
 **/
void shell_greeting()
{
    /* Display Initial Greeting */
    //clear();
    printf("Welcome to our Unix Shell\n\t– TheMatts™\n");
    printf("'Luck is what happens when preparation meets opportunity.'\n\t– Seneca.™\n");
}

/**
 * display_prompt - displays prompt for user to enter command
 */

void display_prompt()
{
    /* Display $PS1 or Valid Prompt String */
    // if ((ps1_prompt != NULL) && (ps1_prompt[0] == '\0'))
    // {
    char *default_prompt = "$";
    write(STDOUT_FILENO, default_prompt, 2);
    // }
    // else
    // {
    //     write(STDOUT_FILENO, ps1_prompt, 2);
    // }
}