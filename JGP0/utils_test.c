#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "utils.h"

//show code to console & excute code
#define scode(expression) printf("%s\n",#expression); expression
// assert
#define massert(expression) printf("Assert Expression : %s\n",#expression); assert(expression) 

char PATH_C[] = "C:\\";
char PATH_E[] = "E:\\";
char STR_EMPTY[] = "";
char PATH_INVALID_ABS[] = "C:\\!";
char PATH_INVALID_REL[] = ".\\!";

char PATH_PWD_REL[] =".";
char PATH_PARENT_REL[] = "..";

//다른 컴퓨터에서 테스트시 경로 수정
char PATH_TEST_DIR[]="C:\\Users\\dojh9\\test";
char PATH_TEST_SUBDIR[] = "C:\\Users\\dojh9\\test\\subtestfolder";
char PATH_TEST_SUBFILE1[] = "C:\\Users\\dojh9\\test\\test1.txt";

char PATH_TEST_SUBDIR_REL[] = ".\\subtestfolder";
char PATH_TEST_SUBFILE1_REL[] = ".\\test1.txt";

char TEMP[500];


int main(void){

	/*
		cd(char* arg)
		프로그램의 현제경로를 arg로 변경.
		오류발생시 1 반환
	*/
	//TODO : subprocess 경로 체크, directory 값 확인
	printf("----- cd -----\n");
	char STR_AAA_AAA[] = "AAA AAA";
	massert(cd(STR_EMPTY) == 1);
	massert(cd(STR_AAA_AAA) == 1);
	massert(cd(NULL) == 1);
	massert(cd(PATH_C) == 0);
	massert(cd(PATH_TEST_DIR) == 0);
	printf("PASSED\n\n");

	/*
		isPathValid(char*)
		유효한 경로인가를 판단
		유효한 경우 1, 아닌경우 0 반환
	*/
	printf("----- isPathValid(char*) -----\n");
	massert(isPathValid(PATH_PWD_REL) == 1); // 상대경로로 현재경로
	massert(isPathValid(PATH_PARENT_REL) == 1);  // 상대경로로 상위경로
	massert(isPathValid(PATH_C) == 1); // C드라이브 경로
	massert(isPathValid(PATH_INVALID_ABS) == 0); //유효하지 않은 경로
	massert(isPathValid(PATH_INVALID_REL) == 0); //유효하지 않은 경로
	massert(isPathValid(STR_EMPTY) == 0); //빈 문자열
	massert(isPathValid(PATH_TEST_DIR) == 1); //절대경로 폴더
	massert(isPathValid(PATH_TEST_SUBDIR) == 1); //상대경로 폴더
	massert(isPathValid(PATH_TEST_SUBFILE1) == 1); //절대경로 파일
	massert(isPathValid(PATH_TEST_SUBFILE1_REL) == 1); //상대경로 파일
	printf("PASSED\n\n");

	/*
		isDir(char *path)
		경로가 디렉토리인가?
		디렉토리 일경우 0이 아닌 값, 아닌경우 0 반환
	*/
	printf("----- isDir(char *path) -----\n");
	massert(isDir(".") != 0); // 상대경로로 현재경로
	massert(isDir("..") != 0);  // 상대경로로 상위경로
	massert(isDir(PATH_C) != 0); // C드라이브 경로
	massert(isDir(PATH_INVALID_ABS) == 0); //유효하지 않은 경로
	massert(isDir(PATH_INVALID_REL) == 0); //유효하지 않은 경로
	massert(isDir(STR_EMPTY) == 0); //빈 문자열
	massert(isDir(PATH_TEST_DIR) != 0); //절대경로 폴더
	massert(isDir(PATH_TEST_SUBDIR) != 0); //상대경로 폴더
	massert(isDir(PATH_TEST_SUBFILE1) == 0); //절대경로 파일
	massert(isDir(PATH_TEST_SUBFILE1_REL) == 0); //상대경로 파일

	printf("PASSED\n\n");

	/*
		getFullPath(char* partialPath, char* dest);
		상대경로를 절대경로로 변환해준다.
		오류가 없을 때 0 반환 , 오류발생시 1 반환

		단, 입력된 partialPath가 이미 절대경로인경우 그 절대경로를 그대로 출력
	*/

	printf("----- getFullPath(char* partialPath, char* dest) -----\n");
	char PATH_PARTIAL[] = "ABC";
	char PATH_FULL[_MAX_DIR];
	strcpy(PATH_FULL,PATH_TEST_DIR);
	strcat(PATH_FULL, "\\");
	strcat(PATH_FULL, PATH_PARTIAL);

	scode(getFullPath(PATH_PARTIAL,TEMP));
	printf("Partial : %s\nExpected Full : %s\nResult : %s\n", PATH_PARTIAL, PATH_FULL, TEMP);
	massert(strcmp(TEMP,PATH_FULL) == 0);
	printf("\n");

	scode(getFullPath(PATH_FULL, TEMP));
	printf("Partial : %s\nExpected Full : %s\nResult : %s\n", PATH_PARTIAL, PATH_FULL, TEMP);
	massert(strcmp(TEMP, PATH_FULL) == 0);
	printf("\n");

	scode(getFullPath(PATH_TEST_SUBDIR_REL, TEMP));
	printf("Partial : %s\nExpected Full : %s\nResult : %s\n", PATH_TEST_SUBDIR_REL, PATH_TEST_SUBDIR, TEMP);
	massert(strcmp(TEMP, PATH_TEST_SUBDIR) == 0);
	printf("\n");

	scode(getFullPath(PATH_TEST_DIR, TEMP));
	printf("Partial : %s\nExpected Full : %s\nResult : %s\n", PATH_TEST_DIR, PATH_TEST_DIR, TEMP);
	massert(strcmp(TEMP, PATH_TEST_DIR) == 0);
	printf("\n");

	printf("PASSED\n\n");


	/*
		isCommandExist(char* command)
		command 존재할 때 CMD객체의 주소를 반환함
		존재하지 않을경우 0 반환
	*/
	printf("-----isCommandExist(char* command) -----\n");
	char STR_CMD_INV[] = "NOCOMMAND";
	char STR_CMD_CD[] = "cd";
	char STR_CMD_EXIT[] = "exit";
	char STR_CMD_MAKE[] = "make";
	CMD* cmd_tmp = 0;
	scode(cmd_tmp = isCommandExist(STR_CMD_INV));
	massert(cmd_tmp == 0);
	scode(cmd_tmp = isCommandExist(STR_CMD_CD));
	massert(cmd_tmp != 0);
	massert(strcmp(cmd_tmp->cmd_char,STR_CMD_CD) == 0);
	scode(cmd_tmp = isCommandExist(STR_CMD_EXIT));
	massert(cmd_tmp != 0);
	massert(strcmp(cmd_tmp->cmd_char, STR_CMD_EXIT) == 0);
	scode(cmd_tmp = isCommandExist(STR_CMD_MAKE));
	massert(cmd_tmp != 0);
	massert(strcmp(cmd_tmp->cmd_char, STR_CMD_MAKE) == 0);

	printf("PASSED\n\n");

	/*
		char** getCommandWithArg(char* buffer);
		명령어와 인자로 구분함.

		freeCommandWithArg(char ** cmd_arg);
		getCommandWithArg 에서 생성한 배열 해제

	*/
	printf("----- getCommandWithArg(char* buffer) & freeCommandWithArg(char ** cmd_arg) -----\n");
	char** ca = getCommandWithArg("");
	massert(ca == 0);
	scode(ca = getCommandWithArg("cmd"));
	massert((strcmp(ca[0],"cmd") == 0) & (ca[1] == 0));
	scode(freeCommandWithArg(ca));

	scode(ca = getCommandWithArg("cmd arg"));
	massert((strcmp(ca[0], "cmd") == 0) & (strcmp(ca[1], "arg") == 0));
	scode(freeCommandWithArg(ca));


	printf("PASSED\n\n");

	/*
		ls(char* arg)
	*/
	
	printf("----- ls -----\n");
	massert(ls(".") == 0);	//상대경로 with dot
	massert(ls("..") == 0);	//상대경로 with dot
	massert(ls(".\\subtestfolder") == 0); //상대경로 폴더 with dot
	massert(ls(".\\nopath") == 1); //존재하지 않는 경로 with dot
	massert(ls(".\\test1.txt") == 0); //상대경로 파일 with dot
	massert(ls("subtestfolder") == 0); //상대경로 폴더 without dot
	massert(ls("nopath") == 1); //존재하지 않는 경로 without dot
	massert(ls("test1.txt") == 0); //상대경로 파일 without dot
	massert(ls("워드파일1.docx") == 0); //상대경로 파일 without dot
	massert(ls("C:\\Users\\dojh9\\test") == 0); //절대경로 폴더
	massert(ls("C:\\Users\\dojh9\\test\\test1.txt") == 0); //절대경로 파일
	massert(ls("C:\\Users\\dojh9\\test\\nopath") == 1); //절대경로 존재하지 않는 경로


	massert(ls("*") == 0); //wildcard
	massert(ls(".\\*") == 0); //wildcard
	massert(ls("*.txt") == 0); //wildcard front
	massert(ls("*.docx") == 0); //wildcard front
	massert(ls("test*") == 0); //wildcard back
	massert(ls("t*t") == 0); //wildcard mid
	massert(ls("t*.*t") == 0); //two wildcard
	massert(ls("test.aaa*aa") == 1); // wildcard , 경로 없음
	massert(ls("워*파*")==0); //wildcard with korean
	massert(ls("C:\\Users\\dojh9\\test\\t*t") == 0); //wild card 절대경로 


	/*
		getPathFromUser()
		유저에게 받은 문자열이 directory배열에 입력됨
	*/

	// 아무것도 입력을 하지 않은 체 enter를 누른경우 directory 값은 이전과 같음
	
}