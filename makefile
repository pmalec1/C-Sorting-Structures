PROGRAM_NAME = mal1.c
LIB_NAME = new_sorting_lib.c
EXEC_NAME = exe
TEXT_FILE_NAME = humans.txt

compile:
		gcc ${PROGRAM_NAME} ${LIB_NAME}  -o ${EXEC_NAME}
age:
			./${EXEC_NAME} ${TEXT_FILE_NAME} age
height:
			./${EXEC_NAME} ${TEXT_FILE_NAME} height
name:
			./${EXEC_NAME} ${TEXT_FILE_NAME} name
wrong:
			./${EXEC_NAME} ${TEXT_FILE_NAME} wrong