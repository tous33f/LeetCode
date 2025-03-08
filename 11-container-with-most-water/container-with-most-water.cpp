class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int left=0,right=n-1;
        int area=0;
        while(left<right){
            int t=min(height[left],height[right])*(right-left);
            if(t>area) area=t;
            if(height[left]<height[right]) left++;
            else right--;
        }
        return area;
    }
};