class Solution {
private:
    bool isPalindrome(int num){
        int orig = num;
        int rev = 0;
        while(num > 0){
            int digit = num%10;
            num /= 10;
            rev = rev*10 + digit;
        }

        return orig == rev;
    }
    long long FindCost(vector<int>& nums, int Pal_median){
        long long cost = 0;
        for(int num: nums){
            cost += abs(num-Pal_median);
        }

        return cost;
    }    
public:
    long long minimumCost(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int median = nums[n/2];
        
        int inc = median, dec = median;
        while(!isPalindrome(inc)){
            inc++;
        }

        while(!isPalindrome(dec)){
            dec--;
        }

        return min(FindCost(nums, inc), FindCost(nums, dec));
    }
};