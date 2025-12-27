#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement:
Given an array of integers and multiple range queries, find the sum
of elements in a given range for each query.

Approach (Using Prefix Sums):
We construct a prefix sum array where prefix[i] stores the sum of
elements from index 0 to i. For any range [l, r], the sum can be
calculated in O(1) time using:
prefix[r] - prefix[l - 1].

Time Complexity:
O(n + q)

Space Complexity:
O(n)

Example:
Input:
5
1 2 3 4 5
1
1 3

Output:
9

Submission Link : https://codeforces.com/contest/1560/submission/355273828
*/

int main() {
    int n;
    cin >> n;

    vector<int> arr(n), prefix(n);

    // Building prefix sum array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (i == 0) {
            prefix[i] = arr[i];
        } else {
            prefix[i] = prefix[i - 1] + arr[i];
        }
    }

    int q;
    cin >> q;

    // Answering queries
    while (q--) {
        int l, r;
        cin >> l >> r;

        int sum;
        if (l == 0) {
            sum = prefix[r];
        } else {
            sum = prefix[r] - prefix[l - 1];
        }

        cout << sum << endl;
    }

    return 0;
}
