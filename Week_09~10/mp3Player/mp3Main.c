#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListBaseQueue.h"

int main(void) {
	Queue mp3_queue;
	QueueInit(&mp3_queue);
	
	int input;
	char ch;
	Data name = (Data)malloc(sizeof(char) * SIZE);
	Data mp3Name;

	while (TRUE)
	{
		printf("================================================================\n");
		printf("                            ♫ mp3 플레이어 ♫                      \n");
		printf("1 : 음악 추가, 2 : 음악 리스트 보기, 3 : 플레이 리스트 삭제 0 : 프로그램 종료 \n");
		printf("================================================================\n");
		printf("커맨드를 입력하세요 : ");

		scanf("%d", &input);
		getchar(); // 버퍼에 남아있는 개행 문자 제거

		switch(input)
		{
			case 0 :
			{
				printf("프로그램이 정상적으로 종료되었습니다!\n");
				exit(0);
				break;
			}		
			case 1 :
			{
				printf("음악 이름을 입력하세요 : ");
				scanf("%s", name);
				getchar();

				Data newMusic = (Data)malloc(sizeof(char) * SIZE);
				strcpy(newMusic, name);
				Enqueue(&mp3_queue, newMusic);
				break;
			}
			case 2 :
			{
				if(QFirst(&mp3_queue, &mp3Name))
				{
					printf("%s\n",  mp3Name);

					while(QNext(&mp3_queue, &mp3Name))
					{
						printf("%s\n", mp3Name);
					}
				}
				break;
			}
			case 3 :
			{
				printf("정말 현재 플레이리스트를 삭제하겠습니까? Y or N : ");
				scanf("%c", &ch);

				if (ch == 'Y')
				{
					while (!QIsEmpty(&mp3_queue))
					{
						Dequeue(&mp3_queue);
					}
					printf("플레이 리스트가 완전 삭제되었습니다.\n");
				}
				if (ch == 'N')
				{
					continue;
				}
			}

		}
	}

	return 0;
}
