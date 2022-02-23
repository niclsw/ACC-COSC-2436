#include <iostream>

int factorialIterative(int);

int main() {

    int num;

    std::cout << "Enter a num: ";
    std::cin >> num;

    std::cout << "factorial of " << num << " is " << factorialIterative(num);

}

int factorialIterative(int num) {

    int fact = num;

    while (num > 1) {
        fact *= num - 1;
        num--;
    }

    return fact;
}