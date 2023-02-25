#include<iostream>
#include<cassert>

using namespace std;
//********************struct nodeType********************
template <class Type>
struct nodeType
{
	Type info;
	nodeType<Type>* link;
};