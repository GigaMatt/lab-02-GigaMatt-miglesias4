#ifndef _UNIXSHELL_
#define _UNIXSHELL_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Global variables for command not found of command fails */
char *cmd_not_found_prompt = "command not found", *cmd_fail_prompt = "Program terminated with exit code %s";

/* Initial Shell Greeting */
void shell_greeting();

/* Retrieve User Shell Commands */
char *user_input(char *input_value);

/* Execute User Commands */
void execute_command(char **parse);

#endif