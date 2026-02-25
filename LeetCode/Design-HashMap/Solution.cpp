1class MyHashMap {
2public:
3    vector<int> mp;
4    
5    MyHashMap() {
6        mp.resize(1000001,-1);
7    }
8    
9    void put(int key, int value) {
10        mp[key]=value;
11    }
12    
13    int get(int key) {
14        return mp[key];
15    }
16    
17    void remove(int key) {
18        mp[key]=-1;
19    }
20};