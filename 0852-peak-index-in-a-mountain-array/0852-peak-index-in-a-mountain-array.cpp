class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int left = 0;
        int right = n-1;

        while(left <= right){
            int mid=left+(right-left)/2;
            
            if(mid-1 >=0 && arr[mid-1] < arr[mid] && mid+1 < n && arr[mid] > arr[mid+1]){
                return mid;
            }
            else if(arr[mid] < arr[mid+1]){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }

        return left;
    }
};