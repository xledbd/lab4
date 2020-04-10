#include <Windows.h>

#include "Menu.h"
//#define KEY_LEFT 75
//#define KEY_RIGHT 77

Menu::Menu()
{
	choiceList.push_back("�����");
	exitNum = choiceList.size() - 1;
}

int Menu::build()
{
	int pos = 0;
	while (true)
	{
		system("CLS");
		auto it = choiceList.begin();
		for (int i = 0; it != choiceList.end(); i++, it++)
		{
			if (i == pos)
			{
				std::cout << "> " << *it << '\n';
			}
			else std::cout << "  " << *it << '\n';
		}
		int c = 0;
		while (c != KEY_ENTER && c != KEY_DOWN && c != KEY_UP)
		{
			c = _getch();
			switch (c)
			{
			case KEY_UP:
				if (pos != 0) --pos;
				break;
			case KEY_DOWN:
				if (pos != choiceList.size() - 1) ++pos;
				break;
			case KEY_ENTER:
				system("CLS");
				return pos;
				break;
			}
		}
	}
	return 0;
}

MainMenu::MainMenu() : Menu()
{
	choiceList.push_front("������� ����� � Excel");
	choiceList.push_front("��������� ���������");
	choiceList.push_front("�������� �������� ���������");
	choiceList.push_front("������� ���������� � ���������");
	choiceList.push_front("������� ���������� � ���������");
	choiceList.push_front("������� ��������");
	choiceList.push_front("������������� ��������");
	choiceList.push_front("�������� ��������");
	exitNum = choiceList.size() - 1;
}

TrainerCategoryMenu::TrainerCategoryMenu() : Menu()
{
	choiceList.pop_back();
	choiceList.push_front("�������� �����");
	choiceList.push_front("�������� �������");
	choiceList.push_front("�������� ��������������");
	choiceList.push_front("�������� �������� �� ���������� ������");
	choiceList.push_front("�������� ������������ ��������");
	exitNum = choiceList.size() - 1;
}

EditTrainerMenu::EditTrainerMenu() : Menu()
{
	choiceList.push_front("�������� �������������");
	choiceList.push_front("�������� ��� ���������");
	exitNum = choiceList.size() - 1;
}

EditResistanceTrainerMenu::EditResistanceTrainerMenu() : EditTrainerMenu()
{
	choiceList.push_front("�������� ������������ ������� ���");
	choiceList.push_front("�������� ������ ����");
	exitNum = choiceList.size() - 1;
}

EditFreeTrainerMenu::EditFreeTrainerMenu() : EditTrainerMenu()
{
	choiceList.push_front("�������� ������ ����");
	exitNum = choiceList.size() - 1;
}

EditCardioTrainerMenu::EditCardioTrainerMenu() : EditTrainerMenu()
{
	choiceList.push_front("�������� ������������ �����");
	choiceList.push_front("�������� ������������ ��������");
	exitNum = choiceList.size() - 1;
}
