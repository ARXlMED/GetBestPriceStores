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
	
	// Конструктор стандартный
	list() = default;

	// Деструктор для избежания утечек памяти
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

	// Копирующий конструктор
	list(const list&) = delete;

	// Оператор присваивания
	list& operator=(const list&) = delete;

	// Добавляет элемент в начало списка
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

	// Добавляет элемент в конце списка
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

	// Удаляет элемент с начала списка
	void pop_begin()
	{
		part_list* temp = begin;
		begin = begin->ptr;
		delete temp;
	}

	// Удаляет элемент с конца списка
	void pop_end()
	{
		part_list* temp = end;
		end = end->ptr_back;
		delete temp;
	}

	// Возвращает размер списка
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

	// Работа с оператором [] (возможность обращения к определенным элементам)
	T operator[](int input)
	{
		if (input < 0 || input >= get_size())
		{
			throw std::out_of_range("Индекс выходит за границы списка");
		}
		part_list* temp = begin;
		for (int i = 0; i < input; i++)
		{
			temp = temp->ptr;
		}
		return temp->data;
	}

	// Функция для вывода списка
	void print()
	{
		part_list* temp = begin;
		if (temp == nullptr)
		{
			std::cout << "Список пуст";
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