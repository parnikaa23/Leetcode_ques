1class Solution {
2public:
3    ListNode* oddEvenList(ListNode* head) {
4        if (!head || !head->next)
5            return head;
6
7        ListNode* odd = head;
8        ListNode* even = head->next;
9        ListNode* evenHead = even;
10
11        while (even && even->next) {
12            odd->next = even->next;
13            odd = odd->next;
14
15            even->next = odd->next;
16            even = even->next;
17        }
18
19        odd->next = evenHead;
20
21        return head;
22    }
23};
24