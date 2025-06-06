class Solution {
public:
    int distMoney(int money, int children) {
        if(money < children){
            return -1;
        }    
        money -= children;

        int ans = 0;
        while(money >= 7 && children > 0){
            money -= 7;
            ans++;
            children--;
        }

        if(ans){
            if(children == 0 && money > 0){
                ans--;
            }    
            if(children == 1 && money == 3){
                ans--;
            }    
        }
         
        return ans;
    }
};