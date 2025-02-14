class ProductOfNumbers {
public:
vector<int>products;
int zero=-1;
    ProductOfNumbers() {
        ;
    }
    
    void add(int num) {
        if(num==0){
            zero=products.size();
            products.push_back(1);
            return;
        }
        if(products.size()<1) products.push_back(num);
        else products.push_back( products.back()*num );
    }
    
    int getProduct(int k) {
        int n=products.size()-1;
        cout<<n-k<<","<<zero<<endl;
        if(n-k<zero) return 0;
        else if(k==0 || n-k<0) return products.back();
        else return products.back()/products[n-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */