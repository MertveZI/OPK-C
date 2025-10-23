/*  Курс ОПК ФФ, 3 семестр, 2025г.
    Задача №2 "Существование треугольника"
    Стерлягов Сергей, гр. 24310*/
#include <stdio.h>
#include <stdbool.h>
#include <math.h>


/** <p>Вычисляет число Фибоначчи по заданному номеру.</p>
  * 
  * @param n номер числа Фибоначчи
  * @return n-ное число Фибоначчи
  */
unsigned int generate_n_fib(unsigned int n) {
    if (n == 1 || n == 2){
        return 1;
    }
    else{ 
        unsigned int f1 = 1;
        unsigned int f2 = 1;
        unsigned int i = 0;
        unsigned int fib_sum = 0;
        n = n - 2;
        while(i < n){
            fib_sum = f1 + f2;
            f1 = f2;
            f2 = fib_sum;
            i = i + 1;
        }
        return f2;
    }
}

int main(void) {
    unsigned int n = 0;
    printf("Задача №6246 'Числа Фибоначчи'\n");
    printf("Введите номер числа Фибоначчи(больше 0): ");
    scanf_s("%u", &n);
    unsigned int n_fib = generate_n_fib(n);
    printf("Число Фибоначчи под номером %u равно %u \n", n, n_fib);
    
    printf("\nНажмите Enter для выхода...");
    getchar();
    getchar();  

    return 0;
}