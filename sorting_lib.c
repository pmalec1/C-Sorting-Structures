#include "sorting_lib.h"
FILE *myfile;

bool check_number_of_arguments(int argc)
{
 if(argc==EXPECTED_ARGS_NUMBER) return true;
 else  return false;
}
       
bool check_if_file_exists(char path_to_file[NUMBEROFCHARS]) 
{                                                          // remeber arg no.1 must be path to existing file or name of file in project enviroment
  if((myfile = fopen(path_to_file,"r")) == NULL) return false;
  else
  {
  fclose(myfile);
  return true;  
  }
}


int select_sorting_category(char sorting_category[NUMBEROFCHARS],short operation_code)
{
  printf("\nsorting category is %s\n",sorting_category);\
  operation_code = 0;
  if( strncmp( sorting_category, "age", NUMBEROFCHARS )   == 0 ) operation_code = 1;
  if( strncmp( sorting_category, "height", NUMBEROFCHARS) == 0 ) operation_code = 2;
  if( strncmp( sorting_category, "name", NUMBEROFCHARS)   == 0 ) operation_code = 3;
  if(operation_code == 0)
  {
   printf("WRONG OPERATION CODE\n");
   exit(0);
  }
  return operation_code;
}

void go_to_new_line()
{
  char temp_char = '0';
  while((temp_char = fgetc(myfile)) != '\n' && temp_char != EOF);
}

bool get_information_about_direction_of_sorting()
{
  char tempchar = '0';
   printf("\n A for ascending  or  D for descending\n");
  tempchar = getchar();
  if (tempchar=='A') return true;
  else if(tempchar=='D') return false;
  else  exit(0);
}


Humans *read_list_of_humans(unsigned int amount_of_humans)
{
    
    Humans *humans = (Humans *)malloc(amount_of_humans * (sizeof(Humans)));
    fseek(myfile,0,0);
    char temp_line[NUMBEROFCHARS];
    for (unsigned int i = 0; i < amount_of_humans; i++)
    {
        fscanf(myfile,"%s",temp_line);
        go_to_new_line();
        if (strncmp(temp_line, EACH_STRUCT_IDENTIFIER, NUMBEROFCHARS) == 0)
        {
          fscanf(myfile,"\nName: %s",humans[i].name);
          fscanf(myfile,"\nAge: %d",&humans[i].age);
          fscanf(myfile,"\nHeight: %f",&humans[i].height);
          go_to_new_line();
        }
    }
    fseek(myfile, 0, 0);
    return humans;
}

int count_humans()
{
    fseek(myfile,0,0);
    unsigned int amount_of_structs = 0;
    char temp_char = '0';
    char temp_line[NUMBEROFCHARS];
    fseek(myfile,0,0);
    while((temp_char = fgetc(myfile))!=EOF)
    {
      fseek(myfile,(-1),1);
      fgets(temp_line,NUMBEROFCHARS,myfile);
      if(strncmp(temp_line,EACH_STRUCT_IDENTIFIER,6)==0) ++amount_of_structs;     
    }
   return amount_of_structs;
}

void copy_calling_arguments_to_strings(char **argv,char path_to_file[NUMBEROFCHARS],char sorting_category[NUMBEROFCHARS])
{
  strncpy(sorting_category,argv[2],NUMBEROFCHARS);
  strncpy(path_to_file,argv[1],NUMBEROFCHARS);
}

void display_structs(Humans *humans,unsigned int amount_of_structs)
{
  for(unsigned int i = 0; i<amount_of_structs; i++)
  {
    printf(EACH_STRUCT_IDENTIFIER "%d ", i+1);
    printf("Name =%s, ",humans[i].name);
    printf("age =%d, ",humans[i].age);
    printf("height =%.2f\n",humans[i].height);
  }
}

void write_list_of_humans_to_file(Humans *humans,unsigned int amount_of_humans)
{
  myfile = fopen("sorted_humans.txt","w"); 
    fseek(myfile, 0, 0);
    for (unsigned int i = 0; i < amount_of_humans; i++)
    {
     fprintf(myfile,"Person %d:\n",i+1);
     fprintf(myfile,"Name: %s\n",humans[i].name);
     fprintf(myfile,"Age: %d\n",humans[i].age);
     fprintf(myfile,"Height: %.2f\n",humans[i].height);
     fprintf(myfile,"\n");
    }
  fclose(myfile);
}

void swap(Humans *humans, Humans temp,unsigned int i)
{
  temp= humans[i+1];
  humans[i+1]=humans[i];
  humans[i]=temp;
}

void sort_struct_by_int(Humans *humans, Humans temp,unsigned int amount_of_humans,bool parameter_of_direction)
{
  do
  {
    amount_of_humans--;
    for(unsigned int i = 0; i< amount_of_humans; i++)
    {
        if ((humans[i].age>humans[i+1].age) && parameter_of_direction==true) swap(humans,temp,i);
        if ((humans[i].age<humans[i+1].age) && parameter_of_direction==false) swap(humans,temp,i);
    }
  } while (amount_of_humans>0);

}

void sort_struct_by_float(Humans *humans, Humans temp,unsigned int amount_of_humans,bool parameter_of_direction)
{
   do
  {
    amount_of_humans--;
    for(unsigned int i = 0; i<amount_of_humans; i++)
    {
        if ((humans[i].height>humans[i+1].height) && parameter_of_direction==true) swap(humans,temp,i);
        if ((humans[i].height<humans[i+1].height) && parameter_of_direction==false) swap(humans,temp,i);
    }
  } while (amount_of_humans>0);
}

void sort_struct_by_string(Humans *humans, Humans temp,unsigned int amount_of_humans,bool parameter_of_direction)
{
  do
  { amount_of_humans--;
    for(unsigned int i = 0; i<amount_of_humans; i++)
    {
        if ((strcoll(humans[i].name,humans[i+1].name) > 0) && parameter_of_direction==true) swap(humans,temp,i);
        if ((strcoll(humans[i].name,humans[i+1].name) <0) && parameter_of_direction==false) swap(humans,temp,i);
    }
  } while (amount_of_humans>0);
}

void switch_type_of_sorting(Humans *humans,unsigned int amount_of_humans,bool parameter_of_direction,short operation_code)
{ 
  Humans temp;
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
    printf("CATEGORY OF SORTING\n");
    exit(0);
    break;
  }
}
