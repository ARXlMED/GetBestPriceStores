#pragma once
#include <vector>
#include "List.h"
#include "Map.h"

// Проверка существует ли в массивах такой логин и пароль который ввёл пользователь в данной функции
int authorizathion(int size_massive, std::vector<list<std::string>>& massive_logins, std::vector<list<int>>& massive_hashes, std::vector<list<std::string>>& massive_account_cities);

// Регистрация нового аккаунта с выгрузкой в массив и в файл
void registrathion(int size_massive, std::vector<list<std::string>>& massive_logins, std::vector<list<int>>& massive_hashes, map<std::string, double>& massive_cities);

// Подгрузка в массивы всех данных про аккаунты с файлов
void load_data_accounts(int size_massive, std::vector<list<std::string>>& massive_logins, std::vector<list<int>>& massive_hashes, std::vector<list<std::string>>& massive_account_cities);