//This file will split the original word vector into a bunch of smaller vectors
//so that each vector can be searched in their own thread

#include "multiThread.h"
#include "solutions.h"
#include "multiThreadSolution.h"

void threaded_solution(int thread_num, vector<string> words){
    //Will hold all of the string vectors that will be used in each thread
    vector<vector<string>> word_collections;
    //Holds all of the average word lengths
    vector<double> averages;
    //Holds all of the longest words
    vector<string> longest_words;
    //Holds all of the shortest words
    vector<string> shortest_words;
    //Holds all of the most common words
    vector<string> common_words;

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
        averages.push_back(0.0);
        longest_words.push_back("");
        shortest_words.push_back("");
        common_words.push_back("");
        i += collections_size;
    }

    multi_longest(word_collections, longest_words);
    multi_shortest(word_collections, shortest_words);
    multi_average(word_collections, averages);
    multi_common(word_collections, common_words);
}