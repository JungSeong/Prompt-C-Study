#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[10];
    int health;
    int attack;
} Monster;

typedef struct
{
    char name[10];
    int health;
    int attack;
} User;

int main()
{
    Monster* monster = NULL;
    User* user = NULL;
    int monster_death_cnt = 0, user_death_cnt = 0;
    int monster_idx = 0, user_idx = 0;

    int M, U;
    printf("몬스터의 수와 유저의 수 입력 : ");
    scanf("%d %d", &M, &U);

    monster = (Monster*)malloc(sizeof(Monster) * M);
    user = (User*)malloc(sizeof(User) * U);

    if (monster == NULL || user == NULL)
    {
        printf("메모리 할당에 실패하였습니다.\n");
        return -1;
    }

    // for (int i=0; i<M; i++)
    // {
    //     printf("name %d : %p, health %d : %p, attack %d : %p \n", i, monster[i].name, i, &monster[i].health, i, &monster[i].attack);
    //     printf("name %d : %p, health %d : %p, attack %d : %p \n", i, (monster+i)->name, i, &(monster+i)->health, i, &(monster+i)->attack);
    // }

    for (int i=0; i<M; i++)
    {
        printf("Monster %d의 name, health, attack : ", i);
        scanf("%s %d %d", (monster+i)->name, &(monster+i)->health, &(monster+i)->attack);
    }

    for (int i=0; i<U; i++)
    {
        printf("User %d의 name, health, attack : ", i);
        scanf("%s %d %d", user[i].name, &user[i].health, &user[i].attack);
    }

    while(monster_death_cnt < M && user_death_cnt < U)
    {
        monster[monster_idx].health = monster[monster_idx].health - user[user_idx].attack;
        user[user_idx].health = user[user_idx].health - monster[monster_idx].attack;

        if (monster[monster_idx].health <= 0)
        {
            printf("%s이(가) 쓰러졌습니다!\n", monster[monster_idx].name);
            // printf("%s이(가) 쓰러졌습니다!\n", (*(monster + monster_idx)).name);
            // printf("%s이(가) 쓰러졌습니다!\n", (monster + monster_idx)->name);

            monster_idx++;
            monster_death_cnt++;
        }
        if (user[user_idx].health <= 0)
        {
            printf("%s이(가) 쓰러졌습니다!\n", user[user_idx].name);
            // printf("%s이(가) 쓰러졌습니다!\n", (*(user + user_idx)).name);
            // printf("%s이(가) 쓰러졌습니다!\n", (user + user_idx) -> name);

            user_idx++;
            user_death_cnt++;
        }
    }

    if (monster_death_cnt == M && user_death_cnt != U)
    {
        printf("유저 팀이 승리했습니다!\n");
    }

    if (monster_death_cnt != M && user_death_cnt == U)
    {
        printf("몬스터 팀이 승리했습니다!\n");
    }
    if (monster_death_cnt == M && user_death_cnt == U)
    {
        printf("비겼습니다!\n");
    }

    free(monster);
    free(user);
}