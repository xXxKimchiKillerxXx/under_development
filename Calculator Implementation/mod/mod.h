#pragma once

class Mod
{
	int A;
	int B;

public:
	void set_A(int _A);
	void set_B(int _B);

	int get_A() const;
	int get_B() const;

	void mod_input();
	int mod_alg();
	void mod_print();
};