#include "multiThread.h"
#include "solutions.h"

void threaded_solution(int thread_num, vector<string> words){
    //Will hold all of the string vectors that will be used in each thread
    vector<vector<string>> word_collections;
    //Holds all of the threads
    vector<thread> threads;
    //Holds all of the average word lengths
    vector<long> averages;

    int collections_size = words.size() / thread_num;

    int i = 0;
    while(i < words.size()){
        vector<string> collection;

        //adds words to a collection until there are enough words in the collection
        //or until the file runs out of words
        for(int j = i; j < i + collections_size && j < words.size(); j++){
            collection.push_back(words[j]);
        }

        word_collections.push_back(collection);
        averages.push_back(0);
        i += collections_size;
    }

    cout << "number of collections " << word_collections.size() << endl; 

    //launch all of the threads
    for(int k = 0; k < word_collections.size(); k++){
        threads.emplace_back(average_length, word_collections[k], ref(averages[k]));
    }

    //Wait for all of the threads to finish, then calculate the average
    for(auto& thread : threads){
        thread.join();
    }
    threads.clear();

    long overall_average = 0;
    for(auto& average : averages){
        cout << average << endl;
        overall_average += average;
    }
    overall_average /= averages.size();

    cout << "Multi-threaded average: " << overall_average << endl;
}