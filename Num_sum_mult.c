/*  Курс ОПК ФФ, 3 семестр, 2025г.
    Задача №1 "Сумма и произведение цифр числа"
    Стерлягов Сергей, гр. 24310*/
#include <stdio.h>

/**
  * <p>Вычисляет сумму цифр числа.</p>
  * 
  * @param num число, сумму цифр которого необходимо найти
  * @return сумма цифр числа
  */
unsigned int digit_sum(unsigned int num) {
    unsigned int sum = 0;
    unsigned int temp = num;
    
    if (temp == 0) {
        return 0;  // сумма цифр числа 0 равна 0
    }
    
    while (temp > 0) {
        sum += temp % 10;  // добавляем последнюю цифру
        temp /= 10;        // убираем последнюю цифру
    }
    return sum;
}

/**
  * <p>Вычисляет произведение цифр числа.</p>
  * 
  * @param num число, произведение цифр которого необходимо найти
  * @return произведение цифр числа
  */
unsigned int digit_mult(unsigned int num) {
    unsigned int mult = 1;  
    unsigned int temp = num;
    
    if (temp == 0) {
        return 0;  // произведение цифр числа 0 равно 0
    }
    
    while (temp > 0) {
        mult *= temp % 10;  // умножаем на последнюю цифру
        temp /= 10;         // убираем последнюю цифру
    }
    return mult;
}

int main(void) {
    unsigned int num = 0;
    
    printf("Задача №1 'Сумма и произведение цифр числа'\n");
    printf("Введите целое положительное число, не превышающее 4 294 967 295: ");
    scanf_s("%u", &num);  
    
    unsigned int sum = digit_sum(num);
    unsigned int product = digit_mult(num);
    
    printf("Введенное число: %u\n", num);
    printf("Сумма цифр: %u\n", sum);
    printf("Произведение цифр: %u\n", product);
    char ch;
    printf("Нажмите любую кнопку для продолжения...    ");
    scanf("%c",&ch);

    return 0;
}