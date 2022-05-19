#pragma once
#include "ElementList.h"
template<typename type>
class List
{	
	int size;
	int numberCurrent;
	ElementList<type>* current;
	ElementList<type>* last;
	void moveCurrentOnPosition(int number);
public:
	List() {

		this->size = 0;
		last = new ElementList<type>();
		current = last;
		numberCurrent = 0;
	
		current->NextElement = last;
		last = current;

	}

	List(int Size) {
		
		this->size = Size;
		ElementList<type>* header = new ElementList<type>();
		current = header;
		numberCurrent = Size-1;
		for (int i = 1; i < Size; i++)
		{
			current->NextElement = new ElementList<type>();
			current = current->NextElement;
		}
		current->NextElement = header;
		last = current;

	}
	~List() {
		
		for (int i = size; i > 0; i--)
		{
			current = last;
			last = last->NextElement;
			delete current;

		}

	}
	
	type& operator [](int n) {
		if (n > size)
			throw "going beyond the borders";
		else if (n < numberCurrent) {
			current = last;
			numberCurrent = size - 1;
		}
		moveCurrentOnPosition(n);

		return current->data;
	}
	void addElement(type data);
	void deleteElement(int number);

	int GetSize() {
		return size;
	}

};

