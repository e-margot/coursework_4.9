#pragma once
#include "Conveyor.h"
#include "Builder.h"


class Director
{
public:
	// �����, �������������� �����
	void Construct(Builder& builder);
	void Edit(Builder& builder);
	void Del(Builder& builder);
	void Get(Builder& builder);
};