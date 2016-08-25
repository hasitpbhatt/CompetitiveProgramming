// O(n) : 40 ms

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
        ListNode *start, *end;
        ListNode *answer = NULL, *ptr;
        start = l1;
        end = l2;
        int sum = 0;
        while(start!=NULL && end!=NULL) {
            sum += start->val + end->val;
            if(answer == NULL) {
                answer = new ListNode(sum%10);
                ptr = answer;
            } else {
                ptr->next = new ListNode(sum%10);
                ptr = ptr->next;
            }
            sum /= 10;
            start = start->next;
            end = end->next;
        }
        while(start != NULL) {
            if(sum == 0) {
                ptr->next = start;
                return answer;
            }
            sum += start->val;
            if(answer == NULL) {
                answer = new ListNode(sum%10);
                ptr = answer;
            } else {
                ptr->next = new ListNode(sum%10);
                ptr = ptr->next;
            }
            sum /= 10;
            start = start->next;
        }
        while(end != NULL) {
            if(sum == 0) {
                ptr->next = end;
                return answer;
            }
            sum += end->val;
            if(answer == NULL) {
                answer = new ListNode(sum%10);
                ptr = answer;
            } else {
                ptr->next = new ListNode(sum%10);
                ptr = ptr->next;
            }
            sum /= 10;
            end = end->next;
        }
        if(sum) {
            if(answer == NULL) {
                answer = new ListNode(sum%10);
                ptr = answer;
            } else {
                ptr->next = new ListNode(sum%10);
                ptr = ptr->next;
            }
        }
        return answer;
    }
};