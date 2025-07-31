class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        vector<int> nums;
        bool flag = 0;
        for(int num: arr){
            if(num == 0){
                if(!flag){
                    nums.push_back(num);
                    flag = 1;
                }
            }
            else{
                nums.push_back(num);
            }
        }

        int n = nums.size();
        vector<int> vec;

        for(int i=0; i<n; i++){
            if(i == 0 || nums[i] != nums[i-1]){
                vec.push_back(nums[i]);
            }
        }
        
        int maxOR = 0;
        for(int val: vec){
            maxOR |= val;
        }

        if(maxOR == 0){
            return 1;
        }

        unordered_set<int> st;
        n = vec.size();

        for(int i=0; i<n; i++){
            int curOR = 0;
            for(int j=i; j<n; j++){
                curOR |= vec[j];
                st.insert(curOR);

                if(curOR == maxOR){
                    break;
                } 
            }
        }

        return st.size();
    }
};