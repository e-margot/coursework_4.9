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
	// ������� main() � ������ ������ ��������� ��������
	// 1. �������� ��������� �� �������, ������� ����� ��������
	Conveyor** product = new Conveyor*[N]; //builder
	helicopter Helic; //concrete builder
	quadcopter Quadr;
	airliner Air;
	combatAircraft CA;
	Director *D = new Director;
	do {
		system("cls");
		cout << "�������� ��� ������������ ��������:" << endl;
		cout << "1) ������������ �������" << endl;
		cout << "2) ������� �������" << endl;
		cout << "3) ��������" << endl;
		cout << "4) ������������" << endl;
		cout << "5) �����" << endl;
		cin >> choose;

		switch (choose) {
		case 1:
			D->Construct(Air);
			//D.Edit(Air);
		//	M->fMenu(Air);
		//	D.Construct(Air); // ����������������
		//	menu2(*D, Air);
			product[i] = Air.GetResult();
			i++;
			break;
		case 2:
			//D->Construct(CA); // ����������������
			menu2(*D, CA);
			product[i] = CA.GetResult();
			i++;
			break;
		case 3:
			//D->Construct(Helic); // ����������������
			menu2(*D, Helic);
			product[i] = Helic.GetResult();
			i++;
			break;
		case 4:
			//D->Construct(Quadr); // ����������������
			menu2(*D, Quadr);
			product[i] = Quadr.GetResult();
			i++;
			break;
		case 5:
			loop = false;
		default:
			loop = false;
		}
		if (i == N) { //�������� �� �������
			cout << "���� ���" << endl;
			loop = false;
		}

	} while (loop);
	system("cls");
	/*for (int j = 0; j < i; j++) {
		cout << product[j]->type << endl;
	}*/
	// 2. ������� ���������� ��������� ������ helicopter � ��������� ����������

	// 3. ������� �����-������������� � ���������������� ��� ��������� B
	//Director D;
	//D.Construct(Helic); // ����������������
	//D.Construct(Quadr1); // ����������������
	//D.Construct(Quadr2); // ����������������

	//// 4. ����� ����������������, �������� ��������� ������� �������
	//product[0] = Helic.GetResult();
	//product[1] = Quadr1.GetResult();
	//product[2] = Quadr2.GetResult();

	// 5. ������� �������� �������� ��� ��������
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
		cout << "�������� ��� ������������ ��������:" << endl;
		cout << "1) ������������ �������" << endl;
		cout << "2) ������� �������" << endl;
		cout << "3) ��������" << endl;
		cout << "4) ������������" << endl;
		cout << "5) �����" << endl;
		cin >> choose;

		switch (choose) {
		case 1:
			//D.Construct(Air);
			//D.Edit(Air);
		//	M->fMenu(Air);
		//	D.Construct(Air); // ����������������
			product[i] = Air.GetResult();
			i++;
			break;
		case 2:
			director.Construct(CA); // ����������������
			product[i] = CA.GetResult();
			i++;
			break;
		case 3:
			director.Construct(Helic); // ����������������
			product[i] = Helic.GetResult();
			i++;
			break;
		case 4:
			director.Construct(Quadr); // ����������������
			product[i] = Quadr.GetResult();
			i++;
			break;
		case 5:
			loop = false;
		default:
			loop = false;
		}
		if (i == N) { //�������� �� �������
			cout << "���� ���" << endl;
			loop = false;
		}

	} while (loop);
	delete[] product;
}

void menu2(Director& director, Builder &builder) {
	cout << "1) ����������������" << endl;
	cout << "2) �������������" << endl;
	cout << "3) �������" << endl;
	cout << "4) ��������� � ����" << endl;
	cout << "5) ������� �� ����� �� �����" << endl;
	cout << "6) �����" << endl;
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
