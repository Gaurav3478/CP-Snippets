#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
#define int long long
#define double long double
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

void run_case(int test_case) {
    
}

signed main() {    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int num_test_cases = 1;
    cin >> num_test_cases;
    for(int test_case = 1; test_case <= num_test_cases; test_case++) {
        run_case(test_case);
    }

    return 0;
}
