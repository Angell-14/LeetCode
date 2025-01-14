class Solution {
public:
vector<int> getRow(int rowIndex) {
    vector<int> row(rowIndex + 1, 1);  // Initialize the row with 1s

    for (int i = 1; i <= rowIndex / 2; i++) {
        // Use long long to prevent overflow during intermediate calculations
        long long val = (long long)row[i - 1] * (rowIndex - (i - 1)) / i;
        row[i] = val;
        row[rowIndex - i] = val;
    }

    return row;
}

};