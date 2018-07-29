// Note: This sorting algorithm works for non negative integers.
// However it can be extended to work for negative integers

#include <iostream>
#include <limits.h>
using namespace std;



// Time complexity: O(n + range), Space complexity: O(range)
void countingSort(int input[], int size)
{
    int largest = INT_MIN;
    // A for loop to find the range of the elements
    for (int i = 0; i < size; i++)
    {
        if (input[i] > largest)
        {
            largest = input[i];
        }
    }
    
    int range = largest + 1;
    
    int * count= new int[range];
    for(int i = 0; i < range; i++)
        count[i] = 0;
    // Store the count of each input element at the corresponding index
    for (int i = 0; i < size; i++)
    {
        count[input[i]]++;
    }
    // modify the count array
    for (int i = 1; i < range; i++)
    {
        count[i] += count[i - 1];
    }
    // make the output array
    int * output = new int[size];
    // fill the output array in the sorted order using the count array
    for (int i = 0; i < size; i++)
    {
        output[count[input[i]] - 1] = input[i];
        --count[input[i]];
    }
    for(int i = 0; i < size; i++)
    {
        input[i] = output[i];
    }
}

int main()
{
    int input[] = {3, 4, 1, 2, 6, 5};
    int size = sizeof(input)/ sizeof(int);
    countingSort(input, size);
    
    cout << "Sorted Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;
}
