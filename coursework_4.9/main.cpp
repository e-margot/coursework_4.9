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
	//Director *D = new Director;
	//menu1(*D);
	int i = 0;
	char choose1, choose2;
	int ch;
	bool loop = true;
	//menu *M;
	// ������� main() � ������ ������ ��������� ��������
// 1. �������� ��������� �� �������, ������� ����� ��������
	vector <Conveyor*> product;
	//Conveyor** product = new Conveyor*[N]; //builder
	helicopter *Helic = new helicopter; //concrete builder
	quadcopter* Quadr = new quadcopter;
	airliner* Air = new airliner;
	combatAircraft *CA = new combatAircraft;
	Director *D = new Director;
	do {
		system("cls");
		cout <<"������� ����:" << endl;
		cout << "1) ��������" << endl;
		cout << "2) ��������������" << endl;
		cout << "3) ��������" << endl;
		cout << "4) ����������" << endl;
		cout << "5) ��������" << endl;
		cout << "6) ������� ��������� ��������" << endl;
		cout << "7) �����" << endl;
		cin >> choose1;
		system("cls");
		switch (choose1) {
		case '1':
			cout << "�������� ��� ������������ ��������:" << endl;
			cout << "1) ������������ �������" << endl;
			cout << "2) ������� �������" << endl;
			cout << "3) ��������" << endl;
			cout << "4) ������������" << endl;
			cout << ">>" << endl;
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
			break;
		case '3':
			if (!product.empty()) {
				for (int j = 0; j < product.size(); j++) {
					cout << j + 1 << ") " << product[j]->machine << endl;
						cout<<product[j]->type << endl;
				}
				cout << ">>";
				cin >> ch;
				product.erase(product.begin() + ch - 1);
				/*f_ca.open("combatAircraft.txt", ios_base::trunc);
				f_h.open("helic.txt", ios_base::trunc);
				f_air.open("airliner.txt", ios_base::trunc);
				f_quadr.open("qudro.txt", ios_base::trunc);*/

			}
			else {
				cout << "������ ����������� ��������� ����!" << endl;
			}
			break;
		case '4':
			break;	
		case '5':
			break;
		case '6':
			D->Get(*CA);
			break;
		case '7':
			loop = false;
			break;
		default:
			cout << "������! ��������� ����" << endl;
		}
	} while (loop);
	system("cls");
	if (!product.empty()) {
		for (int j = 0; j < product.size(); j++) {
			cout << product[j]->type << endl;
		}
	}
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
	//delete[] product;
	delete Quadr;
	delete D;
	delete Helic;
	delete CA;
	delete Air;
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
// ���������� �������� � ����� �������

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
