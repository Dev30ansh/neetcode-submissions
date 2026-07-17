class PrefixTree {
public:
    struct trieNode{
        bool isEndOfWord;
        trieNode* children[26];
    };

    trieNode* getNode(){
        //creates a new trie node
        trieNode* newNode = new trieNode();

        // mark end of word to false
        newNode->isEndOfWord = false;
        // mark null to every children of newNode
        for(int i = 0; i < 26; i++){
            newNode->children[i] = NULL;
        }

        return newNode;
    }

    //create a root node for trie
    trieNode* root;

    PrefixTree() {
        root = getNode();
    }
    
    void insert(string word) {
        //crate a crawler which will traverse along with the word in trie
        trieNode* crawler =root;

        //get each char in word
        for(auto ch : word){
            //find index of ch
            int idx = ch - 'a';

            if(crawler->children[idx] == NULL){
                crawler->children[idx] = getNode();
            }
            crawler = crawler->children[idx];
        }
        crawler->isEndOfWord = true;
    }
    
    bool search(string word) {
        trieNode* crawler =root;

        for(auto ch : word){
            int idx = ch - 'a';

            if(crawler->children[idx] == NULL){
                return false;
            }
            crawler = crawler->children[idx];
        }

        //we reached the end of word, now check if that char is end of the word
        if(crawler != NULL and crawler->isEndOfWord == true){
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        trieNode* crawler = root;
        
        int i = 0;
        for(; i < prefix.length(); i++){
            char ch = prefix[i];
            int idx = ch - 'a';

            if(crawler->children[idx] == NULL){
                return false;
            }
            crawler = crawler->children[idx];
        }

        //we traversed to all the char of the prefix word, we return true
        if(i == prefix.length()){
            return true;
        }
    }
};
