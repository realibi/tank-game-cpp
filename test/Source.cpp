#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

#define ROWS 5
#define COLUMNS 5

enum Buttons {
	left = 97,
	up = 119,
	right = 100,
	down = 115
};

struct Position {
	int posX;
	int posY;
};

void draw(int map[ROWS][COLUMNS]) {
	system("cls");
	for (int i = 0; i < ROWS; i++) {
		for (int k = 0; k < COLUMNS; k++) {
			if (map[i][k] == 1) {
				cout << (char)219;
			}
			else {
				cout << (char)176;
			}
		}
		cout << endl;
	}
}

Position getActiveCellPosition(int map[ROWS][COLUMNS]) {
	int activePosX = 0;
	int activePosY = 0;

	for (int i = 0; i < ROWS; i++) {
		for (int k = 0; k < COLUMNS; k++) {
			if (map[i][k] == 1) {
				activePosY = i;
				activePosX = k;
			}
		}
	}

	Position activePosition;
	activePosition.posX = activePosX;
	activePosition.posY = activePosY;

	return activePosition;
}

void changeActiveCell(int map[ROWS][COLUMNS], int buttonCode) {
	Position activeCellPosition = getActiveCellPosition(map);

	switch (buttonCode) {
	case Buttons::right:
		if ((activeCellPosition.posX + 1) != COLUMNS) {
			map[activeCellPosition.posY][activeCellPosition.posX] = 0;
			map[activeCellPosition.posY][activeCellPosition.posX + 1] = 1;
		}
		break;
	case Buttons::left:
		if ((activeCellPosition.posX - 1) >= 0) {
			map[activeCellPosition.posY][activeCellPosition.posX] = 0;
			map[activeCellPosition.posY][activeCellPosition.posX - 1] = 1;
		}
		break;
	case Buttons::down:
		if ((activeCellPosition.posY + 1) != ROWS) {
			map[activeCellPosition.posY][activeCellPosition.posX] = 0;
			map[activeCellPosition.posY + 1][activeCellPosition.posX] = 1;
		}
		break;
	case Buttons::up:
		if ((activeCellPosition.posY - 1) >= 0) {
			map[activeCellPosition.posY][activeCellPosition.posX] = 0;
			map[activeCellPosition.posY - 1][activeCellPosition.posX] = 1;
		}
		break;
	}
}

int main() {
	int map[ROWS][COLUMNS] = { {1, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0} };
	
	draw(map);

	int button;
	while (true)
	{
		if (_kbhit())
		{
			button = _getch();
			
			changeActiveCell(map, button);
			draw(map);
		}
		Sleep(250);
	}
}