#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int TC;
    scanf("%d", &TC);
    for(int tc = 1; tc <= TC; ++tc) {
        int N;
        scanf("%d", &N);
        vector<pair<int, pair<int, int> > > v(N);
        vector<char> ans(N, 'C');
        for(int i = 0; i < N; ++i) {
            scanf("%d %d", &v[i].first, &v[i].second.first);
            v[i].second.second = i;
        }

        sort(v.begin(), v.end());

        bool possible = true;
        int c = 0, j = 0;
        for(int i = 0; i < N; ++i) {
            if(c <= v[i].first) {
                ans[v[i].second.second] = 'C';
                c = v[i].second.first;
            } else if(j <= v[i].first) {
                ans[v[i].second.second] = 'J';
                j = v[i].second.first;
            } else {
                possible = false;
                break;
            }
        }

        if(!possible) {
            printf("Case #%d: IMPOSSIBLE\n", tc);
        } else {
            printf("Case #%d: ", tc);
            for(int i = 0; i < N; ++i)
                printf("%c", ans[i]);
            printf("\n");
        }
    }
    return 0;
}