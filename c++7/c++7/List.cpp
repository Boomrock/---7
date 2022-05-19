#include "List.h"
#include "ElementList.h"

template<typename type>
void List<type>::moveCurrentOnPosition(int number)
{
	do
	{

		if (numberCurrent < size) {
			current = current->NextElement;
			numberCurrent++;
		}
		else {
			numberCurrent = 0;
		}

	} while (numberCurrent != number);

}

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
	if (size > 1) {
		moveCurrentOnPosition(n - 1);

		ElementList<type>* deleteElement = current->NextElement; /*leftElement = current*/
		ElementList<type>* rightElement = deleteElement->NextElement;
		current->NextElement = rightElement;
		if (n == size - 1) {
			last = current;
		}
		size--;
		numberCurrent = size - 1;
		current = last;
		delete deleteElement;
	}
	else {
		last->data = 0;
		size = 0;
	}

}


