/*
* util.h�� �Ϻ� �Լ� �׽�Ʈ ����
*/

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

//�ٸ� ��ǻ�Ϳ��� �׽�Ʈ�� ��� ����
char PATH_TEST_DIR[]="C:\\Users\\dojh9\\test";
char PATH_TEST_SUBDIR[] = "C:\\Users\\dojh9\\test\\subtestfolder";
char PATH_TEST_SUBFILE1[] = "C:\\Users\\dojh9\\test\\test1.txt";

char PATH_TEST_SUBDIR_REL[] = ".\\subtestfolder";
char PATH_TEST_SUBFILE1_REL[] = ".\\test1.txt";

char TEMP[500];


int main(void){

	/*
		cd(char* arg)
		���α׷��� ������θ� arg�� ����.
		�����߻��� 1 ��ȯ
	*/
	//TODO : subprocess ��� üũ, directory �� Ȯ��
	//printf("----- cd -----\n");
	//char STR_AAA_AAA[] = "AAA AAA";
	//massert(cd(STR_EMPTY) == 1);
	//massert(cd(STR_AAA_AAA) == 1);
	//massert(cd(NULL) == 1);
	//massert(cd(PATH_C) == 0);
	//massert(cd(PATH_TEST_DIR) == 0);
	//printf("PASSED\n\n");

	///*
	//	isPathValid(char*)
	//	��ȿ�� ����ΰ��� �Ǵ�
	//	��ȿ�� ��� 1, �ƴѰ�� 0 ��ȯ
	//*/
	//printf("----- isPathValid(char*) -----\n");
	//massert(isPathValid(PATH_PWD_REL) == 1); // ����η� ������
	//massert(isPathValid(PATH_PARENT_REL) == 1);  // ����η� �������
	//massert(isPathValid(PATH_C) == 1); // C����̺� ���
	//massert(isPathValid(PATH_INVALID_ABS) == 0); //��ȿ���� ���� ���
	//massert(isPathValid(PATH_INVALID_REL) == 0); //��ȿ���� ���� ���
	//massert(isPathValid(STR_EMPTY) == 0); //�� ���ڿ�
	//massert(isPathValid(PATH_TEST_DIR) == 1); //������ ����
	//massert(isPathValid(PATH_TEST_SUBDIR) == 1); //����� ����
	//massert(isPathValid(PATH_TEST_SUBFILE1) == 1); //������ ����
	//massert(isPathValid(PATH_TEST_SUBFILE1_REL) == 1); //����� ����
	//printf("PASSED\n\n");

	///*
	//	isDir(char *path)
	//	��ΰ� ���丮�ΰ�?
	//	���丮 �ϰ�� 0�� �ƴ� ��, �ƴѰ�� 0 ��ȯ
	//*/
	//printf("----- isDir(char *path) -----\n");
	//massert(isDir(".") != 0); // ����η� ������
	//massert(isDir("..") != 0);  // ����η� �������
	//massert(isDir(PATH_C) != 0); // C����̺� ���
	//massert(isDir(PATH_INVALID_ABS) == 0); //��ȿ���� ���� ���
	//massert(isDir(PATH_INVALID_REL) == 0); //��ȿ���� ���� ���
	//massert(isDir(STR_EMPTY) == 0); //�� ���ڿ�
	//massert(isDir(PATH_TEST_DIR) != 0); //������ ����
	//massert(isDir(PATH_TEST_SUBDIR) != 0); //����� ����
	//massert(isDir(PATH_TEST_SUBFILE1) == 0); //������ ����
	//massert(isDir(PATH_TEST_SUBFILE1_REL) == 0); //����� ����

	//printf("PASSED\n\n");

	///*
	//	getFullPath(char* partialPath, char* dest);
	//	����θ� �����η� ��ȯ���ش�.
	//	������ ���� �� 0 ��ȯ , �����߻��� 1 ��ȯ

	//	��, �Էµ� partialPath�� �̹� �������ΰ�� �� �����θ� �״�� ���
	//*/

	//printf("----- getFullPath(char* partialPath, char* dest) -----\n");
	//char PATH_PARTIAL[] = "ABC";
	//char PATH_FULL[_MAX_DIR];
	//strcpy(PATH_FULL,PATH_TEST_DIR);
	//strcat(PATH_FULL, "\\");
	//strcat(PATH_FULL, PATH_PARTIAL);

	//scode(getFullPath(PATH_PARTIAL,TEMP));
	//printf("Partial : %s\nExpected Full : %s\nResult : %s\n", PATH_PARTIAL, PATH_FULL, TEMP);
	//massert(strcmp(TEMP,PATH_FULL) == 0);
	//printf("\n");

	//scode(getFullPath(PATH_FULL, TEMP));
	//printf("Partial : %s\nExpected Full : %s\nResult : %s\n", PATH_PARTIAL, PATH_FULL, TEMP);
	//massert(strcmp(TEMP, PATH_FULL) == 0);
	//printf("\n");

	//scode(getFullPath(PATH_TEST_SUBDIR_REL, TEMP));
	//printf("Partial : %s\nExpected Full : %s\nResult : %s\n", PATH_TEST_SUBDIR_REL, PATH_TEST_SUBDIR, TEMP);
	//massert(strcmp(TEMP, PATH_TEST_SUBDIR) == 0);
	//printf("\n");

	//scode(getFullPath(PATH_TEST_DIR, TEMP));
	//printf("Partial : %s\nExpected Full : %s\nResult : %s\n", PATH_TEST_DIR, PATH_TEST_DIR, TEMP);
	//massert(strcmp(TEMP, PATH_TEST_DIR) == 0);
	//printf("\n");

	//printf("PASSED\n\n");


	/*
		isCommandExist(char* command)
		command ������ �� CMD��ü�� �ּҸ� ��ȯ��
		�������� ������� 0 ��ȯ
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
		��ɾ�� ���ڷ� ������.

		freeCommandWithArg(char ** cmd_arg);
		getCommandWithArg ���� ������ �迭 ����

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
		int getRenameType(const char* str)
	*/
	massert(getRenameType("str") == -1);
	massert(getRenameType("*str") == 1);
	massert(getRenameType("str*") == 2);
	massert(getRenameType("*str*") == 3);
	massert(getRenameType("str*str") == 4);
	massert(getRenameType("*") == -1);
	massert(getRenameType("**") == -1);
	massert(getRenameType("***") == -1 );
	massert(getRenameType("*str*str") == -1);
	massert(getRenameType("*str*str*") == -1);
	massert(getRenameType("") == -1);
	printf("PASSED\n\n");

	/*
		ls(char* arg)
	*/
	
	printf("----- ls -----\n");
	massert(ls("") == 0); // �� ���ڿ�
	massert(ls(".") == 0);	//����� with dot
	massert(ls("..") == 0);	//����� with dot
	massert(ls(".\\subtestfolder") == 0); //����� ���� with dot
	massert(ls(".\\nopath") == 1); //�������� �ʴ� ��� with dot
	massert(ls(".\\test1.txt") == 0); //����� ���� with dot
	massert(ls("subtestfolder") == 0); //����� ���� without dot
	massert(ls("nopath") == 1); //�������� �ʴ� ��� without dot
	massert(ls("test1.txt") == 0); //����� ���� without dot
	massert(ls("��������1.docx") == 0); //����� ���� without dot
	massert(ls("C:\\Users\\dojh9\\test") == 0); //������ ����
	massert(ls("C:\\Users\\dojh9\\test\\test1.txt") == 0); //������ ����
	massert(ls("C:\\Users\\dojh9\\test\\nopath") == 1); //������ �������� �ʴ� ���


	massert(ls("*") == 0); //wildcard
	massert(ls(".\\*") == 0); //wildcard
	massert(ls("*.txt") == 0); //wildcard front
	massert(ls("*.docx") == 0); //wildcard front
	massert(ls("test*") == 0); //wildcard back
	massert(ls("t*t") == 0); //wildcard mid
	massert(ls("t*.*t") == 0); //two wildcard
	massert(ls("test.aaa*aa") == 1); // wildcard , ��� ����
	massert(ls("��*��*")==0); //wildcard with korean
	massert(ls("C:\\Users\\dojh9\\test\\t*t") == 0); //wild card ������

	char ls_op_l[] = "test* -l";
	massert(ls(ls_op_l) ==0); //�ɼ� l
	char ls_op_t[] = "test* -t";
	massert(ls(ls_op_t) == 0); //�ɼ� t
	char ls_op_s[] = "test* -s";
	massert(ls(ls_op_s) == 0); //�ɼ� s
	char ls_op_r[] = "test* -r";
	massert(ls(ls_op_r) == 0); //�ɼ� r
	char ls_op_l_r_t[] = "test* -l -r -t";
	massert(ls(ls_op_l_r_t) == 0); //�ɼ� l r t
	char ls_op_lt[] = "test* -lt";
	massert(ls(ls_op_lt) == 0); //�ɼ� lt
	char ls_op_ls[] = "test* -ls";
	massert(ls(ls_op_ls) == 0); //�ɼ� ls
	char ls_op_ts[] = "test* -ts";
	massert(ls(ls_op_ts) == 1); //�ɼ� ts
	char ls_op_llllssssr[] = "test* -llllssssr";
	massert(ls(ls_op_llllssssr) == 0); //�ɼ� llllssssr

	printf("PASSED\n\n");

	
}