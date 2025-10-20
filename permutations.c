/*  Курс ОПК ФФ, 3 семестр, 2025г.
    Задача № 6331 "Все перестановки"
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

/** <p>Факториал числа n.</p>
  * 
  * @param n число
  * @return n!
  */
unsigned long long factorial(unsigned int n) {
    unsigned long long result = 1;
    for(unsigned int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

/** <p>Рекурсивная функция для генерации перестановок.</p>
  * 
  * @param array исходный массив
  * @param start_id начальный индекс
  * @param end_id конечный индекс
  * @param result массив для сохранения перестановок
  * @param count указатель на счетчик перестановок
  */
void permute(int *array, int start_id, int end_id, int **result, int *count) 
{ 
    if (start_id == end_id) {
        for(int i = 0; i <= end_id; i++) {
            result[*count][i] = array[i];
        }
        (*count)++;
    } else { 
        for (int i = start_id; i <= end_id; i++) { 
            swap(&array[start_id], &array[i]); 
            permute(array, start_id + 1, end_id, result, count); 
            swap(&array[start_id], &array[i]); 
        } 
    } 
} 

/** <p>Генерирует все перестановки чисел от 0 до N-1.</p>
  * 
  * @param n количество элементов
  * @return массив размера n! с перестановками
  */
int** permutations(unsigned int n) {
    if (n == 0) {
        return NULL;
    }
    
    unsigned long long total_permutations = factorial(n);
    
    int **result = (int**)malloc(total_permutations * sizeof(int*));
    if (result == NULL) {
        return NULL;
    }
    
    for(unsigned long long i = 0; i < total_permutations; i++) {
        result[i] = (int*)malloc(n * sizeof(int));
        if (result[i] == NULL) {
            for(unsigned long long j = 0; j < i; j++) {
                free(result[j]);
            }
            free(result);
            return NULL;
        }
    }
    
    int *array = (int*)malloc(n * sizeof(int));
    if (array == NULL) {
        for(unsigned long long i = 0; i < total_permutations; i++) {
            free(result[i]);
        }
        free(result);
        return NULL;
    }

    for (unsigned int i = 0; i < n; i++) {
        array[i] = i;
    }
    
    int count = 0;
    permute(array, 0, n - 1, result, &count);
    
    free(array);
    return result;
}

/** <p>Освобождает память, выделенную под массив перестановок.</p>
  * 
  * @param permutations массив перестановок
  * @param n количество элементов в исходном наборе
  */
void free_permutations(int **permutations, unsigned int n) {
    if (permutations == NULL) return;
    
    unsigned long long total = factorial(n);
    for(unsigned long long i = 0; i < total; i++) {
        free(permutations[i]);
    }
    free(permutations);
}

/** <p>Выводит массив перестановок на экран.</p>
  * 
  * @param permutations массив перестановок
  * @param n количество элементов в исходном наборе
  */
void print_permutations(int **permutations, unsigned int n) {
    if (permutations == NULL) {
        printf("Нет перестановок\n");
        return;
    }
    
    unsigned long long total = factorial(n);
    printf("Все перестановки для n = %u (всего %llu):\n", n, total);
    
    for(unsigned long long i = 0; i < total; i++) {
        printf("[");
        for(unsigned int j = 0; j < n; j++) {
            printf("%d", permutations[i][j]);
            if (j < n - 1) {
                printf(", ");
            }
        }
        printf("]");
        if (i < total - 1) {
            printf(", ");
        }
        printf("\n");
    }
}

int main(void) {
    unsigned int n = 0;
    printf("Задача №6331 'Все перестановки'\n");
    printf("Введите n (количество элементов): ");
    scanf("%u", &n);
    
    if (n > 8) {
        printf("Предупреждение: для n > 8 количество перестановок очень велико!\n");
    }
    
    int **all_permutations = permutations(n);
    
    if (all_permutations != NULL) {
        print_permutations(all_permutations, n);
        free_permutations(all_permutations, n);
    } else {
        printf("Ошибка генерации перестановок\n");
    }
    
    printf("\nНажмите Enter для выхода...");
    getchar();
    getchar();  

    return 0;
}