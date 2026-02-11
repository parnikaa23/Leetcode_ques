1class Solution {
2public:
3    ListNode* swapPairs(ListNode* head) {
4        ListNode dummy(0);
5        dummy.next = head;
6        
7        ListNode* prev = &dummy;
8        
9        while (prev->next && prev->next->next) {
10            ListNode* first = prev->next;
11            ListNode* second = first->next;
12            
13            // Swapping
14            first->next = second->next;
15            second->next = first;
16            prev->next = second;
17            
18            // Move prev forward
19            prev = first;
20        }
21        
22        return dummy.next;
23    }
24};
25