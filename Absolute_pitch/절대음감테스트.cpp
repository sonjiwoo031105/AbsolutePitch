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
	system("mode con cols=76 lines=30 | title 절 대 음 감 테 스 트");

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
	gotoxy(x - 2, y); //-2한 이유는 >를 출력하기 위해
	cout << ">       게 임 하 기 ";
	gotoxy(x, y + 1);
	cout << "      게 임 방 법  ";
	gotoxy(x, y + 2);
	cout << "         종 료 ";

	while (1) {
		int n = keyControl();
		switch (n) {
		case UP: {
			if (y > 13) { //y는 12~14까지만 이동
				gotoxy(x - 2, y); // x-2하는 이유는 >를 두 칸 이전에 출력하기 위해서
				cout << " "; //원래 위치를 지우고
				gotoxy(x - 2, --y); //새로 이동한 위치로 이동하여
				cout << ">"; //다시 그리기
			}
			break;
		}
		case DOWN: {
			if (y < 15) { //최대 15
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, ++y);
				cout << ">";
			}
			break;
		}
		case SUBMIT: {
			return y - 13; //y 시작 위치가 12였으므로 y-12를 하면 0,1,2 세 숫자를 받을 수 있다.
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
		string note[] = { "도","레","미","파","솔","라","시" };
		double frequency[] = { 523.2511, 587.3295, 659.2551, 698.456, 783.9909, 880, 987.7666 };
		const int note_len = 600;
		srand((unsigned int)time(NULL));
		int random = 1 + (rand() % 7); //1-7사이의 랜덤 숫자
		string answer;

		for (int i = 0; i < 7; i++) {
			if (random == i + 1) {
				Sleep(200);
			}
		}
		Beep(frequency[random - 1], note_len);

		cout << "정답은 무엇일까요?: ";
		cin >> answer;

		if (answer == note[random - 1]) {
			cout << "맞았습니다." << endl;
			count ++;
			cout << count << " 번쨰" << endl;
			switch (count) {
			case 3:
				cout << "이때부터 두개로";
			case 5:
				cout << "이때부터 세개로";
			default:
				cout << "랜덤숫자가 +1개씩";
			}
		}
		else {
			cout << "틀렸어 바부양" << endl;
			cout << "정답은 " << note[random - 1] << " (이)었습니당" << endl;
			gotoxy(38, 28);
			cout << "뒤로 가려면 스페이스바를 누르세요...";
			break;
		}
	}
	goBack();
}

void rule() {
	system("cls");
	gotoxy(26, 14);
	cout << "그냥 듣고 맞추세여";
	gotoxy(38, 28);
	cout << "뒤로 가려면 스페이스바를 누르세요...";
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
			return 0; //종료
		}
		system("cls");
	}
	return 0;
}
