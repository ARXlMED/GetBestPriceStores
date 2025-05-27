#include "hash.h"
// ������� ������������� ������ � ��� ����� �������� �� int
int gethash(std::string password)
{
	int hash = 0;
	for (int i = 0; i < password.length(); i++)
	{
		hash = (hash << 5) - hash + password[i]; // ����� ������ �� 5 ��� � ��������� ������������ ��������� �� 31 (2^5 = 32 - 1 = 31)
	}
	return abs(hash);
}

// � ����������� �� ������� ������� �������� ����� � ������� ���� ����� ��������� ��� ��� ����� �� ������ ������ ����� ����� ��� ������� � ��� ����� ���� ����� ��������� 
int getindex(int hash, int lenmassive)
{
	return hash % lenmassive;
}

// �������� �� ������� ���� (���� �� ������������)
bool presence_in_hashes(std::string answer, std::vector<list<int>> massive_hashes)
{
	int hash = gethash(answer);
	int index = getindex(hash, massive_hashes.size());
	for (int i = 0; i < massive_hashes[index].get_size(); i++)
	{
		if (massive_hashes[index][i] == hash)
		{
			return true;
		}
	}
	return false;
}