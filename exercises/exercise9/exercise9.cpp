#include <iostream>
using namespace std;

// Determinate the letter L, M and G with their ASCII code respectively
// @ref: https://www.ascii-code.com/ 
enum GRAVITY {
    SLIGHT = 76,
    MODERATE = 77,
    SERIOUS = 71
};

enum InfringementType {
    TYPE_1 = 1,
    TYPE_2 = 2,
    TYPE_3 = 3,
    TYPE_4 = 4
};

struct Infringement {
    InfringementType type;
    string reason;
    int amount;
    GRAVITY gravity;
};

void exerciseNine();

int main() {
    exerciseNine();

    return 0;
}

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
            cout << "********* Closing Factory ********* \n";
        }
    }

    cout << "Due to your violations you will have to pay a fine of: $" << penaltyFee << endl;
}