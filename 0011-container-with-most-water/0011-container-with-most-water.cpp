class Solution {  
public:
    int maxArea(vector<int>& height) {
        int max_area = min(height[0], height[1])*1;
        int l = 0;
        int r = height.size() -1;
        
        while(l < r){
            int area = (r-l)*(min(height[r], height[l]));
            max_area = max(max_area, area);

            if(height[l] < height[r]){
                l++;
            }
            else{
                r--;
            }
        }

        return max_area;
    }
};