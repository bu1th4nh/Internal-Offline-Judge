#include <bits/stdc++.h>

using namespace std;

const int MAXN = 150 + 10;
const int MAXL = 15 + 10;

int m, n, mod;
char grid[MAXN][MAXN];
string pattern;

int kmp_nxt[MAXL];
int longest_suffix_of_rev_prefix[MAXL], longest_prefix_of_rev_suffix[MAXL];
int nxt_prefix[MAXL][30], nxt_suffix[MAXL][30];
string suffix[MAXN], prefix[MAXN];
int ways[MAXN][MAXN][MAXN][MAXL][2][2];

void kmp_next()
{
    kmp_nxt[1] = 0;
    for(int i = 2; i <= pattern.length(); ++i)
    {
        int j = kmp_nxt[i - 1];
        while ((j > 0) && (pattern[i - 1] != pattern[j])) j = kmp_nxt[j];
        kmp_nxt[i] = j + (pattern[i - 1] == pattern[j]);
    }

    for(int i = 0; i <= pattern.length(); ++i)
    {
        for(char c = 'a'; c <= 'z'; ++c)
        {
            int j = i - (i == pattern.length());
            while ((j > 0) && (pattern[j] != c)) j = kmp_nxt[j];
            j += (pattern[j] == c);
            nxt_prefix[i][c - 'a'] = j;
        }
    }
}

void gen_nxt_suffix()
{
    for(int i = 0; i <= pattern.length(); ++i)
    {
        for(char c = 'a'; c <= 'z'; ++c)
        {
            string nxt_suf = ""; nxt_suf.push_back(c);
            nxt_suf += suffix[i];
            for(int j = min(pattern.length(), nxt_suf.length()); j >= 0; --j)
            {
                if (nxt_suf.substr(0, j) == suffix[j])
                {
                    nxt_suffix[i][c - 'a'] = j; break;
                }
            }
        }
    }
}

void gen_longest_match()
{
    for(int i = 0; i <= pattern.length(); ++i)
    {
        string rev_prefix = prefix[i];
        reverse(rev_prefix.begin(), rev_prefix.end());
        for(int j = min(pattern.length(), rev_prefix.length()); j >= 0; --j)
            if (rev_prefix.substr(0, j) == suffix[j])
            {
                longest_suffix_of_rev_prefix[i] = j; break;
            }
    }
    for(int i = 0; i <= pattern.length(); ++i)
    {
        string rev_suffix = suffix[i];
        reverse(rev_suffix.begin(), rev_suffix.end());
        for(int j = min(pattern.length(), rev_suffix.length()); j >= 0; --j)
            if (rev_suffix.substr(rev_suffix.length() - j, j) == prefix[j])
            {
                longest_prefix_of_rev_suffix[i] = j; break;
            }
    }
}

void init()
{
    suffix[0] = "";
    for(int i = 1; i <= pattern.length(); ++i)
    {
        suffix[i] = "";
        suffix[i].push_back(pattern[pattern.length() - i]);
        suffix[i] += suffix[i - 1];
    }
    prefix[0] = "";
    for(int i = 1; i <= pattern.length(); ++i)
    {
        prefix[i] = prefix[i - 1];
        prefix[i].push_back(pattern[i - 1]);
    }

    kmp_next();
    gen_nxt_suffix();
    gen_longest_match();
}

void add(int &a, int b)
{
    a = (a + b) % mod;
}

int save_ok_join[MAXL][MAXL];
bool ok_join(int p1, int p2, bool has_common)
{
    if (min(p1, p2) == 0) return 0;
    if (has_common) p2--;
    if (save_ok_join[p1][p2] != 0) return (save_ok_join[p1][p2] == 1);

    string s = prefix[p1] + suffix[p2];
    for(int i = 0; i + pattern.length() - 1 < s.length(); ++i)
        if (s.substr(i, pattern.length()) == pattern)
        {
            save_ok_join[p1][p2] = 1; return true;
        }
    save_ok_join[p1][p2] = -1; return false;
}

void solve()
{
    ways[1][0][m][0][0][0] = 1;
    int path_len = m + n - 1;

    for(int len = 0; len < (path_len + 1) / 2; ++len)
    {
        //cout << "len = " << len << " " << (path_len + 1) / 2 << "\n";
        for(int i = 1; i <= m; ++i)
        {
            //cout << "i = " << i << "\n";
            int j = len + 1 - i; //i + j - 1 = len
            if ( ((len == 0) && (j != 0)) || ((len > 0) && ((j <= 0) || (j > n))) ) continue;
            //cout << "j = " << j << "\n";
            for(int u = 1; u <= m; ++u)
            {
                //cout << "u = " << u << "\n";
                int v = m + n + 1 - len - u; // (m - u + 1) + (n - v + 1) - 1 = len <=> (m + n) - (u + v) + 1 = len
                if ( ((len == 0) && (v != n + 1)) || ( (len > 0) && ((v <= 0) || (v > n)) ) ) continue;

                //cout << "at " << i << " " << j << " " << u << " " << v << "\n";
                for(int longest_match = 0; longest_match <= pattern.length(); ++longest_match)
                {
                    //cout << "longest = " << longest_match << "\n";
                    for(int is_p1 = 0; is_p1 <= 1; ++is_p1)
                    {
                        //cout << "is_p1 = " << is_p1 << "\n";
                        int p1 = (is_p1) ? longest_match : longest_prefix_of_rev_suffix[longest_match];
                        int p2 = (!is_p1) ? longest_match : longest_suffix_of_rev_prefix[longest_match];
                        //cout << "p1, p2 = " << p1 << " " << p2 << "\n";
                        for(int already_contains = 0; already_contains < 2; ++already_contains)
                        {
                            if (ways[i][j][u][longest_match][is_p1][already_contains] == 0) continue;
                            //cout << "state " << longest_match << " " << is_p1 << " " << already_contains << "\n";
                            //cout << p1 << " " << p2 << "\n";
                            //cout << i << " " << j << " " << u << " " << v << " " << p1 << " " << p2 << " " << already_contains << " -> " << ways[i][j][u][longest_match][is_p1][already_contains] << "\n";

                            for(int dx_i = 0; dx_i <= 1; ++dx_i)
                            {
                                int nxt_i = i + dx_i, nxt_j = j + (1 - dx_i);
                                if ((nxt_i <= 0) || (nxt_i > m) || (nxt_j <= 0) || (nxt_j > n)) continue;

                                for(int dx_u = -1; dx_u <= 0; ++dx_u)
                                {
                                    int nxt_u = u + dx_u, nxt_v = v + (-1 - dx_u);
                                    if ((nxt_u <= 0) || (nxt_u > m) || (nxt_v <= 0) || (nxt_v > n)) continue;

                                    if ((grid[nxt_i][nxt_j] != grid[nxt_u][nxt_v]) || (grid[nxt_i][nxt_j] == '#')) continue;

                                    char c = grid[nxt_i][nxt_j];
                                    int nxt_p1 = nxt_prefix[p1][c - 'a'];
                                    int nxt_p2 = nxt_suffix[p2][c - 'a'];
                                    int nxt_is_p1 = (nxt_p1 >= nxt_p2) ? 1 : 0;
                                    //cout << "next cells: " << nxt_i << " " << nxt_j << " " << nxt_u << " " << nxt_v << "\n";
                                    //cout << "nxt match " << nxt_p1 << " " << nxt_p2 << "\n";
                                    add(ways[nxt_i][nxt_j][nxt_u][max(nxt_p1, nxt_p2)][nxt_is_p1][already_contains | (max(nxt_p1, nxt_p2) == pattern.length())], ways[i][j][u][longest_match][is_p1][already_contains]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    int res = 0;
    //cout << "doneeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee\n";
    int len = (path_len + 1) / 2;
    for(int i = 1; i <= m; ++i)
    {
            int j = len + 1 - i; //i + j - 1 = len
            if ( ((len == 0) && (j != 0)) || ((len > 0) && ((j <= 0) || (j > n))) ) continue;

            for(int u = 1; u <= m; ++u)
            {
                int v = m + n + 1 - len - u; // (m - u + 1) + (n - v + 1) - 1 = len <=> (m + n) - (u + v) + 1 = len
                if ( ((len == 0) && (v != n + 1)) || ( (len > 0) && ((v <= 0) || (v > n)) ) ) continue;

                if (((path_len % 2) == 1) && ((i != u) || (j != v))) continue;
                if (((path_len % 2) == 0) && (abs(i - u) + abs(j - v) != 1)) continue;

                for(int longest_match = 0; longest_match <= pattern.length(); ++longest_match)
                {
                    for(int is_p1 = 0; is_p1 <= 1; ++is_p1)
                    {
                        int p1 = (is_p1) ? longest_match : longest_prefix_of_rev_suffix[longest_match];
                        int p2 = (!is_p1) ? longest_match : longest_suffix_of_rev_prefix[longest_match];

                        for(int already_contains = 0; already_contains < 2; ++already_contains)
                        {
                            //cout << i << " " << j << " " << u << " " << v << " " << p1 << " " << p2 << " " << already_contains << " -> " << ways[i][j][u][longest_match][is_p1][already_contains] << "\n";
                            if ((already_contains == 1) || (ok_join(p1, p2, (path_len % 2) == 1)))
                            {
                                add(res, ways[i][j][u][longest_match][is_p1][already_contains]);
                            }
                        }
                    }
                }
            }
    }

    cout << res << "\n";
}

int res_bf = 0;
void go(int x, int y, string s)
{
    if ((x <= 0) || (x > m) || (y < 0) || (y > n)) return;
    if (grid[x][y] == '#') return;
    string ss = s;
    ss.push_back(grid[x][y]);
    if ((x == m) && (y == n))
    {

        for(int i = 0; i < ss.length(); ++i)
            if (ss[i] != ss[ss.length() - 1 - i]) return;

        for(int i = 0; i + pattern.length() - 1 < ss.length(); ++i)
            if (ss.substr(i, pattern.length()) == pattern)
            {
                res_bf++;
                break;
            }
        return;
    }
    go(x + 1, y, ss);
    go(x, y + 1, ss);
}

void brute_force()
{
    res_bf = 0;
    go(1, 1, "");
    cout << "brute force: " << res_bf % mod << "\n";
}

int main()
{
    freopen("wgame.inp", "r", stdin);
    freopen("wgame.out", "w", stdout);

    cin >> m >> n >> mod;
    cin >> pattern;

    for(int i = 1; i <= m; ++i)
    {
        for(int j = 1; j <= n; ++j) cin>>grid[i][j];
    }

    //brute_force();

    init();
    //cout << "init done\n";
    solve();
}
