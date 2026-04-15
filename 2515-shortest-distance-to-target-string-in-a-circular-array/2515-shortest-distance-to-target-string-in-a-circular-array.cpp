class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int minSteps = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int diff = abs(i - startIndex);
                int steps = min(diff, n - diff);
                minSteps = min(minSteps, steps);
            }
        }

        return (minSteps == INT_MAX) ? -1 : minSteps;
    }
};