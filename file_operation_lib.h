
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define new_size_of_array 9


#define NUMBER_OF_EXPECTED_EXT_ARGS 3



int check_if_file_exists(char path_to_file[255]);
int check_number_of_arguments(int number_of_calling_args);
int write_number_into_array( int Array_of_numbers[]);

void message_correct_no_of_args();
void message_incorrect_no_of_args();
void message_file_exist();
void message_file_not_exist();
bool check_if_there_are_any_letters();
void message_about_letters_in_file();
int  count_numbers_in_the_file();

