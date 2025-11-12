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
    printf("Введите размер массива(больше 0): ");
    scanf("%d", &size);
    
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