#include "timer.hpp"
#include <vector>
#include <stdlib.h>

int main(int argc, char** argv)
{
    if (argc != 3){
        std::cerr << "Please run as: cpp_test 10 1000" << std::endl \
                  << "with 1000 means total loop count" << std::endl \
                  << "10 means setp" << std::endl;
        return -1;
    }

    std::size_t loop_step = stoul(std::string(argv[1]));
    std::size_t loop_count = stoul(std::string(argv[2]));

    Timer mul =  Timer("两次除法，一次加法          ");
    Timer plus = Timer("一次除法，一次加法，三次乘法");

    for (std::size_t i = loop_step; i <= loop_count; i *= loop_step){
        std::cout << "循环次数：" << i << std::endl;
        std::vector<double> a1(i, 0.0);
        std::vector<double> a2(i, 0.0);
        std::vector<double> b1(i, 0.0);
        std::vector<double> b2(i, 0.0);
        for (int j = 0; j < i; ++j){
            a1[j] = rand();
            a2[j] = rand();
            b1[j] = rand();
            b2[j] = rand();
        }
        std::vector<double> result(i, 0.0);
        // （1）两次除法，一次加法
        mul.start();
        for (int j = 0; j < i; ++j){
            result[j] = a1[j] / b1[j] + a2[j] / b2[j];
        }
        mul.stop();
        // （2）一次除法，一次加法，三次乘法
        result.clear();
        plus.start();
        for (int j = 0; j < i; ++j){
            result[j] = (a1[j] * b2[j] + a2[j] * b1[1]) / (b1[j] *b2[j]);
        }
        plus.stop();

        mul.showCost();
        plus.showCost();
        std::cout << std::endl;
    }
}