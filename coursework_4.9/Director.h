#pragma once
#include "Conveyor.h"
#include "Builder.h"


class Director
{
public:
	// Метод, конструирующий части
	void Construct(Builder& builder);
	void Edit(Builder& builder);
	void Del();
	void Get(Builder& builder);
	void File(Builder& builder);
	//void File(vector <Conveyor*> product);
	//void Edit(vector <Conveyor*> product);
};