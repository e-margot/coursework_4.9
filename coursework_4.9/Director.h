#pragma once
#include "Conveyor.h"
#include "Builder.h"


class Director
{
public:
	// Метод, конструирующий части
	void Construct(Builder& builder);
	void EditProduct(Conveyor * product, Builder & builder);
	//void Edit(Builder& builder);
	//void Del();
	void GetProduct(Conveyor * product, Builder & builder);
	void File(Builder& builder);
	void clrFile();
	int check(Conveyor* product);
	void FileRead(vector <Conveyor*>& product, Builder & builder);
	void FileWrite(Conveyor * product, Builder & builder);
	//void File(vector <Conveyor*> product);
	//void Edit(vector <Conveyor*> product);
};