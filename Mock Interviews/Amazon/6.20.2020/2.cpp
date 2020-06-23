#include <vector>
#include <string>
#include <algorithm>

using namespace std;


struct Node{
    public:
        char c = '0';
        vector< Node * > next;
};

class Trie {
private: 
    Node * root;
public:
    
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int n = word.length();
        Node * curr = this->root;
        for(int i = 0; i < n; i++){
            char c = word[i];
            int found = -1;
            int n_size = curr->next.size();
            for(int j = 0; j < n_size; j++){
                if(curr->next[j]->c == c){
                    found = j;
                    break;
                }
            }
            if(found != -1){
                if(i == n-1){
                    for(int j = 0; j < curr->next[found]->next.size(); j++){
                        if(curr->next[found]->next[j]->c == '0'){
                            return;
                        }
                    }
                    Node * newNode = new Node();
                    newNode->c = '0';
                    curr->next[found]->next.push_back(newNode);
                    return;
                }
                curr = curr->next[found];
                continue;
            }
            Node * newNode = new Node();
            newNode->c = c;
            curr->next.push_back(newNode);
            curr = newNode;
        }
        for(int i = 0; i < curr->next.size();i++){
            if(curr->next[i]->c == '0')
            return ;
        } 
        Node * newNode = new Node();
        newNode->c = '0';
        curr->next.push_back(newNode);
        return;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node * curr = this->root;
        for(int i = 0; i < word.length(); i++){
            int found = -1;
            for(int j = 0; j < curr->next.size();j++){
                if(word[i] == curr->next[j]->c){
                    found = j;
                    break;
                }
            }
            if(found == -1){
                return false;
            }
            curr = curr->next[found];
        }
        for(int i = 0; i < curr->next.size();i++){
            if(curr->next[i] -> c == '0'){
                return true;
            }
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        Node * curr = this->root;
        for(int i = 0; i < word.length(); i++){
            int found = -1;
            for(int j = 0; j < curr->next.size();j++){
                if(word[i] == curr->next[j]->c){
                    found = j;
                    break;
                }
            }
            if(found == -1){
                return false;
            }
            curr = curr->next[found];
        }
        return true;
    }
};
