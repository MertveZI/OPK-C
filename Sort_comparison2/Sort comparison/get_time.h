#pragma once

/*  Курс ОПК ФФ, 3 семестр, 2025г.
    Задание № 6352 "Сравнение сортировок"
    Стерлягов Сергей, гр. 24310*/

/** <p>Возвращает время сортировки массива.</p>
 * 
 * @param sort функция сортировки
 * @param array массив для сортировки
 * @param size размер массива
 * @return время выполнения в мс
 */
unsigned int get_time(void (*sort)(int*, unsigned int), int* array, unsigned int size);