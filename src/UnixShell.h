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

/* Creates a list of words based on user input */
char parse_user_input(char *buffer);

/* Executes single user command, invoking 'execvp' */
int execute_single_cmd(char **tokens);

/* Executes two (2) user commands by piping (system call) the processes, invoking 'execvp' */
int execute_dual_cmd(char ** first_shell_command, char ** second_shell_command);

/* Finds the next word in the string */
char *find_word_start(char *str);

/* Finds the end of current word */
char *find_word_end(char *str);

/* Counts the number of words in the string argument */
int count_words(char* str);

/* Tokenizes the string argument into an array of tokens */
char **tokenize(char *str);

/* Counts the number of characters in the string argument */
int string_length(char *str);

/* Evaluates if the character c is an acceptable character for a token */
char is_valid_character(char c);

/* Prints all tokens */
void print_tokens(char **tokens);

/* Frees all tokens and the array containing the tokens */
void free_tokens(char **tokens);

/* Copy token parameter */
char *token_copy(char *tokens);

#endif
