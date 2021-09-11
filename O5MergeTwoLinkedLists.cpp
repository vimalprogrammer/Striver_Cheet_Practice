#include<bits/stdc++.h>
using namespace std;

/* Merge two Sorted Linked Lists
Input: L1 = [1->3->5->7] 
       L2 = [2->4->6->8]
Output: [1->2->3->4->5->6->7->8]
*/

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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* L1, ListNode* L2) {
        
        if(L1==NULL) return L2;
        if(L2==NULL) return L1;
        
        if(L1->val > L2->val)
            swap(L1,L2);
        ListNode * res=L1;
        while(L1!=NULL && L2!=NULL)
        {
            ListNode *tmp=NULL;
            while(L1!=NULL && L1->val<=L2->val)
            {
                tmp=L1;
                L1=L1->next;
            }
            tmp->next=L2;
            swap(L1,L2);
        }
        return res;
    }
};

*/