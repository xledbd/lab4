#pragma once
#include <iostream>
#include <conio.h>
#include <list>
#include <string>

constexpr auto KEY_UP = 72;
constexpr auto KEY_DOWN = 80;
constexpr auto KEY_ENTER = 13;

using listOfStrings = std::list<std::string>;

class Menu
{
protected:
	listOfStrings choiceList;
public:
	Menu();
	int exitNum;
	int build();
};

class MainMenu : public Menu
{
public:
	MainMenu();
};

class TrainerCategoryMenu : public Menu
{
public:
	TrainerCategoryMenu();
};

class EditTrainerMenu : public Menu
{
public:
	EditTrainerMenu();
};

class EditResistanceTrainerMenu : public EditTrainerMenu
{
public:
	EditResistanceTrainerMenu();
};

class EditFreeTrainerMenu : public EditTrainerMenu
{
public:
	EditFreeTrainerMenu();
};

class EditCardioTrainerMenu : public EditTrainerMenu
{
public:
	EditCardioTrainerMenu();
};

