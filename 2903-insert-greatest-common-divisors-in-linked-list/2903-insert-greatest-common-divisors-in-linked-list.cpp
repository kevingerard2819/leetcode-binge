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
    ListNode* insertGreatestCommonDivisors(ListNode* head)
    {
        if(head->next==NULL)
        {
            return head;
        }
        ListNode* ans=head;
        while(head->next)
        {
            int res;
            res = GCD(head->val , head->next->val);
            ListNode* temp=new ListNode(res);
            temp->next=head->next;
            head->next=temp;
            head=temp->next;

        }
        return ans;
      

    }

    int GCD(int num1 , int num2)
    {
        while (num2 != 0) {
        int remainder = num1 % num2;
        num1 = num2;
        num2 = remainder;
    }
    return num1;
    }
    
      
    
};