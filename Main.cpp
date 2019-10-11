#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>

#include "Car.h"

enum { QUIT, ADD, DELETE, SORT, SHOW };

const unsigned PARAMS = 4;

using Park = std::vector<Car>;
using Compare = bool(*)(const Car&, const Car&); // pointer to a function typedef

bool name_cmp(const Car& first, const Car& second);
bool year_cmp(const Car &first, const Car& second);
bool cost_cmp(const Car& first,const Car& second);
bool volume_cmp(const Car& first, const Car& second);

// Array of pointer to a functions
const Compare cmp[PARAMS] = { name_cmp, year_cmp, cost_cmp, volume_cmp };

void menu();

void show_car(const Car& car);
void delete_car(Park& park);
void add_car(Park& park);
void sort_park(Park& park);

int main()
{
	const Car lada("Lada", 2016, 1.6, 10000);
	const Car ford("Ford", 2013, 1.8, 11000);
	const Car mers("Mersedes", 2012, 1.9, 9000);
	const Car jeely("Jeely", 2019, 2.0, 20000);
	const Car opel("Opel", 2018, 2.2, 22000);
	Park park({ lada, ford, mers, jeely, opel }); // initializer_list
	int choice;
	menu();
	std::cin >> choice;
	while (choice != QUIT)
	{
		switch (choice)
		{
		case SHOW: for_each(park.begin(), 
			park.end(), show_car); break;
		case DELETE: delete_car(park); break;
		case ADD: add_car(park); break;
		case SORT: sort_park(park); break;
		default : continue;
		}
		system("pause");
		system("cls");
		menu();
		std::cin >> choice;
	}

}

bool name_cmp(const Car& first, const Car& second)
{
	return first.car_name() < second.car_name();
}

bool year_cmp(const Car &first, const Car& second)
{
	return first.car_year() < second.car_year();
}

bool cost_cmp(const Car& first, const Car& second)
{
	return first.car_cost() < second.car_cost();
}

bool volume_cmp(const Car& first, const Car& second)
{
	return first.car_volume() < second.car_volume();
}

void menu()
{
	std::cout << "Choose option (0 to quit): \n";
	std::cout << "1. Add a car  2. Delete a car\n";
	std::cout << "3. Sort cars  4. Show cars\n";
}

void show_car(const Car& car)
{
	std::cout << car;
}

void delete_car(Park& park)
{
	std::cout << "Choose car number: ";
	int choice;
	std::cin >> choice;
	while (choice > park.size() || choice < 1)
	{
		std::cout << "Choose car number: ";
		std::cin >> choice;
	}
	park.erase(park.begin() + choice - 1);
}

void add_car(Park& park)
{
	std::string name;
	int year;
	float cost;
	float volume;
	std::cout << "Enter name: ";
	std::cin >> name;
	std::cout << "Enter year: ";
	std::cin >> year;
	std::cout << "Enter cost: ";
	std::cin >> cost;
	std::cout << "Enter volume: ";
	std::cin >> volume;
	Car new_car(name, year, volume, cost);
	park.push_back(new_car);
}

void sort_park(Park& park)
{
	std::cout << "Choose sort option: ";
	int choice;
	std::cout << "1. By name 2. By year 3. By cost 4. By power\n";
	std::cin >> choice;
	while (choice > PARAMS || choice < 1)
	{
		std::cout << "Choose sort option: ";
		std::cin >> choice;
	}
	std::sort(park.begin(), 
		park.end(), cmp[choice - 1]);
}
