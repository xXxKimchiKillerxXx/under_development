#include "std.h"

void app_init()
{
	logo();
	con_init();
}

void app_run()
{
	dummy();
	system("cls");

	char ch, conf;

	if (fMake() || fLoad()) return;

	while (true)
	{
		con_reset();	//Run initialization.

		dummy();
		system("cls");

		menuprint();
		ch = _getch();

		dummy();
		system("cls");

		switch (ch)
		{
		case '1':
			sort_bubble();
			break;
		case '2':
			sort_insertion();
			break;
		case '3':
			sort_selection();
			break;
		case '4':
			sort_merge();
			break;
		case '0':
			puts("Confirm [Y]");
			conf = _getch();

			switch (conf)
			{
			case 'Y':
			case 'y':
				return;
			}
		}
	}
}

void app_exit()
{
	ending();
	con_exit();
}

void logo()
{
	puts("Sorting Algorithms");
	puts("- Student No.202310631");
	puts("- Class: Algorithm (003)");
	dummy();
	system("pause");
}

void menuprint()
{
	puts("MENU");
	puts("");
	puts("[1] Bubble Sort");
	puts("[2] Insertion Sort");
	puts("[3] Selection Sort");
	puts("[4] Merge Sort");
	puts("[0] Exit");
}

void ending()
{
	dummy();
	system("cls");
	puts("Terminated");
}