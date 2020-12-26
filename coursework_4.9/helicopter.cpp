#include "helicopter.h"

bool helicopter::isNum(float num) {
	if (num > 0)
		return true;
	else return false;
}
void helicopter::setIsMil() {
	int ch;
	while (true) {
		cout << "���:" << endl;
		cout << "1) �����������;" << endl;
		cout << "2) �������;" << endl;
		cin >> ch;
		if (ch == 1) {
			currentBuilder->isMilitary = "�����������";
			return;
		}
		else if (ch == 2) {
			currentBuilder->isMilitary = "�������";
			return;
		}
		else {
			cout << "������ ������� �����������" << endl;
		}
	}
}
void helicopter::setType() {
	cout << "��� ������������ ��������: " << endl;
	cout << ">> ";
	getline(cin, currentBuilder->type);
	system("cls");
}

void helicopter::setWeihht() {
	do {
		string tmp;
		cout << "������� �������� �����" << endl;
		cout << ">> ";
		getline(cin, tmp);
		currentBuilder->weihht = atoi(tmp.c_str());
		system("cls");
	} while (!isNum(currentBuilder->weihht));
}

void helicopter::setEngine() {
	cout << "������� ��� ����������" << endl;
	cout << ">> ";
	getline(cin, currentBuilder->engine);
	system("cls");
}

void helicopter::setNumEngine() {
	do {
		string tmp;
		cout << "������� ���������� ����������" << endl;
		cout << ">> ";
		getline(cin, tmp);
		currentBuilder->NumEngine = atoi(tmp.c_str());
		system("cls");
	} while (!isNum(currentBuilder->NumEngine));
} 
void helicopter::setSpeed() {
	do {
		string tmp;
		cout << "������� �������� ������" << endl;
		cout << ">> ";
		getline(cin, tmp);
		currentBuilder->speed = atoi(tmp.c_str());
		system("cls");
	} while (!isNum(currentBuilder->speed));
}

void helicopter::setTakeoff() {
	cout << "������� ��� ������" << endl;
	cout << ">> ";
	getline(cin, currentBuilder->takeoff);
	system("cls");
}

void helicopter::setLanding() {
	cout << "������� ��� �������" << endl;
	cout << ">> ";
	getline(cin, currentBuilder->landing);
	system("cls");
}


void helicopter::setControl() {
	cout << "������� ������ ����������" << endl;
	cout << ">> ";
	getline(cin, currentBuilder->control);
	system("cls");
}

void helicopter::setCrew() {
	do {
		string tmp;
		cout << "������� ������ (����� ��������)" << endl;
		cout << ">> ";
		getline(cin, tmp);
		currentBuilder->crew = atoi(tmp.c_str());
		system("cls");
	} while (!isNum(currentBuilder->crew));
}

void helicopter::setYear() {
	do {
		string tmp;
		cout << "������� ��� ������������" << endl;
		cout << ">> ";
		getline(cin, tmp);
		currentBuilder->year = atoi(tmp.c_str());
		system("cls");
	} while ((currentBuilder->year) < 1920 || (currentBuilder->year) > 2020);
}

void helicopter::setWeapon() {
	cout << "������� ��� ����������" << endl;
	cout << ">> ";
	getline(cin, currentBuilder->weapon);
	system("cls");
}


/*---------------------------------------*/

void helicopter::setMachine() {
	currentBuilder->machine = "��������";
}

helicopter::helicopter()
{
	currentBuilder = nullptr;
}

void helicopter::CreateProduct()
{
	currentBuilder = new Conveyor();
}

void helicopter::ofile() {
	ofstream fout;
	fout.open("helic.txt", ios_base::app);
	fout << "���: " << currentBuilder->isMilitary << endl;
	fout << "��� �������� ��� ������������ ��������: " << currentBuilder->type << endl;
	fout << "�������� �����: " << currentBuilder->weihht << endl;
	fout << "��� ����������: " << currentBuilder->engine << endl;
	fout << "����� ����������: " << currentBuilder->NumEngine << endl;
	fout << "�������� ������: " << currentBuilder->speed << endl;
	fout << "�� ���� ������: " << currentBuilder->takeoff << endl;
	fout << "�� ���� �������: " << currentBuilder->landing << endl;
	fout << "������ ����������: " << currentBuilder->control << endl;
	fout << "������ (����� �������): " << currentBuilder->crew << endl;
	fout << "��� ������������: " << currentBuilder->year << endl;
	fout << "��� ����������: " << currentBuilder->weapon << endl;
	fout.close();
}

Conveyor* helicopter::GetResult()
{
	return currentBuilder;
}
helicopter::~helicopter()
{
	if (currentBuilder != nullptr)
		delete currentBuilder;
}

void helicopter::toCurrBuild(Conveyor* product) {
	currentBuilder->machine = product->machine;
	currentBuilder->type = product->type;
	currentBuilder->isMilitary = product->isMilitary;
	currentBuilder->weihht = product->weihht;
	currentBuilder->engine = product->engine;
	currentBuilder->NumEngine = product->NumEngine;
	currentBuilder->speed = product->speed;
	currentBuilder->takeoff = product->takeoff;
	currentBuilder->landing = product->landing;
	currentBuilder->control = product->control;
	currentBuilder->crew = product->crew;
	currentBuilder->year = product->year;
	currentBuilder->weapon = product->weapon;
}

void helicopter::Get() {
	cout << "���: " << currentBuilder->type << endl;
	cout << "��� �������� ��� ������������ ��������: " << currentBuilder->isMilitary << endl;
	cout << "�������� �����: " << currentBuilder->weihht << endl;
	cout << "��� ����������: " << currentBuilder->engine << endl;
	cout << "����� ����������: " << currentBuilder->NumEngine << endl;
	cout << "�������� ������: " << currentBuilder->speed << endl;
	cout << "�� ���� ������: " << currentBuilder->takeoff << endl;
	cout << "�� ���� �������: " << currentBuilder->landing << endl;
	cout << "������ ����������: " << currentBuilder->control << endl;
	cout << "������ (����� �������): " << currentBuilder->crew << endl;
	cout << "��� ������������: " << currentBuilder->year << endl;
	cout << "��� ����������: " << currentBuilder->weapon << endl;
	cout << "----------------\n";
}

void helicopter::ifile(vector <Conveyor*>& product) {
	string str;
	ifstream fin;
	currentBuilder = new Conveyor();
	fin.open("helic.txt", ios::in);
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

		currentBuilder->machine = "��������";

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
				if (pos = str.find("��� �������� ��� ������������ ��������: ") != 0) throw 1;
				currentBuilder->type = str.substr(40);
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
		case 7:
			try {
				if (pos = str.find("�� ���� ������: ") != 0) throw 1;

				currentBuilder->takeoff = str.substr(16);
			}
			catch (int i) {
				currentBuilder->takeoff = "-";
			}
			break;
		case 8:
			try {
				if (pos = str.find("�� ���� �������: ") != 0) throw 1;

				currentBuilder->landing = str.substr(17);
			}
			catch (int i) {
				currentBuilder->landing = "-";
			}
			break;
		case 9:
			try {
				if (pos = str.find("������ ����������: ") != 0) throw 1;

				currentBuilder->control = str.substr(11);
			}
			catch (int i) {
				currentBuilder->control = "-";
			}
			break;
		case 10:
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
		case 11:
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
		case 12:
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
