#pragma once
#include <vector>
#include "Product.h"

// ��������� ��� ������ �� �����
std::vector<Product> load_products();

// ��������� ��� ������ ���������� � ���� (������� ����� ��������������)
void upload_products(std::vector<Product>& vector_products);