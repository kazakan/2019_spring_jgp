#pragma once

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <io.h>
#include <time.h>
#include <windows.h>
#include <direct.h>
#include <errno.h>

#define BUFFER_SIZE 500

typedef struct _CMD{
	char* cmd_char;
	int(*cmd_func)(char* arg);
} CMD;

char _buffer[BUFFER_SIZE];
char directory[_MAX_PATH];

//command head
int ls(char* arg);
int delete(char* arg);
int _rename(char* arg);
int cd(char* arg);
int copy(char* arg);
int mv(char* arg);
int pwd(char* arg);
int help(char* arg);
int make(char* arg);

extern CMD commands[];

//const int COMMAND_NUM = 10;


// utility functions head
void getPathFromUser();
int isPathValid(char* path);
void dealSlash(char*buffer);
CMD* isCommandExist(char* command);
char** getCommandWithArg(char* buffer);
void freeCommandWithArg(char ** cmd_arg);
int isDir(char *path);
int getFullPath(char* partialPath, char* dest);
int isWhiteSpace(char c);
void showFileInfo(struct _finddata_t FileInfo, int l);
