class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        int i=0,j=0,key,value;
        vector<vector<int>>ans;
        while(i<n1 && j<n2){
            if(nums1[i][0]<nums2[j][0]){
                key=nums1[i][0];
                value=nums1[i++][1];
            }
            else if(nums1[i][0]>nums2[j][0]){
                key=nums2[j][0];
                value=nums2[j++][1];
            }
            else{
                key=nums1[i][0];
                value=nums1[i++][1]+nums2[j++][1];
            }
            ans.push_back(vector<int>{key,value});
        }
        while(i<n1){
            key=nums1[i][0];
            value=nums1[i++][1];
            ans.push_back(vector<int>{key,value});
        }
        while(j<n2){
            key=nums2[j][0];
            value=nums2[j++][1];
            ans.push_back(vector<int>{key,value});
        }
        return ans;
    }
};