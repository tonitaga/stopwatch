# StopWatch 
---
---
# Basic idea:

1) The s21::StopWatch class is just a wrapper over std::chrono

2) In my opinion it is not always a comfortable way to write:
```c++
    auto begin = std::chrono::steady_clock::now();
    auto end = std::chrono::steady_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
```
--- 
---
# How to use the class?
1) You can create an instance of the s21::StopWatch class and use the start() stop() methods
```c++
    s21::StopWatch<s21::steady_clock> stopwatch;
    stopwatch.start();
    stopwatch.stop();
    auto time = stopwatch.milliseconds();
```

2) The class is template with template parameter bool:
```c++
    template <bool IsSteadyClock>
    class StopWatch {

    };
    /*
    IsSteadyClock = true the main clock will be steady_clock from std::chrono
    IsSteadyClock = false the main clock will be system_clock from std::chrono
    */

   const bool steady_clock = true;
   const bool system_clock = false;
```
3) The class is not disposable, you can call start() stop() many times in turn and the stopwatch will restart
```c++
    s21::StopWatch<s21::steady_clock> stopwatch;
    stopwatch.start();
    stopwatch.stop();  
    {
        auto time = stopwatch.milliseconds();
    }
    stopwatch.start();
    stopwatch.stop();  
    {
        auto time = stopwatch.milliseconds();
    }
```
4) There are different kinds of time functions: nanoseconds() microseconds() milliseconds() seconds()
```c++
    long long nano = stopwatch.nanoseconds();
    double micro = stopwatch.microseconds();
    double milli = stopwatch.milliseconds();
    double sec = stopwatch.seconds();
```
---
---
**© tonitaga 2023** 