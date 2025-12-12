//This file will hold the methods for calculating the shortest word, longest word, 
//and average word length
#ifndef SOLUTIONS_H
#define SOLUTIONS_H
#include <vector>
#include <string>
#include <map>
using namespace std;
#pragma once

void average_length(vector<string> words, double& average);
void shortest_word(vector<string> words, string& shortest);
void longest_word(vector<string> words, string& longest);
void most_common_word(vector<string> words, string& most_common);

#endif