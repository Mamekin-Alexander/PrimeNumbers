#pragma once
#include <vector>
#include <fstream>
#include <iostream>

class PrimeNumbers
{
private:
	static std::vector<int> DataBase;
public:
	class Loader
	{
	public:
		Loader();
		~Loader();
	};  //Class to load data, because there is no static constructor in C++

	/*Methods*/
	static void print_prime_numbers();
	static bool check_for_prime(int);
	static std::vector<int> prime_factorization(int);
	static int scd(int, int);
	static int scm(int, int);
private:
	static Loader loader;
	static int greatest_checked;
};

/*Functions*/
bool bin_search(const std::vector<int>&,const int);
