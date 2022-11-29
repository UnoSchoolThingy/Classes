#include "Music.h"

Music::Music() {
    memset(reinterpret_cast<char*>(this) + 0x8, 0, sizeof(Music) - 0x8); // Avoid overwriting vtable pointer 
}

Music::Music(char* title, int year, char* artist, int duration, char* publisher) {
    memset(reinterpret_cast<char*>(this) + 0x8, 0, sizeof(Music) - 0x8); // Avoid overwriting vtable pointer 
    setTitle(title);
    setYear(year);
    setArtist(artist);
    setDuration(duration);
    setPublisher(publisher);
}

void Music::setArtist(char* artist) {
    strcpy(this->artist, artist);
}

void Music::setDuration(int duration) {
    this->duration = duration;
}

void Music::setPublisher(char* publisher) {
    strcpy(this->publisher, publisher);
}

char* Music::getArtist() {
    return artist;
}

int Music::getDuration() {
    return duration;
}

char* Music::getPublisher() {
    return publisher;
}

const char* Music::getType() {
    return "Music";
}

void Music::print() {
    Media::print();
    cout << "Artist: " << artist << '\n';
    cout << "Duration: " << duration << '\n';
    cout << "Publisher: " << publisher << '\n';
}

void Music::promptInput() {
    Media::promptInput();
    cout << "Enter artist: ";
    cin.getline(artist, 100); // Make sure we don't do (cin >> artist) because it will only read the first word
    cout << "Enter duration: ";
    cin >> duration;
    cin.ignore();
    cout << "Enter publisher: ";
    cin.getline(publisher, 100); // Make sure we don't do (cin >> publisher) because it will only read the first word
}