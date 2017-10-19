/*
 * PlaneOrderer.cpp
 *
 *  Created on: Oct 17, 2017
 *      Author: Robin Shaw
 *
 *  Source for NULL:
 *  https://stackoverflow.com/questions/7433448/eclipse-cdt-symbol-null-could-not-be-resolved
 */

#ifndef NULL
#define NULL   ((void *) 0)
#endif
#include <iostream>
#include "OrderedLinkedList.h"
#include "Passenger.h"
using namespace std;

int main() {
	OrderedLinkedList *one = new OrderedLinkedList(); //Flight 100
	OrderedLinkedList *two = new OrderedLinkedList(); //Flight 200
	OrderedLinkedList *three = new OrderedLinkedList(); //Flight 300
	OrderedLinkedList *four = new OrderedLinkedList(); //Flight 400



	string fName, lName; //used for inputs
	char command; //the user command
	int flight; //the user's given flight

	cout << "Welcome to Delta Airlines Flight Manager." << endl;
	cout << "Flights available today are: 100, 200, 300, 400." << endl;

	for (;;) { //infinite loop until user closes it with Q
		cout << "Please select an operation:" << endl;
		cout << "A(Add) | S (Search) | D(Delete) |L(List) |Q(Quit):";
		cin >> command;

		//Flight number must be asked for all but Q (for obvious reasons)
		if (command == 'A') { //Add
			//Note: building is done by OrderedLinkedList, not in main.
			cout << "Enter an airline: ";
			cin >> flight;
			if (flight == 100) {
				one->add();
			} else if (flight == 200) {
				two->add();
			} else if (flight == 300) {
				three->add();
			} else if (flight == 400) {
				four->add();
			} else { //The user entered an invalid number
				cout << "Valid airline not given." << endl;
			}
			flight = 5; //this is to assure that flight is reset after every use.


		} else if (command == 'S') { //Search
			//Note: Search requires first and last names are passed as strings.
			//These names must be asked for in main.
			//Printing is done in the Search method.
			cout << "Enter a first name (please use all caps): ";
			cin >> fName;
			cout << "Enter a last name (please use all caps): ";
			cin >> lName;

			cout << "Enter an airline: ";
			cin >> flight;
			if (flight == 100) {
				one->search(fName, lName);
			} else if (flight == 200) {
				two->search(fName, lName);
			} else if (flight == 300) {
				three->search(fName, lName);
			} else if (flight == 400) {
				four->search(fName, lName);
			} else { //The user entered an invalid number
				cout << "Valid airline not given." << endl;
			}
			flight = 5; //this is to assure that flight is reset after every use.

		} else if (command == 'D') { //Delete
			//Note: Delete requires first and last names are passed as strings.
			//These names must be asked for in main.
			cout << "Enter a first name (please use all caps): ";
			cin >> fName;
			cout << "Enter a last name (please use all caps): ";
			cin >> lName;

			cout << "Enter an airline: ";
			cin >> flight;
			if (flight == 100) {
				one->deletePass(fName, lName);
			} else if (flight == 200) {
				two->deletePass(fName, lName);
			} else if (flight == 300) {
				three->deletePass(fName, lName);
			} else if (flight == 400) {
				four->deletePass(fName, lName);
			} else { //The user entered an invalid number
				cout << "Valid airline not given." << endl;
			}
			flight = 5; //this is to assure that flight is reset after every use.

		} else if (command == 'L') { //List
			cout << "Enter an airline: ";
			cin >> flight;
			if (flight == 100) {
				one->printer();
			} else if (flight == 200) {
				two->printer();
			} else if (flight == 300) {
				three->printer();
			} else if (flight == 400) {
				four->printer();
			} else { //The user entered an invalid number
				cout << "Valid airline not given." << endl;
			}
			flight = 5; //this is to assure that flight is reset after every use.

		} else if (command == 'Q') { //Quit
			cout << "The program will now close." << endl;
			cout << "Thanks for running!" << endl;
			break;

		} else { //No valid command
			cout << "No valid command was given." << endl;
			cout << "Please try again." << endl;
		}

	}
	delete one;
	delete two;
	delete three;
	delete four;

}
