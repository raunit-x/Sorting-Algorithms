#include <iostream>

using namespace std;

int partition(int input[], int start, int end)
{
    int count = 0;
    int pivot = input[start];
    for (int i = start + 1; i <= end; i++ )
    {
        if (input[i] <= pivot)
        {
            count++;
        }
    }
    
    int pivotIndex = start + count;
    input[start] = input[pivotIndex];
    input[pivotIndex] = pivot;
    
    int i = start;
    int j = end;
    while (i <= pivotIndex && j >= pivotIndex)
    {
        if(input[i] <= pivot)
            i++;
        else if(input[j] > pivot)
            j--;
        else
        {
            swap(input[i], input[j]);
            i++;
            j--;
        }
    }
    
    return pivotIndex;
}

void quickSort(int input[], int start, int end)
{
    if(start >= end)
        return;
    int p = partition(input, start, end);
    quickSort(input, start, p - 1);
    quickSort(input, p + 1, end);
}

int main()
{
    int input[] = {6, 4, 3, 3, 2, 1};
    int size = sizeof(input)/ sizeof(int);
    quickSort(input, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;
}
