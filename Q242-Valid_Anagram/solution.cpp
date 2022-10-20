#include <unordered_map>

class Solution {
public:
    bool isAnagram(string s, string t) {
		int a[26];
		for (int i = 0; i < 26; i++) {
			a[i] = 0;
		}
		for (auto c : s) {
			a[c-'a'] += 1;
		}
		for (auto c : t) {
			a[c-'a'] -= 1;
		}
		for (int i = 0; i < 26; i++) {
			if (a[i] != 0) {
				return false;
			}
		}
		return true;
    }

    bool isAnagram2(string s, string t) {
		if (s.size() != t.size()) return false;
		std::unordered_map<char, int> _umap;
		for (auto c : s) {
			_umap[c]++;
		}
		for (auto c : t) {
			_umap[c]--;
			if (_umap[c] < 0)
				return false;
		}
		
		return true;
    }
};