1class Solution {
2public:
3    int majorityElement(vector<int>& nums) {
4        int count = 0, candi = 0;
5        for(int num : nums){
6            if(count == 0){
7                candi = num;
8            }
9            if(num == candi){
10                count ++;
11            }
12            else{
13                count--;
14            }
15        }
16        return candi;
17    }
18};