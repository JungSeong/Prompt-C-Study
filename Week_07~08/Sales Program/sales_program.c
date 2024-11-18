#include <stdio.h>
#include <stdlib.h>

void set_employee_structure();
void print_good_sellers();

typedef struct
{
    int num, result;
    char name[10];
} Employee;

int main()
{
    Employee* employee = NULL;
    int size = 0;

    set_employee_structure(&employee, &size);
    print_good_sellers(employee, size);

    free(employee);
}

void set_employee_structure(Employee ** employee, int *size)
{
    FILE* report = fopen("sales_report.txt", "r");
    char c;

    if(report != NULL)
    {
        while (EOF != (c = fgetc(report)))
        {
            
            if (c == '\n')
            {
                (*size)++;
            }
        }

        *employee = (Employee*)malloc(sizeof(Employee) * *size);
        rewind(report);

        for (int i=0; i<*size; i++)
        {
            fscanf(report, "%d %d %s", &(*employee)[i].num, &(*employee)[i].result, (*employee)[i].name);
        }
    }

    fclose(report);
}

void print_good_sellers(Employee * employee, int size)
{
    FILE* good_seller = fopen("good_seller.txt", "w+");
    FILE* best_seller = fopen("best_seller.txt", "w+");
    int best_idx = 0;

    fprintf(good_seller, "이 달의 우수 사원 목록\n");
    fprintf(best_seller, "이 달의 최고 우수 사원\n");

    for (int i=0; i<size; i++)
    {
        if (employee[i].result > 30)
        {
            fprintf(good_seller,
            "사원 번호 : %d, 이름 : %s, 실적 : %d\n",
            employee[i].num, employee[i].name, employee[i].result
            );
        }

        if (employee[i].result > employee[best_idx].result)
        {
            best_idx = i;
        }
    }

    fprintf(best_seller,
            "사원 번호 : %d, 이름 : %s, 실적 : %d\n",
            employee[best_idx].num, employee[best_idx].name, employee[best_idx].result
            );

    fclose(good_seller);
    fclose(best_seller);
}