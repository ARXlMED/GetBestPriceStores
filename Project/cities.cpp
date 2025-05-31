#include "cities.h"
#include <fstream>
#include <sstream>
#include "interface.h"
#include "cin_int.h"

// ���������� �������� �� inline ���������� now_city
std::string get_now_city()
{
	return now_city;
}

// ����� �������� ������ � ������� ��������
void change_now_city(map<std::string, double> cities)
{
	std::string new_city;
	std::cout << "������� ��� ������� �����:\n";
	std::cin >> new_city;
	if (cities.check_presense_key(new_city))
	{
		now_city = new_city;

	}
	else std::cout << "������� ������ ��� � ������ ��������� ��� ��������\n";
}

// ��������� ��� ������ �� �����
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

// �������� ����� ����� � ��������� � � ����
void new_city(map<std::string, double>& cities)
{
	std::string name;
	double lenth;
	std::cout << "������� �������� ������: \n";
	clear_console();
	std::getline(std::cin, name);
	std::cout << "������� ���������� �� ������ �� ������ \n";
	lenth = cin_double();
	std::ofstream out("Cities.txt", std::ios::app);
	cities.add_value(name, lenth);
	if (out.is_open())
	{
		out << name << " " << lenth << "\n";
	}
	out.close();
}

// �������� �������������� ���� ��� ������� ������ ��� ������� �������� ��� ������� ������
double get_addict_price(Product& product, int index_store_in_product, std::vector<std::string>& all_name_stores, std::vector<int>& all_coef_stores, map<std::string, double>* massive_cities, std::string city)
{
	if (massive_cities == nullptr) return 0;
	else return product.mass * (*massive_cities).get_value(city) / 100 * product.get_koef_by_store(index_store_in_product, all_name_stores, all_coef_stores);
}