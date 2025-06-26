class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        
        if(s[n-1] != '0'){
            return false;
        }    

        vector<bool> vis(n, false);
        queue<int> q;
        q.push(0);
        vis[0] = true;

        int lastCheck = 0; //This track the last idx we check currently.

        while(!q.empty()){
            int idx = q.front();
            q.pop();

            int start = max(idx+minJump, lastCheck);
            int end = min(idx+maxJump, n-1);

            for(int i=start; i<=end; i++){
                if(s[i] == '0' && !vis[i]){
                    if(i == n-1){
                        return true;
                    }

                    q.push(i);
                    vis[i] = true;
                }
            }

            lastCheck = end;
        }

        return false;
    }
};