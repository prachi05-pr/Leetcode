// class Solution {
// public:
//     int largestInteger(vector<int>& nums, int k) {
//         int n=nums.size();
//        // sort(nums.begin(),nums.end());
//         unordered_map<int,int>mp;
//         //freq arr
//         // for(int i=0;i<n;i++){
//         // mp[nums[i]]++;
//         // }
//         //     if(mp[nums[n-1]] <k)   return nums[n-1];

//         //     if(mp[nums[0]] <k)   return nums[0];
//         //   if(n==2) {
//         //     if(mp[nums[0]]==2 )   return nums[0];
//         //   }




//     //       for(int i=n-1;i>=n-k-1;i--){
//     //         mp[nums[i]]++;
//     //       }
//     //       if(mp[nums[n-1]] <2)   return nums[n-1];
//     //        for(int i=0;i<k;i++){
//     //         mp[nums[i]]++;
//     //       }
//     //       if(mp[nums[0]]<2)  return nums[0];
//     //   return -1;
//     int ans=-1;
//        if(n==k && nums[0]==nums[n-1]){
//         return max(nums[0],nums[n-1]);
//        }
//        if(n==2 && nums[0]==nums[n-1]){
//         return -1;
//        }
//        for(int i = n-k; i < n; i++) {
//             mp[nums[i]]++;
//         }


//         if(mp[nums[n-1]] == 1) {
//               ans = max(ans, nums[n-1]);
//         }
//           mp.clear();
//         for(int i = 0; i < k; i++) {
//             mp[nums[i]]++;
//         }

//         if(mp[nums[0]] == 1) {
//               ans = max(ans, nums[0]);
//         }

//        return ans;


//        // return -1;
   
//     }
// };




class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> freq;

        // Generate every subarray of size k
        for(int i = 0; i <= n - k; i++) {

            unordered_set<int> st;

            // Current subarray: [i ... i+k-1]
            for(int j = i; j < i + k; j++) {
                st.insert(nums[j]);
            }

            // Count this element once for this subarray
            for(int x : st) {
                freq[x]++;
            }
        }

        int ans = -1;

        // Find largest element present in exactly one subarray
        for(auto it : freq) {
            if(it.second == 1) {
                ans = max(ans, it.first);
            }
        }

        return ans;
    }
};