#include <iostream>

using namespace std;

// Time complexity: O(n^2), speed is around 2x of that of the bubble sort
void cocktailSort(int input[], int size)
{
    bool swapped = true;
    int start = 0;
    int end = size - 1;
    while (swapped)
    {
        // Just like the bubble sort we will traverse from left to right and swap the elements if the right element is greater than the left element
        for (int i = start; i < end; i++)
        {
            if (input[i] > input[i + 1])
            {
                swap(input[i], input[i + 1]);
                swapped = true;
            }
        }
        
        //Check if the array had been sorted
        if(!swapped)
            break;
        
        swapped = false; // reset the flag for the use in the next iteration
        
        end--; // We decrease the end as the element has reached the correct position
        
        // Now we traverse from right to left and we will swap the elements if the right element is greater than the left element
        for (int i = end - 1; i >= start; i--)
        {
            if (input[i] > input[i + 1])
            {
                swap(input[i], input[i + 1]);
                swapped = true;
            }
        }
    }
}
int main()
{
    int input[] = {2, 3, 4, 5, 1}; // As compared to bubble sort this would take half the number of iterations
    int size = sizeof(input)/ sizeof(int);
    cocktailSort(input, size);
    
    cout << "Sorted Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;
    
}

