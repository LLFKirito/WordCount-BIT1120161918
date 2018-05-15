/*  
 *  ���ļ�ʵ�ֻ������������� 
 */

#include "stdafx.h"


/// ���ڸ���������� 
char para[200][500];

///	<summary> ����ļ��Ƿ���ڲ����Զ�ȡ </summary> 
/// <param name="filename"> �ļ����� </param> 
///	<return> 
///  -1: �ļ������� 
///  -2: �ļ����ڵ�û�ж�ȡȨ�� 
///   1: �ļ��з���Ȩ�� 
/// </return> 
int check_file_name(char filename[])
{
	if (access(filename, 0) != 0) { return -1; }	// �ļ������ڷ���-1 
	if (access(filename, 4) != 0) { return -2; }	// �ļ����ܶ�ȡ����-2 
	return 1;
}

///	<summary> ��������Ƿ���ȷ </summary> 
/// <param name="order"> �������� </param> 
///	<return> -1: �����ʽ����; 1: ��ȷ�������ʽ </return> 
int check_order(char order[])
{
	int len = strlen(order);
	if (len != 2 || order[0] != '-') return -1;

	if (order[1] == 'c' || order[1] == 'w' || order[1] == 'l' || order[1] == 'a') {
		return 1;
	}
	else return -1;
}

///	<summary> ������������Ĵ��� </summary> 
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
