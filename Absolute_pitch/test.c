#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>


void main(void) {
	char note[21] = "도 레 미 파 솔 라 시";
	char answer[10];

		srand((unsigned int)time(NULL));
		int random = (rand() % 7);
		printf("%d\n", random);
		printf("%c%c", note[random * 2], note[random * 2 + 1]); 

		printf("정답은 무엇일까요?: ");
		scanf("%s", answer);

		printf("%s\n", answer);
		printf("%c%c\n", note[random * 2], note[random * 2 + 1]);
		//여기까진 잘나옴


		if (!strcmp(answer, note[random * 2])) {
			printf("맞았습니다.\n");
		}
		else {
			printf("틀렸습니다.");
			printf("정답은 %c%c입니다. ", note[random * 2], note[random * 2 + 1]);
		}

		

	return 0;
}