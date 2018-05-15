/*  
 *  本文件实现基本输入输出检查 
 */

#include "stdafx.h"


/// 用于复制命令参数 
char para[200][500];

///	<summary> 检查文件是否存在并可以读取 </summary> 
/// <param name="filename"> 文件名称 </param> 
///	<return> 
///  -1: 文件不存在 
///  -2: 文件存在但没有读取权限 
///   1: 文件有访问权限 
/// </return> 
int check_file_name(char filename[])
{
	if (access(filename, 0) != 0) { return -1; }	// 文件不存在返回-1 
	if (access(filename, 4) != 0) { return -2; }	// 文件不能读取返回-2 
	return 1;
}

///	<summary> 检查命令是否正确 </summary> 
/// <param name="order"> 命令名称 </param> 
///	<return> -1: 命令格式错误; 1: 正确的命令格式 </return> 
int check_order(char order[])
{
	int len = strlen(order);
	if (len != 2 || order[0] != '-') return -1;

	if (order[1] == 'c' || order[1] == 'w' || order[1] == 'l' || order[1] == 'a') {
		return 1;
	}
	else return -1;
}

///	<summary> 单条基本命令的处理 </summary> 
void basic_command(char order[], char filename[])
{
	switch (order[1]) {
	case 'c':
		printf("    The number of characters:  %d\n", count_character(filename));
		break;
	case 'w':
		printf("    The number of words:       %d\n", count_word(filename));
		break;
	case 'l':
		printf("    The number of lines:       %d\n", count_line(filename));
		break;
	case 'a':
		complex_data_statistics(filename);
		break;
	}
}
