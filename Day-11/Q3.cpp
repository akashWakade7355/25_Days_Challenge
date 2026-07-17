// Topic : Linked List

/*
Question :

Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:

Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000

*/

// solution :


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

    if(head == nullptr)
        return nullptr;     
   ListNode* rhead = nullptr;

      while(head != nullptr){
        ListNode* temp = head;
        head = head->next;
        temp->next=nullptr;
        temp->next=rhead;
        rhead = temp;
      }
     
     return rhead;
    }
};

//TC:0(n)

// SC:0(1)

/*
Apprach :

Step 1:
Check if the linked list is empty (`head == nullptr`). If it is, return `nullptr`.

Step 2:
Create a pointer `rhead` and initialize it to `nullptr`. This pointer will store the head of the reversed linked list.

Step 3:
Traverse the original linked list until `head` becomes `nullptr`.

Step 4:
Store the current node in a temporary pointer `temp`.

Step 5:
Move `head` to the next node using `head = head->next`.

Step 6:
Detach the current node from the original list by setting `temp->next = nullptr`.

Step 7:
Insert the current node at the beginning of the reversed list by setting `temp->next = rhead`.

Step 8:
Update `rhead` to point to the current node (`rhead = temp`).

Step 9:
Repeat Steps 4 to 8 until all nodes have been processed.

Step 10:
Return `rhead`, which is the head of the reversed linked list.

*/