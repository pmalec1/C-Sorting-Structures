#include "new_sorting_lib.h"
extern FILE *myfile;

bool check_number_of_arguments(int argc)
{
 if(argc==EXPECTED_ARGS_NUMBER) return true;
 else  return false;
}
       
bool check_if_file_exists(char path_to_file[255]) 
{                                                          // remeber arg no.1 must be path to existing file or name of file in project enviroment
      if((myfile = fopen(path_to_file,"r")) == NULL)                   //check if file exist if no display a message to user
        {
          return false;
        } 
        else
        {
        fclose(myfile);
        return true;  
        }
}


void get_sorting_category(char sorting_category[NUMBEROFCHARS],short *ptr_to_operation_code)
{
  printf("\nsorting category is %s\n",sorting_category);\
  *ptr_to_operation_code = 0;
  if( strcmp( sorting_category, "age" )   == 0 ) *ptr_to_operation_code = 1;
  if( strcmp( sorting_category, "height") == 0 ) *ptr_to_operation_code = 2;
  if( strcmp( sorting_category, "name")   == 0 ) *ptr_to_operation_code = 3;
  if(*ptr_to_operation_code == 0)
  {
   printf("WRONG OPERATION CODE\n");
   exit(0);
  }
}

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

bool get_information_about_direction_of_sorting()
{
  char tempchar = '0';
   printf("\n A for ascending  or  D for descending\n");
  tempchar = getchar();
  if (tempchar=='A')
  {
    return true;
  }
  else if(tempchar=='D')
  {
    return false;
  }
  else  exit(0);
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
    printf("height =%.2f\n",humans[i].height);

  }
}

void write_list_of_humans(Humans_struct *humans,int amount_of_humans)
{
    fseek(myfile, 0, 0);
    for (int i = 0; i < amount_of_humans; i++)
    {
     fprintf(myfile,"Person %d:\n",i+1);
     fprintf(myfile,"    Name: %s\n",humans[i].name);
     fprintf(myfile,"     Age: %d\n",humans[i].age);
     fprintf(myfile,"  Height: %.2f\n",humans[i].height);
     fprintf(myfile,"\n");
    
    }
    fseek(myfile, 0, 0);
}

void swap(Humans_struct *humans, Humans_struct temp,unsigned int i)
{
  temp= humans[i+1];
  humans[i+1]=humans[i];
  humans[i]=temp;
}

void sort_struct_by_int(Humans_struct *humans, Humans_struct temp,int amount_of_humans,bool parameter_of_direction)
{
  do
  {
    amount_of_humans--;
    for(unsigned int i = 0; i<(unsigned int)amount_of_humans; i++)
    {
        if (humans[i].age>humans[i+1].age && parameter_of_direction==true)
        {
          swap(humans,temp,i);
        }
        if (humans[i].age<humans[i+1].age && parameter_of_direction==false)
        {
          swap(humans,temp,i);
        }
    }
  
  } while (amount_of_humans>0);

}

void sort_struct_by_float(Humans_struct *humans, Humans_struct temp,int amount_of_humans,bool parameter_of_direction)
{
   do
  {
    amount_of_humans--;
    for(unsigned int i = 0; i<(unsigned int)amount_of_humans; i++)
    {
        if (humans[i].height>humans[i+1].height && parameter_of_direction==true)
        {
          swap(humans,temp,i);
        }
           if (humans[i].height<humans[i+1].height && parameter_of_direction==false)
        {
          swap(humans,temp,i);
        }
    }
  } while (amount_of_humans>0);
}

void sort_struct_by_string(Humans_struct *humans, Humans_struct temp,int amount_of_humans,bool parameter_of_direction)
{
  do
  {
    amount_of_humans--;
    for(unsigned int i = 0; i<(unsigned int)amount_of_humans; i++)
    {
        if ((strcoll(humans[i].name,humans[i+1].name) > 0) && parameter_of_direction==true)
        {
          swap(humans,temp,i);
        }
           if ((strcoll(humans[i].name,humans[i+1].name) <0) && parameter_of_direction==false)
        {
          swap(humans,temp,i);
        }
    }
  } while (amount_of_humans>0);
}


void bubble_sort(Humans_struct *humans,int amount_of_humans,bool parameter_of_direction,short operation_code)
{
  printf("OPERATION CODE = %hd",operation_code);
  Humans_struct temp;
  switch (operation_code)
  {
  case 1:
    sort_struct_by_int(humans,temp,amount_of_humans,parameter_of_direction);
    break;
  case 2:
      sort_struct_by_float(humans,temp,amount_of_humans,parameter_of_direction);
      break;
  case 3:
    sort_struct_by_string(humans,temp,amount_of_humans,parameter_of_direction);
    break;
  default:
    printf("WRONG OPERATION CODE\n");
    exit(0);
    break;
  }  
}
