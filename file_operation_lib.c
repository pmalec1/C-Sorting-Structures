
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_operation_lib.h"
extern FILE *myfile;



void read_numbers_from_file(int array_of_numbers[SIZE_OF_ARRAY_OF_NUMBERS],short amount_of_numbers)
{
    int temp_number;
    int index_in_array = 0;
    while(index_in_array<SIZE_OF_ARRAY_OF_NUMBERS)
    {
    fscanf(myfile,"%d",&temp_number);
    if(index_in_array == amount_of_numbers) break;
    array_of_numbers[index_in_array]=temp_number; 
    printf("%d\n",temp_number);
    fseek(myfile,1,1);
    ++index_in_array;
    }


}
void message_correct_no_of_args()
{
    printf("Number of arguments is correct :D\n");
}
void message_incorrect_no_of_args()
{
    printf("Incorrect number of arguments \n");
    printf("Expected number of arguments(ext) is 2\n");
}
void message_file_exist()
{
    printf("File exists :D\n");
}

void message_file_not_exist()
{
    printf("File doesn't exist\n");
}

int check_number_of_arguments(int argc)
{
    if (argc != NUMBER_OF_EXPECTED_EXT_ARGS)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int check_if_file_exists(char path_to_file[255])
{                                                    // remeber arg no.1 must be path to existing myfile or name of myfile in project enviroment
    if ((myfile = fopen(path_to_file, "r")) == NULL) // check if myfile exist if no display a message to user
    {
        return false;
    }
    else
    {
        fclose(myfile);
        return true;
    }
}
