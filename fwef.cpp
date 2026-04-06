#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdio.h>
//Задание 1
//// Функция f(x) = x^4 - x - 1
//double f(double x) {
//    return std::pow(x, 4) - std::pow(x, 1) - 1;
//}
//
//// Реализация метода дихотомии
//double bisection(double a, double b, double eps) {
//    double c;
//    while ((b - a) / 2.0 > eps) {
//        c = (a + b) / 2.0;
//
//        // Если f(c) и f(a) разных знаков, корень в левой половине
//        if (f(a) * f(c) < 0) {
//            b = c;
//        }
//        else {
//            a = c;
//        }
//    }
//    return (a + b) / 2.0;
//}
//
//int main() {
//    char* locale = setlocale(LC_ALL, "");
//    double eps = 0.001; // Точность
//
//    // Известные отрезки локализации
//    double a1 = -3.0, b1 = -2.0;
//    double a2 = 0.0, b2 = 1.0;
//
//    std::cout << std::fixed << std::setprecision(4);
//
//    std::cout << "Корень на отрезке [" << a1 << ", " << b1 << "]: "
//        << bisection(a1, b1, eps) << std::endl;
//
//    std::cout << "Корень на отрезке [" << a2 << ", " << b2 << "]: "
//        << bisection(a2, b2, eps) << std::endl;
//
//    return 0;
//}

//Задание 2
// Исходная функция для метода дихотомии
double f(double x) {
    return log(x) + 2 * x^2 - 6;
}

// Преобразованная функция x = phi(x) для метода итераций
// phi(x) = 1.5 - ln(x)
double phi(double x) {
    return 1.5 - log(x);
}

double bisection(double a, double b, double eps) {
    double c;
    while ((b - a) / 2.0 > eps) {
        c = (a + b) / 2.0;
        if (f(a) * f(c) < 0) b = c;
        else a = c;
    }
    return (a + b) / 2.0;
}

int main() {
    setlocale(LC_ALL, "");

    // 1. Метод дихотомии
    double eps_bis = 0.001;
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Метод дихотомии: " << bisection(1.0, 2.0, eps_bis) << "\n\n";

    // 2. Метод простой итерации (исправленный)
    double x0 = 1.5;
    double epsilon = 0.000001;
    double x_next;
    int step = 0;

    std::cout << "Метод итераций (x = 1.5 - ln(x)):\n";
    std::cout << "Step\tValue\n";

    while (true) {
        // Теперь используем phi(x), где производная < 1
        x_next = phi(x0);
        step++;

        std::cout << step << "\t" << std::setprecision(6) << x_next << "\n";

        if (std::abs(x_next - x0) < epsilon) {
            break;
        }

        x0 = x_next;

        if (step > 100) { // Увеличим лимит, так как сходимость может быть плавной
            std::cout << "Метод не сходится\n";
            return 1;
        }
    }

    std::cout << "\nИтоговый корень: " << x_next << "\n";

    return 0;
}
