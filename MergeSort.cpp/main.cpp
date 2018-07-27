#include <iostream>
using namespace std;

// Time complexity: O(nlogn), Space complexity: O(n)

// This function will merge two sorted arrays
void mergeArrays(int arr[], int start, int end)
{
    int size = end - start + 1;
    int middle = (start + end)/2;
    int * output = new int[size];
    int i = start; // counter 1
    int j = middle + 1; // counter 2
    int k = 0; // counter for the output array
    while (i <= middle && j <= end)
    {
        if (arr[i] < arr[j])
        {
            output[k] = arr[i];
            i++; // move on to the next element of the first half
        }
        else
        {
            output[k] = arr[j]; // move on to the next element of the second half
            j++;
        }
        k++; // increase the counter of the output array
    }
    
    // Copy the elements if there are some present in the first half
    while (i <= middle)
    {
        output[k] = arr[i];
        i++;
        k++;
    }
    
    // Copy the rest of the elements from the second half if they are present
    while (j <= end)
    {
        output[k] = arr[j];
        j++;
        k++;
    }
    
    // Copy the output array into the input array
    int m = 0;
    for (int i = start; i <= end; i++) {
        arr[i] = output[m];
        m++;
    }
    
    delete []output; // delete the output array
}


void mergeSort(int input[], int start, int end)
{
    if(start >= end)
    {
        return;
    }
    int middle = (end + start)/2;
    mergeSort(input, start, middle); // first half
    mergeSort(input, middle + 1, end); // second half
    mergeArrays(input, start, end); // now we will merge these above half sorted arrays into one
}

int main()
{
    int input[] = {8, 10, 2, 0, 90, 22};
    int size = sizeof(input)/ sizeof(int);
    mergeSort(input, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;
}
