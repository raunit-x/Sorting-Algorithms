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
    int * frequency = new int[largest];
    // initialize the frequency array with all the frequencies as 0
    for (int i = 0; i < range; i++)
    {
        frequency[i] = 0;
    }
    
    // To store the frequency of the elements of the input array
    for (int i = 0; i < size; i++)
    {
        frequency[input[i]]++;
    }
    
    // In the original array, we replace the elements by the index in the frequency array
    int k = 0; // original array counter
    for (int i = 0; i < range; i++)
    {
        while (frequency[i] > 0) // for all non zero frequency elements we replace in the original/ input array
        {
            frequency[i]--;
            input[k] = i;
            k++;
        }
    }
}

int main()
{
    int input[] = {3, 4, 1, 2, 6};
    int size = sizeof(input)/ sizeof(int);
    countingSort(input, size);
    
    cout << "Sorted Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;
}
