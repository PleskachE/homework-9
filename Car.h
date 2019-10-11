#pragma once

#ifndef CAR_H_
#define CAR_H_

#include <string>
#include <iostream>

class Car
{
private:
	std::string name;
	int year;
	float volume;
	float cost;
public:
	Car() = default;
	Car(std::string name, int year, float volume, float cost);
	Car(const Car& from) = default;
	Car(Car&& from) = default;
	Car& operator=(const Car& right) = default;
	Car& operator=(Car&& right) = default;
	~Car() {}
	friend std::ostream& operator<<
		(std::ostream& os, const Car& car);
public:
	// getters 
	const std::string car_name()const;
	int car_year()const;
	float car_volume()const;
	float car_cost()const;
};

#endif