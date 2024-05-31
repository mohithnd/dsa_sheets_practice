#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

int brute_force(Node *head)
{
    // TC - O(N)
    // SC - O(1)
    if (head == nullptr)
    {
        return -1;
    }
    if (head->next == nullptr)
    {
        return head->data;
    }
    int len = 0;
    Node *temp = head;
    while (temp)
    {
        temp = temp->next;
        len++;
    }
    int i = 0;
    while (i < (len / 2))
    {
        i++;
        head = head->next;
    }
    return head->data;
}

int optimal_approach(Node *head)
{
    // TC - O(N/2)
    // SC - O(1)
    if (head == nullptr)
    {
        return -1;
    }
    if (head->next == nullptr)
    {
        return head->data;
    }

    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << brute_force(head) << endl;
    cout << optimal_approach(head) << endl;

    head->next->next->next->next->next = new Node(6);
    cout << endl;

    cout << brute_force(head) << endl;
    cout << optimal_approach(head) << endl;
    return 0;
}