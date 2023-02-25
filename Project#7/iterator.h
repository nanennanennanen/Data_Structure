#include "struct.h"
//*****************  class linkedListIterator ****************
template <class Type>
class linkedListIterator
{
public:
	linkedListIterator()
	{
		current = nullptr;
	}
	//Default constructor
	//Postcondition: current = nullptr;

	linkedListIterator(nodeType<Type>* ptr)
	{
		current = ptr;
	}
	//Constructor with a parameter.
	//Postcondition: current = ptr;

	Type operator*()
	{
		return current->info;
	}
	//Function to overload the dereferencing operator *.
	//Postcondition: Returns the info contained in the node.

	linkedListIterator<Type> operator++()
	{
		current = current->link;
		return *this;
	}
	//Overload the pre-increment operator.
	//Postcondition: The iterator is advanced to the next 
	//               node.

	bool operator==(const linkedListIterator<Type>& right) const
	{
		return (current == right.current);
	}
	//Overload the equality operator.
	//Postcondition: Returns true if this iterator is equal to 
	//               the iterator specified by right, 
	//               otherwise it returns the value false.

	bool operator!=(const linkedListIterator<Type>& right) const
	{
		return (current != right.current);
	}
	//Overload the not equal to operator.
	//Postcondition: Returns true if this iterator is not  
	//               equal to the iterator specified by  
	//               right; otherwise it returns the value 
	//               false.

private:
	nodeType<Type>* current; //pointer to point to the current 
							 //node in the linked list
};