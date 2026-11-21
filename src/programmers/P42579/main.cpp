#include <iostream>

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string, int> count_genres;

class Song {
public:
    int id;
    string genre;
    int plays;

    Song(int id, string genre, int plays) : id(id), genre(genre), plays(plays) {}
};

bool compare(Song a, Song b) {
    if(count_genres[a.genre] == count_genres[b.genre]) {
        if(a.plays == b.plays) {
            return a.id < b.id;
        }

        return a.plays > b.plays;
    }

    return count_genres[a.genre] > count_genres[b.genre];
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<Song> songs;

    // 각 장르 당 2곡이 최대가 하도록 하는 unoredered_map
    unordered_map<string, int> maxTwo;

    for(int i=0; i<plays.size(); i++) {
        songs.push_back({i, genres[i], plays[i]});
        count_genres[genres[i]] += plays[i];
        maxTwo[genres[i]] = 2;
    }
    
    sort(songs.begin(), songs.end(), compare);

    vector<int> result;

    for(Song s : songs) {
        // cout << s.id << ' ' << s.genre << ' ' << s.plays << '\n';
        if(maxTwo[s.genre]) {
            result.push_back(s.id);
            maxTwo[s.genre]--;
        }
    }

    return result;
}

template <typename T>
bool check(const pair<T, T> &p) {
    return p.first == p.second;
}

template <typename T>
void printCheck(const vector<pair<T, T>> &v) {
    for (int i = 0; i < (int)v.size(); i++) {
        cout << "testcase " << i + 1 << ": ";
        cout << (check(v[i]) ? "정답!\n" : "오답!\n");
    }
}

int main() {
    vector<pair<vector<int>, vector<int>>> testcase = {
        {solution({"classic", "pop", "classic", "classic", "pop"}, {500, 600, 150, 800, 2500}), {4,1,3,0}},
        {solution({"classic", "classic", "classic", "classic", "classic"}, {500, 600, 150, 800, 2500}), {4,3}}

    };

    printCheck(testcase);
}
