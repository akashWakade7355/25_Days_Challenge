// Topic : Linked List

/*
Question :
Given the heads of two singly linked lists, head1 and head2,
the task is to determine whether the two linked lists are identical.
Two linked lists are considered identical if they have the same number 
of nodes and each corresponding node contains the same data in the same order. 
Return true if both lists are identical; otherwise, return false.

Examples:

Input: head1: 1->2->3->4->5->6, head2: 99->59->42->20
Output: false
Explanation:

As shown in figure the two lists are not identical.
Input: head1: 1->2->3->4->5, head2: 1->2->3->4->5
Output: true
Explanation: 
 
As shown in figure both are identical.

Constraints:
1 ≤ length of lists ≤ 105
1 ≤ elements of lists ≤ 105
*/

// solution :

// Strucutre of a Node in linked list

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
}; 
class Solution {
  public:
    bool areIdentical(Node *head1, Node *head2) {
        // code here
        
        Node* temp1 = head1;
        Node* temp2 = head2;

        while (temp1 != nullptr && temp2 != nullptr) {

            if (temp1->data != temp2->data)
                return false;

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return temp1 == temp2;   
    }
};

// TC:0(n)

// SC:0(1)

/*
Apprach :

1. Initialize two pointers:
   - `temp1` pointing to the head of the first linked list.
   - `temp2` pointing to the head of the second linked list.

2. Traverse both linked lists simultaneously until either pointer reaches `nullptr`.
   - Compare the data stored in the current nodes.
   - If the data is different, return `false` immediately since the lists are not identical.
   - Otherwise, move both pointers to their respective next nodes.

3. After the traversal:
   - If both pointers become `nullptr` at the same time, it means both lists have the same length and all corresponding nodes matched, so return `true`.
   - If only one pointer becomes `nullptr`, the lists have different lengths, so return `false`.

### Algorithm
1. Set `temp1 = head1` and `temp2 = head2`.
2. While both `temp1` and `temp2` are not `nullptr`:
   - Compare `temp1->data` and `temp2->data`.
   - If they are different, return `false`.
   - Move both pointers to their next nodes.
3. Return `temp1 == temp2`.
   - `true` if both are `nullptr`.
   - `false` otherwise.

*/