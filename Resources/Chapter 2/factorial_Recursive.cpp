#include <iostream>

int factorialRecursive(int);

int main() {

    int num;

    std::cout << "Enter a num: ";
    std::cin >> num;

    int result = factorialRecursive(num);

    std::cout << "factorial of " << num << " is " << result;

}

int factorialRecursive(int num) {

    int fact = num;

    if (num == 0) {
        return 1;
    }
    else {
        return num * factorialRecursive(num - 1);
    }

    return fact;
}