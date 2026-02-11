1class Solution {
2public:
3typedef ListNode* ln;
4
5    bool hasCycle(ListNode *head) {
6        if(!head || !head->next) return 0;
7
8        ln s = head->next;
9        ln f = head->next->next;
10
11        while(s && f && s != f){
12            s = s->next;
13            f = f->next;
14            f = f ? f->next : f;
15        }
16
17        return s == f;
18    }
19};
20