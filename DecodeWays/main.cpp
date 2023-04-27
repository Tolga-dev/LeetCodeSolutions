//https://leetcode.com/problems/decode-ways/description/
#include <iostream>
#include<iostream>
#include<vector>

int findOdd(std::vector<int> numbers, int size) {

    int counter = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (numbers[i] == numbers[j]) {
                counter++;
            }
        }
        if (counter % 2 != 0)
            return numbers[i];

    }

    return -1;
}


int main() {

    std::vector<int> arr;

    int x;
    std::cout << "enter a size of array";
    std::cin >> x;
    arr.reserve(x);
    std::cout << std::endl;

    std::cout << "enter an array";
    for (int i = 0; i < x; i++)
    {
        std::cin >> arr[i];
    }
    std::cout << std::endl;


    std::cout << findOdd(arr, x);
    return 0;
}
