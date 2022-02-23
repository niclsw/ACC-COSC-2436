// Recursive Binary Search
#include <iostream>

using namespace std;

void display_array(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << array[i];
        (i == length - 1) ? cout << "." : cout << ",";
    }
}
// binary_search(array,length,search_number,lower,upper)
int binary_search(int array[], int length, int search_number, int lower, int upper)
{
    if (lower <= upper)
    {
        int center = (lower + upper) / 2;
        if (search_number == array[center])
        {
            return center;
        }
        else if (search_number < array[center])
        {
            return binary_search(array, length, search_number, lower, center - 1);
        }
        else
        {
            return binary_search(array, length, search_number, center + 1, upper);
        }
    }
    else
    {
        return -1;
    }
}
void sorting(int array[], int length)
{
    for (int i = length - 1; i >= 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            if (array[j - 1] > array[j])
            {
                // Swap
                int temp_A = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp_A;
            }
        }
    }
}
int main()
{
    int array[10] = {12, 34, 21, 39, 65, 48, 36, 11, 58, 23};
    int number, index;
    int length = 10;

    cout << "\n Recursive Binary Search";
    cout << "\n -----------------------";
    cout << "\n Un-Sorted Elements in a Array ";

    display_array(array, length);

    // Sorting
    cout << "\n\n Recursive Binary Search is Works With Sorted Array.. ";
    sorting(array, length);

    cout << "\n\n After Sorting Sorted Elements in a Array ";
    display_array(array, length);

    cout << "\n Enter Number to be Search : ";
    cin >> number;
    int lower = 0;          // Left of Array Segment
    int upper = length - 1; // Right of Array Segment

    index = binary_search(array, length, number, lower, upper);
    if (index > -1)
    {
        cout << "\n Number Found at index of " << index;
    }
    else
    {
        cout << "\n " << number << " is not Found in Array ";
    }

    return 0;
}