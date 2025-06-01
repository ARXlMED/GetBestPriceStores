#pragma once
#include <windows.h>
#include <vector>
#include "Product.h"
#include "List.h"
#include "Map.h"

// ѕолучить дескриптор консоли
HANDLE get_handle();

// »зменить размер консоли
void change_size_console(int size_console);

// ѕочистить консоль
void clear_console();

// Ќачальное главное меню где предлагаетс€ зарегатьс€ или авторизоватьс€ или зайти в качестве гост€
int main_menu_registrathion(int now_size, std::vector<list<std::string>>& massive_logins, std::vector<list<int>>& massive_hashes, std::vector<list<std::string>>& massive_account_cities, map<std::string, double>& massive_cities, std::string file_name);

// √лавное меню завис€щее от статуса пользовател€ где происходит выбор действий
void main_menu(int user_status);

// ¬ыход из приложени€ без возможности сохранени€ измененной конфигурации
void exit_without_save();

// ¬ыход из приложени€ с предложением сохранить конфигурацию
void exit_with_save(std::vector<Product>& massive_products, std::vector<std::string>& all_name_stores, std::vector<int>& all_coef_stores, std::string file_product, std::string file_all_stores);