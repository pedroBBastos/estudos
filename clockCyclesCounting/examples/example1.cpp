#include <countClockCycles.h>
#include <iostream>

using pedro::studies::countClockCycles::ClockCounter;

int main() {
    ClockCounter counter;
    counter.start();

    counter.mark(1);

    int k =0;
    for(int i=0; i<43; i++) {
        k++;
        for(int j=0; j<555; j++) {
            int asd=-90;
        }
        counter.mark(2);
    }

    std::cout << "---------------- Testei saida ----------------" << std::endl;

    counter.mark(3);

    std::cout << counter;
}