#include "std.h"

extern int* arr_tmp, size, cnt_cmp;

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void arr_print(int* arr, const char* name_arr)
{
	puts(name_arr);
	for (int i = 0; i < size; i++)
	{
		printf("%5d ", arr[i]);
	}
	puts("");
}

void cnt_print()
{
	puts("");
	printf("Total Comparisons: %d", cnt_cmp);
	puts("");
}

void arrow_print(int left, int right)
{
	for (int i = 0; i < left; i++)
	{
		printf("      ");
	}

	printf("^^^^^ ");

	for (int i = left + 1; i < right; i++)
	{
		printf("      ");
	}

	printf("^^^^^ ");
}

void sort_bubble()
{
	for (int i = size - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			arr_print(arr_tmp, "Main Array");
			arrow_print(j, j + 1);
			puts("\n");
			puts("Items Comparison");
			printf("%5d %5d\n", arr_tmp[j], arr_tmp[j + 1]);

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
			puts("");

			arr_print(arr_tmp, "Main Array");
			cnt_print();			
			void dummy();
			system("pause");

			if(cnt_cmp == size * (size - 1) / 2)
			{
				puts("Loop has reached final run, list fully sorted.");
				void dummy();
				system("pause");
			}

			void dummy();
			system("cls");
		}
	}
}

void sort_insertion(int* arr, int size)
{

}

void sort_selection()
{
	int idx_min;

	for (int i = 0; i < size - 1; i++)
	{
		idx_min = i;

		for (int j = i + 1; j < size; j++)
		{
			arr_print(arr_tmp, "Main Array");
			arrow_print(idx_min, j);
			puts("");
			puts("Items Comparison");
			printf("HAND: %d, FIND: %d\n", arr_tmp[idx_min], arr_tmp[j]);
			puts("Item Positions");
			printf("HAND at %d, FIND at %d\n", idx_min + 1, j + 1);
			puts("");

			if (arr_tmp[j] < arr_tmp[idx_min])
			{
				puts("FIND < HAND, keeping the position.");

				idx_min = j;
			}
			else
			{
				puts("Not FIND < HAND, moving to the next FIND.");
			}
			puts("");
			cnt_cmp++;

			cnt_print();
			void dummy();
			system("pause");
			void dummy();
			if (i != size - 2)
				system("cls");
		}

		if (idx_min != i)
		{
			void dummy();
			system("cls");
			arr_print(arr_tmp, "Main Array");
			arrow_print(i, idx_min);
			puts("\n");
			puts("Swap.");
			puts("\n");

			swap(&arr_tmp[i], &arr_tmp[idx_min]);

			arr_print(arr_tmp, "Main Array");
			cnt_print();
			void dummy();
			system("pause");
		}

		if (cnt_cmp == size * (size - 1) / 2)
		{
			puts("Loop has reached final run, list fully sorted.");
			void dummy();
			system("pause");
		}

		void dummy();
		system("cls");
	}
}

void sort_merge_rec(int* arr, int size)
{

}

void sort_merge_non_rec()
{
	int* arr_buf = (int*)malloc(size * sizeof(int));
	int rght, rend;
	int i, j, m;

	for (int k = 1; k < size; k *= 2)
	{
		memset(arr_buf, 0, size * sizeof(int));	//Buffer array reset.

		for (int left = 0; left + k < size; left += 2 * k)
		{
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
				arr_print(arr_tmp, "Main Array");
				arrow_print(i, j);
				puts("");
				puts("Items Comparison");
				printf("%5d %5d\n", arr_tmp[i], arr_tmp[j]);

				if (arr_tmp[i] < arr_tmp[j])
				{
					puts("LEFT is less.");
					arr_buf[m] = arr_tmp[i];
					i++;
				}
				else
				{
					puts("LEFT is not less.");
					arr_buf[m] = arr_tmp[j];
					j++;
				}
				puts("\n");
				puts("Copy the less.");
				puts("\n");
				cnt_cmp++;

				arr_print(arr_tmp, "Main Array");
				puts("\n");
				arr_print(arr_buf, "Buffer Array");
				cnt_print();
				void dummy();
				system("pause");
				void dummy();
				system("cls");
			}

			for (; i < rght; i++, m++)
			{
				arr_buf[m] = arr_tmp[i];
			}

			for (; j < rend; j++, m++)
			{
				arr_buf[m] = arr_tmp[j];
			}

			for (m = left; m < rend; m++)
			{
				arr_tmp[m] = arr_buf[m];
			}

			puts("The buffer is transferred to the main.");
			arr_print(arr_tmp, "Main Array");
			cnt_print();
			void dummy();
			system("pause");
			void dummy();
			system("cls");
		}
	}			
	
	arr_print(arr_tmp, "Main Array");
	cnt_print();
	puts("");
	puts("Loop has reached final run, list fully sorted.");
	void dummy();
	system("pause");

	free(arr_buf);
}