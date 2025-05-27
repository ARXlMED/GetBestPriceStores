#include "cities.h"
#include <fstream>
#include <sstream>
#include "interface.h"
#include "cin_int.h"

// Возвращает значение из inline переменной now_city
std::string get_now_city()
{
	return now_city;
}

// Смена текущего города у данного аккаунта
void change_now_city(map<std::string, double> cities)
{
	std::string new_city;
	std::cout << "Введите ваш текущий город:\n";
	std::cin >> new_city;
	if (cities.check_presense_key(new_city))
	{
		now_city = new_city;

	}
	else std::cout << "Данного города нет в списке доступных для доставки\n";
}

map<std::string, double> load_all_cities()
{
	map<std::string, double> cities;
	std::ifstream in("Cities.txt");
	std::string city, line;
	double coefficient;
	if (in.is_open())
	{
		while (std::getline(in, line))
		{
			std::istringstream iss(line);
			iss >> city >> coefficient;
			cities.add_value(city, coefficient);
		}
	}
	in.close();
	return cities;
}

// Из за самой струтуры map нельзя выгружать сразу все города
void new_city(map<std::string, double>& cities)
{
	std::string name;
	double lenth;
	std::cout << "Введите название города: \n";
	clear_console();
	std::getline(std::cin, name);
	std::cout << "Введите расстояние до города от Минска \n";
	lenth = cin_double();
	std::ofstream out("Cities.txt", std::ios::app);
	cities.add_value(name, lenth);
	if (out.is_open())
	{
		out << name << " " << lenth << "\n";
	}
	out.close();
}

double get_addict_price(Product product, map<std::string, double> cities, std::string city)
{
	return product.mass * cities.get_value(city) / 100 /* добавить определенный коэффициент от определенного магазина, условно указать цену за 100 км (для удобства) и разделить на 100*/;
}