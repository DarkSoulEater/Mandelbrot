#include "util/time.hpp"

namespace Time {
    static std::chrono::high_resolution_clock::time_point now_time_ = std::chrono::high_resolution_clock::now();
    static double delta_time_ = 0;
    static int64_t FPS_ = 0;

    void UpdateTime_() {
        std::chrono::high_resolution_clock::time_point time = std::chrono::high_resolution_clock::now();
        delta_time_ = std::chrono::duration<double>(time - now_time_).count();
        now_time_ = time;

        if (delta_time_ > 0.00000001) {
            FPS_ = 1.0 / delta_time_;
        }
    }

    //int64_t GetTime() {
        //return now_time_;
        //return std::chrono::duration_cast<std::chrono::nanoseconds>(now_time_ - now_time_).count();
    //}

    double GetDeltaTime() {
        return delta_time_;
    }

    int64_t GetFPS() {
        return FPS_;
    }
} // namespace time