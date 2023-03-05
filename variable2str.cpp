#include <iostream>
#include <string>

#define RSFSC_VARIABLE_TO_STR(_variable)                                                             \
  [&]() -> std::string {                                                                             \
    static_assert(!std::is_same<void, decltype(_variable)>::value, "only support variable");         \
    std::string org_str = std::string(#_variable);                                                   \
    auto last_dot_iter  = org_str.find_last_of('.');                                                 \
    if (std::string::npos != last_dot_iter)                                                          \
    {                                                                                                \
      org_str = org_str.substr(last_dot_iter + 1, org_str.size() - last_dot_iter);                   \
    }                                                                                                \
    auto last_greater_than_iter = org_str.find_last_of('>');                                         \
    if (std::string::npos != last_greater_than_iter)                                                 \
    {                                                                                                \
      org_str = org_str.substr(last_greater_than_iter + 1, org_str.size() - last_greater_than_iter); \
    }                                                                                                \
    return org_str;                                                                                  \
  }()

int main(int argc, char** argv)
{
  const int config_name = 0;
  struct ConfigName
  {
    int test1;
    const int test2 = 1;
    std::string test3_;
  } config_struct;
  struct Struct2
  {
    ConfigName config_name_;
    enum MyEnum
    {
      ENUM_1,
      ENUM_2
    } enum_data;
  } struct2;
  std::cout << RSFSC_VARIABLE_TO_STR(123) << std::endl;
  std::cout << RSFSC_VARIABLE_TO_STR("123") << std::endl;
  std::cout << RSFSC_VARIABLE_TO_STR(config_name) << std::endl;
  // std::cout << RSFSC_VARIABLE_TO_STR(config_nema) << std::endl; // compile fail， config_nema was not declared
  std::cout << RSFSC_VARIABLE_TO_STR(config_struct.test1) << std::endl;
  std::cout << RSFSC_VARIABLE_TO_STR((&config_struct)->test2) << std::endl;
  std::cout << RSFSC_VARIABLE_TO_STR(config_struct.test3_) << std::endl;

  std::cout << RSFSC_VARIABLE_TO_STR(struct2.ENUM_1) << std::endl;
  std::cout << RSFSC_VARIABLE_TO_STR(struct2.enum_data) << std::endl;
  std::cout << RSFSC_VARIABLE_TO_STR(struct2.config_name_.test1) << std::endl;
  std::cout << RSFSC_VARIABLE_TO_STR((&struct2.config_name_)->test1) << std::endl;
  return 0;
}