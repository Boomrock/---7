#pragma once
#include "ElementList.h"
template<typename type>
class List
{	
	int size;
	int numberCurrent;
	ElementList<type>* current;
	ElementList<type>* last;
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

		do
		 {

			if (numberCurrent < size) {
				current = current->NextElement;
				numberCurrent++;
			}
			else {
				numberCurrent = 0;
			}

		} while (numberCurrent != n);
		return current->data;
	}
	void addElement(type);
	void deleteElement(int);
	int GetSize() {
		return size;
	}

};

