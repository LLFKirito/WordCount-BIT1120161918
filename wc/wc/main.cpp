/* 
 *  Project: WordCount 
 *  Function: 
 *  		1.实现统计文件的字符数、单词数、行数 
 *  		2.实现递归处理目录下符合条件的文件 
 *  		3.实现图形界面功能 
 *  Author: 李林峰, 马伯乐 
 *  Student Number: 1120161918, 1120161922 
 *  Version: 6.2 
 *  Date: May 12,2018 
 */ 

//#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"


int main(int argc, char* argv[])
{
	if (strcmp(argv[1], "-s") == 0) {		// 递归处理目录下符合条件的文件  
		TCHAR szPath[MAX_PATH] = { 0 };
		if (GetModuleFileName(NULL, szPath, MAX_PATH)) {
			(_tcsrchr(szPath, _T('\\')))[1] = 0;
		}
		string Path;
		Wchar_tToString(Path, szPath);
		for (int i = 0; i < argc; i++)
			strcpy(para[i], argv[i]);
		search_file(Path, argc - 1);
	}
	else if (strcmp(argv[1], "-x") == 0) {	// 高级功能: 图形界面 
		ShellExecuteA(NULL, "open", "WordCount.exe", NULL, NULL, SW_SHOW);
	}
	else {									// 对单个.c文件的统计 
		
		int num_para;
		for (num_para = argc - 1; num_para > 1; num_para--) {
			if (   strcmp(argv[num_para], "-s") == 0 || strcmp(argv[num_para], "-x") == 0
			    || strcmp(argv[num_para], "-c") == 0 || strcmp(argv[num_para], "-w") == 0
				|| strcmp(argv[num_para], "-l") == 0 || strcmp(argv[num_para], "-a") == 0 )
			{break;}
		}

		char  filename[500] = {0};
		strcat(filename, argv[num_para+1]);

		for (int i = num_para+2;i < argc;i++) {
			strcat(filename, " ");
			strcat(filename, argv[i]);
		}

		
		int flag_3 = check_file_name(filename);
		
		if (flag_3 == -1) {
			printf("Wrong: File does not exist !\n");
			return 0;
		}
		else if (flag_3 == -2) {
			printf("Wrong: File has no read permissions !\n");
			return 0;
		}
		
		printf("%s:\n", filename);
		for (int i = 1; i <= num_para; i++) {
			if (check_order(argv[i]) == 1) 
				basic_command(argv[i], filename);
			else
				printf("Wrong: Command parameter error !\n");
		}
	}
	
	return 0;
}
