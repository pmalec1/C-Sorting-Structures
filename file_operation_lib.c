

#include "file_operation_lib.h"
extern FILE *myfile;


int count_numbers_in_the_file()
{
 int znak = 0;
 int amount_of_numbers = 0;
 
 while(znak!=EOF)
 {   
    znak = getc(myfile); 
    if(isdigit(znak)>0)
    {   znak = getc(myfile); 
        if(ispunct(znak)>0) ++amount_of_numbers;
        else 
        {   if(znak==EOF)++amount_of_numbers;
            fseek(myfile,1,1);
        }
    }
  } 
  return amount_of_numbers;
}


bool check_if_there_are_any_letters()
{
 int ilosc_bledow =0;
 int znak = 0;
    while((znak!=EOF))
    {
    znak = getc(myfile);
    if(isalpha(znak)>0)
    {
        ++ilosc_bledow;
    }
    }
       if(ilosc_bledow!=0)return true;
    else return false;
}

void message_about_letters_in_file()
{
    printf("INCORRECT FILE FORMAT\n");
    printf("The file cannot contain letters\n");
}

int write_number_into_array( int Array_of_numbers[new_size_of_array])
{
 int temp_number = 0;
 int index_in_array = 0;
 fseek(myfile,0,0);
 while(index_in_array<new_size_of_array)
 {
    fscanf(myfile,"%d",&temp_number);
    fseek(myfile,1,1);
    Array_of_numbers[index_in_array]=temp_number;
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
