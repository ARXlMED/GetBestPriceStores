#pragma once
#include <string>
#include <vector>
#include "List.h"

// ������� ���������� FNV-1a ���� ��� ������
unsigned int gethash(std::string text);

// � ����������� �� ������� ������� �������� ����� � ������� ���� ����� ��������� ��� ��� ����� �� ������ ������ ����� ����� ��� ������� � ��� ����� ���� ����� ��������� 
unsigned int getindex(unsigned int hash, int lenmassive);
