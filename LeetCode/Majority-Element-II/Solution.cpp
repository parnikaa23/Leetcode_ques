1class Solution {
2public:
3    vector<int> majorityElement(vector<int>& nums) {
4        int count1=0,count2=0;
5        int candidate1=0,candidate2=0;
6        
7        for(int num:nums){
8            if(num==candidate1) count1++;
9            else if(num==candidate2) count2++;
10            else if(count1==0){
11                candidate1=num;
12                count1=1;
13            }
14            else if(count2==0){
15                candidate2=num;
16                count2=1;
17            }
18            else{
19                count1--;
20                count2--;
21            }
22        }
23        
24        count1=0,count2=0;
25        
26        for(int num:nums){
27            if(num==candidate1) count1++;
28            else if(num==candidate2) count2++;
29        }
30        
31        vector<int> ans;
32        
33        if(count1>nums.size()/3) ans.push_back(candidate1);
34        if(count2>nums.size()/3) ans.push_back(candidate2);
35        
36        return ans;
37    }
38};