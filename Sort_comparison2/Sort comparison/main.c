/*  Курс ОПК ФФ, 3 семестр, 2025г.
    Задание № 6352 "Сравнение сортировок"
    Стерлягов Сергей, гр. 24310*/

#include "heap_sort.h"
#include "bubble_sort.h"
#include "insertion_sort.h"
#include "get_time.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Задача №6352 'Сравнение сортировок'\n");
    printf("Размер\tПузырьковая\tВставками\tПирамидальная\n");

    for(unsigned int i = 100; i < 500000; i = i * 2) {
        unsigned int size = i;
        int *array = (int*)malloc(size * sizeof(int));
        int *uns_array = (int*)malloc(size * sizeof(int));

        if(array == NULL || uns_array == NULL) {
            printf("Ошибка выделения памяти!\n");
            return 1;
        }

        // Заполняем массив случайными числами
        for(unsigned int j = 0; j < size; j++) {
            array[j] = rand() % 1000;
        }

        // Тестируем пузырьковую сортировку
        memcpy(uns_array, array, size * sizeof(int));
        unsigned int bub_time = get_time(bubble_sort, uns_array, size);

        // Тестируем сортировку вставками
        memcpy(uns_array, array, size * sizeof(int));
        unsigned int ins_time = get_time(insertion_sort, uns_array, size);

        // Тестируем пирамидальную сортировку
        memcpy(uns_array, array, size * sizeof(int));
        unsigned int heap_time = get_time(heap_sort, uns_array, size);

        printf("%u\t%u ms\t\t%u ms\t\t%u ms\n", size, bub_time, ins_time, heap_time);

        free(uns_array);
        free(array);
    }

    printf("\nНажмите Enter для выхода...");
    getchar();
    return 0;
}
