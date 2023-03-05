#include <iostream>
#include <string>

class Solution {
public:
  std::string longestPalindrome(std::string _s) {
    int s_size = _s.size();
    if (s_size == 1) {
      return _s;
    }
    // if (s_size == 2){
    //     return _s[0] == _s[1] ? _s : string(_s[0]);
    // }
    int start_index = 0;
    int p_size = 1;
    for (std::size_t i = 0; i < s_size - (p_size >> 1) + 1; ++i) {
      // std::cout << "i: " << i << std::endl;
      int temp_size = 0;
      while ((i - temp_size) >= 0 && (i + temp_size + 1) < s_size &&
             _s[i - temp_size] == _s[i + temp_size + 1]) {
        ++temp_size;
        // std::cout << "1temp_size: " << temp_size << std::endl;
      }
      if ((temp_size << 1) > p_size) {
        p_size = temp_size << 1;
        start_index = i - temp_size + 1;
        // std::cout << "1p_size" << p_size << std::endl;
      }

      temp_size = 0;
      while ((i - temp_size - 1) >= 0 && (i + temp_size + 1) < s_size &&
             _s[i - temp_size - 1] == _s[i + temp_size + 1]) {
        ++temp_size;
        // std::cout << "2temp_size: " << temp_size << std::endl;
      }
      if (((temp_size << 1) + 1) > p_size) {
        p_size = (temp_size << 1) + 1;
        start_index = i - temp_size;
        // std::cout << "2p_size" << p_size << std::endl;
      }
    }
    return _s.substr(start_index, p_size);
  }
};

int main(int argc, char **argv) {
  if (argc != 2) {
    return -1;
  }
  std::string input(argv[1]);
  Solution sln;
  std::cout << input << "'s result is: " << sln.longestPalindrome(input) <<
  std::endl; return 0;
}