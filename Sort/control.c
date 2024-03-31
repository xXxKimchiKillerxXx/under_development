#include "std.h"
#pragma warning(disable:6031)

int* arr_tmp, cnt_cmp;
extern int* arr, size;

void con_init()
{
	arr_tmp = (int*)malloc(size * sizeof(int));
}

void con_arr()
{
	memcpy(arr_tmp, arr, size * sizeof(int));
	cnt_cmp = 0;
}

void dummy()	//Error prevention for 'system();'.
{
	puts("");
	puts("");
	puts("");
	puts("");
}

void con_exit()
{
	free(arr);
	//free(arr_tmp);
}