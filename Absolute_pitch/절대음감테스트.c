#include "guess_note.h"
// _getch() value of ESC key
#define ESC 27
#define UP 72
#define DOWN 80
#define SUBMIT 4
#define ENTER 13

/* �Լ� ���� */
int keyControl();
int menuDraw();
void print_piano();
int MakeRandNote(int random);
int playGame(char** dp, int n);
void rule();
void guess_note(void);

char* p[SIZE] = { "��", "��", "��", "��", "��" , "��", "��", "��", "��", "��" };


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
			else if (temp == 13) {
				return ENTER;
			}
			else if (temp == 27) {
				return ESC;
			}
		}
		return 0;
	}
}

int menuDraw() {
	PlaySound(TEXT("guess_note.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	system("cls");

	rectangle(114, 29, 2, 1);

	int x = 2;
	int y = 5;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	print_auto_y(&x, &y, " _______  _______  _______  _______  ___      __   __  _______  _______    _______  ___   _______  _______  __   __ ");
	print_auto_y(&x, &y, "|   _   ||  _    ||       ||       ||   |    |  | |  ||       ||       |  |       ||   | |       ||       ||  | |  |");
	print_auto_y(&x, &y, "|  |_|  || |_|   ||  _____||   _   ||   |    |  | |  ||_     _||    ___|  |    _  ||   | |_     _||       ||  |_|  |");
	print_auto_y(&x, &y, "|       ||       || |_____ |  | |  ||   |    |  |_|  |  |   |  |   |___   |   |_| ||   |   |   |  |       ||       |");
	print_auto_y(&x, &y, "|       ||  _   | |_____  ||  |_|  ||   |___ |       |  |   |  |    ___|  |    ___||   |   |   |  |      _||       |");
	print_auto_y(&x, &y, "|   _   || |_|   | _____| ||       ||       ||       |  |   |  |   |___   |   |    |   |   |   |  |     |_ |   _   |");
	print_auto_y(&x, &y, "|__| |__||_______||_______||_______||_______||_______|  |___|  |_______|  |___|    |___|   |___|  |_______||__| |__|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);

	gotoxy(41, 15);
	printf("�鸮�� ���� ��� �˸��� ���ڸ� ������~!");
	gotoxy(46, 16);
	printf("�ٽ� �������� 0�� �Է��ϼ���!");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);


	x = 50;
	y = 21;

	gotoxy(x - 2, y); // -2�� ������ >�� ����ϱ� ���ؼ�
	printf(">     �� �� �� �� \n");
	gotoxy(x, y + 2);
	printf("       �� �� \n");
	print_by_name("������");



	while (1) {
		int n = keyControl();
		switch (n) {
		case UP: {
			if (y > 21) { //y�� 12~14������ �̵�
				gotoxy(x - 2, y); // x-2�ϴ� ������ >�� �� ĭ ������ ����ϱ� ���ؼ�
				printf(" ");

				gotoxy(x - 2, y -= 2); //���� �̵��� ��ġ�� �̵��Ͽ�
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
				printf(">"); //�ٽ� �׸���
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			break;
		}
		case DOWN: {
			if (y < 23) { //�ִ� 20
				gotoxy(x - 2, y);
				printf(" ");

				gotoxy(x - 2, y += 2);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
				printf(">");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			break;
		}
		case ENTER: {
			return y - 21;
			break;
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
	puts("�� 1 �� 2 �� 3 �� 4 �� 5 �� 6 �� 7 �� 8 �� 9 �� 10��");
	gotoxy(34, 19);
	puts("���������������������������");
}

// ���� �� ����ϴ� �Լ�
int MakeRandNote(int random) {
	double frequency[] = { 523, 587, 659, 699, 784, 880, 988, 1047, 1175, 1319 };
	const int note_len = 600;

	Beep(frequency[random], note_len);

	return 0;
}

int playGame(char** dp, int n) {
	int count = 0;
	while (1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | (0 << 4));

		srand((unsigned int)time(NULL));
		int random = (rand() % 10);

		MakeRandNote(random);

		system("cls");

		print_piano();

		int answer;

		while (1) {
			gotoxy(34, 9);
			printf("���� ���ϱ��?: ");
			scanf("%d", &answer);

			if (answer == 0) {
				MakeRandNote(random);
			}
			else {
				break;
			}
		}

		if (answer == random + 1) {
			gotoxy(75, 9);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 | (0 << 4));
			printf("�����Դϴ�!\n");
			count++;
			//printf("%d", count);
		}
		else if (answer != 0 && answer != random + 1) {
			gotoxy(64, 9);
			printf("��! ������ %d(%s)�Դϴ�.\n", random + 1, *(dp + random));
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12 | (0 << 4));
			for (int n = 3; n > 0; --n) {
				gotoxy(82, 29);
				printf("%d�� �Ŀ� ����ȭ������ ���ư��ϴ�...\n", n);
				Sleep(1000);
			}
			//Sleep(2500);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | (0 << 4));
			break;
		}
	}
	return 0;
}

void guess_note(void) {
	system("cls");

	while (1) {
		int menuCode = menuDraw();
		switch (menuCode) {
		case 0:
			PlaySound(NULL, 0, 0);
			playGame(p, SIZE);
			break;
		case 2:
			main();
			break;
		}
		system("cls");
	}
	return 0;
}