#pragma once

#include<iostream>
#include "information.h"

void information::setinformation() {
	cin >> pinformation;
}

void information::getname() {
	size_t i = pinformation.find(",");
	name = pinformation.substr(0,i);
	pinformation = pinformation.substr(++i);
}

void information::getphone() {
	int flag = 0;
	int i;
	for ( i = 0; pinformation.length() && flag == 0; i++) {
		if (pinformation[i] == '1') {
			flag = 1;
			for (int j = i; j <= 11 && flag == 1; j++) {
				if (pinformation[j] < '0' || pinformation[j] > '9') {
					flag = 0;
				}
			}
		}
	}
	phone = pinformation.substr(--i, 11);
	pinformation = pinformation.erase(i, 11);
}

void information::getaddress() {
	address = pinformation;
}

void information::getaddress1() {
	int flag = 0;
	size_t i= address.find("省");
	if (i == address.npos) {
		i = address.find("市");
		if (i != address.npos) {
			address1 = address.substr(0, i);
			address2 = address.substr(0, i + 2);
			address = address.substr(i + 2);
			getaddress3();
			flag = 1;
		}
	}
	if (flag == 0 && i!=address.npos) {
		address1 = address.substr(0, i+2);
		address = address.substr(i+2);
		getaddress2();
	}

}

void information::getaddress2() {
	size_t i = address.find("市");
	if (i != address.npos) {
		address2 = address.substr(0, i + 2);
		address = address.substr(i + 2);
	}
	getaddress3();
}

void information::getaddress3() {
	size_t i = address.find("区");
	if (i == address.npos) {
		i = address.find("县");
		if (i == address.npos) {
			i = address.find("市");
		}
	}
	if (i != address.npos){
		address3 = address.substr(0, i + 2);
		address = address.substr(i + 2);
	}
	getaddress4();
}

void information::getaddress4() {
	int flag = 0;
	size_t i = address.find("街道");
	if (i == address.npos) {
		flag = 1;
		i = address.find("镇");
		if (i == address.npos) {
			i = address.find("乡");
		}
	}
	if (flag == 1 && i!=address.npos) {
		address4 = address.substr(0, i + 2);
		address = address.substr(i + 2);
	}
	else if (flag == 0 && i!=address.npos){
		address4 = address.substr(0, i + 4);
		address = address.substr(i + 4);
	}
	getaddress5();
}

void information::getaddress5() {
	address5 = address;
}

void information::display() {
	cout << "name:" << name << endl;
	cout << "phone:" << phone << endl;
	cout << "address:" << address << endl;
	cout << "address1:" << address1 << endl;
	cout << "address2:" << address2 << endl;
	cout << "address3:" << address3 << endl;
	cout << "address4:" << address4 << endl;
	cout << "address5:" << address5 << endl;
}

void information::doit() {
	setinformation();
	getname();
	getphone();
	getaddress();
	getaddress1();
	display();
}