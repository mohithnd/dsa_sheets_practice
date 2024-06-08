#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

int height_1(Node *root)
{
    if (!root)
    {
        return 0;
    }

    int left_height = height_1(root->left);
    int right_height = height_1(root->right);

    return 1 + max(left_height, right_height);
}

int diameter_1(Node *root)
{
    // TC - O(N^2)
    // SC - O(1)
    if (!root)
    {
        return 0;
    }

    int left_dia = diameter_1(root->left);
    int right_dia = diameter_1(root->right);

    int left_height = height_1(root->left);
    int right_height = height_1(root->right);

    int curr_dia = left_height + right_height;

    return max(curr_dia, max(left_dia, right_dia));
}

int height_2(Node *root, int &diameter)
{
    if (root == nullptr)
    {
        return 0;
    }

    int left_height = height_2(root->left, diameter);
    int right_height = height_2(root->right, diameter);

    diameter = max(diameter, left_height + right_height);

    return 1 + max(left_height, right_height);
}

int diameter_2(Node *root)
{
    // TC - O(N)
    // SC - O(1)
    int diameter = 0;

    height_2(root, diameter);

    return diameter;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    cout << diameter_1(root) << endl;
    cout << diameter_2(root) << endl;
    return 0;
}