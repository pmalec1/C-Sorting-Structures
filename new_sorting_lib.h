//Needed headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NUMBEROFCHARS 128
#define EXPECTED_ARGS_NUMBER 3
//Define structure that storages informations about humans
typedef struct
{
    char name[NUMBEROFCHARS];
    int age;
    float height;
} Humans_struct;

//Colecting data section
void copy_arguments_to_chars(char **argv,char path_to_file[NUMBEROFCHARS],char sorting_category[NUMBEROFCHARS]);
int count_humans();
bool get_information_about_direction_of_sorting();
Humans_struct *read_list_of_humans(int amount_of_humans);
void get_sorting_category(char sorting_category[NUMBEROFCHARS],short *ptr_to_operation_code);
void get_new_line(char temp_line[NUMBEROFCHARS]);

//Checking correctivity section
bool check_if_file_exists(char path_to_file[NUMBEROFCHARS]);
bool check_number_of_arguments(int argc);


//Sorting section
void swap(Humans_struct *humans, Humans_struct temp,unsigned int i);
void bubble_sort(Humans_struct *humans,int amount_of_humans,bool parameter_of_direction,short operation_code);
void sort_struct_by_int(Humans_struct *humans, Humans_struct temp,int amount_of_humans,bool parameter_of_direction);
void sort_struct_by_float(Humans_struct *humans, Humans_struct temp,int amount_of_humans,bool parameter_of_direction);
void sort_struct_by_string(Humans_struct *humans, Humans_struct temp,int amount_of_humans,bool parameter_of_direction);

//Writeing and displaying section
void display_structs(Humans_struct *humans,unsigned int amount_of_structs);
void write_list_of_humans(Humans_struct *humans,int amount_of_humans);
