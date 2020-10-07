#include <fstream>
#include <list>
#include <iterator>
#include <algorithm>
#include <iostream>
using namespace std;
void BirthdaySpacingsTest()
{
	const char* filename = "input.txt";
	std::fstream file;
	file.open(filename, std::ios::in);
	int number;
	std::list <int> numbers_list;
	while (!file.eof())
	{
		file >> number;
		numbers_list.push_back(number);
	}
	file.close();

	numbers_list.sort();

	std::list<int> spacings;

	std::list<int>::iterator e = numbers_list.begin();

	int helper;
	for (int i = 0; i < numbers_list.size() - 1; i++) {
		helper = 0;
		e = numbers_list.begin();
		std::advance(e, i);
		auto nx = std::next(e, 1);
		helper = (*nx) - (*e);
		spacings.push_back(helper);

	}

	spacings.sort();

	std::list<int>::iterator it = spacings.begin();
	int counter = 0;
	int result[6];
	for (int i = 0; i < 6; i++) {
		counter = 0;
		it = spacings.begin();

		for (size_t j = 0; j < spacings.size(); j++)
		{
			if (*it == i) {
				counter++;
			}
			result[i] = counter;
			it++;
		}

		std::fstream result("OutputBirthday.txt", std::ios_base::app);
		result << i << " " << counter << "\n";

	}

	return;
}

