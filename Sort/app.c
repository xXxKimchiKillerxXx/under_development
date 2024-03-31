#include "std.h"

void app_init()
{
	logo();
	con_init();
}

void app_run()
{
	system("cls");

	char ch, conf;

	if (fmake() || fload()) return;

	while (true)
	{
		con_arr();	//Run initialization.
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
			sort_merge_non_rec();
			break;
		case '5':
			sort_merge_rec();
			break;
		case '0':
			puts("Confirm [Y / N]");
			conf = _getch();

			switch (conf)
			{
			case 'Y':
			case 'y':
				return;
			case 'N':
			case 'n':
				break;
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
	//puts("- Student No.202310631");
	puts("- Class: Algorithm (003)");
	system("pause");
}

void menuprint()
{
	puts("MENU");
	puts("");
	puts("[1] Bubble Sort");
	puts("[2] Insertion Sort");
	puts("[3] Selection Sort");
	puts("[4] Merge Sort (Non-Recursive)");
	puts("[5] Merge Sort (Recursive)");
	puts("[0] Exit");
}

void ending()
{
	system("cls");
	puts("Terminated");
}