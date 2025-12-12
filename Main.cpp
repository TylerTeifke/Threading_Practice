#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>
#include <string>
#include <map>
#include <windows.h>
#include <fstream>
#include "multiThread.h"
#include "solutions.h"
using namespace std;
using namespace literals::chrono_literals;

//Will hold all of the threads as they run
vector<thread> threads;

int main(){
    string word;
    vector<string> words;

    ifstream stream("lorem_ipsum.txt");

    while(stream >> word){
        words.push_back(word);
    }
    stream.close();

    //Will determine the longest word in the file, and how long it takes to find said word
    string longest = "";
    auto start = chrono::high_resolution_clock::now();
    longest_word(words, longest);
    cout << "The longest word is: " << longest << endl;
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Time: " << duration.count() << " microseconds" << endl;
    cout << endl;

    //Will determine the shortest word in the file
    string shortest = "";
    start = chrono::high_resolution_clock::now();
    shortest_word(words, shortest);
    cout << "The shortest word is: " << shortest << endl;
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Time: " << duration.count() << " microseconds" << endl;
    cout << endl;

    //Will determine the average length of a word in the file
    double average = 0.0;
    start = chrono::high_resolution_clock::now();
    average_length(words, average);
    cout << "The average word length is: " << average << endl;
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Time: " << duration.count() << " microseconds" << endl;
    cout << endl;

    //Will determine the most common word in the file
    string most_common = "";
    start = chrono::high_resolution_clock::now();
    most_common_word(words, most_common);
    cout << "The most common word is: " << most_common << endl;
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Time: " << duration.count() << " microseconds" << endl;
    cout << endl;

    int threads = 1;
    while(threads > 0){
        cout << "Enter the number of threads you want to use. Enter 0 or a negative number to quit: ";
        cin >> threads;

        if(threads > 0){
            threaded_solution(threads, words);
        }
    }

    cout << "End Program" << endl;
    return 0;
}