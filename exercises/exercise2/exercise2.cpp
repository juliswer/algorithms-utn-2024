#include <iostream>
using namespace std;

void exerciseTwo(int dateParam);

int main() {
    exerciseTwo(20040404);

    return 0;
}

void exerciseTwo(int dateParam) {
    string numberString = to_string(dateParam);
    string year = numberString.substr(0, 4);
    string month = numberString.substr(4, 2);
    string day = numberString.substr(6, 2);

    cout << "The year is: " << year << '\n';
    cout << "The month is: " << month << '\n';
    cout << "The day is: " << day << '\n';
}