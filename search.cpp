// Do NOT add any other includes
#include "search.h"

SearchEngine::SearchEngine(){
    // Implement your function here  
}

SearchEngine::~SearchEngine(){
    // Implement your function here  
}
void SearchEngine::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence){
    for(char& c : sentence){
        if (c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a';
        }
    }
    // Check if 'book_code', 'page', 'paragraph', and 'sentence_no' are within valid bounds
        if (book_code >= 0 && page >= 0 && paragraph >= 0 && sentence_no >= 0) {
            if (book_code >= searcher.size()) {
                searcher.resize(book_code + 1);
            }
            if (page >= searcher[book_code].size()) {
                searcher[book_code].resize(page + 1);
            }
            if (paragraph >= searcher[book_code][page].size()) {
                searcher[book_code][page].resize(paragraph + 1);
            }
            if (sentence_no >= searcher[book_code][page][paragraph].size()) {
                searcher[book_code][page][paragraph].resize(sentence_no + 1,"");
            }
            searcher[book_code][page][paragraph][sentence_no] = sentence;
    }
}
unsigned long computeHash(string pattern){
    unsigned long hash = 5381;
    for (char ch : pattern) {
        hash = ((hash << 5) + hash) + ch;
    }
    return hash % 1000000007;
}
unsigned long updateHash(unsigned long oldHash, char oldChar, char newChar, int patternLength) {
    unsigned long hashValue = oldHash;
    hashValue = (hashValue - (oldChar << (5 * (patternLength - 1)))) % 1000000007;
    hashValue = (hashValue << 5) + hashValue + newChar;
    return hashValue % 1000000007;  
}
Node* SearchEngine::search(string pattern, int& n_matches) {
    for (char& c : pattern) {
        if (c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a';
        }
    }

    unsigned long patternHash = computeHash(pattern);
    Node* head = nullptr;
    Node* current = nullptr;

    n_matches = 0;  // Initialize the match count to 0

    for (int book_code = 0; book_code < searcher.size(); book_code++) {
        for (int page = 0; page < searcher[book_code].size(); page++) {
            for (int paragraph = 0; paragraph < searcher[book_code][page].size(); paragraph++) {
                for (int sentence_no = 0; sentence_no < searcher[book_code][page][paragraph].size(); sentence_no++) {
                    string sentence = searcher[book_code][page][paragraph][sentence_no];
                    for (char& c : sentence) {
                        if (c >= 'A' && c <= 'Z') {
                            c = c - 'A' + 'a';
                        }
                    }
                    if (sentence.length() < pattern.length()) {
                        // Skip short sentences that are shorter than the pattern
                        continue;
                    }

                    for (size_t i = 0; i <= sentence.length() - pattern.length(); i++) {
                        unsigned long sentenceHash = computeHash(sentence.substr(i, pattern.length()));
                        // Check hash value for the current window
                        if (sentenceHash == patternHash) {
                            bool isMatch = true;
                            for (size_t j = 0; j < pattern.length(); j++) {
                                if (pattern[j] != sentence[i + j]) {
                                    isMatch = false;
                                    break;
                                }
                            }
                            if (isMatch) {
                                Node* matchNode = new Node(book_code, page, paragraph, sentence_no, i);
                                if (current == nullptr) {
                                    head = matchNode;
                                    current = head;
                                } else {
                                    current->right = matchNode;
                                    current = matchNode;
                                }
                                n_matches++;  // Increment the match count
                            }
                        }
                        sentenceHash = updateHash(sentenceHash, sentence[i], sentence[i + pattern.length()], pattern.length());
                    }
                }
            }
        }
    }
    return head;
}





// int main(){
//     SearchEngine Engine;
//     Engine.insert_sentence(0,1,1,1,"Thi1s is Piyush, I want to talk to you");
//     Engine.insert_sentence(0,1,1,2,"this Actually I love you This");
//     Engine.insert_sentence(0,1,1,3,"You this have such beautiful eyes");
//     Engine.insert_sentence(0,1,1,4,"Really in my life, you came as a fortune for me");
//     int n_matches = 0;
//     Node* head = Engine.search("this actually",n_matches);
//     cout<<n_matches<<endl;
//     int i = 1;
//     Node* temp = head;
//     while(temp){
//         cout<<"ab bolo\n";
//         cout<<"here is word "<<i<<endl;
//         cout<<"book code is "<<temp->book_code<<endl;
//         cout<<"page is "<<temp->page<<endl;
//         cout<<"paragraph no. is "<<temp->paragraph<<endl;
//         cout<<"sentence no. is "<<temp->sentence_no<<endl;
//         temp = temp->right;
//         i++;
//     }
// return 0;
// }