

#include <stdio.h>

#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0


#define NUMBER_OF_EXPECTED_EXT_ARGS 3
#define SIZE_OF_ARRAY_OF_NUMBERS    20

void read_numbers_from_file(int array_of_numbers[SIZE_OF_ARRAY_OF_NUMBERS],short amount_of_numbers);
int check_if_file_exists(char path_to_file[255]);
int check_number_of_arguments(int number_of_calling_args);

void message_correct_no_of_args();
void message_incorrect_no_of_args();
void message_file_exist();
void message_file_not_exist();
