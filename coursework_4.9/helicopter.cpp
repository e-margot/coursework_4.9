#include "helicopter.h"

void helicopter::setMachine() {
	currentBuilder->machine = "��������";
}

helicopter::helicopter()
{
	currentBuilder = nullptr;
}

// ���������� ����������� �������
void helicopter::CreateProduct()
{
	currentBuilder = new Conveyor();
}

void helicopter::setIsMil() {
	int ch;
	while (true) {
		cout << "���:" << endl;
		cout << "1) �����������;" << endl;
		cout << "2) �������;" << endl;
		cin >> ch;
		if (ch == 1) {
			currentBuilder->isMilitary = false;
			break;
		}
		else if (ch == 2) {
			currentBuilder->isMilitary = true;
			break;
		}
		else {
			cout << "������ ������� �����������" << endl;
		}
	}
}
void helicopter::setType() {
	string type;
	cout << "Enter type of plane" << endl;
	cin >> type;
	currentBuilder->type = type;
}//military or civilian - ������� ��� �����������


void helicopter::setWeihht() {
	float weihht;
	cout << "������� �������� �����" << endl;
	cin >> weihht;
	currentBuilder->weihht = weihht;
} // takeoff weight - �������� �����

void helicopter::setEngine() {
	string engine;
	cout << "������� ��� ����������" << endl;
	cin >> engine;
	currentBuilder->engine = engine;
} //type of engines - ��� ����������

void helicopter::setNumEngine() {
	int engine;
	cout << "������� ���������� ����������" << endl;
	cin >> engine;
	currentBuilder->NumEngine = engine;
} //number of engines - ���������� ����������


void helicopter::setSpeed() {
	float speed;
	cout << "������� �������� ������" << endl;
	cin >> speed;
	currentBuilder->speed = speed;
}//flight speed - �������� ������

void helicopter::setTakeoff() {
	string takeoff;
	cout << "������� ��� ������" << endl;
	cin >> takeoff;
	currentBuilder->takeoff = takeoff;
}//��� ������

void helicopter::setLanding() {
	string landing;
	cout << "������� ��� �������" << endl;
	cin >> landing;
	currentBuilder->takeoff = landing;
}//��� �������


void helicopter::setControl() {
	string control;
	cout << "������� ������ ����������" << endl;
	cin >> control;
	currentBuilder->control = control;
} //����� ����������

void helicopter::setCrew() {
	int crew;
	cout << "������� ������ (����� ��������)" << endl;
	cin >> crew;
	currentBuilder->crew = crew;
}//������(�����)

void helicopter::setYear() {
	int year;
	cout << "������� ��� ������������" << endl;
	cin >> year;
	currentBuilder->year = year;
} //��� ������������

void helicopter::SetWeapon() {
	string weapon;
	cout << "������� ��� ����������" << endl;
	cin >> weapon;
	currentBuilder->weapon = weapon;
}//��� ����������
void helicopter::ofile() {
	ofstream fout;
	fout.open("helic.txt", ios_base::app);
	fout << "���: " << currentBuilder->type << endl;
	fout << "��� �������� ��� ������������ ��������: " << currentBuilder->isMilitary << endl;
	fout << "�������� �����: " << currentBuilder->weihht << endl;
	fout << "��� ����������: " << currentBuilder->engine << endl;
	fout << "����� ����������: " << currentBuilder->NumEngine << endl;
	fout << "���������� �������: " << currentBuilder->wings << endl;
	fout << "������������ �������: " << currentBuilder->arrangW << endl;
	fout << "��� �����: " << currentBuilder->chassis << endl;
	fout << "�������� ������: " << currentBuilder->speed << endl;
	fout << "�� ���� ������: " << currentBuilder->takeoff << endl;
	fout << "�� ���� �������: " << currentBuilder->landing << endl;
	fout << "������ ����������: " << currentBuilder->control << endl;
	fout << "������ (����� �������): " << currentBuilder->crew << endl;
	fout << "��� ������������: " << currentBuilder->year << endl;
	fout << "��� ����������: " << currentBuilder->weapon << endl;
	fout << "----------------\n";
	fout.close();
}//��� ����������
void helicopter::ifile() {
	char line[100][100];
	ifstream fin;
	fin.open("helic.txt", ios::in);
	if (!fin)
	{
		cout << "���� �� ������\n\n";
		return;
	}
	int count = 0;
	while (fin.getline(line[count], 100)) count++;
	for (int j = 0; j < count; j++)
	{
		cout << line[j] << endl;
	}
	system("pause");
	fin.close();
}//��� ����������

Conveyor* helicopter::GetResult()
{
	return currentBuilder;
}
//void helicopter::del() {
//	if (currentBuilder != nullptr)
//		delete currentBuilder;
//	i--;
//}
// ����������
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
	currentBuilder->crew= product->crew;
	currentBuilder->year= product->year;
	currentBuilder->weapon= product->weapon;
}

void helicopter::Get() {
	cout << "���: " << currentBuilder->type << endl;
	cout << "��� �������� ��� ������������ ��������: " << currentBuilder->isMilitary << endl;
	cout << "�������� �����: " << currentBuilder->weihht << endl;
	cout << "��� ����������: " << currentBuilder->engine << endl;
	cout << "����� ����������: " << currentBuilder->NumEngine << endl;
	cout << "���������� �������: " << currentBuilder->wings << endl;
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