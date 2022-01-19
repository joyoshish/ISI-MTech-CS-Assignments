#if !defined(__GTRIE__)
#define __GTRIE__

#define ALPHABET_SIZE 36
// a-z[0-25] 0-9[26-35]

typedef struct TrieNode{
    struct TrieNode *(elements[ALPHABET_SIZE]);
    int  count;
    // count of number of words that pass/reach this alphabet
    int end_flag;
    // 0 if no word ends here
    // 1 if atleaast one word in the dctionary ends here
}TrieNode;

int CHAR_TO_KEY(char c);
TrieNode *newTrie();
TrieNode *initTrieNode();
void insertTrie(TrieNode *trie, char *s);
TrieNode *searchTrie(TrieNode *trie, char *s);
void freeTrie(TrieNode *trie);



#endif // __GTRIE__
