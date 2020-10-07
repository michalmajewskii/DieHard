#include <fstream>
#include <iostream>
#include <algorithm>
#include <list> 
#include <iterator>
void SqueezeTest()
{
	const char* filename = "input.txt";
	std::fstream file;
	file.open(filename, std::ios::in);
	int number;
	std::list <uint8_t> numbers_list;
	while (!file.eof())
	{
		file >> number;
		numbers_list.push_back(number);
	}
	file.close();


	std::list<float> squeezed_list(numbers_list.size());
	squeezed_list.assign(numbers_list.begin(), numbers_list.end());
	std::list<float>::iterator p = squeezed_list.begin();
	while (p != squeezed_list.end()) {
		*p /= 255.0f;
		p++;
	}
	
	p = squeezed_list.begin();

	std::list<float> result_list;
	int helper;
	int k = 0;
	float j = 0;


	for (int i = 0; i < squeezed_list.size(); i++)
	{
		k = 2147483647;
		j = 0;

		while ((k != 1) && (j < 48))
		{
			k = nearbyint(k * *p);
			j++;
		}

			if (j < 6) j = 6;
		
		result_list.push_back(j);
		p++;
	}


	std::list<float>::iterator pointer = result_list.begin();
	int counter = 0;

	for (int i = 6; i <= 48; i++) {
		pointer = result_list.begin();
	
		while (pointer != result_list.end()) {
		
			if (*pointer == i) {
				counter++;
			}
			pointer++;
		
		}
		std::fstream result("OutputSqueeze.txt", std::ios_base::app);
		result << i << " " << counter << "\n";
		counter = 0;
	}

	return;
}
