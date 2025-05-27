#pragma once
#include "Product.h"
#include <vector>
#include "Map.h"

void get_best_price(std::vector<Product>& products, std::vector<std::string>& all_name_stores, std::vector<int>& all_coef_stores, map<std::string, double>* massive_cities = nullptr);

void sort_by_price(Product product, std::vector<std::string>& all_name_stores, std::vector<int>& all_coef_stores, map<std::string, double>* massive_cities);