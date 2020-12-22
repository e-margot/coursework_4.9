#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "windows.h"
#include "Conveyor.h"
#include "Builder.h"
#include "Director.h"
#include "helicopter.h"
#include "quadcopter.h"
#include "airliner.h"
#include "combatAircraft.h"

using namespace std;

/*поиграться с полями*/
int main() {
	ofstream f_ca, f_quadr, f_h, f_air;
	f_ca.open("combatAircraft.txt", ios_base::trunc);
	f_h.open("helic.txt", ios_base::trunc);
	f_air.open("airliner.txt", ios_base::trunc);
	f_quadr.open("qudro.txt", ios_base::trunc);
	f_ca.close();
	f_h.close();
	f_air.close();
	f_quadr.close();
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	int i = 0;
	char choose1, choose2;
	int ch;
	bool loop = true, flag = false;
	vector <Conveyor*> product;
	helicopter *Helic = new helicopter;
	quadcopter* Quadr = new quadcopter;
	airliner* Air = new airliner;
	combatAircraft *CA = new combatAircraft;
	Director *D = new Director;
	do {
		system("cls");
		cout <<"Главное меню:" << endl;
		cout << "1) Создание" << endl;
		cout << "2) Редактирование" << endl;
		cout << "3) Удаление" << endl;
		cout << "4) Сохранение" << endl;
		cout << "5) Загрузка из файла" << endl;
		cout << "6) Вывести созданные продукты" << endl;
		cout << "7) Выход" << endl;
		cin >> choose1;
		system("cls");
		switch (choose1) {
		case '1':
			/*создание*/
			cout << "СОЗДАНИЕ" << endl;
			cout << "1) Пассажирский самолет" << endl;
			cout << "2) Военный самолет" << endl;
			cout << "3) Вертолет" << endl;
			cout << "4) Квадрокоптер" << endl;
			cout << ">>";
			cin >> choose2;
			switch (choose2) {
			case '1':
				D->Construct(*Air);
				product.push_back(Air->GetResult());
				break;
			case '2':
				D->Construct(*CA);
				product.push_back(CA->GetResult());
				break;
			case '3':
				D->Construct(*Helic);
				product.push_back(Helic->GetResult());
				break;
			case '4':
				D->Construct(*Quadr);
				product.push_back(Quadr->GetResult());
				break;
			}
			break;
		case '2':
			/*редактирование*/
			cout << "РЕДАКТИРОВАНИЕ" << endl;
			cout << "1) Пассажирский самолет" << endl;
			cout << "2) Военный самолет" << endl;
			cout << "3) Вертолет" << endl;
			cout << "4) Квадрокоптер" << endl;
			cout << ">>";
			cin >> choose2;
			switch (choose2) {
			case '1':
				if (Air->GetResult()!=nullptr) {
					D->Edit(*Air);
				}
				else { cout << "Объект не создан!" << endl; }
				break;
			case '2':
				if (Air->GetResult() != nullptr) {
					D->Edit(*CA);
				}
				else { cout << "Объект не создан!" << endl; }
				break;
			case '3':
				if (Air->GetResult() != nullptr) {
					D->Edit(*Helic);
				}
				else { cout << "Объект не создан!" << endl; }
				break;
			case '4':
				if (Air->GetResult() != nullptr) {
					D->Edit(*Quadr);
				}
				else { cout << "Объект не создан!" << endl; }
				break;
			default:
				cout << "Ошибка ввода!" << endl;
			}
			break;
		case '3':
			/*удаление*/
			if (!product.empty()) {
				for (int j = 0; j < product.size(); j++) {
					cout << j + 1 << ") " << product[j]->machine << product[j]->type << endl;
				}
				cout << ">>";
				cin >> ch;
				product.erase(product.begin() + ch - 1);
			}
			else {
				cout << "Список летательных аппаратов пуст!" << endl;
			}
			break;
		case '4':
			/*Сохранение в файл*/
			break;
		case '5':
			/*Загрузка из файла*/
			break;
		case '6':
			/*вывести на экран*/
			D->Get(*CA);
			break;
		case '7':
			loop = false;
			break;
		default:
			cout << "Ошибка! Повторите ввод" << endl;
		}
		system("pause");
	} while (loop);
	system("cls");
	delete Quadr;
	delete D;
	delete Helic;
	delete CA;
	delete Air;
	return 0;
}
