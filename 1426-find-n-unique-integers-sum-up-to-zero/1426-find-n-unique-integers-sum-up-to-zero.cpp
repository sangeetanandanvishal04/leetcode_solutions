class Solution {
private:
    vector<int> evenArr(int n){
        vector<int> nums(n);
        int start = -(n/2);
        for(int i=0; i<n; i++){
            nums[i] = start;
            start++;
            if(start == 0){
                start++;
            }
        }

        return nums;
    }   

    vector<int> oddArr(int n){
        vector<int> nums(n);
        int start = -(n/2);
        for(int i=0; i<n; i++){
            nums[i] = start;
            start++;
        }
        
        return nums;
    }  
public:
    vector<int> sumZero(int n) {
        if(n%2 == 0){
            return evenArr(n);
        }
        return oddArr(n);
    }
};