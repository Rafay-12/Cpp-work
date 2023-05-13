#include <iostream>
using namespace std;

// Template function to increment a variable by 1
template<typename T>
T increment(T variable) {
    return variable + 1;
}

// Template specialization for char* variables (uppercase conversion)
template<>
char* increment<char*>(char* variable) {
    char* ptr = variable;
    while (*ptr != '\0') {
        if (*ptr >= 'a' && *ptr <= 'z') {
            *ptr = *ptr - 32;
        }
        ptr++;
    }
    return variable;
}

int main() {
    int num = 5;
    double dbl = 3.14;
    float flt = 2.5f;
    char str[] = "Hello World";

    num = increment(num);
    dbl = increment(dbl);
    flt = increment(flt);
    increment(str);

    cout << "num: " << num << endl;
    cout << "dbl: " << dbl << endl;
    cout << "flt: " << flt << endl;
    cout << "str: " << str << endl;

    return 0;
}
