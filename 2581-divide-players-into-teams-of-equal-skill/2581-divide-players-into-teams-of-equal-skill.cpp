class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        unordered_map<int, int> mp;
        int n = skill.size();
        int sum = 0;

        for(int s: skill){
            mp[s]++;
            sum += s;
        }
        
        int num_team = n / 2;
        if(sum % num_team != 0){
            return -1;
        }

        int target = sum / num_team;
        long long chemistry = 0;

        for(int num: skill){
            int partner = target-num;
            if(mp[num] == 0){
                continue;
            } 

            if(mp[partner] == 0){ 
                return -1;
            }
            
            chemistry += (long long)num*partner;
            mp[num]--;
            mp[partner]--;
        }

        return chemistry;
    }
};