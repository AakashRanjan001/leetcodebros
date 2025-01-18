class Solution {
public:
    map<char, int> mp;
    const int mod = 1e9 + 7;

    long long factorial_recursive(int n) {
        if (n == 0 || n == 1) 
            return 1;
        return (n * factorial_recursive(n - 1)) % mod;
    }

    long long modExp(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    long long modInverse(long long a, long long mod) {
        return modExp(a, mod - 2, mod);
    }

    int countAnagrams(string s) {
        vector<string> v;
        int i = 0, j = 0;
        
        // Fixing word extraction
        while (i < s.size()) {
            if (s[i] == ' ') {
                v.push_back(s.substr(j, i - j));
                j = i + 1;
            }
            i++;
        }
        v.push_back(s.substr(j, i - j));  // Last word

        long long res = 1;
        
        for (int i = 0; i < v.size(); i++) {
            mp.clear();
            for (auto ch : v[i]) 
                mp[ch]++;
            
            long long num = factorial_recursive(v[i].size());
            long long deno = 1;
            
            for (auto p : mp) {
                deno = (deno * factorial_recursive(p.second)) % mod;
            }

            // Fix division with modulo inverse
            res = (res * (num * modInverse(deno, mod) % mod)) % mod;
        }

        return res;
    }
};
