#pragma once
#include <string>
#include <vector>
#include "List.h"

// ������� ���������� MD-5 ���� ��� ������
unsigned int gethash(std::string text);

// � ����������� �� ������� ������� �������� ����� � ������� ���� ����� ��������� ��� ��� ����� �� ������ ������ ����� ����� ��� ������� � ��� ����� ���� ����� ��������� 
unsigned int getindex(unsigned int hash, int lenmassive);
