PROGRAM_NAME = program.c
LIB_NAME = new_sorting_lib.c
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
