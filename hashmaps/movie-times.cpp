#include <vector>
#include <map>
#include <iostream>


// WRONG
bool canFitTwoMovies(const vector<int> movieTimes, int flightLength){
    //build a map of movieTimes
    int pos = 0;
    map<int, int> movieMap; //time, id/pos
    for (int movieTime : movieTimes) {
        movieSet.insert(make_pair(movieTime, pos));
        pos++;
    }

    //iterate again, check map to see if there is a fit for your flight.
    pos = 0;
    for (int movieTime : moveTimes){
        int remainingTime = flightLength - movieTime;
        if (movieSet.find(remainingTime) != movieSet.end() && //we have a movie of this time
            movieSet.at(movieTime) != pos //and its not the same movie as the one we're currently examining
        ){
            //we have at least one fit, return true
            return true;
        }
        pos++;
    }
    //no two movie fits found
    return false;
}

bool canFitTwoMoviesCorrect(const vector<int> movieTimes, int flightLength){
     unordered_set<int> movieLengthsSeen;

     for (int firstMovieLength : movieLengths) {
         int matchingSecondMovieLength = flightLength - firstMovieLength;
         if (movieLengthsSeen.find(matchingSecondMovieLength) != movieLengthsSeen.end()) {
             return true;
         }
         movieLengthsSeen.insert(firstMovieLength);
     }

     // we never found a match, so return false
     return false;
}

int main(){

}