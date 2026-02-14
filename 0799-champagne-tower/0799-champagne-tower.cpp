class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {

        if (query_row == 0) return min((double)poured, 1.0);

        vector<double> prev(101, 0.0);
        vector<double> curr(101, 0.0);

        prev[0] = poured;
        int row = 0;

        while (++row <= query_row)
        {
            if (row % 2 == 1)
                propagateToNextRow(row, prev, curr);
            else
                propagateToNextRow(row, curr, prev);
        }

        double result = (query_row % 2 == 1) ? curr[query_glass] : prev[query_glass];
        return min(result, 1.0);
    }

private:
    void propagateToNextRow(int row, vector<double>& a, vector<double>& b)
    {
        fill(b.begin(), b.end(), 0.0);

        for (int i = 0; i < row; i++)
        {
            if (a[i] > 1.0)
            {
                double overflow = (a[i] - 1.0) / 2.0;
                b[i] += overflow;
                b[i + 1] += overflow;
            }
        }
    }
};
