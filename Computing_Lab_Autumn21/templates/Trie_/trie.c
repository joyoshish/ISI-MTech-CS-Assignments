#include "trie.h"
#include "common.h"

int CHAR_TO_KEY(char c){
    if (isalpha(c)){
        return ((int)c - (int)'a');
    }
    else if (isdigit(c)){
        return ((int)c - (int)'0') + 26;
    }
    return -1;
}


TrieNode *newTrie(){
    TrieNode *trie = initTrieNode();
    return trie;
}

TrieNode *initTrieNode(){
    TrieNode *trie;
    if (NULL == (trie = CALLOC(TrieNode, 1))){
        printf("Out Of memory : Could not allocate memory for TrieNode\n");
        assert(trie != NULL);
    }
    trie->end_flag = 0;
    trie->count = 0;
    int i;
    for(i = 0; i < ALPHABET_SIZE; i++){
        trie->elements[i] = NULL;
    }
    return trie;
}


void freeTrie(TrieNode *trie){
    int i;
    for(i = 0; i < ALPHABET_SIZE; i++){
        if (trie->elements[i] != NULL){
            freeTrie(trie->elements[i]);
        }
    }
    free(trie);
}

void insertTrie(TrieNode *trie, char *s){
    int i; // level
    int length = strlen(s);
    int char_position;
    TrieNode *p = trie;

    for(i = 0; i < length; i++)
    {
        char_position = CHAR_TO_KEY(s[i]);
        assert(char_position != -1);
        if (p->elements[char_position] == NULL){
            p->elements[char_position] = initTrieNode();
        }
        p = p->elements[char_position];
        p->count += 1;
    }
    p->end_flag = 1;
}

TrieNode *searchTrie(TrieNode *trie, char *s){
    int i; // level
    int length = strlen(s);
    int char_position;
    TrieNode *p = trie;

    for(i = 0; i < length; i++)
    {
        char_position = CHAR_TO_KEY(s[i]);
        assert(char_position != -1);
        if (p->elements[char_position] == NULL){
            return NULL;
            // trie dosot have the provided word
        }
        p = p->elements[char_position];
    }
    return p;
}
