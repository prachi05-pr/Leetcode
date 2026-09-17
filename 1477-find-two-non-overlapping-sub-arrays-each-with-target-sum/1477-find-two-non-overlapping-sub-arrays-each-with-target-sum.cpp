class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        int sum=0;
        int minlen=INT_MAX;
        int len=0;
        int ans=INT_MAX;
        int left=0;
        vector<int>best(n+1,INT_MAX);

        for(int right=0; right<n ; right++){
            sum+=arr[right];

            while(sum>target){
                sum -= arr[left];
                left++;
            }

            if(sum==target){
              len= right-left+1;

              if(left>0 && best[left-1]!=INT_MAX){
                ans=min(ans,best[left-1] + len);
              }
              minlen=min(len,minlen);
            
            }//curr
         if(right>0){
            best[right]=best[right-1];
         }

         if(sum==target){
            best[right]=min(right-left+1 , best[right]);
         }

         
        }//for
        return ans==INT_MAX ?-1:ans;
    }
};