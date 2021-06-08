#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>

#define SIZE 7

// _getch() value of ESC key
#define ESC 27
#define UP 72
#define DOWN 80
#define SUBMIT 4

/* �Լ� ���� */
int keyControl();

void gotoxy(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int get_key(void) {
	// if keyboard pressed
	if (_kbhit()) {
		// return pressed value
		return _getch();
	}
	return 1;
}

int keyControl() {
	char temp;
	while (1) {
		if (_kbhit()) {
			temp = _getch();
			if (temp == -32) {
				temp = _getch();
				switch (temp) {
				case UP:
					return UP;
					break;
				case DOWN:
					return DOWN;
					break;
				}
			}
			if (temp == ' ') {
				return SUBMIT;
			}
		}
		return 0;
	}
}

int menuDraw() {
	system("cls");
	int x = 50;
	int y = 13;

	gotoxy(x - 2, y); // -2�� ������ >�� ����ϱ� ���ؼ�
	printf(">     �� �� �� �� \n");
	gotoxy(x, y + 2);
	printf("    �� �� �� ��  \n");
	gotoxy(x, y + 4);
	printf("       �� �� \n");


	while (1) {
		int n = keyControl();
		switch (n) {
		case UP: {
			if (y > 13) { //y�� 12~14������ �̵�
				gotoxy(x - 2, y); // x-2�ϴ� ������ >�� �� ĭ ������ ����ϱ� ���ؼ�
				printf(" ");

				gotoxy(x - 2, y -= 2); //���� �̵��� ��ġ�� �̵��Ͽ�
				printf(">"); //�ٽ� �׸���
			}
			break;
		}
		case DOWN: {
			if (y < 17) { //�ִ� 17
				gotoxy(x - 2, y);
				printf(" ");

				gotoxy(x - 2, y += 2);
				printf(">");
			}
			break;
		}
		case SUBMIT: {
			return y - 13;
		}
		}
	}
	return 0;
}

void print_piano() {
	gotoxy(34, 11);
	puts("����� �������� ��� �������� �����");
	gotoxy(34, 12);
	puts("��  ��� ���  ��  ��� ��� ���  ��  ��� ���  �� ");
	gotoxy(34, 13);
	puts("��  ��� ���  ��  ��� ��� ���  ��  ��� ���  �� ");
	gotoxy(34, 14);
	puts("��  ��� ���  ��  ��� ��� ���  ��  ��� ���  �� ");
	gotoxy(34, 15);
	puts("��  ��� ���  ��  ��� ��� ���  ��  ��� ���  �� ");
	gotoxy(34, 16);
	puts("��  ��� ���  ��  ��� ��� ���  ��  ��� ���  �� ");
	gotoxy(34, 17);
	puts("��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��");
	gotoxy(34, 18);
	puts("��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��");
	gotoxy(34, 19);
	puts("���������������������������");
}

int pr_str_array(char** dp, int n) {
	while (1) {
		double frequency[] = { 523.2511, 587.3295, 659.2551, 698.456, 783.9909, 880, 987.7666 };
		const int note_len = 600;

		srand((unsigned int)time(NULL));
		int random = (rand() % 7);

		for (int i = 0; i < 7; i++) {
			if (random == i + 1) {
				Sleep(200);
			}
		}
		Beep(frequency[random], note_len);


		system("cls");

		char answer[10];

		print_piano();

		gotoxy(34, 9);
		printf("���� ���ϱ��?: ");
		scanf("%s", answer);

		if (!strcmp(answer, *(dp + random))) {
			gotoxy(76, 9);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 | (0 << 4));
			printf("�����Դϴ�!\n");
		}
		else {
			gotoxy(67, 9);
			printf("��! ������ %s�Դϴ�.\n", *(dp + random));
			gotoxy(82, 28);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12 | (0 << 4));
			printf("3�� �Ŀ� ����ȭ������ ���ư��ϴ�...");
			Sleep(3000);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | (0 << 4));
			break;
		}
	}
	return 0;
}

int playGame() {
	char* p[SIZE] = { "��", "��", "��", "��", "��" , "��", "��" };
	while (1) {
		int n = keyControl();
		switch (n) {
		case SUBMIT: {
			return pr_str_array(p, SIZE);
		}
		}
	}
	return 0;
}
void rule() {
	system("cls");
	gotoxy(26, 14);
	printf("���� ���� �� �ѱ۷� �����Ǿ� �ִ��� Ȯ�����ּ���.");
	gotoxy(75, 29);
	printf("������ �����Ϸ��� �����̽��ٸ� ��������...");
	playGame();
}

void main(void) {
	system("cls");

	char* p[SIZE] = { "��", "��", "��", "��", "��" , "��", "��" };
	int x = 100, y = 20;
	char key;


	while (1) {
		int menuCode = menuDraw();
		switch (menuCode) {
		case 0:
			pr_str_array(p, SIZE);
			break;
		case 2:
			rule();
			break;
		case 4:
			return 1;
		}
		system("cls");
	}

	do {
		gotoxy(x, y);
		printf("guess note");
		key = _getch();
	} while (key != ESC);

	return 0;
}