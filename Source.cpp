#include<iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include<fstream>
#include <vector>
#include <sstream>
#include"Header-Node.h"
#include"Header-Transactions.h"
#include"Header-List.h"
using namespace std;





int main()
{
	int TransNo=1, price2, num;
	time_t timestamp2;
	char choice;
	char* orderID2;
	orderID2 = new char[9];
	string status2;
	string item2;
	string purchaser2, seller2;
	List l;
	Node **n=NULL ;
	string fname = "d:/a.csv";
	vector<vector<string>> content;
	vector<string> row;
	string line, word;

	fstream file(fname, ios::in);
	if (file.is_open())
	{
		while (getline(file, line))
		{
			row.clear();

			stringstream str(line);

			while (getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}
	else
		cout << "Could not open the file\n";

	for (int i = 0; i < content.size(); i++)
	{
		
		
		char c[10];
		strcpy_s(c, content[i][2].c_str());
		
		l.InsertNode(0, atoi(content[i][0].data()), atoi(content[i][1].data()) , c, atoi(content[i][3].data()), content[i][4], content[i][5], content[i][6], content[i][7]);

	}
	do {
		cout << "Menu:" << endl;
		cout << "1. ADD_NEW_ORDER" << endl;
		cout << "2. MODIFY_ORDER_STATUS" << endl;
		cout << "3. CHECK_STATUS" << endl;
		cout << "4. REPORT PURCHASER" << endl;
		cout << "5. REPORT SELLER" << endl;
		cout << "6. EXPORT" << endl;
		cout << "7. DELETE TRANSACTION" << endl;
		cout << "8. RUN SECURITY CHECK" << endl;
		cout << "9. DONE" << endl;

		cout << "Enter the command you want to execute:" << endl;
		cin >> num;
		switch (num) 
		{
		case 1:
			cout << "Enter price: " << endl;
			cin >> price2;
			cin.ignore();
			rand_string(orderID2, 7);
			cout << "Enter item: " << endl;
			getline(cin, item2);
			cout << "Enter purchaser: " << endl;
			getline(cin, purchaser2);
			cout << "Enter seller: " << endl;
			getline(cin, seller2);
			l.InsertNode(0, TransNo++, price2, orderID2, time(NULL), "Order_Placed", item2, purchaser2, seller2);
			l.DisplayList();
			break;


		case 2:
			cout << "Enter the previous oders ID: " << endl;
			cin >> orderID2;
			Node *newNode;
			newNode = l.FindNode_OderID(orderID2);
			cin.ignore();
			cout << "Enter status: " << endl;
			getline(cin, status2);
			l.InsertNode(0, newNode->t.TransactionNo, newNode->t.Price1, newNode->t.OrderID1, newNode->t.Timestamp1, status2, newNode->t.Item1, newNode->t.Purchaser1, newNode->t.Seller1);
			l.DisplayNode(newNode);
			break;

		case 3:
			char* orderID3;
			orderID3 = new char[10];
			cout << "Enter the OderID:" << endl;
			cin>> orderID3;
			Node* newNode3;
			newNode3 = l.FindNode_CHECK_STATUS(orderID3);
		
			
			break;

		case 4:
			cin.ignore();
			cout << "Enter the purchaser:" << endl;
			getline(cin , purchaser2);
			Node* newNode1;
			newNode1=l.FindNode_Purchaser(purchaser2);
			l.DisplayNode(newNode1);
			break;
		case 5:
			cin.ignore();
			cout << "Enter the seller:" << endl;
			getline(cin, seller2);
			Node* newNode2;
			newNode2 = l.FindNode_Seller(seller2);
			l.DisplayNode(newNode2);
			break;

		case 6:
			break;

		case 7:
			int T;
			cout << "Enter Transaction number:" << endl;
			cin >> T;
			Node* newNode7;
			newNode7 = l.FindNode_TransactionNo(T);
			l.DeleteNode(TransNo);
			l.DisplayList();
			break;
		case 8:
			break;
		case 9:
			exit(0);
			break;
        }

		cout << "Do you want to execute another command:" << endl;
		cin >> choice;
	} while ((choice == 'Y') || (choice == 'y'));
	
}