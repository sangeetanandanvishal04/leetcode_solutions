class Solution {
private:
    static bool comp(vector<int>& a, vector<int>& b){
        return a[1] > b[1];
    }    
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        sort(boxTypes.begin(), boxTypes.end(), comp);
        
        int ans = 0;
        for(int i=0; i<n; i++){
            int box = boxTypes[i][0];
            int units = boxTypes[i][1];

            if(box <= truckSize){
                truckSize -= box;
                ans += (box*units);
            }
            else{
                ans += truckSize*units;
                break;
            }
        }

        return ans;
    }
};