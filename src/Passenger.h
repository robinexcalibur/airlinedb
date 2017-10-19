/*
 * Passenger.h
 *
 *  Created on: Oct 17, 2017
 *      Author: Robin Shaw
 *
 *  Sources:
 *  https://stackoverflow.com/questions/1488775/c-remove-new-line-from-multiline-string
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_
#include <iostream>
using namespace std;

class Passenger {
private:
public:
	string mFName, mLName, mAddress, mPhone;
	const string& getAddress() const;
	void setAddress(const string& address);
	const string& getFName() const;
	void setFName(const string& fName);
	const string& getLName() const;
	void setLName(const string& lName);
	const string& getPhone() const;
	void setPhone(const string& phone);
	friend ostream& operator<<( ostream&, const Passenger&);
};

inline const string& Passenger::getAddress() const {
	return mAddress;
}

inline void Passenger::setAddress(const string& address) {
	mAddress = address;
	mAddress.erase(mAddress.length()-1); //Needed to get rid of the '/n' that tags along
}

inline const string& Passenger::getFName() const {
	return mFName;
}

inline void Passenger::setFName(const string& fName) {
	mFName = fName;
}

inline const string& Passenger::getLName() const {
	return mLName;
}

inline void Passenger::setLName(const string& lName) {
	mLName = lName;
}

inline const string& Passenger::getPhone() const {
	return mPhone;
}

inline void Passenger::setPhone(const string& phone) {
	mPhone = phone;
}

ostream& operator<<(ostream& os, const Passenger& obj) {
	os << obj.mFName << " " << obj.mLName << " [" << obj.mAddress << "] ["
			<< obj.mPhone << "]";
	return os;
}

#endif /* PASSENGER_H_ */
