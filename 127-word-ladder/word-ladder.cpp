class Solution {
public:
    bool differByOne(string s1,string s2){
        if(s1.length()!=s2.length())return false;
        int cnt=0;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i])++cnt;
            if(cnt>1)return false;
        }
        return true;
    }
    unordered_map<string,vector<string>> graphCreation(vector<string>& wordList,string beginWord){
        unordered_map<string,vector<string>> graph;
        vector<string> words=wordList;
        words.push_back(beginWord);
        int n=words.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(differByOne(words[i],words[j])){
                    graph[words[i]].push_back(words[j]);
                    graph[words[j]].push_back(words[i]);
                }
            }
        }
        return graph;
    }

    int bfsShortestPath(unordered_map<string, vector<string>> &graph, string beginWord, string endWord) {
        queue<pair<string, int>> q;
        unordered_set<string> visited;

        q.push({beginWord, 1});
        visited.insert(beginWord);

        while (!q.empty()) {
            auto [word, depth] = q.front();
            q.pop();

            if (word == endWord) return depth;

            for (auto &neighbor : graph[word]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push({neighbor, depth + 1});
                }
            }
        }
        return 0;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,vector<string>> graph=graphCreation(wordList,beginWord);
        // auto graph = graphCreation(beginWord, wordList);
        if (graph.find(endWord) == graph.end()) {
            return 0;
        }
        return bfsShortestPath(graph,beginWord,endWord);
    }
};