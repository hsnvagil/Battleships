#include <iostream>
#include <Windows.h>
#include <fstream>
#include <time.h>
using namespace std;

int TEMP;
char name[25];
char name2[25];
HANDLE  hConsole;
int hitted = 0, hitted2 = 0, missed = 0, missed2 = 0;

void Printf(char player[][10], char enemy[][10], char playerplace[][10], char enemyplace[][10]) {

	char temp[10][10];

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			if (TEMP == 1) temp[i][j] = player[i][j];
			else if (TEMP == 2) temp[i][j] = enemy[i][j];
			else if (TEMP == 4) temp[i][j] = playerplace[i][j];
			else if (TEMP == 5) temp[i][j] = enemyplace[i][j];
		}

	int ROWS = 0, COLS = 0;
	system("CLS");
	cout << "\n\n    1   2   3   4   5   6   7   8   9   10" << endl;
	char letter = 65;
	for (int i = 0; i < 20; i++) {
		if (i == 0) {
			cout << "  " << char(218) << char(196) << char(196) << char(196);
			for (int i = 0; i <= 8; i++) cout << char(194) << char(196) << char(196) << char(196);
			cout << char(191) << "\n" << letter << " ";
			letter++;
		}

		if (i % 2 == 0) {
			COLS = 0;
			for (int j = 0; j < 10; j++) {
				cout << char(179) << " ";
				if (temp[ROWS][COLS] == 'X') {
					SetConsoleTextAttribute(hConsole, 8);
					cout << temp[ROWS][COLS] << " ";
					SetConsoleTextAttribute(hConsole, 15);
				}
				else if (temp[ROWS][COLS] == 'M') {
					SetConsoleTextAttribute(hConsole, 9);
					cout << temp[ROWS][COLS] << " ";
					SetConsoleTextAttribute(hConsole, 15);
				}
				else if (temp[ROWS][COLS] == 'H') {
					SetConsoleTextAttribute(hConsole, 4);
					cout << temp[ROWS][COLS] << " ";
					SetConsoleTextAttribute(hConsole, 15);
				}
				else cout << temp[ROWS][COLS] << " ";
				COLS++;
			}
			ROWS++;
			if (i == 4) {
				if (TEMP == 2) {
					cout << char(179) << "                Hitted Ships: ";
					SetConsoleTextAttribute(hConsole, 4);
					cout << hitted;
					SetConsoleTextAttribute(hConsole, 15);
					cout << "    Missed Ships: ";
					SetConsoleTextAttribute(hConsole, 9);
					cout << missed << "\n  ";
					SetConsoleTextAttribute(hConsole, 15);
				}
				else if (TEMP == 1 || TEMP == 4) {
					cout << char(179) << "                Hitted Ships: ";
					SetConsoleTextAttribute(hConsole, 4);
					cout << hitted;
					SetConsoleTextAttribute(hConsole, 15);
					cout << "    Missed Ships: ";
					SetConsoleTextAttribute(hConsole, 9);
					cout << missed << "\n  ";
					SetConsoleTextAttribute(hConsole, 15);
				}
			}
			else cout << char(179) << endl << "  ";
		}



		if (i % 2 == 1 && i != 19) {
			cout << char(195) << char(196) << char(196) << char(196);
			for (int i = 0; i <= 8; i++) cout << char(197) << char(196) << char(196) << char(196);
			cout << char(180) << endl << letter << " ";
			letter++;
		}

		if (i == 19) {
			cout << char(192) << char(196) << char(196) << char(196);
			for (int i = 0; i <= 8; i++) cout << char(193) << char(196) << char(196) << char(196);
			cout << char(217) << endl << "  ";
		}
	}
}

void Printfplace(char playerplace[][10], char enemyplace[][10]) {

	char temp[10][10];

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			if (TEMP == 1) temp[i][j] = playerplace[i][j];
			else if (TEMP == 2) temp[i][j] = enemyplace[i][j];
		}

	int ROWS = 0, COLS = 0;
	system("CLS");
	cout << "\n\n    1   2   3   4   5   6   7   8   9   10" << endl;
	char letter = 65;
	for (int i = 0; i < 20; i++) {
		if (i == 0) {
			cout << "  " << char(218) << char(196) << char(196) << char(196);
			for (int i = 0; i <= 8; i++) cout << char(194) << char(196) << char(196) << char(196);
			cout << char(191) << "\n" << letter << " ";
			letter++;
		}

		if (i % 2 == 0) {
			COLS = 0;
			for (int j = 0; j < 10; j++) {
				cout << char(179) << " ";
				if (temp[ROWS][COLS] == 'X') {
					SetConsoleTextAttribute(hConsole, 8);
					cout << temp[ROWS][COLS] << " ";
					SetConsoleTextAttribute(hConsole, 15);
				}
				else if (temp[ROWS][COLS] == 'M') {
					SetConsoleTextAttribute(hConsole, 9);
					cout << temp[ROWS][COLS] << " ";
					SetConsoleTextAttribute(hConsole, 15);
				}
				else if (temp[ROWS][COLS] == 'H') {
					SetConsoleTextAttribute(hConsole, 4);
					cout << temp[ROWS][COLS] << " ";
					SetConsoleTextAttribute(hConsole, 15);
				}
				else cout << temp[ROWS][COLS] << " ";
				COLS++;
			}
			ROWS++;
			cout << char(179) << endl << "  ";
		}

		if (i % 2 == 1 && i != 19) {
			cout << char(195) << char(196) << char(196) << char(196);
			for (int i = 0; i <= 8; i++) cout << char(197) << char(196) << char(196) << char(196);
			cout << char(180) << endl << letter << " ";
			letter++;
		}

		if (i == 19) {
			cout << char(192) << char(196) << char(196) << char(196);
			for (int i = 0; i <= 8; i++) cout << char(193) << char(196) << char(196) << char(196);
			cout << char(217) << endl << "  ";
		}
	}
}

int Checkwin(char enemy[][10], char playerplace[][10]) {
	int count = 0, count2 = 0;

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			if (playerplace[i][j] == 'H') count++;
			if (enemy[i][j] == 'H') count2++;
		}

	if (count == 20 || count2 == 20) return 1;
	else return 0;
}

void Manually(char playerplace[][10], char enemyplace[][10]) {

	char temp[10][10];

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			if (TEMP == 1) temp[i][j] = playerplace[i][j];
			else if (TEMP == 2) temp[i][j] = enemyplace[i][j];
		}

	int ROWS, COLS, tmp, answer;
	bool check;
	char letter;
	int ships = 10, size = 4;

	while (ships) {
		tmp = ships;
		check = true;
		if (ships == 10) size = 4;
		else if (ships == 9) size = 3;
		else if (ships == 7) size = 2;
		else if (ships == 4) size = 1;

		Printfplace(playerplace, enemyplace);
		cout << "Ship " << size << "x\n";
		cout << "  Ship begin: (e.g 5g)\n";
		cin >> COLS;
		cin >> letter;

		if (size != 1) {
			cout << "  1.vertical\n  2.horizontal\n  ";
			cin >> answer;
		}
		else answer = 2;

		if (int(letter) >= 65 && int(letter) <= 74) ROWS = int(letter) - 65;
		else if (int(letter) >= 97 && int(letter) <= 106) ROWS = int(letter) - 97;


		COLS--;

		if (answer == 1 && ROWS <= 10 - size) {
			for (int i = -1; i <= size; i++) {
				if (temp[ROWS + i][COLS] == 'X') check = false;
			}
			if (check) {
				if (COLS == 0) {
					for (int i = -1; i <= size; i++) {
						if (temp[ROWS + i][COLS + 1] == 'X') check = false;
					}
				}
				else if (COLS == 9) {
					for (int i = -1; i <= size; i++) {
						if (temp[ROWS + i][COLS - 1] == 'X') check = false;
					}
				}
				else {
					for (int i = -1; i <= size; i++) {
						if (temp[ROWS + i][COLS - 1] == 'X' || temp[ROWS + i][COLS + 1] == 'X') check = false;
					}
				}
			}
			if (check) {
				for (int i = ROWS; i < ROWS + size; i++) temp[i][COLS] = 'X';
				ships--;
			}
		}
		else if (answer == 2 && COLS <= 10 - size) {
			for (int i = 0; i < size; i++) {
				if (temp[ROWS][COLS + i] == 'X') check = false;
			}
			if (check) {
				if (COLS == 0) {
					for (int i = 0; i <= size; i++) {
						if (temp[ROWS + 1][COLS + i] == 'X' || temp[ROWS - 1][COLS + i] == 'X') check = false;
					}
				}
				else if (COLS == 10 - size) {
					for (int i = -1; i < size; i++) {
						if (temp[ROWS + 1][COLS + i] == 'X' || temp[ROWS - 1][COLS + i] == 'X') check = false;
					}
				}
				else {
					for (int i = -1; i <= 1; i++)
						for (int j = -1; j <= size; j++) {
							if (temp[ROWS + i][COLS + j] == 'X') check = false;
						}
				}
			}
			if (check) {
				for (int i = COLS; i < COLS + size; i++) temp[ROWS][i] = 'X';
				ships--;
			}
		}

		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++) {
				if (TEMP == 1) playerplace[i][j] = temp[i][j];
				else if (TEMP == 2) enemyplace[i][j] = temp[i][j];
			}

		if (tmp != ships) Printfplace(playerplace, enemyplace);
		else {
			cout << "\nInvalid Move!\n";
			system("pause");
		}
	}
}

void Randomly(char playerplace[][10], char enemyplace[][10]) {

	char temp[10][10];

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			if (TEMP == 1) temp[i][j] = playerplace[i][j];
			else if (TEMP == 2) temp[i][j] = enemyplace[i][j];
		}

	int ROWS, COLS, answer;
	int ships = 10, size = 4;
	bool check = true;

	while (ships) {

		check = true;
		if (ships == 10) size = 4;
		else if (ships == 9) size = 3;
		else if (ships == 7) size = 2;
		else if (ships == 4) size = 1;

		answer = rand() % 100;
		COLS = rand() % 10;
		ROWS = rand() % 10;

		if (size != 1) {
			if (answer % 2 == 1) answer = 1;
			else answer = 2;
		}
		else answer = 2;
		if (answer == 1 && ROWS <= 10 - size) {
			for (int i = -1; i <= size; i++) {
				if (temp[ROWS + i][COLS] == 'X') check = false;
			}
			if (check) {
				if (COLS == 0) {
					for (int i = -1; i <= size; i++) {
						if (temp[ROWS + i][COLS + 1] == 'X') check = false;
					}
				}
				else if (COLS == 9) {
					for (int i = -1; i <= size; i++) {
						if (temp[ROWS + i][COLS - 1] == 'X') check = false;
					}
				}
				else {
					for (int i = -1; i <= size; i++) {
						if (temp[ROWS + i][COLS - 1] == 'X' || temp[ROWS + i][COLS + 1] == 'X') check = false;
					}
				}
			}
			if (check) {
				for (int i = ROWS; i < ROWS + size; i++) temp[i][COLS] = 'X';
				ships--;
			}
		}
		else if (answer == 2 && COLS <= 10 - size) {
			if (check) {
				if (COLS == 0) {
					for (int i = 0; i <= size; i++) {
						if (temp[ROWS + 1][COLS + i] == 'X' || temp[ROWS - 1][COLS + i] == 'X' || temp[ROWS][COLS + i] == 'X') check = false;
					}
				}
				else if (COLS == 10 - size) {
					for (int i = -1; i < size; i++) {
						if (temp[ROWS + 1][COLS + i] == 'X' || temp[ROWS - 1][COLS + i] == 'X' || temp[ROWS][COLS + i] == 'X') check = false;
					}
				}
				else {
					for (int i = -1; i <= 1; i++)
						for (int j = -1; j <= size; j++) {
							if (temp[ROWS + i][COLS + j] == 'X') check = false;
						}
				}
			}
			if (check) {
				for (int i = COLS; i < COLS + size; i++) temp[ROWS][i] = 'X';
				ships--;
			}
		}
	}

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			if (TEMP == 1) playerplace[i][j] = temp[i][j];
			else if (TEMP == 2) enemyplace[i][j] = temp[i][j];
		}
}

int Adjust(char playerplace[][10], char enemyplace[][10]) {

	char temp[10][10];

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			if (TEMP == 1) temp[i][j] = playerplace[i][j];
			else if (TEMP == 2) temp[i][j] = enemyplace[i][j];
		}

	system("CLS");
	for (int i = 0; i < 10; i++) cout << "\n";
	for (int i = 0; i < 25; i++) cout << "  ";
	cout << "Set random ships\n";
	for (int i = 0; i < 25; i++) cout << "  ";
	cout << "Set manual ships\n";
	for (int i = 0; i < 25; i++) cout << "  ";
	cout << "Show the grid\n";
	for (int i = 0; i < 25; i++) cout << "  ";
	cout << "Clean the grid\n";
	for (int i = 0; i < 25; i++) cout << "  ";
	cout << "Start game\n";
	int answer2;
	cin >> answer2;

	int count = 0;
	if (answer2 == 1) {
		count = 0;
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++) if (temp[i][j] == 'X') count++;
		if (count > 0) {
			cout << "\nPlease clean ships..\n";
			system("pause");
			Adjust(playerplace, enemyplace);
		}
		else {
			Randomly(playerplace, enemyplace);
			Printfplace(playerplace, enemyplace);
			system("pause");
			Adjust(playerplace, enemyplace);
		}
	}
	else if (answer2 == 2) {
		count = 0;
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++) if (temp[i][j] == 'X') count++;
		if (count > 0) {
			cout << "\nPlease clean ships..\n";
			system("pause");
			Adjust(playerplace, enemyplace);
		}
		else {
			Manually(playerplace, enemyplace);
			system("pause");
			Adjust(playerplace, enemyplace);
		}
	}
	else if (answer2 == 3) {
		Printfplace(playerplace, enemyplace);
		system("pause");
		Adjust(playerplace, enemyplace);
	}
	else if (answer2 == 4) {
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++) {
				if (TEMP == 1) playerplace[i][j] = '.';
				else enemyplace[i][j] = '.';
			}
		Printfplace(playerplace, enemyplace);
		system("pause");
		Adjust(playerplace, enemyplace);
	}
	else if (answer2 == 5) {
		count = 0;
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++) if (temp[i][j] == 'X') count++;

		if (count > 0) {
			for (int i = 0; i < 10; i++)
				for (int j = 0; j < 10; j++) {
					if (TEMP == 1) playerplace[i][j] = temp[i][j];
					else if (TEMP == 2) enemyplace[i][j] = temp[i][j];
				}
			return 0;
		}
		else {
			cout << "\nPlease set ships..\n";
			Sleep(2000);
			Adjust(playerplace, enemyplace);
		}
	}
}

int Singleplayer(char player[][10], char enemy[][10], char playerplace[][10], char enemyplace[][10]) {

	cin.ignore(), cin.clear(), fseek, fflush;
	system("CLS");
	for (int i = 0; i < 10; i++) cout << "\n";
	for (int i = 0; i < 25; i++) cout << "  ";
	cout << "Name: ";
	cin.getline(name, 25);

	ofstream LOGS;
	LOGS.open("logs.txt");

	int easy = 1, medium = 2, hard = 3;

	system("CLS");
	for (int i = 0; i < 10; i++) cout << "\n";
	for (int i = 0; i < 25; i++) cout << "  ";
	cout << "Select the difficulty level:\n";
	for (int i = 0; i < 25; i++) cout << "  ";
	cout << "Easy\n";
	for (int i = 0; i < 25; i++) cout << "  ";
	cout << "Medium\n";
	for (int i = 0; i < 25; i++) cout << "  ";
	cout << "Hard\n";

	int answer;
	cin >> answer;

	if (answer == 1) answer = easy;
	else if (answer == 2) answer = medium;
	else if (answer == 3) answer = hard;

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			playerplace[i][j] = '.';
			enemy[i][j] = '.';
		}

	TEMP = 2;
	Randomly(playerplace, enemyplace);
	TEMP = 1;
	Adjust(playerplace, enemyplace);


	int cols, rows = 0;
	char history = '0';
	int ROWS, COLS, control;
	int count = 0, count2 = 1, memory = 0, tmp = 0, tmp2 = 0, c = 0, rule = 1, l = 3;
	char letter;
	ROWS = rand() % 10, COLS = rand() % 10;

	do {
		TEMP = 2;
		control = Checkwin(playerplace, enemy);
		if (rule == 1 && control == 0) {
			Printf(player, enemy, playerplace, enemyplace);
			cout << "\n" << name << ", it's your turn\nEnter the number: v/h (e.g. 4c)\n";
			cin >> cols;
			cin >> letter;
			cols--;


			if (int(letter) >= 65 && int(letter) <= 74) rows = int(letter) - 65;
			else if (int(letter) >= 97 && int(letter) <= 106) rows = int(letter) - 97;

			if (enemy[rows][cols] != '.' || rows >= 10 || cols >= 10) {
				cout << "\nInvalid move..\nPlease wait...";
				Sleep(3000);
			}
			else if (enemyplace[rows][cols] == 'X') {
				enemy[rows][cols] = 'H';
				hitted++;
				Printf(player, enemy, playerplace, enemyplace);
				cout << "\nYou hit!\nPlease wait...";
				Sleep(2000);
			}
			else {
				enemy[rows][cols] = 'M';
				missed++;
				Printf(player, enemy, playerplace, enemyplace);
				cout << "\nYou miss..\nPlease wait...";
				Sleep(3000);
				rule = 2, TEMP = 4;
				Printf(player, enemy, playerplace, enemyplace);
				Sleep(3000);
			}
		}
		else {
			if (answer == easy) {
				if (playerplace[ROWS][COLS] == '.' || playerplace[ROWS][COLS] == 'X') {
					if (playerplace[ROWS][COLS] == 'X') {
						playerplace[ROWS][COLS] = 'H';
						hitted2++;
					}
					else {
						playerplace[ROWS][COLS] = 'M';
						missed2++;
						rule = 1;
					}
				}
				else {
					ROWS = rand() % 10, COLS = rand() % 10;
				}
				count = 0;
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 10; j++) {
						if (playerplace[i][j] == 'M' || playerplace[ROWS][COLS] == 'H') count++;
					}
				}
				if (count == count2) {
					count2++;
					TEMP = 4;
					Printf(player, enemy, playerplace, enemyplace);
					Sleep(3000);
				}
			}
			else if (answer == medium) {
				if (history == '0') {
					if (playerplace[ROWS][COLS] == 'X' || playerplace[ROWS][COLS] == '.') {
						if (playerplace[ROWS][COLS] == 'X') {
							playerplace[ROWS][COLS] = 'H';
							hitted2++;
							memory = 1;
							history = 'X';
						}
						else {
							playerplace[ROWS][COLS] = 'M';
							missed2++;
							rule = 1;
						}
					}
					else {
						ROWS = rand() % 10, COLS = rand() % 10;
					}
				}
				else if (history == 'X') {
					if (memory == 1) {
						if (ROWS != 9) {
							if (playerplace[ROWS + 1][COLS] == 'X' || playerplace[ROWS + 1][COLS] == '.') {
								ROWS++;
								if (playerplace[ROWS][COLS] == 'X') {
									playerplace[ROWS][COLS] = 'H';
									hitted2++;
									history = '0';
								}
								else {
									playerplace[ROWS][COLS] = 'M';
									missed2++;
									memory = 2, rule = 1;
									ROWS--;
								}
							}
							else memory = 2;
						}
						else memory = 2;
					}
					else if (memory == 2) {
						if (ROWS != 0) {
							if (playerplace[ROWS - 1][COLS] == 'X' || playerplace[ROWS - 1][COLS] == '.') {
								ROWS--;
								if (playerplace[ROWS][COLS] == 'X') {
									playerplace[ROWS][COLS] = 'H';
									hitted2++;
									history = '0';
								}
								else {
									playerplace[ROWS][COLS] = 'M';
									missed2++;
									memory = 3, rule = 1;
									ROWS++;
								}
							}
							else memory = 3;
						}
						else memory = 3;
					}
					else if (memory == 3) {
						if (COLS != 9) {
							if (playerplace[ROWS][COLS + 1] == 'X' || playerplace[ROWS][COLS + 1] == '.') {
								COLS++;
								if (playerplace[ROWS][COLS] == 'X') {
									playerplace[ROWS][COLS] = 'H';
									hitted2++;
									history = '0';
								}
								else {
									playerplace[ROWS][COLS] = 'M';
									missed++;
									memory = 4, rule = 1;
									COLS--;
								}
							}
							else memory = 4;
						}
						else memory = 4;
					}
					else if (memory == 4) {
						if (COLS != 0) {
							if (player[ROWS][COLS - 1] == 'X' || player[ROWS][COLS - 1] == '.') {
								COLS--;
								if (playerplace[ROWS][COLS] == 'X') {
									playerplace[ROWS][COLS] = 'H';
									hitted2++;
									history = '0';
								}
								else {
									playerplace[ROWS][COLS] = 'M';
									missed2++;
									memory = 0, rule = 1;
									history = ' ';
								}
							}
							else {
								memory = 0;
								history = '0';
							}
						}
						else {
							memory = 0;
							history = '0';
						}
					}
				}
				else {
					ROWS = rand() % 10, COLS = rand() % 10;
					history = '0';
				}

				count = 0;
				for (int i = 0; i < 10; i++)
					for (int j = 0; j < 10; j++)
						if (playerplace[i][j] == 'M' || playerplace[i][j] == 'H') count++;

				if (count == count2) {
					TEMP = 4;
					count2++;
					Printf(player, enemy, playerplace, enemyplace);
					Sleep(3000);
				}

			}
			else if (answer == hard) {
				if (c == 5 && history != 'X') {
					do {
						ROWS = rand() % 10, COLS = rand() % 10;
					} while (playerplace[ROWS][COLS] != 'X');
				}

				if (history == '0') {
					if (COLS != 9 && COLS != 0 && playerplace[ROWS + 1][COLS] != 'H' && playerplace[ROWS + 1][COLS + 1] != 'H' &&
						playerplace[ROWS + 1][COLS - 1] != 'H' && playerplace[ROWS - 1][COLS] != 'H' && playerplace[ROWS - 1][COLS + 1] != 'H' &&
						playerplace[ROWS - 1][COLS - 1] != 'H' && playerplace[ROWS][COLS + 1] != 'H' && playerplace[ROWS][COLS - 1] != 'H') {
						if (playerplace[ROWS][COLS] == 'X' || playerplace[ROWS][COLS] == '.') {
							if (playerplace[ROWS][COLS] == 'X') {
								playerplace[ROWS][COLS] = 'H';
								hitted2++;
								history = 'X';
								memory = 1;
								c = 0;
							}
							else {
								playerplace[ROWS][COLS] = 'M';
								missed2++, c++;
								rule = 1;
							}
						}
						else {
							ROWS = rand() % 10, COLS = rand() % 10;
						}
					}

					else if (COLS == 9 && playerplace[ROWS + 1][COLS] != 'H' && playerplace[ROWS + 1][COLS - 1] != 'H' &&
						playerplace[ROWS - 1][COLS] != 'H' && playerplace[ROWS - 1][COLS - 1] != 'H' && playerplace[ROWS][COLS - 1] != 'H') {
						if (playerplace[ROWS][COLS] == 'X' || playerplace[ROWS][COLS] == '.') {
							if (playerplace[ROWS][COLS] == 'X') {
								playerplace[ROWS][COLS] = 'H';
								hitted2++;
								history = 'X';
								memory = 1;
								c = 0;
							}
							else {
								playerplace[ROWS][COLS] = 'M';
								missed2++, c++;
								rule = 1;
							}
						}
						else {
							ROWS = rand() % 10, COLS = rand() % 10;
						}
					}

					else if (COLS == 0 && playerplace[ROWS + 1][COLS] != 'H' && playerplace[ROWS + 1][COLS + 1] != 'H' &&
						playerplace[ROWS - 1][COLS] != 'H' && playerplace[ROWS - 1][COLS + 1] != 'H' && playerplace[ROWS][COLS + 1] != 'H') {
						if (playerplace[ROWS][COLS] == 'X' || playerplace[ROWS][COLS] == '.') {
							if (playerplace[ROWS][COLS] == 'X') {
								playerplace[ROWS][COLS] = 'H';
								hitted2++;
								history = 'X';
								memory = 1;
								c = 0;
							}
							else {
								playerplace[ROWS][COLS] = 'M';
								missed2++, c++;
								rule = 1;
							}
						}
						else {
							ROWS = rand() % 10, COLS = rand() % 10;
						}
					}
					else ROWS = rand() % 10, COLS = rand() % 10;
				}

				else if (history == 'X') {
					if (tmp == l || tmp2 == l) {
						memory = 0;
						l = 2;
					}

					if (memory == 1) {
						if (ROWS != 9) {
							if (playerplace[ROWS + 1][COLS] == 'X' || playerplace[ROWS + 1][COLS] == '.') {
								ROWS++;
								if (playerplace[ROWS][COLS] == 'X') {
									playerplace[ROWS][COLS] = 'H';
									tmp++, hitted2++;
								}
								else {
									playerplace[ROWS][COLS] = 'M';
									missed2++;
									memory = 2, rule = 1;
									ROWS -= (tmp + 1);
								}
							}
							else {
								memory = 2;
								ROWS -= tmp;
							}
						}
						else {
							memory = 2;
							ROWS -= tmp;
						}
					}

					else if (memory == 2) {
						if (playerplace[ROWS - 1][COLS] == 'X' || playerplace[ROWS - 1][COLS] == '.') {
							ROWS--;
							if (playerplace[ROWS][COLS] == 'X') {
								playerplace[ROWS][COLS] = 'H';
								tmp++, hitted2++;
							}
							else {
								playerplace[ROWS][COLS] = 'M';
								missed2++;
								rule = 1;
								if (tmp == 0) {
									memory = 3;
									ROWS++;
								}
								else memory = 0;
							}
						}
						else memory = 3;
					}
					else if (memory == 3 && tmp == 0) {
						if (COLS != 9) {
							if (playerplace[ROWS][COLS + 1] == 'X' || playerplace[ROWS][COLS + 1] == '.') {
								COLS++;
								if (playerplace[ROWS][COLS] == 'X') {
									playerplace[ROWS][COLS] = 'H';
									tmp2++, hitted2++;
								}
								else {
									playerplace[ROWS][COLS] = 'M';
									missed2++;
									rule = 1, memory = 4;
									COLS -= (tmp2 + 1);
								}
							}
							else {
								memory = 4;
								COLS -= tmp2;
							}
						}
						else {
							memory = 4;
							COLS -= tmp2;
						}
					}
					else if (memory == 4 && tmp == 0) {
						if (COLS != 0) {
							if (playerplace[ROWS][COLS - 1] == 'X' || playerplace[ROWS][COLS - 1] == '.') {
								COLS--;
								if (playerplace[ROWS][COLS] == 'X') {
									playerplace[ROWS][COLS] = 'H';
									tmp2++, hitted2++;
								}
								else {
									playerplace[ROWS][COLS] = 'M';
									missed2++;
									rule = 1, memory = 0;
									tmp = 0, tmp2 = 0;
									history = '0';
								}
							}
							else {
								tmp = 0, tmp2 = 0;
								history = '0';
							}
						}
						else {
							tmp = 0, tmp2 = 0;
							history = '0';
						}
					}
					else {
						tmp = 0, tmp2 = 0;
						history = '0';
					}
				}
				else {
					ROWS = rand() % 10, COLS = rand() % 10;
					tmp = 0, tmp2 = 0, memory = 0;
					history = '0';
				}

				count = 0;
				for (int i = 0; i < 10; i++)
					for (int j = 0; j < 10; j++) if (playerplace[i][j] == 'M' || playerplace[i][j] == 'H') count++;

				if (count == count2) {
					TEMP = 4;
					count2++;
					Printf(player, enemy, playerplace, enemyplace);
					Sleep(3000);
				}
			}
		}
		control = Checkwin(playerplace, enemy);
	} while (control == 0);

	LOGS << "PLAYER: " << name;
	LOGS << "\nHitted Ships: " << hitted;
	LOGS << "\nMissed Ships: " << missed;
	if (rule == 1) {
		LOGS << "\nWIN\n\n";
		cout << "\n" << name << ", you won the game!";
	}
	else LOGS << "\nLOST\n\n";

	LOGS << "Enemy: ";
	LOGS << "\nHitted Ships: " << hitted2;
	LOGS << "\nMissed Ships: " << missed2;
	if (rule == 2) {
		LOGS << "\nWIN\n\n";
		cout << "\n" << "Enemy won the game!";
	}
	else LOGS << "\nLOST\n\n";
	LOGS.close();
	Sleep(5000);
	return 0;
}

int Multiplayer(char player[][10], char enemy[][10], char playerplace[][10], char enemyplace[][10]) {

	int control;
	system("CLS");
	cin.ignore(), cin.clear(), fseek, fflush;
	for (int i = 0; i < 10; i++) cout << "\n";
	for (int i = 0; i < 25; i++) cout << "  ";
	cout << "(Player 1) Name: ";
	cin.getline(name, 25);
	system("CLS");
	for (int i = 0; i < 10; i++) cout << "\n";
	for (int i = 0; i < 25; i++) cout << "  ";
	cout << "(Player 2) Name: ";
	cin.clear(), fseek, fflush;
	cin.getline(name2, 25);

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			enemy[i][j] = '.';
			player[i][j] = '.';
		}

	TEMP = 1;
	Adjust(playerplace, enemyplace);
	TEMP = 2;
	Adjust(playerplace, enemyplace);
	int COLS, ROWS = 0;
	char letter;
	int rule = 1;
	ofstream LOGS;
	LOGS.open("logs.txt");

	do {
		control = Checkwin(playerplace, enemy);
		if (rule == 1 && control == 0) {
			TEMP = 2;
			Printf(player, enemy, playerplace, enemyplace);
			cout << "\n" << name << ", it's your turn\nEnter the number: v/h (e.g. 4c)\n";
			cin >> COLS;
			cin >> letter;
			COLS--;
			if (int(letter) >= 65 && int(letter) <= 74) ROWS = int(letter) - 65;
			else if (int(letter) >= 97 && int(letter) <= 106) ROWS = int(letter) - 97;
			if (enemy[ROWS][COLS] == 'M' || enemy[ROWS][COLS] == 'H' || ROWS >= 10 || COLS >= 10) {
				cout << "\nInvalid move..\n";
				Sleep(3000);
			}
			else if (enemyplace[ROWS][COLS] == 'X') {
				enemy[ROWS][COLS] = 'H';
				hitted++;
				Printf(player, enemy, playerplace, enemyplace);
				cout << "\nYou Hit..\n";
				Sleep(3000);
			}
			else {
				enemy[ROWS][COLS] = 'M';
				missed++;
				rule = 2;
				Printf(player, enemy, playerplace, enemyplace);
				cout << "\nYou miss..\n";
				Sleep(3000);
			}
		}
		else {
			TEMP = 1;
			Printf(player, enemy, playerplace, enemyplace);
			cout << "\n" << name2 << ", it's your turn\nEnter the number: v/h (e.g. 4c)\n";
			cin >> COLS;
			cin >> letter;
			COLS--;
			if (int(letter) >= 65 && int(letter) <= 74) ROWS = int(letter) - 65;
			else if (int(letter) >= 97 && int(letter) <= 106) ROWS = int(letter) - 97;
			if (player[ROWS][COLS] == 'M' || player[ROWS][COLS] == 'H' || ROWS >= 10 || COLS >= 10) {
				cout << "\nInvalid move..\n";
				Sleep(3000);
			}
			else if (playerplace[ROWS][COLS] == 'X') {
				player[ROWS][COLS] = 'H';
				hitted2++;
				Printf(player, enemy, playerplace, enemyplace);
				cout << "\nYou hit..\n";
				Sleep(3000);
			}
			else {
				player[ROWS][COLS] = 'M';
				missed2++;
				rule = 1;
				Printf(player, enemy, playerplace, enemyplace);
				cout << "\nYou miss..\n";
				Sleep(3000);
			}
		}
		control = Checkwin(playerplace, enemy);
	} while (control == 0);

	LOGS << "PLAYER1: " << name;
	LOGS << "\nHitted Ships: " << hitted;
	LOGS << "\nMissed Ships: " << missed;
	if (rule == 1) {
		LOGS << "\nWIN\n\n";
		cout << name << ", you won the game!";
	}
	else LOGS << "\nLOST\n\n";

	LOGS << "PLAYER2: " << name2;
	LOGS << "\nHitted Ships: " << hitted2;
	LOGS << "\nMissed Ships: " << missed2;
	if (rule == 2) {
		LOGS << "\nWIN\n\n";
		cout << name2 << ", you won the game!";
	}
	else LOGS << "\nLOST\n\n";

	LOGS.close();
	return 0;
}

int main() {

	srand(time(NULL));

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

	char player[10][10], enemy[10][10], playerplace[10][10], enemyplace[10][10];
	char str[20] = "Battleship..";

	for (int i = 0; i < 10; i++) cout << "\n";
	for (int i = 0; i < 25; i++) cout << "  ";
	for (int i = 0; str[i] != '\0'; i++) {
		cout << str[i];
		Sleep(100);
	}
	Sleep(1000);

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			playerplace[i][j] = '.';
			enemyplace[i][j] = '.';
		}

	system("CLS");
	for (int i = 0; i < 10; i++) cout << "\n";
	for (int i = 0; i < 25; i++) cout << "  ";
	cout << "Singleplayer\n";
	for (int i = 0; i < 25; i++) cout << "  ";
	cout << "Multiplayer\n";
	for (int i = 0; i < 25; i++) cout << "  ";
	cout << "Quit game\n";

	int answer;
	cin >> answer;
	if (answer == 1) Singleplayer(player, enemy, playerplace, enemyplace);
	else if (answer == 2) Multiplayer(player, enemy, playerplace, enemyplace);
	else if (answer == 3) return 0;
	else cin >> answer;

	return 0;
}