#include "new_sorting_lib.h"
FILE *myfile;

int main(int argc,char **argv)
{
//Variables init
char path_to_file[NUMBEROFCHARS];
char sorting_category[NUMBEROFCHARS];
short operation_code = 0;
short *ptr_to_operation_code = &operation_code;
int amount_of_humans = 0;
bool parameter_of_direction;
copy_arguments_to_chars(argv,path_to_file,sorting_category);

//Checking correctivity of calling arguments 
if(check_number_of_arguments(argc)!=true)
   { printf("Incorrect number of arguments \n");
      printf("Expected number of arguments(ext) is 2\n");
      exit(0); }                        
else printf("Number of arguments is correct :D\n");
   

if(check_if_file_exists(path_to_file)==true) printf("File exists :D\n");
else
   {printf("File doesn't exist\n");
    exit(0); }

//Geting data about sorting
get_sorting_category(sorting_category,ptr_to_operation_code);
parameter_of_direction=get_information_about_direction_of_sorting();

//Reading structure from file section
myfile = fopen(path_to_file,"r");
fseek(myfile,0,0);
amount_of_humans=count_humans();
Humans_struct *humans = read_list_of_humans(amount_of_humans);
fclose(myfile);

//Sorting
bubble_sort(humans,amount_of_humans,parameter_of_direction,operation_code);

//Writeing and displaying section
printf("\nQuantinity of humans = %d\n\n",amount_of_humans);
display_structs(humans,amount_of_humans);
myfile = fopen("sorted_humans.txt","w"); 
write_list_of_humans(humans,amount_of_humans);//write sorted data to file sorted_humans.txt
fclose(myfile);
free(humans);
return 0;
}
