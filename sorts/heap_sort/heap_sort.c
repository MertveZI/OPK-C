/*  Курс ОПК ФФ, 3 семестр, 2025г.
    Задача № 6340 "Пирамидальная сортировка"
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

/** <p>Выводит массив на экран.</p>
  * 
  * @param array массив для вывода
  * @param size размер массива
  */
void print_array(int array[],  int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

/** <pПреобразует в двоичную кучу поддерева(max_heap).</p>
  * 
  * @param array массив для
  * @param size длина массива 
  * @param i индекс корня
  */
void heapify(int arr[], unsigned int size, unsigned int i)
{
    unsigned int largest = i;   
    // Инициализируем наибольший элемент как корень
    int l = 2*i + 1; // левый = 2*i + 1
    int r = 2*i + 2; // правый = 2*i + 2

    // Если левый дочерний элемент больше корня
    if (l < size && arr[l] > arr[largest])
        largest = l;

    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (r < size && arr[r] > arr[largest])
        largest = r;

    // Если самый большой элемент не корень
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);

// Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        heapify(arr, size, largest);
    }
}

/** <p>Сортирует массив пирамидальной сортировкой.</p>
  * 
  * @param array массив, который необходимо отсортировать
  * @param size размер массива
  */
void heap_sort(int array[], unsigned int size)
{
  // Построение кучи
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i);

   // Один за другим извлекаем элементы из кучи
    for (int i=size-1; i>=0; i--)
    {
        // Перемещаем текущий корень в конец
        swap(&array[0], &array[i]);

        // вызываем процедуру heapify на уменьшенной куче
        heapify(array, i, 0);
    }
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
    
    heap_sort(array, size);
    
    printf("Отсортированный массив: ");
    print_array(array, size);

    free(array);
    
    printf("Нажмите Enter для выхода...");
    getchar();
    getchar();
    
    return 0;
}