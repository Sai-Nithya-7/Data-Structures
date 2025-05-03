// C++ Program to find the maximum number of blocks that can be moved to Tower 1 after performing valid moves.

#include <iostream>
#include <vector>
using namespace std;

class BlockTowers {
public:
    void solve();

private:
    long long Max_t1(vector<long long>& tow);
};

int main() {
    BlockTowers bt;
    bt.solve();
    return 0;
}

// Function to process test cases
void BlockTowers::solve() {
    int t;
    cout << "No. of testcases:";
    cin >> t;

    while (t--) {
        int n;
        cout << "No of towers in the testcase :";
        cin >> n;
        vector<long long> tow(n);

        for (int i = 0; i < n; i++) {
            cout << "No. of blocks in tower " << i+1 << ":";
            cin >> tow[i];
        }

        long long result = Max_t1(tow);

        cout << "Largest possible blocks in tower 1: " << result << endl;
    }
}

// Function to find the maximum number of blocks Tower 1 can have
long long BlockTowers::Max_t1(vector<long long>& tow) {
    long long tower1 = tow[0];

    for (int i = 1; i < tow.size(); i++) {
        if (tower1 < tow[i]) {
            long long diff = (tow[i] - tower1 + 1) / 2;
            tower1 += diff;
        }
    }

    return tower1;
}