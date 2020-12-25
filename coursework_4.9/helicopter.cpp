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

void helicopter::setWings() {
	int wings;
	cout << "������� ���������� �������" << endl;
	cin >> wings;
	currentBuilder->wings = wings;
} // number of wings - ����� �������

void helicopter::setArrangW() {
	string arrangW;
	cout << "������� ������������ �������" << endl;
	cin >> arrangW;
	currentBuilder->arrangW = arrangW;
}//arrangement of wings - ������������ �������

void helicopter::setChassis() {
	string chassis;
	cout << "������� ��� �����" << endl;
	cin >> chassis;
	currentBuilder->chassis = chassis;
} // type of chassis - ��� �����

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

void helicopter::Edit(Conveyor* product) {

	currentBuilder->machine = product->machine;

}