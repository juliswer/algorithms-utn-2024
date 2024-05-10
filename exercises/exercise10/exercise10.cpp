#include <iostream>
using namespace std;

struct Report {
    // category for: < 1520
    int categoryOneCounter;
    // category for: >= 1520 && < 2780
    int categoryTwoCounter;
    // category for: >= 2780 && < 5999
    int categoryThreeCounter;
    // category for: >= 5999
    int categoryFourCounter;
};

void exerciseTen(const float* arrOfPayments, int arrLength);

int main() { 
    
    return 0;
}

void exerciseTen(const float* arrOfPayments, int arrLength) {
    Report report = {};
    report.categoryOneCounter = 0;
    report.categoryTwoCounter = 0;
    report.categoryThreeCounter = 0;
    report.categoryFourCounter = 0;

    // arrLength - 1 to prevent handling the zero.
    for (int i = 0; i < arrLength - 1; ++i) {
        if(arrOfPayments[i] < 1520)
            report.categoryOneCounter++;

        if(arrOfPayments[i] >= 1520 && arrOfPayments[i] < 2780)
            report.categoryTwoCounter++;

        if(arrOfPayments[i] >= 2780 && arrOfPayments[i] < 5999)
            report.categoryThreeCounter++;

        if(arrOfPayments[i] >= 5999)
            report.categoryFourCounter++;
    }

    cout << "Analysis Concluded!" << '\n';

    cout << endl;
    cout << "Employees earning less than $1.520: " << report.categoryOneCounter << '\n';
    cout << endl;
    cout << "Employees earning more than than $1.520 but less than $2.780: " << report.categoryTwoCounter << '\n';
    cout << endl;
    cout << "Employees earning more than $2.780 but less than $5.999: " << report.categoryThreeCounter << '\n';
    cout << endl;
    cout << "Employees earning more than $5.999: " << report.categoryFourCounter << '\n';

    cout << endl;
}