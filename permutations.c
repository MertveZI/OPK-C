/*  Курс ОПК ФФ, 3 семестр, 2025г.
    Задача № 6331 "Все перестановки"
    Стерлягов Сергей, гр. 24310*/
#include <stdio.h>
#include <stdbool.h>
#include <math.h>


/** <p>Меняет элементы a и b местами.</p>
  * 
  * @param a указатель на элемент a
  * @param b указатель на элемент b
  */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/** <p>Выводит все возможные перестановки.</p>
  * 
  * @param n количество элементов массива
  * @return массив, размером n! с массивами всех возможных перестановок и 
  */
void permute(char *a, int start_id, int end_id) 
{ 
    int i; 
    if (start_id == end_id) 
        printf("%s\n", a); 
    else
    { 
        for (i = start_id; i <= end_id; i++) 
        { 
            swap((a + start_id), (a + i)); 
            permute(a, start_id + 1, end_id); 

            //backtrack 
            swap((a + start_id), (a + i)); 
        } 
    } 
} 

/** <p>Выводит все возможные перестановки.</p>
  * 
  * @param n количество элементов массива
  * @return массив, размером n! с массивами всех возможных перестановок и 
  */
unsigned int permutations(unsigned int n) {
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
    printf("Чисдло Фибоначчи под номером %u равно %u \n", n, n_fib);
    
    printf("\nНажмите Enter для выхода...");
    getchar();
    getchar();  

    return 0;
}
