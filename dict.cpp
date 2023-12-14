// // Do NOT add any other includes
// #include "dict.h"

// Dict::Dict(){
//     // Implement your function here 
//     int size=1000000;
//     dict.resize(size);
// ;}

// Dict::~Dict(){
//     // Implement your function here    
// }

// std::vector<std::string> splitIntoWords(const std::string& sentence) {
//     std::vector<std::string> words;
//     std::string word="";
//     string seprators =".,-:!\"\'( )?[ ]; @";
//     for (char ch : sentence) {
//         if (seprators.find(ch)!=string::npos){
//             if (!word.empty()) {
//                 words.push_back(word);
//                 word.clear();
//             }
//         } else {
//             word += ch;
//         }
//     }

//     // Push the last word if any
//     if (!word.empty()) {
//         words.push_back(word);
//     }

//     return words;
// }

// int hashFunc(std::string key) {
//     unsigned long hash = 5381;
//     for (char ch : key) {
//         hash = ((hash << 5) + hash) + ch; 
//     }
//     return hash % 1000000;
// //int sum=0;


// // for(int i=0;i<key.size();i++){
// // sum+=i*(static_cast<int>(key[i])+(static_cast<int>(toupper(key[i]))));
// // }

// // return sum%269;
    
// }
// void Dict::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence){
//     // Implement your function here
//     for(char& c : sentence) {
//         if (c >= 'A' && c <= 'Z') {
//             c = c - 'A' + 'a';
//         }
//     }
//     vector<string> words = splitIntoWords(sentence);
//     for(string word : words){
//         int key=hashFunc(word);
//         bool exist=true;
//         for(int i=0;i<dict[key].size();i++){
//             //int cnt=dict[key][i].first;
//             string result=dict[key][i].second;
//             //string result="";
//             //string word_count="";
//             // bool check=false;
//             // for(char c: s){
//             //     if(check){
//             //         if(c>='0'&& c<='9'){
//             //         word_count+=c;
//             //     }
//             //     }
//             //     else if(c=='-'){
//             //         check=true;
//             //     }
//             //     else{
//             //         result+=c;
//             //     }
//             // }
//         if(result==word){
//             //int num=std::stoi(word_count);
//             //num++;
//             dict[key][i].first++;
//             //string cnt=std::to_string(num);
//             //s=word+'-'+cnt;
//             //dict[key].push_back(std::make_pair(cnt, word));
//             exist=false;//this exist is red underlined
//         }
//         }
//         if(exist){
//             dict[key].push_back(std::make_pair(1, word));
//         }}
        
//     return;
// }

// int Dict::get_word_count(string word){
//     // Implement your function here 
//     for(char& c : word) {
//         if (c >= 'A' && c <= 'Z') {
//             c = c - 'A' + 'a';
//         }
//     }
//     int key=hashFunc(word);
//     for(int i=0;i<dict[key].size();i++){
//         int cnt=dict[key][i].first;
//         string result=dict[key][i].second;
//         //string result="";
//         //string cnt="";
//         //bool check=false;
//         // for(char c: s){
//         //     if(check){
//         //         if(c>='0'&& c<='9'){
//         //             cnt+=c;
//         //         }
//         //     }
//         //     else if(c=='-'){
//         //         check=true;
//         //     }
//         //     else{
//         //         result+=c;
//         //     }
//         // }
//         if(result==word){
//             //int num=std::stoi(cnt);
//             return cnt; 
//         }
        
//     }
//     return 0;
// }

// void Dict::dump_dictionary(string filename){
//     // Implement your function here 
//     ofstream out(filename.c_str());
//     ofstream ip;
//     ip.open(filename,ios::app); 
//     for(int i=0;i<dict.size();i++){
//         for(int j=0;j<dict[i].size();j++){
//             string result=dict[i][j].second;
//             //string result="";
//             int cnt=dict[i][j].first;
//             // bool check=false;
//             // for(char c: s){
//             //     if(check){
//             //         if(c>='0'&& c<='9'){
//             //             cnt+=c;
//             //         }
//             //     }
//             //     else if(c=='-'){
//             //         check=true;
//             //     }
//             //     else{
//             //         result+=c;
//             //     }
//             // }
//             ip<<result;
//             ip<<", ";
//             ip<<cnt<<"\n";
//         }
//     }
//     return;
// }


// Do NOT add any other includes
#include "dict.h"

Dict::Dict(){
    // Implement your function here 
    int size=1000000;
    dict.resize(size);
;}

Dict::~Dict(){
    // Implement your function here    
}

std::vector<std::string> splitIntoWords(const std::string& sentence) {
    std::vector<std::string> words;
    std::string word="";
    string seprators =".,-:!\"\'( )?[ ]; @";
    for (char ch : sentence) {
        if (seprators.find(ch)!=string::npos){
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        } else {
            word += ch;
        }
    }

    // Push the last word if any
    if (!word.empty()) {
        words.push_back(word);
    }

    return words;
}

int hashFunc(std::string key) {
    unsigned long hash = 5381;
    for (char ch : key) {
        hash = ((hash << 5) + hash) + ch; 
    }
    return hash % 1000000;
//int sum=0;


// for(int i=0;i<key.size();i++){
// sum+=i*(static_cast<int>(key[i])+(static_cast<int>(toupper(key[i]))));
// }

// return sum%269;
    
}
void Dict::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence){
    // Implement your function here
    for(char& c : sentence) {
        if (c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a';
        }
    }
    vector<string> words = splitIntoWords(sentence);
    for(string word : words){
        int key=hashFunc(word);
        bool exist=true;
        for(int i=0;i<dict[key].size();i++){
            string s=dict[key][i];
            string result="";
            string word_count="";
            bool check=false;
            for(char c: s){
                if(check){
                    if(c>='0'&& c<='9'){
                    word_count+=c;
                }
                }
                else if(c=='-'){
                    check=true;
                }
                else{
                    result+=c;
                }
            }
        if(result==word){
            int num=std::stoi(word_count);
            num++;
            string cnt=std::to_string(num);
            s=word+'-'+cnt;
            dict[key][i] = s;
            exist=false;//this exist is red underlined
        }
        }
        if(exist){
            dict[key].push_back(word+'-'+'1');
        }}
        
    return;
}

int Dict::get_word_count(string word){
    // Implement your function here 
    for(char& c : word) {
        if (c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a';
        }
    }
    int key=hashFunc(word);
    for(int i=0;i<dict[key].size();i++){
        string s=dict[key][i];
        string result="";
        string cnt="";
        bool check=false;
        for(char c: s){
            if(check){
                if(c>='0'&& c<='9'){
                    cnt+=c;
                }
            }
            else if(c=='-'){
                check=true;
            }
            else{
                result+=c;
            }
        }
        if(result==word){
            int num=std::stoi(cnt);
            return num; 
        }
        
    }
    return 0;
}

void Dict::dump_dictionary(string filename){
    // Implement your function here 
    ofstream out(filename.c_str());
    ofstream ip;
    ip.open(filename,ios::app); 
    for(int i=0;i<dict.size();i++){
        for(int j=0;j<dict[i].size();j++){
            string s=dict[i][j];
            string result="";
            string cnt="";
            bool check=false;
            for(char c: s){
                if(check){
                    if(c>='0'&& c<='9'){
                        cnt+=c;
                    }
                }
                else if(c=='-'){
                    check=true;
                }
                else{
                    result+=c;
                }
            }
            ip<<result;
            ip<<", ";
            ip<<cnt<<"\n";
        }
    }
    return;
}

