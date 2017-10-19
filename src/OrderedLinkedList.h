/*
 * OrderedLinkedList.h
 *
 *  Created on: Oct 17, 2017
 *      Author: Robin Shaw
 *
 *  solution for checking a string for numbers was referenced from:
 *  http://www.cplusplus.com/forum/beginner/48769/
 */

#ifndef ORDEREDLINKEDLIST_H_
#define ORDEREDLINKEDLIST_H_
#include "LinkedList.h"
#include "Passenger.h"
#include <iostream>
using namespace std;

//Note: OrderedLinkedList is made to work specifically with Passenger objects.
class OrderedLinkedList: public LinkedList<Passenger> {
public:
	int count;
	node<Passenger> *head, *last;
	OrderedLinkedList();
	void search(string, string);
	bool hasNumbers(string);
	void add();
	void deletePass(string, string);
	void printer();
	~OrderedLinkedList();
};

OrderedLinkedList::OrderedLinkedList() {
	head = last = NULL;
	count = 0;
}

void OrderedLinkedList::search(string fName, string lName) {
	node<Passenger> *p = head;
	bool found = false;
	while(p!= NULL){
		if (fName.compare(p->data.getFName()) == 0 && lName.compare(p->data.getLName()) == 0) {
			found = true;
			break;
		}
		p = p->next;
	}
	if (found == true) {
		cout << p->data << endl;
	} else {
		cout << fName << " " << lName << " was not found." << endl;
	}
}

bool OrderedLinkedList::hasNumbers(string test) {
	for (int i = 0; i < test.length(); ++i) {
		if (isdigit(test[i])) {
			return true;
		}
	}
	return false;
}

void OrderedLinkedList::add() {
	node<Passenger> *p = head;
	string inputHolder;

	//put the info into the node:
	node<Passenger> *temp = new node<Passenger>;
	//FIRST NAME
	cout << "Enter a first name (please use all upper case):";
	cin >> inputHolder;
	while (hasNumbers(inputHolder)) {
		cout << "The input is invalid. Please enter no numeric values." <<endl;
		cout << "Please enter a first name (please use all upper case):";
		cin >> inputHolder;
	}
	temp->data.setFName(inputHolder);

	//LAST NAME
	cout << "Enter a last name (please use all upper case):";
	cin >> inputHolder;
	while (hasNumbers(inputHolder)) {
		cout << "The input is invalid. Please enter no numeric values." <<endl;
		cout << "Please enter a first name (please use all upper case):";
		cin >> inputHolder;
	}
	temp->data.setLName(inputHolder);

	//ADDRESS
	cout << "Please enter an address:";
	getline(cin, inputHolder); //Need two of these for some reason. It appears to skip the first.
	getline(cin, inputHolder);
	temp->data.setAddress(inputHolder);

	//PHONE NUMBER
	cout << "Please enter a phone number:";
	cin >> inputHolder;
	temp->data.setPhone(inputHolder);

	//place the node:
	int counter = 0; //needed for final "else"
	while(p!= NULL){
		if (temp->data.mLName.compare(p->data.mLName) < 0) {
			//note to self: direction here may need to be changed
			break;
		}
		++counter;
		p = p->next;
	}
	if (p == head && p == last) { //the list is empty
		cout << "EMPTY" << endl;
		head = last = temp;
		++count;
	} else if (p == head) { //font insert
		cout << "FRONT INSERT" << endl;
		temp->next = head;
		head = temp;
		++count;
	} else if (p == NULL) { //back insert
		cout << "BACK INSERT" << endl;
		last->next = temp;
		last = temp;
		++count;
	} else { //else
		cout << "ELSE" << endl;

		//get p in the right spot, only works and is needed for our else scenario
		p = head;
		for (int i = 0; i < counter-1; ++i) {
			p = p->next;
		}

		temp->next = p->next;
		p->next = temp;
		++count;
	}

}

void OrderedLinkedList::deletePass(string fName, string lName) {
	node<Passenger> *p = head;
	int found = 0; //0 means it wasn't found
	//Check if it's at the head and remove if so:
	if(p != NULL && fName.compare(p->data.mFName) == 0 && lName.compare(p->data.mLName) == 0) {
		cout << p->data << " has been deleted." << endl;
		p = head;
		head = head->next;
		delete p;
		count--;
		if(head==NULL)
			last = NULL;
		found = 2; //2 means it was found in the head.
	}
	//Not found at the head:
	while(p->next != NULL && found != 2){
		if (fName.compare(p->next->data.mFName) == 0 && lName.compare(p->next->data.mLName) == 0) {
			found = 1; //1 means it was found further in the list
			break;
		}
		p = p->next;
	}
	//Removing it:
	if (found == 1) {
		cout << p->next->data << " has been deleted." << endl;
		node<Passenger> *q = p->next;
		p->next = q->next;
		count--;
		if(last == q)
			last = p;
		delete q;
	//It wasn't found in the list:
	} else if (found == 0) {
		cout << fName << " " << lName << " was not found." << endl;
	}
}

void OrderedLinkedList::printer() {
	node<Passenger> *p = head;
	while(p!= NULL){
		cout << p->data << " " << endl;
		p = p->next;
	}
}

OrderedLinkedList::~OrderedLinkedList(){
	destroylist();
}

#endif /* ORDEREDLINKEDLIST_H_ */
