class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for(int num: nums){
            if(set.find(num) != set.end()){
                return num;
            }

            set.insert(num);
        }
        
        return 0;
    }
};