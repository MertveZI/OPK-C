/*  Курс ОПК ФФ, 3 семестр, 2025г.
    Задача № 6330 "Сортировка вставками"
    Стерлягов Сергей, гр. 24310*/
#include <stdio.h>

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

/** <p>Сортирует массив методом вставок.</p>
  * 
  * @param array массив, который необходимо отсортировать
  * @param size размер массива
  */
void insertion_sort(int array[], int size) {
    if (size > 1) {
        for(int i = 1; i < size; i++) {
            for(int j = i; j > 0 && array[j - 1] > array[j]; j--) {
                swap(&array[j - 1], &array[j]); // Передаем указатели
            }
        }
    }
}

/** <p>Выводит массив на экран.</p>
  * 
  * @param array массив для вывода
  * @param size размер массива
  */
void print_array(int array[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(void) {
    unsigned int size = 0;
    printf("Задача №6330 'Сортировка вставками'\n");
    printf("Введите размер массива: ");
    scanf_s("%d", &size);
    
    if (size <= 0) {
        printf("Ошибка: размер массива должен быть положительным числом.\n");
        printf("Нажмите Enter для выхода...");
        getchar();
        getchar();
        return 1;
    }
    
    int array[size];
    
    printf("Введите %d чисел через пробел: ", size);
    for(int i = 0; i < size; i++) {
        scanf_s("%d", &array[i]);
    }
    
    printf("Исходный массив: ");
    print_array(array, size);
    
    insertion_sort(array, size);
    
    printf("Отсортированный массив: ");
    print_array(array, size);

    printf("Нажмите Enter для выхода...");
    getchar();
    getchar();
    
    return 0;
}