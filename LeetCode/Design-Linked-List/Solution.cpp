1class Node{
2public:
3int val;
4    Node*prev;
5    Node*next;
6    Node(int _Val=0){
7    val=_Val;
8    prev=next=nullptr;
9}
10Node(int _Val,Node*_Pre,Node*_Nxt){
11    val=_Val;
12    prev=_Pre;
13    next=_Nxt;
14    }
15};
16
17class MyLinkedList{
18public:
19    Node*head;
20    Node*tail;
21    int size;
22    MyLinkedList(){
23    head=tail=nullptr;
24    size=0;
25}
26
27int get(int index){
28    if(index<0||index>=size)return -1;
29        Node*itr=head;
30    while(index--)itr=itr->next;
31    return itr->val;
32}
33
34    void addAtHead(int val){
35    Node*nd=new Node(val);
36    if(size==0)head=tail=nd;
37    else{
38        nd->next=head;
39    head->prev=nd;
40    head=nd;
41}
42++size;
43}
44
45void addAtTail(int val){
46    Node*nd=new Node(val);
47    if(size==0)head=tail=nd;
48    else{
49        tail->next=nd;
50        nd->prev=tail;
51        tail=nd;
52    }
53    ++size;
54}
55
56void addAtIndex(int ind,int val){
57    if(ind<0||ind>size)return;
58        if(ind==0){
59        addAtHead(val);
60        return;
61    }
62    if(ind==size){
63    addAtTail(val);
64    return;
65    }
66Node*itr=head;
67    while(ind--)itr=itr->next;
68    Node*pre=itr->prev;
69    Node*newNode=new Node(val,pre,itr);
70    pre->next=newNode;
71       itr->prev=newNode;
72    ++size;
73}
74
75void deleteAtIndex(int index){
76    if(index<0||index>=size)return;
77    Node*nd=head;
78    while(index--)nd=nd->next;
79    if(nd->prev)nd->prev->next=nd->next;
80    else head=nd->next;
81    if(nd->next)nd->next->prev=nd->prev;
82    else tail=nd->prev;
83    delete nd;
84    --size;
85}
86};
87