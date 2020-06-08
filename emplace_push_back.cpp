#include <iostream>
#include <string>
#include <vector>
#include <time.h>

class BaseClass
{
public:
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
private:
  std::string name_;
  int count_;
};

int main(int argc, char** argv)
{
  std::vector<BaseClass> vec_bc;
  std::vector<std::string> vec_s;
  vec_bc.reserve(10); // 不提前reserve会有多次拷贝操作

  std::cout << "--------------------------------emplace_back rvalue:" << std::endl;
  vec_bc.emplace_back(BaseClass("b1", 1));
  vec_bc.emplace_back("b1_1", 1);

  std::cout << "--------------------------------push_back rvalue:" << std::endl;
  vec_bc.push_back(BaseClass("b3", 1));
  // vec_bc.push_back("b4_1");// 不能通过编译

  std::cout << "--------------------------------emplace_back lvalue:" << std::endl;
  BaseClass b2("b2", 1);
  vec_bc.emplace_back(b2);
  vec_bc.emplace_back(std::move(b2));

  std::cout << "--------------------------------push_back lvalue:" << std::endl;
  BaseClass b4("b4", 1);
  vec_bc.push_back(b4);
  vec_bc.push_back(std::move(b4));

  std::cout << "--------------------------------push_back move const lvalue:" << std::endl;
  const BaseClass b5("b5", 1);
  vec_bc.push_back(b5);
  vec_bc.push_back(std::move(b5));

  vec_bc.shrink_to_fit(); // 存在移动的可能
  std::cout << "--------------------------------destruct:" << std::endl;
}