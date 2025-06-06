#pragma once
#include <vector>
#include "Map.h"

struct Product 
{
	std::string name;
	std::string main_info;
	double mass = 0;
	double min_price = 0;
	int sum_count = 0;
	std::vector<std::string> Stores;
	std::vector<double> Stores_base_price;
	std::vector<int> Stores_num_products;

	// ���������� �� ���������
	Product() = default;

	// �����������
	Product(std::string name, std::string main_info, double mass);

	// ���������� ���������� �� ������ ������ ������� � ������ ��������� ������ � ���� �� �� ����� ��� ����� � �������
	int place_store_vector(int num_store, std::vector<std::string>& all_name_stores);

	// ���������� ��� ������ ���������
	void swap_data_stores(int first_index, int second_index);

	// ������������� ������ ��������� ������� ������� ������ �������� ������� �������
	void set_data_stores(int first_index, int second_index);

	// ��������� �������� �� �������� (���������� ���������)
	void sort_by_name();

	// ��������� �������� �� ���� (���������� ���������) (���������� ��������� � cpp)
	//void sort_by_price();

	// �� �������� �������� ������� ������ �������� � ������� ����������� ������ (�������� ��� ��������������� ������� �� ��������)
	int binary_search_store(int index_store, std::vector<std::string>& all_name_stores);

	// �������� ��� ������������ ���� � �������� ��� ��������� ����� � ����� ��������� (������� ����� ��������������)
	void change_price(std::vector<std::string>& all_name_stores);
	
	// �������� ������� ���������� � ������ (������� ����� ��������������)
	void change_main_info();

	// ������� � ������� �������� � �� ����
	void print_price();

	// ������� ���� � ������ ������ "Products.txt" (������� ����� ��������������)
	void delete_file();

	// ������� ������ �� ������������� ��������
	void delete_store();

	// ������� ����������� ���������� � ������ (���)
	void print_data();

	// ������� ��� ���������� � ������ � ������� �����
	void print_all_data();

	// ������� ��� ���������� � ������ � ����� �� ��������
	void print_all_data(std::vector<double>& values);

	// ����� ����� ����������� ����
	double get_min_price();

	// ��������� ��� ���������� ������ � �������� � �����
	int get_sum_count();

	// ����� ����������� �� �������� � �������� ������ �� ��� ������� � ������� ������
	int get_koef_by_store(int index, std::vector<std::string>& all_name_stores, std::vector<int>& all_coef_stores);

	// ����� ������ ���� ��� ������� ������� �������� � ������
	double get_full_price(int index, std::vector<std::string>& all_name_stores, std::vector<int>& all_coef_stores, map<std::string, double>* massive_cities, std::string city);
};