#include "quadcopter.h"


bool quadcopter::isNum(float num) {
	if (num > 0)
		return true;
	else return false;
}
void quadcopter::setMachine() {
	currentBuilder->machine = "������������";
}

void quadcopter::setType() {
	cout << "��� ��������" << endl;
	cout << ">> ";
	getline(cin, currentBuilder->type);
	system("cls");
}

void quadcopter::setWeihht() {
	do {
		string tmp;
		cout << "������� �������� �����" << endl;
		cout << ">> ";
		getline(cin, tmp);
		currentBuilder->weihht = atoi(tmp.c_str());
		system("cls");
	} while (!isNum(currentBuilder->weihht));
}



void quadcopter::setSpeed() {
	do {
		string tmp;
		cout << "������� �������� ������" << endl;
		cout << ">> ";
		getline(cin, tmp);
		currentBuilder->speed = atoi(tmp.c_str());
		system("cls");
	} while (!isNum(currentBuilder->speed));
}


void quadcopter::setControl() {
	cout << "������� ������ ����������" << endl;
	cout << ">> ";
	getline(cin, currentBuilder->control);
	system("cls");
}



void quadcopter::setYear() {
	do {
		string tmp;
		cout << "������� ��� ������������" << endl;
		cout << ">> ";
		getline(cin, tmp);
		currentBuilder->year = atoi(tmp.c_str());
		system("cls");
	} while ((currentBuilder->year) < 1920 || (currentBuilder->year) > 2020);
}




/*----------------------------------------------*/

quadcopter::quadcopter()
{
	currentBuilder = nullptr;
}

void quadcopter::CreateProduct()
{
	currentBuilder = new Conveyor();
}

// �����, ������������ ������� ��� �������
Conveyor* quadcopter::GetResult() {
	return currentBuilder;
}

// ����������
quadcopter::~quadcopter()
{
	if (currentBuilder != nullptr)
		delete currentBuilder;
}


void quadcopter::ofile() {
	ofstream fout;
	fout.open("qudro.txt", ios_base::app);
	fout << "���: " << currentBuilder->type << endl;
	fout << "��� ��������: " << currentBuilder->isMilitary << endl;
	fout << "�������� �����: " << currentBuilder->weihht << endl;
	fout << "�������� ������: " << currentBuilder->speed << endl;
	fout << "������ ����������: " << currentBuilder->control << endl;
	fout << "��� ������������: " << currentBuilder->year << endl;
	fout.close();
}

void quadcopter::toCurrBuild(Conveyor* product) {
	currentBuilder->machine = product->machine;
	currentBuilder->type = product->type;
	currentBuilder->isMilitary = product->isMilitary;
	currentBuilder->weihht = product->weihht;
	currentBuilder->speed = product->speed;
	currentBuilder->control = product->control;
	currentBuilder->year = product->year;
}

void quadcopter::Get() {
	cout << "���: " << currentBuilder->isMilitary << endl;
	cout << "��� ��������: " << currentBuilder->type << endl;
	cout << "�������� �����: " << currentBuilder ->weihht << endl;
	cout << "�������� ������: " << currentBuilder->speed << endl;
	cout << "������ ����������: " << currentBuilder->control << endl;
	cout << "��� ������������: " << currentBuilder->year << endl;
	cout << "----------------\n";
}
void quadcopter::ifile(vector <Conveyor*>& product) {
	string str;
	ifstream fin;
	currentBuilder = new Conveyor();
	fin.open("qudro.txt", ios::in);
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

		currentBuilder->machine = "������������";

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
				if (pos = str.find("��� ��������: ") != 0) throw 1;
				currentBuilder->type = str.substr(14);
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
		case 5:
			try {
				if (pos = str.find("������ ����������: ") != 0) throw 1;

				currentBuilder->control = str.substr(11);
			}
			catch (int i) {
				currentBuilder->control = "-";
			}
			break;
		case 6:
			try {
				if (pos = str.find("��� ������������: ") != 0)
					throw 1;

				str = str.substr(18);

				currentBuilder->year = atoi(str.c_str());
				if ((currentBuilder->year) < 2000 || currentBuilder->year > 2020)
					throw 1;
			}
			catch (int i) {
				currentBuilder->year = 2020;
			}
			product.push_back(currentBuilder);
			count = 0;
			currentBuilder = new Conveyor();
			break;
		default:
			break;
		}
		count++;
	}
	fin.close();
}
