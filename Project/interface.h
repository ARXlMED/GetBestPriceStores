#pragma once
#include <windows.h>
#include <vector>
#include "Product.h"
#include "List.h"
#include "Map.h"

// �������� ���������� �������
HANDLE get_handle();

// �������� ������ �������
void change_size_console(int size_console);

// ��������� �������
void clear_console();

// ��������� ������� ���� ��� ������������ ���������� ��� �������������� ��� ����� � �������� �����
int main_menu_registrathion(int now_size, std::vector<list<std::string>>& massive_logins, std::vector<list<int>>& massive_hashes, std::vector<list<std::string>>& massive_account_cities, map<std::string, double>& massive_cities, std::string file_name);

// ������� ���� ��������� �� ������� ������������ ��� ���������� ����� ��������
void main_menu(int user_status);

// ����� �� ���������� ��� ����������� ���������� ���������� ������������
void exit_without_save();

// ����� �� ���������� � ������������ ��������� ������������
void exit_with_save(std::vector<Product>& massive_products, std::vector<std::string>& all_name_stores, std::vector<int>& all_coef_stores, std::string file_product, std::string file_all_stores);