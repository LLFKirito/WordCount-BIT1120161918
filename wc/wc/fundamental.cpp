/*  
 *  ���ļ�ʵ�ֻ������� 
 */ 

#include "stdafx.h"

/// <summary> ����ļ��ַ��� </summary> 
int count_character(char file[])
{
	int ch_num = 0;
	char ch;
	freopen(file, "r", stdin);
	while ((ch = getchar()) != EOF) {
		if (ch != ' '&&ch != '\n'&&ch != '\t')
			ch_num++;
	}
	fclose(stdin);

	return ch_num;
}

///	<summary> ����ļ������� </summary> 
int count_word(char file[])
{
	int w_num = 0, is_word = 0;
	char ch;
	freopen(file, "r", stdin);
	while ((ch = getchar()) != EOF) {
		if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || ch == '_')
			is_word = 1;
		else {
			if (is_word) {
				w_num++;
				is_word = 0;
			}
		}
	}
	fclose(stdin);

	return w_num;
}

///	<summary> ����ļ����� </summary> 
int count_line(char file[])
{
	int l_num = 0;
	char ch;
	freopen(file, "r", stdin);
	while ((ch = getchar()) != EOF) {
		if (ch == '\n')
			l_num++;
	}
	fclose(stdin);

	return l_num;
}