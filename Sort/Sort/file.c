#pragma warning(disable:6031)
#include "std.h"

#define FNAME "Sample.txt"

short* arr, size;

bool fMake()
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

	short n, rInt;

	printf("Number of Randoms: ");
	scanf("%hd", &n);
	puts("");
	fprintf(fp, "%d\n", n);	//Saves number of randoms.

	while (n--)
	{
		rInt = rand();	//A random.
		fprintf(fp, "%d\n", rInt);	//Copies to the sample.
	}

	fclose(fp);
	puts("Sample Made");
	puts("");
	return false;
}

bool fLoad()
{
	FILE* fp;
	fp = fopen(FNAME, "r");
	//Opens the sample.

	if (fp == NULL)
	{
		puts("Error reading text file.");
		return true;
	}
	fscanf(fp, "%hd", &size);	//Gets the total.
	arr = (short*)malloc(size * sizeof(short));	//Array generation.

	short num;	//Number copied to the array.
	for (int i = 0; i < size; i++)
	{
		fscanf(fp, "%hd", &num);	//Reads integer from each file line.
		arr[i] = num;
	}

	puts("Read Successful");
	fclose(fp);
	dummy();
	system("pause");
	return false;
}