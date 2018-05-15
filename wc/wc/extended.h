#ifndef __EXTENDED_H__
#define __EXTENDED_H__


#include "stdafx.h"

// 函数声明: 复杂数据统计 
void complex_data_statistics(char file[]);

// 函数声明: 统计文件 空行 数 
int count_blankline(char file[]);

// 函数声明: 统计文件注释行数 
int count_noteline(char file[]);

// 函数声明: 统计文件代码行数 
int count_codeline(char file[]);

// 函数声明：递归搜索目录 
void search_file(string path, int idx);

// 函数声明：Wchar to string 
void Wchar_tToString(string& szDst, wchar_t *wchar);


#endif
