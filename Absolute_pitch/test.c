#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>


void main(void) {
	char note[21] = "�� �� �� �� �� �� ��";
	char answer[10];

		srand((unsigned int)time(NULL));
		int random = (rand() % 7);
		printf("%d\n", random);
		printf("%c%c", note[random * 2], note[random * 2 + 1]); 

		printf("������ �����ϱ��?: ");
		scanf("%s", answer);

		printf("%s\n", answer);
		printf("%c%c\n", note[random * 2], note[random * 2 + 1]);
		//������� �߳���


		if (!strcmp(answer, note[random * 2])) {
			printf("�¾ҽ��ϴ�.\n");
		}
		else {
			printf("Ʋ�Ƚ��ϴ�.");
			printf("������ %c%c�Դϴ�. ", note[random * 2], note[random * 2 + 1]);
		}

		

	return 0;
}