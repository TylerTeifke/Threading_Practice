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

void average_length(vector<string> words, long& average){
    long total_chars = 0;

    for(auto& word : words){
        total_chars += word.length();
    }

    average = total_chars / words.size();
}

int main(){
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
    long average = 0;
    start = chrono::high_resolution_clock::now();
    average_length(words, average);
    cout << "The average word length is: " << average << endl;
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Time: " << duration.count() << " microseconds" << endl;
    cout << endl;

    //These vectors will be used to divide the collection of words into 5 different groups.
    //This way the program will be able to check each group simultaneously, and lower the run time
    vector<string> words1;
    vector<string> words2;
    vector<string> words3;
    vector<string> words4;
    vector<string> words5;

    for(int i = 0; i < 200000; i++){
        words1.push_back(words.at(i));
    }
    for(int i = 200000; i < 400000; i++){
        words2.push_back(words.at(i));
    }
    for(int i = 400000; i < 600000; i++){
        words3.push_back(words.at(i));
    }
    for(int i = 600000; i < 800000; i++){
        words4.push_back(words.at(i));
    }
    for(int i = 800000; i < words.size(); i++){
        words5.push_back(words.at(i));
    }

    long avg1 = 0;
    long avg2 = 0;
    long avg3 = 0;
    long avg4 = 0;
    long avg5 = 0;

    start = chrono::high_resolution_clock::now();
    thread t1(average_length, words1, ref(avg1));
    thread t2(average_length, words2, ref(avg2));
    thread t3(average_length, words3, ref(avg3));
    thread t4(average_length, words4, ref(avg4));
    thread t5(average_length, words5, ref(avg5));

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    long overall_avg = (avg1 + avg2 + avg3 + avg4 + avg5) / 5;

    cout << "Multi-threaded average: " << overall_avg << endl;

    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Time: " << duration.count() << " microseconds" << endl;
    
    stream.close();

    return 0;
}