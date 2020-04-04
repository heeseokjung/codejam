#include <cstdio>

int main() {
    int TC;
    scanf("%d", &TC);
    for(int tc = 1; tc <= TC; ++tc) {
        int N;
        int arr[100][100];
        scanf("%d", &N);
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
                scanf("%d", &arr[i][j]);
        
        int trace = 0;
        for(int i = 0, j = 0; i < N && j < N; ++i, ++j)
            trace += arr[i][j];

        int r = 0, c = 0;
        bool dup[101];
        for(int i = 0; i < N; ++i) {
            for(int k = 1; k <= N; ++k)
                dup[k] = false;
            for(int j = 0; j < N; ++j) {
                if(!dup[arr[i][j]]) {
                    dup[arr[i][j]] = true;
                } else {
                    r++;
                    break;
                }
            }
        }
        for(int j = 0; j < N; ++j) {
            for(int k = 1; k <= N; ++k)
                dup[k] = false;
            for(int i = 0; i < N; ++i) {
                if(!dup[arr[i][j]]) {
                    dup[arr[i][j]] = true;
                } else {
                    c++;
                    break;
                }
            }
        }

        printf("Case #%d: %d %d %d\n", tc, trace, r, c);
    }
    return 0;
}