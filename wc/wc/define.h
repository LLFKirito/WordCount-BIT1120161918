#ifndef __DIFINE_H__
#define __DIFINE_H__


// 全局变量声明: 命令参数 
extern char para[200][500];

// 函数声明: 检查文件是否存在并可以读取 
int check_file_name(char filename[]);

// 函数声明: 检查命令是否正确 
int check_order(char order[]);

// 函数声明: 单条基本命令的处理 
void basic_command(char order[], char filename[]);


#endif
