//Needed headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define EACH_STRUCT_IDENTIFIER "Person"
#define NUMBEROFCHARS 128
#define EXPECTED_ARGS_NUMBER 3
//Define structure that storages informations about humans
typedef struct
{
    char name[NUMBEROFCHARS];
    unsigned int age;
    float height;
} Humans;

//Colecting data section
void copy_calling_arguments_to_strings(char **argv,char path_to_file[NUMBEROFCHARS],char sorting_category[NUMBEROFCHARS]);
int count_humans();
bool get_information_about_direction_of_sorting();
Humans *read_list_of_humans(unsigned int amount_of_humans);
int select_sorting_category(char sorting_category[NUMBEROFCHARS], short operation_code);
void go_to_new_line();

//Checking correctivity section
bool check_if_file_exists(char path_to_file[NUMBEROFCHARS]);
bool check_number_of_arguments(int argc);


//Sorting section
void swap(Humans *humans, Humans temp,unsigned int i);
void switch_type_of_sorting(Humans *humans,unsigned int amount_of_humans,bool parameter_of_direction,short operation_code);
void sort_struct_by_int(Humans *humans, Humans temp,unsigned int amount_of_humans,bool parameter_of_direction);
void sort_struct_by_float(Humans *humans, Humans temp,unsigned int amount_of_humans,bool parameter_of_direction);
void sort_struct_by_string(Humans *humans, Humans temp,unsigned int amount_of_humans,bool parameter_of_direction);

//Writeing and displaying section
void display_structs(Humans *humans,unsigned int amount_of_structs);
void write_list_of_humans_to_file(Humans *humans,unsigned int amount_of_humans);
