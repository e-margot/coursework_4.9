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
		/*	cout << "1) ������������ �������" << endl;
			cout << "2) ������� �������" << endl;
			cout << "3) ��������" << endl;
			cout << "4) ������������" << endl;
			cout << ">>";*/
			//cin >> choose2;
			/*switch (choose2) {
			case '1':*/
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
				/*	if (Air!=nullptr && Air->GetResult() != nullptr) {
						int i = 0;
						airliner* A = new airliner;
						D->EditProdukt(product[i], *A);

					   *product[i] = move(*(A->GetResult()));

					}
					else { cout << "������ �� ������!" << endl; }
					break;
				case '2':
					if (CA->GetResult() != nullptr) {
						D->Edit(*CA);
					}
					else { cout << "������ �� ������!" << endl; }
					break;
				case '3':
					if (Helic->GetResult() != nullptr) {
						D->Edit(*Helic);
					}
					else { cout << "������ �� ������!" << endl; }
					break;
				case '4':
					if (Quadr->GetResult() != nullptr) {
						D->Edit(*Quadr);
					}
					else { cout << "������ �� ������!" << endl; }
					break;
				default:
					cout << "������ �����!" << endl;
				}*/
			
			break;
		case '3':
			/*��������*/
			if (!product.empty()) {
				for (int j = 0; j < product.size(); j++) {
					cout << j + 1 << ") " << product[j]->machine << " " << product[j]->type << endl;
				}
				cout << ">>";  cin >> ch; /*����� �� ����*/
				/*int check = D->check(product, ch - 1);
				if (check == 1) { delete CA; CA = nullptr; }
				else if (check == 2) { delete Air; Air = nullptr; }
				else if (check == 3) { delete Quadr; Quadr = nullptr; }
				else if (check == 4) { delete Helic; Helic = nullptr; }*/
				product.erase(product.begin() + (ch-1));
			}
			else {
				cout << "������ ����������� ��������� ����!" << endl;
			}
			break;
		case '4':
			cout << "��������..." << endl;
			/*�������� �� �����*/
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
				//	*product[ch] = move(*(A->GetResult()));
				}
				else if (check == 2) {
					combatAircraft* A = new combatAircraft;
					D->GetProduct(product[ch], *A);
				//	*product[ch] = move(*(A->GetResult()));
				}
				else if (check == 3) {
					quadcopter* A = new quadcopter;
					D->GetProduct(product[ch], *A);
				//	*product[ch] = move(*(A->GetResult()));
				}
				else if (check == 4) {
					helicopter* A = new helicopter;
					D->GetProduct(product[ch], *A);
				//	*product[ch] = move(*(A->GetResult()));
				}
			}
			/*������� �� �����*/
			break;
		case '6':
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
