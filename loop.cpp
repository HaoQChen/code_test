#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <time.h>


using std::cout;
using std::endl;


class BaseClass
{
public:
    BaseClass()
    {
        std::cout << "default constructor called" << std::endl;
    }
    BaseClass(const std::string name, int count) : name_(name), count_(count)
    {
        std::cout << name_ << " constructor called" << std::endl;
    } 
    BaseClass(const BaseClass& b)
    {
        this->name_ = b.name_;
        std::cout << name_ << " copy constructor called" << std::endl;
    } 
    BaseClass(BaseClass&& b)
    {
        this->name_ = b.name_;
        std::cout << name_ << " move constructor called" << std::endl;
    } 
    virtual ~BaseClass()
    {
        std::cout << name_ << " destructor called" << std::endl;
    }
public: 
    virtual void showMsg()
    {
        std::cout << " showMsg" << std::endl;
    }
    virtual void Init()
    {
        showMsg();
    }
private:
    std::string name_;
    int count_;
};

class DerivedClass : public BaseClass
{
public:
    DerivedClass() : int_data_(0)
    {
        std::cout << "DerivedClass constructor called" << std::endl;
    }
    virtual ~DerivedClass()
    {
        std::cout << "DerivedClass destructor" << std::endl;
    }
protected:
    void showMsg()
    {
        std::cout << "DerivedClass showMsg" << std::endl;
    }
private:
    int int_data_;
};

auto time2String = [](struct timespec t_start, struct timespec t_end) -> const std::string {
    std::string result;
    std::stringstream ss;
    long double temp = 0.0;
    temp += (t_end.tv_sec - t_start.tv_sec);
    temp += static_cast<long double>((t_end.tv_nsec - t_start.tv_nsec) / 1000u) / static_cast<long double>(1000000.0);
    ss.precision(6);
    ss.setf(std::ios::fixed);
    ss << temp  ;
    ss >> result;
    return result;
};


int main(int argc, char** argv)
{
    if (argc != 2){
        std::cerr << "Please run as: cpp_test 1000" << std::endl \
                  << "with 1000 means loop count" << std::endl;
        return -1;
    }

    std::size_t loop_count = stoul(std::string(argv[1]));
    std::vector<int> data(loop_count, 0);
    for (int i = 0; i < loop_count; ++i){
        data[i] = i;
    }
    
    volatile std::size_t i = 0; // 要求编译器每次都直接读取原始内存地址，防止编译器对循环做优化
    struct timespec time_start;
    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &time_start);

    i = 0;
    for (; i < loop_count; ++i)
    {
        
    }

}