/*  Курс ОПК ФФ, 3 семестр, 2025г.
    Задача №6253 "Вклад в банке"
    Стерлягов Сергей, гр. 24310*/
#include <stdio.h>
#include <math.h>

/**
  * <p>Вычисляет баланс к концу вклада.</p>
  * 
  * @param start_balance стартовый баланс на вкладе
  * @param period период вклада в месяцах
  * @param percent годовая процентная ставка
  * @return конечный баланс на вкладе
  */
double deposit_balance(double start_balance, unsigned short period, double percent) {
    unsigned short month_in_year = 12;
    unsigned short base = 100;
    double monthly_rate = percent / month_in_year / base;  // Рассчет месячной ставки в долях
    return start_balance * pow(1 + monthly_rate, period);
}

int main(void) {
    double start_balance = 0;
    unsigned short period = 0;
    double percent = 0;

    printf("Задача №6253 'Вклад в банке'\n");
    
    printf("Введите стартовый баланс: ");
    if (scanf_s("%lf", &start_balance) != 1 || start_balance <= 0) {
        printf("Ошибка: введите положительное число для баланса!\n");
        return 1;
    }
    
    printf("Введите длительность вклада в месяцах (целое число): ");
    if (scanf_s("%hu", &period) != 1 || period == 0) {
        printf("Ошибка: введите положительное целое число для периода!\n");
        return 1;
    }
    
    printf("Введите годовую процентную ставку: ");
    if (scanf_s("%lf", &percent) != 1 || percent < 0) {
        printf("Ошибка: введите неотрицательное число для процента!\n");
        return 1;
    }
    
    double end_balance = deposit_balance(start_balance, period, percent);
    
    printf("\n--- Результаты расчета ---\n");
    printf("Начальный баланс: %.2lf руб.\n", start_balance);
    printf("Период вклада: %hu месяцев\n", period);
    printf("Годовая ставка: %.2lf%%\n", percent);
    printf("Конечный баланс: %.2lf руб.\n", end_balance);
    printf("Доход: %.2lf руб.\n", end_balance - start_balance);
    
    printf("\nНажмите Enter для выхода...");
    getchar();
    getchar();  
    
    return 0;
}