#include "std.h"

int LCM::lcm_alg()
{
	GCD GCD;

	GCD.gcd_input();

	A = GCD.get_A();
	B = GCD.get_B();

	int tmp = GCD.gcd_alg();

	int value = A * B / tmp;

	return value;
}

void LCM::lcm_print()
{
	int value = lcm_alg();

	printf("LCM(%i, %i) = %i", A, B, value);
}