#include "combatAircraft.h"
#include "combatAircraft.h"


bool combatAircraft:: isNum(float num) {
	if (num > 0)
		return true;
	else return false;
}
void combatAircraft::setIsMil() {
	currentBuilder->isMilitary = "�������";
}
void combatAircraft::setType() {
	cout << "��� �������� ��������" << endl;
	cout << ">> ";
	getline(cin, currentBuilder->type);
	system("cls");
}
void combatAircraft::setWeihht() {
	do {
		string tmp;
		cout << "������� �������� �����" << endl;
		cout << ">> ";
		getline(cin, tmp);
		currentBuilder->weihht = atoi(tmp.c_str());
		system("cls");
	} while (!isNum(currentBuilder->weihht));
}

void combatAircraft::setEngine() {
	cout << "������� ��� ����������" << endl;
	cout << ">> ";
	getline(cin, currentBuilder->engine);
	system("cls");
}

void combatAircraft::setNumEngine() {
	do {
		string tmp;
		cout << "������� ���������� ����������" << endl;
		cout << ">> ";
		getline(cin, tmp);
		currentBuilder->NumEngine = atoi(tmp.c_str());
		system("cls");
	} while (!isNum(currentBuilder->NumEngine));
} 

void combatAircraft::setWings() {
	do {
		string tmp;
		cout << "������� ���������� �������" << endl;
		cout << ">> ";
		getline(cin, tmp);
		currentBuilder->wings = atoi(tmp.c_str());
		system("cls");
	} while (!isNum(currentBuilder->wings));
}

void combatAircraft::setArrangW() {
	cout << "������� ������������ �������" << endl;
	cout << ">> ";
	getline(cin, currentBuilder->arrangW);
	system("cls");
}

void combatAircraft::setChassis() {
	cout << "������� ��� �����" << endl;
	cout << ">> ";
	getline(cin, currentBuilder->chassis);
	system("cls");
}

void combatAircraft::setSpeed() {
	do {
		string tmp;
		cout << "������� �������� ������" << endl;
		cout << ">> ";
		getline(cin, tmp);
		currentBuilder->speed = atoi(tmp.c_str());
		system("cls");
	} while (!isNum(currentBuilder->speed));
}

void combatAircraft::setTakeoff() {
	cout << "������� ��� ������" << endl;
	cout << ">> ";
	getline(cin, currentBuilder->takeoff);
	system("cls");
}

void combatAircraft::setLanding() {
	cout << "������� ��� �������" << endl;
	cout << ">> ";
	getline(cin, currentBuilder->landing);
	system("cls");
}


void combatAircraft::setControl() {
	cout << "������� ������ ����������" << endl;
	cout << ">> ";
	getline(cin, currentBuilder->control);
	system("cls");
}

void combatAircraft::setCrew() {
	do {
		string tmp;
		cout << "������� ������ (����� ��������)" << endl;
		cout << ">> ";
		getline(cin, tmp);
		currentBuilder->crew = atoi(tmp.c_str());
		system("cls");
	} while (!isNum(currentBuilder->crew));
}

void combatAircraft::setYear() {
	do {
		string tmp;
		cout << "������� ��� ������������" << endl;
		cout << ">> ";
		getline(cin, tmp);
		currentBuilder->year = atoi(tmp.c_str());
		system("cls");
	} while ((currentBuilder->year) < 1920 || (currentBuilder->year) > 2020);
}




void combatAircraft::setWeapon() {
	cout << "������� ��� ����������" << endl;
	cout << ">> ";
	getline(cin, currentBuilder->weapon);
	system("cls");
}





/*----------------------------------------------*/



void combatAircraft::ofile() {
	ofstream fout;
	fout.open("combatAircraft.txt", ios_base::app);
	fout << "���: " << currentBuilder->isMilitary << endl;
	fout << "��� �������� ���������: " << currentBuilder->type << endl;
	fout << "�������� �����: " << currentBuilder->weihht << endl;
	fout << "��� ����������: " << currentBuilder->engine << endl;
	fout << "����� ����������: " << currentBuilder->NumEngine << endl;
	fout << "���������� �������:" << currentBuilder->wings << endl;
	fout << "������������ �������: " << currentBuilder->arrangW << endl;
	fout << "��� �����: " << currentBuilder->chassis << endl;
	fout << "�������� ������: " << currentBuilder->speed << endl;
	fout << "�� ���� ������: " << currentBuilder->takeoff << endl;
	fout << "�� ���� �������: " << currentBuilder->landing << endl;
	fout << "������ ����������: " << currentBuilder->control << endl;
	fout << "������ (����� �������): " << currentBuilder->crew << endl;
	fout << "��� ������������: " << currentBuilder->year << endl;
	fout << "��� ����������: " << currentBuilder->weapon << endl;
	fout.close();
}

void combatAircraft::ifile(vector <Conveyor*>& product) {
	string str;
	ifstream fin;
	currentBuilder = new Conveyor();
	fin.open("combatAircraft.txt", ios::in);
	try {
		if (!fin.is_open())
			throw 1;

		if (fin.peek() == EOF)
			throw 1;
	}
	catch (int i)
	{
		cout << "�� ������� ������� ����." << endl;
		return;
	}
	int count = 1, pos = 0;
	while (fin.peek() != EOF)
	{
		getline(fin, str);

		currentBuilder->machine = "�������";

		switch (count)
		{
		case 1:
			try {
				if (pos = str.find("���: ") != 0) throw 1;
				currentBuilder->isMilitary = str.substr(5);
			}
			catch (int i) {
				currentBuilder->isMilitary = "-";
			}
			break;
		case 2:
			try {
				if (pos = str.find("��� �������� ��������: ") != 0) throw 1;
				currentBuilder->type = str.substr(27);
			}
			catch (int i) {
				currentBuilder->type = "-";
			}

			break;
		case 3:
			try {
				if (pos = str.find("�������� �����: ") != 0)
					throw 1;
				str = str.substr(16);

				currentBuilder->weihht = atoi(str.c_str());
				if (!isNum(currentBuilder->weihht))
					throw 1;

			}
			catch (int i) {
				currentBuilder->weihht = 0;
			}
			break;
		case 4:
			try {
				if (pos = str.find("��� ����������: ") != 0) throw 1;
				currentBuilder->engine = str.substr(16);
			}
			catch (int i) {
				currentBuilder->engine = "-";
			}
			break;
		case 5:
			try {
				if (pos = str.find("����� ����������: ") != 0) throw 1;

				str = str.substr(18);

				currentBuilder->NumEngine = atoi(str.c_str());
				if (!isNum(currentBuilder->NumEngine))
					throw 1;
			}
			catch (int i) {
				currentBuilder->NumEngine = 0;
			}
			break;
		case 6:
			try {
				if (pos = str.find("���������� �������: ") != 0) throw 1;

				str = str.substr(20);

				currentBuilder->wings = atoi(str.c_str());
				if (!isNum(currentBuilder->wings))
					throw 1;

			}
			catch (int i) {
				currentBuilder->wings = 0;
			}
			break;
		case 7:
			try {
				if (pos = str.find("������������ �������: ") != 0) throw 1;
				currentBuilder->arrangW = str.substr(22);
			}
			catch (int i) {
				currentBuilder->arrangW = "-";
			}
			break;
		case 8:
			try {
				if (pos = str.find("��� �����: ") != 0) throw 1;

				currentBuilder->chassis = str.substr(11);
			}
			catch (int i) {
				currentBuilder->chassis = "-";
			}
			break;
		case 9:
			try {
				if (pos = str.find("�������� ������: ") != 0)
					throw 1;

				str = str.substr(17);

				currentBuilder->speed = atoi(str.c_str());
				if (!isNum(currentBuilder->speed))
					throw 1;
			}
			catch (int i) {
				currentBuilder->speed = 0;
			}
			break;
		case 10:
			try {
				if (pos = str.find("�� ���� ������: ") != 0) throw 1;

				currentBuilder->takeoff = str.substr(16);
			}
			catch (int i) {
				currentBuilder->takeoff = "-";
			}
			break;
		case 11:
			try {
				if (pos = str.find("�� ���� �������: ") != 0) throw 1;

				currentBuilder->landing = str.substr(17);
			}
			catch (int i) {
				currentBuilder->landing = "-";
			}
			break;
		case 12:
			try {
				if (pos = str.find("������ ����������: ") != 0) throw 1;

				currentBuilder->control = str.substr(11);
			}
			catch (int i) {
				currentBuilder->control = "-";
			}
			break;
		case 13:
			try {
				if (pos = str.find("������ (����� �������): ") != 0)
					throw 1;

				str = str.substr(24);

				currentBuilder->crew = atoi(str.c_str());
				if (!isNum(currentBuilder->crew))
					throw 1;
			}
			catch (int i) {
				currentBuilder->crew = 0;
			}
			break;
		case 14:
			try {
				if (pos = str.find("��� ������������: ") != 0)
					throw 1;

				str = str.substr(18);

				currentBuilder->year = atoi(str.c_str());
				if ((currentBuilder->year) < 1920 || currentBuilder->year > 2020)
					throw 1;
			}
			catch (int i) {
				currentBuilder->year = 2020;
			}
			
			break;
		case 15: 
			try {
				if (pos = str.find("��� ����������: ") != 0) throw 1;

				currentBuilder->weapon = str.substr(16);
			}
			catch (int i) {
				currentBuilder->weapon = "-";
			}
			product.push_back(currentBuilder);
			count = 0;
			currentBuilder = new Conveyor();
		default:
			break;
		}
		count++;
	}
	fin.close();
}

combatAircraft::combatAircraft()
{
	currentBuilder = nullptr;
}
void combatAircraft::CreateProduct()
{
	currentBuilder = new Conveyor();
}
Conveyor*combatAircraft::GetResult()
{
	return currentBuilder;
}
combatAircraft::~combatAircraft()
{
	if (currentBuilder != nullptr)
		delete currentBuilder;
}

void combatAircraft::setMachine() {
	currentBuilder->machine = "�������";
}
void combatAircraft::toCurrBuild(Conveyor* product)
{
	currentBuilder->machine = product->machine;
	currentBuilder->type = product->type;
	currentBuilder->isMilitary = product->isMilitary;
	currentBuilder->weihht = product->weihht;
	currentBuilder->engine = product->engine;
	currentBuilder->NumEngine = product->NumEngine;
	currentBuilder->wings = product->wings;
	currentBuilder->arrangW = product->arrangW;
	currentBuilder->chassis= product->chassis;
	currentBuilder->speed = product->speed;
	currentBuilder->takeoff = product->takeoff;
	currentBuilder->landing = product->landing;
	currentBuilder->control = product->control;
	currentBuilder->crew = product->crew;
	currentBuilder->year = product->year;
	currentBuilder->weapon = product->weapon;
}

void combatAircraft::Get() {
	cout << "���: " << currentBuilder->isMilitary << endl;
	cout << "��� �������� ���������: " << currentBuilder->type << endl;
	cout << "�������� �����: " << currentBuilder->weihht << endl;
	cout << "��� ����������: " << currentBuilder->engine << endl;
	cout << "����� ����������: " << currentBuilder->NumEngine << endl;
	cout << "���������� �������:" << currentBuilder->wings << endl;
	cout << "������������ �������: " << currentBuilder->arrangW << endl;
	cout << "��� �����: " << currentBuilder->chassis << endl;
	cout << "�������� ������: " << currentBuilder->speed << endl;
	cout << "�� ���� ������: " << currentBuilder->takeoff << endl;
	cout << "�� ���� �������: " << currentBuilder->landing << endl;
	cout << "������ ����������: " << currentBuilder->control << endl;
	cout << "������ (����� �������): " << currentBuilder->crew << endl;
	cout << "��� ������������: " << currentBuilder->year << endl;
	cout << "��� ����������: " << currentBuilder->weapon << endl;
	cout << "----------------\n";
}

