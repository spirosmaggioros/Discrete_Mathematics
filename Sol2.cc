#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vector_ll vecor<long long>
#define MOD 1000000007
typedef long long int int64;
typedef unsigned long int uint32;

template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef SPIROS_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

class checker {
public:
    void generate(vector<string> &S , vector<string> &universe){
        sort(S.begin() , S.end());
        for(auto & x : S){
            s.insert(x);
        }
    }
    bool A(string &x) {
        if(s.find(x) != s.end()){
            return true;
        }
        return false;
    }

    pair<vector<string> , vector<string> > create_E_EC(vector<string> &universe){
        vector<string> E , EC;
        for(auto & x : universe){
            if(A(x)){
                E.emplace_back(x);
            }
            else{
                EC.emplace_back(x);
            }
        }
        return {E , EC};
    }

    unordered_set<string> generate_checker(vector<string> &E , vector<string> &EC){
        unordered_set<string> A;
        for(auto & x : E){
            A.insert(x);
        }
    }
private:
    unordered_set<string> s;
    vector<string> E;
};

int main(){
    checker sol;
    vector<string> universe = {"0" , "01" , "10" , "11" , "001" , "010" , "011" , "100" , "101" , "110" , "111"};
    vector<string> E = {"0" , "11" , "101"};
}
