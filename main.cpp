#include <iostream>
#include "PrimeNumbers.h"


int main()
{
	int n;
	std::cin >> n;
	std::cout << PrimeNumbers::check_for_prime(n);
	return 0;
	
}