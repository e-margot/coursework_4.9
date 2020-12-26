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
	cout << "��� �������� ��������: " << endl;
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
	fout << "���: " << currentBuilder->type << endl;
	fout << "��� �������� ���������: " << currentBuilder->isMilitary << endl;
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
	fout << "----------------\n";
	fout.close();
}

void combatAircraft::ifile() {
	char line[100][100];
	ifstream fin;
	fin.open("combatAircraft.txt", ios::in);
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
	cout << "���: " << currentBuilder->type << endl;
	cout << "��� �������� ���������: " << currentBuilder->isMilitary << endl;
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

void combatAircraft::ifile(vector <Conveyor*>& product) {
	string str;
	ifstream fin;
	currentBuilder = new Conveyor();
	fin.open("combatAircraft.txt", ios::in);

	if (!fin.is_open())
		throw exception("���� �� ������� �������!\n");

	if (fin.peek() == EOF)
		throw exception("�a�� ����!\n"); //�� �������� ����, � ������ ��������
	int count = 1, pos = 0;
	while (fin.peek() != EOF)
	{
		getline(fin, str);

		currentBuilder->machine = "������������";

		switch (count)
		{
		case 1:
			if (pos = str.find("���: ") != 0) throw exception("������ ��������\n");

			currentBuilder->type = str.substr(5);
			break;
		case 2:
			if (pos = str.find("��� ������������ ��������: ") != 0) throw exception("������ ��������\n");

			currentBuilder->isMilitary = str.substr(27);
			break;
		case 3:
			if (pos = str.find("�������� �����: ") != 0)
				throw exception("������ ��������\n");

			str = str.substr(16);

			currentBuilder->weihht = atoi(str.c_str());
			if (!isNum(currentBuilder->weihht))
				throw exception("�������� �� ����������\n");
			break;
		case 4:
			if (pos = str.find("��� ����������: ") != 0) throw exception("������ ��������\n");

			currentBuilder->engine = str.substr(16);
			break;
		case 5:
			if (pos = str.find("����� ����������: ") != 0) throw exception("������ ��������\n");

			str = str.substr(18);

			currentBuilder->NumEngine = atoi(str.c_str());
			if (!isNum(currentBuilder->NumEngine))
				throw exception("�������� �� ����������\n");
			break;
		case 6:
			if (pos = str.find("���������� �������: ") != 0) throw exception("������ ��������\n");

			str = str.substr(20);

			currentBuilder->wings = atoi(str.c_str());
			if (!isNum(currentBuilder->wings))
				throw exception("�������� �� ����������\n");
			break;
		case 7:
			if (pos = str.find("������������ �������: ") != 0) throw exception("������ ��������\n");

			currentBuilder->arrangW = str.substr(22);
			break;
		case 8:
			if (pos = str.find("��� �����: ") != 0) throw exception("������ ��������\n");

			currentBuilder->chassis = str.substr(11);
			break;
		case 9:
			if (pos = str.find("�������� ������: ") != 0)
				throw exception("������ ��������\n");

			str = str.substr(17);

			currentBuilder->speed = atoi(str.c_str());
			if (!isNum(currentBuilder->speed))
				throw exception("�������� �� ����������\n");
			break;
		case 10:
			if (pos = str.find("�� ���� ������: ") != 0) throw exception("������ ��������\n");

			currentBuilder->takeoff = str.substr(17); //����

			break;
		case 11:
			if (pos = str.find("�� ���� �������: ") != 0) throw exception("������ ��������\n");

			currentBuilder->landing = str.substr(16);
			break;
		case 12:
			if (pos = str.find("������ ����������: ") != 0) throw exception("������ ��������\n");

			currentBuilder->control = str.substr(11);
			break;
		case 13:
			if (pos = str.find("������ (����� �������): ") != 0)
				throw exception("������ ��������\n");

			str = str.substr(24);

			currentBuilder->crew = atoi(str.c_str());
			if (!isNum(currentBuilder->crew))
				throw exception("�������� �� ����������\n");
			break;
		case 14:
			if (pos = str.find("��� ������������: ") != 0)
				throw exception("������ ��������\n");

			str = str.substr(18);

			currentBuilder->year = atoi(str.c_str());
			if ((currentBuilder->year) < 1920 || currentBuilder->year > 2020)
				throw exception("�������� �� ����������\n");
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