#pragma warning(disable:6031)
#include "std.h"

#define FNAME "Sample.txt"

int* arr, size;

bool fmake()
{
	FILE* fp;
	fp = fopen(FNAME, "w");
	//Generates a sample.

	if (fp == NULL)
	{
		puts("Error Generating Sample");
		return true;
	}
	else
	{
		puts("Sample File Generated");
		puts("");
	}

	int n, rint;

	printf("Number of Randoms: ");
	scanf("%d", &n);
	puts("");
	fprintf(fp, "%d\n", n);	//Saves number of randoms.

	while (n--)
	{
		rint = rand();	//A random.
		fprintf(fp, "%d\n", rint);	//Copies to the sample.
	}

	fclose(fp);
	puts("Sample Made");
	puts("");
	return false;
}

bool fload()
{
	FILE* fp;
	fp = fopen(FNAME, "r");
	//Opens the sample.

	if (fp == NULL)
	{
		puts("Error reading text file.");
		return true;
	}
	fscanf(fp, "%d", &size);	//Gets the total.
	arr = (int*)malloc(size * sizeof(int));	//Array generation.

	int num;	//Number copied to the array.
	for (int i = 0; i < size; i++)
	{
		fscanf(fp, "%d", &num);	//Reads integer from each file line.
		arr[i] = num;
	}

	puts("Read Successful");
	fclose(fp);
	void dummy();
	system("pause");
	return false;
}