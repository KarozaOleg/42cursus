/* пример аргумента переменной длины - сумма последовательности */
#include <stdio.h>
#include <stdarg.h>
double sum_series(int num, ...)
{
	double sum = 0.0, t;
	va_list argptr;

	/* инициализация argptr */
	va_start(argptr, num);

	/* сумма последовательности */
	for (; num; num--)
	{
		t = va_arg(argptr, double);
		sum += t;
	}

	/* завершение */
	va_end(argptr);
	return sum;
}
int main(void)
{
	double d;
	d = sum_series(5, 0.5, 0.25, 0.125, 0.0625, 0.03125);
	printf("Sum of series is %f\n", d);
	return 0;
}

