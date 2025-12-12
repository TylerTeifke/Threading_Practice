#ifndef MULTITHREADSOLUTION_H
#define MULTITHREADSOLUTION_H
#include <string>
#include <vector>
#include <thread>
#include <iostream>
#include <map>
using namespace std;
#pragma once

void multi_average(vector<vector<string>> word_collections, vector<double> averages);
void multi_longest(vector<vector<string>> word_collections, vector<string> longest_words);
void multi_shortest(vector<vector<string>> word_collections, vector<string> shortest_words);
void multi_common(vector<vector<string>> word_collections, vector<string> common_words);

#endif