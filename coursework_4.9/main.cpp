#include <iostream>
using namespace std;
// �����, ������� ���� ���������
class Conveyor
{
public:
	//int lopasti; // ����� 1
	//int engine; // ����� 2
	string type; //military or civilian - ������� ��� �����������
	string Mil;//  type of military apparatus - ��� �������� ��������
	string Civ; //type of civilian apparatus - ��� ������������ ��������
	float weihht; // takeoff weight - �������� �����
	string engine; //type of engines - ��� ����������
	int NumEngine; //number of engines - ���������� ����������
	int wings; // number of wings - ����� �������
	string arrangW; //arrangement of wings - ������������ �������
	string chassis; // type of chassis - ��� �����
	float speed;//flight speed - �������� ������
	string takeoff;//��� ������
	string landing;//��� �������
	string control; //����� ����������
	int crew; //������(�����)
	int year; //��� ������������
	string weapon; //��� ����������
};

// �����, ������� ��������� ��������� � ��������
//���������� �������
class Builder
{
public:
	virtual void CreateProduct() {}
	virtual void setType(string type) {}//military or civilian - ������� ��� �����������
	virtual void setMil(string Mil) {}//  type of military apparatus - ��� �������� ��������
	virtual void setCiv(string Civ) {} //type of civilian apparatus - ��� ������������ ��������
	virtual void setWeihht(float weihht) {} // takeoff weight - �������� �����
	virtual void setEngine(string engine) {} //type of engines - ��� ����������
	virtual void setEngine(int NumEngine) {} //number of engines - ���������� ����������
	virtual void setWings(int wings) {} // number of wings - ����� �������
	virtual void setArrangW(string arrangW) {}//arrangement of wings - ������������ �������
	virtual void setChassis(string chassis) {} // type of chassis - ��� �����
	virtual void setSpeed(float speed) {}//flight speed - �������� ������
	virtual void setTakeoff(string takeoff) {}//��� ������
	virtual void setLanding(string landing) {}//��� �������
	virtual void setControl(string control) {} //����� ����������
	virtual void setCrew(int crew) {}//������(�����)
	virtual void setYear(int year) {} //��� ������������
	virtual void SetWeapon(string weapon) {}//��� ����������
	/*virtual void BuildLopasti(int lopasti) { }
	virtual void BuildEngine(int engine) { }*/
	virtual Conveyor* GetResult() { return nullptr; }
};

// �����, ������� ���� ���������� ����������
class helicopter : public Builder
{
private:
	Conveyor* currentBuilder;

public:
	// �����������
	helicopter()
	{
		currentBuilder = nullptr;
	}

	// ���������� ����������� �������
	virtual void CreateProduct()
	{
		cout << "helicopter::CreateProduct()" << endl;
		currentBuilder = new Conveyor();
	}
	virtual void setType(string type) {
		currentBuilder->type = type;
	}//military or civilian - ������� ��� �����������

	virtual void setMil(string Mil) {
		currentBuilder->Mil = Mil;
	}//  type of military apparatus - ��� �������� ��������

	virtual void setCiv(string Civ) {
		currentBuilder->Civ = Civ;
	} //type of civilian apparatus - ��� ������������ ��������

	virtual void setWeihht(float weihht) {
		currentBuilder->weihht = weihht;
	} // takeoff weight - �������� �����

	virtual void setEngine(string engine) {
		currentBuilder->engine = engine;
	} //type of engines - ��� ����������

	virtual void setEngine(int engine) {
		currentBuilder->NumEngine = engine;
	} //number of engines - ���������� ����������

	virtual void setWings(int wings) {
		currentBuilder->wings = wings;
	} // number of wings - ����� �������

	virtual void setArrangW(string arrangW) {
		currentBuilder->arrangW = arrangW;
	}//arrangement of wings - ������������ �������

	virtual void setChassis(string chassis) {
		currentBuilder->chassis = chassis;
	} // type of chassis - ��� �����

	virtual void setSpeed(float speed) {
		currentBuilder->speed = speed;
	}//flight speed - �������� ������

	virtual void setTakeoff(string takeoff) {
		currentBuilder->takeoff = takeoff;
	}//��� ������

	virtual void setLanding(string landing) {
		currentBuilder->takeoff = landing;
	}//��� �������

	virtual void setControl(string control) {
		currentBuilder->control = control;
	} //����� ����������

	virtual void setCrew(int crew) {
		currentBuilder->crew = crew;
	}//������(�����)

	virtual void setYear(int year) {
		currentBuilder->year = year;
	} //��� ������������

	virtual void SetWeapon(string weapon) {
		currentBuilder->weapon = weapon;

	}//��� ����������

// ��������� ����� 1
	//virtual void BuildLopasti(int lopasti)
	//{
	//	cout << "helicopter::currentBuilder->lopasti = " << lopasti << endl;
	//	currentBuilder->lopasti = lopasti;
	//}

	//// ��������� ����� 2
	//virtual void BuildEngine(int engine)
	//{
	//	cout << "helicopter::currentBuilder->engine = " << engine << endl;
	//	currentBuilder->engine = engine;
	//}

	// �����, ������������ ������� ��� �������
	virtual Conveyor* GetResult()
	{
		return currentBuilder;
	}

	// ����������
	~helicopter()
	{
		if (currentBuilder != nullptr)
			delete currentBuilder;
	}
};

class combatAircraft : public Builder
{
private:
	Conveyor* currentBuilder;

public:
	// �����������
	combatAircraft()
	{
		currentBuilder = nullptr;
	}

	// ���������� ����������� �������
	virtual void CreateProduct()
	{
		cout << "helicopter::CreateProduct()" << endl;
		currentBuilder = new Conveyor();
	}

	// ��������� ����� 1
	//virtual void BuildLopasti(int lopasti)
	//{
	//	cout << "helicopter::currentBuilder->lopasti = " << lopasti << endl;
	//	currentBuilder->lopasti = lopasti;
	//}

	//// ��������� ����� 2
	//virtual void BuildEngine(int engine)
	//{
	//	cout << "helicopter::currentBuilder->engine = " << engine << endl;
	//	currentBuilder->engine = engine;
	//}

	// �����, ������������ ������� ��� �������
	virtual Conveyor* GetResult()
	{
		return currentBuilder;
	}

	// ����������
	~combatAircraft()
	{
		if (currentBuilder != nullptr)
			delete currentBuilder;
	}
};

class airliner : public Builder
{
private:
	Conveyor* currentBuilder;

public:
	// �����������
	airliner()
	{
		currentBuilder = nullptr;
	}

	// ���������� ����������� �������
	virtual void CreateProduct()
	{
		cout << "helicopter::CreateProduct()" << endl;
		currentBuilder = new Conveyor();
	}

	// ��������� ����� 1
	//virtual void BuildLopasti(int lopasti)
	//{
	//	cout << "helicopter::currentBuilder->lopasti = " << lopasti << endl;
	//	currentBuilder->lopasti = lopasti;
	//}

	//// ��������� ����� 2
	//virtual void BuildEngine(int engine)
	//{
	//	cout << "helicopter::currentBuilder->engine = " << engine << endl;
	//	currentBuilder->engine = engine;
	//}

	// �����, ������������ ������� ��� �������
	virtual Conveyor* GetResult()
	{
		return currentBuilder;
	}

	// ����������
	~airliner()
	{
		if (currentBuilder != nullptr)
			delete currentBuilder;
	}
};

class quadcopter : public Builder
{
private:
	Conveyor* currentBuilder;

public:
	// �����������
	quadcopter()
	{
		currentBuilder = nullptr;
	}

	// ���������� ����������� �������
	virtual void CreateProduct()
	{
		cout << "helicopter::CreateProduct()" << endl;
		currentBuilder = new Conveyor();
	}



	// ��������� ����� 2
	//virtual void BuildEngine(int engine)
	//{
	//	cout << "quadcopter::currentBuilder->engine = " << engine << endl;
	//	currentBuilder->engine = engine;
	//}

	// �����, ������������ ������� ��� �������
	virtual Conveyor* GetResult()
	{
		return currentBuilder;
	}

	// ����������
	~quadcopter()
	{
		if (currentBuilder != nullptr)
			delete currentBuilder;
	}
};
// ����� - �������������
class Director
{
public:
	// �����, �������������� �����
	void Construct(Builder& builder)
	{
		// 1. ������� �������
		builder.CreateProduct();

		//// 2. ��������� ����� 1
		//builder.BuildLopasti(25);

		//// 3. ��������� ����� 2
		//builder.BuildEngine(777);
	}
};

int main()
{
	int N = 0;
	cout << "Enter N" << endl;
	cin >> N;
	// ������� main() � ������ ������ ��������� ��������
	// 1. �������� ��������� �� �������, ������� ����� ��������
	Conveyor** product = new Conveyor*[N]; //builder

	// 2. ������� ���������� ��������� ������ helicopter � ��������� ����������
	helicopter Helic; //concrete builder
	quadcopter Quadr1;
	quadcopter Quadr2;

	// 3. ������� �����-������������� � ���������������� ��� ��������� B
	Director D;
	D.Construct(Helic); // ����������������
	D.Construct(Quadr1); // ����������������
	D.Construct(Quadr2); // ����������������

	// 4. ����� ����������������, �������� ��������� ������� �������
	product[0] = Helic.GetResult();
	product[1] = Quadr1.GetResult();
	product[2] = Quadr2.GetResult();

	// 5. ������� �������� �������� ��� ��������
	/*cout << "product->lopasti = " << product->lopasti << endl;
	cout << "product->engine = " << product->engine << endl;*/
	system("pause");
	return 0;
}