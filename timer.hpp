#include <iostream>
#include <string>
#include <sstream>
#include <time.h>

class Timer
{
public:
    Timer(const std::string& _name);
    ~Timer();

    inline void start(void);
    inline void stop(void);
    inline void showCost(void);
private:
    long double temp = 0.0;
    struct timespec time_start_;
    struct timespec time_stop_;
    const std::string name_;
};

Timer::Timer(const std::string& _name) : name_(_name)
{

}

Timer::~Timer()
{
}

void Timer::start(void)
{
    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &time_start_);
}

void Timer::stop(void)
{
    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &time_stop_);
}

void Timer::showCost(void)
{
    std::string result;
    std::stringstream ss;
    long double temp = (time_stop_.tv_sec - time_start_.tv_sec);
    temp += static_cast<long double>((time_stop_.tv_nsec - time_start_.tv_nsec) / 1000u) / static_cast<long double>(1000000.0);
    ss.precision(6);
    ss.setf(std::ios::fixed);
    ss << temp  ;
    ss >> result;
    std::cout << name_ << " costs: " << result << "s" << std::endl;;
}
