int romanToDecimal(std::string &s) {
        std::map<char, int> values;
        values['I'] = 1;
        values['V'] = 5;
        values['X'] = 10;
        values['L'] = 50;
        values['C'] = 100;
        values['D'] = 500;
        values['M'] = 1000;

        int ans = 0;
        int n = s.length();

        for (int i = 0; i < n; ++i) {
            if (i + 1 < n && values[s[i]] < values[s[i + 1]]) {
                ans += values[s[i + 1]] - values[s[i]];
                ++i; // Skip the next character since it's already processed
            } else {
                ans += values[s[i]];
            }
        }

        return ans;
