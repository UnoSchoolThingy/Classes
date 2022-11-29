#include "Movie.h"

Movie::Movie() {
    memset(reinterpret_cast<char*>(this) + 0x8, 0, sizeof(Movie) - 0x8); // Avoid overwriting vtable pointer 
}

Movie::Movie(char* title, int year, char* director, int duration, float rating) {
    memset(reinterpret_cast<char*>(this) + 0x8, 0, sizeof(Movie) - 0x8); // Avoid overwriting vtable pointer 
    setTitle(title);
    setYear(year);
    setDirector(director);
    setDuration(duration);
    setRating(rating);
}

void Movie::setDirector(char* director) {
    strcpy(this->director, director);
}

void Movie::setDuration(int duration) {
    this->duration = duration;
}

void Movie::setRating(float rating) {
    this->rating = rating;
}

char* Movie::getDirector() {
    return director;
}

int Movie::getDuration() {
    return duration;
}

float Movie::getRating() {
    return rating;
}

const char* Movie::getType() {
    return "Movie";
}

void Movie::print() {
    Media::print();
    cout << "Director: " << director << '\n';
    cout << "Duration: " << duration << '\n';
    cout << "Rating: " << rating << '\n';
}

void Movie::promptInput() {
    Media::promptInput();
    cout << "Enter director: ";
    cin.getline(director, 100); // Make sure we don't do (cin >> director) because it will only read the first word
    cout << "Enter duration: ";
    cin >> duration;
    cout << "Enter rating: ";
    cin >> rating;
    cin.ignore();
}