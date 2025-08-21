class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> count;
        for(string word: words){
            count[word]++;
        }
        
        auto compare = [](const pair<int, string>& a, const pair<int, string>& b){
            if(a.first == b.first){
                return a.second < b.second; 
            }
            return a.first > b.first; 
        };

        priority_queue<pair<int, string>, vector<pair<int, string>>, 
                                          decltype(compare)> pq(compare);

        for(auto entry: count){
            string word = entry.first;
            int cnt = entry.second;

            pq.push({cnt, word});
            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<string> result;
        while(!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};