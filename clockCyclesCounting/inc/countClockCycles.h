#include <time.h>
#include <map>

namespace pedro::studies::countClockCycles {

    class ClockCounter
    {
    private:
        clock_t cursor_t;
        std::map<int, clock_t> countMap;
    public:
        ClockCounter();
        ~ClockCounter();

        void reset();
        void start();
        void mark(const int& codeLocation);
        void produceReport();
    };
}