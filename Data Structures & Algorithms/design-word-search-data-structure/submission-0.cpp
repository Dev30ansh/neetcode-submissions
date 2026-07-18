class WordDictionary {
   public:
    struct trieNode {
        bool isEndOfWord;
        trieNode* children[26];
    };

    trieNode* getNode() {
        trieNode* newNode = new trieNode();

        newNode->isEndOfWord = false;

        for (int i = 0; i < 26; i++) {
            newNode->children[i] = NULL;
        }
        return newNode;
    }

    trieNode* root;

    WordDictionary() { root = getNode(); }

    void addWord(string word) {
        trieNode* crawler = root;

        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];
            int idx = ch - 'a';

            if (crawler->children[idx] == NULL) {
                crawler->children[idx] = getNode();
            }
            crawler = crawler->children[idx];
        }
        crawler->isEndOfWord = true;
    }

    //helper function-
    bool searchUtil(trieNode* root, string word) {
        trieNode* crawler = root;

        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];
            int idx = ch - 'a';

            // handle case when ch = '.'
            if (ch == '.') {
                // try every possibility from 'a' - 'z'
                for (int j = 0; j < 26; j++) {
                    if (crawler->children[j] != NULL) {
                        // koi element mila hai
                        // search rest the next elements after '.'
                        if (searchUtil(crawler->children[j], word.substr(i + 1)) == true) {
                            return true;
                        }
                    }
                }
                return false;
            }

            // rest other cases when ch = 'a'/'b'/...'z'
            else if (crawler->children[idx] == NULL) {
                return false;
            }
            //crawler ko age badhao
            crawler = crawler->children[idx];
        }

        return (crawler != NULL and crawler->isEndOfWord == true);
    }

    bool search(string word) {
        //helper func to find word
        return searchUtil(root, word); 
    }
};
