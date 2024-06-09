#pragma once
#include"Header-Transactions.h"
class Node {
public:
	Transactions t;
	Node* next;

	Node()
	{
		next = NULL;
	}


};