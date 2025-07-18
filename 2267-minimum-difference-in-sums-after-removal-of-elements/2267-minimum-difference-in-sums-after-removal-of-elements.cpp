class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n3 = nums.size();
        int n = n3/3;

        vector<long long> leftMin(n3, 0);
        priority_queue<int> maxHeap;
        
        long long curSum = 0;
        for(int i=0; i<n3; i++){
            curSum += nums[i];
            maxHeap.push(nums[i]);

            if(maxHeap.size() > n){
                curSum -= maxHeap.top();
                maxHeap.pop();
            }
            if(maxHeap.size() == n){
                leftMin[i] = curSum;
            }
        }


        priority_queue<int, vector<int>, greater<int>> minHeap;
        vector<long long> rightMin(n3, 0);
        curSum = 0;

        for(int i=n3-1; i>=0; i--){
            curSum += nums[i];
            minHeap.push(nums[i]);

            if(minHeap.size() > n){
                curSum -= minHeap.top();
                minHeap.pop();
            }
            if(minHeap.size() == n){
                rightMin[i] = curSum;
            }
        }

        long long ans = LLONG_MAX;
        for(int i=n-1; i<=2*n-1; i++){
            ans = min(ans, leftMin[i] - rightMin[i+1]);
        }

        return ans;
    }
};