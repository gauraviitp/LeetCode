/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = nullptr;
        ListNode* resultHead = nullptr;
        int sum = 0, carry = 0, prevCarry = 0;
        while(l1 != nullptr || l2 != nullptr || prevCarry != 0){
            carry = 0;
            int l1Val = (l1 == nullptr) ? 0 : l1->val;
            int l2Val = (l2 == nullptr) ? 0 : l2->val;
            sum = l1Val + l2Val + prevCarry;
            if(sum >= 10) {
                sum = sum - 10;
                carry = 1;
            }
            if(result == nullptr){
                result = new ListNode(sum);
                resultHead = result;
            }
            else {
                result->next = new ListNode(sum);
            }
            prevCarry = carry;
            if(l1 != nullptr) {
                l1 = l1 -> next;
            }
            if(l2 != nullptr) {
                l2 = l2 -> next;
            }
            if(result != nullptr && result->next != nullptr) {
                result = result -> next;
            }
        }
        if (result == nullptr){
            result = new ListNode(0);
        }
        return resultHead;
    }
};
