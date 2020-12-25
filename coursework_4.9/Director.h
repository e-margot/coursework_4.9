#pragma once
#include "Conveyor.h"
#include "Builder.h"


class Director
{
public:
	// Метод, конструирующий части
	void Construct(Builder& builder);
	void EditProdukt(Conveyor * product, Builder & builder);
	//void Edit(Builder& builder);
	void Del();
	void Get(Builder& builder);
	void File(Builder& builder);
	void clrFile();
	int check(Conveyor* product);
	//void File(vector <Conveyor*> product);
	//void Edit(vector <Conveyor*> product);
};