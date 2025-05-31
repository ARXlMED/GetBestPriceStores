#pragma once

template <class T>
struct stack
{
	struct Node
	{
		T info;
		Node* next = nullptr;
	};

	// Вершина стека
	Node* stackTop = nullptr;

	// Конструктор стека по умолчанию
	stack() = default;

	// Деструктор
	~stack()
	{
		while (stackTop != nullptr)
		{
			pop();
		}
	}

	// Удаление оператора копирования
	stack(const stack&) = delete; 

	// Удаление оператора присваивания
	stack& operator=(const stack&) = delete;

	// Добавить элемент в стек
	void push(T info)
	{
		if (stackTop == nullptr)
		{
			stackTop = new Node();
			stackTop->info = info;
		}
		else
		{
			Node* temp = stackTop;
			stackTop = new Node();
			stackTop->info = info;
			stackTop->next = temp;
		}
	}

	// Удалить элемент из стека
	void pop()
	{
		if (stackTop)
		{
			Node* temp = stackTop->next;
			delete stackTop;
			stackTop = temp;
		}
	}

	// Получить данные из вершины
	T top()
	{
		return stackTop->info;
	}

	// Получить данные из вершины и потом удалить
	T top_pop()
	{
		T data = top();
		pop();
		return data;
	}

	// Если пуст -> true, заполнен -> false
	bool empty()
	{
		if (stackTop == nullptr) return true;
		else return false;
	}
};