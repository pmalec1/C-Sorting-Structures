#include "new_sorting_lib.h"
extern FILE *myfile;

void get_new_line(char temp_line[NUMBEROFCHARS])
{
  char temp_char = '0';
  int index_in_line = 0;
    while((temp_char = fgetc(myfile)) != '\n' && temp_char != EOF)
    {
       temp_line[index_in_line]=temp_char;
      ++index_in_line;
    }
}


Humans_struct *read_list_of_humans(int amount_of_humans)
{
    Humans_struct *humans = (Humans_struct *)malloc(amount_of_humans * (sizeof(Humans_struct)));
    char temp_line[NUMBEROFCHARS];
    for (int i = 0; i < amount_of_humans; i++)
    {
        get_new_line(temp_line);
        if (strncmp(temp_line, "Person", 6) == 0)
        {
            fseek(myfile, 1, 1);
            fseek(myfile, 9, 1);
            fscanf(myfile, "%s", humans[i].name);
            get_new_line(temp_line);

            fseek(myfile, 1, 1);
            fseek(myfile, 9, 1);
            fscanf(myfile, "%d", &humans[i].age);
            get_new_line(temp_line);

            fseek(myfile, 1, 1);
            fseek(myfile, 9, 1);
            fscanf(myfile, "%f", &humans[i].height);
            get_new_line(temp_line);
            fseek(myfile, 1, 1);
        }
    }
    fseek(myfile, 0, 0);
    return humans;
}





int count_humans()
{
    int amount_of_structs = 0;
    char temp_char = '0';
    char temp_line[NUMBEROFCHARS];
   // FILE *myfile = fopen(path_to_file,"r");
    fseek(myfile,0,0);
    while((temp_char = fgetc(myfile))!=EOF)
    {
      fseek(myfile,(-1),1);
      get_new_line(temp_line);
      if(strncmp(temp_line,"Person",6)==0) ++amount_of_structs;
      fseek(myfile,1,1);
    }
   // fclose(myfile);
   fseek(myfile,0,0);
   return amount_of_structs;
}

void copy_arguments_to_chars(char **argv,char path_to_file[NUMBEROFCHARS],char sorting_category[NUMBEROFCHARS])
{
  strncpy(sorting_category,argv[2],NUMBEROFCHARS);
  strncpy(path_to_file,argv[1],NUMBEROFCHARS);
}


void display_structs(Humans_struct *humans,unsigned int amount_of_structs)
{
  for(short i = 0; i<(short)amount_of_structs; i++)
  {
    printf("Person %d ", i+1);
    printf("Name =%s, ",humans[i].name);
    printf("age =%d, ",humans[i].age);
    printf("height =%f\n",humans[i].height);

  }
}



void bubble_sort_by_age(Humans_struct *humans,unsigned int amount_of_structs)
{
  do
  {
    for (unsigned short i = 0; i <(unsigned short)amount_of_structs-1; i++)
    {
      if (humans[i].age> humans[i+1].age)
      {
        humans[amount_of_structs]=humans[i+1];
        humans[i+1]= humans[i];
        humans[i]= humans[amount_of_structs];
      }
    }
  -- amount_of_structs;
  } while (amount_of_structs>1);
  
}


void bubble_sort_by_name(Humans_struct *humans,unsigned int amount_of_structs)
{
  do
  {
    for (unsigned short i = 0; i <(unsigned short)amount_of_structs-1; i++)
    {
      if (strncmp(humans[i].name,humans[i+1].name,128)>0)
      {
        humans[amount_of_structs]=humans[i+1];
        humans[i+1]= humans[i];
        humans[i]= humans[amount_of_structs];
      }
     

    }
  -- amount_of_structs;
  } while (amount_of_structs>1);
}


void bubble_sort_by_height(Humans_struct *humans,unsigned int amount_of_structs)
{
  do
  {
    for (short i = 0; i <(short)amount_of_structs-1; i++)
    {
      if (humans[i].height > humans[i+1].height)
      {
        humans[amount_of_structs]=humans[i+1];
        humans[i+1]= humans[i];
        humans[i]= humans[amount_of_structs];
      }
    }
  -- amount_of_structs;
  } while (amount_of_structs>1);
}





void bubble_sort(Humans_struct *humans,short operation_code,unsigned int amount_of_structs)
{
 switch (operation_code)
 {
 case 1:
  bubble_sort_by_age(humans,amount_of_structs);
  break;
 case 2:
 bubble_sort_by_height(humans,amount_of_structs);
 break;
 case 3:
 bubble_sort_by_name(humans,amount_of_structs);
 break;
 default:
 printf("Wrong operation code!\n");
  
 }
}


void get_operation_code(char sorting_category[NUMBEROFCHARS],short *ptr_to_operation_code)
{
  if( strcmp( sorting_category, "age" )   == 0 ) *ptr_to_operation_code = 1;
  if( strcmp( sorting_category, "height") == 0 ) *ptr_to_operation_code = 2;
  if( strcmp( sorting_category, "name")   == 0 ) *ptr_to_operation_code = 3;
}
