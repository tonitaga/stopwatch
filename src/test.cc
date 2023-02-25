#include "stopwatch.h"

#include <iostream>

void Test() {
    double sum = 0;
    s21::StopWatch<s21::steady_clock> stopwatch;
    stopwatch.start();
    for (int i = 0; i != 1'000'000; ++i, sum += i);
    stopwatch.stop();
    std::cout << "nanoseconds: " << stopwatch.nanoseconds() << std::endl;
    std::cout << "microseconds: " << stopwatch.microseconds() << std::endl;
    std::cout << "milliseconds: " << stopwatch.milliseconds() << std::endl;
    std::cout << "seconds: " << stopwatch.seconds() << std::endl;
}

int main() {
    Test();
}