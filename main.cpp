#include <iostream>
#include <utility>
#include "container.h"

void test_copy(container c)
{
	std::cout << "Funkcija test_copy primila container (copy konstruktor)" << std::endl;
}

container create_container()
{
	container temp(2);
	temp.push_back(100);
	temp.push_back(200);
	return temp;
}

int main()
{
	std::cout << "\n1.\n";
	container c1(2);
	c1.push_back(10);
	c1.push_back(20);
	c1.push_back(30);

	std::cout << "\n2.\n";
	container c2 = c1;

	std::cout << "\n3.\n";
	container c3 = std::move(c1);

	std::cout << "\n4.\n";
	test_copy(c2);

	std::cout << "\n5.\n";
	container c4 = create_container();

	std::cout << "\n6. \n";
	c4.push_back(300);
	c4.push_back(400);

	std::cout << "\n7.\n";
	for (size_t i = 0; i < c3.size(); ++i)
		std::cout << "Index " << i << " -> " << c3.at(i) << std::endl;

	std::cout << "\nKraj programa.\n";
	system("pause");
	return 0;
}