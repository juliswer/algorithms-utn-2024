#include <iostream>
#include <string>
#include <vector>

void exerciseOne(int valueA, int valueB) {
    std::cout << "La suma es " << valueA + valueB << '\n';
    std::cout << "La resta es " << valueA - valueB << '\n';;
    std::cout << "El producto es " << valueA * valueB << '\n';;
}

void exerciseTwo(int dateParam) {
    std::string numberString = std::to_string(dateParam);
    std::string year = numberString.substr(0, 4);
    std::string month = numberString.substr(4, 2);
    std::string day = numberString.substr(6, 2);

    std::cout << "The year is: " << year << '\n';
    std::cout << "The month is: " << month << '\n';
    std::cout << "The day is: " << day << '\n';
}

void exerciseThree() {
    int sum = 0;
    for(int i = 2; i <= 10000; i++) {
        if(i % 2 == 0)
            sum += i;
    }
    // sum should be equals to 25005000
    std::cout << "Total Even Numbers " << sum;
}

void exerciseFour(int valueOne, int valueTwo, int valueThree) {
    if(valueOne == valueTwo == valueThree)
        std::cout << "Forman Triangulo";
    else
        std::cout << "No Forman Triangulo";
}

void exerciseFive(int ladoUno, int ladoDos, int ladoTres) {
    if(ladoUno == ladoDos && ladoDos == ladoTres)
        std::cout << "Equilatero";

    if(ladoUno != ladoDos && ladoUno != ladoTres && ladoDos != ladoTres)
        std::cout << "Escaleno";

    if(ladoUno == ladoDos && ladoUno != ladoTres)
        std::cout << "Isosceles";

    if(ladoUno == ladoTres && ladoUno != ladoDos)
        std::cout << "Isosceles";

    if(ladoDos == ladoTres && ladoUno != ladoDos)
        std::cout << "Isosceles";
}

void exerciseSix(unsigned int age) {
    if(age <= 12)
        std::cout << "Menor";
    if(age >= 13 && age <=18)
        std::cout << "Cadete";
    if(age > 18 && age <= 26)
        std::cout << "Juvenil";
    if(age > 26)
        std::cout << "Mayor";
}

void exerciseSeven(int timeInSeconds, int timeInMinutes = 0) {
    // x = v . t
    const int distance = 1500;

    int time = timeInSeconds;

    if(timeInMinutes > 0)
        time += timeInMinutes * 60;

    int velocity = distance / time;

    std::cout << "El corredor ha tenido una velocidad de " << velocity << " metros/segundo";
}

void exerciseEight(int (&arrayOfNumbers)[50]) {
    int sumMinusTen = 0;
    int sumHigherThanHundred = 0;
    float averageHundred = 0.00;
    std::vector<int> higherThanHundred;

    for (int i = 0; i < sizeof(arrayOfNumbers); i++) {
        if (arrayOfNumbers[i] < -10) {
            sumMinusTen += arrayOfNumbers[i];
        }
        if(arrayOfNumbers[i] > 100) {
            higherThanHundred.push_back(arrayOfNumbers[i]);
        }
    }

    for (int j = 0; j < higherThanHundred.size(); j++) {
        sumHigherThanHundred += higherThanHundred[j];
    }

    averageHundred = sumHigherThanHundred / higherThanHundred.size();
    std::cout << "La suma de los -10 es " << sumMinusTen;
    std::cout << "AVG Hundred " << averageHundred;
}

// exercise 9
enum InfringementType {
    TYPE_1 = 1,
    TYPE_2 = 2,
    TYPE_3 = 3,
    TYPE_4 = 4
};

// Determinate the letter L, M and G with their ASCII code respectively
enum GRAVITY {
    SLIGHT = 76,
    MODERATE = 77,
    SERIOUS = 71
};

struct Infringement {
    InfringementType type;
    std::string reason;
    int amount;
    GRAVITY gravity;
};

void exerciseNine() {
    int penaltyFee = 0;
    int seriousCasesCounter = 0;
    Infringement infringements[5];

    infringements[0].type = InfringementType::TYPE_4;
    infringements[0].reason = "Reason of the infringement 1";
    infringements[0].amount = 20;
    infringements[0].gravity = GRAVITY::SERIOUS;

    infringements[1].type = InfringementType::TYPE_4;
    infringements[1].reason = "Reason of the infringement 2";
    infringements[1].amount = 100;
    infringements[1].gravity = GRAVITY::SERIOUS;

    infringements[2].type = InfringementType::TYPE_3;
    infringements[2].reason = "Reason of the infringement 3";
    infringements[2].amount = 200;
    infringements[2].gravity = GRAVITY::SERIOUS;

    infringements[3].type = InfringementType::TYPE_2;
    infringements[3].reason = "Reason of the infringement 4";
    infringements[3].amount = 82;
    infringements[3].gravity = GRAVITY::MODERATE;

    infringements[4].type = InfringementType::TYPE_1;
    infringements[4].reason = "Reason of the infringement 5";
    infringements[4].amount = 15;
    infringements[4].gravity = GRAVITY::SLIGHT;


    int infringementLength = sizeof(infringements) / sizeof(infringements[0]);

    for(int i = 0; i < infringementLength; i++) {
        penaltyFee += infringements[i].amount;

        if((infringements[i].type == InfringementType::TYPE_3 || infringements[i].type == InfringementType::TYPE_4) && infringements[i].gravity == GRAVITY::SERIOUS) {

            seriousCasesCounter++;
        }

        if(seriousCasesCounter >= 3) {
            std::cout << "********* Closing Factory *********" << '\n';
        }
    }

    std::cout << "Due to your violations you will have to pay a fine of: $" << penaltyFee << std::endl;
}

// Exercise 10

struct Report {
    // < 1520
    int categoryOneCounter;
    // >= 1520 && < 2780
    int categoryTwoCounter;
    // >= 2780 && < 5999
    int categoryThreeCounter;
    // >= 5999
    int categoryFourCounter;
};

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

    std::cout << "Analysis Concluded!" << '\n';

    std::cout << std::endl;
    std::cout << "Employees earning less than $1.520: " << report.categoryOneCounter << '\n';
    std::cout << std::endl;
    std::cout << "Employees earning more than than $1.520 but less than $2.780: " << report.categoryTwoCounter << '\n';
    std::cout << std::endl;
    std::cout << "Employees earning more than $2.780 but less than $5.999: " << report.categoryThreeCounter << '\n';
    std::cout << std::endl;
    std::cout << "Employees earning more than $5.999: " << report.categoryFourCounter << '\n';

    std::cout << std::endl;
}


int main() {
    float arrOfPayments[] = {1519, 1518, 1517, 1516, 0};
    int arrOfPaymentsLength = sizeof(arrOfPayments) / sizeof(arrOfPayments[0]);

    exerciseTen(arrOfPayments, arrOfPaymentsLength);

    return 0;
}

