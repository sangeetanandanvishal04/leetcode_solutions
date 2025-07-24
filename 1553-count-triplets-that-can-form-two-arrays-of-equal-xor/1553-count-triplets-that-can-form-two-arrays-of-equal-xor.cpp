class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefixXOR(n, 0);

        prefixXOR[0] = arr[0];

        for(int i=1; i<n; i++){
            prefixXOR[i] = prefixXOR[i-1] ^ arr[i];
        }

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