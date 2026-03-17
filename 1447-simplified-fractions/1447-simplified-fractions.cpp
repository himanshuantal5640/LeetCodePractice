class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> trishya;
        for(int d = 2;d<=n;d++){
            for(int ne = 1;ne<d;ne++){
                if(__gcd(ne,d) == 1){
                    trishya.push_back(to_string(ne) +"/"+to_string(d));
                }
            }
        }
        return trishya;
    }
};