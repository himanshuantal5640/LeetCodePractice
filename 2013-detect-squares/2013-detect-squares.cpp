class DetectSquares {
public:
    map<pair<int,int>,int> map;
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        map[{x,y}]++;
    }
    
    int count(vector<int> point) {
        int x1 = point[0];
        int y1 = point[1];
        //try every point as diagonal
        int ans = 0;
        for(auto& it : map){
            int x2 = it.first.first;
            int y2 = it.first.second;
            int freq = it.second;
            if(abs(x1 - x2) != abs(y1 - y2) || x1 == x2 || y1 == y2){
                continue;
            }
            int cnt1 = map[{x1,y2}];
            int cnt2 = map[{x2,y1}];
            ans += freq * cnt1 * cnt2;
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */