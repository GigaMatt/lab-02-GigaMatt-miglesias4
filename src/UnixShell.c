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
    /* Reset variables before every input */
    int pos, user_exit, piped_command, cmd_one_length, buffer_iterator, piped_input = 0, execute = 1;
    char buffer[MAX], *tokens[MAX];
    char ** tokens_list;
    char *first_shell_command[MAX] = {0}, *second_shell_command[MAX] = {0};
    /* Display greeting similar to UTEP CS 3432 VM greeting */
    shell_greeting();

    /* Run shell until user terminates program*/
    while (execute)
    {
        /* Display user input prompt */
        printf("$");

        fgets(buffer, MAX, stdin);

        if (buffer == NULL)
        {
            break;
        }

        char* start_word = find_word_start(buffer);
        char* end_word = find_word_end(buffer);
        int word_length = count_words(buffer);
        char **user_tokens = (char**) malloc(word_length);  // Consider sending in a pointer
        user_tokens = tokenize(buffer);
        print_tokens(user_tokens);


        printf("I am here 0\n");

        /* Get List of Tokens */
        // tokens_list = parse_user_input(buffer);
        //print_tokens(tokens_list);
        

        //         int it = 0;
        //         while (tokens_list[it])
        //         { // Loop through the string & individually print the chars
        //             printf("[%d] = %s\n", it, tokens_list[it]);
        //             it++;
        //         }
        // }
        //         printf("I am here 1\n");

        //         /* Check for user terminating program*/
        //         user_exit = strcmp(tokens[0], "exit");
        //         if (user_exit == 0){
        //             printf("Terminating shell.\n");
        //             break;
        //         }

        //         printf("I am here 1.5\n");
        //         if (strcmp(tokens[0], "exit") == 1) break;

        //         printf("I am here 2\n");

        //         /* Check for user piping commands */
        //         for (pos = 0; pos < tokens_list; pos++)
        //         {
        //             piped_input = strcmp(tokens[pos], "|");
        //             if (piped_input == 1)
        //             {
        //                 cmd_one_length = pos;
        //                 break;
        //             }
        //         }

        //         printf("I am here 3\n");

        //         /* Two commands exist: Separate & execute the two commands */
        //         if (piped_input == 1)
        //         {
        //             for (buffer_iterator = 0; buffer_iterator < cmd_one_length; buffer_iterator++)
        //             {
        //                 first_shell_command[buffer_iterator] = tokens[buffer_iterator];
        //             }
        //             int cmd_two_pos = 0;
        //             for (buffer_iterator = pos + 1; buffer_iterator < tokens_list; buffer_iterator++)
        //             {
        //                 second_shell_command[cmd_two_pos] = tokens[buffer_iterator];
        //                 cmd_two_pos++;
        //             }
        //             if (execute_dual_cmd(first_shell_command, second_shell_command) == 0)
        //             {
        //                 break;
        //             }
        //         }

        //         printf("I am here 4\n");

        //         /* One command exists: Execute the single command */
        //         if (piped_input == 0)
        //         {
        //             if (execute_single_cmd(tokens) == 0)
        //             {
        //                 break;
        //             }
        //         }
    }
    printf("'Fortune favors the prepared mind.'  –  Louis Pasteur\n");
    return 0;
}

/**
 * Finds the next word in the string. For example, given an input of "  my cake" the function should return "my cake".
 * @str: user input string
 **/
char *find_word_start(char *str)
{
    if (count_words(str) > 0)
    {                                // Determine if more than zero words exist
        char *temp_char_array = str; // Duplicate array for checking
        while (*temp_char_array)
        {
            if ((is_valid_character(temp_char_array[0])) == 1)
            {                           // DANIEL (INSTRUCTOR): C BOOLEANS ARE COMPRISED OF INTS
                return temp_char_array; // Return the next words, beginning with valid chars
            }
            *temp_char_array++;
        }
    }
    return str; // Return original array if no valid chars exist
}


/**
 * Finds the end of current word. For example, given an input of "my cake" the function should return " cake".
 * @str: user input string
 **/
char *find_word_end(char *str)
{
    while (is_valid_character(*str))
    {
        str++;
        if (*str == 32)
        {
            return str; // Return the end of current word
        }
    }
    return "0"; // Return original array if no valid chars exist
}


/**
 * Counts the number of words in the string argument.
 * @str: user input string
 **/
int count_words(char* str)
{
    int pos_1 = 0, pos_2 = 0, num_words = 1;
    while(is_valid_character(str[pos_2])==0)
    {
        pos_1++;
        pos_2++;
    }
    pos_2 = string_length(str);

    while(is_valid_character(str[pos_2])== 0)
    {
        pos_2--;
    }

    // Find the difference to separate out the words
    while(pos_1 < pos_2)
    {
        if((is_valid_character(str[pos_1])==0) && (is_valid_character(str[pos_1+1])==1))
            num_words++;
        pos_1++;
    }
    return num_words;
}


/**
 * Tokenizes the string argument into an array of tokens.
 * @str: user input string
 **/
char **tokenize(char *str)
{
    int pos = 0, word_length = count_words(str);
    char** tokens = (char**) malloc((word_length+1) * sizeof(char*));

    while(pos<word_length)
    {
        str = find_word_start(str);
        char* tokenized_word = token_copy(str);
        str = find_word_end(str);
        tokens[pos] = tokenized_word;

        pos++;
    }
    return tokens;
}


/**
 * Counts the number of characters in the string argument.
 * @str: user input string
*/
int string_length(char *str)
{
    int num_chars = 0;
    int pos = 0;
    while(str[pos])
    {
        num_chars++;
        pos++;
    }
    return num_chars-1;
}


/** Evaluates if the character c is an acceptable character for
 * a token. Acceptable characters include any alphanumeric or
 * special character. Unacceptable characters include any
 * whitespace or control characters.
 * Returns 0 if not, 1 if yes.
 * 
 * @c: character from user input string
 **/
char is_valid_character(char c)
{
    // Special Characters: characters with octal codes 000 through 037, and 177
    if (c >= 34 & c <= 126)
        return 1;
    else
        return 0;
}

/* Prints all tokens. */
void print_tokens(char **tokens)
{
    int pos = 0;
    while (tokens[pos])
    { // Loop through the string & individually print the chars
        printf("[%d] = %s\n", pos, tokens[pos]);
        pos++;
    }
}

/* Frees all tokens and the array containing the tokens. */
void free_tokens(char **tokens)
{
    // Daniel (Instructor): "free" is a keyword. Don't reinvent the wheel
    int pos = 0;
    while (tokens[pos])
    {
        // Loop through the string & individually free the chars
        free(tokens[pos]);
        pos++;
    }
    free(tokens);
}

/* Copy Parameter & return */
char *token_copy(char *tokens)
{
    char *str_copy_1 = tokens;
    int word_length = 0, pos = 0;  // Placeholder for cycling through array
    while(str_copy_1[pos])
    {
        if(is_valid_character(str_copy_1[pos]) == 1)
            word_length++;
        else
            break;

        pos++;
    }

    char* str_copy_2 = (char*) malloc(word_length + 1);
    pos = 0;                        // Reset variable so we can continue using variable
    while(pos<word_length)
    {
        str_copy_2[pos] = str_copy_1[pos];
        pos++;
    }
    str_copy_2[pos] = '\0';         // Tell the array we are at the end
    return str_copy_2;
}