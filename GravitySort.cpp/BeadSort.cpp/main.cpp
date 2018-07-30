#include <iostream>
using namespace std;

#define BEAD(i, j) beads[i * max + j]

// function to perform the above algorithm
void gravitySort(int *a, int len)
{
    // Find the maximum element
    int max = a[0];
    for (int i = 1; i < len; i++)
        if (a[i] > max)
            max = a[i];
    
    // allocating memory
    unsigned char beads[max*len];
    memset(beads, 0, sizeof(beads));
    
    // mark the beads
    for (int i = 0; i < len; i++)
        for (int j = 0; j < a[i]; j++)
            BEAD(i, j) = 1;
    
    for (int j = 0; j < max; j++)
    {
        // count how many beads are on each post
        int sum = 0;
        for (int i=0; i < len; i++)
        {
            sum += BEAD(i, j);
            BEAD(i, j) = 0;
        }
        
        // Move beads down
        for (int i = len - sum; i < len; i++)
            BEAD(i, j) = 1;
    }
    
    // Put sorted values in array using beads
    for (int i = 0; i < len; i++)
    {
        int j;
        for (j = 0; j < max && BEAD(i, j); j++);
        
        a[i] = j;
    }
}

int main()
{
   
    int arr[] = {7, 2, 1, 4, 2};
    int size = sizeof(arr)/sizeof(int);
    gravitySort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
