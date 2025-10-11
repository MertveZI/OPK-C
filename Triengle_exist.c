/*  Курс ОПК ФФ, 3 семестр, 2025г.
    Задача №2 "Существование треугольника"
    Стерлягов Сергей, гр. 24310*/
#include <stdio.h>
#include <stdbool.h>
#include <math.h>


/** <p>Проверяет, существует ли треугольник со сторонами a, b, c.</p>
  * 
  * @param a сторона a треугольника
  * @param b сторона b треугольника
  * @param c сторона c треугольника
  * @return true, если существует, false, если нет
  */
bool is_exist(unsigned int a, unsigned int b, unsigned int c) {
    if (a + b <= c || a + c <= b || b + c <= a || a == 0 || b == 0 || c == 0){
        return false;
    }
    else{
        return true;
    }
}

/** <p>Проверяет, равнобедренный ли треугольник со сторонами a, b, c.</p>
  * 
  * @param a сторона a треугольника
  * @param b сторона b треугольника
  * @param c сторона c треугольника
  * @return true, если равнобедренный, false, если нет
  */
bool is_isosceles(unsigned int a, unsigned int b, unsigned int c) {
    if (a == b || a == c || b == c){
        return true;
    }
    else{
        return false;
    }
}

/** <p>Проверяет, равносторонний ли треугольник со сторонами a, b, c.</p>
  * 
  * @param a сторона a треугольника
  * @param b сторона b треугольника
  * @param c сторона c треугольника
  * @return true, если равностороний, false, если нет
  */
bool is_iequilateral(unsigned int a, unsigned int b, unsigned int c) {
    if (a == b && b == c){
        return true;
    }
    else{
        return false;
    }
}

/** <p>Проверяет, равносторонний ли треугольник со сторонами a, b, c.</p>
  * 
  * @param a сторона a треугольника
  * @param b сторона b треугольника
  * @param c сторона c треугольника
  * @return true, если равностороний, false, если нет
  */
float tri_area(unsigned int a, unsigned int b, unsigned int c) {
    float p = (a + b + c) / 2;
    float S = sqrt(p * (p - a) * (p - b) * (p - c));
    return S;
}

int main(void) {
    unsigned int a, b, c = 0;
    printf("Задача №2 'Существование треугольника'\n");
    printf("Введите сторону треугольника a: ");
    scanf_s("%u", &a);
    printf("Введите сторону треугольника b: ");
    scanf_s("%u", &b); 
    printf("Введите сторону треугольника c: ");
    scanf_s("%u", &c);  
    
    if (is_exist(a, b, c) == true){
        float area = tri_area(a,b,c);
        unsigned int perimeter = a + b + c;
        if (is_isosceles(a, b, c) == true){
            printf("Треугольник равнобедренный \n");
        }
        if (is_iequilateral(a, b, c) == true){
            printf("Треугольник равносторонний \n");
        }
        printf("Периметр треугольника: %u \n", perimeter);
        printf("Площадь треугольника: %f \n", area);
    }
    else{
        printf("Треугольника не существует!!");
    }
    char ch;
    printf("Нажмите любую кнопку для продолжения...    ");
    scanf("%c",&ch);
    
    return 0;
}