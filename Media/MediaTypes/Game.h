#pragma once
#include "../Media.h"

class Game : public Media {
private:
	char publisher[100];
	float rating;
public:
	Game();
	Game(char* title, int year, char* publisher, float rating);
	void setPublisher(char* publisher);
	void setRating(float rating);
	char* getPublisher();
	float getRating();
	const char* getType();
	void print();
	void promptInput();
};