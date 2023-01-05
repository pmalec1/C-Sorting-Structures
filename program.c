#include "new_sorting_lib.h"
FILE *myfile;


int main(int argc,char **argv)
{
char path_to_file[NUMBEROFCHARS];
char sorting_category[NUMBEROFCHARS];
short operation_code = 0;
short *ptr_to_operation_code = &operation_code;
int amount_of_humans = 0;
copy_arguments_to_chars(argv,path_to_file,sorting_category);
get_operation_code(sorting_category,ptr_to_operation_code);
myfile = fopen(path_to_file,"r");\
fseek(myfile,0,0);
amount_of_humans=count_humans();
Humans_struct *humans = read_list_of_humans(amount_of_humans);
fclose(myfile);
bubble_sort(humans,operation_code,amount_of_humans);
printf("\nQuantinity of humans = %d\n\n",amount_of_humans);
display_structs(humans,amount_of_humans);
free(humans);
return 0;
}