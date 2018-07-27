#include <iostream>

using namespace std;

// Return minimum index
int minIndex(int a[], int i, int j)
{
    if (i == j)
        return i;
    
    // Find minimum of remaining elements
    int k = minIndex(a, i + 1, j);
    
    // Return minimum of current and remaining.
    return (a[i] < a[k])? i : k;
}

// Recursive selection sort. n is size of a[] and index
// is index of starting element.
void recurSelectionSort(int a[], int n, int index = 0)
{
    // Return when starting and size are same
    if (index == n)
        return;
    
    // calling minimum index function for minimum index
    int k = minIndex(a, index, n-1);
    
    // Swapping when index nd minimum index are not same
    if (k != index)
        swap(a[k], a[index]);
    
    // Recursively calling selection sort function
    recurSelectionSort(a, n, index + 1);
}


int main()
{
    int input[] = {8, 10, 2, 0, 90, 22};
    int size = sizeof(input)/ sizeof(int);
    recurSelectionSort(input, size);
    
    for (int i = 0; i < size; i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;
}
