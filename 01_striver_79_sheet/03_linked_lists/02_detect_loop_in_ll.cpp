#include <iostream>
#include <unordered_set>
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

string brute_force(Node *head)
{
    // TC - O(N * 2 * log(N))
    // SC - O(N)
    unordered_set<Node *> st;
    while (head)
    {
        if (st.find(head) == st.end())
        {
            st.insert(head);
            head = head->next;
        }
        else
        {
            return "Loop Present";
        }
    }
    return "No Loop";
}

string optimal_approach(Node *head)
{
    // TC - O(N)
    // SC - O(1)
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return "Loop Present";
        }
    }
    return "No Loop";
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << brute_force(head) << endl;
    cout << optimal_approach(head) << endl;

    head->next->next->next->next = head->next;
    cout << endl;

    cout << brute_force(head) << endl;
    cout << optimal_approach(head) << endl;
    return 0;
}