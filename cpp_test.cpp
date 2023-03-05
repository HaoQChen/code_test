#include <math.h>
#include <time.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

// #include <Eigen/Dense>
// #define EIGEN_USE_MKL_ALL
// #define EIGEN_VECTORIZE_SSE4_2

using std::cout;
using std::endl;
// using namespace Eigen;

class BaseClass {
 public:
  BaseClass(const std::string name, int count) : name_(name), count_(count) {
    std::cout << name_ << " constructor called" << std::endl;
  }
  BaseClass(const BaseClass& b) {
    this->name_ = b.name_;
    std::cout << name_ << " copy constructor called" << std::endl;
  }
  BaseClass(BaseClass&& b) {
    this->name_ = b.name_;
    std::cout << name_ << " move constructor called" << std::endl;
  }
  virtual ~BaseClass() {
    std::cout << name_ << " destructor called" << std::endl;
  }

 public:
  virtual void showMsg() { std::cout << " showMsg" << std::endl; }
  virtual void Init() { showMsg(); }

 private:
  std::string name_;
  int count_;
};

// class DerivedClass : public BaseClass
// {
// public:
//   DerivedClass() : int_data_(0)
//   {
//     std::cout << "DerivedClass constructor called" << std::endl;
//   }
//   virtual ~DerivedClass()
//   {
//     std::cout << "DerivedClass destructor" << std::endl;
//   }
// protected:
//   void showMsg()
//   {
//     std::cout << "DerivedClass showMsg" << std::endl;
//   }
// private:
//   int int_data_;
// };

auto time2String = [](struct timespec t_start,
                      struct timespec t_end) -> const std::string {
  std::string result;
  std::stringstream ss;
  long double temp = 0.0;
  temp += (t_end.tv_sec - t_start.tv_sec);
  temp += static_cast<long double>((t_end.tv_nsec - t_start.tv_nsec) / 1000u) /
          static_cast<long double>(1000000.0);
  ss.precision(6);
  ss.setf(std::ios::fixed);
  ss << temp;
  ss >> result;
  return result;
};

// int main(int argc, char** argv) {
//   // float a = 10.0f;
//   // float b = 11.0f;
//   // float c = 12.0f;
//   // std::stringstream ss;
//   // ss << "0x" << std::uppercase << std::hex << static_cast<unsigned int>(a)
//   //    << "0x" << static_cast<unsigned int>(b) << "0x"
//   //    << static_cast<unsigned int>(c);
//   // std::cout << ss.str() <<  std::endl;
//   // std::fstream file;
//   // file.open("/home/hqchen/Desktop/test.txt", std::ios::out |
//   // std::ios::trunc); unsigned char utf8BOM[] = {0xEF, 0xBB, 0xBF};
//   // file.write((char*)utf8BOM, sizeof(utf8BOM));
//   // file << "test" << '/r' << '/n';
//   // file << "test1" << std::endl;
//   int n = 20;
//   for (int i = 0; i < n; i--) {
//     printf("+");
//   }
// }

#include <iostream>
#include <string>

int main(void)
{
  int test = 0xFFFFFFFF;
  std::cout << "test: " << test << std::endl;
  test = static_cast<int>(std::stol("0xFFFFFFFF", nullptr, 16));
  std::cout << "test: " << test << std::endl;
  for (int i = 0; i < 32; ++i)
  {
    if ((test & (0x00000001 << i)) == 0)
    {
      std::cout << "error-----------" << std::endl;
    }
  }
  return 0;
}

// void func(std::vector<int>& vec)
// {
//   for(int i=0; i<5; i++)
//   {
//     int b;
//     std::cout << "new b: " << std::dec << b
//               << " @ " << std::hex << &b << std::endl;

//     b+=10;
//     int a = i;
//     std::cout << "b+11 : "<< std::dec << b << std::endl;
//     std::cout << "a: " << a << std::endl;
//     std::cout << "----" << std::endl;
//   }
// }

// int main (int argc, char** argv)
// {
//   std::vector<int> temp_vec;
//   func(temp_vec);
//   return 0;
// }

// int main(int argc, char **argv)
// {
//     if (argc != 2){
//         std::cerr << "Please run as: cpp_test 1000" << std::endl \
//                   << "with 1000 means loop count" << std::endl;
//         return -1;
//     }

//     std::size_t loop_count = stoul(std::string(argv[1]));
//     volatile std::size_t i = 0; //
//     要求编译器每次都直接读取原始内存地址，防止编译器对循环做优化

//     std::vector<float> vfloat(loop_count, 0.0f);
//     std::vector<double> vdouble(loop_count, 0.0);

//     for (i = 0; i < loop_count; ++i){
//         vfloat[i] = 0.1234567f / 0.24654f;
//         vdouble[i] = 0.1234567 / 0.24654;
//     }

//     struct timespec time_1;
//     struct timespec time_2;

//     struct timespec time_start;
//     clock_gettime(CLOCK_THREAD_CPUTIME_ID, &time_start);

// // float 循环做cos
//     i = 0;
//     for (; i < loop_count; ++i){
//         vfloat[i] = logf(vfloat[i]);
//         // vfloat[i] = sinf(vfloat[i]);
//     }

//     clock_gettime(CLOCK_THREAD_CPUTIME_ID, &time_1);
// // double 循环做cos
//     i = 0;
//     for (; i < loop_count; ++i){
//         vdouble[i] = log(vdouble[i]);
//         // vdouble[i] = sin(vdouble[i]);
//     }

//     clock_gettime(CLOCK_THREAD_CPUTIME_ID, &time_2);

//     std::cout << "float  cos and sin time: " << time2String(time_start,
//     time_1) << "s" << std::endl; std::cout << "double cos and sin time: " <<
//     time2String(time_1, time_2) << "s" << std::endl;
// }

// int main(int argc, char **argv)
// {
//     if (argc != 2){
//         std::cerr << "Please run as: cpp_test 1000" << std::endl \
//                   << "with 1000 means loop count" << std::endl;
//         return -1;
//     }

//     std::size_t loop_count = stoul(std::string(argv[1]));
//     volatile std::size_t i = 0; //
//     要求编译器每次都直接读取原始内存地址，防止编译器对循环做优化

//     float data_float = 0.1018f;
//     double data_double = 0.1018;

//     struct timespec time_1;
//     struct timespec time_2;
//     struct timespec time_3;
//     struct timespec time_4;

//     struct timespec time_start;
//     clock_gettime(CLOCK_THREAD_CPUTIME_ID, &time_start);

// // float 循环写入硬盘
//     i = 0;
//     std::ofstream float_out;
//     float_out.open("./float_out.txt", std::ios::out | std::ios::trunc); //
//     如果存在则先删除 float_out.setf(std::ios::fixed); float_out.precision(7);
//     for (; i < loop_count; ++i){
//         float_out << data_float;
//     }
//     float_out.close();
//     clock_gettime(CLOCK_THREAD_CPUTIME_ID, &time_1);

// // float 循环读取硬盘
//     i = 0;
//     std::ifstream float_in;
//     float_in.open("./float_out.txt", std::ios::in);
//     float_in.setf(std::ios::fixed);
//     float_in.precision(7);
//     for (; i < loop_count; ++i){
//         float_in >> data_float;
//         // std::cout << data_float << ",";
//     }
//     // std::cout << std::endl;
//     float_in.close();
//     clock_gettime(CLOCK_THREAD_CPUTIME_ID, &time_2);

// // double 循环写入硬盘
//     i = 0;
//     std::ofstream double_out;
//     double_out.open("./double_out.txt", std::ios::out | std::ios::trunc); //
//     如果存在则先删除 double_out.setf(std::ios::fixed);
//     double_out.precision(14);
//     for (; i < loop_count; ++i){
//         double_out << data_double;
//     }
//     double_out.close();
//     clock_gettime(CLOCK_THREAD_CPUTIME_ID, &time_3);

// // double 循环读取硬盘
//     i = 0;
//     std::ifstream double_in;
//     double_in.open("./double_out.txt", std::ios::in);
//     double_in.setf(std::ios::fixed);
//     double_in.precision(14);
//     for (; i < loop_count; ++i){
//         double_in >> data_double;
//         // std::cout << data_double << ",";
//     }
//     // std::cout << std::endl;
//     double_in.close();
//     clock_gettime(CLOCK_THREAD_CPUTIME_ID, &time_4);

//     std::cout << "float  write time: " << time2String(time_start, time_1) <<
//     "s" << std::endl; std::cout << "double write time: " <<
//     time2String(time_2, time_3) << "s" << std::endl; std::cout << "float read
//     time: " << time2String(time_1, time_2) << "s" << std::endl; std::cout <<
//     "double read  time: " << time2String(time_3, time_4) << "s" << std::endl;
// }

// int main(int argc, char **argv)
// {
//     if (argc != 2){
//         std::cerr << "Please run as: cpp_test 1000" << std::endl \
//                   << "with 1000 means loop count" << std::endl;
//         return -1;
//     }

//     std::size_t loop_count = stoul(std::string(argv[1]));
//     volatile std::size_t i = 0; //
//     要求编译器每次都直接读取原始内存地址，防止编译器对循环做优化

//     std::vector<float> vfloat(loop_count, 0.0f);
//     std::vector<double> vdouble(loop_count, 0.0);

//     std::vector<float> vfloat1(loop_count, 0.0f);
//     std::vector<double> vdouble1(loop_count, 0.0);

//     std::vector<float> vfloat2(loop_count, 0.0f);
//     std::vector<double> vdouble2(loop_count, 0.0);

//     std::vector<float> vfloat3(loop_count, 0.0f);
//     std::vector<double> vdouble3(loop_count, 0.0);
//     for (; i < loop_count; ++i){
//         vfloat[i] = (float)i;
//         vdouble[i] = (double)i;

//         vfloat1[i] = (float)i;
//         vdouble1[i] = (double)i;

//         vfloat2[i] = (float)i;
//         vdouble2[i] = (double)i;

//         vfloat3[i] = (float)i;
//         vdouble3[i] = (double)i;
//     }
//     struct timespec time_1;
//     struct timespec time_2;

//     struct timespec time_start;
//     clock_gettime(CLOCK_THREAD_CPUTIME_ID, &time_start);

// // float 循环做加减乘除
//     i = 0;
//     for (; i < loop_count; ++i){
//         vfloat[i] += 2.3f;
//         vfloat1[i] += 2.3f;
//         vfloat2[i] += 2.3f;
//         // vfloat3[i] += 2.3f;

//         vfloat[i] -= 3.4f;
//         vfloat1[i] -= 3.4f;
//         vfloat2[i] -= 3.4f;
//         // vfloat3[i] -= 3.4f;

//         vfloat[i] *= 4.5f;
//         vfloat1[i] *= 4.5f;
//         vfloat2[i] *= 4.5f;
//         // vfloat3[i] *= 4.5f;

//         vfloat[i] /= 5.6f;
//         vfloat1[i] /= 5.6f;
//         vfloat2[i] /= 5.6f;
//         // vfloat3[i] /= 5.6f;
//     }
//     clock_gettime(CLOCK_THREAD_CPUTIME_ID, &time_1);
// // double 循环做加减乘除
//     i = 0;
//     for (; i < loop_count; ++i){
//         vdouble[i] += 2.3;
//         vdouble1[i] += 2.3;
//         vdouble2[i] += 2.3;
//         // vdouble3[i] += 2.3;

//         vdouble[i] -= 3.4;
//         vdouble1[i] -= 3.4;
//         vdouble2[i] -= 3.4;
//         // vdouble3[i] -= 3.4;

//         vdouble[i] *= 4.5;
//         vdouble1[i] *= 4.5;
//         vdouble2[i] *= 4.5;
//         // vdouble3[i] *= 4.5;

//         vdouble[i] /= 5.6;
//         vdouble1[i] /= 5.6;
//         vdouble2[i] /= 5.6;
//         // vdouble3[i] /= 5.6;
//     }
//     clock_gettime(CLOCK_THREAD_CPUTIME_ID, &time_2);

//     std::cout << "float  +-*/+-*/ O3 time: " << time2String(time_start,
//     time_1) << "s" << std::endl; std::cout << "double +-*/+-*/ O3 time: " <<
//     time2String(time_1, time_2) << "s" << std::endl;
// }

// int main(int argc, char **argv)
// {
//     if (argc != 2){
//         std::cerr << "Please run as: cpp_test 1000" << std::endl \
//                   << "with 1000 means loop count" << std::endl;
//         return -1;
//     }

//     std::size_t loop_count = stoul(std::string(argv[1]));
//     volatile std::size_t i = 0; //
//     要求编译器每次都直接读取原始内存地址，防止编译器对循环做优化

//     MatrixXf float_m1 = MatrixXf::Random(loop_count, loop_count);
//     MatrixXf float_m2 = MatrixXf::Random(loop_count, loop_count);
//     MatrixXd double_m1 = MatrixXd::Random(loop_count, loop_count);
//     MatrixXd double_m2 = MatrixXd::Random(loop_count, loop_count);

//     struct timespec time_1;
//     struct timespec time_2;

//     struct timespec time_start;
//     clock_gettime(CLOCK_THREAD_CPUTIME_ID, &time_start);

// // float 循环做加减乘除
//     MatrixXf float_p = float_m1 + float_m2;
//     clock_gettime(CLOCK_THREAD_CPUTIME_ID, &time_1);
// // double eigen矩阵相乘
//     MatrixXd double_p = double_m1 + double_m2;
//     clock_gettime(CLOCK_THREAD_CPUTIME_ID, &time_2);

//     std::cout << "float  Eigen + time O0: " << time2String(time_start,
//     time_1) << "s" << std::endl; std::cout << "double Eigen + time O0: " <<
//     time2String(time_1, time_2) << "s" << std::endl;
// }
