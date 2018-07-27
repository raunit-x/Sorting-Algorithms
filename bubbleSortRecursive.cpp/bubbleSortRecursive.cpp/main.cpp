#include <iostream>

using namespace std;

// Time complexity: O(n^2), Space complexity: O(1)

void bubbleSort_Recursive(int input[], int n)
{
    if(n == 0 || n == 1)
        return;
    // After 1 iteration the largest element would be at the end of the array
    for (int i = 1; i < n; i++)
    {
        if(input[i - 1] > input[i])
        {
            swap(input[i - 1], input[i]);
        }
    }
    // We pass the array except the last element
    bubbleSort_Recursive(input, n - 1);
}

int main()
{
    int input[] = {8, 10, 2, 0, 90, 22};
    int size = sizeof(input)/ sizeof(int);
    bubbleSort_Recursive(input, size);
    for (int i = 0; i < size; i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;
}
