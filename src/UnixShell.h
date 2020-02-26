#ifndef _UNIXSHELL_
#define _UNIXSHELL_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Initial Shell Greeting */
void shell_greeting();

/* Retrieve User Shell Commands */
int user_input(char *input_value);

/* Execute User Commands */
void execute_command(char **parse);

#endif