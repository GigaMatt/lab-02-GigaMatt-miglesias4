/*
 * CS 170 - Theory of Operating Systems
 * By: Matthew Iglesias (ID: 80591632)
 * By: Matthew S Montoya (ID: 88606727)
 * Purpose: 
 * Last Modified: 25 February 2020
 * 
 * NOTES: DUE TO ISSUES WITH GUTHUB CLASSROOM, THIS REPOSITORY IS PRIVATE UNTIL 01 MARCH 2020
*/


/**
 * Retrieve User Shell Commands 
 * @input_value: User Shell Command
 **/
int user_input(char *input_value)
{
    char *line;
    line = readline("\n$ "); //Command line user input
    if (strlen(line) != 0)
    {                      //Length of string
        add_history(line); //Adds to the history for tabbing back to previous command
        strcpy(input_value, line);
        return 0;
    }
    return 1;
}