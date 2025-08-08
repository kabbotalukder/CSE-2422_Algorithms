#include<bits/stdc++.h>
using namespace std;

int activitySelection(vector<int> &start, vector<int> &end) {
    int n = start.size();
    
    vector<pair<int, int>> activities;
    for(int i = 0; i < n; i++) {
        activities.push_back({end[i], start[i]});
    }

    sort(activities.begin(), activities.end());

    int count = 1;
    int lastEnd = activities[0].first;

    for(int i = 1; i < n; i++) {
        if(activities[i].second >= lastEnd) {
            count++;
            lastEnd = activities[i].first;
        }
    }
    return count;
}

int main(){
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end   = {2, 4, 6, 7, 9, 9};

    cout << activitySelection(start, end) << endl;

    return 0;
}
