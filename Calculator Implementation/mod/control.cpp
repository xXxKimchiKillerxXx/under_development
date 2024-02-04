#include "std.h"

void Control::menu()
{
	cout << "1. Two numbers." << endl;
	cout << "2. More than two." << endl;
	cout << "3. Termination." << endl;
}

void Control::run()
{
	int choice;

	while(true)
	{
		menu();

		choice = _getch();

		system("cls");

		switch (choice)
		{
		case '1':
			general_run();

			break;
		case '2':
			multi_run();

			break;
		case '3':
			return;
		}
	}

}

void Control::general_menu()
{
	cout << "1. modulo" << endl;
	cout << "2. GCD" << endl;
	cout << "3. LCM" << endl;
}

void Control::general_run()
{
	int choice;

	system("cls");

	general_menu();

	cout << "Choice: " << endl;

	choice = _getch();

	system("cls");

	switch (choice)
	{
	case '1':
		cout << "mod(A, B) calculator" << endl;

		general_mod_run();

		break;
	case '2':
		cout << "GCD(A, B) calculator" << endl;

		general_gcd_run();

		break;
	case '3':
		cout << "LCM(A, B) calculator" << endl;

		general_lcm_run();
	}
}

void Control::multi_menu()
{
	cout << "1. GCD" << endl;
	cout << "2. LCM" << endl;
}

void Control::multi_run()
{
	int choice;

	system("cls");

	general_menu();

	cout << "Choice: " << endl;

	choice = _getch();

	system("cls");

	switch (choice)
	{
	case '1':
		cout << "GCD(A, B, ...) calculator" << endl;

		general_mod_run();

		break;
	case '2':
		cout << "LCM(A, B, ...) calculator" << endl;

		general_gcd_run();
	}
}

void Control::general_mod_run()
{
	Mod mod;

	mod.mod_input();
	mod.mod_print();
}

void Control::general_gcd_run()
{
	GCD GCD;

	GCD.gcd_input();
	GCD.gcd_print();
}

void Control::general_lcm_run()
{
	LCM LCM;

	LCM.lcm_print();
}

void Control::multi_gcd_run()
{

}

void Control::multi_lcm_run()
{

}