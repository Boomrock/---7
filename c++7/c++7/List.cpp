#include "List.h"
#include "ElementList.h"

template<typename type> void
List<type>:: addElement(type data) {
	if (size > 0) {
		ElementList<type>* header = last->NextElement;
		last->NextElement = new ElementList<type>(data, header);
	}
	else {
		last->data = data;
	}
	size++;
	numberCurrent = size - 1;
	last = last->NextElement;
	current = last;
}

template<typename type> void
List<type>::deleteElement(int n) {
	if(false){
		do
		{

			if (numberCurrent < size) {
				current = current->NextElement;
				numberCurrent++;
			}
			else {
				numberCurrent = 0;
			}

		} while (numberCurrent != size - 2);
		ElementList<type>* header = last->NextElement;
		last = current;
		ElementList<type>* tmp = last->NextElement;
		last->NextElement = header;
		size--;
		numberCurrent = size - 1;
		current = last;
		delete tmp;
	}

	last->data = 0;
	size = 0;
}