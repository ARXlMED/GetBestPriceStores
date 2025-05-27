#pragma once
#include <vector>
#include "Product.h"

// Загружает все данные из файла
std::vector<Product> load_products();

// Выгружает все данные структруры в файл (требует права администратора)
void upload_products(std::vector<Product>& vector_products);