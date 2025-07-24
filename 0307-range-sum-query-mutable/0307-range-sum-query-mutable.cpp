class NumArray {
public:
    vector<int> prefix, arr;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        arr = nums;
        prefix.resize(n, 0);
        prefix[0] = nums[0];

        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
    }

    void update(int index, int val) {
        int delta = val-arr[index];
        arr[index] = val;

        for(int i=index; i<n; i++){
            prefix[i] += delta;
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0){
            return prefix[right];
        }
        else{
            return prefix[right] - prefix[left-1];
        }    
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */