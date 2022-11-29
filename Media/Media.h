#pragma once
#include <iostream>
#include <cstring>

using std::cout;
using std::cin;

class Media {
private:
	char title[100];
	int year;
public:
	Media();
	~Media();
	void setTitle(char* title);
	void setYear(int year);
	char* getTitle();
	int getYear();
	virtual const char* getType();
	virtual void print();
	virtual void promptInput();
};