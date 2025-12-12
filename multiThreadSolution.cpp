//This file will actually run multiple threads to get the various solutions

#include "multiThreadSolution.h"
#include "solutions.h"

void multi_average(vector<vector<string>> word_collections, vector<double> averages){
    vector<thread> threads;
    //launch all of the threads
    auto start = chrono::high_resolution_clock::now();
    for(int k = 0; k < word_collections.size(); k++){
        threads.emplace_back(average_length, word_collections[k], ref(averages[k]));
    }

    //Wait for all of the threads to finish, then calculate the average
    for(auto& thread : threads){
        thread.join();
    }
    threads.clear();

    double overall_average = 0.0;
    for(auto& average : averages){
        overall_average += average;
    }
    overall_average /= averages.size();

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "Multi-threaded average: " << overall_average << endl;
    cout << "Time: " << duration.count() << " microseconds" << endl;
    cout << endl;
}

void multi_longest(vector<vector<string>> word_collections, vector<string> longest_words){
    vector<thread> threads;
    //launch all of the threads
    auto start = chrono::high_resolution_clock::now();
    for(int k = 0; k < word_collections.size(); k++){
        threads.emplace_back(longest_word, word_collections[k], ref(longest_words[k]));
    }

    //Wait for all of the threads to finish, then calculate the average
    for(auto& thread : threads){
        thread.join();
    }
    threads.clear();

    string longest = "";
    for(auto& word : longest_words){
        if(word.size() > longest.size()){
            longest = word;
        }
    }

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "Multi-threaded longest word: " << longest << endl;
    cout << "Time: " << duration.count() << " microseconds" << endl;
    cout << endl;
}

void multi_shortest(vector<vector<string>> word_collections, vector<string> shortest_words){
    vector<thread> threads;
    //launch all of the threads
    auto start = chrono::high_resolution_clock::now();
    for(int k = 0; k < word_collections.size(); k++){
        threads.emplace_back(shortest_word, word_collections[k], ref(shortest_words[k]));
    }

    //Wait for all of the threads to finish, then calculate the average
    for(auto& thread : threads){
        thread.join();
    }
    threads.clear();

    string shortest = "";
    int length = INT_MAX;
    for(auto& word : shortest_words){
        if(word.size() < length){
            shortest = word;
            length = word.size();
        }
    }

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "Multi-threaded longest word: " << shortest << endl;
    cout << "Time: " << duration.count() << " microseconds" << endl;
    cout << endl;
}

void multi_common(vector<vector<string>> word_collections, vector<string> common_words){
    vector<thread> threads;
    //launch all of the threads
    auto start = chrono::high_resolution_clock::now();
    for(int k = 0; k < word_collections.size(); k++){
        threads.emplace_back(most_common_word, word_collections[k], ref(common_words[k]));
    }

    //Wait for all of the threads to finish, then calculate the average
    for(auto& thread : threads){
        thread.join();
    }
    threads.clear();

    string most_common = "";
    map<string, int> word_counts;
    int frequency = 0;
    for(auto& word : common_words){
        word_counts[word] = word_counts[word] + 1;

        if(word_counts[word] > frequency){
            most_common = word;
            frequency = word_counts[word];
        }
    }

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "Multi-threaded most common word: " << most_common << endl;
    cout << "Time: " << duration.count() << " microseconds" << endl;
    cout << endl;
}