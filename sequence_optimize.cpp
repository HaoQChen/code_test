#include "timer.hpp"
#include <vector>
#include <stdlib.h>

bool isInBox(const std::pair<int, int>& point, std::pair<int, int> box_pose, std::pair<int, int> box_size)
{
    return ((std::abs(point.first - box_pose.first) < (box_size.first / 2)) 
         && (std::abs(point.second - box_pose.second) < (box_size.second / 2)));
}

void findPointInBox(std::vector<std::pair<int, int>>& src, 
                    std::vector<std::pair<int, int>>& dst, 
                    std::pair<int, int> box_pose, std::pair<int, int> box_size)
{
    for (auto& point : src){
        if ((std::abs(point.first - box_pose.first) < (box_size.first / 2)) 
         && (std::abs(point.second - box_pose.second) < (box_size.second / 2))) {
            dst.push_back(point);
        }
    }
}

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

    Timer mul = Timer("循环中调用函数");
    Timer plus = Timer("将函数放到循环外");

    for (std::size_t i = loop_step; i <= loop_count; i *= loop_step){
        std::cout << "循环次数：" << i << std::endl;
        std::vector<std::pair<int, int>> data(i, std::make_pair<int, int>(0, 0));
        for (auto& d : data){
            d.first = rand();
            d.second = rand();
        }
        std::vector<std::pair<int, int>> result;

        mul.start();
        for (auto& point : data){
            if (isInBox(point, std::make_pair<int, int>(500, 1000), std::make_pair<int, int>(600, 600))){
                result.push_back(point);
            }
        }
        mul.stop();

        result.clear();
        plus.start();
        findPointInBox(data, result, std::make_pair<int, int>(500, 1000), std::make_pair<int, int>(600, 600));
        plus.stop();

        mul.showCost();
        plus.showCost();
        std::cout << std::endl;
    }
}