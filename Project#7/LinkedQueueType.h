#include<iostream>
#include<cassert>

using namespace std;

template <class Type>
class linkedQueueType
{
public:
	const linkedQueueType<Type>& operator= (const linkedQueueType<Type>&);
	linkedQueueType(const linkedQueueType<Type>&);

	bool isEmptyQueue() const;
	bool isFullQueue() const;
	void initializeQueue();
	Type front() const;
	Type back() const;
	void addQueue(const Type&);
	void deleteQueue();
	linkedQueueType<Type>();
	~linkedQueueType();
	int queueCount();
	void print();

private:
	nodeType<Type>* queueFront;
	nodeType<Type>* queueRear;
	int count;
	void copyQueue(const linkedQueueType<Type>&);
};

template<class Type>
int linkedQueueType<Type> ::queueCount()
{
	return count;
}

template<class Type>
const linkedQueueType<Type>& linkedQueueType<Type> ::operator=(const linkedQueueType<Type>& otherQueue)
{
	if (this != &otherQueue)
		copyQueue(otherQueue);
	return* this;
}

template<class Type>
linkedQueueType<Type> ::linkedQueueType(const linkedQueueType<Type>& otherQueue)
{
	queueFront = NULL;
	queueRear = NULL;

	copyQueue(otherQueue);
}

template<class Type>
void linkedQueueType<Type> ::copyQueue(const linkedQueueType<Type>& otherQueue)
{
	initializeQueue();
	nodeType<Type>* temp;
	temp = otherQueue.queueFront;

	while (temp != NULL)
	{
		addQueue(temp->info);
		temp = temp->link;
	}
}

template<class Type>
bool linkedQueueType<Type> ::isEmptyQueue() const
{
	return(queueFront == NULL);
}

template<class Type>
bool linkedQueueType<Type> ::isFullQueue() const
{
	return false;
}

template<class Type>
void linkedQueueType<Type> ::initializeQueue()
{
	nodeType<Type>* temp;

	while (queueFront != NULL)
	{
		temp = queueFront;
		queueFront = queueFront->link;
		delete temp;
	}
	count = 0;
	queueRear = NULL;
}

template<class Type>
Type linkedQueueType<Type> ::front() const
{
	assert(queueFront != NULL);
	return queueFront->info;
}

template<class Type>
Type linkedQueueType<Type> ::back() const
{
	assert(queueRear != NULL);
	return queueRear->info;
}

template<class Type>
void linkedQueueType<Type> ::addQueue(const Type& newElement)
{
	nodeType<Type>* newNode;
	newNode = new nodeType<Type>;

	newNode->info = newElement;
	newNode->link = NULL;

	if (queueFront == NULL)
		queueFront = newNode;
	else
		queueRear->link = newNode;

	queueRear = newNode;
	++count;
}

template<class Type>
void linkedQueueType<Type> ::deleteQueue()
{
	nodeType<Type>* temp;
	
	if (!isEmptyQueue())
	{
		temp = queueFront;
		queueFront = queueFront->link;
		delete temp;
		--count;

		if (queueFront == NULL)
			queueRear = NULL;
	}
	else
		cout << "Can not remove from an empty queue.";
}

template<class Type>
linkedQueueType<Type> ::linkedQueueType()
{
	queueFront = NULL;
	queueRear = NULL;
	count = 0;
}

template<class Type>
linkedQueueType<Type> ::~linkedQueueType()
{
	initializeQueue();
}

template<class Type>
void linkedQueueType<Type> ::print()
{
	nodeType<Type>* temp = queueFront;

	while (temp != nullptr)
	{
		cout << temp->info << " ";
		temp = temp->link;
	}
}




