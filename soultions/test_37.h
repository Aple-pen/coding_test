#pragma once
/*너비 우선 탐색으로 모든 노드를 순회하는 함수 solution()을 작성하라.
  시작 노드는 정수형 start로 주어진다.
  grapth 배열은 [출발 노드, 도착 노드] 쌍이 들어 있는 배열이다.
  반환 값은 그래프의 시작 노드로부터 모든 노드를 너비 우선 탐색한 경로가 순서대로 저장된 배열이다.


  제약 조건 :
    - 노드의 최대 개수는 100개를 넘지 않는다.
    - 시작 노드부터 시작해서 모든 노드를 방문할 수 있는 경로가 항상 있다.
    - 그래프의 각 노드는 숫자이다.

  입출력 예 : 
    - graph                                                         start   result
    - {{1,2},{1,3},{2,4},{2,5},{3,6},{3,7},{4,8},{5,8},{6,9},{7,9}}  1      {1,2,3,4,5,6,7,8,9}
    - {{0,1},{1,2},{2,3},{3,4},{4,5},{5,0}}                          1      {1,2,3,4,5,0}
*/


#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

unordered_map<int, vector<int>> adjList;
vector<int> result;
unordered_set<int> visited;

void bfs(int start){
  unordered_set<int> visited;
  queue<int> q;

  q.push(start);
  visited.insert(start);
  result.push_back(start);

  while(!q.empty()){
    int node = q.front();
    q.pop();

    for(int neighbor : adjList[node]){
      if(visited.find(neighbor) == visited.end()){
        q.push(neighbor);
        visited.insert(neighbor);
        result.push_back(neighbor);
      }
    }
  } 
}

vector<int> solution(vector<pair<int,int>> graph,int start){
  for (auto &edge : graph){
    auto f = edge.first;
    auto s = edge.second;
    adjList[f].push_back(s);
  }

  bfs(start);
  return result;
}