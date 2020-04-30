#include <iostream>
#include <functional>

std::function<void()> detect_angle_func_;

int main(int argc, char** argv)
{
  detect_angle_func_ = [&]() -> void {
    std::cout << "test" << std::endl;
  };
  detect_angle_func_();
  detect_angle_func_();
  return 0;
}