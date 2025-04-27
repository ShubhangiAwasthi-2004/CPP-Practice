//Given two numbers as strings s1 and s2. Calculate their Product.
//Note: The numbers can be negative and You are not allowed to use any built-in function or convert the strings to integers.
//There can be zeros in the begining of the numbers. You don't need to specify '+' sign in the begining of positive numbers.

class Solution {
  public:
    string multiplyStrings(string& s1, string& s2) {
        // Check if the result should be negative
        bool isNegative = false;
        if (s1[0] == '-') {
            isNegative = !isNegative;
            s1 = s1.substr(1);
        }
        if (s2[0] == '-') {
            isNegative = !isNegative;
            s2 = s2.substr(1);
        }

        // Remove leading zeros
        while (s1.size() > 1 && s1[0] == '0') s1.erase(0, 1);
        while (s2.size() > 1 && s2[0] == '0') s2.erase(0, 1);

        if (s1 == "0" || s2 == "0") return "0";  // Special case

        int n = s1.size();
        int m = s2.size();
        vector<int> result(n + m, 0);

        // Multiply each digit
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (s1[i] - '0') * (s2[j] - '0');
                int sum = mul + result[i + j + 1];
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }

        // Convert result vector to string
        string ans = "";
        int i = 0;
        // Skip leading zeros
        while (i < result.size() && result[i] == 0) i++;
        while (i < result.size()) ans += (result[i++] + '0');

        if (isNegative) ans = '-' + ans;
        return ans;
    }
};
