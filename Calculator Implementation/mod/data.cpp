#include "std.h"

bool Data::set_queue()
{
	int input = NULL;

	cout << "Inputs are requested until 'CTRL + Z' is entered." << endl;

	if (input == EOF)
	{

	}
	while (input != EOF)
	{
		int i = 0;

		cout << "[" << ++i << "] ";
		cin >> input;

		QUEUE.push(input);
	}
}

int* Data::get_queue()
{
	return QUEUE;
}