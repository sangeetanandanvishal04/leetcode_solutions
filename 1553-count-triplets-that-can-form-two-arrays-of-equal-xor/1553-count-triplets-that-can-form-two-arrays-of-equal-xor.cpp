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
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefixXOR(n);
        build(arr, n, prefixXOR);

        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int k=i+1; k<n; k++){
                int totalXor = (i == 0 ? prefixXOR[k] : prefixXOR[k] ^ prefixXOR[i-1]);
                
                if(totalXor == 0){
                    cnt += (k - i);
                }
            }
        }    

        return cnt;
    }
};