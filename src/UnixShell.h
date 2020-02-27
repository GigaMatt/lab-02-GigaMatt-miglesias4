/*
 * CS 4375 - Theory of Operating Systems
 * By: Matthew Iglesias (ID: 80591632)
 * By: Matthew S Montoya (ID: 88606727)
 * Purpose: To build a user shell for a Unix operating system
 * Last Modified: 28 February 2020
*/

#ifndef _UNIXSHELL_
#define _UNIXSHELL_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX 300

/* Greets user similar to UTEP CS 3432 VM greeting */
void shell_greeting();

/* Displays prompt for user to enter command */
void display_prompt();

/* Creates a list of words based on user input */
char parse_user_input(char *buffer);

/* Executes single user command, invoking 'execvp' */
int execute_single_cmd(char **tokens);

/* Executes two (2) user commands by piping (system call) the processes, invoking 'execvp' */
int execute_dual_cmd(char ** first_shell_command, char ** second_shell_command);

char *find_word_start(char *str);
char *find_word_end(char *str);
int count_words(char* str);
char **tokenize(char *str);
int string_length(char *str);
char is_valid_character(char c);
void print_tokens(char **tokens);
void free_tokens(char **tokens);
char *token_copy(char *tokens);

#endif
