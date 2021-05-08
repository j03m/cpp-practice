#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <stdexcept>
#include <queue>
#include <utility>
#include <stack>

using namespace std;

void buildGraph(unordered_map<string, vector<string>> &graph,
                vector<string> &wordList,
                string beginWord,
                string endWord){

    const int length = beginWord.length();

    for (auto word : wordList){
        for(int i = 0; i<length; i++){
            string wildCard = word;
            wildCard.replace(i, 1, "*");
            if (graph.find(wildCard) == graph.end()){
                vector<string> foo;
                graph[wildCard] = foo;
            }
            graph[wildCard].push_back(word);
        }
    }

}

int main(){

    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()){
        return 0;
    }

    unordered_map<string, vector<string>> graph;
    unordered_map<string, string> predecessors;
    unordered_map<string, bool> visited;
    int length = beginWord.length();

    //step 1 build a graph
    buildGraph(graph, wordList, beginWord, endWord);

    for(auto word : wordList){
        visited[word] = false;
    }


    queue<string> bfsQueue;
    bfsQueue.push(beginWord);
    while(!bfsQueue.empty()){
        string word = bfsQueue.front();
        bfsQueue.pop();
        if (word == endWord){
            break;
        }
        //cout << word << "\n";
        for(int i = 0; i<length; i++){
            string wildCard = word;
            wildCard.replace(i, 1, "*");
            //cout << "\t" << wildCard << "\n";
            if (visited[wildCard] != true){
                for(auto entry : graph[wildCard]){
                    if (entry != word){
                        cout << "\t\t" << entry << "->" << word << "\n";
                        predecessors[entry] = word;
                        bfsQueue.push(entry);
                    }

                }
                visited[wildCard] = true;
            }
        }

    }
    //cout << "bfs done\n";

    stack<string> path;
    string lookUp = endWord;
    while(predecessors.find(lookUp) != predecessors.end()){
        //cout << "path:" << lookUp <<  "\n";
        path.push(lookUp);
        lookUp = predecessors[lookUp];
    }

    while(!path.empty()){
        //cout << path.top() << "\n";
        path.pop();
    }

}