#include <iostream>
#include <Windows.h>
#include <fstream>
#include <time.h>
using namespace std;

int TEMP;
char name[25];
char name2[25];
HANDLE  h_console;
int hitted = 0, hitted2 = 0, missed = 0, missed2 = 0;

void printF(char player[][10], char enemy[][10], char player_place[][10], char enemy_place[][10]) {

	char temp[10][10];

	for (auto i = 0; i < 10; i++)
		for (auto j = 0; j < 10; j++) {
			if (TEMP == 1) temp[i][j] = player[i][j];
			else if (TEMP == 2) temp[i][j] = enemy[i][j];
			else if (TEMP == 4) temp[i][j] = player_place[i][j];
			else if (TEMP == 5) temp[i][j] = enemy_place[i][j];
		}

	auto rows = 0, cols = 0;
	system("CLS");
	cout << "\n\n    1   2   3   4   5   6   7   8   9   10" << endl;
	char letter = 65;
	for (auto i = 0; i < 20; i++) {
		if (i == 0) {
			cout << "  " << static_cast<char>(218) << static_cast<char>(196) << static_cast<char>(196) << static_cast<char>(196);
			for (auto i = 0; i <= 8; i++) cout << static_cast<char>(194) << static_cast<char>(196) << static_cast<char>(196) << static_cast<char>(196);
			cout << static_cast<char>(191) << "\n" << letter << " ";
			letter++;
		}

		if (i % 2 == 0) {
			cols = 0;
			for (auto j = 0; j < 10; j++) {
				cout << static_cast<char>(179) << " ";
				if (temp[rows][cols] == 'X') {
					SetConsoleTextAttribute(h_console, 8);
					cout << temp[rows][cols] << " ";
					SetConsoleTextAttribute(h_console, 15);
				}
				else if (temp[rows][cols] == 'M') {
					SetConsoleTextAttribute(h_console, 9);
					cout << temp[rows][cols] << " ";
					SetConsoleTextAttribute(h_console, 15);
				}
				else if (temp[rows][cols] == 'H') {
					SetConsoleTextAttribute(h_console, 4);
					cout << temp[rows][cols] << " ";
					SetConsoleTextAttribute(h_console, 15);
				}
				else cout << temp[rows][cols] << " ";
				cols++;
			}
			rows++;
			if (i == 4) {
				if (TEMP == 2) {
					cout << static_cast<char>(179) << "                Hitted Ships: ";
					SetConsoleTextAttribute(h_console, 4);
					cout << hitted;
					SetConsoleTextAttribute(h_console, 15);
					cout << "    Missed Ships: ";
					SetConsoleTextAttribute(h_console, 9);
					cout << missed << "\n  ";
					SetConsoleTextAttribute(h_console, 15);
				}
				else if (TEMP == 1 || TEMP == 4) {
					cout << static_cast<char>(179) << "                Hitted Ships: ";
					SetConsoleTextAttribute(h_console, 4);
					cout << hitted2;
					SetConsoleTextAttribute(h_console, 15);
					cout << "    Missed Ships: ";
					SetConsoleTextAttribute(h_console, 9);
					cout << missed2 << "\n  ";
					SetConsoleTextAttribute(h_console, 15);
				}
			}
			else cout << static_cast<char>(179) << endl << "  ";
		}



		if (i % 2 == 1 && i != 19) {
			cout << static_cast<char>(195) << static_cast<char>(196) << static_cast<char>(196) << static_cast<char>(196);
			for (auto i = 0; i <= 8; i++) cout << static_cast<char>(197) << static_cast<char>(196) << static_cast<char>(196) << static_cast<char>(196);
			cout << static_cast<char>(180) << endl << letter << " ";
			letter++;
		}

		if (i == 19) {
			cout << static_cast<char>(192) << static_cast<char>(196) << static_cast<char>(196) << static_cast<char>(196);
			for (auto i = 0; i <= 8; i++) cout << static_cast<char>(193) << static_cast<char>(196) << static_cast<char>(196) << static_cast<char>(196);
			cout << static_cast<char>(217) << endl << "  ";
		}
	}
}

void print_f_place(char player_place[][10], char enemy_place[][10]) {

	char temp[10][10];

	for (auto i = 0; i < 10; i++)
		for (auto j = 0; j < 10; j++) {
			if (TEMP == 1) temp[i][j] = player_place[i][j];
			else if (TEMP == 2) temp[i][j] = enemy_place[i][j];
		}

	auto ROWS = 0, COLS = 0;
	system("CLS");
	cout << "\n\n    1   2   3   4   5   6   7   8   9   10" << endl;
	char letter = 65;
	for (auto i = 0; i < 20; i++) {
		if (i == 0) {
			cout << "  " << static_cast<char>(218) << static_cast<char>(196) << static_cast<char>(196) << static_cast<char>(196);
			for (auto i = 0; i <= 8; i++) cout << static_cast<char>(194) << static_cast<char>(196) << static_cast<char>(196) << static_cast<char>(196);
			cout << static_cast<char>(191) << "\n" << letter << " ";
			letter++;
		}

		if (i % 2 == 0) {
			COLS = 0;
			for (auto j = 0; j < 10; j++) {
				cout << static_cast<char>(179) << " ";
				if (temp[ROWS][COLS] == 'X') {
					SetConsoleTextAttribute(h_console, 8);
					cout << temp[ROWS][COLS] << " ";
					SetConsoleTextAttribute(h_console, 15);
				}
				else if (temp[ROWS][COLS] == 'M') {
					SetConsoleTextAttribute(h_console, 9);
					cout << temp[ROWS][COLS] << " ";
					SetConsoleTextAttribute(h_console, 15);
				}
				else if (temp[ROWS][COLS] == 'H') {
					SetConsoleTextAttribute(h_console, 4);
					cout << temp[ROWS][COLS] << " ";
					SetConsoleTextAttribute(h_console, 15);
				}
				else cout << temp[ROWS][COLS] << " ";
				COLS++;
			}
			ROWS++;
			cout << static_cast<char>(179) << endl << "  ";
		}

		if (i % 2 == 1 && i != 19) {
			cout << static_cast<char>(195) << static_cast<char>(196) << static_cast<char>(196) << static_cast<char>(196);
			for (auto i = 0; i <= 8; i++) cout << static_cast<char>(197) << static_cast<char>(196) << static_cast<char>(196) << static_cast<char>(196);
			cout << static_cast<char>(180) << endl << letter << " ";
			letter++;
		}

		if (i == 19) {
			cout << static_cast<char>(192) << static_cast<char>(196) << static_cast<char>(196) << static_cast<char>(196);
			for (auto i = 0; i <= 8; i++) cout << static_cast<char>(193) << static_cast<char>(196) << static_cast<char>(196) << static_cast<char>(196);
			cout << static_cast<char>(217) << endl << "  ";
		}
	}
}

int check_win(char enemy[][10], char player_place[][10]) {
	auto count = 0, count2 = 0;

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			if (player_place[i][j] == 'H') count++;
			if (enemy[i][j] == 'H') count2++;
		}

	if (count == 20 || count2 == 20) return 1;
	else return 0;
}

void manually(char player_place[][10], char enemy_place[][10]) {

	char temp[10][10];

	for (auto i = 0; i < 10; i++)
		for (auto j = 0; j < 10; j++) {
			if (TEMP == 1) temp[i][j] = player_place[i][j];
			else if (TEMP == 2) temp[i][j] = enemy_place[i][j];
		}

	int rows = 0, COLS, answer;
	char letter;
	auto ships = 10, size = 4;

	while (ships) {
		auto tmp = ships;
		auto check = true;
		if (ships == 10) size = 4;
		else if (ships == 9) size = 3;
		else if (ships == 7) size = 2;
		else if (ships == 4) size = 1;

		print_f_place(player_place, enemy_place);
		cout << "Ship " << size << "x\n";
		cout << "  Ship begin: (e.g 5g)\n";
		cin >> COLS;
		cin >> letter;

		if (size != 1) {
			cout << "  1.vertical\n  2.horizontal\n  ";
			cin >> answer;
		}
		else answer = 2;

		if (static_cast<int>(letter) >= 65 && static_cast<int>(letter) <= 74) rows = static_cast<int>(letter) - 65;
		else if (static_cast<int>(letter) >= 97 && static_cast<int>(letter) <= 106) rows = static_cast<int>(letter) - 97;


		COLS--;

		if (answer == 1 && rows <= 10 - size) {
			for (auto i = -1; i <= size; i++) {
				if (temp[rows + i][COLS] == 'X') check = false;
			}
			if (check) {
				if (COLS == 0) {
					for (auto i = -1; i <= size; i++) {
						if (temp[rows + i][COLS + 1] == 'X') check = false;
					}
				}
				else if (COLS == 9) {
					for (auto i = -1; i <= size; i++) {
						if (temp[rows + i][COLS - 1] == 'X') check = false;
					}
				}
				else {
					for (auto i = -1; i <= size; i++) {
						if (temp[rows + i][COLS - 1] == 'X' || temp[rows + i][COLS + 1] == 'X') check = false;
					}
				}
			}
			if (check) {
				for (auto i = rows; i < rows + size; i++) temp[i][COLS] = 'X';
				ships--;
			}
		}
		else if (answer == 2 && COLS <= 10 - size) {
			for (auto i = 0; i < size; i++) {
				if (temp[rows][COLS + i] == 'X') check = false;
			}
			if (check) {
				if (COLS == 0) {
					for (auto i = 0; i <= size; i++) {
						if (temp[rows + 1][COLS + i] == 'X' || temp[rows - 1][COLS + i] == 'X') check = false;
					}
				}
				else if (COLS == 10 - size) {
					for (auto i = -1; i < size; i++) {
						if (temp[rows + 1][COLS + i] == 'X' || temp[rows - 1][COLS + i] == 'X') check = false;
					}
				}
				else {
					for (auto i = -1; i <= 1; i++)
						for (auto j = -1; j <= size; j++) {
							if (temp[rows + i][COLS + j] == 'X') check = false;
						}
				}
			}
			if (check) {
				for (auto i = COLS; i < COLS + size; i++) temp[rows][i] = 'X';
				ships--;
			}
		}

		for (auto i = 0; i < 10; i++)
			for (auto j = 0; j < 10; j++) {
				if (TEMP == 1) player_place[i][j] = temp[i][j];
				else if (TEMP == 2) enemy_place[i][j] = temp[i][j];
			}

		if (tmp != ships) print_f_place(player_place, enemy_place);
		else {
			cout << "\nInvalid Move!\n";
			system("pause");
		}
	}
}

void randomly(char player_place[][10], char enemy_place[][10]) {

	char temp[10][10];

	for (auto i = 0; i < 10; i++)
		for (auto j = 0; j < 10; j++) {
			if (TEMP == 1) temp[i][j] = player_place[i][j];
			else if (TEMP == 2) temp[i][j] = enemy_place[i][j];
		}

	auto ships = 10, size = 4;
	auto check = true;

	while (ships) {

		check = true;
		if (ships == 10) size = 4;
		else if (ships == 9) size = 3;
		else if (ships == 7) size = 2;
		else if (ships == 4) size = 1;

		auto answer = rand() % 100;
		const auto cols = rand() % 10;
		const auto rows = rand() % 10;

		if (size != 1) {
			if (answer % 2 == 1) answer = 1;
			else answer = 2;
		}
		else answer = 2;
		if (answer == 1 && rows <= 10 - size) {
			for (auto i = -1; i <= size; i++) {
				if (temp[rows + i][cols] == 'X') check = false;
			}
			if (check) {
				if (cols == 0) {
					for (auto i = -1; i <= size; i++) {
						if (temp[rows + i][cols + 1] == 'X') check = false;
					}
				}
				else if (cols == 9) {
					for (auto i = -1; i <= size; i++) {
						if (temp[rows + i][cols - 1] == 'X') check = false;
					}
				}
				else {
					for (auto i = -1; i <= size; i++) {
						if (temp[rows + i][cols - 1] == 'X' || temp[rows + i][cols + 1] == 'X') check = false;
					}
				}
			}
			if (check) {
				for (auto i = rows; i < rows + size; i++) temp[i][cols] = 'X';
				ships--;
			}
		}
		else if (answer == 2 && cols <= 10 - size) {
			if (check) {
				if (cols == 0) {
					for (auto i = 0; i <= size; i++) {
						if (temp[rows + 1][cols + i] == 'X' || temp[rows - 1][cols + i] == 'X' || temp[rows][cols + i] == 'X') check = false;
					}
				}
				else if (cols == 10 - size) {
					for (auto i = -1; i < size; i++) {
						if (temp[rows + 1][cols + i] == 'X' || temp[rows - 1][cols + i] == 'X' || temp[rows][cols + i] == 'X') check = false;
					}
				}
				else {
					for (auto i = -1; i <= 1; i++)
						for (auto j = -1; j <= size; j++) {
							if (temp[rows + i][cols + j] == 'X') check = false;
						}
				}
			}
			if (check) {
				for (auto i = cols; i < cols + size; i++) temp[rows][i] = 'X';
				ships--;
			}
		}
	}

	for (auto i = 0; i < 10; i++)
		for (auto j = 0; j < 10; j++) {
			if (TEMP == 1) player_place[i][j] = temp[i][j];
			else if (TEMP == 2) enemy_place[i][j] = temp[i][j];
		}
}

int adjust(char player_place[][10], char enemy_place[][10]) {

	char temp[10][10];

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			if (TEMP == 1) temp[i][j] = player_place[i][j];
			else if (TEMP == 2) temp[i][j] = enemy_place[i][j];
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

	auto count = 0;
	if (answer2 == 1) {
		count = 0;
		for (auto& i : temp)
			for (auto j = 0; j < 10; j++) if (i[j] == 'X') count++;
		if (count > 0) {
			cout << "\nPlease clean ships..\n";
			system("pause");
			adjust(player_place, enemy_place);
		}
		else {
			randomly(player_place, enemy_place);
			print_f_place(player_place, enemy_place);
			system("pause");
			adjust(player_place, enemy_place);
		}
	}
	else if (answer2 == 2) {
		count = 0;
		for (auto& i : temp)
			for (auto j = 0; j < 10; j++) if (i[j] == 'X') count++;
		if (count > 0) {
			cout << "\nPlease clean ships..\n";
			system("pause");
			adjust(player_place, enemy_place);
		}
		else {
			manually(player_place, enemy_place);
			system("pause");
			adjust(player_place, enemy_place);
		}
	}
	else if (answer2 == 3) {
		print_f_place(player_place, enemy_place);
		system("pause");
		adjust(player_place, enemy_place);
	}
	else if (answer2 == 4) {
		for (auto i = 0; i < 10; i++)
			for (auto j = 0; j < 10; j++) {
				if (TEMP == 1) player_place[i][j] = '.';
				else enemy_place[i][j] = '.';
			}
		print_f_place(player_place, enemy_place);
		system("pause");
		adjust(player_place, enemy_place);
	}
	else if (answer2 == 5) {
		count = 0;
		for (auto& i : temp)
			for (auto j = 0; j < 10; j++) if (i[j] == 'X') count++;

		if (count > 0) {
			for (auto i = 0; i < 10; i++)
				for (auto j = 0; j < 10; j++) {
					if (TEMP == 1) player_place[i][j] = temp[i][j];
					else if (TEMP == 2) enemy_place[i][j] = temp[i][j];
				}
			return 0;
		}
		else {
			cout << "\nPlease set ships..\n";
			Sleep(2000);
			adjust(player_place, enemy_place);
		}
	}
	return 0;
}

auto single_player(char player[][10], char enemy[][10], char player_place[][10], char enemy_place[][10]) -> int
{

	cin.ignore(), cin.clear(), fseek, fflush;
	system("CLS");
	for (int i = 0; i < 10; i++) cout << "\n";
	for (int i = 0; i < 25; i++) cout << "  ";
	cout << "Name: ";
	cin.getline(name, 25);

	ofstream LOGS;
	LOGS.open("logs.txt");

	auto easy = 1, medium = 2, hard = 3;

	system("CLS");
	for (auto i = 0; i < 10; i++) cout << "\n";
	for (auto i = 0; i < 25; i++) cout << "  ";
	cout << "Select the difficulty level:\n";
	for (auto i = 0; i < 25; i++) cout << "  ";
	cout << "Easy\n";
	for (auto i = 0; i < 25; i++) cout << "  ";
	cout << "Medium\n";
	for (auto i = 0; i < 25; i++) cout << "  ";
	cout << "Hard\n";

	int answer;
	cin >> answer;

	if (answer == 1) answer = easy;
	else if (answer == 2) answer = medium;
	else if (answer == 3) answer = hard;

	for (auto i = 0; i < 10; i++)
		for (auto j = 0; j < 10; j++) {
			player_place[i][j] = '.';
			enemy[i][j] = '.';
		}

	TEMP = 2;
	randomly(player_place, enemy_place);
	TEMP = 1;
	adjust(player_place, enemy_place);


	int cols, rows = 0;
	auto history = '0';
	int ROWS, COLS, control;
	auto count = 0, count2 = 1, memory = 0, tmp = 0, tmp2 = 0, c = 0, rule = 1, l = 3;
	char letter;
	ROWS = rand() % 10, COLS = rand() % 10;

	do {
		TEMP = 2;
		control = check_win(player_place, enemy);
		if (rule == 1 && control == 0) {
			printF(player, enemy, player_place, enemy_place);
			cout << "\n" << name << ", it's your turn\nEnter the number: v/h (e.g. 4c)\n";
			cin >> cols;
			cin >> letter;
			cols--;


			if (static_cast<int>(letter) >= 65 && static_cast<int>(letter) <= 74) rows = static_cast<int>(letter) - 65;
			else if (static_cast<int>(letter) >= 97 && static_cast<int>(letter) <= 106) rows = static_cast<int>(letter) - 97;

			if (enemy[rows][cols] != '.' || rows >= 10 || cols >= 10) {
				cout << "\nInvalid move..\nPlease wait...";
				Sleep(3000);
			}
			else if (enemy_place[rows][cols] == 'X') {
				enemy[rows][cols] = 'H';
				hitted++;
				printF(player, enemy, player_place, enemy_place);
				cout << "\nYou hit!\nPlease wait...";
				Sleep(2000);
			}
			else {
				enemy[rows][cols] = 'M';
				missed++;
				printF(player, enemy, player_place, enemy_place);
				cout << "\nYou miss..\nPlease wait...";
				Sleep(3000);
				rule = 2, TEMP = 4;
				printF(player, enemy, player_place, enemy_place);
				Sleep(3000);
			}
		}
		else {
			if (answer == easy) {
				if (player_place[ROWS][COLS] == '.' || player_place[ROWS][COLS] == 'X') {
					if (player_place[ROWS][COLS] == 'X') {
						player_place[ROWS][COLS] = 'H';
						hitted2++;
					}
					else {
						player_place[ROWS][COLS] = 'M';
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
						if (player_place[i][j] == 'M' || player_place[ROWS][COLS] == 'H') count++;
					}
				}
				if (count == count2) {
					count2++;
					TEMP = 4;
					printF(player, enemy, player_place, enemy_place);
					Sleep(3000);
				}
			}
			else if (answer == medium) {
				if (history == '0') {
					if (player_place[ROWS][COLS] == 'X' || player_place[ROWS][COLS] == '.') {
						if (player_place[ROWS][COLS] == 'X') {
							player_place[ROWS][COLS] = 'H';
							hitted2++;
							memory = 1;
							history = 'X';
						}
						else {
							player_place[ROWS][COLS] = 'M';
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
							if (player_place[ROWS + 1][COLS] == 'X' || player_place[ROWS + 1][COLS] == '.') {
								ROWS++;
								if (player_place[ROWS][COLS] == 'X') {
									player_place[ROWS][COLS] = 'H';
									hitted2++;
									history = '0';
								}
								else {
									player_place[ROWS][COLS] = 'M';
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
							if (player_place[ROWS - 1][COLS] == 'X' || player_place[ROWS - 1][COLS] == '.') {
								ROWS--;
								if (player_place[ROWS][COLS] == 'X') {
									player_place[ROWS][COLS] = 'H';
									hitted2++;
									history = '0';
								}
								else {
									player_place[ROWS][COLS] = 'M';
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
							if (player_place[ROWS][COLS + 1] == 'X' || player_place[ROWS][COLS + 1] == '.') {
								COLS++;
								if (player_place[ROWS][COLS] == 'X') {
									player_place[ROWS][COLS] = 'H';
									hitted2++;
									history = '0';
								}
								else {
									player_place[ROWS][COLS] = 'M';
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
								if (player_place[ROWS][COLS] == 'X') {
									player_place[ROWS][COLS] = 'H';
									hitted2++;
									history = '0';
								}
								else {
									player_place[ROWS][COLS] = 'M';
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
				for (auto i = 0; i < 10; i++)
					for (auto j = 0; j < 10; j++)
						if (player_place[i][j] == 'M' || player_place[i][j] == 'H') count++;

				if (count == count2) {
					TEMP = 4;
					count2++;
					printF(player, enemy, player_place, enemy_place);
					Sleep(3000);
				}

			}
			else if (answer == hard) {
				if (c == 5 && history != 'X') {
					do {
						ROWS = rand() % 10, COLS = rand() % 10;
					} while (player_place[ROWS][COLS] != 'X');
				}

				if (history == '0') {
					if (COLS != 9 && COLS != 0 && player_place[ROWS + 1][COLS] != 'H' && player_place[ROWS + 1][COLS + 1] != 'H' &&
						player_place[ROWS + 1][COLS - 1] != 'H' && player_place[ROWS - 1][COLS] != 'H' && player_place[ROWS - 1][COLS + 1] != 'H' &&
						player_place[ROWS - 1][COLS - 1] != 'H' && player_place[ROWS][COLS + 1] != 'H' && player_place[ROWS][COLS - 1] != 'H') {
						if (player_place[ROWS][COLS] == 'X' || player_place[ROWS][COLS] == '.') {
							if (player_place[ROWS][COLS] == 'X') {
								player_place[ROWS][COLS] = 'H';
								hitted2++;
								history = 'X';
								memory = 1;
								c = 0;
							}
							else {
								player_place[ROWS][COLS] = 'M';
								missed2++, c++;
								rule = 1;
							}
						}
						else {
							ROWS = rand() % 10, COLS = rand() % 10;
						}
					}

					else if (COLS == 9 && player_place[ROWS + 1][COLS] != 'H' && player_place[ROWS + 1][COLS - 1] != 'H' &&
						player_place[ROWS - 1][COLS] != 'H' && player_place[ROWS - 1][COLS - 1] != 'H' && player_place[ROWS][COLS - 1] != 'H') {
						if (player_place[ROWS][COLS] == 'X' || player_place[ROWS][COLS] == '.') {
							if (player_place[ROWS][COLS] == 'X') {
								player_place[ROWS][COLS] = 'H';
								hitted2++;
								history = 'X';
								memory = 1;
								c = 0;
							}
							else {
								player_place[ROWS][COLS] = 'M';
								missed2++, c++;
								rule = 1;
							}
						}
						else {
							ROWS = rand() % 10, COLS = rand() % 10;
						}
					}

					else if (COLS == 0 && player_place[ROWS + 1][COLS] != 'H' && player_place[ROWS + 1][COLS + 1] != 'H' &&
						player_place[ROWS - 1][COLS] != 'H' && player_place[ROWS - 1][COLS + 1] != 'H' && player_place[ROWS][COLS + 1] != 'H') {
						if (player_place[ROWS][COLS] == 'X' || player_place[ROWS][COLS] == '.') {
							if (player_place[ROWS][COLS] == 'X') {
								player_place[ROWS][COLS] = 'H';
								hitted2++;
								history = 'X';
								memory = 1;
								c = 0;
							}
							else {
								player_place[ROWS][COLS] = 'M';
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
							if (player_place[ROWS + 1][COLS] == 'X' || player_place[ROWS + 1][COLS] == '.') {
								ROWS++;
								if (player_place[ROWS][COLS] == 'X') {
									player_place[ROWS][COLS] = 'H';
									tmp++, hitted2++;
								}
								else {
									player_place[ROWS][COLS] = 'M';
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
						if (player_place[ROWS - 1][COLS] == 'X' || player_place[ROWS - 1][COLS] == '.') {
							ROWS--;
							if (player_place[ROWS][COLS] == 'X') {
								player_place[ROWS][COLS] = 'H';
								tmp++, hitted2++;
							}
							else {
								player_place[ROWS][COLS] = 'M';
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
							if (player_place[ROWS][COLS + 1] == 'X' || player_place[ROWS][COLS + 1] == '.') {
								COLS++;
								if (player_place[ROWS][COLS] == 'X') {
									player_place[ROWS][COLS] = 'H';
									tmp2++, hitted2++;
								}
								else {
									player_place[ROWS][COLS] = 'M';
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
							if (player_place[ROWS][COLS - 1] == 'X' || player_place[ROWS][COLS - 1] == '.') {
								COLS--;
								if (player_place[ROWS][COLS] == 'X') {
									player_place[ROWS][COLS] = 'H';
									tmp2++, hitted2++;
								}
								else {
									player_place[ROWS][COLS] = 'M';
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
				for (auto i = 0; i < 10; i++)
					for (auto j = 0; j < 10; j++) if (player_place[i][j] == 'M' || player_place[i][j] == 'H') count++;

				if (count == count2) {
					TEMP = 4;
					count2++;
					printF(player, enemy, player_place, enemy_place);
					Sleep(3000);
				}
			}
		}
		control = check_win(player_place, enemy);
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

int multi_player(char player[][10], char enemy[][10], char player_place[][10], char enemy_place[][10]) {

	int control;
	system("CLS");
	cin.ignore(), cin.clear(), fseek, fflush;
	for (auto i = 0; i < 10; i++) cout << "\n";
	for (auto i = 0; i < 25; i++) cout << "  ";
	cout << "(Player 1) Name: ";
	cin.getline(name, 25);
	system("CLS");
	for (auto i = 0; i < 10; i++) cout << "\n";
	for (auto i = 0; i < 25; i++) cout << "  ";
	cout << "(Player 2) Name: ";
	cin.clear(), fseek, fflush;
	cin.getline(name2, 25);

	for (auto i = 0; i < 10; i++)
		for (auto j = 0; j < 10; j++) {
			enemy[i][j] = '.';
			player[i][j] = '.';
		}

	TEMP = 1;
	adjust(player_place, enemy_place);
	TEMP = 2;
	adjust(player_place, enemy_place);
	int COLS, ROWS = 0;
	char letter;
	auto rule = 1;
	ofstream LOGS;
	LOGS.open("logs.txt");

	do {
		control = check_win(player_place, enemy);
		if (rule == 1 && control == 0) {
			TEMP = 2;
			printF(player, enemy, player_place, enemy_place);
			cout << "\n" << name << ", it's your turn\nEnter the number: v/h (e.g. 4c)\n";
			cin >> COLS;
			cin >> letter;
			COLS--;
			if (static_cast<int>(letter) >= 65 && static_cast<int>(letter) <= 74) ROWS = static_cast<int>(letter) - 65;
			else if (static_cast<int>(letter) >= 97 && static_cast<int>(letter) <= 106) ROWS = static_cast<int>(letter) - 97;
			if (enemy[ROWS][COLS] == 'M' || enemy[ROWS][COLS] == 'H' || ROWS >= 10 || COLS >= 10) {
				cout << "\nInvalid move..\n";
				Sleep(3000);
			}
			else if (enemy_place[ROWS][COLS] == 'X') {
				enemy[ROWS][COLS] = 'H';
				hitted++;
				printF(player, enemy, player_place, enemy_place);
				cout << "\nYou Hit..\n";
				Sleep(3000);
			}
			else {
				enemy[ROWS][COLS] = 'M';
				missed++;
				rule = 2;
				printF(player, enemy, player_place, enemy_place);
				cout << "\nYou miss..\n";
				Sleep(3000);
			}
		}
		else {
			TEMP = 1;
			printF(player, enemy, player_place, enemy_place);
			cout << "\n" << name2 << ", it's your turn\nEnter the number: v/h (e.g. 4c)\n";
			cin >> COLS;
			cin >> letter;
			COLS--;
			if (static_cast<int>(letter) >= 65 && static_cast<int>(letter) <= 74) ROWS = static_cast<int>(letter) - 65;
			else if (static_cast<int>(letter) >= 97 && static_cast<int>(letter) <= 106) ROWS = static_cast<int>(letter) - 97;
			if (player[ROWS][COLS] == 'M' || player[ROWS][COLS] == 'H' || ROWS >= 10 || COLS >= 10) {
				cout << "\nInvalid move..\n";
				Sleep(3000);
			}
			else if (player_place[ROWS][COLS] == 'X') {
				player[ROWS][COLS] = 'H';
				hitted2++;
				printF(player, enemy, player_place, enemy_place);
				cout << "\nYou hit..\n";
				Sleep(3000);
			}
			else {
				player[ROWS][COLS] = 'M';
				missed2++;
				rule = 1;
				printF(player, enemy, player_place, enemy_place);
				cout << "\nYou miss..\n";
				Sleep(3000);
			}
		}
		control = check_win(player_place, enemy);
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

	srand(time(nullptr));

	h_console = GetStdHandle(STD_OUTPUT_HANDLE);
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

	char player[10][10], enemy[10][10], player_place[10][10], enemy_place[10][10];
	char str[20] = "Battleship..";

	for (auto i = 0; i < 10; i++) cout << "\n";
	for (auto i = 0; i < 25; i++) cout << "  ";
	for (auto i = 0; str[i] != '\0'; i++) {
		cout << str[i];
		Sleep(100);
	}
	Sleep(1000);

	for (auto i = 0; i < 10; i++)
		for (auto j = 0; j < 10; j++) {
			player_place[i][j] = '.';
			enemy_place[i][j] = '.';
		}

	system("CLS");
	for (auto i = 0; i < 10; i++) cout << "\n";
	for (auto i = 0; i < 25; i++) cout << "  ";
	cout << "Single player\n";
	for (auto i = 0; i < 25; i++) cout << "  ";
	cout << "Multi player\n";
	for (auto i = 0; i < 25; i++) cout << "  ";
	cout << "Quit game\n";

	int answer;
	cin >> answer;
	if (answer == 1) single_player(player, enemy, player_place, enemy_place);
	else if (answer == 2) multi_player(player, enemy, player_place, enemy_place);
	else if (answer == 3) return 0;
	else cin >> answer;

	return 0;
}