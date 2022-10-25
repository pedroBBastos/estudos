#include <countClockCycles.h>

namespace pedro::studies::countClockCycles {

    ClockCounter::ClockCounter() {
        this->reset();
    };

    ClockCounter::~ClockCounter() = default;

    void ClockCounter::reset() {
        this->countMap.clear();
        this->cursor_t = 0;
    }

    void ClockCounter::start() {
        this->cursor_t = clock();
    }

    void ClockCounter::mark(const int& codeLocation) {
        clock_t markedTime = clock();
        clock_t absoluteTime = markedTime - this->cursor_t;
        this->cursor_t = markedTime;

        if (countMap.find(codeLocation) == countMap.end()) {
            countMap.insert(std::make_pair(codeLocation, absoluteTime));
        } else {
            countMap[codeLocation] += absoluteTime;
        }
    }

    std::ostream& operator<<(std::ostream& os, const ClockCounter& clockCounter) {
        for(auto iterator = clockCounter.countMap.begin(); 
            iterator != clockCounter.countMap.end(); ++iterator) {
            os << iterator->first << " -> " << iterator->second << "\n";
        }
        return os;
    }
}