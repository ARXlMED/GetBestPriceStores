#pragma once
#include <vector>
#include "Product.h"

// ��������� ��� ������ �� �����
std::vector<Product> load_products(std::string file_name);

// ��������� ��� ������ ���������� � ���� (������� ����� ��������������)
void upload_products(std::vector<Product>& vector_products, std::string file_name);