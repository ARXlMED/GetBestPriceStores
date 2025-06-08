#include "hash.h"

// Функция вычисления MD-5 хеша для строки
unsigned int gethash(std::string text)
{
    unsigned int A = 0x67452301;
    unsigned int B = 0xefcdab89;
    unsigned int C = 0x98badcfe;
    unsigned int D = 0x10325476;

    for (char c : text) {
        unsigned int tempA = A;
        A = ((tempA ^ c) << 3 | (tempA ^ c) >> (32 - 3)) + B;
        unsigned int tempB = B;
        B = ((tempB ^ c) << 5 | (tempB ^ c) >> (32 - 5)) + C;
        unsigned int tempC = C;
        C = ((tempC ^ c) << 7 | (tempC ^ c) >> (32 - 7)) + D;
        unsigned int tempD = D;
        D = ((tempD ^ c) << 11 | (tempD ^ c) >> (32 - 11)) + A;
    }

    return (A ^ B) + (C ^ D);
}

// В зависимости от размера массива получает место в массиве куда нужно загрузить хеш или какие то другие данные чтобы через хеш таблицу к ним можно было потом обратится 
unsigned int getindex(unsigned int hash, int lenmassive)
{
	return hash % lenmassive;
}
