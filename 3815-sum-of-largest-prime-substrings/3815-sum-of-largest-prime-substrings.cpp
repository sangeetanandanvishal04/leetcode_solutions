class Solution {
private:
    bool isPrime(long long n){
        if(n < 2){
            return false;
        }    
        if(n == 2 || n == 3){
            return true;
        }    
        if(n%2 == 0 || n%3 == 0){
            return false;
        }    
        for(long long i = 5; i*i <= n; i += 6){
            if(n%i == 0 || n%(i+2) == 0){
                return false;
            }    
        }
        
        return true;
    }
public:
    long long sumOfLargestPrimes(string s) {
        unordered_set<long long> primes;

        int n = s.length();
        for(int i=0; i<n; i++){
            string temp = "";
            for(int j=i; j<n && j-i < 10; j++){  
                temp += s[j];
                
                if(temp[0] == '0'){
                    continue;  
                }  
                
                long long val = stoll(temp);
                if(isPrime(val)){
                    primes.insert(val);
                }
            }
        }

        priority_queue<long long> pq(primes.begin(), primes.end());

        long long sum = 0;
        for(int i=0; i<3 && !pq.empty(); i++){
            sum += pq.top();
            pq.pop();
        }

        return sum;
    }
};