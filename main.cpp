#include <iostream>
#include "PrimeNumbers.h"
enum class State
{
	RUN,
	QUIT
};

int main()
{
	State state=State::RUN;
	char choice;
	do
	{
		std::cout<<"Enter 'p' to check, if the number is prime, 's' to show scd/scm, 'q' to quit and save all data"<<'\n';
		std::cin >> choice;
		switch (choice)
		{
		case 'p': 
			int n;
			std::cout << "Enter a number"<<'\n';
			std::cin >> n;
			std::cout << std::boolalpha << PrimeNumbers::check_for_prime(n) << '\n';
			break;
		case 's':
			int a, b;
			std::cout << "Enter 2 numbers"<<'\n';
			std::cin >> a >> b;
			std::cout << "SCD = " << PrimeNumbers::scd(a, b)<<'\n';
			std::cout << "SCM = " << PrimeNumbers::scm(a, b) << '\n';
			break;
		case 'q':
			state = State::QUIT;
			break;
		default:
			std::cout << "Error key"<<'\n';
			break;
		}
	}
	while (state!=State::QUIT);
	return 0;
	
}