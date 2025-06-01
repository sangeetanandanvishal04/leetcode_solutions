class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();

        int black = 0;
        int l=0, r=0;

        while(r<k){
            if(blocks[r] == 'B'){
                black++;
            }
            r++;
        }

        int mini = k-black;

        while(r<n){
            if(blocks[r] == 'B'){
                black++;
            }
            if(blocks[l] == 'B'){
                black--;
            }

            mini = min(mini, k-black);
            l++;
            r++;
        }

        return mini;
    }
};