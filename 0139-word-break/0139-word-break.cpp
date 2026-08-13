// class Solution {
// public:
//     bool isPresent(vector<string> &wordDict, string &part){
//     int n=wordDict.size();
//     for(int i=0;i<n;i++){
//         if(wordDict[i]==part){
//             return true;
//         }
//     }
//     return false;
//     }
//     bool solve( vector<string>& wordDict,string &s){
//         int n=wordDict.size();
//         if(s.empty())  return true;

//         for(int i=0;i<s.size();i++){
//             string part=s.substr(0,i+1);

//             if(isPresent(wordDict,part)){
//             string rem=s.substr(i+1);

//             if(solve(wordDict,rem)){
//                 return true;
//             }
//             }
        
//         }
//         return false;
//     }
//     bool wordBreak(string s, vector<string>& wordDict) {
//         int n=wordDict.size();
//        return  solve(wordDict,s);
        
//     }
// };




class Solution {
public:

    unordered_set<string> st;
    vector<int> dp;

    bool solve(string& s, int index) {

        if (index == s.size())
            return true;

        if (dp[index] != -1)
            return dp[index];

        string part = "";

        for (int i = index; i < s.size(); i++) {

            part += s[i];

            if (st.find(part) != st.end()) {

                if (solve(s, i + 1))
                    return dp[index] = true;
            }
        }

        return dp[index] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        for (string word : wordDict)
            st.insert(word);

        dp.resize(s.size(), -1);

        return solve(s, 0);
    }
};