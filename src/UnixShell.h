#ifndef _UNIXSHELL_
#define _UNIXSHELL_

/* Initial Shell Greeting */
void shell_greeting();

/* Retrieve User Shell Commands */
int user_input(char *input_value);

/* Execute User Commands */
void execute_command(char **parse);

#endif