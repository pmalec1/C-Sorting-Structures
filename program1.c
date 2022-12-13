#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_operation_lib.h"
FILE *myfile;

int main(int argc, char **argv)
{
   
    myfile = NULL;
    int array_of_numbers[SIZE_OF_ARRAY_OF_NUMBERS];
    int temp_number;
    int amount_of_numbers = 4;
    if (check_number_of_arguments(argc) != true)
    {
        message_incorrect_no_of_args();             // Check if number of invocation arguments is correct and message to user.
        exit(1);                                    //If file doesn't exist exit programm with failure code
    }
    else                                            // if number of calling args is correct
    {
        message_correct_no_of_args();               // Message to user about correct number of args
        if (check_if_file_exists(argv[1]) == true)
            message_file_exist();                   // Check path to myfile point to existing myfile and messeage to user if myfile exist
        else
        {
            message_file_not_exist();               // Message to user if myfile doesn't exist
            exit(1);                                //If file doesn't exist exit programm with failure code
        }
    }

    myfile = fopen(argv[1], "r");
    read_numbers_from_file(array_of_numbers,amount_of_numbers);
  
    
    fclose(myfile);
}


