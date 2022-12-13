
#include "file_operation_lib.h"
FILE *myfile;


int main(int argc, char **argv)
{
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
     fseek(myfile,0,0); 
    if(check_if_there_are_any_letters()==true)
    {
        message_about_letters_in_file();
        exit(1);
    }
    fseek(myfile,0,0); 
     // new_size_of_array = count_numbers_in_the_file();
    printf("%d\n",new_size_of_array);
    int Array_of_numbers[new_size_of_array];
    write_number_into_array(Array_of_numbers);
    fclose(myfile);
  
}



