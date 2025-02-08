N - Queen Problem

    class Solution
{
public:
    void solve(int colo, int n, vector<vector<int>> &ans, vector<int> &sol, vector<bool> &col, vector<bool> &ldiag, vector<bool> &rdiag)
    {
        for (int i = 0; i < n; i++)
        {
            if (colo == n)
            {
                ans.push_back(sol);
                return;
            }
            if (!col[i] && !ldiag[colo - i + n - 1] && !rdiag[i + colo])
            {
                sol.push_back(i + 1);
                col[i] = true;
                ldiag[colo - i + n - 1] = true;
                rdiag[i + colo] = true;

                solve(colo + 1, n, ans, sol, col, ldiag, rdiag);
                sol.pop_back();
                col[i] = false;
                ldiag[colo - i + n - 1] = false;
                rdiag[i + colo] = false;
            }
        }
    }
    vector<vector<int>> nQueen(int n)
    {
        vector<bool> col(n, false);
        vector<bool> ldiag(2 * n - 1, false);
        vector<bool> rdiag(2 * n - 1, false);
        vector<vector<int>> ans;
        vector<int> sol;
        solve(0, n, ans, sol, col, ldiag, rdiag);
        return ans;
    }