#include "modules.h"

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77


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

void move_arrow_key(
	char key,
	int* x,
	int* y,
	int size,
	int y_min,
	int y_max,
	int x_min,
	int x_max
) {
	const int Y_MIN = y_min;
	const int Y_MAX = y_max;
	const int X_MIN = x_min;
	const int X_MAX = x_max;

	switch (key) {
		// pressed ¡è
	case UP:
		*y -= size;
		if (*y < Y_MIN) *y = Y_MAX;
		break;
		// pressed ¡é
	case DOWN:
		*y += size;
		if (*y > Y_MAX) *y = Y_MIN;
		break;
		// pressed ¡ç
	case LEFT:
		*x -= size;
		if (*x < X_MIN) *x = X_MAX;
		break;
		// pressed ¡æ
	case RIGHT:
		*x += size;
		if (*x > X_MAX) *x = X_MIN;
		break;
	}
}

void print_auto_y(int* x, int* y, char* str) {
	gotoxy(*x, *y);
	printf(str);
	*y += 1;
}

void setColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void rectangle(int width, int height, int x, int y) {
	// ¦£¡ª¡ª¡ª¡ª¦¤
	for (int i = 1; i < width / 2; i++) {
		gotoxy((x + width) / 2 - i, y);
		printf("¦¡");

		gotoxy((x + width) / 2 + i, y);
		printf("¦¡");
		Sleep(1);
	}
	gotoxy(x, y);
	printf("¦£");
	gotoxy(x + width, y);
	printf("¦¤");

	// £ü      £ü
	for (int i = 1; i < height; i++) {
		gotoxy(x, y + i);
		// £ü      £ü
		printf("¦¢");

		for (int j = 1; j < width - 1; j++) {
			printf(" ");
		}
		printf(" ");

		printf("¦¢");
		Sleep(1);
	}

	// ¦¦¡ª¡ª¡ª¡ª¦¥
	gotoxy(x, y + height);
	printf("¦¦");
	gotoxy(x + width, y + height);
	printf("¦¥");
	for (int i = 1; i < width / 2; i++) {
		gotoxy(x + i, y + height);
		printf("¦¡");

		gotoxy((x + width) - i, y + height);
		printf("¦¡");
		Sleep(1);
	}
}
