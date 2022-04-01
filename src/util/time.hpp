#ifndef TAURMAZE__TIME_H_
#define TAURMAZE__TIME_H_

#include <chrono>

namespace Time {
    //int64_t GetTime();
    double GetDeltaTime();
    int64_t GetFPS();
} // namespace time

#endif // TAURMAZE__TIME_H_