#pragma once
#include <iostream>
template<typename type>
class ElementList
{
public:
	ElementList* NextElement;
	type data;
	int number;
	ElementList(int number) {
		NextElement = NULL;
		this->number = number;
	}
	~ElementList() {
		delete NextElement;
	}
	type& operator = (ElementList&);
};

