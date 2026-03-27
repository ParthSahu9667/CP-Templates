class TrieNode {
public:
    TrieNode* child[2];
    int count;
    TrieNode () {
        child[0] = child[1] = NULL;
        count = 0;
    }
};

class trie {
public:
    TrieNode* root;
    int maxbit;
    trie () {
        maxbit = 30;
        root = new TrieNode();
    }
    void add(int num) {
        insert(root, num);
    }
    void insert (TrieNode* root, int &num) {
        root->count++;
        for (int bit = maxbit; bit >= 0; bit--) {
            int need = (num >> bit & 1);
            TrieNode* next = root->child[need];

            if (!next) {
                next = new TrieNode();
            }

            root->child[need] = next;
            root = next;
            root->count++;
        }
    }

    void remove(int num) {
        remove(root, num);
    }
    void remove (TrieNode* root, int& num) {
        root->count--;
        for (int bit = maxbit; bit >= 0; bit--) {
            if (num >> bit & 1) {
                TrieNode* next = root->child[1];
                root = next;
            }
            else {
                TrieNode* next = root->child[0];
                root = next;
            }
            root->count--;
        }
    }

    int maxXor(int num) { 
        return maxXor(root, num); 
    }
    int maxXor(TrieNode* root, int &num) {
        int ans = 0;

        for (int bit = maxbit; bit >= 0; bit--) {
            int need = !(num >> bit & 1);

            if (root->child[need] && root->child[need]->count > 0) {
                TrieNode* next = root->child[need];
                root = next;
                ans |= (1 << bit);
            }
            else {
                TrieNode* next = root->child[!need];
                root = next;
            }
        }

        return ans;
    }
};