/*
* Uno Pasadhika 
* Classes - assignment where we make a media list using different classes using 4 .h files and 5 .cpp files 
* 9/11/2022 
*/

#include "Media/MediaTypes/Game.h"
#include "Media/MediaTypes/Music.h"
#include "Media/MediaTypes/Movie.h"

#include <vector>

using namespace std;

int main()
{
    vector<Media*> mediaList;
    char in[100];
    cout << "Commands (case-sensitive): add, search, delete, print, quit\n";
    while (true) { // Infinitely loop until user quits
        // Prompt user for command
        cout << "Enter command: ";
        cin >> in;
        cin.ignore();
        cout << '\n';
        if (strcmp(in, "add") == 0) {
            // Prompt user for media type
            cout << "Enter type (game, movie, music): ";
            cin >> in;
            cin.ignore();
            if (strcmp(in, "game") == 0) {
                mediaList.push_back(new Game());
            }
            else if (strcmp(in, "movie") == 0) {
                mediaList.push_back(new Movie());
            }
            else if (strcmp(in, "music") == 0) {
                mediaList.push_back(new Music());
            }
            else {
                cout << "Invalid type!\n";
                continue; // Make sure we don't try to access mediaList.back() because we didn't actually add anything this time 
            }
            // Prompt user for media info 
            mediaList.back()->promptInput();
        }
        else if (strcmp(in, "search") == 0) {
            // Ask the user if they want to search by title or year
            cout << "Search by title or year? (t, y): ";
            cin >> in;
            cin.ignore();
            if (strcmp(in, "t") == 0) {
                // Ask the user for the title
                cout << "Enter title: ";
                cin.getline(in, 100); // Make sure we don't do (cin >> in) because it will only read the first word 
                // Search for the title
                bool found = false;
                for (int i = 0; i < mediaList.size(); i++) {
                    if (strcmp(mediaList[i]->getTitle(), in) == 0) { // Check if the titles are equal 
                        found = true;
                        cout << "====================\n";
                        mediaList[i]->print();
                    }
                }
                cout << "====================\n";
                if (!found) cout << "No media found with that title!\n";
            }
            else if (strcmp(in, "y") == 0) {
                // Ask the user for the year
                cout << "Enter year: ";
                int year;
                cin >> year;
                cin.ignore();
                // Search for the year
                bool found = false;
                for (int i = 0; i < mediaList.size(); i++) {
                    if (mediaList[i]->getYear() == year) {
                        found = true;
                        cout << "====================\n";
                        mediaList[i]->print();
                    }
                }
                cout << "====================\n";
                if (!found) cout << "No media found from that year!\n";
            }
            else {
                cout << "Invalid option!\n";
            }
        }
        else if (strcmp(in, "delete") == 0) {
            // Ask the user if they want to delete by title or year
            cout << "Delete by title or year? (t, y): ";
            cin >> in;
            cin.ignore();
            if (strcmp(in, "t") == 0) {
                // Ask the user for the title
                cout << "Enter title: ";
                cin.getline(in, 100); // Make sure we don't do (cin >> in) because it will only read the first word 
                // Search for the title
                bool found = false;
                for (int i = 0; i < mediaList.size(); i++) {
                    if (strcmp(mediaList[i]->getTitle(), in) == 0) { // Check if the titles are equal 
                        found = true;
                        // Prompt the user to make sure they actually want to delete this item 
                        cout << "Are you sure you want to delete \"" << mediaList[i]->getTitle() << "\" (" << mediaList[i]->getYear() << ")? (y, n): ";
                        cin >> in;
                        cin.ignore();
                        if (strcmp(in, "y") != 0) {
                            cout << "Skipping this item!\n";
                            continue; // Don't delete this item
                        }
                        delete mediaList[i]; // Delete the media
                        mediaList.erase(mediaList.begin() + i); // Remove the media from the vector
                    }
                }
                if (!found) cout << "No media found with that title!\n";
            }
            else if (strcmp(in, "y") == 0) {
                // Ask the user for the year
                cout << "Enter year: ";
                int year;
                cin >> year;
                cin.ignore();
                // Search for the year
                bool found = false;
                for (int i = 0; i < mediaList.size(); i++) {
                    if (mediaList[i]->getYear() == year) {
                        found = true;
                        // Prompt the user to make sure they actually want to delete this item 
                        cout << "Are you sure you want to delete \"" << mediaList[i]->getTitle() << "\" (" << mediaList[i]->getYear() << ")? (y, n): ";
                        cin >> in;
                        cin.ignore();
                        if (strcmp(in, "y") != 0) {
                            cout << "Skipping this item!\n";
                            continue; // Don't delete this item
                        }
                        delete mediaList[i]; // Delete the media
                        mediaList.erase(mediaList.begin() + i); // Remove the media from the vector
                    }
                }
                if (!found) cout << "No media found with that year!\n";
            }
            else {
                cout << "Invalid option!\n";
            }
        }
        else if (strcmp(in, "print") == 0) {
            // Print the number of entires and all entries 
            cout << "There are " << mediaList.size() << " entries.\n";
            for (int i = 0; i < mediaList.size(); i++) {
                cout << "====================\n";
                mediaList[i]->print();
            }
            cout << "====================\n";
        }
        else if (strcmp(in, "quit") == 0) {
            break;
        }
        else {
            cout << "Command not recognized! The commands are case-sensitive.\n";
        }
        cout << '\n';
    }
    cout << "Thanks for using this program!\n";
    return 0;
}