/*  Курс ОПК ФФ, 3 семестр, 2025г.
    Задача №6260 "Решение квадратного уравнения"
    Стерлягов Сергей, гр. 24310*/
#include <stdio.h>
#include <math.h>

/** <p>Проверяет, существует ли треугольник со сторонами a, b, c.</p>
  * 
  * @param a коэффициент перед x^2
  * @param b коэффициент перед x
  * @param c константа
  * @param result массив, где первый номер- количество корней, а остальные - это корни
  */
void solveQuadraticParam(double a, double b, double c, double result[]) {
    double discriminant = b * b - 4 * a * c;
    
    if(discriminant > 0) {
        result[0] = 2;
        result[1] = (-b + sqrt(discriminant)) / (2 * a);
        result[2] = (-b - sqrt(discriminant)) / (2 * a);
    }
    else if(discriminant == 0) {
        result[0] = 1;
        result[1] = -b / (2 * a);
        result[2] = result[1];
    }
    else {
        result[0] = 0;
        result[1] = 0;
        result[2] = 0;
    }
}

int main() {
    double a, b, c;
    double roots[3]; 
    printf("Задача №6260 'Решение квадратного уравнения'\n");
    printf("Введите коэффициенты уравнения ax² + bx + c = 0\n");
    printf("Введите коэффициент a: ");
    scanf("%lf", &a);
    printf("Введите коэффициент b: ");
    scanf("%lf", &b);
    printf("Введите коэффициент c: ");
    scanf("%lf", &c);
    
    if(a == 0) {
        if (b == 0 && c != 0){
            printf("Действительных корней нет\n");
        }
        else{
            double roots[2] = {1, -a / b};
        }
    }
    else{
        solveQuadraticParam(a, b, c, roots);
    }

    int numRoots = (int)roots[0];
    if(numRoots == 2) {
        printf("Два корня: x1 = %.2f, x2 = %.2f\n", roots[1], roots[2]);
    } else if(numRoots == 1) {
        printf("Один корень: x = %.2f\n", roots[1]);
    } else {
        printf("Действительных корней нет\n");
    }
    
    printf("\nНажмите Enter для выхода...");
    getchar();
    getchar(); 

    return 0;
}