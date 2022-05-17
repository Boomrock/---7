#include "ElementList.h"
template<typename type>
type& ElementList<type>:: operator = (ElementList& rightElement) {
	data = rightElement.data;
	return (*this);
}