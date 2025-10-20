/*  Курс ОПК ФФ, 3 семестр, 2025г.
    Задача № 6330 "Сортировка вставками"
    Стерлягов Сергей, гр. 24310*/
#include <stdio.h>
#include <stdlib.h>

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
                swap(&array[j - 1], &array[j]);
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
    int *array = NULL;
    
    printf("Задача №6330 'Сортировка вставками'\n");
    printf("Введите размер массива: ");
    scanf("%d", &size);
    
    if (size <= 0) {
        printf("Ошибка: размер массива должен быть положительным числом.\n");
        printf("Нажмите Enter для выхода...");
        getchar();
        getchar();
        return 1;
    }
    
    // Выделяем память для динамического массива
    array = (int*)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Ошибка выделения памяти!\n");
        printf("Нажмите Enter для выхода...");
        getchar();
        getchar();
        return 1;
    }
    
    printf("Введите %d чисел через пробел: ", size);
    for(int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    
    printf("Исходный массив: ");
    print_array(array, size);
    
    insertion_sort(array, size);
    
    printf("Отсортированный массив: ");
    print_array(array, size);

    free(array);
    
    printf("Нажмите Enter для выхода...");
    getchar();
    getchar();
    
    return 0;
}