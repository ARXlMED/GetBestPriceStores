#pragma once
#include <vector>
#include <string>

// Загрузить все данные о названиях магазинах и коэффициентах доставки в них
void load_all_stores(std::vector<std::string>& all_name_stores, std::vector<int>& all_coef_stores, std::string file_name);

// Выгрузить в файл все данные о названиях магазинах и коэффициентах доставки в них
void upload_all_stores(std::vector<std::string>& all_name_stores, std::vector<int>& all_coef_stores, std::string file_name);

// Добавить новый магазин и его коэффициент доставки в переменные
void new_store(std::vector<std::string>& all_name_stores, std::vector<int>& all_coef_stores);