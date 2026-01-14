class Solution {
public:
    struct Event {
        long long x;
        int type; // +1 add, -1 remove
        long long y1, y2;
        bool operator<(Event const& other) const {
            return x < other.x;
        }
    };

    double computeArea(double Y, vector<vector<int>>& sq) {
        vector<Event> events;
        for(auto &s : sq) {
            long long x = s[0], y = s[1], l = s[2];
            if(Y <= y) continue;
            long long top = min((double)(y+l), Y);
            events.push_back({x, +1, y, top});
            events.push_back({x+l, -1, y, top});
        }
        if(events.empty()) return 0;
        sort(events.begin(), events.end());

        multiset<pair<long long,long long>> active;
        auto calcYUnion = [&]() {
            if(active.empty()) return 0LL;
            vector<pair<long long,long long>> v(active.begin(), active.end());
            sort(v.begin(), v.end());
            long long len=0;
            long long curL=v[0].first, curR=v[0].second;
            for(auto &p:v){
                if(p.first>curR){
                    len += curR-curL;
                    curL=p.first; curR=p.second;
                } else curR=max(curR,p.second);
            }
            len += curR-curL;
            return len;
        };

        double area=0;
        long long prevX=events[0].x;
        for(auto &e:events){
            long long dx = e.x - prevX;
            if(dx>0){
                long long ylen = calcYUnion();
                area += (double)dx * ylen;
            }
            if(e.type==1) active.insert({e.y1,e.y2});
            else active.erase(active.find({e.y1,e.y2}));
            prevX=e.x;
        }
        return area;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double low=1e18, high=-1e18;
        for(auto &s:squares){
            low = min(low, (double)s[1]);
            high = max(high, (double)s[1]+s[2]);
        }

        double total = computeArea(high, squares);
        double target = total/2.0;

        for(int i=0;i<60;i++){
            double mid=(low+high)/2;
            if(computeArea(mid,squares) < target) low=mid;
            else high=mid;
        }
        return low;
    }
};
