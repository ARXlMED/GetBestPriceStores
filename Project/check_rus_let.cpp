#include "check_rus_let.h"

// Проверка есть ли русские буквы в введённой строке true - да, false - нет.
bool check_rus_let(std::string answer)
{
	for (int i = 0; i < answer.length(); i++)
	{
		if (answer[i] < 0)
		{
			return true;
		}
	}
	return false;
}