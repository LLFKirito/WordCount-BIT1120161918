/*
 *  本文件实现扩展功能
 */

#include "stdafx.h"

///	<summary> 复杂数据统计 </summary> 
void complex_data_statistics(char file[])
{
	int b_num = count_blankline(file);	// 空行数 
	int n_num = count_noteline(file);	// 注释行数 
	int cl_num = count_line(file) - b_num - n_num; 	// 代码行数 

	printf("    The number of code lines:  %d\n", cl_num);
	printf("    The number of blank lines: %d\n", b_num);
	printf("    The number of note lines:  %d\n", n_num);
}

///	<summary> 统计文件 空行 数 </summary> 
int count_blankline(char file[])
{
	int b_num = 0, ch_num = 0;
	char ch;
	freopen(file, "r", stdin);
	while ((ch = getchar()) != EOF) {
		if (ch == '\n'){
			if (ch_num <= 1)
				b_num++;
			ch_num = 0;
		}
		else if (ch != ' '&&ch != '\t')
			ch_num++;
	}
	fclose(stdin);

	return b_num;
}

///	<summary> 统计文件注释行数 </summary> 
int count_noteline(char file[])
{
	int n_num = 0, line = 0, ch_num = 0, flag_1 = 0, flag_2 = 0, flag_3 = 0, thisline = 0;
	char ch;
	freopen(file, "r", stdin);
	while ((ch = getchar()) != EOF) {
		if (ch == '\n'){
			if (line&&ch_num > 0)
				line++;
			ch_num = 0;
			flag_1 = thisline = 0;
		}
		if (thisline == 1)
			continue;
		if (ch != ' '&&ch != '\t'&&ch != '\n')
			ch_num++;
		if (flag_2){
			if (ch != ' '&&ch != '\t'&&ch != '\n')
				ch_num++;
			if (ch == '*')
				flag_3 = 1;
			else if (ch == '/'&&flag_3){
				n_num += line;
				line = 0;
				flag_2 = flag_3 = 0;
				thisline = 1;
			}
			else
				flag_3 = 0;
		}
		else if (ch == '/') {
			if (flag_1 == 0)
				flag_1 = 1;
			else if (flag_1 == 1 && ch_num <= 3){
				n_num++;
				thisline = 1;
			}
		}
		else if (ch == '*'){
			if (flag_1 == 1){
				flag_2 = 1;
				line = 1;
			}
		}
		else
			flag_1 = 0;
	}
	fclose(stdin);

	return n_num;
}

///	<summary> 统计文件代码行数 </summary> 
int count_codeline(char file[])
{
	int line = count_line(file);
	int blank = count_blankline(file);
	int note = count_noteline(file);
	int cl_num = line - blank - note;

	return cl_num;
}

///	<summary> wchar_t to string </summary> 
void Wchar_tToString(std::string& szDst, wchar_t *wchar)
{
	wchar_t * wText = wchar;
	DWORD dwNum = WideCharToMultiByte(CP_OEMCP, NULL, wText, -1, NULL, 0, NULL, FALSE);
	char *psText;
	psText = new char[dwNum];
	WideCharToMultiByte(CP_OEMCP, NULL, wText, -1, psText, dwNum, NULL, FALSE);
	szDst = psText;
	delete[]psText;
}

///	<summary> 递归处理文件 </summary> 
void search_file(string path, int idx)
{
	struct _finddata_t filefind;
	string cur = path + "*.*";
	int done = 0, handle;
	if ((handle = _findfirst(cur.c_str(), &filefind)) != -1) {
		while (!(done = _findnext(handle, &filefind))) {
			if (strcmp(filefind.name, "..") == 0)
				continue;
			if ((_A_SUBDIR == filefind.attrib)) {  //目录
				cur = path + filefind.name + '\\';
				search_file(cur, idx);    //递归处理
			}
			else {
				int len = strlen(filefind.name);
				for (int i = 0; i < len; i++) {
					if (filefind.name[i] == '.') {
						len = i;
						break;
					}
				}
				if (strcmp(filefind.name + len, para[idx] + 1) == 0) {
					cur = path + filefind.name;
					printf("%s:\n", filefind.name);
					for (int i = 1; i < idx; i++)
						basic_command(para[i], &cur[0]);
				}
			}
		}
		_findclose(handle);
	}
}