#include "std.h"

extern short* arr_tmp, size, cnt_cmp;

void swap(short* a, short* b)
{
	short tmp = *a;
	*a = *b;
	*b = tmp;
}

void arrPrint(short* arr, const char* name_arr)
{
	puts(name_arr);
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == -1) printf("  NULL");
		else printf("%5d ", arr[i]);
	}
	puts("");
}

void cntPrint()
{
	puts("");
	printf("Total Comparisons: %d", cnt_cmp);
	puts("");
}

void arrowPrint(int left, int right)
{
	int i;

	for (i = 0; i < left; i++)
	{
		printf("      ");
	}

	printf("    ^ ");

	for (i = left + 1; i < right; i++)
	{
		printf("      ");
	}

	if (i == right) printf("    ^ ");

	puts("");

	for (i = 0; i < left; i++)
	{
		printf("      ");
	}

	printf("    | ");

	for (i = left + 1; i < right; i++)
	{
		printf("      ");
	}

	if (i == right) printf("    | ");
}

void sort_bubble()
{
	for (int i = size - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			arrPrint(arr_tmp, "MAIN");
			arrowPrint(j, j + 1);
			puts("\n");
			puts("Items Comparison");
			printf("%5d %5d\n", arr_tmp[j], arr_tmp[j + 1]);
			puts("\n");

			cnt_cmp++;

			if (arr_tmp[j] > arr_tmp[j + 1])
			{
				puts("LEFT is greater, swapping.");
				swap(&arr_tmp[j], &arr_tmp[j + 1]);
			}
			else
			{
				puts("LEFT is not greater, not swapping.");
			}
			puts("\n");

			arrPrint(arr_tmp, "MAIN");
			cntPrint();
			dummy();
			system("pause");

			if (cnt_cmp == size * (size - 1) / 2)
			{
				puts("Loop reached final run, list fully sorted.");
				dummy();
				system("pause");
			}

			dummy();
			system("cls");
		}
	}
}

void sort_insertion()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j > 0; j--)
		{
			cnt_cmp++;

			arrPrint(arr_tmp, "MAIN");
			arrowPrint(j - 1, j);
			puts("\n");
			puts("Items Comparison");
			printf("%5d %5d\n", arr_tmp[j - 1], arr_tmp[j]);
			puts("\n");

			if (!(arr_tmp[j - 1] > arr_tmp[j]))
			{
				puts("LEFT is not lesser, not swapping.");
				arrPrint(arr_tmp, "MAIN");
				cntPrint();
				dummy();
				system("pause");
				dummy();
				system("cls");

				break;
			}
			else
			{
				puts("LEFT is lesser, swapping.");
			}
			puts("\n");

			swap(&arr_tmp[j - 1], &arr_tmp[j]);

			arrPrint(arr_tmp, "MAIN");
			cntPrint();
			dummy();
			system("pause");
			dummy();
			system("cls");
		}
	}
	arrPrint(arr_tmp, "MAIN");
	cntPrint();
	puts("Loop reached final run, list fully sorted.");
	dummy();
	system("pause");
	dummy();
}

void sort_selection()
{
	int idx_min;

	for (int i = 0; i < size - 1; i++)
	{
		idx_min = i;

		for (int j = i + 1; j < size; j++)
		{
			arrPrint(arr_tmp, "MAIN");
			arrowPrint(idx_min, j);
			puts("\n");
			puts("Items Comparison");
			printf("MIN: %d, ITEM: %d\n", arr_tmp[idx_min], arr_tmp[j]);
			puts("\n");
			puts("Item Positions");
			printf("MIN at %d, ITEM at %d\n", idx_min + 1, j + 1);
			puts("\n");

			if (arr_tmp[j] < arr_tmp[idx_min])
			{
				puts("MIN > ITEM, updating MIN.");

				idx_min = j;
			}
			else
			{
				puts("Not MIN > ITEM, moving to next ITEM.");
			}
			puts("");
			cnt_cmp++;

			cntPrint();
			dummy();
			system("pause");
			dummy();
			system("cls");
		}

		if (idx_min != i)
		{
			dummy();
			system("cls");
			arrPrint(arr_tmp, "MAIN");
			arrowPrint(i, idx_min);
			puts("\n");
			puts("Swap.");
			puts("\n");

			swap(&arr_tmp[i], &arr_tmp[idx_min]);

			arrPrint(arr_tmp, "MAIN");
			cntPrint();
			dummy();
			system("pause");
		}
		else
		{
			dummy();
			system("cls");
			arrPrint(arr_tmp, "MAIN");
			arrowPrint(i, idx_min);
			puts("\n");
			puts("Don't swap.");
			puts("\n");

			arrPrint(arr_tmp, "MAIN");
			cntPrint();
			dummy();
			system("pause");
		}

		if (cnt_cmp == size * (size - 1) / 2)
		{
			puts("Loop reached final run, list fully sorted.");
			dummy();
			system("pause");
		}

		dummy();
		system("cls");
	}
	dummy();
}

void sort_merge()
{
	short* arr_buf = (short*)malloc(size * sizeof(short));
	int rght, rend;
	int i, j, m;

	for (int k = 1; k < size; k *= 2)
	{
		memset(arr_buf, -1, size * sizeof(short));	//Clear BUFFER.

		puts("Clear BUFFER.");
		puts("\n");
		arrPrint(arr_buf, "BUFFER");
		dummy();
		system("pause");

		for (int left = 0; left + k < size; left += 2 * k)
		{
			dummy();
			system("cls");

			rght = left + k;
			rend = rght + k;
			if (rend > size)
			{
				rend = size;
			}

			i = left, j = rght, m = left;

			for (; i < rght && j < rend; m++)
			{
				if (i == left && j == rght) puts("Divide.");
				else puts("Merge.");
				puts("\n");
				arrPrint(arr_tmp, "MAIN");
				arrowPrint(i, j);
				puts("\n");
				puts("Items Comparison");
				printf("%5d %5d\n", arr_tmp[i], arr_tmp[j]);
				puts("\n");

				if (arr_tmp[i] < arr_tmp[j])
				{
					puts("LEFT is lesser.");
					arr_buf[m] = arr_tmp[i];
					i++;
				}
				else
				{
					puts("LEFT is not lesser.");
					arr_buf[m] = arr_tmp[j];
					j++;
				}
				puts("\n");
				puts("Move lesser one to the BUFFER.");
				puts("\n");
				cnt_cmp++;

				arrPrint(arr_tmp, "MAIN");
				arrowPrint(m, m);
				puts("\n");
				arrPrint(arr_buf, "BUFFER");
				arrowPrint(m, m);
				cntPrint();
				dummy();
				system("pause");
				dummy();
				system("cls");
			}

			for (; i < rght; i++, m++)
			{
				arrPrint(arr_tmp, "MAIN");
				arrowPrint(i, i);
				puts("\n");

				arr_buf[m] = arr_tmp[i];

				puts("Move MAIN to BUFFER.");
				puts("\n");
				arrPrint(arr_buf, "BUFFER");
				arrowPrint(i, i);
				cntPrint();
				dummy();
				system("pause");
				dummy();
				system("cls");
			}

			for (; j < rend; j++, m++)
			{
				arrPrint(arr_tmp, "MAIN");
				arrowPrint(j, j);
				puts("\n");
				arrPrint(arr_buf, "BUFFER");
				arrowPrint(j, j);
				puts("\n");

				arr_buf[m] = arr_tmp[j];

				puts("Move MAIN to BUFFER.");
				puts("\n");
				arrPrint(arr_buf, "BUFFER");
				cntPrint();
				dummy();
				system("pause");
				dummy();
				system("cls");
			}

			for (m = left; m < rend; m++)
			{
				arrPrint(arr_tmp, "MAIN");
				arrowPrint(m, m);
				puts("\n");
				arrPrint(arr_buf, "BUFFER");
				arrowPrint(m, m);
				puts("\n");

				puts("Move BUFFER to MAIN");
				puts("\n");
				arr_tmp[m] = arr_buf[m];
				arrPrint(arr_tmp, "MAIN");
				cntPrint();
				dummy();
				system("pause");
				dummy();
				system("cls");
			}
		}
	}

	arrPrint(arr_tmp, "MAIN");
	cntPrint();
	puts("Loop reached final run, list fully sorted.");
	dummy();
	system("pause");

	free(arr_buf);
}