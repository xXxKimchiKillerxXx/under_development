#include "std.h"

void GCD::set_A(int _A)
{
	A = _A;
}

void GCD::set_B(int _B)
{
	B = _B;
}

int GCD::get_A() const
{
	return A;
}

int GCD::get_B() const
{
	return B;
}

void GCD::gcd_input()
{
	int A;
	int B;

	cout << "Put A: ";
	cin >> A;
	set_A(A);

	cout << "Put B: ";
	cin >> B;
	set_B(B);
}

int GCD::gcd_alg()
{
	Mod mod;

	A_prev = A;	//Remembers A.
	B_prev = B;	//Remembers B.

	int rem_tmp;	//Temporary remainder variable.
	int tmp;	//The swap variable.

	try
	{
		if (A <= 0 || B <= 0)	//Exceptions.
		{
			throw("A and B must be positive.");
		}
		if (B >= A)	//The swap function.
		{
			tmp = B;
			B = A;
			A = tmp;
		}

		mod.set_A(A);
		mod.set_B(B);

		rem_tmp = mod.mod_alg();

		if (rem_tmp == 0)	//The least divides another.
		{
			return B;	//The least.
		}

		while (rem_tmp != 0)
		{
			A = B;
			B = rem_tmp;

			mod.set_A(A);
			mod.set_B(B);

			rem_tmp = mod.mod_alg();
		}
		return B;	//The Euclidean algorithm.
	}
	catch (const char* msg)
	{
		cout << msg << endl;

		return -1;
	}
}

void GCD::gcd_print()
{
	int value = gcd_alg();

	if (value == -1)
	{
		return;
	}

	printf("GCD(%i, %i) = %i", A_prev, B_prev, value);
}