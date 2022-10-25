#include <time.h>
#include <map>
#include <iostream>

namespace pedro::studies::countClockCycles {

    class ClockCounter {
     private:
        clock_t cursor_t;
        std::map<int, clock_t> countMap;
     public:
        ClockCounter();
        ~ClockCounter();

        void reset();
        void start();
        void mark(const int& codeLocation);

        // friend of class ClockCounter so it can access the private
        // data within a ClockCounter object
        friend std::ostream& operator<<(std::ostream& os, const ClockCounter& clockCounter);
    };
}