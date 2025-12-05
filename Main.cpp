#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>
#include <string>
#include <map>
#include <windows.h>
using namespace std;
using namespace literals::chrono_literals;

mutex water;
mutex free_time;
map<int, string> chores = {{1, "[1] Take a shower"}, {2, "[2] Wash the dishes"}, {3, "[3] Cook dinner"}};
//Will hold all of the threads as they run
vector<thread> threads;

void shower(){
    water.lock();

    cout << "Showering in progress" << endl;
    this_thread::sleep_for(5s);
    cout << "Shower finished" << endl;

    water.unlock();
}

void dish_washer(){
    water.lock();

    cout << "Washing dishes" << endl;
    this_thread::sleep_for(5s);
    cout << "Dishes washed" << endl;

    water.unlock();
}

void stove(){
    free_time.lock();

    cout << "Cooking Food" << endl;
    this_thread::sleep_for(5s);
    cout << "Food finished" << endl;

    free_time.unlock();
}

void run_chore(int var){
    switch (var){
    case 1:
        threads.emplace_back(shower);
        chores.erase(var);
        break;
    case 2:
        threads.emplace_back(dish_washer);
        chores.erase(var);
        break;
    case 3:
        threads.emplace_back(stove);
        chores.erase(var);
        break;
    }
}

int main(){
    int num;

    while(chores.empty() == false){
        cout << "Type the number in brackets to do the matching chore" << endl;

        //Will only print out the message for each chore, and ensures that the map
        //is looped through properly, even when a chore has been completed
        for(auto& chore : chores){
            cout << chore.second << endl;
        }

        cout << "Enter Number: ";
        cin >> num;
        run_chore(num);
        Sleep(1);
    }

    //Will ensure all threads complete their execution before the program ends
    for(auto& thread : threads){
        thread.join();
    }

    cout << "All chores completed" << endl;

    return 0;
}