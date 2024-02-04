#include "std.h"

int Algorithms::pivot()
{
	Mod mod;
	Data data;

	int size = data.QUEUE.size();	//Counts from 1.

	mod.set_A(size);
	mod.set_B(2);
	int rem = mod.mod_alg();

	int tmp = (size + rem) / 2 - 1;

	return tmp;
}