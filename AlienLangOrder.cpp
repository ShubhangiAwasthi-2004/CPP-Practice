/*A new alien language uses the English alphabet, but the order of letters is unknown. 
You are given a list of words[] from the alien language’s dictionary, where the words are 
claimed to be sorted lexicographically according to the language’s rules.

Your task is to determine the correct order of letters in this alien language based on the given words. 
If the order is valid, return a string containing the unique letters in lexicographically increasing order as per the new language's rules.
If there are multiple valid orders, return any one of them.

However, if the given arrangement of words is inconsistent with any possible letter ordering, return an empty string ("").

A string a is lexicographically smaller than a string b if, at the first position where they differ,
the character in a appears earlier in the alien language than the corresponding character in b.
If all characters in the shorter word match the beginning of the longer word, the shorter word is considered smaller.

Note: Your implementation will be tested using a driver code. 
It will print true if your returned order correctly follows the alien language’s lexicographic rules; 
otherwise, it will print false.*/


class Solution {
public:
    string findOrder(vector<string> &words) {
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> inDegree;

        // Initialize graph with all unique characters
        for (const string& word : words) {
            for (char c : word) {
                graph[c];
                inDegree[c];
            }
        }

        // Build graph
        for (int i = 0; i < words.size() - 1; ++i) {
            string& w1 = words[i];
            string& w2 = words[i + 1];
            int len = min(w1.size(), w2.size());
            bool found_diff = false;

            for (int j = 0; j < len; ++j) {
                char c1 = w1[j];
                char c2 = w2[j];
                if (c1 != c2) {
                    if (graph[c1].find(c2) == graph[c1].end()) {
                        graph[c1].insert(c2);
                        inDegree[c2]++;
                    }
                    found_diff = true;
                    break;
                }
            }

            // Check for invalid case: prefix issue
            if (!found_diff && w1.size() > w2.size()) {
                return "";
            }
        }

        // Topological Sort using Kahn's Algorithm
        queue<char> q;
        for (auto it = inDegree.begin(); it != inDegree.end(); ++it) {
            if (it->second == 0)
                q.push(it->first);
        }

        string result;
        while (!q.empty()) {
            char curr = q.front(); q.pop();
            result += curr;

            for (char neighbor : graph[curr]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If not all characters are used, there is a cycle
        if (result.size() != graph.size())
            return "";

        return result;
    }
};
