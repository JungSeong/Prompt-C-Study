#include <stdio.h>

typedef union student {
    int age;
    double grade;
} STUDENT;

int main()
{
    STUDENT student = {20};
    printf("%d %lf", student.age, student.grade);
    student.grade = 90.2f;
    printf("\n%d %lf", student.age, student.grade);
}

//메모리가 부족했을 때에는 사용했지만 요즘에는 잘 사용되지 않는다.