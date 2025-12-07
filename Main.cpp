#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>
#include <string>
#include <map>
#include <windows.h>
#include <fstream>
using namespace std;
using namespace literals::chrono_literals;

//Will hold all of the threads as they run
vector<thread> threads;

string longest_word(vector<string> words){
    string longest = "";

    for(auto& word : words){
        if(word.length() > longest.length()){
            longest = word;
        }
    }

    return longest;
}

string shortest_word(vector<string> words){
    string shortest = "";
    int length = INT_MAX;

    for(auto& word : words){
        if(word.length() < length){
            shortest = word;
            length = word.length();
        }
    }

    return shortest;
}

long average_length(vector<string> words){
    long total_chars = 0;

    for(auto& word : words){
        total_chars += word.length();
    }

    return total_chars / words.size();
}

int main(){
    int num;
    string word;
    vector<string> words;

    ifstream stream("lorem_ipsum.txt");

    while(stream >> word){
        words.push_back(word);
    }

    cout << words.size() << endl;

    //Will determine the longest word in the file, and how long it takes to find said word
    auto start = chrono::high_resolution_clock::now();
    cout << "The longest word is: " << longest_word(words) << endl;
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Time: " << duration.count() << " microseconds" << endl;
    cout << endl;

    //Will determine the shortest word in the file
    start = chrono::high_resolution_clock::now();
    cout << "The shortest word is: " << shortest_word(words) << endl;
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Time: " << duration.count() << " microseconds" << endl;
    cout << endl;

    //Will determine the average length of a word in the file
    start = chrono::high_resolution_clock::now();
    cout << "The average word length is: " << average_length(words) << endl;
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Time: " << duration.count() << " microseconds" << endl;
    cout << endl;

    stream.close();

    return 0;
}