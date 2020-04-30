#include <omp.h>
#include <iostream>
#include <chrono>
#define N 10000

int main()
{
  const int n = N;
  int count = 0;
omp_set_num_threads(4);
#pragma omp parallel
{
  #pragma omp for schedule(static, 3)
  for (int i = 0; i < n; i++)
  {
#pragma omp critical
    count++;
  }
}


  std::cout << count << std::endl;
  return 0;
}
