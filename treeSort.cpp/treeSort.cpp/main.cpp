#include <iostream>

using namespace std;

// Average time complexity: O(nlogn), worst = O(n^2), Space complexity: O(n)

// Binary tree node class
class BinaryTreeNode
{
public:
    
    int data;
    BinaryTreeNode * left;
    BinaryTreeNode * right;
    BinaryTreeNode(int data)
    {
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

// Insert in a BST
BinaryTreeNode * insert(BinaryTreeNode * root, int data)
{
    if(root == NULL)
    {
        BinaryTreeNode * newNode = new BinaryTreeNode(data); //  create a new root
        root = newNode;
        return root;
    }
    if (root -> data > data)
    {
        root -> left = insert(root -> left, data);
    }
    else
    {
        root -> right = insert(root -> right, data);
    }
    return root;
}

// This function is to store the tree in the given array
void storeTree(int arr[], BinaryTreeNode * root, int &i)
{
    if(root == NULL)
        return;
    storeTree(arr, root -> left, i);
    arr[i] = root -> data;
    i++;
    storeTree(arr, root -> right, i);
    
}

void treeSort(int arr[], int size)
{
    BinaryTreeNode * root = NULL;
    // Form a BST from the input array
    root = insert(root, arr[0]);
    for (int i = 1; i < size; i++)
    {
         insert(root, arr[i]);
    }
    // Now the BST is ready
    int i = 0; // For reference
    storeTree(arr, root, i);
    
}
int main()
{
    int input[] = {3, 4, 1, 2, 6};
    int size = sizeof(input)/ sizeof(int);
    treeSort(input, size);
    
    cout << "Sorted Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;
}
