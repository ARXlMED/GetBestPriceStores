#pragma once
#include "Product.h"
#include "Map.h"

inline std::string now_city = "Минск";

std::string get_now_city();

void change_now_city(map<std::string, double> cities);

map<std::string, double> load_all_cities();

void new_city(map<std::string, double>& cities);

double get_addict_price(Product product, map<std::string, double> cities, std::string city = "Minsk");