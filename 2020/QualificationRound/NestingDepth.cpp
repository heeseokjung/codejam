#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int TC;
    cin >> TC;
    for(int tc = 1; tc <= TC; ++tc) {
        string s;
        cin >> s;

        vector<char> v;
        int size = (int)s.size();
        int i, j;
        for(i = 0, j = 0; i < size; ++i) {
            int d = s[i] - '0';
            if(j < d) {
                for(int k = 0; k < d-j; ++k)
                    v.push_back('(');
                v.push_back(s[i]);
                j = d;
            } else if(j > d) {
                for(int k = 0; k < j-d; ++k)
                    v.push_back(')');
                v.push_back(s[i]);
                j = d;
            } else {
                v.push_back(s[i]);
            }
        }
        for(int k = 0; k < j; ++k)
            v.push_back(')');
        
        size = (int)v.size();
        cout << "Case #" << tc << ": ";
        for(int i = 0; i < size; ++i)
            cout << v[i];
        cout << "\n";
    }
    return 0;
}