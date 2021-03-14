#include<queue>
#include<unordered_map>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;

class Solution {
    public:
        int ladderLength(string beingWord, string endWord, const vector<string> &wordList){

            if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()){
                return 0;
            }

            unordered_map<string, vector<string>> map;
            buildList(wordList, map, beingWord.length());

            queue<pair<string, int>> beginQueue;
            queue<pair<string, int>> endQueue;

            beginQueue.push(make_pair(beingWord, 1));
            endQueue.push(make_pair(endWord, 1));

            unordered_map<string, int> visitedBegin;
            unordered_map<string, int> visitedEnd;
            visitedBegin[beingWord] = 1;
            visitedEnd[endWord] = 1;

            while(!beginQueue.empty() && !endQueue.empty()){

                int result = visitWordNode(map, beginQueue, visitedBegin, visitedEnd, beingWord.length());
                if (result > -1){
                    return result;
                }

                result = visitWordNode(map, endQueue, visitedEnd, visitedBegin, beingWord.length());
                if (result > -1){
                    return result;
                }
            }

            return 0;
        }


        int visitWordNode(unordered_map<string, vector<string>> &map,
                          queue<pair<string, int>> &q,
                          unordered_map<string, int> &visited,
                          unordered_map<string, int> &visitedOther,
                          const int length){

            pair<string, int> node = q.front();
            q.pop();
            string word = node.first;
            int level = node.second;
            for (int i =0; i< length; i++){
                string wildCard = word;
                wildCard.replace(i, 1, "*");
                for (auto entry : map[wildCard]){

                    //if our other bfs visited this then return!
                    if (visitedOther.find(entry) != visitedOther.end()){
                        return level + visitedOther[entry];
                    }

                    //otherwise if we HAVE NOT visited this
                    if (visited.find(entry) == visited.end()){
                        visited[entry] = level + 1;
                        q.push(make_pair(entry, level +1));
                    }
                }
            }
            return -1;
        }

        void path(string beingWord, string endWord, const vector<string> &wordList, vector<string> &path){

        }

        void buildList(const vector<string> &wordList, unordered_map<string, vector<string>> &map, const int length){
            for (auto word : wordList){
                for(int i =0; i< length; i++){
                    string wildCard = word;
                    wildCard.replace(i, 1, "*");
                    if (map.find(wildCard) == map.end()){
                        vector<string> foo;
                        map[wildCard] = foo;
                    }
                    map[wildCard].push_back(word);
                }
            }
        }


    private:

};


int main () {
    string beingWord = "a";
    string endWord = "c";
//    vector<string> wordList = {
//        "hot","dot","dog","lot","log", "cog"
//    };

    vector<string> wordList = {
        "a", "b", "c"
    };
    Solution s;
    cout << s.ladderLength(beingWord, endWord, wordList) << "\n";

    //vector<string> path;
    //s.path(beingWord, endWord, wordList, path);
//    for(auto word : path){
//        cout << word << "\n";
//    }
//    unordered_map<string, vector<string>> map;
//    s.buildList(wordList, map, 3);
//    for (auto entry : map){
//        cout << "key: " << entry.first << "\n";
//        for (auto word : entry.second){
//            cout << "\t" << word << "\n";
//        }
//    }
}