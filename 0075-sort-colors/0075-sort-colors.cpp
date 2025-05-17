class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> count(3, 0);
        for(int i = 0; i < nums.size(); i++){
            count[nums[i]]++;
            nums[i] = 0;
        }

        int j = 0;
        for(int i=0; i<3; i++){
            while(count[i] > 0){
                nums[j] = i;
                count[i]--;
                j++;
            }
        }
    }
};