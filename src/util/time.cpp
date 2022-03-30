#include "util/time.hpp"
#include "ctime"

namespace Time {
    static double now_time_ = 0;
    static double delta_time_ = 0;

    void UpdateTime_() {
        double time_ = clock();
        delta_time_ = time_ - now_time_;
        now_time_ = time_;
    }

    double GetTime() {
        return now_time_;
    }

    double GetDeltaTime() {
        return delta_time_;
    }
} // namespace time