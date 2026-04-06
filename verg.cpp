#include <iostream>
#include  <math.h>
#include <cmath>
#include <clocale>

int main() {
	setlocale(LC_ALL, "Russian");
	/*double x = 27.0 / 31.0;
	double a2 = 0.871;

	double absolute = std::abs(x - a2);

	std::cout << "Абсолютная погрешность = " << absolute << std::endl;

	double relative = absolute / std::abs(a2);

	std::cout << "Относительная погрешность = " << relative << std::endl;


	double x1 = sqrt(42);
	double a1 = 6.48;

	double absolute1 = std::abs(x1 - a1);

	std::cout << "Абсолютная погрешность = " << absolute1 << std::endl;

	double relative1 = absolute1 / std::abs(a1);

	std::cout << "Относительная погрешность = " << relative1 << std::endl;

	if (relative > relative1) {
		std::cout << "Первое выражение точнее" << std::endl;
	}
	else if (relative < relative1) {
		std::cout << "Второе выражение точнее" << std::endl;
	}


	double number = 0.088748;
	double rel_perc = 0.56;

	double rel_error = rel_perc / 100.0;

	double abs_err = number * rel_error;

	std::cout <<"абсолютная погрешность: "<< abs_err << std::endl;

	double rounded = std::round(number * 10) / 10.0;

	std::cout << "Округленное число = " << rounded << std::endl;

	double res = 0.5 * 0.1;

	std::cout << "Погрешность результата = " << res<<std::endl;

	double pred_abs =  0.01;

	std::cout << "Пределельная абсолютная погрешность = " << pred_abs<<std::endl;

	double pred_rel = pred_abs / std::abs(7.38);

	std::cout << "Предельная относительная погрешность = " << pred_rel << std::endl;*/


	double a = 1.24734;
	double b = 0.346;
	double c = 0.051;

	double Abs_ErrA = 0.00001;
	std::cout << "Абсолютная погрешность а: " << Abs_ErrA << std::endl;

	double Abs_ErrB = 0.001;
	std::cout << "Абсолютная погрешность b: " << Abs_ErrB << std::endl;

	double Abs_ErrC = 0.001;
	std::cout << "Абсолютная погрешность c: " << Abs_ErrC << std::endl;

	double Rel_ErrA = Abs_ErrA / std::abs(a);
	std::cout << "Относительная погрешность а = " << Rel_ErrA << std::endl;

	double Rel_ErrB = Abs_ErrB / std::abs(b);
	std::cout << "Относительная погрешность b = " << Rel_ErrB << std::endl;

	double Rel_ErrC = Abs_ErrC / std::abs(c);
	std::cout << "Относительная погрешность c = " << Rel_ErrC << std::endl;

	std::cout << std::endl;

	double n1 = sqrt(b);
	std::cout << "Первое действие = " << n1 << std::endl;
	double Rel_ErrN1 = 0.5 * Rel_ErrB;
	std::cout << "Относительная погрешность корня b = " << Rel_ErrN1 << std::endl;
	double Abs_ErrN1 = Rel_ErrN1 * std::abs(sqrt(b));
	std::cout << "Абсолютная погрешность корня b = " << Abs_ErrN1 << std::endl;

	std::cout << std::endl;

	double n2 = a * a;
	std::cout << "Второе действие = " << n2 << std::endl;
	double Rel_ErrN2 = 0.5 * Rel_ErrA;
	std::cout << "Относительная погрешность a = " << Rel_ErrN2 << std::endl;
	double Abs_ErrN2 = Rel_ErrN2 * std::abs(a * a);
	std::cout << "Абсолютная погрешность a = " << Abs_ErrN2 << std::endl;

	std::cout << std::endl;

	double n3 = 10 * c;
	std::cout << "Третье действие = " << n3 << std::endl;

	std::cout << std::endl;

	double n4 = n3 + n1;
	std::cout << "Четвертое действие = " << n4 << std::endl;
	double Abs_ErrN4 = Abs_ErrC + Abs_ErrN1;
	std::cout << "Погрешность суммы c и b = " << Abs_ErrN4 << std::endl;
	double Rel_ErrN4 =  Abs_ErrN4 / std:: abs(n4);
	std::cout << "Относительная погрешность погрешностей суммы = " << Rel_ErrN4 << std::endl;

	std::cout << std::endl;

	double n5 = n2 - b;
	std::cout << "Пятое действие = " << n5 << std::endl;
	double Abs_ErrN5 = Abs_ErrN2 + Abs_ErrB;
	std::cout << "Погрешность разности a и b = " << Abs_ErrN5 << std::endl;
	double Rel_ErrN5 = Abs_ErrN5 / std::abs(n5);
	std::cout << "Относительная погрешность погрешностей разности = " << Rel_ErrN5 << std::endl;

	double n6 = n4 / n5;
	std::cout << "Шестое действие = " << n6 << std::endl;
	double Rel_ErrN6 = Rel_ErrN4 + Rel_ErrN5;
	std::cout << "Относительная погрешность частного = " << Rel_ErrN6 << std::endl;
	double Abs_ErrN6 = Rel_ErrN6 * std::abs(n6);
	std::cout << "Абсолютная погрешность частного = " << Rel_ErrN6 << std::endl;
	std::cout << std::endl;

	return 0;
}
