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

/*���������� � ������*/
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
		cout <<"������� ����:" << endl;
		cout << "1) ��������" << endl;
		cout << "2) ��������������" << endl;
		cout << "3) ��������" << endl;
		cout << "4) ����������" << endl;
		cout << "5) �������� �� �����" << endl;
		cout << "6) ������� ��������� ��������" << endl;
		cout << "7) �����" << endl;
		cin >> choose1;
		system("cls");
		switch (choose1) {
		case '1':
			/*��������*/
			cout << "��������" << endl;
			cout << "1) ������������ �������" << endl;
			cout << "2) ������� �������" << endl;
			cout << "3) ��������" << endl;
			cout << "4) ������������" << endl;
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
			/*��������������*/
			cout << "��������������" << endl;
			cout << "1) ������������ �������" << endl;
			cout << "2) ������� �������" << endl;
			cout << "3) ��������" << endl;
			cout << "4) ������������" << endl;
			cout << ">>";
			cin >> choose2;
			switch (choose2) {
			case '1':
				if (Air->GetResult()!=nullptr) {
					D->Edit(*Air);
				}
				else { cout << "������ �� ������!" << endl; }
				break;
			case '2':
				if (Air->GetResult() != nullptr) {
					D->Edit(*CA);
				}
				else { cout << "������ �� ������!" << endl; }
				break;
			case '3':
				if (Air->GetResult() != nullptr) {
					D->Edit(*Helic);
				}
				else { cout << "������ �� ������!" << endl; }
				break;
			case '4':
				if (Air->GetResult() != nullptr) {
					D->Edit(*Quadr);
				}
				else { cout << "������ �� ������!" << endl; }
				break;
			default:
				cout << "������ �����!" << endl;
			}
			break;
		case '3':
			/*��������*/
			if (!product.empty()) {
				for (int j = 0; j < product.size(); j++) {
					cout << j + 1 << ") " << product[j]->machine << product[j]->type << endl;
				}
				cout << ">>";
				cin >> ch;
				product.erase(product.begin() + ch - 1);
			}
			else {
				cout << "������ ����������� ��������� ����!" << endl;
			}
			break;
		case '4':
			/*���������� � ����*/
			break;
		case '5':
			/*�������� �� �����*/
			break;
		case '6':
			/*������� �� �����*/
			D->Get(*CA);
			break;
		case '7':
			loop = false;
			break;
		default:
			cout << "������! ��������� ����" << endl;
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
