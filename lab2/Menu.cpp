#include <Windows.h>

#include "Menu.h"
//#define KEY_LEFT 75
//#define KEY_RIGHT 77

Menu::Menu()
{
	choiceList.push_back("Выход");
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
	choiceList.push_front("Создать отчет в Excel");
	choiceList.push_front("Сохранить изменения");
	choiceList.push_front("Изменить название спортзала");
	choiceList.push_front("Вывести информацию о тренажере");
	choiceList.push_front("Вывести информацию о спотрзале");
	choiceList.push_front("Удалить тренажер");
	choiceList.push_front("Редактировать тренажер");
	choiceList.push_front("Добавить тренажер");
	exitNum = choiceList.size() - 1;
}

TrainerCategoryMenu::TrainerCategoryMenu() : Menu()
{
	choiceList.pop_back();
	choiceList.push_front("Добавить диски");
	choiceList.push_front("Добавить гантели");
	choiceList.push_front("Добавить кардиотренажер");
	choiceList.push_front("Добавить тренажер со свободными весами");
	choiceList.push_front("Добавить грузоблочный тренажер");
	exitNum = choiceList.size() - 1;
}

EditTrainerMenu::EditTrainerMenu() : Menu()
{
	choiceList.push_front("Изменить производителя");
	choiceList.push_front("Изменить тип тренажера");
	exitNum = choiceList.size() - 1;
}

EditResistanceTrainerMenu::EditResistanceTrainerMenu() : EditTrainerMenu()
{
	choiceList.push_front("Изменить максимальный рабочий вес");
	choiceList.push_front("Изменить группу мыщц");
	exitNum = choiceList.size() - 1;
}

EditFreeTrainerMenu::EditFreeTrainerMenu() : EditTrainerMenu()
{
	choiceList.push_front("Изменить группу мышц");
	exitNum = choiceList.size() - 1;
}

EditCardioTrainerMenu::EditCardioTrainerMenu() : EditTrainerMenu()
{
	choiceList.push_front("Изменить максимальный уклон");
	choiceList.push_front("Изменить максимальную скорость");
	exitNum = choiceList.size() - 1;
}
