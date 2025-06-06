#pragma once
#include <vector>
#include "Map.h"

struct Product 
{
	std::string name;
	std::string main_info;
	double mass = 0;
	double min_price = 0;
	int sum_count = 0;
	std::vector<std::string> Stores;
	std::vector<double> Stores_base_price;
	std::vector<int> Stores_num_products;

	// Коструктор по умолчанию
	Product() = default;

	// Конструктор
	Product(std::string name, std::string main_info, double mass);

	// Определяет существует ли вообще данный магазин в списке магазинов товара и если да то выдаёт его номер в массиве
	int place_store_vector(int num_store, std::vector<std::string>& all_name_stores);

	// Обменивает все данные магазинов
	void swap_data_stores(int first_index, int second_index);

	// Устанавливает данные магазинов второго индекса данным магазина первого индекса
	void set_data_stores(int first_index, int second_index);

	// Сортирует магазины по алфавиту (сортировка расчёской)
	void sort_by_name();

	// Сортирует магазины по цене (сортировка расчёской) (приколдесы расписаны в cpp)
	//void sort_by_price();

	// По названию магазина находит индекс элемента в массиве конкретного товара (работает при отсортированном массиве по алфавиту)
	int binary_search_store(int index_store, std::vector<std::string>& all_name_stores);

	// Изменяет уже существующую цену в магазине или добавляет новую с новым магазином (требует права администратора)
	void change_price(std::vector<std::string>& all_name_stores);
	
	// Изменяет главную информацию о товаре (требует права администратора)
	void change_main_info();

	// Выводит в консоль магазины и их цены
	void print_price();

	// Удаляет файл в данном случае "Products.txt" (требует права администратора)
	void delete_file();

	// Удаляет данные по определенному магазину
	void delete_store();

	// Выводит минимальную информацию о товаре (имя)
	void print_data();

	// Выводит всю информацию о товаре с базовой ценой
	void print_all_data();

	// Выводит всю информацию о товаре с ценой за доставку
	void print_all_data(std::vector<double>& values);

	// Выдаёт самую минимальную цену
	double get_min_price();

	// Суммирует все количества товара в магазине и выдаёт
	int get_sum_count();

	// Выдаёт коэффициент за доставку в магазине исходя из его индекса в массиве товара
	int get_koef_by_store(int index, std::vector<std::string>& all_name_stores, std::vector<int>& all_coef_stores);

	// Выдаёт полную цену для индекса данного магазина в товаре
	double get_full_price(int index, std::vector<std::string>& all_name_stores, std::vector<int>& all_coef_stores, map<std::string, double>* massive_cities, std::string city);
};