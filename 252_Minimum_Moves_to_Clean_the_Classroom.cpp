class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr = -1, sc = -1;
        vector<pair<int,int>> litter;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char ch = classroom[i][j];
                if (ch == 'S') { sr = i; sc = j; }
                else if (ch == 'L') { litter.push_back({i, j}); }
            }
        }

        int k = (int)litter.size();
        if (k == 0) return 0;

        int fullMask = (1 << k) - 1;
        vector<vector<int>> litIndex(m, vector<int>(n, -1));
        for (int idx = 0; idx < k; idx++) {
            litIndex[litter[idx].first][litter[idx].second] = idx;
        }

        int ecap = energy;
        int eCount = ecap + 1;
        int maskCount = 1 << k;
        int total = m * n * eCount * maskCount;

        vector<int> dist(total, -1);
        vector<int> q;
        q.reserve(total);

        auto encode = [&](int r, int c, int e, int mask) -> int {
            return ((r * n + c) * eCount + e) * maskCount + mask;
        };

        int startState = encode(sr, sc, ecap, 0);
        dist[startState] = 0;
        q.push_back(startState);

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        int ans = -1;
        size_t head = 0;
        while (head < q.size()) {
            int state = q[head++];
            int d = dist[state];

            int mask = state % maskCount;
            int tmp = state / maskCount;
            int e = tmp % eCount;
            int posv = tmp / eCount;
            int r = posv / n;
            int c = posv % n;

            if (mask == fullMask) {
                ans = d;
                break;
            }

            if (e <= 0) continue;

            for (int dir = 0; dir < 4; dir++) {
                int nr = r + dr[dir];
                int nc = c + dc[dir];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                char ch = classroom[nr][nc];
                if (ch == 'X') continue;

                int ne = (ch == 'R') ? ecap : (e - 1);
                int nmask = mask;
                if (ch == 'L') {
                    int idx = litIndex[nr][nc];
                    if (idx != -1) nmask = mask | (1 << idx);
                }

                int nstate = encode(nr, nc, ne, nmask);
                if (dist[nstate] == -1) {
                    dist[nstate] = d + 1;
                    q.push_back(nstate);
                }
            }
        }

        return ans;
    }
};