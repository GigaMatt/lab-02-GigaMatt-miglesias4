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
#include <stdio.h>
#include <stdlib.h>
#define LSH_RL_BUFSIZE 1024

/**
 * Retrieve User Shell Commands and perform the parse function by each line. Then this function will return the command
 * which then will be sent to the ExecuteCommand.c file under the execute_command function to execute the user's desired command.
 * @input_value: user command
 **/
char *user_input(char *input_value)
{
    char *user_line = NULL;
    ssize_t buffer_size = 0; //ssize_t integrates return value of valid size (includes negative values)
    getline(&user_line, &buffer_size, stdin); //getline() will allocate memory using buffer_
    //user_line is the read line

    //Performing parse on each line of the user_input value
    char *parsed_line = parse_user_input(user_line);

    //Switch case statements in execute_command in ExecuteCommand.c file
    return parsed_line;
}

/* This function uses user input line and performs tokenization to determine command variable and parameter variable */ 
char *tokenize(char *line){
    int pos = 0, token_length = count_tokens(line);
    char** tokens = (char**) malloc((token_length+1) * sizeof(char*));

    while(pos < token_length)
    {
        line = find_word_start(line);
        char* tokenized_word = token_copy(line);
        line = find_word_end(line);
        tokens[pos] = tokenized_word;

        pos++;
    }
    return tokens;
}

/* This function determines if each character in the user input line is valid */
char is_Valid_Char(char user_input_char){

    if(user_input_char == 124){
        pipe_cmd = 1; // There is a pipe (|) in the user's argument
    }
    // Special Characters: includes " " and up to 126
    if (user_input_char >= 32 & user_input_char <= 126){
        return 1;
    }
    else{
        return 0;
    }
    return;
}

/* This function counts the number of tokens from the user input line */
char count_tokens(char *user_cmd_token){
    int cmd_count = 0, param_count = 0, num_words = 1;
    while(is_Valid_Char(user_cmd_token[param_count])==0)
    {
        cmd_count++;
        param_count++;
    }
    param_count = string_length(user_cmd_token);

    while(is_Valid_Char(user_cmd_token[param_count])== 0)
    {
        param_count--;
    }

    // Find the difference to separate out the words
    while(cmd_count < param_count)
    {
        if((is_Valid_Char(user_cmd_token[cmd_count])==0) && (is_Valid_Char(user_cmd_token[cmd_count+1])==1))
            num_words++;
        cmd_count++;
    }
    return num_words;
}

/* Finds the first token character in the token */
char *find_token_start(char *token_str)
{
    if (count_words(token_str) > 0)
    {                                // Determine if more than zero strings exist
        char *temp_char_array = token_str; // Duplicate array for checking
        while (*temp_char_array)
        {
            if ((is_Valid_Char(temp_char_array[0])) == 1)
            {                           
                return temp_char_array; // Return the next string, beginning with valid chars
            }
            *temp_char_array++;
        }
    }
    return token_str; // Return original array if no valid chars exist
}

/* Finds the end of current token */
char *find_token_end(char *token_str)
{
    while (is_Valid_Char(*token_str))
    {
        token_str++;
        if (*token_str == 32)
        {
            return token_str; // Return the end of current string
        }
    }
    return "0"; // Return original array if no valid chars exist
}