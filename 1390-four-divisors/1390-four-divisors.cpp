class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0;

        for(int num: nums){
            int cnt = 0;
            int sum = 0;
            for(int i=1; i*i<=num; i++){
                if(num % i == 0){
                    int j = num / i;

                    sum += i;
                    cnt++;

                    if(j != i){
                        cnt++;
                        sum += j;
                    }

                    if(cnt > 4){
                        break;
                    }
                }
            }

            if(cnt == 4){
                totalSum += sum;
            }
        }

        return totalSum;
    }
};