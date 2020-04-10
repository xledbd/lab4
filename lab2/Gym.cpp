#include "Gym.h"

void Gym::addCardioTrainer()
{
	string manufact, type;
	double maxsp, maxinc;
	cout << "Введите тип тренажера: ";
	std::getline(cin, type);
	cout << "Введите производителя: ";
	std::getline(cin, manufact);
	cout << "Введите максимальную скорость: ";
	cin >> maxsp;
	cout << "Введите максимальный уклон: ";
	cin >> maxinc;
	trainerList.insert(std::make_pair(3, std::make_shared<CardiovascularTrainer>(maxsp, maxinc, type, manufact)));
}

void Gym::addResistanceTrainer()
{
	string manufact, type, muscle;
	int maxw;
	cout << "Введите тип тренажера: ";
	std::getline(cin, type);
	cout << "Введите производителя: ";
	std::getline(cin, manufact);
	cout << "Введите группу мышц: ";
	std::getline(cin, muscle);
	cout << "Введите максимальный рабочий вес: ";
	cin >> maxw;
	trainerList.insert(std::make_pair(1, std::make_shared<ResistanceTrainer>(muscle, maxw, type, manufact)));
}

void Gym::addFreeWeightTrainer()
{
	string manufact, type, muscle;
	cout << "Введите тип тренажера: ";
	std::getline(cin, type);
	cout << "Введите производителя: ";
	std::getline(cin, manufact);
	cout << "Введите группу мышц: ";
	std::getline(cin, muscle);
	trainerList.insert(std::make_pair(2, std::make_shared<FreeWeightTrainer>(muscle, type, manufact)));
}

void Gym::addDumbbell()
{
	int w, n;
	while (true)
	{
		try
		{
			cout << "Введите вес: ";
			cin >> w;
			cout << "Введите количество: ";
			cin >> n;
			for (size_t i = 0; i < n; i++)
			{
				dumbbells.addWeight(w);
			}
			return;
		}
		catch (const std::exception& e)
		{
			cout << "Exception caught: " << e.what() << '\n';
		}
	}
}

void Gym::addPlate()
{
	int w, n;
	while (true)
	{
		try
		{
			cout << "Введите вес: ";
			cin >> w;
			cout << "Введите количество: ";
			cin >> n;
			for (size_t i = 0; i < n; i++)
			{
				plates.addWeight(w);
			}
			return;
		}
		catch (const std::exception& e)
		{
			cout << "Exception caught: " << e.what() << '\n';
		}
	}

}

void Gym::editCardioTrainer(std::shared_ptr<Trainer> pos)
{
	EditCardioTrainerMenu m;
	auto p = std::dynamic_pointer_cast<CardiovascularTrainer>(pos);
	int choice = m.build();
	while (choice != m.exitNum)
	{
		system("CLS");
		std::string s;
		double d;
		int n;
		switch (choice)
		{
		case 0:
			//speed
			cout << "Максимальная скорость: " << p->getMaxSpeed() << '\n'
				<< "Введите максимальную скорость: ";
			cin >> d >> std::ws;
			p->setMaxSpeed(d);
			break;
		case 1:
			//inc
			cout << "Максимальный уклон: " << p->getMaxIncline() << '\n'
				<< "Введите максимальный уклон: ";
			cin >> d >> std::ws;
			p->setMaxIncline(d);
			break;
		case 2:
			//type
			cout << "Тип тренажера: " << p->getTrainerType() << '\n'
				<< "Введите тип тренажера: ";
			std::getline(cin, s);
			p->setTrainerType(s);
			break;
		case 3:
			//manuf
			cout << "Производитель: " << p->getManufacturer() << '\n'
				<< "Введите производителя: ";
			std::getline(cin, s);
			p->setManufacturer(s);
			break;
		}
		choice = m.build();
	}
}

void Gym::editResistanceTrainer(std::shared_ptr<Trainer> pos)
{
	EditResistanceTrainerMenu m;
	auto p = std::dynamic_pointer_cast<ResistanceTrainer>(pos);
	int choice = m.build();
	while (choice != m.exitNum)
	{
		system("CLS");
		std::string s;
		int n;
		switch (choice)
		{
		case 0:
			//muscle
			cout << "Группа мышц: " << p->getMuscleType() << '\n'
				<< "Введите группу мышц: ";
			std::getline(cin, s);
			p->setMuscleType(s);
			break;
		case 1:
			//weight
			cout << "Максимальный рабочий вес: " << p->getMaxWeight() << '\n'
				<< "Введите максимальный вес: ";
			cin >> n >> std::ws;
			p->setMaxWeight(n);
			break;
		case 2:
			//type
			cout << "Тип тренажера: " << p->getTrainerType() << '\n'
				<< "Введите тип тренажера: ";
			std::getline(cin, s);
			p->setTrainerType(s);
			break;
		case 3:
			//manuf
			cout << "Производитель: " << p->getManufacturer() << '\n'
				<< "Введите производителя: ";
			std::getline(cin, s);
			p->setManufacturer(s);
			break;
		}
		choice = m.build();
	}
}

void Gym::editFreeWeightTrainer(std::shared_ptr<Trainer> pos)
{
	EditFreeTrainerMenu m;
	auto p = std::dynamic_pointer_cast<FreeWeightTrainer>(pos);
	int choice = m.build();
	while (choice != m.exitNum)
	{
		system("CLS");
		std::string s;
		int n;
		switch (choice)
		{
		case 0:
			//muscle
			cout << "Группа мышц: " << p->getMuscleType() << '\n'
				<< "Введите группу мышц: ";
			std::getline(cin, s);
			p->setMuscleType(s);
			break;
		case 1:
			cout << "Тип тренажера: " << p->getTrainerType() << '\n'
				<< "Введите тип тренажера: ";
			std::getline(cin, s);
			p->setTrainerType(s);
			break;
		case 2:
			//manuf
			cout << "Производитель: " << p->getManufacturer() << '\n'
				<< "Введите производителя: ";
			std::getline(cin, s);
			p->setManufacturer(s);
			break;
		}
		choice = m.build();
	}
}

void Gym::addTrainer()
{
	TrainerCategoryMenu m;
	switch (m.build())
	{
	case 0:
		addResistanceTrainer();
		break;
	case 1:
		addFreeWeightTrainer();
		break;
	case 2:
		addCardioTrainer();
		break;
	case 3:
		addDumbbell();
		break;
	case 4:
		addPlate();
		break;
	}
	cout << "Тренажер добавлен.\n";
	_getch();
}

void Gym::editTrainer()
{
	if (trainerList.size() == 0) cout << "Тренажеров нет.\n";
	else
	{
		TrainerListMenu m(*this);
		auto pos = m.build();
		auto it = trainerList.lower_bound(pos.first);
		for (int i = 0; i < pos.second; i++, it++) {}
		if (pos.first == 1)
			editResistanceTrainer(it->second);
		else if (pos.first == 2)
			editFreeWeightTrainer(it->second);
		else
			editCardioTrainer(it->second);
	}
}

void Gym::removeDumbbell(int kg)
{
	try
	{
		dumbbells.removeWeight(kg);
	}
	catch (const std::exception& e)
	{
		cout << "Exception caught: " << e.what() << '\n';
	}
}

void Gym::removePlate(int kg)
{
	try
	{
		plates.removeWeight(kg);
	}
	catch (const std::exception & e)
	{
		cout << "Exception caught: " << e.what() << '\n';
	}
}

void Gym::removeTrainer()
{
	if (trainerList.size() == 0) std::cout << "Тренажеров нет.\n";
	else
	{
		TrainerListMenu m(*this);
		auto pos = m.build();
		auto it = trainerList.lower_bound(pos.first);
		for (int i = 0; i < pos.second; i++, it++) {}
		trainerList.erase(it);
		std::cout << "Тренажер удален.\n";
	}
	_getch();
}

void Gym::createReport()
{
	string fill(55, '_');
	cout << "Gym " << name << "\n";
	if (trainerList.size() == 0) std::cout << "Тренажеров нет.\n";
	else
	{
		cout << "Тренажеры: \n"
			<< std::setw(15) << "Категория|" << std::setw(20) << "Тип|" << std::setw(20) << "Производитель|\n"
			<< fill << '\n';
		for (auto a : trainerList)
		{
			if (a.first == 1) cout << std::setw(15) << "Грузоблочный|";
			else if (a.first == 2) cout << std::setw(15) << "Со св. весом|";
			else cout << std::setw(15) << "Кардио|";
			cout << std::setw(20) << a.second->getTrainerType() + "|" << std::setw(20) << a.second->getManufacturer() + "|\n";
		}
		cout << fill << '\n';
	}
	fill = string(37, '_');
	cout << "\nОборудование: \n"
		<< std::setw(15) << "Тип|" << std::setw(10) << "Вес, кг|" << std::setw(12) << "Кол-во, шт|" << '\n'
		<< fill << '\n';
	for (auto a : dumbbells.weights)
	{
		cout << std::setw(15) << dumbbells.type + "|" << std::setw(9) << a.first << "|" << std::setw(11) << a.second << "|\n";
	}
	for (auto a : plates.weights)
	{
		cout << std::setw(15) << plates.type + "|" << std::setw(9) << a.first << "|" << std::setw(11) << a.second << "|\n";
	}
	cout << fill << '\n';
	_getch();
}

void Gym::createXLSXReport()
{
	Book* book = xlCreateXMLBook();
	Sheet* sheet1 = book->addSheet(L"Грузоблочные тренажеры");
	Sheet* sheet2 = book->addSheet(L"Тренажеры со свободным весом");
	Sheet* sheet3 = book->addSheet(L"Кардиотренажеры");
	Sheet* sheet4 = book->addSheet(L"Оборудование");

	sheet1->writeStr(1, 0, L"Производитель");
	sheet1->writeStr(1, 1, L"Тип");
	sheet1->writeStr(1, 2, L"Группа мышц");
	sheet1->writeStr(1, 3, L"Макс. вес");

	sheet2->writeStr(1, 0, L"Производитель");
	sheet2->writeStr(1, 1, L"Тип");
	sheet2->writeStr(1, 2, L"Группа мышц");
	
	sheet3->writeStr(1, 0, L"Производитель");
	sheet3->writeStr(1, 1, L"Тип");
	sheet3->writeStr(1, 2, L"Макс. скорость");
	sheet3->writeStr(1, 3, L"Макс. уклон");

	sheet4->writeStr(1, 0, L"Тип");
	sheet4->writeStr(1, 1, L"Вес, кг");
	sheet4->writeStr(1, 2, L"Количество");

	auto eq1 = trainerList.equal_range(1);
	auto eq2 = trainerList.equal_range(2);
	auto eq3 = trainerList.equal_range(3);
	int row = 2;
	for (auto i = eq1.first; i != eq1.second; i++)
	{
		auto a = std::dynamic_pointer_cast<ResistanceTrainer>(i->second);
		sheet1->writeStr(row, 0, to_wstring(a->getManufacturer()).c_str());
		sheet1->writeStr(row, 1, to_wstring(a->getTrainerType()).c_str());
		sheet1->writeStr(row, 2, to_wstring(a->getMuscleType()).c_str());
		sheet1->writeNum(row, 3, a->getMaxWeight());
		++row;
	}
	sheet1->setAutoFitArea();
	row = 2;
	for (auto i = eq2.first; i != eq2.second; i++)
	{
		auto a = std::dynamic_pointer_cast<FreeWeightTrainer>(i->second);
		sheet2->writeStr(row, 0, to_wstring(a->getManufacturer()).c_str());
		sheet2->writeStr(row, 1, to_wstring(a->getTrainerType()).c_str());
		sheet2->writeStr(row, 2, to_wstring(a->getMuscleType()).c_str());
		++row;
	}
	sheet2->setAutoFitArea();
	row = 2;
	for (auto i = eq3.first; i != eq3.second; i++)
	{
		auto a = std::dynamic_pointer_cast<CardiovascularTrainer>(i->second);
		sheet3->writeStr(row, 0, to_wstring(a->getManufacturer()).c_str());
		sheet3->writeStr(row, 1, to_wstring(a->getTrainerType()).c_str());
		sheet3->writeNum(row, 2, a->getMaxSpeed());
		sheet3->writeNum(row, 3, a->getMaxIncline());
		++row;
	}
	sheet3->setAutoFitArea();
	row = 2;
	for (auto a : dumbbells.weights)
	{
		sheet4->writeStr(row, 0, L"Гантели");
		sheet4->writeNum(row, 1, a.first);
		sheet4->writeNum(row, 2, a.second);
		++row;
	}
	for (auto a : plates.weights)
	{
		sheet4->writeStr(row, 0, L"Диски");
		sheet4->writeNum(row, 1, a.first);
		sheet4->writeNum(row, 2, a.second);
		++row;
	}
	sheet4->setAutoFitArea();
	wstring ws = to_wstring(name) + L".xlsx";
	book->save(ws.c_str());
	book->release();
	system("\"IMPECCABLE PECS.xlsx\"");
}

void Gym::printSingle()
{
	if (trainerList.size() == 0) cout << "Тренажеров нет.\n";
	else
	{
		TrainerListMenu m(*this);
		auto pos = m.build();
		auto it = trainerList.lower_bound(pos.first);
		for (int i = 0; i < pos.second; i++, it++) {}
		it->second->printToConsole();
	}
	_getch();
}

ostream& operator<<(ostream& out, Gym& p)
{
	out << p.name << '\n';
	std::for_each(p.trainerList.begin(), p.trainerList.end(), [&out](decltype(p.trainerList)::value_type& p) { out << *(p.second) << '\n'; });
	out << "4\n"
		<< p.dumbbells << '\n'
		<< "5\n"
		<< p.plates;
	return out;
}

istream& operator>>(istream& in, Gym& p)
{
	int n;
	std::getline(in, p.name);
	in >> n;
	ResistanceTrainer r("Abs");
	FreeWeightTrainer f("Abs", "Bench");
	CardiovascularTrainer c;
	while (in.good())
	{
		switch (n)
		{
		case 1:
			in >> r;
			p.trainerList.insert(std::make_pair(1, std::make_shared<ResistanceTrainer>(r)));
			break;
		case 2:
			in >> f;
			p.trainerList.insert(std::make_pair(2, std::make_shared<FreeWeightTrainer>(f)));
			break;
		case 3:
			in >> c;
			p.trainerList.insert(std::make_pair(3, std::make_shared<CardiovascularTrainer>(c)));
			break;
		case 4:
			in >> p.dumbbells;
			break;
		case 5:
			in >> p.plates;
			break;
		}
		in >> n;
	}
	return in;
}

Gym::TrainerListMenu::TrainerListMenu(Gym& g) : Menu(), g(g)
{
	choiceList.pop_back();
	auto eq1 = g.trainerList.equal_range(1);
	auto eq2 = g.trainerList.equal_range(2);
	auto eq3 = g.trainerList.equal_range(3);
	for (auto i = eq1.first; i != eq1.second; i++)
	{
		std::string s("Грузоблочный тренажер: ");
		s += i->second->getManufacturer();
		s += " ";
		s += i->second->getTrainerType();
		choiceList.push_back(s);
	}
	for (auto i = eq2.first; i != eq2.second; i++)
	{
		std::string s("Тренажер со свободными весами: ");
		s += i->second->getManufacturer();
		s += " ";
		s += i->second->getTrainerType();
		choiceList.push_back(s);
	}
	for (auto i = eq3.first; i != eq3.second; i++)
	{
		std::string s("Кардиотренажер: ");
		s += i->second->getManufacturer();
		s += " ";
		s += i->second->getTrainerType();
		choiceList.push_back(s);
	}
	exitNum = choiceList.size() - 1;
}

std::pair<int, int> Gym::TrainerListMenu::build()
{
	int offset1 = g.trainerList.count(1);
	int offset2 = g.trainerList.count(2);
	int pos = Menu::build(), k = 1;
	if (pos >= offset1)
	{
		pos -= offset1;
		++k;
		if (pos >= offset2)
		{
			pos -= offset2;
			++k;
		}
	}
	
	return std::make_pair(k, pos);
}
