#pragma once
#include <vector>
#include <string>

// ��������� ��� ������ � ��������� ��������� � ������������� �������� � ���
void load_all_stores(std::vector<std::string>& all_name_stores, std::vector<int>& all_coef_stores, std::string file_name);

// ��������� � ���� ��� ������ � ��������� ��������� � ������������� �������� � ���
void upload_all_stores(std::vector<std::string>& all_name_stores, std::vector<int>& all_coef_stores, std::string file_name);

// �������� ����� ������� � ��� ����������� �������� � ����������
void new_store(std::vector<std::string>& all_name_stores, std::vector<int>& all_coef_stores);