#pragma once
#include<iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include<fstream>
#include <vector>
#include <sstream>
#include"Header-Node.h"
#include"Header-Transactions.h"
using namespace std;


class List {
private:
	Node* head;
	Node* last;
public:
	List(int ignored = 0)
	{
		head = NULL;
		last = NULL;
	}

	~List()
	{
		Node* current = head;
		Node* next = NULL;

		while (current != NULL)
		{
			next = current->next;
			delete current;
			current = next;

		}
	}



	int DeleteNode(int TransNo) {

		Node* prevNode = NULL;
		Node* currNode = head;
		int currIndex = 1;

		while (currNode && (currNode->t.TransactionNo != TransNo))
		{
			prevNode = currNode;
			currNode = currNode->next;
			currIndex++;

		}

		if (currNode)
		{
			if (prevNode)
			{

				prevNode->next = currNode->next;
				delete currNode;

			}

			else {

				head = currNode->next;
				delete currNode;

			}

			return currIndex;

		}

		return 0;

	}

	Node* InsertNode(int index, int TransNo, int  price, char* orderID, time_t timestamp, string status, string item, string purchaser, string seller) {

		if (index < 0) return NULL;

		int currIndex = 1;

		Node* currNode = head;

		while (currNode && index > currIndex) {

			currNode = currNode->next;
			currIndex++;

		}

		if (index > 0 && currNode == NULL) return NULL;
		Node* newNode = new Node;
		newNode->t.TransactionNo = TransNo;
		// newNode->t.OrderID = oderID;
		strcpy_s(newNode->t.OrderID1, orderID);
		newNode->t.Price1 = price;
		newNode->t.Purchaser1 = purchaser;
		newNode->t.Seller1 = seller;
		newNode->t.Status1 = status;
		newNode->t.Timestamp1 = timestamp;

		if (index == 0) {

			newNode->next = head;

			head = newNode;

		}

		else {

			newNode->next = currNode->next;

			currNode->next = newNode;

		}

		return newNode;

	}
	Node* FindNode_OderID(char oderID3[10]) {

		Node* currNode = head;
		int currIndex = 1;

		while (currNode) {

			if (strcmp(currNode->t.OrderID1, oderID3) == 0)
				break;

			currNode = currNode->next;

			currIndex++;

		}

		if (currNode)
			return currNode;

		return 0;

	}


	Node* FindNode_TransactionNo(int TransNo)
	{
		Node* currNode = head;
		int currIndex = 1;

		while (currNode && (currNode->t.TransactionNo != TransNo)) {

			currNode = currNode->next;
			currIndex++;

		}

		if (currNode)
			return currNode;

		return 0;

	}

	Node* FindNode_Seller(string seller)
	{
		Node* currNode = head;
		int currIndex = 1;

		while (currNode && (currNode->t.Seller1.compare(seller))) {

			currNode = currNode->next;
			currIndex++;

		}

		if (currNode)
			return currNode;

		return 0;

	}

	Node* FindNode_Purchaser(string purchaser)
	{
		Node* currNode = head;
		int currIndex = 1;


		while (currNode && (currNode->t.Purchaser1.compare(purchaser))) {
			currNode = currNode->next;
			currIndex++;

		}

		if (currNode)
			return currNode;

		return 0;

	}
	Node* FindNode_CHECK_STATUS(char orderID[8])
	{
		Node* currNode = head;
		int currIndex = 1;

		while (currNode)
		{
			if (strcmp(currNode->t.OrderID1, (orderID)) == 0)
				break;
			currNode = currNode->next;
			currIndex++;

		}

		//if (currNode)
			//return currNode;

		cout << "Transaction No\tOderID\t\tPrice\tPurchaser\tSeller \t\tStatus\t\tTimestamp" << endl;
		cout << currNode->t.TransactionNo << "\t\t" << currNode->t.OrderID1 << "\t" << currNode->t.Price1 << "\t" << currNode->t.Purchaser1 << "\t\t" << currNode->t.Seller1 << "\t" << currNode->t.Status1 << "\t" << currNode->t.Timestamp1 << endl;

		return 0;
	}


	void DisplayNode(Node* n)
	{
		cout << "Transaction No:" << n->t.TransactionNo << endl;
		cout << "OderID:" << n->t.OrderID1 << endl;
		cout << "Price:" << n->t.Price1 << endl;
		cout << "Purchaser:" << n->t.Purchaser1 << endl;
		cout << "Seller:" << n->t.Seller1 << endl;
		cout << "Status:" << n->t.Status1 << endl;
		cout << "Timestamp:" << n->t.Timestamp1 << endl;
	}

	void DisplayList()

	{

		int num = 0;

		Node* currNode = head;

		while (currNode != NULL) {

			cout << "Transaction No:" << currNode->t.TransactionNo << endl;
			cout << "OderID:" << currNode->t.OrderID1 << endl;
			cout << "Price:" << currNode->t.Price1 << endl;
			cout << "Purchaser:" << currNode->t.Purchaser1 << endl;
			cout << "Seller:" << currNode->t.Seller1 << endl;
			cout << "Status:" << currNode->t.Status1 << endl;
			cout << "Timestamp:" << currNode->t.Timestamp1 << endl;

			currNode = currNode->next;

			num++;

		}

		cout << "Number of nodes in the list: " << num << endl;

	}
};


void rand_string(char* d, int length) {
	char charset[] = "0123456789"
		"abcdefghijklmnopqrstuvwxyz"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	while (length-- > 0) {
		int index = (double)rand() / RAND_MAX * (sizeof charset - 1);
		*d++ = charset[index];
	}
	*d = '\0';
}
