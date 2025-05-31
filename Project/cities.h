#pragma once
#include "Product.h"
#include "Map.h"

inline std::string now_city = "�����";

std::string get_now_city();

void change_now_city(map<std::string, double> cities);

map<std::string, double> load_all_cities();

void new_city(map<std::string, double>& cities);

// �������� �������������� ���� ��� ������� ������ ��� ������� �������� ��� ������� ������
double get_addict_price(Product& product, int index_store_in_product, std::vector<std::string>& all_name_stores, std::vector<int>& all_coef_stores, map<std::string, double>* massive_cities, std::string city = now_city);