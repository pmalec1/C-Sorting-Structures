#include "sorting_lib.h"
FILE *myfile;

int main(int argc,char **argv)
{
//Variables init
char path_to_file[NUMBEROFCHARS];
char sorting_category[NUMBEROFCHARS];
short operation_code = 0;
unsigned int amount_of_humans = 0;
bool parameter_of_direction;

//Checking correctivity of calling arguments 
if(check_number_of_arguments(argc)==false)
{  printf("Incorrect number of arguments\n Expected number of arguments(ext) is 3\n");
   exit(0);}
else printf("Number of arguments is correct :D\n");

copy_calling_arguments_to_strings(argv,path_to_file,sorting_category);
if(check_if_file_exists(path_to_file)==true) printf("File exists :D\n");
else
{printf("File doesn't exist\n");
 exit(0);}

//Geting data about sorting
operation_code = select_sorting_category(sorting_category,operation_code);
parameter_of_direction = get_information_about_direction_of_sorting();

//Reading structure from file 
myfile = fopen(path_to_file,"r");
amount_of_humans=count_humans();
Humans *humans = read_list_of_humans(amount_of_humans);
fclose(myfile);

//Sorting
switch_type_of_sorting(humans,amount_of_humans,parameter_of_direction,operation_code);

//Writeing to file and displaying on the screen
display_structs(humans,amount_of_humans);
write_list_of_humans_to_file(humans,amount_of_humans);
free(humans);
return 0;
}
