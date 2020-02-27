/*
 * CS 4375 - Theory of Operating Systems
 * By: Matthew Iglesias (ID: 80591632)
 * By: Matthew S Montoya (ID: 88606727)
 * Purpose: To build a user shell for a Unix operating system
 * Last Modified: 28 February 2020
*/

#include "UnixShell.h"

int main()
{
    /* Display greeting similar to UTEP CS 3432 VM greeting */
    shell_greeting();

    /* Run shell until user terminates program*/
    while (1)
    {
        /* Reset variables before every input */
        int tokens_list, pos, user_exit, piped_command, cmd_one_length, buffer_iterator, piped_input = 0;
        char *buffer[MAX + 1], **tokens[MAX + 1];
        char *first_shell_command[MAX + 1] = {0}, *second_shell_command[MAX + 1] = {0};

        // DECLARE ENVIRONMENT HERE?

        /* Display user input prompt */
        display_prompt();

        char *user_input = fgets(*buffer, sizeof(*buffer), stdin);
        if (user_input == NULL)
        {
            break;
        }

        /* Get List of Tokens */
        tokens_list = parse_user_input(*buffer, *tokens);

        /* Check for user terminating program*/
        user_exit = strcmp(*tokens[0], exit_cmd);
        if (user_exit == 1)
        {
            printf("Terminating shell.\n");
            break;
        }

        /* Check for user piping commands */
        for (pos = 0; pos < tokens_list; pos++)
        {
            piped_input = strcmp(*tokens[pos], "|");
            if (piped_input == 1)
            {
                cmd_one_length = pos;
                break;
            }
        }

        /* Two commands exist: Separate & execute the two commands */
        if (piped_input == 1)
        {
            for (buffer_iterator = 0; buffer_iterator < cmd_one_length; buffer_iterator++)
            {
                first_shell_command[buffer_iterator] = tokens[buffer_iterator];
            }
            int cmd_two_pos = 0;
            for (buffer_iterator = pos + 1; buffer_iterator < tokens_list; buffer_iterator++)
            {
                second_shell_command[cmd_two_pos] = tokens[buffer_iterator];
                cmd_two_pos++;
            }
            if (execute_dual_cmd(first_shell_command, second_shell_command) == 0)
            {
                break;
            }
        }

        /* One command exists: Execute the single command */
        if (piped_input == 0)
        {
            if (execute_single_cmd(*tokens) == 0)
            {
                break;
            }
        }
    }
    return 0;
}