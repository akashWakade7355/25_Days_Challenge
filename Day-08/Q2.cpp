// Topic : Linked List

/*
Question :
Given a linked list sorted in ascending order and an integer called key,
insert data in the linked list such that the list remains sorted.

Examples:

Input: LinkedList: 25->36->47->58->69->80, key: 19
Output: 19->25->36->47->58->69->80

Explanation: After inserting 19 the sorted linked list will look like the one in the output.
Input: LinkedList: 50->100, key: 75
Output: 50->75->100

Explanation: After inserting 75 the sorted linked list will look like the one in the output.

Constraints:
1 <= size of linked list <= 106
1 <= data of nodes <= 106
*/

// solution :

// structure of the node of the list is as
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    // Should return head of the modified linked list
    Node *sortedInsert(Node *head, int key)
    {
        // Code here
        Node *newNode = new Node(key);

        if (head == nullptr || key <= head->data)
        {
            newNode->next = head;
            return newNode;
        }

        Node *prev = nullptr;
        Node *curr = head;

        while (curr != nullptr && curr->data < key)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = newNode;
        newNode->next = curr;

        return head;
    }
};

// TC:0(n)

// SC:0(1)

/*
Apprach :

1. Create a new node with the given `key`.

2. Handle the special case where:
   - The linked list is empty, or
   - The `key` is smaller than or equal to the data of the head node.
   
   In this case, insert the new node at the beginning of the list and return it as the new head.

3. Otherwise, traverse the linked list using two pointers:
   - `prev` to keep track of the previous node.
   - `curr` to keep track of the current node.

4. Move both pointers forward until:
   - `curr` becomes `nullptr`, or
   - `curr->data` is greater than or equal to the `key`.

5. Insert the new node between `prev` and `curr`:
   - Set `prev->next` to the new node.
   - Set `newNode->next` to `curr`.

6. Return the original `head` of the linked list.

---

### Algorithm

1. Create a new node with value `key`.
2. If `head == nullptr` or `key <= head->data`:
   - Point `newNode->next` to `head`.
   - Return `newNode`.
3. Initialize:
   - `prev = nullptr`
   - `curr = head`
4. Traverse the list while:
   - `curr != nullptr` and `curr->data < key`
   - Update `prev = curr`
   - Update `curr = curr->next`
5. Insert the new node:
   - `prev->next = newNode`
   - `newNode->next = curr`
6. Return `head`.

*/