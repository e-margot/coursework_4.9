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

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	int i = 0, choose1, choose2, ch;
	string tmp;
	bool loop = true;
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
		cout << "6) ��������� � ����" << endl;
		cout << "7) �����" << endl;
		getline(cin, tmp);
		//cin.ignore();
		choose1 = atoi(tmp.c_str());
		system("cls");
		switch (choose1) {
		case 1:
			/*��������*/
			cout << "��������" << endl;
			cout << "1) ������������ �������" << endl;
			cout << "2) ������� �������" << endl;
			cout << "3) ��������" << endl;
			cout << "4) ������������" << endl;
			cout << ">> ";
			getline(cin, tmp);
			//cin >> choose1;
			//cin.ignore();
			choose2 = atoi(tmp.c_str());
			system("cls");
			switch (choose2) {
			case 1:
				D->Construct(*Air);
				product.push_back(Air->GetResult());
				break;
			case 2:
				D->Construct(*CA);
				product.push_back(CA->GetResult());
				break;
			case 3:
				D->Construct(*Helic);
				product.push_back(Helic->GetResult());
				break;
			case 4:
				D->Construct(*Quadr);
				product.push_back(Quadr->GetResult());
				break;
			default:
				cout << "������! ��������� ����" << endl;
			}
			break;
		case 2:
			/*��������������*/
			cout << "��������������" << endl;
			if (!product.empty()) {
				for (int j = 0; j < product.size(); j++) {
					cout << j + 1 << ") " << product[j]->machine << " " << product[j]->type << endl;
				}
				do {
					cout << ">> ";
					getline(cin, tmp);
					//cin.ignore();
					ch = atoi(tmp.c_str());
					
				} while (ch<0||ch>product.size());
				ch--;
				system("cls");
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
			D->clrFile();
			cout << "�������� ����� '6' ��� ���������� ������." << endl;
			system("pause");
			break;
		case 3:
			/*��������*/
			if (!product.empty()) {
				for (int j = 0; j < product.size(); j++) {
					cout << j + 1 << ") " << product[j]->machine << " " << product[j]->type << endl;
				}
				cout << ">> ";  
				do {
					cout << ">> ";
					getline(cin, tmp);
					//cin.ignore();
					ch = atoi(tmp.c_str());

				} while (ch<0 || ch>product.size());
				//cin >> ch; /*����� �� ����*/
				product.erase(product.begin() + (ch-1));
			}
			else {
				cout << "������ ����������� ��������� ����!" << endl;
				system("pause");
			}

			D->clrFile();
			cout << "�������� ����� '6' ��� ���������� ������." << endl;
			break;
		case 4:
			cout << "1) ������������ �������" << endl;
			cout << "2) ������� �������" << endl;
			cout << "3) ��������" << endl;
			cout << "4) ������������" << endl;
			cout << ">> ";
			getline(cin, tmp);
			//cin >> choose1;
			//cin.ignore();
			choose2 = atoi(tmp.c_str());
			system("cls");
			if (choose2 == 1) {
				airliner* A = new airliner;
				D->FileRead(product, *A);
			}
			else if (choose2 == 2) {
				combatAircraft* A = new combatAircraft;
				D->FileRead(product, *A);
			}
			else if (choose2 == 3) {
				quadcopter* A = new quadcopter;
				D->FileRead(product, *A);
			}
			else if (choose2 == 4) {
				helicopter* A = new helicopter;
				D->FileRead(product, *A);
			}
			else { cout << "������ �� ����������." << endl; }
		//	D->FileRead(product, *Air);
			cout << "�������� ���������." << endl;
			system("pause");
			break;
		case 5:
			if (!product.empty()) {
				for (int j = 0; j < product.size(); j++) {
					cout << j + 1 << ") " << product[j]->machine << " " << product[j]->type << endl;
				}
				do {
					cout << ">> ";
					getline(cin, tmp);
				//	cin.ignore();
					ch = atoi(tmp.c_str());

				} while (ch<0 || ch>product.size());
				ch--;
			//	cout << "��������" << endl;
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
			system("pause");
			/*������� �� �����*/
			break;
		case 6:
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
			cout << "�������� ���������." << endl;
			system("pause");
			break;
		case 7:
			loop = false;
			break;
		default:
			cout << "������! ��������� ����" << endl;
			system("pause");
		}
	
	} while (loop);

	system("cls");
	delete Quadr;
	delete D;
	delete Helic;
	delete CA;
	delete Air;
	return 0;
}
