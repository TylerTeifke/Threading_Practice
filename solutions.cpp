#include "solutions.h"

void average_length(vector<string> words, double& average){
    double total_chars = 0;

    for(auto& word : words){
        total_chars += (double) word.length();
    }

    average = total_chars / (double) words.size();
}

void shortest_word(vector<string> words, string& shortest){
    string new_shortest = "";
    int length = INT_MAX;

    for(auto& word : words){
        if(word.length() < length){
            new_shortest = word;
            length = word.length();
        }
    }

    shortest = new_shortest;
}

void longest_word(vector<string> words, string& longest){
    string new_longest = "";

    for(auto& word : words){
        if(word.length() > new_longest.length()){
            new_longest = word;
        }
    }

    longest = new_longest;
}

void most_common_word(vector<string> words, string& most_common){
    map<string, int> word_counts;
    int greatest = 0;
    string current_most_common = "";

    for(auto& word : words){
        word_counts[word] = word_counts[word] + 1;

        if(word_counts[word] > greatest){
            greatest = word_counts[word];
            current_most_common = word;
        }
    }

    most_common = current_most_common;
}