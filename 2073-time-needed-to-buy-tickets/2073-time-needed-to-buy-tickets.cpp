class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;
        int time = 0;
        for(int i=0;i<tickets.size();i++){
            q.push(i);
        }
        while(!q.empty()){
            time++;
            int f = q.front();
            q.pop();
            tickets[f]--;
            if(k == f && tickets[f] == 0){
                return time;
            }
            if(tickets[f] != 0){
                q.push(f);
            }
        }
        return time;
    }
};