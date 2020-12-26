#include "quadcopter.h"

bool quadcopter::isNum(float num) {
	if (num > 0)
		return true;
	else return false;
}
quadcopter::quadcopter()
{
	currentBuilder = nullptr;
}

void quadcopter::CreateProduct()
{
	currentBuilder = new Conveyor();
}
void quadcopter::setMachine() {
	currentBuilder->machine = "������������";
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

void  quadcopter:: setIsMil() {
	currentBuilder->isMilitary = "";

}
void quadcopter::setType() {
	string type;
	cout << "Enter type of plane" << endl;
	cin >> type;
	currentBuilder->type = type;
}//military or civilian - ������� ��� �����������


void quadcopter::setWeihht() {
	float weihht;
	cout << "������� �������� �����" << endl;
	cin >> weihht;
	currentBuilder->weihht = weihht;
} // takeoff weight - �������� �����


void quadcopter::setSpeed() {
	float speed;
	cout << "������� �������� ������" << endl;
	cin >> speed;
	currentBuilder->speed = speed;
}//flight speed - �������� ������



void quadcopter::setControl() {
	string control;
	cout << "������� ������ ����������" << endl;
	cin >> control;
	currentBuilder->control = control;
} //����� ����������


void quadcopter::setYear() {
	int year;
	cout << "������� ��� ������������" << endl;
	cin >> year;
	currentBuilder->year = year;
} //��� ������������

void quadcopter::ofile() {
	ofstream fout;
	fout.open("qudro.txt", ios_base::app);
	fout << "���: " << currentBuilder->type << endl;
	fout << "��� ������������: " << currentBuilder->isMilitary << endl;
	fout << "���: " << currentBuilder->weihht << endl;
	fout << "��������: " << currentBuilder->speed << endl;
	fout << "����������: " << currentBuilder->control << endl;
	fout << "��� ������������: " << currentBuilder->year << endl;
	fout << "----------------\n";
	fout.close();
}//��� ����������
/*void quadcopter::ifile() {
	char line[100][100];
	ifstream fin;
	fin.open("qudro.txt", ios::in);
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
}//��� ����������*/

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
	cout << "���: " << currentBuilder->type << endl;
	cout << "��� ������������: " << currentBuilder->isMilitary << endl;
	cout << "���: " << currentBuilder ->weihht << endl;
	cout << "��������: " << currentBuilder->speed << endl;
	cout << "����������: " << currentBuilder->control << endl;
	cout << "��� ������������: " << currentBuilder->year << endl;
	cout << "----------------\n";
}
void quadcopter::ifile(vector <Conveyor*>& product) {
	string str;
	ifstream fin;
	currentBuilder = new Conveyor();
	fin.open("airliner.txt", ios::in);

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
