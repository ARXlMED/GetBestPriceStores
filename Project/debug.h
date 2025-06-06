#pragma once
#include "Product.h"
#include "List.h"

// Вывод всех аккаунтов содержащихся в массивах
void debug_accounts(int now_size, std::vector<list<std::string>> &massive_logins, std::vector<list<unsigned int>> &massive_hashes, std::vector<list<std::string>>& massive_account_cities);
