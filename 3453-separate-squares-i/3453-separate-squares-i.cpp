class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        int n = squares.size();
        
        // Find search boundaries
        double low = 1e18, high = -1e18;
        for(auto &s : squares){
            double y = s[1], l = s[2];
            low = min(low, y);
            high = max(high, y + l);
        }
        
        // Function to compute (area_below - area_above)
        auto diff = [&](double H){
            double below = 0, above = 0;
            for(auto &s : squares){
                double y = s[1], l = s[2];
                double top = y + l;
                
                if(top <= H) {
                    below += l * l;
                }
                else if(y >= H) {
                    above += l * l;
                }
                else {
                    // line cuts square
                    below += l * (H - y);
                    above += l * (top - H);
                }
            }
            return below - above;
        };
        
        // Binary search for balance point
        for(int i = 0; i < 70; i++){
            double mid = (low + high) / 2.0;
            if(diff(mid) < 0)
                low = mid;
            else
                high = mid;
        }
        
        return low;
    }
};
