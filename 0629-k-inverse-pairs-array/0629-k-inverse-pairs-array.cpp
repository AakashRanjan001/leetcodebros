
class Solution {
public:                              //will solve again
	int C(int n) {
		return n * (n - 1) / 2;
	}
	int kInversePairs(int n, int k) {
		int d = pow(10, 9) + 7;
		long long **arr = new long long*[n + 1];
		for(int i = 0; i < n + 1; i++) arr[i] = new long long[k + 1];
		for(int i = 0; i < n + 1; i++) {
			for(int j = 0; j < k + 1; j ++) {
				if(j == 0 || j == C(i)) arr[i][j] = 1;
				else if(j < 0 || j > C(i)) arr[i][j] = 0;
				else {
					arr[i][j] = (arr[i][j - 1] + arr[i - 1][j]) % d;
					if(j > i - 1) arr[i][j] = (arr[i][j] % d - arr[i - 1][j - i] % d) % d;
				}
			}
		}
		if(arr[n][k] < 0) return int(d + arr[n][k]);
		else return int(arr[n][k]);
	}
};