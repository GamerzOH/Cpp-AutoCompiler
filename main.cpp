#include <iostream>

using namespace std;

int retSum(int a, int b, int& carry) {
    int sum = a+b+carry;
    cout<<sum<<endl;

    carry = 12;
    return sum;
}

int main() {
    int carry=2;
    retSum(12, 15, carry);
    int res = retSum(0, 0, carry);

    return 0;
}
