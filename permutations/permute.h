/** <p>Рекурсивная функция для генерации перестановок.</p>
  * 
  * @param array исходный массив
  * @param start_id начальный индекс для рекурсии
  * @param end_id конечный индекс для рекурсии
  * @param result массив для сохранения перестановок
  * @param count указатель на счетчик перестановок
  */
void permute(int **result, int *array, int *count, int start_id, int end_id);