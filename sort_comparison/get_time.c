/*  Курс ОПК ФФ, 3 семестр, 2025г.
    Задание № 6352 "Сравнение сортировок"
    Стерлягов Сергей, гр. 24310*/

#include "get_time.h"
#include "sorts/heap_sort/heap_sort.h"
#include "sorts/bubble_sort/bubble_sort.h"
#include "sorts/insertion_sort/insertion_sort.h"

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/** <p>Возвращает время сортировки массива.</p>
  * 
  * @param sort функция сортировки
  * @param array массив для сортировки
  * @param size размер массива
  * @return время выполнения в мс
  */
unsigned int get_time(void (*sort)(int*, unsigned int), int* array, unsigned int size) {
  LARGE_INTEGER start_time, end_time, frequency;
  double elapsed_ms;
  QueryPerformanceFrequency(&frequency); // Получаем частоту производительности
  QueryPerformanceCounter(&start_time); // Время начала
  sort(array, size);
  QueryPerformanceCounter(&end_time); // Время конца
  elapsed_ms = (double)(end_time.QuadPart - start_time.QuadPart) * 1000.0 / frequency.QuadPart;
  return (unsigned int)elapsed_ms;
}