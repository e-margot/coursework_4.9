#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "windows.h"
#include "Conveyor.h"
#include "Builder.h"
#include "Director.h"
//#include "menu.h"
#include "helicopter.h"
#include "quadcopter.h"
#include "airliner.h"
#include "combatAircraft.h"


using namespace std;
void menu1(Director& director);
void menu2(Director& director, Builder &builder);


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	//Director *D = new Director;
	//menu1(*D);
	int N = 0, choose = 0, i = 0;
	bool loop = true;
	//menu *M;
	cout << "Enter N" << endl;
	cin >> N;
	// Функция main() в данном случае выступает клиентом
	// 1. Объявить указатель на продукт, который нужно получить
	Conveyor** product = new Conveyor*[N]; //builder
	helicopter Helic; //concrete builder
	quadcopter Quadr;
	airliner Air;
	combatAircraft CA;
	Director *D = new Director;
	do {
		system("cls");
		cout << "Выберите тип летательного аппарата:" << endl;
		cout << "1) Пассажирский самолет" << endl;
		cout << "2) Военный самолет" << endl;
		cout << "3) Вертолет" << endl;
		cout << "4) Квадрокоптер" << endl;
		cout << "5) Выход" << endl;
		cin >> choose;

		switch (choose) {
		case 1:
			D->Construct(Air);
			//D.Edit(Air);
		//	M->fMenu(Air);
		//	D.Construct(Air); // сконфигурировать
		//	menu2(*D, Air);
			product[i] = Air.GetResult();
			i++;
			break;
		case 2:
			//D->Construct(CA); // сконфигурировать
			menu2(*D, CA);
			product[i] = CA.GetResult();
			i++;
			break;
		case 3:
			//D->Construct(Helic); // сконфигурировать
			menu2(*D, Helic);
			product[i] = Helic.GetResult();
			i++;
			break;
		case 4:
			//D->Construct(Quadr); // сконфигурировать
			menu2(*D, Quadr);
			product[i] = Quadr.GetResult();
			i++;
			break;
		case 5:
			loop = false;
		default:
			loop = false;
		}
		if (i == N) { //проверка на дурочка
			cout << "Мест нет" << endl;
			loop = false;
		}

	} while (loop);
	system("cls");
	/*for (int j = 0; j < i; j++) {
		cout << product[j]->type << endl;
	}*/
	// 2. Создать конкретный экземпляр класса helicopter и заполнить значениями

	// 3. Создать класс-распорядитель и сконфигурировать его продуктом B
	//Director D;
	//D.Construct(Helic); // сконфигурировать
	//D.Construct(Quadr1); // сконфигурировать
	//D.Construct(Quadr2); // сконфигурировать

	//// 4. После конфигурирования, передать созданный продукт клиенту
	//product[0] = Helic.GetResult();
	//product[1] = Quadr1.GetResult();
	//product[2] = Quadr2.GetResult();

	// 5. Вывести значение продукта для контроля
	/*cout << "product->type = " << product->type << endl;
	cout << "product->engine = " << product->engine << endl;*/
	/*for (int j = 0; j < i; j++)
	{
		delete[] product[j];
	}*/
	delete[] product;

	system("pause");
	return 0;
}

void menu1(Director& director) {
	int N = 0, choose = 0, i = 0;
	bool loop = true;
	//menu *M;
	cout << "Enter N" << endl;
	cin >> N;
	Conveyor** product = new Conveyor*[N]; //builder
	helicopter Helic; //concrete builder
	quadcopter Quadr;
	airliner Air;
	combatAircraft CA;
	do {
		system("cls");
		cout << "Выберите тип летательного аппарата:" << endl;
		cout << "1) Пассажирский самолет" << endl;
		cout << "2) Военный самолет" << endl;
		cout << "3) Вертолет" << endl;
		cout << "4) Квадрокоптер" << endl;
		cout << "5) Выход" << endl;
		cin >> choose;

		switch (choose) {
		case 1:
			//D.Construct(Air);
			//D.Edit(Air);
		//	M->fMenu(Air);
		//	D.Construct(Air); // сконфигурировать
			product[i] = Air.GetResult();
			i++;
			break;
		case 2:
			director.Construct(CA); // сконфигурировать
			product[i] = CA.GetResult();
			i++;
			break;
		case 3:
			director.Construct(Helic); // сконфигурировать
			product[i] = Helic.GetResult();
			i++;
			break;
		case 4:
			director.Construct(Quadr); // сконфигурировать
			product[i] = Quadr.GetResult();
			i++;
			break;
		case 5:
			loop = false;
		default:
			loop = false;
		}
		if (i == N) { //проверка на дурочка
			cout << "Мест нет" << endl;
			loop = false;
		}

	} while (loop);
	delete[] product;
}

void menu2(Director& director, Builder &builder) {
	cout << "1) Сконфигурировать" << endl;
	cout << "2) Редактировать" << endl;
	cout << "3) Удалить" << endl;
	cout << "4) Загрузить в файл" << endl;
	cout << "5) Вывести на экран из файла" << endl;
	cout << "6) Выход" << endl;
	int ch = 0;
	cin >> ch;
	switch (ch) {
	case 1:
		director.Construct(builder);
		break;
	case 2:
		director.Edit(builder);
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		return;
	default:
		return;
	}


}
