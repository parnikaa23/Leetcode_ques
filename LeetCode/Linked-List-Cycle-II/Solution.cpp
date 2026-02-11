1class Solution {
2public:
3    typedef ListNode* ln;
4
5    ListNode *detectCycle(ListNode *head) {
6        if (!head || !head->next) {
7            return NULL;
8        }
9
10        ln s = head;
11        ln f = head;
12
13        while (f && f->next) {
14            s = s->next;
15            f = f->next->next;
16
17            if (s == f) {
18                s = head;          // reset slow
19                while (s != f) {
20                    s = s->next;
21                    f = f->next;
22                }
23                return s;          // start of cycle
24            }
25        }
26
27        return NULL;
28    }
29};
30