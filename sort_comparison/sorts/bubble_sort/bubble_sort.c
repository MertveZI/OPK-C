/*  Курс ОПК ФФ, 3 семестр, 2025г.
    Задача № 6330 "Сортировка пузырьком"
    Стерлягов Сергей, гр. 24310*/
#include "bubble_sort.h"
#include "C:\Users\mdrn\Documents\GitHub\OPK-C\sort_comparison\swap.h"
#include <stdio.h>

/** <p>Сортирует массив пузырьком.</p>
  * 
  * @param array указатель на массив, который необходимо отсортировать
  * @param size количество элементов в массиве
  */
void bubble_sort(int* array,unsigned int size) {
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(array[j] > array[j+1]){
                swap(&array[j], &array[j+1]);
            }
        }
    }
}