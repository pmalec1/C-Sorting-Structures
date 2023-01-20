PROGRAM_NAME = program.c
LIB_NAME = sorting_lib.c
EXEC_NAME = exe
TEXT_FILE_NAME = humans.txt

compile:
		gcc ${PROGRAM_NAME} ${LIB_NAME}  -o ${EXEC_NAME} -Wall -Wextra
age:
			./${EXEC_NAME} ${TEXT_FILE_NAME} age
height:
			./${EXEC_NAME} ${TEXT_FILE_NAME} height
name:
			./${EXEC_NAME} ${TEXT_FILE_NAME} name
wrong_cat:
			./${EXEC_NAME} ${TEXT_FILE_NAME} wrong_sorting_cateogry
wrong_filename:
			./${EXEC_NAME} wrong_path.txt name
wrong_args:
			./${EXEC_NAME} 
