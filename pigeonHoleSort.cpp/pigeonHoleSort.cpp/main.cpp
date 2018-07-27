#include <iostream>
#include <limits.h>
using namespace std;



// Time complexity: O(n + range), Space complexity: O(range).
// Range: max - min + 1
void pigeonHoleSort(int input[], int n)
{
    int largest = INT_MIN;
    int smallest = INT_MAX;
    // A for loop to find the largest and the smallest elements of the array
    for (int i = 0; i < n; i++)
    {
        if (input[i] > largest)
        {
            largest = input[i];
        }
        if (input[i] < smallest)
        {
            smallest = input[i];
        }
    }
    // The number of holes to be made
    int numHoles = largest - smallest + 1;
    int * holes = new int[largest - smallest + 1];
    for (int i = 0; i < numHoles; i++)
    {
        holes[i] = 0;
    }
    // At the index 'input[i] - smallest', we insert the count of that element input[i]
    for (int i = 0; i < n; i++)
    {
        holes[input[i] - smallest]++;
    }
    
    int k = 0;
    for (int i = 0; i < numHoles; i++)
    {
        while (holes[i] > 0)
        {
            holes[i]--;
            input[k] = i + smallest;
            k++;
        }
    }
}


int main()
{
    int input[] = {8, 10, 2, 0, 90, 22};
    int size = sizeof(input)/ sizeof(int);
    pigeonHoleSort(input, size);
    for (int i = 0; i < size; i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;
}
