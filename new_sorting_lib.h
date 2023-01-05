#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBEROFCHARS 128

typedef struct
{
    int id;
    char name[NUMBEROFCHARS];
    int age;
    float height;
} Humans_struct;

void get_new_line(char temp_line[NUMBEROFCHARS]);
Humans_struct *read_list_of_humans(int amount_of_humans);
void get_operation_code(char sorting_category[NUMBEROFCHARS],short *ptr_to_operation_code);
int count_humans();
void copy_arguments_to_chars(char **argv,char path_to_file[NUMBEROFCHARS],char sorting_category[NUMBEROFCHARS]);
void display_structs(Humans_struct *humans,unsigned int amount_of_structs);
void bubble_sort_by_age(Humans_struct *humans,unsigned int amount_of_structs);
void bubble_sort_by_height(Humans_struct *humans,unsigned int amount_of_structs);
void bubble_sort(Humans_struct *humans,short operation_code,unsigned int amount_of_structs);
