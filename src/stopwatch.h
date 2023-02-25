#pragma once

#include <chrono>
#include <type_traits>

namespace s21 {
    const bool steady_clock = true;
    const bool system_clock = false;

    template <bool IsSteadyClock>
    class StopWatch {
    public:
        using time_point = std::conditional_t<IsSteadyClock, std::chrono::steady_clock::time_point, std::chrono::system_clock::time_point>;
        using clock = std::conditional_t<IsSteadyClock, std::chrono::steady_clock, std::chrono::system_clock>;

    private:
        time_point _begin;
        time_point _end;

        struct CurrentTime {
            long long nanoseconds = 0;
            double microseconds = 0;
            double milliseconds = 0;
            double seconds = 0.0;
        };

        CurrentTime _time;

    public:
        StopWatch() = default;

        void start() {
            reset();
            _begin = clock::now();
        }

        void stop() {
            _end = clock::now();
            countcurrenttime();
        }

        long long nanoseconds() { return _time.nanoseconds; }
        double microseconds() { return _time.microseconds; }
        double milliseconds() { return _time.milliseconds; }
        double seconds() { return _time.seconds; }

    private:
        void reset() {
            _time.nanoseconds = 0;
            _time.microseconds = 0.0;
            _time.milliseconds = 0.0;
            _time.seconds = 0.0;
        }
        void countcurrenttime() {
            _time.nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(_end - _begin).count();
            _time.microseconds = _time.nanoseconds / 1000.0;
            _time.milliseconds = _time.nanoseconds / 1000000.0;
            _time.seconds = _time.nanoseconds / 1000000000.0;
        }
    };
}
