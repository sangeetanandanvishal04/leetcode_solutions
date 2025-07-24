class Solution {
private:
    void build(vector<int> nums, int n, vector<int>& prefixXOR){
        prefixXOR[0] = nums[0];

        for(int i=1; i<n; i++){
            prefixXOR[i] = prefixXOR[i-1] ^ nums[i];
        }
    }

    int rangeXOR(int l, int r, vector<int>& prefixXOR){
        if(l == 0){
            return prefixXOR[r];
        }
        return prefixXOR[r] ^ prefixXOR[l-1];
    }

public:    
    vector<int> xorQueries(vector<int>& nums, vector<vector<int>>& queries){
        int n = nums.size();
        vector<int> prefixXOR(n, 0);

        build(nums, n, prefixXOR);
        
        vector<int> result;
        for(auto query: queries){
            result.push_back(rangeXOR(query[0], query[1], prefixXOR));
        }  
        
        return result;
    }
};