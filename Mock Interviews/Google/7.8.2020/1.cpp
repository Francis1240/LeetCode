#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int numTilePossibilities(string tiles) {
        int res = 0;
        N = tiles.size();
        unordered_map<char, int> dict;
        for (const auto& tile : tiles) {
            dict[tile]++;
        }
        backtrack(dict, "", res);
        return res;
    }
    
    void backtrack(unordered_map<char, int> dict, string cur, int& res) {
        if (cur.size() >= N) {
            return;
        }    
        
        for (auto& tile : dict) {
            if (tile.second > 0) {
                res++;
                cur += tile.first;
                tile.second--;
                backtrack(dict, cur, res);
                cur.pop_back();
                tile.second++;        
            }
        }
        
    }
    
private:
    int N;
};