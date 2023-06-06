# Piotr Malec

### downloading the book collection, sorting and saving the structure to a file   
### an exercise in dynamic memory allocation


# variables
1. char path_to_file[NUMBEROFCHARS];
2. char sorting_category[NUMBEROFCHARS];
3. short operation_code = 0;
4. short *ptr_to_operation_code = &operation_code;
5. int amount_of_humans = 0;
6. bool parameter_of_direction;
7. Humans_struct *humans;

# consts
1. NUMBEROFCHARS 128
2. EXPECTED_ARGS_NUMBER 3

# output results
Program saves sorted structure from input file in output file 

and keep the same format

Program also shows sorted struct in text terminal 

in line by line format
# functions
* Colecting data functions
1. void copy_arguments_to_chars 
2. int count_humans() ----> count amount of humans in input file
3. bool get_information_about_direction_of_sorting(); ----> Ascending or Descening
4. Humans_struct *read_list_of_humans(int amount_of_humans); --> read structures from file 
5. void get_sorting_category
6. void get_new_line ---->get new line in text file 
* Checking correctivity functions
1. bool check_if_file_exists ----> check if path points to existing file 
2. bool check_number_of_arguments ---> check if number of arguments == EXPECTED_ARGS_NUMBER
* Sorting functions 
1. void swap ----> change the order of two elements
2. void bubble_sort
3. void sort_struct_by_int
4. void sort_struct_by_float
5. void sort_struct_by_string
* Writeing and displaying functions 
1. void display_structs ----> show structs in text terminal
2. void write_list_of_humans ----> write structs in text file

# rules

Expected number of arguments = 3

1. program itself (example   ./exe)
2. path to file
3. sorting category

* Path to file should point to an existing file

* Input file should be written in valid format.

Valid format - in exemplary text file "humans.txt" in this repository 

# usage

1. make compile
2. make <"name of category"> 

 
# exemplary results

Image called "EXEMPLARY_USAGE" that shows examplary usage is located in this repository 
