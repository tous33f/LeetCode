class Solution {
public:
    vector<int> minOperations(string boxes) {
        int balls_left,balls_right;
        balls_left=int(boxes[0]-'0');
        balls_right=int(boxes[boxes.length()-1]-'0');

        vector<int>ops_left={0};
        vector<int>ops_right={0};
        
        for(int i=1,j=boxes.length()-2;i<boxes.length() && j>=0;i++,j--){
            ops_left.push_back(balls_left+ops_left[i-1]);
            ops_right.push_back(balls_right+ops_right[i-1]);
            if(boxes[i]=='1'){
                balls_left++;
            }
            if(boxes[j]=='1'){
                balls_right++;
            }
        }

        for(int i=0,j=boxes.length()-1;i<boxes.length() && j>=0;i++,j--){
            ops_left[i]+=ops_right[j];
        }
        return ops_left;
    }
};