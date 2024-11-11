#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    int hour, min, num;
    wchar_t letter;
	char str[10];

    wprintf(L"현재 시각은? : ");
    wscanf(L"%d %d", &hour, &min);

    wprintf(L"시/분 중 어떤 것을 입력 받을까요? : ");
    wscanf(L" %lc", &letter);

	if (!(letter == L'시' || letter == L'분'))
	{
		wprintf(L"잘못된 입력입니다.\n");
		exit(0);
	}

	wprintf(L"어떻게 계산할까요? 1. 더하기, 2. 빼기 : ");
	wscanf(L" %s", &str);

	if (strcmp(str, "더하기")!=0 && strcmp(str, "빼기")!=0)
	{
		wprintf(L"잘못된 입력입니다.\n");
		exit(0);
	}

	wprintf(L"자연수를 입력하세요. : ");
	wscanf(L" %d", &num);

	if (num <= 0)
	{
		wprintf(L"잘못된 입력입니다.\n");
		exit(0);
	}

	// 시각 계산
	int calc = hour * 60 + min;
	int hour_result, min_result;

	if (letter == L'시')
	{
		num *= 60;
	}

	if (strcmp(str, "빼기")==0)
	{
		num *= -1;
	}

	calc += num;
	hour_result = calc / 60;
	min_result = calc % 60;

	printf("%d %d", hour_result, min_result);

	if (min_result < 0)
	{
		min_result = 60 + min_result;
		hour_result -= 1;
	}

	if (hour_result < 0)
	{
		while (hour_result < 0)
		{
			hour_result = 24 + hour_result;
		}
	}

	if (hour_result >= 24)
	{
		while (hour_result >= 24)
		{
			hour_result -= 24;
		}
	}

	wprintf(L"%d시 %d분\n", hour_result, min_result);

    return 0;
}
