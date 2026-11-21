## 문제
[42579 베스트앨범](https://school.programmers.co.kr/learn/courses/30/lessons/42579)

## 풀이

### 풀이에 대한 직관적인 설명
1. 노래마다 고유 번호(id), 장르, 재생 수를 같이 들고 다녀야 하므로 이 셋을 가지는 Song 클래스를 만들었습니다.

2. 노래를 하나씩 Song으로 만들어 담으면서, 장르별 총 재생 수를 count_genres에 더해둡니다.

   이때 장르마다 최대 2곡만 고를 수 있으므로, maxTwo에 장르를 키로 해서 남은 곡 수 2를 같이 저장해 둡니다.

3. 문제에서 요구한 순서대로 노래를 정렬합니다.

   * 장르의 총 재생 수가 많은 장르가 먼저

   * 같은 장르 안에서는 재생 수가 많은 노래가 먼저

   * 재생 수도 같다면 고유 번호가 낮은 노래가 먼저

4. 정렬된 노래를 앞에서부터 하나씩 보면서, 그 장르의 maxTwo가 남아있다면 id를 결과에 넣고 maxTwo를 1 줄입니다.

5. 끝까지 순회하면 결과에는 장르별로 최대 2곡씩, 요구한 순서대로 id가 담겨 있습니다.

### 풀이 도출 과정
1. 장르 순서, 장르 안의 순서, 같은 재생 수일 때의 순서가 모두 정해져 있기 때문에, 비교 함수 하나로 정렬하면 한 번에 해결된다고 생각했습니다.

2. 비교할 때마다 장르의 총 재생 수가 필요한데, 매번 전체를 훑어서 구하면 정렬 중에 너무 오래 걸립니다.

   그래서 장르별 총 재생 수를 미리 해시맵에 저장해 두고 비교 함수에서 바로 꺼내 썼습니다.

3. 장르별 총 재생 수는 모두 다르다는 조건이 있기 때문에, 총 재생 수가 같은 두 노래는 반드시 같은 장르입니다.

   덕분에 정렬하면 같은 장르의 노래끼리 붙어서 나오고, 장르를 따로 나누는 과정이 필요 없습니다.

4. 장르마다 2곡만 고르는 것은 정렬 후에 한 번 순회하면서 장르별 남은 개수(maxTwo)를 줄여가며 처리했습니다.

   정렬되어 있으므로 먼저 만나는 2곡이 곧 그 장르에서 가장 많이 재생된 2곡입니다.

5. 장르에 노래가 한 곡뿐이라면 한 곡만 고르면 되는데, 순회하면서 만나는 곡만 담기 때문에 별도의 처리가 필요 없습니다.

## 복잡도

* 시간복잡도 : O(N log N)

    * 장르별 총 재생 수를 구하는 데 O(N)

    * 노래를 정렬하는 데 O(N log N)

    * 정렬된 노래를 한 번 순회하며 고르는 데 O(N)

    * 따라서 시간복잡도는 O(N log N) 입니다.

### 사용한 언어
C++

### 사용한 소스코드
```cpp
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
```
