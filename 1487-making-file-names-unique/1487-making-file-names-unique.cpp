class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> mpp;
        vector<string> ans;

        for(string name : names){
            if(mpp.find(name) == mpp.end()){
                ans.push_back(name);
                mpp[name] = 1;
            } 
            else{
                int k = mpp[name];
                string new_name;
                
                while(true){
                    new_name = name + "(" + to_string(k) + ")";
                    if(mpp.find(new_name) == mpp.end()){
                        break;
                    }
                    
                    k++;
                }
                
                ans.push_back(new_name);
                mpp[name] = k + 1;
                mpp[new_name] = 1;
            }
        }

        return ans;
    }
};