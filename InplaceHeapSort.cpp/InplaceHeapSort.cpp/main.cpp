#include <iostream>

using namespace std;

// Time complexity: O(nlogn), Space complexity: O(1)
void inplaceHeapSort(int input[], int n)
{
    
    // build a heap
    for (int i = 0; i < n; i++)
    {
        int childIndex = i;
        while(childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if(input[childIndex] < input[parentIndex])
            {
                swap(input[childIndex], input[parentIndex]);
            }
            else break;
            childIndex = parentIndex;
        }
        
    }
    
    //down-heapify
    
    int size = n;
    while (size > 1) {
        
        swap(input[0], input[size - 1]);
        size--;
        int Pindex = 0;
        int LCI = 2*Pindex + 1;
        int RCI = 2*Pindex + 2;
        int minIndex = Pindex;
        while (LCI < size)
        {
            if(input[minIndex] > input[LCI])
                minIndex = LCI;
            if(RCI < size && input[minIndex] > input[RCI])
                minIndex = RCI;
            if(minIndex == Pindex)
                break;
            swap(input[Pindex], input[minIndex]);
            Pindex = minIndex;
            LCI = 2*Pindex + 1;
            RCI = 2*Pindex + 2;
        }
    }
}


int main()
{
    int input[] = {8, 10, 2, 0, 90, 22};
    int size = sizeof(input)/ sizeof(int);
    inplaceHeapSort(input, size);
    // Sorting would be done in descending order
    for (int i = size - 1; i >= 0; i--)
    {
        cout << input[i] << " ";
    }
    cout << endl;
}
