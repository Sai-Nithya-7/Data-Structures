// Program to find the minimum no. of elements to be removed from the beginning so that all other elements are distinct

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int Polycarp(vector<int> &arr) {
    unordered_set<int> seen;
    int n = arr.size();
    int count = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (seen.find(arr[i]) == seen.end()) {
            seen.insert(arr[i]);
        } else {
            break;
        }
        count++;
    }

    return n - count;
}

int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;

    while (t--) {
        int n;
        cout << "Enter number of elements: ";
        cin >> n;

        vector<int> arr(n);
        cout << "Enter the elements: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int result = Polycarp(arr);
        cout << "Minimum elements to remove from the beginning: " << result << "\n";
    }

    return 0;
}