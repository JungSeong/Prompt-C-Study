#include <stdio.h>

double add(double, double);
double sub(double, double);
double mul(double, double);
double div(double, double);
double calculator(double , double, double (*func)(double, double));

int main(void)
{
	double (*calc)(double, double) = NULL;	// 함수 포인터 선언 
	double result = 0;
	
	double num01 = 3, num02 = 5;
	char oper = '*';

    // 함수의 이름은 그 자체로 함수의 시작 주소를 가르키는 상수 값이다.
    // 따라서 calc = add를 하면, 함수 포인터 calc가 add라는 이름의 함수의 주소를 가르킬 수 있게 된다.

	switch (oper)
	{
		case '+':
			calc = add;
			break;
		case '-':
			calc = sub;
			break;
		case '*':
			calc = mul;
			break;
		case '/':
			calc = div;
			break;
		default:
			puts("사칙연산(+, -, *, /)만을 지원합니다.");
	}

    printf("add, sub, mul, div의 주소 : %p %p %p %p\n", add, sub, mul, div);

	result = calculator(num01, num02, calc);
	printf("사칙 연산의 결과는 %lf입니다.\n", result);
	return 0;
}

double add(double num01, double num02)
{
	return num01 + num02;
}

double sub(double num01, double num02)
{
	return num01 - num02;
}

double mul(double num01, double num02)
{
	return num01 * num02;
}

double div(double num01, double num02)
{
	return num01 / num02;
}

double calculator(double num01, double num02, double (*func)(double, double))
{
	return func(num01, num02);
}