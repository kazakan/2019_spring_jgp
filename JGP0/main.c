#include "utils.h"

int main(void){

	while(1){
		printf("폴더 입력: ");
		getPathFromUser();

		//입력이 있고 경로는 유효하며 경로가 디렉토리인 경우 
		if(directory[0] != 0 && isPathValid(directory) && isDir(directory)){
			cd(directory);
			break;
		}
		printf("존재하지 않거나 접근이 불가능한 폴더입니다.\n");
		
		//printf("%s\n", directory); //directory 값 확인 테스트용
	}

	while(1){
		CMD* cmd = 0;
		char** cmd_with_arg = 0;
		int result = 0;
		printf("명령어 입력: ");
		getCommand(_buffer);


		//cmd_with_arg[0] 명령어 문자열 ,[1] 인자 문자열
		//필요없어지면 반드시 freeCommandWithArg 로 메모리 해제
		cmd_with_arg = getCommandWithArg(_buffer);


		if(cmd_with_arg == 0){
			continue;
		}

		//cmd->cmd_char 명령어 문자열
		//cmd->cmd_func 명령어 함수 포인터, exit의 경우 함수포인터는 지정되지 않음
		cmd = isCommandExist(cmd_with_arg[0]); 
		printf("%s/%s \n", cmd_with_arg[0], cmd_with_arg[1]); //cmd값 확인
		if((_buffer[0] == 0) || cmd == 0){
			printf("처리할 수 없는 명령어입니다.\n");
			freeCommandWithArg(cmd_with_arg);
			continue;
		}

		//명령어가 exit인경우 루프 탈출
		if(strcmp(cmd->cmd_char, "exit") == 0){
			printf("exit");
			freeCommandWithArg(cmd_with_arg);
			break;
		} else{
			result = cmd->cmd_func(cmd_with_arg[1]);
			//결과값이 0이 아닌 경우 오류발생으로 간주
			if(result != 0){
				printf("처리할 수 없는 명령어입니다.\n");
			}
			freeCommandWithArg(cmd_with_arg);
		}
	}
	return 0;
}

