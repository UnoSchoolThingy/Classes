#include "Game.h"

Game::Game() {
    memset(reinterpret_cast<char*>(this) + 0x8, 0, sizeof(Game) - 0x8); // Avoid overwriting vtable pointer 
}

Game::Game(char* title, int year, char* publisher, float rating) {
    memset(reinterpret_cast<char*>(this) + 0x8, 0, sizeof(Game) - 0x8); // Avoid overwriting vtable pointer 
    setTitle(title);
    setYear(year);
    setPublisher(publisher);
    setRating(rating);
}

void Game::setPublisher(char* publisher) {
    strcpy(this->publisher, publisher);
}

void Game::setRating(float rating) {
    this->rating = rating;
}

char* Game::getPublisher() {
    return publisher;
}

float Game::getRating() {
    return rating;
}

const char* Game::getType() {
    return "Video Game";
}

void Game::print() {
    Media::print();
    cout << "Publisher: " << publisher << '\n';
    cout << "Rating: " << rating << '\n';
}

void Game::promptInput() {
    Media::promptInput();
    cout << "Enter publisher: ";
    cin.getline(publisher, 100); // Make sure we don't do (cin >> publisher) because it will only read the first word 
    cout << "Enter rating: ";
    cin >> rating;
    cin.ignore();
}