class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int>colors(3,0);
        for(int num:nums) colors[num]++;
        int index=0;
        for(int i=0;i<colors.size();i++){
            while(colors[i]>0){
                nums[index++]=i;
                colors[i]--;
            }
        }
    }
};