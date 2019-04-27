#include "utils.h"
// 프로젝트 설정에서 _CRT_SECURE_NO_WARNINGS 매크로 설정 요망! 

CMD commands[] = {
   {"exit",0},
   {"ls",ls},
   {"delete",delete},
   {"rename",_rename},
   {"cd",cd},
   {"copy",copy},
   {"mv",mv},
   {"pwd",pwd},
   {"help",help},
   {"make",make}
};


// command function body
int help(char * arg){
	// command , synopsis , explanation
	const char* HELP_MESSAGE[][3] = {
		{"exit","exit","프로그램을 종료합니다."},
		{"ls","ls [TARGET] [-lr] [-t|-s]","TARGET이 생략되었을 경우 현재 디렉토리 내의 파일 및 폴더에 대한 정보를 출력합니다. TARGET이 입력된 경우 TARGET에 대한 정보를 출력합니다. \
TARGET이 파일인 경우 해당 파일에 대한 정보를 출력합니다.TARGET이 폴더인 경우 해당 폴더 내 파일 및 폴더에 대한 정보를 출력합니다. \
TARGET에는 와일드카드(*)를 포함하여 검색이 가능합니다.\n\n-옵션\n\
-l : 상세정보를 출력합니다.\n\
- t : 최근 수정시간을 기준으로 출력합니다.\n\
- s : 크기 순서대로 출력합니다.\n\
- r : 역순으로 출력합니다."},
		{"delete","delete TARGET","TARGET을 제거합니다. \nTARGET은 휴지통으로 이동되지 않고 즉시 삭제됩니다."},
		{"rename","rename SOURCE DEST","SOURCE의 이름을 DEST로 변경합니다."},
		{"cd","cd DEST","DEST로 현재 디렉토리를 이동합니다."},
		{"copy","copy SOURCE DEST","SOURCE를 DEST에 복사합니다."},
		{"mv","mv SOURCE DEST","SOURCE의 경로를 DEST로 이동합니다."},
		{"pwd","pwd","현재 디렉토리 경로를 출력합니다."},
		{"help","help [COMMAND]","명령어에 대한 설명을 출력합니다."},
		{"make","make TARGET  [-f]","현재 디렉토리 내에 TARGET을 이름으로 갖는 파일을 생성합니다.\n\n\
-옵션\n\
-f :  TARGET을 이름으로 가지는 폴더를 생성합니다. 해당 옵션이 주어지지 않았다면 파일을 생성합니다."}
	};
	
	char* arg1 = NULL;
	arg1 = strtok(arg," \t");
	if(strtok(NULL, " \t") != NULL){ // 2개 이상의 인자
		printf("인자가 너무 많습니다.\n");
		return 1;
	}

	if(arg == 0 || strlen(arg1) == 0){
		for(int i = 0; i < 10; ++i){
			printf("Command : %s\nSynopsis\n\t%s\n-설명\n%s\n\n\n", HELP_MESSAGE[i][0], HELP_MESSAGE[i][1], HELP_MESSAGE[i][2]);
		}
		return 0;
	} 

	for(int i = 0; i < 10; ++i){
		if(strcmp(arg1, HELP_MESSAGE[i][0]) == 0){
			printf("Command : %s\nSynopsis\n\t%s\n-설명\n%s\n\n\n", HELP_MESSAGE[i][0], HELP_MESSAGE[i][1], HELP_MESSAGE[i][2]);
			return 0;
		}
	}

	
	printf("No such command.\n");
	return 1;
}


int make(char * arg){
	char* argument[BUFFER_SIZE] = {0,};
	char *arg1 = NULL;
	char *arg2 = NULL;
	char *arg3 = NULL;
	int result;
	FILE* fp;
	if(arg == NULL){
		return 1; //인자로 아무것도 주지 않은 경우
	}
	strcpy(argument, arg);
	arg1 = strtok(argument, " ");
	arg2 = strtok(NULL, " ");
	arg3 = strtok(NULL, " ");
	if(arg2 == NULL){ //인자 1개 파일생성
		result = access(arg1, 0);
		if(result == 0){
			return 1; //파일 및 폴더 이미 존재
		} else if(result == -1) //파일 미존재
		{
			fp = fopen(arg1, "wt");
			if(fp == NULL){
				return 1;
			}
			fclose(fp);
			return 0;
		}
	} else if(arg3 == NULL){ //인자 2개 일때 
		result = strchr(arg2, 'f');
		if(result != NULL && arg2[0] == '-'){ //옵션주어짐, 형식에 맞는지 검사
			result = access(arg1, 0);
			if(result == 0) //폴더 존재
			{
				return 1;
			} else if(result == -1) //폴더 미존재
			{
				result = mkdir(arg1);
				if(result == 0){
					return 0;
				} else if(result == -1){
					return 1;
				}
				return 0;
			}
		}
		return 1;
	} else if(arg3 != NULL){ //인자가 많을 때
		return 1;
	}
	return 1;
}

int delete(char * arg){
	char* argument[BUFFER_SIZE] = {0,};
	char *arg1 = NULL;
	char *arg2 = NULL;
	int result;
	struct stat sb;
	if(arg == NULL){
		return 1; //인자로 아무것도 주지 않은 경우
	}
	strcpy(argument, arg);
	arg1 = strtok(argument, " ");
	arg2 = strtok(NULL, " ");
	if(arg2 == NULL){ //인자 1개 파일생성
		result = access(arg1, 0); //파일 및 폴더 존재
		if(result == 0){
			stat(arg1, &sb);
			result = sb.st_mode & S_IFMT;
			switch(result){
				case S_IFREG:
					remove(arg1);
					return 0;
					break;
				case S_IFDIR:
					result = rmdir(arg1);
					if(result == -1)
						return 1;
					return 0;
					break;
			}
		} else if(result == -1) //파일 미존재
		{
			return 1;
		}
		return 1;
	} else if(arg2 != NULL){
		return 1;
	}
	return 1;
}


//int delete(char * arg){
//	char* token = 0;
//	char source[_MAX_DIR] = {0};
//	char source_cp[_MAX_DIR] = {0};
//
//	if(arg == 0 || strlen(arg) == 0){
//		printf("요소가 입력되지 않았습니다.\n");
//		return(1);
//	}
//	token = strtok(arg, " \t");
//	strcpy(source, token);
//	strcpy(source_cp, source);
//
//	if(strtok(NULL, " \t") != NULL){
//		printf("입력이 너무 많습니다.");
//		return 1;
//	}
//
//	getFullPath(&source, &source);
//
//	char* name = 0;
//	char* tmp = 0;
//	name = strtok(source_cp, "\\");
//	while((tmp = strtok(NULL, "\\")) != NULL) name = tmp;
//
//
//	//SHFILEOPSTRUCTA 사용시 문자열 끝에 두개의 널문자가 필요
//	strcat(&source, "\0\0");
//
//	SHFILEOPSTRUCTA sf;
//	int result;
//	sf.pFrom = &source;
//	sf.wFunc = FO_DELETE;
//	sf.fFlags = FOF_NOCONFIRMATION | FOF_NOCONFIRMMKDIR | FOF_SILENT;
//
//	result = SHFileOperation(&sf);
//
//	return result;
//}

int ls(char* arg){
	//for argument extraction
	static const char OPT_L = 1;
	static const char OPT_R = 1 << 1;
	static const char OPT_T = 1 << 2;
	static const char OPT_S = 1 << 3;

	char option = 0;
	char target[_MAX_DIR];
	char* tok;
	int gotTarget = 0;
	int hasWild = 0;

	//for file handling
	int i, j;
	int *ptr, index = 0, total = 0;
	long Handle;
	struct _finddata_t FileInfo;
	struct _finddata_t * array = NULL;

	if(arg != 0){

		tok = strtok(arg, " \t");
		while(tok != NULL){
			if(gotTarget == 0 && tok[0] != '-'){
				strcpy(target, tok);
				hasWild = strchr(tok, '*') != 0;
				gotTarget = 1;
			} else if(tok[0] == '-'){
				for(int i = 1; i < strlen(tok); ++i){
					switch(tok[i]){
						case 'l':
							option |= OPT_L;
							break;
						case 'r':
							option |= OPT_R;
							break;
						case 't':
							option |= OPT_T;
							break;
						case 's':
							option |= OPT_S;
							break;
						default:
							printf("There's no option -%c\n", tok[i]);
							return 1;
					}
				}
			}
			tok = strtok(NULL, " \t");
		}
	}


	// These two options -t,-s can NOT be used together
	if(option&OPT_T && option&OPT_S){
		return 1;
	}

	if(!gotTarget){
		strcpy(target, ".\\*");
	}

	if((Handle = _findfirst(target, &FileInfo)) == -1L){
		printf("Cannot find such a file\n");
		return 1;
	} else{
		if(gotTarget && !hasWild && FileInfo.attrib & _A_SUBDIR){
			strcat(target, "\\*");
		}
		Handle = _findfirst(target, &FileInfo);
		//count
		do{
			if(strcmp(FileInfo.name, ".") && strcmp(FileInfo.name, "..")){
				total++;
			}
		} while(_findnext(Handle, &FileInfo) == 0);

		//copy
		Handle = _findfirst(target, &FileInfo);
		array = malloc(total * sizeof(struct _finddata_t));
		do{
			if(strcmp(FileInfo.name, ".") && strcmp(FileInfo.name, "..")){
				array[index].attrib = FileInfo.attrib;
				strcpy(array[index].name, FileInfo.name);
				array[index].size = FileInfo.size;
				//array[index].time_access = FileInfo.time_access;
				//array[index].time_create = FileInfo.time_create;
				array[index].time_write = FileInfo.time_write;
				++index;
			}
		} while(_findnext(Handle, &FileInfo) == 0);


		//Handle = _findfirst(target, &FileInfo);
		//if(strcmp(FileInfo.name, ".") && strcmp(FileInfo.name, "..")){
		//	array[index].attrib = FileInfo.attrib;
		//	strcpy(array[index].name, FileInfo.name);
		//	array[index].size = FileInfo.size;
		//	//array[index].time_access = FileInfo.time_access;
		//	//array[index].time_create = FileInfo.time_create;
		//	array[index].time_write = FileInfo.time_write;
		//	index++;
		//}
		//while(_findnext(Handle, &FileInfo) == 0){
		//	array[index].attrib = FileInfo.attrib;
		//	strcpy(array[index].name, FileInfo.name);
		//	array[index].size = FileInfo.size;
		//	//array[index].time_access = FileInfo.time_access;
		//	//array[index].time_create = FileInfo.time_create;
		//	array[index].time_write = FileInfo.time_write;
		//	index++;
		//}

		//sort
		ptr = malloc(total * sizeof(int));
		for(i = 0; i < total; i++)
			ptr[i] = i;

		if(option & OPT_T){
			for(i = 0; i < total - 1; i++){
				for(j = i + 1; j < total; j++){
					if(array[ptr[i]].time_write < array[ptr[j]].time_write){
						index = ptr[i];
						ptr[i] = ptr[j];
						ptr[j] = index;
					}
				}
			}
		} else if(option & OPT_S){
			for(i = 0; i < total - 1; i++){
				for(j = i + 1; j < total; j++){
					if(array[ptr[i]].size < array[ptr[j]].size){
						index = ptr[i];
						ptr[i] = ptr[j];
						ptr[j] = index;
					}
				}
			}
		}

		for(i = 0; i < total; i++){
			int idx;
			if(option&OPT_R){
				idx = ptr[total - i - 1];
			} else{
				idx = ptr[i];
			}

			if(option & OPT_L){
				showFileInfo(array[idx], 1);
			} else{
				showFileInfo(array[idx], 0);
				if(!((i + 1) % 3)){
					printf("\n");
				}
			}
		}
		printf("\n");

		_findclose(Handle);
	}

	return 0;
}

int _rename(char * arg){ //rename oldname newname 형태
	char* argument[BUFFER_SIZE] = {0,};
	char *arg1 = NULL;
	char *arg2 = NULL;
	char *arg3 = NULL;
	int result;
	if(arg == NULL){
		return 1; //인자로 아무것도 주지 않은 경우
	}
	strcpy(argument, arg);
	arg1 = strtok(argument, " "); //oldname
	arg2 = strtok(NULL, " "); //newname
	arg3 = strtok(NULL, " ");
	if(arg2 == NULL){ //인자 1개
		return 1;
	} else if(arg3 == NULL) //인자 두개일때
	{
		result = access(arg1, 0);
		if(result == 0){
			result = rename(arg1, arg2);
			if(result == 0){
				return 0;
			} else if(result == -1){
				return 1;
			}
		} else if(result == -1){
			return 1;
		}
		return 1;
	} else if(arg3 != NULL){  //인자 개수 많을 때
		return 1;
	}
	return 1;
}

int cd(char * arg){
	char * token = 0;
	if(arg == 0){
		printf("Number of argument should be 1.\n");
		return 1;
	}
	token = strtok(arg, " \t");

	if(strtok(NULL, " \t") != NULL){
		printf("Number of argument should be 1.\n");
		return 1;
	}

	if(isPathValid(arg) && isDir(arg)){
		getFullPath(arg, directory);
		_chdir(directory);
		return 0;
	}

	printf("Cannot find such folder.\n");
	return 1;
}

int copy(char* arg){

	char* token = 0;
	char source[_MAX_DIR] = {0};
	char source_cp[_MAX_DIR] = {0};
	char dest[_MAX_DIR];

	if(arg == 0 || strlen(arg) == 0){
		printf("요소가 입력되지 않았습니다.\n");
		return(1);
	}
	token = strtok(arg, " \t");
	strcpy(source, token);
	strcpy(source_cp, source); //source 수정 방지를 위해 복제
	token = strtok(NULL, " \t");
	if(token == NULL){
		printf("목표 경로가 입력되지 않았습니다.\n");
		return(1);
	}
	strcpy(dest, token);
	if(strtok(NULL, " \t") != NULL){
		printf("입력이 너무 많습니다.\n");
		return(1);
	}
	if(!strcmp(source, dest)){
		printf("요소와 목표 경로가 동일합니다.\n");
		return(1);
	}

	getFullPath(&source, &source);
	if(!isPathValid(source)){
		printf("요소가 올바르지 않습니다.\n");
		return(1);
	}
	getFullPath(&dest, &dest);
	if(!isDir(dest)){
		printf("목표 경로가 올바르지 않습니다.\n");
		return(1);
	}

	char* name = 0;
	char* tmp = 0;

	name = strtok(source_cp, "\\");
	while((tmp = strtok(NULL, "\\")) != NULL){
		name = tmp;
	}
	strcat(&source, "\0\0");  //SHFileOperation 사용을 위한 null문자 2개 삽입
	strcat(&dest, "\\");
	strcat(&dest, name);
	strcat(&dest, "\0\0"); //SHFileOperation 사용을 위한 null문자 2개 삽입
	if(isPathValid(dest)){
		printf("목표 경로에 요소가 이미 존재합니다.\n");
		return(1);
	}

	SHFILEOPSTRUCTA sf;
	int result;

	sf.pFrom = &source;
	sf.pTo = &dest;
	sf.wFunc = FO_COPY;
	sf.fFlags = FOF_NOCONFIRMATION | FOF_NOCONFIRMMKDIR | FOF_SILENT;

	result = SHFileOperation(&sf);
	return result;
}


int mv(char* arg){
	char* token = 0;
	char source[_MAX_DIR] = {0};
	char source_cp[_MAX_DIR] = {0};
	char dest[_MAX_DIR];

	if(arg == 0 || strlen(arg) == 0){
		printf("요소가 입력되지 않았습니다.\n");
		return(1);
	}
	token = strtok(arg, " \t");
	strcpy(source, token);
	strcpy(source_cp, source);
	token = strtok(NULL, " \t");
	if(token == NULL){
		printf("목표 경로가 입력되지 않았습니다.\n");
		return(1);
	}
	strcpy(dest, token);
	if(strtok(NULL, " \t") != NULL){
		printf("입력이 너무 많습니다.\n");
		return(1);
	}
	if(!strcmp(source, dest)){
		printf("요소와 목표 경로가 동일합니다.\n");
		return(1);
	}

	getFullPath(&source, &source);
	if(!isPathValid(source)){
		printf("요소가 올바르지 않습니다.\n");
		return(1);
	}
	getFullPath(&dest, &dest);
	if(!isDir(dest)){
		printf("목표 경로가 올바르지 않습니다.\n");
		return(1);
	}

	char* name = 0;
	char* tmp = 0;

	name = strtok(source_cp, "\\");
	while((tmp = strtok(NULL, "\\")) != NULL){
		name = tmp;
	}
	strcat(&source, "\0\0");
	strcat(&dest, "\\");
	strcat(&dest, name);
	strcat(&dest, "\0\0");
	if(isPathValid(dest)){
		printf("목표 경로에 요소가 이미 존재합니다.\n");
		return(1);
	}

	SHFILEOPSTRUCTA sf;
	int result;

	sf.pFrom = &source;
	sf.pTo = &dest;
	sf.wFunc = FO_MOVE;
	sf.fFlags = FOF_NOCONFIRMATION | FOF_NOCONFIRMMKDIR | FOF_SILENT;

	result = SHFileOperation(&sf);
	return result;
}


int pwd(char* arg){
	if(arg != NULL){
		printf("입력이 너무 많습니다.\n");
		return(1);
	}

	printf("%s\n", directory);
	return(0);
}


// utility function body
void getPathFromUser(){
	gets(directory);
	//dealSlash(_pwd, BUFFER_SIZE);
	if(directory[0] == 0){
		return;
	}
	getFullPath(directory, directory);
}


int isPathValid(char* path){
	struct stat info;
	return stat(path, &info) >= 0;
}

void dealSlash(char*buffer){
	const int l = strlen(buffer);
	for(int i = 0; i < l; ++i){
		if(buffer[i] == '\\'){
			for(int j = l - 1; j > i; --j){
				buffer[j + 1] = buffer[j];
			}
			buffer[i + 1] = '\\';
			i += 2;
		}
	}
}

void getCommand(char* buffer){
	gets(buffer);

}

int isWhiteSpace(char c){
	return c == ' ' || c == '\t';
}

CMD* isCommandExist(char* command){
	int n_commands = sizeof(commands) / sizeof(CMD);
	for(int i = 0; i < n_commands; ++i){
		if(strcmp(command, commands[i].cmd_char) == 0){
			return &commands[i];
		}
	}
	return 0;
}

/**
 * There could be situations
 * 1) \s0
 * 2) \scommand0
 * 3) \scommand\s0
 * 4) \scommand\sarg...
 * 5) no front spaces or tabs in 1~4
 * 6) 0
 */
char** getCommandWithArg(char * buffer){
	char** cmd_arg;
	char* command, *arg;
	int i = 0, j = 0, k = 0;
	int len = strlen(buffer);

	if(buffer == 0 || buffer[0] == 0){
		return 0;
	}

	//front spaces or tabs + 5)
	while(isWhiteSpace(buffer[i])){
		++i;
	}
	if(buffer[i] == 0){ //1
		return 0;
	}

	j = i;

	cmd_arg = malloc(sizeof(char**) * 2);
	while(!isWhiteSpace(buffer[j])){
		if(buffer[j] == 0){ //2
			command = calloc(j - i + 1, sizeof(char));
			memcpy(command, buffer + i, j - i);
			cmd_arg[0] = command;
			cmd_arg[1] = 0;
			return cmd_arg;
		}
		++j;
	}

	k = j;
	while(isWhiteSpace(buffer[k])){
		++k;
	}
	if(buffer[k] == 0){ //3
		command = calloc(j - i + 1, sizeof(char));
		memcpy(command, buffer + i, (j - i));
		cmd_arg[0] = command;
		cmd_arg[1] = 0;
		return cmd_arg;
	}

	//4
	command = calloc(j - i + 1, sizeof(char));
	arg = calloc(len - k + 1, sizeof(char));
	memcpy(command, buffer + i, j - i);
	memcpy(arg, buffer + k, len - k);
	cmd_arg[0] = command;
	cmd_arg[1] = arg;
	return cmd_arg;
}

void freeCommandWithArg(char ** cmd_with_arg){
	if(cmd_with_arg == 0){
		return;
	}

	for(int i = 0; i < 2; ++i){
		if(cmd_with_arg[i] != 0){
			free(cmd_with_arg[i]);
		}
	}

	free(cmd_with_arg);
}

int isDir(char *path){
	struct stat path_stat;
	if(stat(path, &path_stat) < 0){
		return 0;
	}
	return path_stat.st_mode & S_IFDIR;
}

int getFullPath(char* partialPath, char* dest){
	static char temp[_MAX_PATH];
	if(_fullpath(temp, partialPath, _MAX_PATH) != NULL){
		strcpy(dest, &temp);
		return 0;
	} else{
		return 1;
	}
}

void showFileInfo(struct _finddata_t FileInfo, int l){
	char pcTime[1024];
	if(strcmp(FileInfo.name, ".") && strcmp(FileInfo.name, "..")){
		printf("%s", FileInfo.name);
		if(l){
			if(FileInfo.size)
				printf("\tsize\t\t%u\n", FileInfo.size);
			/*strftime(pcTime, sizeof(pcTime), "%Y/%m/%d %H:%M:%S", localtime(&FileInfo.time_access));
			printf("\ttime_access\t%s\n", pcTime);
			strftime(pcTime, sizeof(pcTime), "%Y/%m/%d %H:%M:%S", localtime(&FileInfo.time_create));
			printf("\ttime_create\t%s\n", pcTime);*/
			strftime(pcTime, sizeof(pcTime), "%Y/%m/%d %H:%M:%S", localtime(&FileInfo.time_write));
			printf("\ttime_write\t%s\n\n", pcTime);
		} else
			printf("\t");
	}
}
