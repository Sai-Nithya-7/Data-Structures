// Program to calculate points earned by three players based on unique and shared 3-letter words

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> Play_game(int n, vector<string> &a, vector<string> &b, vector<string> &c) {
    unordered_map<string, int> freq;
    
    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
        freq[b[i]]++;
        freq[c[i]]++;
    }

    int score1 = 0, score2 = 0, score3 = 0;

    for (int i = 0; i < n; i++) {
        if (freq[a[i]] == 1) score1 += 3;
        else if (freq[a[i]] == 2) score1 += 1;

        if (freq[b[i]] == 1) score2 += 3;
        else if (freq[b[i]] == 2) score2 += 1;

        if (freq[c[i]] == 1) score3 += 3;
        else if (freq[c[i]] == 2) score3 += 1;
    }

    return {score1, score2, score3};
}

int main() {
    int t;
    cout << "Enter number of test cases: ";
    cin >> t;

    while (t--) {
        int n;
        cout << "Enter number of words each player writes: ";
        cin >> n;

        vector<string> a(n), b(n), c(n);

        cout << "Enter words by player 1: ";
        for (int i = 0; i < n; i++) cin >> a[i];

        cout << "Enter words by player 2: ";
        for (int i = 0; i < n; i++) cin >> b[i];

        cout << "Enter words by player 3: ";
        for (int i = 0; i < n; i++) cin >> c[i];

        vector<int> result = Play_game(n, a, b, c);
        cout << "Points: " << result[0] << " " << result[1] << " " << result[2] << "\n";
    }

    return 0;
}