#pragma once
#include "Product.h"
#include "Map.h"

// Глобальная переменная хранящая город текущего пользователя
inline std::string now_city = "Минск";

// Возвращает значение из inline переменной now_city
std::string get_now_city();

// Смена текущего города у данного аккаунта
void change_now_city(map<std::string, double> cities);

// Загрузить все города из файла
map<std::string, double> load_all_cities(std::string file_name);

// Добавить новый город в структуру и в файл
void new_city(map<std::string, double>& cities, std::string file_name);

// Получить дополнительную цену для данного товара для данного магазина для данного города
double get_addict_price(Product& product, int index_store_in_product, std::vector<std::string>& all_name_stores, std::vector<int>& all_coef_stores, map<std::string, double>* massive_cities, std::string city = now_city);