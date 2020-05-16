#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

#define ZERO 0
#define ROWS 10
#define COLUMNS 20

enum CellStates {
	ACTIVE = 1,
	NONACTIVE = 0
};

enum Buttons {
	LEFT = 97,
	UP = 119,
	RIGHT = 100,
	DOWN = 115,
	ENTER = 13
};

enum Rotation {
	TO_LEFT,
	TO_UP,
	TO_RIGHT,
	TO_DOWN
};

struct Position {
	int posX;
	int posY;

	Position(){}

	Position(int posX, int poosY) {
		this->posX = posX;
		this->posY = posY;
	}
};

struct Tank {
	Rotation rotationState;
	Position gunpointPosition = Position();
	int health;
};

void draw(int map[ROWS][COLUMNS], Tank tank1, Tank tank2, int sleepDuration = 0) {
	system("cls");

	map[tank1.gunpointPosition.posX][tank1.gunpointPosition.posY] = 1;
	map[tank2.gunpointPosition.posX][tank2.gunpointPosition.posY] = 1;

	if (tank1.rotationState == Rotation::TO_UP) {
		map[tank1.gunpointPosition.posY + 1][tank1.gunpointPosition.posX - 1] = 1;
		map[tank1.gunpointPosition.posY + 1][tank1.gunpointPosition.posX] = 1;
		map[tank1.gunpointPosition.posY + 1][tank1.gunpointPosition.posX + 1] = 1;
	}
	else if (tank1.rotationState == Rotation::TO_LEFT) {
		map[tank1.gunpointPosition.posY - 1][tank1.gunpointPosition.posX + 1] = 1;
		map[tank1.gunpointPosition.posY][tank1.gunpointPosition.posX + 1] = 1;
		map[tank1.gunpointPosition.posY + 1][tank1.gunpointPosition.posX + 1] = 1;
	}
	else if (tank1.rotationState == Rotation::TO_RIGHT) {
		map[tank1.gunpointPosition.posY - 1][tank1.gunpointPosition.posX - 1] = 1;
		map[tank1.gunpointPosition.posY][tank1.gunpointPosition.posX - 1] = 1;
		map[tank1.gunpointPosition.posY + 1][tank1.gunpointPosition.posX - 1] = 1;
	}
	else if (tank1.rotationState == Rotation::TO_DOWN) {
		map[tank1.gunpointPosition.posY - 1][tank1.gunpointPosition.posX - 1] = 1;
		map[tank1.gunpointPosition.posY - 1][tank1.gunpointPosition.posX] = 1;
		map[tank1.gunpointPosition.posY - 1][tank1.gunpointPosition.posX + 1] = 1;
	}

	if (tank2.rotationState == Rotation::TO_UP) {
		map[tank2.gunpointPosition.posY + 1][tank2.gunpointPosition.posX - 1] = 1;
		map[tank2.gunpointPosition.posY + 1][tank2.gunpointPosition.posX] = 1;
		map[tank2.gunpointPosition.posY + 1][tank2.gunpointPosition.posX + 1] = 1;
	}
	else if (tank2.rotationState == Rotation::TO_LEFT) {
		map[tank2.gunpointPosition.posY - 1][tank2.gunpointPosition.posX + 1] = 1;
		map[tank2.gunpointPosition.posY][tank2.gunpointPosition.posX + 1] = 1;
		map[tank2.gunpointPosition.posY + 1][tank2.gunpointPosition.posX + 1] = 1;
	}
	else if (tank2.rotationState == Rotation::TO_RIGHT) {
		map[tank2.gunpointPosition.posY - 1][tank2.gunpointPosition.posX - 1] = 1;
		map[tank2.gunpointPosition.posY][tank2.gunpointPosition.posX - 1] = 1;
		map[tank2.gunpointPosition.posY + 1][tank2.gunpointPosition.posX - 1] = 1;
	}
	else if (tank2.rotationState == Rotation::TO_DOWN) {
		map[tank2.gunpointPosition.posY - 1][tank2.gunpointPosition.posX - 1] = 1;
		map[tank2.gunpointPosition.posY - 1][tank2.gunpointPosition.posX] = 1;
		map[tank2.gunpointPosition.posY - 1][tank2.gunpointPosition.posX + 1] = 1;
	}
	
	for (int i = 0; i < ROWS; i++) {
		for (int k = 0; k < COLUMNS; k++) {
			if (map[i][k] == 1) {
				cout << (char)219;
			}
			else {
				cout << (char)176;
			}
			Sleep(sleepDuration);
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

void player1Move(int map[ROWS][COLUMNS], Tank tank, int buttonCode) {
	Position activeCellPosition = getActiveCellPosition(map);

	switch (buttonCode) {
	case Buttons::RIGHT:
		if ((activeCellPosition.posX + 1) != COLUMNS) {
			map[activeCellPosition.posY][activeCellPosition.posX] = CellStates::NONACTIVE;
			map[activeCellPosition.posY][activeCellPosition.posX + 1] = CellStates::ACTIVE;
		}
		break;
	case Buttons::LEFT:
		if ((activeCellPosition.posX - 1) >= ZERO) {
			map[activeCellPosition.posY][activeCellPosition.posX] = CellStates::NONACTIVE;
			map[activeCellPosition.posY][activeCellPosition.posX - 1] = CellStates::ACTIVE;
		}
		break;
	case Buttons::DOWN:
		if ((activeCellPosition.posY + 1) != ROWS) {
			map[activeCellPosition.posY][activeCellPosition.posX] = CellStates::NONACTIVE;
			map[activeCellPosition.posY + 1][activeCellPosition.posX] = CellStates::ACTIVE;
		}
		break;
	case Buttons::UP:
		if ((activeCellPosition.posY - 1) >= ZERO) {
			map[activeCellPosition.posY][activeCellPosition.posX] = CellStates::NONACTIVE;
			map[activeCellPosition.posY - 1][activeCellPosition.posX] = CellStates::ACTIVE;
		}
		break;
	}
}

int main() {
	int map[ROWS][COLUMNS] = { 
								{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
								{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
								{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
								{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
								{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
								{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
								{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
								{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
							};

	Tank tank1, tank2;
	tank1.gunpointPosition.posX = 3;
	tank1.gunpointPosition.posY = 3;
	tank1.health = 100;
	tank1.rotationState = Rotation::TO_UP;

	tank2.gunpointPosition.posX = 7;
	tank2.gunpointPosition.posY = 7;
	tank2.health = 100;
	tank2.rotationState = Rotation::TO_LEFT;
	
	draw(map, tank1, tank2); //draw(map, 10) for starting animation

	int button;
	while (true)
	{
		if (_kbhit())
		{
			button = _getch();
			
			//changeActiveCell(map, button);
			draw(map, tank1, tank2);
			cout << "\npressed button: " << (char)button << " (" << button << ")";
		}
		Sleep(250);
	}
}