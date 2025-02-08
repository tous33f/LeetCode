class NumberContainers {
public:
    unordered_map<int,int> nums;//min indexes of numbers
    unordered_map<int,int> idxs;//indexes with their numbers
    NumberContainers() {
        ;
    }
    
    void change(int index, int number) {
        int prev_num=(idxs.find(index)!=idxs.end())?idxs[index]:-1;
        if(prev_num>0 && nums[prev_num]==index){
            //loop to find minimum
            unordered_map<int,int>::iterator itr;
            int min=INT_MAX;
            for(itr=idxs.begin();itr!=idxs.end();itr++){
                if(itr->second==prev_num && itr->first!=index && itr->first<min) min=itr->first;
            }
            if(min!=INT_MAX) nums[prev_num]=min;
            else nums.erase(prev_num);
            idxs[index]=number;
            if(nums.find(number)==nums.end() || nums[number]>index){
                nums[number]=index;
            }
        }
        else{
            idxs[index]=number;
            if(nums.find(number)==nums.end() || nums[number]>index){
                nums[number]=index;
            }
        }
    }
    
    int find(int number) {
        if(nums.find(number)==nums.end()) return -1;
        else return nums[number];
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */