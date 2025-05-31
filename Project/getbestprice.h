#pragma once
#include "Product.h"
#include <vector>
#include "Map.h"

// Функция для поиска выгодных товаров в интернет магазинах
void get_best_price(std::vector<Product>& massive_products, std::vector<std::string>& all_name_stores, std::vector<int>& all_coef_stores, map<std::string, double>* massive_cities = nullptr);

// Определяет границу где разделяется массив на две части, до элемента возвращаемого идут элементы меньше некоторого pivot, а после больше pivot 
int partition(Product& product, int left, int right, std::vector<std::string>& all_name_stores, std::vector<int>& all_coef_stores, map<std::string, double>* massive_cities = nullptr);