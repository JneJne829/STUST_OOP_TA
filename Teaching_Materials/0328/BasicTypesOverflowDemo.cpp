#include <iostream>
#include <limits>

using namespace std;

int main() {
    // int溢位示例
    int max_int = numeric_limits<int>::max();
    cout << "int的最大值是: " << max_int << endl;
    max_int++;
    cout << "int最大值加1: " << max_int << endl;

    // unsigned int溢位示例
    unsigned int max_uint = numeric_limits<unsigned int>::max();
    cout << "unsigned int的最大值是: " << max_uint << endl;
    max_uint++;
    cout << "unsigned int最大值加1: " << max_uint << endl;

    // short溢位示例
    short max_short = numeric_limits<short>::max();
    cout << "short的最大值是: " << max_short << endl;
    max_short++;
    cout << "short最大值加1: " << max_short << endl;

    // long溢位示例
    long max_long = numeric_limits<long>::max();
    cout << "long的最大值是: " << max_long << endl;
    max_long++;
    cout << "long最大值加1: " << max_long << endl;

    // float溢位示例
    float max_float = numeric_limits<float>::max();
    cout << "float的最大值是: " << max_float << endl;
    max_float *= 2;
    cout << "float最大值乘以2: " << max_float << endl;

    // double溢位示例
    double max_double = numeric_limits<double>::max();
    cout << "double的最大值是: " << max_double << endl;
    max_double *= 2;
    cout << "double最大值乘以2: " << max_double << endl;

    return 0;
}