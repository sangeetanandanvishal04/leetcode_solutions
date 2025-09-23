class Solution {
private:
    vector<int> split(const string& version) {
        vector<int> result;
        stringstream ss(version);
        string item;
            
        while(getline(ss, item, '.')){
            result.push_back(stoi(item)); 
        }
        
        return result;
    }    
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1 = split(version1);
        vector<int> v2 = split(version2);
        
        int len = max(v1.size(), v2.size());
        
        for(int i=0; i<len; i++){
            int num1 = (i < v1.size()) ? v1[i] : 0;
            int num2 = (i < v2.size()) ? v2[i] : 0;
            
            if(num1 < num2){
                return -1;
            }    
            if(num1 > num2){
                return 1;
            }    
        }

        return 0;
    }
};