#include <string>
#include <vector>

class StringHash {

public:
    using ull = unsigned long long;
    const int P = 13331;

    StringHash(const std::string& s)
        : s(s), len(s.size()), _hash(len + 1), p(len + 1) {
        
        //预处理p的幂和_hash值 
        p[0] = 1;
        for(int i = 1; i <= len; ++ i) {
            p[i] = p[i - 1] * P;
            _hash[i] = _hash[i - 1] * P + s[i - 1];
        }
    }

    ull get(int l, int r) const {
        ++l; ++ r;
        return _hash[r] - _hash[l - 1] * p[r - l + 1];
    }

private:
    int len;
    std::string s;
    std::vector<ull> _hash;
    std::vector<ull> p;
};