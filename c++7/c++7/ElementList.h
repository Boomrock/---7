#pragma once
#include <iostream>
template<typename type>
class ElementList
{
public:
	ElementList* NextElement;
	type data;

	ElementList() {
		this->NextElement = NULL;
	}
	ElementList(ElementList& nextElement) {
		this->NextElement = nextElement;
	}
	ElementList(type data, ElementList* nextElement ) {
		this->data = data;
		this->NextElement = nextElement;
	}
	

	/*type& operator =(ElementList rightElement)
	{
		data = rightElement.data;
		return (*this);

	}*/
};

