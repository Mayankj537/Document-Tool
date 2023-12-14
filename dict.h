// Do NOT add any other includes
#include <string> 
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Dict {
private:
    // You can add attributes/helper functions here
    //vector<vector<pair<int,string>>> dict;
    vector<vector<string>> dict;
    //vector<vector<pair<int,string>>> ar;
    //vector<string> st;

public: 
    /* Please do not touch the attributes and 
    functions within the guard lines placed below  */
    //void get_strings(string sentence);
    /* ------------------------------------------- */
    Dict();

    ~Dict();

    void insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence);

    int get_word_count(string word);

    void dump_dictionary(string filename);

    /* -----------------------------------------*/
};

// // Do NOT add any other includes
// #include <string> 
// #include <vector>
// #include <iostream>
// #include <fstream>
// using namespace std;

// class Dict {
// private:
//     vector<vector<pair<int,string>>> ar;
//     vector<string> st;
    
// public: 
//     /* Please do not touch the attributes and 
//     functions within the guard lines placed below  */
//     void get_strings(string sentencce);
//     /* ------------------------------------------- */
//     Dict();

//     ~Dict();

//     void insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence);

//     int get_word_count(string word);

//     void dump_dictionary(string filename);

//     /* -----------------------------------------*/
// };