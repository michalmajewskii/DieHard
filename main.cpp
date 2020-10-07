#include <iostream>


void SqueezeTest();
void OverlappingSumsTest();
void BirthdaySpacingsTest();

int main()
{
	int choice;
	std::cout << "Please choose test: 1)Overlapping Sums Test 2)Birthday Spacings Test 3)Squeeze Test "; 
	std::cin >> choice;

	switch (choice) {
	case 1:
		OverlappingSumsTest();
		break;
	case 2:
		BirthdaySpacingsTest();
		break;
	case 3:
		SqueezeTest();

	}




	return 0;
}