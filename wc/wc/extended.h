#ifndef __EXTENDED_H__
#define __EXTENDED_H__


#include "stdafx.h"

// ��������: ��������ͳ�� 
void complex_data_statistics(char file[]);

// ��������: ͳ���ļ� ���� �� 
int count_blankline(char file[]);

// ��������: ͳ���ļ�ע������ 
int count_noteline(char file[]);

// ��������: ͳ���ļ��������� 
int count_codeline(char file[]);

// �����������ݹ�����Ŀ¼ 
void search_file(string path, int idx);

// ����������Wchar to string 
void Wchar_tToString(string& szDst, wchar_t *wchar);


#endif
