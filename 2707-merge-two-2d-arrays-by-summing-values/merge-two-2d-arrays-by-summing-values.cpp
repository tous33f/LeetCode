class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        vector<vector<int>>ans;
        unordered_map<int,int>idxs;
        int i=0,j=0,key,value,cur=0;
        while(i<n1 && j<n2){
            if(nums1[i][0]<nums2[j][0]){
                key=nums1[i][0];
                value=nums1[i][1];
                i++;
            }
            else if(nums1[i][0]>nums2[j][0]){
                key=nums2[j][0];
                value=nums2[j][1];
                j++;
            }
            else {
                key=nums1[i][0];
                value=nums1[i][1]+nums2[j][1];
                i++;
                j++;
            }
            if(idxs.find(key)==idxs.end()){
                ans.push_back(vector<int>{key,value});
                idxs[key]=cur++;
            }
            else{
                ans[idxs[key]][1]+=value;
            }
            cout<<key<<","<<value<<endl;
        }
        while(i<n1){
            key=nums1[i][0];
            value=nums1[i][1];
            i++;
            if(idxs.find(key)==idxs.end()){
                ans.push_back(vector<int>{key,value});
                idxs[key]=cur++;
            }
            else{
                ans[idxs[key]][1]+=value;
            }
        }
        while(j<n2){
            key=nums2[j][0];
            value=nums2[j][1];
            j++;
            if(idxs.find(key)==idxs.end()){
                ans.push_back(vector<int>{key,value});
                idxs[key]=cur++;
            }
            else{
               ans[idxs[key]][1]+=value;
            }
        }
        return ans;
    }
};