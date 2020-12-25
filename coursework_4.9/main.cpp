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
	D->clrFile();
	do {
		system("cls");
		cout <<"Главное меню:" << endl;
		cout << "1) Создание" << endl;
		cout << "2) Редактирование" << endl;
		cout << "3) Удаление" << endl;
		cout << "4) Загрузка из файла" << endl;
		cout << "5) Вывести созданные продукты" << endl;
		cout << "6) Выход" << endl;
		cout << "7) Загрузить в файл" << endl;
	//	getline(cin, choose1);
		cin >> choose1;
		cin.ignore();
		//i = atoi(choose1);
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
			cin.ignore();
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
			default:
				cout << "Ошибка! Повторите ввод" << endl;
			}
			break;
		case '2':
			/*редактирование*/
			cout << "РЕДАКТИРОВАНИЕ" << endl;
			if (!product.empty()) {
				for (int j = 0; j < product.size(); j++) {
					cout << j + 1 << ") " << product[j]->machine << " " << product[j]->type << endl;
				}
				cout << ">>";  cin >> ch; /*заита на ввод*/
				ch--;
				int check = D->check(product[ch]);
				if (check == 1) {
					airliner* A = new airliner;
					D->EditProduct(product[ch], *A);
					*product[ch] = move(*(A->GetResult()));
				}
				else if (check == 2) {
					combatAircraft* A = new combatAircraft;
					D->EditProduct(product[ch], *A);
					*product[ch] = move(*(A->GetResult()));
				}
				else if (check == 3) {
					quadcopter* A = new quadcopter;
					D->EditProduct(product[ch], *A);
					*product[ch] = move(*(A->GetResult()));
				}
				else if (check == 4) {
					helicopter* A = new helicopter;
					D->EditProduct(product[ch], *A);
					*product[ch] = move(*(A->GetResult()));
				}
			}			
			break;
		case '3':
			/*удаление*/
			if (!product.empty()) {
				for (int j = 0; j < product.size(); j++) {
					cout << j + 1 << ") " << product[j]->machine << " " << product[j]->type << endl;
				}
				cout << ">>";  cin >> ch; /*заита на ввод*/
				product.erase(product.begin() + (ch-1));
			}
			else {
				cout << "Список летательных аппаратов пуст!" << endl;
			}
			break;
		case '4':
			cout << "Загрузка..." << endl;
			D->FileRead(product, *Air);
			break;
		case '5':
			if (!product.empty()) {
				for (int j = 0; j < product.size(); j++) {
					cout << j + 1 << ") " << product[j]->machine << " " << product[j]->type << endl;
				}
				cout << ">>";  cin >> ch; /*заита на ввод*/
				ch--;
				int check = D->check(product[ch]);
				if (check == 1) {
					airliner* A = new airliner;
					D->GetProduct(product[ch], *A);
				}
				else if (check == 2) {
					combatAircraft* A = new combatAircraft;
					D->GetProduct(product[ch], *A);
				}
				else if (check == 3) {
					quadcopter* A = new quadcopter;
					D->GetProduct(product[ch], *A);
				}
				else if (check == 4) {
					helicopter* A = new helicopter;
					D->GetProduct(product[ch], *A);
				}
			}
			/*вывести на экран*/
			break;
		case '6':
			loop = false;
			break;
		case '7':
			//D->FileWrite(product, *Air);
			if (!product.empty()) {
				for (int j = 0; j < product.size(); j++) {
					int check = D->check(product[j]);
					if (check == 1) {
						airliner* A = new airliner;
						D->FileWrite(product[j], *A);
					}
					else if (check == 2) {
						combatAircraft* A = new combatAircraft;
						D->FileWrite(product[j], *A);
					}
					else if (check == 3) {
						quadcopter* A = new quadcopter;
						D->FileWrite(product[j], *A);
					}
					else if (check == 4) {
						helicopter* A = new helicopter;
						D->FileWrite(product[j], *A);
					}
				}
			}
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
