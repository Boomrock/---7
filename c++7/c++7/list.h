#pragma once
#include "ElementList.h"
template<typename type>
class List
{	
	int count;
	ElementList<type>* current;
	ElementList<type>* last;
public:
	List(int count) {
		this->count = count;
		ElementList<type>* header = new ElementList<type>(0);
		current = header;
		for (int i = 1; i < count; i++)
		{
			current->NextElement = new ElementList(i);
		}
		current->NextElement = header;
		last = current;

	}
	~List() {
		/*while (header)
		{
			current = header;
			header = header->next;
			delete current;
		}*/

	}
	void addElement(type&);
	void deleteElement(int);
	type& operator [](int);
};

