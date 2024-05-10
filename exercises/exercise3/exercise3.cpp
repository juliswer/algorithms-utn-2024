#include <iostream>
using namespace std;

void exerciseThree();

int main() {
    exerciseThree();
    
    return 0;
}

void exerciseThree() {
    int sum = 0;
    
    for(int i = 2; i <= 10000; i++) {
        if(i % 2 == 0)
            sum += i;
    }
    
    // sum should be equals to 25005000
    cout << "Total Even Numbers " << sum;
}