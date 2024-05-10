#include <iostream>
using namespace std;

void exerciseSeven(int timeInSeconds, int timeInMinutes = 0);

int main() {
    exerciseSeven(20);
    
    return 0;
}

void exerciseSeven(int timeInSeconds, int timeInMinutes) {
    // x = v . t
    const int distance = 1500;

    int time = timeInSeconds;

    if(timeInMinutes > 0)
        time += timeInMinutes * 60;

    int velocity = distance / time;

    cout << "El corredor ha tenido una velocidad de " << velocity << " metros/segundo";
}