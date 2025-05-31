#pragma once

template <class T>
struct stack
{
	struct Node
	{
		T info;
		Node* next = nullptr;
	};

	// ������� �����
	Node* stackTop = nullptr;

	// ����������� ����� �� ���������
	stack() = default;

	// ����������
	~stack()
	{
		while (stackTop != nullptr)
		{
			pop();
		}
	}

	// �������� ��������� �����������
	stack(const stack&) = delete; 

	// �������� ��������� ������������
	stack& operator=(const stack&) = delete;

	// �������� ������� � ����
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

	// ������� ������� �� �����
	void pop()
	{
		if (stackTop)
		{
			Node* temp = stackTop->next;
			delete stackTop;
			stackTop = temp;
		}
	}

	// �������� ������ �� �������
	T top()
	{
		return stackTop->info;
	}

	// �������� ������ �� ������� � ����� �������
	T top_pop()
	{
		T data = top();
		pop();
		return data;
	}

	// ���� ���� -> true, �������� -> false
	bool empty()
	{
		if (stackTop == nullptr) return true;
		else return false;
	}
};