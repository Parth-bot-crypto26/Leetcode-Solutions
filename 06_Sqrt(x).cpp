class Solution {
public:
    int mySqrt(int x) {
        if(x < 0) return -1;
        if(x == 0) return 0;
        if(x == 1) return 1;
        double low = 0, high = x;;
        for(int i = 0; i < 100; i++){
            double mid = (low+high)/2;
            if(mid*mid > x){
                high = mid;
            }else{
                low = mid;
            }
        }
        return (int)low;
    }
};