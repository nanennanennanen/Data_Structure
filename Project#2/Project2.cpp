#include <iostream>
#include <cassert>
#include <iomanip>
using namespace std;

//partent class
template <class Type>
class stackADT
{
public:
	virtual void initializeStack() = 0;
	virtual bool isEmptyStack() const = 0;
	virtual bool isFullStack() const = 0;
	virtual void push(const Type& newItem) = 0;
	virtual Type top() const = 0;
	virtual void pop() = 0;
};

//child class
template <class Type>
class stackType : public stackADT<Type>// left : right, left derived from right one
{
private:
	int maxStackSize;
	int stackTop;
	Type* list;//ÀÌ°Å¹¹Áö

public:
	void initializeStack()
	{
		stackTop = 0;
		//cout << "stackTop " << stackTop << endl;
	}

	void print()
	{
		for (int i = 0; i < stackTop; i++)
		{
			cout << list[i] << endl;
		}
	}

	bool isEmptyStack() const
	{
		return(stackTop == 0);
	}

	bool isFullStack() const
	{
		return(stackTop == maxStackSize);
	}

	void push(const Type& newItem)
	{
		if (!isFullStack())
		{
			list[stackTop] = newItem;
			stackTop++;
		}
		else
		{
			cout << "Cannot add to a full stack." << endl;
		}
		//cout << "stacktop: " << stackTop << endl;

		//system("pause");
	}

	Type top() const
	{
		assert(stackTop != 0); //if stack is empty, terminate the program.                            
		return list[stackTop - 1];
	}

	void pop()
	{
		if (!isEmptyStack())
			stackTop--;
		else
			cout << "Cannot remove from an empty stack." << endl;

		//cout << "pop: " << stackTop << endl;
	}

	stackType(int stackSize = 100)//default value for the argument
	{
		if (stackSize <= 0)
		{
			cout << "Size of the array to hold the stack must be positive." << endl;
			cout << "Creating an array of size 100." << endl;
			maxStackSize = 100;
		}
		else
		{
			maxStackSize = stackSize;
			//cout << "maxStackSize " << maxStackSize << endl;
		}

		stackTop = 0;
		list = new Type[maxStackSize];
	}

	stackType(const stackType<Type>& otherStack)
	{
		list = NULL;
		copyStack(otherStack);
	}

	~stackType()
	{
		delete[] list;
	}

	const stackType<Type>& operator=(const stackType<Type>& otherStack)
	{
		if (this != &otherStack)// to avoid self-copy
		{
			copyStack(otherStack);
		}
		return *this;// return newly captured copy of stack
	}

	bool operator==(const stackType<Type>& otherStack) const
	{
		if (this == &otherStack)
		{
			return true;
		}
		else
		{
			if (stackTop != otherStack.stackTop)
			{
				return false;
			}
			else
			{
				for (int i = 0; i < stackTop; i++)
				{
					if (list[i] != otherStack.list[i])
					{
						return false;
					}
					return true;
				}
			}
		}
	}

	void copyStack(const stackType<Type>& otherStack)
	{
		delete[] list;
		maxStackSize = otherStack.maxStackSize;
		stackTop = otherStack.stackTop;

		list = new Type[maxStackSize];

		//copy otherStack into this stack. 
		for (int j = 0; j < stackTop; j++)
		{
			list[j] = otherStack.list[j];
		}
	}

	void reverseStack(stackType<Type>& otherStack) {
		delete[] otherStack.list;
		otherStack.maxStackSize = maxStackSize;
		otherStack.stackTop = stackTop;
		otherStack.list = new Type[maxStackSize];
		int j = stackTop - 1;

	//cout << "stack1 stacktop: " << stackTop << endl;
		for (int i = 0; i < stackTop; ++i) {
			//cout << list[i] << " i = " << i << endl;
			otherStack.list[j] = list[i];
			//cout << otherStack.list[j] << " j = " << j << endl;
			--j;
		}
	}


};

int main()
{
	/*Write a program that reads a string consisting of a positive integer or a positive decimal number
	and converts the number to the numeric format.
	If the string consists of a decimal number, 
	the program must use a stack to convert the decimal number to the numeric format.*/

	stackType<char> stack1;
	string str;
	char ch;
	int num;
	bool isDecimal = false;
	int countDeci = 0;
	double fraction = 0;
	double numericNum = 0;
	int integer = 0;
	char response = '\0';

	//do{
		cout << "Enter a positive integer or a positive decimal number : ";
		cin >> str;
		cin.ignore(100, '\n');

		for (int i = 0; i < str.length(); ++i) {
			ch = str.at(i);
			if (ch == '.') {
				isDecimal = true;
			}
			else if (!isDecimal) {
				// 0 = 48 in ascii code.
				int num = ch - 48;
				integer = integer * 10 + num;
			}
			else stack1.push(ch);

		}
		if (isDecimal) {
			while (!stack1.isEmptyStack()) {
				ch = stack1.top();
				stack1.pop();
				num = ch - 48;
				fraction = fraction / 10.0;
				fraction = fraction + num / 10.0;
				countDeci++;

			}
		}

		numericNum = integer + fraction;

		cout << setprecision(countDeci) << fixed;
		cout << "Your Numeric number : " << numericNum << endl;

	/*	cout << "Try again? (Enter 'y') : ";
		cin >> response;
		cin.ignore(100, '\n');
	} while (response == 'y' || response == 'Y');*/





	/*stackType<int> stack1(50);
	stackType<int> stack2(50);

	stack1.initializeStack();
	stack1.push(23);
	stack1.push(45);
	stack1.push(38);

	stack1.print();

	stack2 = stack1;
	
	if (stack1 == stack2)
		cout << "stack1 and stack2 are identical" << endl;
	else
		cout << "stack1 and stack2 are not identical" << endl;

	stack2.pop();
	stack2.push(38);

	cout << "**** after pop and push operations on stack2 ****" << endl;
	if (stack1 == stack2)
		cout << "stack1 and stack2 are identical" << endl;
	else
		cout << "stack1 and stack2 are not identical" << endl;

	stack2.push(11);

	cout << "**** after another push operation on stack2 ****" << endl;
	if (stack1 == stack2)
		cout << "stack1 and stack2 are identical" << endl;
	else
		cout << "stack1 and stack2 are not identical" << endl;*/
	return 0;
}