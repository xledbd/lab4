#include <iostream>
#include <fstream>
#include <Windows.h>
#define NOMINMAX
#include "Menu.h"
#include "Gym.h"
#include "Treadmill.h"
#include "ExtensionTrainer.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.bVisible = false;
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	std::fstream f("dat.dat");
	Gym g{};
	f >> g;
	f.close();
	MainMenu m;
	//Gym::TrainerListMenu m(g); //temp
	string name;
	int choice = m.build();
	while (choice != m.exitNum)
	{
		switch (choice)
		{
		case 0:
			g.addTrainer();
			break;
		case 1:
			g.editTrainer();
			break;
		case 2:
			g.removeTrainer();
			break;
		case 3:
			g.createReport();
			break;
		case 4:
			g.printSingle();
			break;
		case 5:
			system("CLS");
			cout << "¬ведите новое название: ";
			cin >> std::ws;
			std::getline(cin, name);
			g.setName(name);
			break;
		case 6:
			f.open("dat.dat", std::ios::out | std::ios::trunc);
			f << g;
			f.close();
			break;
		case 7:
			g.createXLSXReport();
			break;
		}
		choice = m.build();
	}
	return 0;
}