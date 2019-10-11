#include "Car.h"

Car::Car(std::string name, int year, float volume, float cost)
{
	this->name = name;
	this->year = year;
	this->volume = volume;
	this->cost = cost;
}

std::ostream& operator<< (std::ostream& os, const Car& car)
{
	os << "Name: " << car.name << std::endl;
	os << "Year: " << car.year << std::endl;
	os << "Volume: " << car.volume << std::endl;
	os << "Cost: " << car.cost << std::endl;
	os << std::endl;
	return os;
}

const std::string Car::car_name()const
{
	return name;
}

int Car::car_year()const
{
	return year;
}

float Car::car_volume()const
{
	return volume;
}

float Car::car_cost()const
{
	return cost;
}