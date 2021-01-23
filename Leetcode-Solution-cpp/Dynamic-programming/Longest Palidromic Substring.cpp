class Solution {
public:
	string longestPalindrome(string s) {
		string ans;
		int j; int k;
		int n = s.size();
		for (int i = 0; i < n; i++) {
			j = i; k = i + 1;
			while (j >= 0 && k < n) {
				if (s[j] != s[k])break;
				j--;
				k++;
			}
			if (ans.size() < k - j - 1) {
				ans = s.substr(j + 1, k - j - 1);
			}
			j = i - 1; k = i + 1;
			while (j >= 0 && k < n) {
				if (s[j] != s[k])break;
				j--;
				k++;
			}
			if (ans.size() < k - j - 1) {
				ans = s.substr(j + 1, k - j - 1);
			}
		}
		return ans;
	}
};