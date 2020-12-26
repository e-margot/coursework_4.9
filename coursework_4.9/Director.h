#pragma once
#include "Conveyor.h"
#include "Builder.h"


class Director
{
public:
	void Construct(Builder& builder);
	void EditProduct(Conveyor * product, Builder & builder);
	void GetProduct(Conveyor * product, Builder & builder);
	void File(Builder& builder);
	void clrFile();
	int check(Conveyor* product);
	void FileRead(vector <Conveyor*>& product, Builder & builder);
	void FileWrite(Conveyor * product, Builder & builder);

};