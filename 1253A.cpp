    // https://codeforces.com/problemset/problem/1253/A
    
    #include <bits/stdc++.h>
     
    #define for0(i, n) for (int i = 0; i < (int)(n); ++i)
    #define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
    #define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
    #define forr0(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
    #define forr1(i, n) for (int i = (int)(n); i >= 1; --i)
    #define pb push_back
    #define fi first
    #define se second
    #define all(x) (x).begin(), (x).end()
    #define rall(x) (x).rbegin, (x).rend()
     
    using namespace std;
     
    typedef long long ll;
    typedef vector<int> vi;
    typedef vector<ll> vll;
    typedef vector<vi> vvi;
    typedef vector<vll> vvll;
    typedef double ld;
    typedef pair<int, int> pi;
     
    int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.precision(10);
        cout << fixed;
        int nt;
        cin >> nt;
        vvi c;
        
        for0(i,nt) {
            int length;
            cin >> length;
            vi a;
            vi b;
            for0(j,length) {
                int val;
                cin >> val;
                a.pb(val);
            }
            for0(j,length) {
                int val;
                cin >> val;
                b.pb(val);
            }
     
            bool failed = false;
            int change = 0;
            int last_diff = b[0]-a[0];
            if(last_diff != 0) {
                change += 1;
            }
            int prev_diff = last_diff;
            for0(j,length) {
                if(b[j] - a[j] < 0) {
                    failed = true;
                    break;
                } else {
                    if (last_diff != b[j]-a[j]) {
                            if((prev_diff != 0) || (prev_diff != b[j]-a[j])) {
                                if ( (b[j]-a[j] != 0))
                                    change += 1;
                            }
                            prev_diff = last_diff;
                            last_diff = b[j] - a[j];
                    }       
                    if(change > 1) {
                        failed = true;
                        break;
                    }
                }
            }
            if(failed) {
                cout << "NO" <<'\n';
            } else {
                cout << "YES" <<'\n';
            }
        }
     
        return 0;
    }
