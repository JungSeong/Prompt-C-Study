#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void input_information();
void print_information();

void pay();
void basic_pay();
void additional_pay();
void final_pay();

typedef struct
{
    char name[20];
    char position[10];
    int overtime;

    int basic_pay;
    int additional_pay;
    int final_pay;
} Employee;

int main()
{
    int size;
    Employee* employee = NULL;

    input_information(&employee, &size); // 사원의 수, 사원의 정보를 입력 받음

    pay(&employee, size); // 급여 관련 내용 처리

    print_information(employee, size); // 사원 정보 출력

    free(employee);
}

void input_information(Employee** employee, int *size)
{
    printf("전체 사원의 수를 입력하세요 : ");
    scanf("%d", size);
    *employee = (Employee*)malloc(sizeof(Employee)* *size);

    if (*employee == NULL)
    {
        printf("메모리 할당에 실패하였습니다.\n");
    }

    for (int i=0; i<*size; i++)
    {
        printf("사원 %d의 이름, 직위, 야근 시간을 입력하세요 : ", i+1);
        scanf("%s %s %d", (*employee)[i].name, (*employee)[i].position, &(*employee)[i].overtime);
    }
}

void print_information(Employee* employee, int size)
{
    FILE* ptr_file = fopen("result.txt", "w+");

    if (ptr_file == NULL)
    {
        puts("sales_report 파일을 열 수가 없습니다!");
        exit(1);
    }
    
    for (int i=0; i<size; i++)
    {
        fprintf(
            ptr_file, 
            "========================\n"
            "사원 %d의 정보 : \n"
            "이름 : %s\n"
            "직책 : %s\n"
            "야근시간 : %d시간\n"
            "기본 급여 : %d원\n"
            "추가 급여 : %d원\n"
            "최종 급여 : %d원\n"
            ,i+1, employee[i].name, employee[i].position, employee[i].overtime, employee[i].basic_pay, employee[i].additional_pay, employee[i].final_pay
        );
    }

    fclose(ptr_file);
}

void pay(Employee** employee, int size)
{
    basic_pay(employee, size); // 기본 급여 적용하기
    additional_pay(employee, size); // 직책, 야근 수당 적용하기
    final_pay(employee, size); // 최종 급여 결정하기
}

void basic_pay(Employee** employee, int size)
{
    for (int i=0; i<size; i++)
    {
        if (strcmp((*employee)[i].position, "과장") == 0) // 직책이 과장인 경우
        {
            (*employee)[i].basic_pay = 3000000;
        }
        else if (strcmp((*employee)[i].position, "대리") == 0) // 직책이 대리인 경우
        {
            (*employee)[i].basic_pay = 2000000;
        }
        else // 그 외 모든 경우
        {
            (*employee)[i].basic_pay = 1500000;
        }
    }
}

void additional_pay(Employee** employee, int size)
{
    for (int i=0; i<size; i++)
    {
        if (strcmp((*employee)[i].position, "과장") == 0) // 직책이 과장인 경우
        {
            (*employee)[i].additional_pay = 0.1 * 3000000 + (*employee)[i].overtime * 20000;
        }
        else if (strcmp((*employee)[i].position, "대리") == 0) // 직책이 대리인 경우
        {
            (*employee)[i].additional_pay = 0.07 * 2000000 + (*employee)[i].overtime * 20000;
        }
        else // 그 외 모든 경우
        {
            (*employee)[i].additional_pay = 0.05 * 1500000 + (*employee)[i].overtime * 20000;
        }
    }
}

void final_pay(Employee** employee, int size)
{
    for (int i=0; i<size; i++)
    {
        (*employee)[i].final_pay = (*employee)[i].basic_pay + (*employee)[i].additional_pay;
    }
}