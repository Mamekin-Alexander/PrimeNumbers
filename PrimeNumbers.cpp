#include "PrimeNumbers.h"
PrimeNumbers::Loader::Loader()
{
	std::ifstream source ("DataBase.txt");
	if (source.peek() == std::ifstream::traits_type::eof())
	{
		DataBase.push_back(2);
		greatest_checked=2;
	}
	else
	{	
		int tmp;
		while (!source.eof())
		{
			source >> tmp;
			DataBase.push_back(tmp);
		}
		greatest_checked = DataBase.back();
		DataBase.pop_back();
	}
	source.close();
	return;
}
PrimeNumbers::Loader::~Loader()
{

	std::remove("DataBase.txt");
	std::ofstream source("DataBase.txt");
	for (int i = 0; i < DataBase.size(); i++)
		source << DataBase.at(i) << '\n';
	source << greatest_checked;
	source.close();
}


/*Methods*/
void PrimeNumbers::print_prime_numbers()
{
	for (int i=0; i<DataBase.size(); i++)
		std::cout<<DataBase.at(i)<<'\n';
}
bool PrimeNumbers::check_for_prime(int n)
{
	bool result = false;
	if (n <= greatest_checked)
		result=bin_search(DataBase, n);
	else                                    //if number is greater then greatest checked,
	{										//start sieve of eratothenes
		std::vector<int> tmp;
		for (int i = greatest_checked + 1; i <= n; i++)		//make vector tmp of elements from greatest checked to n
			tmp.push_back(i);

		/*look through all prime numbers*/
		for (int i = 0; i < DataBase.size(); i++)			
		{
			int current_prime = DataBase.at(i);	
			int j = 0;	

			/*removing all unprime numbers from vector*/
			while (j < tmp.size())				
			{
				if (tmp.at(j) % current_prime == 0)			
				{
					tmp.erase(tmp.begin()+j);
					j--;
				}
				j++;
			}
			if (!tmp.empty())
			{				
				if (tmp.front() == n)				//if this number equals our checked number, stop the search
					result = true;
				DataBase.push_back(tmp.front());		//The first number in tmp vector will be prime, add it DataBase
				tmp.erase(tmp.begin());					//Delete if tmp
			}
		}
		greatest_checked = n;
	}

	return result;
}
std::vector<int> PrimeNumbers::prime_factorization(int n)
{
	std::vector<int> result;
	if (PrimeNumbers::check_for_prime(n))
		result.push_back(n);
	else
	{
		int i = 0;
		while (DataBase.at(i) <= n)
		{
			//std::cout << DataBase.at(i) << '\n';
			while (n % DataBase.at(i) == 0)
			{
				result.push_back(DataBase.at(i));
				n = n / DataBase.at(i);
			}
			i++;
		}
	}
	return result;
}
int PrimeNumbers::scd(int first, int second)
{
	std::vector<int> fact1 = prime_factorization(first);
	std::vector<int> fact2 = prime_factorization(second);
	int res = 1;
	int i;
	while ((!fact1.empty()) && (!fact2.empty()) )
	{
		if (fact1.front() == fact2.front())
		{
			res = res*fact1.front();
			fact1.erase(fact1.begin());
			fact2.erase(fact2.begin());
		}
		else
			if (fact1.front() < fact2.front())
				fact1.erase(fact1.begin());
			else fact2.erase(fact2.begin());
	}
	return res;
}
int PrimeNumbers::scm(int first, int second)
{
	return (first * second / scd(first, second));
}


/*Static members*/
std::vector<int> PrimeNumbers::DataBase;
int PrimeNumbers::greatest_checked;
PrimeNumbers::Loader PrimeNumbers::loader;

/*Functions*/
bool bin_search(const std::vector<int>& mas, const int key)
{
	bool result = false;
	int left = 0;
	int right = mas.size() - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (key == mas.at(mid))
			return true;
		if (key < mas.at(mid))
			right = mid - 1;
		else left = mid + 1;
	}
	return result;
}