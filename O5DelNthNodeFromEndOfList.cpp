#include<bits/stdc++.h>
using namespace std;

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

/*
Input: 1->2->3->4->5->NULL, n = 2
Output: 1->2->3->5->NULL
Explanation: You are given the second node with value 2, the linked list should become 1->2->3->5->NULL.
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* start=new ListNode();
        start->next=head;
        ListNode* slow=start;
        ListNode* fast=start;
        
        ListNode* temp=NULL;
        for(int i=0;i<n;i++)
            fast=fast->next;

        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
    return start->next;
    }
};