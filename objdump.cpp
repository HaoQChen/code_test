#include <iostream>

// int main (int argc, char** argv)
// {
//     int i = 0;
//     const int data_size = 100;
//     int data[data_size] = {0};
//     for (; i < data_size; ++i){
//         data[i] = i;
//     }

//     i = 0;
//     while(i < data_size){
//         data[i] = i;
//         ++i;
//     }
//     return 0;
// }

const int kDataSize = 100;
int data_size = 100;

const int getSize(void)
{
    return kDataSize;
}

int main (int argc, char** argv)
{
    int data[kDataSize] = {0};
    for (int i = 0; i < getSize(); ++i){
        data[i] = i;
    }

    for (int i = 0; i < kDataSize; ++i){
        data[i] = i;
    }

    for (int i = 0; i < data_size; ++i){
        data[i] = i;
    }
    return 0;
}