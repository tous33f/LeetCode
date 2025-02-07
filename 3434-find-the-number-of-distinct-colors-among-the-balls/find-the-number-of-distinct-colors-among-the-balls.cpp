class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>balls;
        unordered_map<int,int>colors;
        vector<int>ans;
        int last;
        for(vector<int>query:queries){
            last=(ans.size()<1)?0:ans[ans.size()-1];
            bool b,c;
            int prev_color,new_color;
            if( balls.find(query[0])==balls.end() ){
                b=false;
                balls[query[0]]=0;
            }
            else{
                b=true;
            }
            prev_color=0?!b:(balls[query[0]]);
            new_color=query[1];

            if(colors.find(query[1])==colors.end() || colors[query[1]]<1){
                c=false;
                colors[query[1]]=0;
            }
            else{
                c=true;
            }
            if(!b && !c) ans.push_back(last+1);
            else if(b && !c){
                if(colors[prev_color]>1){
                    ans.push_back(last+1);
                }
                else{
                    ans.push_back(last);
                }
            }
            else if(!b && c){
                ans.push_back(last);
            }
            else{
                if(colors[prev_color]<=1 && prev_color!=new_color){
                    ans.push_back(last-1);
                }
                else{
                    ans.push_back(last);
                }
            }
            if(prev_color>0) colors[prev_color]--;
            colors[new_color]++;
            balls[query[0]]=new_color;
        }
        return ans; 
    }
};