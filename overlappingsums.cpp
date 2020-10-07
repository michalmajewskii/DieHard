#include <fstream>
#include <algorithm>
#include <list> 
#include <iterator>

void OverlappingSumsTest()
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

	std::list<float> float_numbers(numbers_list.size());
	float_numbers.assign(numbers_list.begin(), numbers_list.end());
	std::list<float>::iterator p = float_numbers.begin();
	while (p != float_numbers.end()) {
		*p /= 255.0f;
		p++;

	}
	p = float_numbers.begin();

	int offset = 100;

	std::list<float>::iterator e = float_numbers.begin();

	std::list <float> sum_list;
	float helper;
	for (int i = 0; i < float_numbers.size() - offset; i++) {

		p = float_numbers.begin();
		std::advance(p, i);
		helper = 0;
		for (int a = 0; a < 100; a++) {
			helper += *p;
			p++;
		}

		sum_list.push_back(helper);

	}

	std::fstream result("OutputOverlappingSum.txt", std::ios::out);

	std::for_each(sum_list.begin(), sum_list.end(), [&](const float i) { result << i << "\n"; });

	return;
}