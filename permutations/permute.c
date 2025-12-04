#include "permute.h"


/** <p>Рекурсивная функция для генерации перестановок.</p>
  * 
  * @param array исходный массив
  * @param start_id начальный индекс для рекурсии
  * @param end_id конечный индекс для рекурсии
  * @param result массив для сохранения перестановок
  * @param count указатель на счетчик перестановок
  */
void permute(int **result, int *array, int *count, int start_id, int end_id) 
{ 
    if (start_id == end_id) {
        for(int i = 0; i <= end_id; i++) {
            result[*count][i] = array[i];
        }
        (*count)++;
    } else { 
        for (int i = start_id; i <= end_id; i++) { 
            swap(&array[start_id], &array[i]); 
            permute(result, array, count, start_id + 1, end_id); 
            swap(&array[start_id], &array[i]); 
        } 
    } 
} 
