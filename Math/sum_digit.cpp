#include <iostream>
using namespace std;

static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();

int addDigits3(int num) {
    int sum_of_digits;
    while (num >= 10) {
        sum_of_digits = 0;
        while (num > 0) {
            sum_of_digits += num % 10;
            num /= 10;
        }
        num = sum_of_digits;
    }
    return num;
}

int addDigits2(int num) {
    int sum = 0;
    while(num > 0){
        sum+=num%10;
        num/=10;
        if(num == 0 && sum > 9) {
            num = sum;
            sum = 0;
        }
    }
    return sum;
}
int addDigits(int num) {
    int sum = 0;
    while (num || sum >= 10) {
        sum += num % 10;
        num /= 10;
        if (num == 0 && sum >= 10) {
            num = sum;
            sum = 0;
        }
    }
    return sum;
}

int main()
{

    cout << addDigits(31) << endl;
}