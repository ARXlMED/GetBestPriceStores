#pragma once
#include <vector>
#include "Product.h"

// Загружает все данные из файла
std::vector<Product> load_products(std::string file_name);

// Выгружает все данные структруры в файл (требует права администратора)
void upload_products(std::vector<Product>& massive_products, std::string file_name);