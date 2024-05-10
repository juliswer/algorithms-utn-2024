#include <iostream>
using namespace std;

struct BirthDate {
    int day;
    int month;
    int year;
};

struct Person {
    string name;
    BirthDate dateOfBirth;
};

BirthDate formatBirthDate(int dateOfBirth);

bool isOlderHelper(BirthDate date1, BirthDate date2);

bool isYoungerHelper(BirthDate date1, BirthDate date2);

int main() { 
    return 0;
}

BirthDate formatBirthDate(int dateOfBirth) {
    BirthDate formattedBirthDate = {};

     string numberString = to_string(dateOfBirth);

    formattedBirthDate.day = stoi(numberString.substr(6, 2));
    formattedBirthDate.month = stoi(numberString.substr(4, 2));
    formattedBirthDate.year = stoi(numberString.substr(0, 4));

    return formattedBirthDate;
}

bool isOlderHelper(BirthDate date1, BirthDate date2) {
    // It's read like 'date1' is older than 'date2'
    if(date1.year < date2.year)
        return true;
    if(date1.year == date2.year && date1.month < date2.month)
        return true;
    if(date1.year == date2.year && date1.month == date2.month && date1.day < date2.day) {
        return true;
    }

    return false;
}

bool isYoungerHelper(BirthDate date1, BirthDate date2) {
    // It's read like 'date1' is younger than 'date2'
    if(date1.year > date2.year)
        return true;
    if(date1.year == date2.year && date1.month > date2.month)
        return true;
    if(date1.year == date2.year && date1.month == date2.month && date1.day > date2.day) {
        return true;
    }

    return false;
}