#pragma once
#include <iostream>

template <class T>
struct list
{
	struct part_list
	{
		T data{};
		part_list* ptr = nullptr;
		part_list* ptr_back = nullptr;
	};

	part_list* begin = nullptr;
	part_list* end = nullptr;
	
	// ����������� �����������
	list() = default;

	// ���������� ��� ��������� ������ ������
	~list() 
	{
		part_list* current = begin;
		while (current != nullptr) 
		{
			part_list* next = current->ptr;
			delete current;
			current = next;
		}
		begin = end = nullptr;
	}

	// ���������� �����������
	list(const list&) = delete;

	// �������� ������������
	list& operator=(const list&) = delete;

	// ��������� ������� � ������ ������
	void push_begin(T value)
	{
		if (begin == nullptr)
		{
			begin = new part_list();
			end = begin;
			begin->data = value;
		}
		else
		{
			part_list* temp = begin;
			begin = new part_list();
			begin->data = value;
			begin->ptr = temp;
			temp->ptr_back = begin;
		}
	}

	// ��������� ������� � ����� ������
	void push_back(T value)
	{
		if (begin == nullptr)
		{
			begin = new part_list();
			end = begin;
			end->data = value;
		}
		else
		{
			part_list* temp = end;
			end = new part_list();
			end->data = value;
			temp->ptr = end;
			end->ptr_back = temp;
		}
	}

	// ������� ������� � ������ ������
	void pop_begin()
	{
		part_list* temp = begin;
		begin = begin->ptr;
		delete temp;
	}

	// ������� ������� � ����� ������
	void pop_end()
	{
		part_list* temp = end;
		end = end->ptr_back;
		delete temp;
	}

	// ���������� ������ ������
	int get_size()
	{
		if (begin == nullptr)
			return 0;
		if (begin != nullptr && begin->ptr == nullptr)
			return 1;

		int size = 1;
		part_list* temp = begin;

		while (temp->ptr != nullptr)
		{
			temp = temp->ptr;
			size++;
		}
		return size;
	}

	// ������ � ���������� [] (����������� ��������� � ������������ ���������)
	T operator[](int input)
	{
		if (input < 0 || input >= get_size())
		{
			throw std::out_of_range("������ ������� �� ������� ������");
		}
		part_list* temp = begin;
		for (int i = 0; i < input; i++)
		{
			temp = temp->ptr;
		}
		return temp->data;
	}

	// ������� ��� ������ ������
	void print()
	{
		part_list* temp = begin;
		if (temp == nullptr)
		{
			std::cout << "������ ����";
		}
		else
		{
			while (temp != nullptr)
			{
				std::cout << temp->data << " ";
				temp = temp->ptr;
			}
			std::cout << "\n";
		}
	}
};