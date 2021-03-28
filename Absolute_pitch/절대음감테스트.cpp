#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <conio.h>
#include<windows.h>
using namespace std;

#define UP 72
#define DOWN 80
#define SUBMIT 4

void init() {
	system("mode con cols=76 lines=30 | title �� �� �� �� �� �� Ʈ");

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
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
	int x = 26;
	int y = 13;
	gotoxy(x - 2, y); //-2�� ������ >�� ����ϱ� ����
	cout << ">       �� �� �� �� ";
	gotoxy(x, y + 1);
	cout << "      �� �� �� ��  ";
	gotoxy(x, y + 2);
	cout << "         �� �� ";

	while (1) {
		int n = keyControl();
		switch (n) {
		case UP: {
			if (y > 13) { //y�� 12~14������ �̵�
				gotoxy(x - 2, y); // x-2�ϴ� ������ >�� �� ĭ ������ ����ϱ� ���ؼ�
				cout << " "; //���� ��ġ�� �����
				gotoxy(x - 2, --y); //���� �̵��� ��ġ�� �̵��Ͽ�
				cout << ">"; //�ٽ� �׸���
			}
			break;
		}
		case DOWN: {
			if (y < 15) { //�ִ� 15
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, ++y);
				cout << ">";
			}
			break;
		}
		case SUBMIT: {
			return y - 13; //y ���� ��ġ�� 12�����Ƿ� y-12�� �ϸ� 0,1,2 �� ���ڸ� ���� �� �ִ�.
		}
		}
	}
	return 0;
}

int goBack() {
	while (1) {
		if (keyControl() == SUBMIT)
			break;
		int n = keyControl();
		switch (n) {
		case SUBMIT: {
			return 0;
		}
		}
	}
	return 0;
}

void makeRandom() {
	system("cls");
	int count = 0;
	while (1) {
		string note[] = { "��","��","��","��","��","��","��" };
		double frequency[] = { 523.2511, 587.3295, 659.2551, 698.456, 783.9909, 880, 987.7666 };
		const int note_len = 600;
		srand((unsigned int)time(NULL));
		int random = 1 + (rand() % 7); //1-7������ ���� ����
		string answer;

		for (int i = 0; i < 7; i++) {
			if (random == i + 1) {
				Sleep(200);
			}
		}
		Beep(frequency[random - 1], note_len);

		cout << "������ �����ϱ��?: ";
		cin >> answer;

		if (answer == note[random - 1]) {
			cout << "�¾ҽ��ϴ�." << endl;
			count ++;
			cout << count << " ����" << endl;
			switch (count) {
			case 3:
				cout << "�̶����� �ΰ���";
			case 5:
				cout << "�̶����� ������";
			default:
				cout << "�������ڰ� +1����";
			}
		}
		else {
			cout << "Ʋ�Ⱦ� �ٺξ�" << endl;
			cout << "������ " << note[random - 1] << " (��)�����ϴ�" << endl;
			gotoxy(38, 28);
			cout << "�ڷ� ������ �����̽��ٸ� ��������...";
			break;
		}
	}
	goBack();
}

void rule() {
	system("cls");
	gotoxy(26, 14);
	cout << "�׳� ��� ���߼���";
	gotoxy(38, 28);
	cout << "�ڷ� ������ �����̽��ٸ� ��������...";
	goBack();
}

int main()
{
	init();

	while (1) {
		int menuCode = menuDraw();
		if (menuCode == 0) {
			makeRandom();
		}
		else if (menuCode == 1) {
			rule();
		}
		else if (menuCode == 2) {
			return 0; //����
		}
		system("cls");
	}
	return 0;
}
