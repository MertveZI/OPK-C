/*  Курс ОПК ФФ, 3 семестр, 2025г.
    Задача № 6330 "Сортировка вставками"
    Стерлягов Сергей, гр. 24310*/
#include <stdio.h>
#include <stdlib.h>
#include "insertion_sort.h"

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
void insertion_sort(int* array, unsigned int size) {
    if (size > 1) {
        for(unsigned int i = 1; i < size; i++) {
            for(unsigned int j = i; j > 0 && array[j - 1] > array[j]; j--) {
                swap(&array[j - 1], &array[j]);
            }
        }
    }
}