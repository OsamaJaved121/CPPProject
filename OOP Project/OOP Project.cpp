#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<conio.h>

using namespace std;

class Movie
{
private:
    string name;
    int year;
    string stars;
    int totalNoOfCopies;
    int noOfCopiesRentedOut;
public:
    Movie(string nam, int yr, string str, int totalCopies, int rentedCopies ) {
        setter(nam, yr, str, totalCopies, rentedCopies);
    }
    void setter(string nam, int yr, string str, int totalCopies, int rentedCopies) {
        name = nam;
        year = yr;
        stars = str;
        totalNoOfCopies = totalCopies;
        noOfCopiesRentedOut = rentedCopies;
    }
    void setName(string n){
        name = n;
    }
    void setYear(int y) {
        year = y;
    }
    void setStarName(string strName) {
        stars = strName;
    }
    void setTotalCopies(int ttlCopies) {
        totalNoOfCopies = ttlCopies;
    }
    void setRentedCopies(int rentdCopies) {
        noOfCopiesRentedOut = rentdCopies;
    }
    
    int getYear()const {
        return year;
    }
    string getName()const {
        return name;
    }
    string getStars()const {
        return stars;
    }
    int getTotalNoOfCopies() {
        return totalNoOfCopies;
    }
    int getNoOfCopiesRentedout() {
        return noOfCopiesRentedOut;
    }
    void rentMovies(int temp) {
        if (temp+noOfCopiesRentedOut>totalNoOfCopies) {
            cout << "\nOperantion invalid" << endl;
        }
        else {
            noOfCopiesRentedOut += temp;
        }
    }
    void display() {
        cout << "\n\nName: " << getName() << endl;
        cout << "\nYear: " << getYear() << endl;
        cout << "\nStars: " << getStars() << endl;
        cout << "\nTotal copies available: " << getTotalNoOfCopies() << endl;
        cout << "\nCopies rented out: " << getNoOfCopiesRentedout() << endl;
    }
};

void menu() {
    vector <Movie> movies;
    Movie rec1("Alien", 1979, "Yaphet-Kotto, Sigourney Weaver", 2, 1);
    Movie rec2("Repo-man", 2020, "Harry-Dean-Stanton", 4, 2);
    Movie rec3("Midnight-run", 2011, "Yaphet-Kotto", 1, 1);
    movies.push_back(rec1);
    movies.push_back(rec2);
    movies.push_back(rec3);
    bool escape = true;
    int choice;
    do {
        system("cls");
        cout << "\n\n1. Search for a movie" << endl;
        cout << "\n2. Add a new movie record" << endl;
        cout << "\n3. Delete a movie record" << endl;
        cout << "\n4. Edit existing movie record" << endl;
        cout << "\n5. Change availability status" << endl;
        cout << "\n6. Check availability" << endl;
        cout << "\n7. Exit" << endl;
        cout << "\n";
        cin >> choice;
        switch (choice) {
        case 1: {
            system("cls");
            cout << "\nEnter the criteria by which you want to search the movie: " << endl;
            cout << "1. Name\n"
                << "2. Year\n"
                << "3. Star\n";
            int selection;
            cout << "\n";
            cin >> selection;
            cin.ignore();
            switch (selection) {
            case 1: {
                system("cls");
                string name;
                bool found = false;
                cout << "Enter the name or a part of the name of the movie that you want to find" << endl;
                getline(cin, name);
                for (int i = 0; i < movies.size(); i++) {
                    if (movies[i].getName().find(name, 0) != -1) {
                        cout << "\nRecord found\n" << endl;
                        movies[i].display();
                        cout << "\nPress any key to continue." << endl;
                        char temp;
                        cin >> temp;
                        cin.ignore();
                        found = true;
                    }
                }if (found == false) {
                    cout << "\n\nRecord not found" << endl;
                    cout << "\nPress any key to continue." << endl;
                    char temp;
                    cin >> temp;
                    cin.ignore();
                }break;
            }
            case 2: {
                system("cls");
                int yr; bool flag = false;
                cout << "\nEnter the year by which you want to search:\n" << endl;
                cin >> yr;
                cin.ignore();
                for (int i = 0; i < movies.size(); i++) {
                    if (movies[i].getYear() == yr) {
                        cout << "\n\nRecord found" << endl;
                        movies[i].display();
                        cout << "\nPress any key to continue." << endl;
                        char temp;
                        cin >> temp;
                        cin.ignore();
                        flag = true;
                    }
                }if (flag == false) {
                    cout << "\nRecord not found\n" << endl;
                    cout << "\nPress any key to continue." << endl;
                    char temp;
                    cin >> temp;
                    cin.ignore();
                }break;
            }
            case 3: {
                system("cls");
                string star;
                bool found = false;
                cout << "\n\nEnter the name of the movie star that you want to find" << endl;
                getline(cin, star);
                for (int i = 0; i < movies.size(); i++) {
                    if (movies[i].getStars().find(star, 0) != -1) {
                        cout << "\nRecord found" << endl;
                        movies[i].display();
                        cout << "\nPress any key to continue." << endl;
                        char temp;
                        cin >> temp;
                        cin.ignore();
                        found = true;
                    }
                }if (found == false) {
                    cout << "\nRecord not found" << endl;
                    cout << "\nPress any key to continue." << endl;
                    char temp;
                    cin >> temp;
                    cin.ignore();
                }break;
            } default: {
                cout << "\nInvalid entry. Please try again." << endl;
                break;
            }
            }

                  break;
            }
        case 2: {
            system("cls");
            int totalCopies, rented, yr;
            string nam, str;
            cout << "Enter the name of the movie:" << endl;
            cin.ignore();
            getline(cin, nam);
            cout << "Enter the release year of the movie:" << endl;
            cin >> yr;
            cout << "Enter star names (separated by comas if more than one): " << endl;
            cin.ignore();
            getline(cin, str);
            cout << "Enter the number of available copies" << endl;
            cin >> totalCopies;
            cout << "Enter the number of rented copies" << endl;
            cin >> rented;
            cin.ignore();
            Movie temp(nam, yr, str, totalCopies, rented);
            movies.push_back(temp);
            cout << "\nRecord added successfully\n" << endl;
            cout << "\nPress any key to continue." << endl;
            char temp1;
            cin >> temp1;
            cin.ignore();
            break;
        }case 3: {
            system("cls");
            cout << "\n\nEnter the name of the movie that you want to delete:" << endl;
            string tempName;
            bool chk = false;
            cout << "\n";
            cin.ignore();
            getline(cin, tempName);
            for (int i = 0; i < movies.size(); i++) {
                if (movies[i].getName().find(tempName, 0) != -1) {
                    cout << "\n\nRecord found" << endl;
                    movies.erase(movies.begin() + (i));
                    cout << "\nRecord erased successfully" << endl;
                    cout << "\nPress any key to continue." << endl;
                    char temp;
                    cin >> temp;
                    cin.ignore();
                    chk = true;
                }
            }if (chk == false) {
                cout << "\nRecord not found" << endl;
                cout << "\nPress any key to continue." << endl;
                char temp;
                cin >> temp;
                cin.ignore();
            }
            break;
        }
        case 4: {
            system("cls");
            string temp, starName, movieName;
            int year, availableCopies, rentedCopies;
            cout << "\n\nEnter the name of the movie that you want to edit:" << endl;
            cin >> temp;
            cin.ignore();
            bool found = false;
            for (int i = 0; i < movies.size(); i++) {
                if (movies[i].getName().find(temp, 0) != -1) {
                    cout << "\nRecord found" << endl;
                    movies[i].display();
                    cout << "\n" << endl;
                    int option;
                    cout << "Choose the attributes that you want to change:" << endl;
                    cout << "1. Change name\n"
                        << "2. Change Year\n"
                        << "3. Change Stars\n"
                        << "4. Change Available Copies\n"
                        << "5. Change rented copies\n"
                        << "6. Change all\n";
                    cin >> option;
                    cin.ignore();
                    switch (option) {
                    case 1: {
                        system("cls");
                        cout << "Enter new name" << endl;
                        getline(cin, movieName);
                        movies[i].setName(movieName);
                        cout << "\n\nHere are new records:\n" << endl;
                        movies[i].display();
                        cout << "\nPress any key to continue." << endl;
                        char temp;
                        cin >> temp;
                        cin.ignore();
                        break;
                    } case 2: {
                        system("cls");
                        cout << "Enter new year" << endl;
                        cin >> year;
                        cin.ignore();
                        movies[i].setYear(year);
                        cout << "\n\nHere are new records:\n" << endl;
                        movies[i].display();
                        cout << "\nPress any key to continue." << endl;
                        char temp;
                        cin >> temp;
                        cin.ignore();
                        break;
                    }case 3: {
                        system("cls");
                        cout << "Enter new star name (separated by commas if more than one)" << endl;
                        getline(cin, starName);
                        movies[i].setStarName(starName);
                        cout << "\n\nHere are new records:\n" << endl;
                        movies[i].display();
                        cout << "\nPress any key to continue." << endl;
                        char temp;
                        cin >> temp;
                        cin.ignore();
                        break;
                    } case 4: {
                        system("cls");
                        cout << "Enter new number of total copies" << endl;
                        cin >> availableCopies;
                        cin.ignore();
                        movies[i].setTotalCopies(availableCopies);
                        cout << "\n\nHere are new records:\n" << endl;
                        movies[i].display();
                        cout << "\nPress any key to continue." << endl;
                        char temp;
                        cin >> temp;
                        cin.ignore();
                        break;
                    }case 5: {
                        system("cls");
                        cout << "Enter new Rented number of copies" << endl;
                        cin >> rentedCopies;
                        cin.ignore();
                        movies[i].setRentedCopies(rentedCopies);
                        cout << "\n\nHere are new records:\n" << endl;
                        movies[i].display();
                        cout << "\nPress any key to continue." << endl;
                        char temp;
                        cin >> temp;
                        cin.ignore();
                        break;
                    }case 6: {
                        system("cls");
                        cout << "Enter new name" << endl;
                        getline(cin, movieName);
                        cout << "Enter new year" << endl;
                        cin >> year;
                        cin.ignore();
                        cout << "Enter new star name (separated by commas if more than one)" << endl;
                        getline(cin, starName);
                        cout << "Enter new number of total copies" << endl;
                        cin >> availableCopies;
                        cin.ignore();
                        cout << "Enter new Rented number of copies" << endl;
                        cin >> rentedCopies;
                        cin.ignore();
                        movies[i].setter(movieName, year, starName, availableCopies, rentedCopies);
                        cout << "\n\nHere are new records:\n" << endl;
                        movies[i].display();
                        cout << "\nPress any key to continue." << endl;
                        char temp;
                        cin >> temp;
                        cin.ignore();
                        break;
                    }default: {
                        cout << "\nInvalid entry, please try again." << endl;
                        break;
                    }
                    }
                    found = true;
                }
            }if (found == false) {
                cout << "\nRecord not found" << endl;
                cout << "\nPress any key to continue." << endl;
                char temp;
                cin >> temp;
                cin.ignore();
            }break;
        }case 5: {
            system("cls");
            string name;
            bool found = false;
            cout << "Enter the name or a part of the name of the movie that you want to rent" << endl;
            cin.ignore();
            getline(cin, name);
            for (int i = 0; i < movies.size(); i++) {
                if (movies[i].getName().find(name, 0) != -1) {
                    cout << "\nRecord found\n" << endl;
                    movies[i].display();
                    cout << "\nHow many copies would you like to rent?" << endl;
                    int rent;
                    cin >> rent;
                    cin.ignore();
                    movies[i].rentMovies(rent);
                    cout << "\nHere are new records:\n" << endl;
                    movies[i].display();
                    cout << "\nPress any key to continue." << endl;
                    char temp;
                    cin >> temp;
                    cin.ignore();
                    found = true;
                }
            }if (found == false) {
                cout << "\n\nRecord not found" << endl;
                cout << "\nPress any key to continue." << endl;
                char temp;
                cin >> temp;
                cin.ignore();
            }break;
        } case 6: {
            system("cls");
            string chkName; bool flag=true;
            cout << "\n\nPlease enter the movie name to check its availability status" << endl;
            cin.ignore();
            getline(cin, chkName);
            for (int i = 0; i < movies.size(); i++) {
                if (movies[i].getName().find(chkName, 0) != -1) {
                    if (movies[i].getTotalNoOfCopies() == movies[i].getNoOfCopiesRentedout()) {
                        cout << "\n\nAll the copies of the movie that you are trying to" <<
                            " check have been rented out";
                        cout << "\nPress any key to continue." << endl;
                        char temp;
                        cin >> temp;
                        cin.ignore();
                        flag = false;
                        break;
                        
                    }
                    else {
                        movies[i].display();
                        cout << "\nPress any key to continue." << endl;
                        char temp;
                        cin >> temp;
                        cin.ignore();
                        flag = true;
                        break;
                    }
                }if (flag == false) {
                    cout << "\nNo record found" << endl;
                    cout << "\nPress any key to continue." << endl;
                    char temp;
                    cin >> temp;
                    cin.ignore();
                    break;
                }
            }break;
        } case 7: {
            ofstream saveData("movie.txt");
            for (int i = 0; i < movies.size(); i++) {
                saveData << "Name: " << movies[i].getName() << endl;
                saveData << "Year: " << movies[i].getYear() << endl;
                saveData << "Star names: " << movies[i].getStars() << endl;
                saveData << "Total number of Copies: " << movies[i].getTotalNoOfCopies() << endl;
                saveData << "Number of Copies Rented Out: " << movies[i].getName() << "\n" << endl;
            }
            saveData.close();
            escape = false;
            break;
        } default: {
            cout << "\nInvalid entry, please try again." << endl;
            break;
        }
        }
        } while (escape);
    }

int main() {
    menu();
    return 0;
}