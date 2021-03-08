#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Meeting {
    public:
    Meeting() : start(0), end(0) {}
    Meeting(int _start, int _end) : start(_start), end(_end) {}
    int start;
    int end;
};





bool compareStart (Meeting &m1, Meeting &m2){ return m1.start < m2.start; }



Meeting doMerge(Meeting m1, Meeting m2){
    Meeting merged;
    merged.start = m1.start < m2.start ? m1.start : m2.start;
    merged.end = m1.end > m2.end ? m1.end : m2.end;
    return merged;
}

int main()
{

    vector<Meeting> meetings;
    meetings.push_back(Meeting(9,10));
    meetings.push_back(Meeting(10,12));
    meetings.push_back(Meeting(4,8));
    meetings.push_back(Meeting(3,5));
    meetings.push_back(Meeting(0,1));




    vector<Meeting> sortedMeetings(meetings);
    sort(sortedMeetings.begin(), sortedMeetings.end(), compareStart);

    vector<Meeting> mergedMeetings;
    mergedMeetings.push_back(sortedMeetings.front());
    for (const Meeting& currentMeeting : sortedMeetings){
        cout << "current: " << currentMeeting.start << "," << currentMeeting.end << "\n";
        Meeting &lastMergedMeeting = mergedMeetings.back();
        cout << "lastMergedMeeting: " << lastMergedMeeting.start << "," << lastMergedMeeting.end << "\n";
        if (currentMeeting.start <= lastMergedMeeting.end){
            lastMergedMeeting.end = currentMeeting.end > lastMergedMeeting.end ? currentMeeting.end : lastMergedMeeting.end;
        }
        else {
            mergedMeetings.push_back(currentMeeting);
        }
    }

    for (const Meeting& meeting : mergedMeetings){
        cout << meeting.start << "," << meeting.end << "\n";
    }
}
