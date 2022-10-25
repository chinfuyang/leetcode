// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
	
    int firstBadVersion(int n) {
		bool preBad = isBadVersion(1);
		if (preBad) return 1;
		for (int i = 2; i < n; i++) {
			bool curBad = isBadVersion(i);
			if (! preBad && curBad) {
				return i;
			}
			preBad = curBad;
		}

		return n;
    }
};