#include "List.h"
#include "ElementList.h"

template<typename type> type&  
List<type>::operator [](int n) {
	if (n > count) 
		throw "going beyond the borders";
	
	for (int i = current->number; n < count && n != current->number; i++){

		if (i < count) {
			current = current->NextElement;
			i++;
		}
		else {
			i = 0;
		}

	}
	return &current;
}

template<typename type> void
List<type>::addElement(type& element) {
	ElementList<type>* header = last->NextElement;
	last->NextElement = new ElementList<type>(count);
	*(last->NextElement) = element;
	count++;
}

template<typename type> void
List<type>::deleteElement(int n) {
	last = (*this)[count - 2];
	ElementList<type> tmp = last->NextElement;
	last->NextElement = (*this)[0];
	delete tmp;
}