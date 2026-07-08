class Solution {
   public:
    int calPoints(vector<string>& operations) {
        vector<int> record;

        for (string& op : operations) {
            if (op == "+") {
                record.push_back(record[record.size() - 1] + record[record.size() - 2]);
            } else if (op == "D") {
                record.push_back(2 * record.back());
            } else if (op == "C") {
                record.pop_back();
            } else {
                record.push_back(stoi(op));  // converting string to int
            }
        }

        int ans = 0;
        for (int score : record) {
            ans += score;
        }
        return ans;
    }
};