/*  Курс ОПК ФФ, 3 семестр, 2025г.
    Задача №6353 "Поиск подстроки в строке алгоритмом Боуэра-Мура"
    Стерлягов Сергей, гр. 24310*/
#include <stdio.h>
#include <stdbool.h>
#include <math.h>


/** <p>Функция поиска подстроки в строке алгоритмом Боуэра-Мура</p>
  * 
  * @param haystack "стог" -строка, в которой выполняется поиск
  * @param needle "иголка" - подстрока, инддекс вхождения которой выводится
  * @return n-ное число Фибоначчи
  */
char * bm_find(char *haystack, const char *needle) {
    return 0;
}

int main(void) {
    unsigned int n = 0;
    printf("Задача №6353 'Поиск подстроки в строке алгоритмом Боуэра-Мура'\n");
    printf("Введите номер числа Фибоначчи(больше 0): ");
    scanf_s("%u", &n);
    unsigned int n_fib = generate_n_fib(n);
    printf("Число Фибоначчи под номером %u равно %u \n", n, n_fib);
    
    printf("\nНажмите Enter для выхода...");
    getchar();
    getchar();  

    return 0;
}