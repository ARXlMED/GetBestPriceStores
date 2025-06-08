#pragma once
#include <string>
#include <vector>
#include "List.h"

// Функция вычисления MD-5 хеша для строки
unsigned int gethash(std::string text);

// В зависимости от размера массива получает место в массиве куда нужно загрузить хеш или какие то другие данные чтобы через хеш таблицу к ним можно было потом обратится 
unsigned int getindex(unsigned int hash, int lenmassive);
