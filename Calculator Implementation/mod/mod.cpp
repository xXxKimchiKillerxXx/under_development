#include "std.h"

void Mod::set_A(int _A)
{
	A = _A;
}

void Mod::set_B(int _B)
{
	B = _B;
}

int Mod::get_A() const
{
	return A;
}

int Mod::get_B() const
{
	return B;
}

void Mod::mod_input()
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

int Mod::mod_alg()
{
	A = get_A();
	B = get_B();
	int tmp = A;

	try
	{
		if (B <= 0)
		{
			throw "Divisor must be a positive integer.";
		}
		if (A >= B)
		{
			while (!(0 <= tmp && tmp < B))
			{
				tmp -= B;
			}
			return tmp;
		}
		else
		{
			while (!(0 <= tmp && tmp < B))
			{
				tmp += B;
			}
			return tmp;
		}
	}
	catch (const char* str)
	{
		cout << str << endl;

		return -1;
	}
}

void Mod::mod_print()
{
	int value = mod_alg();

	if (value == -1)
	{
		return;
	}

	printf("mod(%i, %i) = %i", get_A(), get_B(), value);
}