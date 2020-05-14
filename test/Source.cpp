#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

enum Buttons {
	left = 97,
	up = 119,
	right = 100,
	down = 115
};

void draw(int length, int line[]) {
	system("cls");
	for (int i = 0; i < length; i++) {
		if (line[i] == 1) {
			cout << (char)219;
		}
		else {
			cout << (char)176;
		}
	}
}

int getActiveCellPosition(int length, int line[]) {
	int activeCellPosition = 0;
	for (int i = 0; i < length; i++) {
		if (line[i] == 1)
			activeCellPosition = i;
	}

	return activeCellPosition;
}

void changeActiveCell(int length, int line[], int buttonCode) {
	int activeCellPosition = getActiveCellPosition(length, line);

	switch (buttonCode) {
	case Buttons::right:
		if ((activeCellPosition + 1) != length) {
			line[activeCellPosition] = 0;
			line[activeCellPosition + 1] = 1;
		}
		break;
	case Buttons::left:
		if ((activeCellPosition - 1) >= 0) {
			line[activeCellPosition] = 0;
			line[activeCellPosition - 1] = 1;
		}
		break;
	}
}

int main() {
	const int length = 5;
	int line[length] = { 1, 0, 0, 0, 0 };
	
	draw(length, line);

	int button;
	while (true)
	{
		if (_kbhit())
		{
			button = _getch();
			
			changeActiveCell(length, line, button);
			draw(length, line);
		}
		Sleep(250);
	}
}