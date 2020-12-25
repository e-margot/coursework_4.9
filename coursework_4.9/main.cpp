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
		cout <<"������� ����:" << endl;
		cout << "1) ��������" << endl;
		cout << "2) ��������������" << endl;
		cout << "3) ��������" << endl;
		cout << "4) �������� �� �����" << endl;
		cout << "5) ������� ��������� ��������" << endl;
		cout << "6) �����" << endl;
		cout << "7) ��������� � ����" << endl;
	//	getline(cin, choose1);
		cin >> choose1;
		cin.ignore();
		//i = atoi(choose1);
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
				cout << "������! ��������� ����" << endl;
			}
			break;
		case '2':
			/*��������������*/
			cout << "��������������" << endl;
			if (!product.empty()) {
				for (int j = 0; j < product.size(); j++) {
					cout << j + 1 << ") " << product[j]->machine << " " << product[j]->type << endl;
				}
				cout << ">>";  cin >> ch; /*����� �� ����*/
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
			/*��������*/
			if (!product.empty()) {
				for (int j = 0; j < product.size(); j++) {
					cout << j + 1 << ") " << product[j]->machine << " " << product[j]->type << endl;
				}
				cout << ">>";  cin >> ch; /*����� �� ����*/
				product.erase(product.begin() + (ch-1));
			}
			else {
				cout << "������ ����������� ��������� ����!" << endl;
			}
			break;
		case '4':
			cout << "��������..." << endl;
			D->FileRead(product, *Air);
			break;
		case '5':
			if (!product.empty()) {
				for (int j = 0; j < product.size(); j++) {
					cout << j + 1 << ") " << product[j]->machine << " " << product[j]->type << endl;
				}
				cout << ">>";  cin >> ch; /*����� �� ����*/
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
			/*������� �� �����*/
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
