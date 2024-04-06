#include "std.h"
#pragma warning(disable:6031)

short* arr_tmp, cnt_cmp;
extern short* arr, size;

void con_init()
{
	arr_tmp = (short*)malloc(size * sizeof(short));
}

void con_reset()
{
	memcpy(arr_tmp, arr, size * sizeof(short));
	cnt_cmp = 0;
}

void con_exit()
{
	free(arr);
	//free(arr_tmp);
}

void dummy()	//Error prevention for 'system();'.
{
	printf("");
	printf("");
	printf("");
}