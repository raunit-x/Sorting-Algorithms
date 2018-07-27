#include <iostream>
#include <queue>

using namespace std;


// Time complexity: O(nlogn), Space Complexity: O(n)
void heapSort(int input[], int size)
{
    // min heap
    priority_queue<int, vector<int>, greater<>> heap;
    // build the heap
    for (int i = 0; i < size; i++)
    {
        heap.push(input[i]);
    }
    for(int i = 0; i < size; i++)
    {
        input[i] = heap.top();
        heap.pop();
    }
}

int main()
{
    int input[] = {8, 10, 2, 0, 90, 22};
    int size = sizeof(input)/ sizeof(int);
    heapSort(input, size);
    for (int i = 0; i < size; i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;
}
