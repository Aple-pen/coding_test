#pragma once
/*깊이 우선 탐색으로 모든 그래프의 노드를 순회하는 함수 solution을 작성하라
  시작 노드는 문자형 start로 주어진다. graph 배열은 [출발노드, 도착노드] 쌍들이 들어있는 배열이다.
  반환값은 그래프의 시작 노드부터 모든 노드를 깊이 우선 탐색으로 탐색한 경로가 순서대로 저장된 배열이다.

  제약 조건 :
    - 노드의 최대 개수는 100개를 넘지 않는다.
    - 시작 노드부터 시작해서 모든 노드를 방문할 수 있는 경로가 항상 있다.
    - 그래프의 각 노드는 대문자 알파벳 문자이다.

  입출력 예 : 
    - graph                                                         start   result
    - [['A','B'],['B','C'],['C','D'],['D','E']]                     'A'     ['A','B','C','D','E']
    - [['A','B'],['A','C'],['B','D'],['B','E'],['C','F'],['E','F']] 'A'     ['A','B','D','E','F','C']
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<char,vector<char>> adjList;
vector<char> result;
unordered_set<char> visited;

//길이 우선 탐색
void dfs(char node){
  // 현재 노드를 방문한 목록과 방문한 경로에 추가
  visited.insert(node);
  result.push_back(node);

  for(char neighbor : adjList[node]){
    // 해당 노드가 가리키는 노드들을 갔다 왔는지 확인.
    // 조건에 부합한다면 아직 다녀오지 않았기때문에 dfs를 재귀호출 한다.
    if(visited.find(neighbor) == visited.end()){
      dfs(neighbor);
    }
  }
}


vector<char> solution(vector<pair<char,char>> graph,char start){
  for(auto &edge : graph){
    char u = edge.first;
    char v = edge.second;
    adjList[u].push_back(v);
  }

  dfs(start);
  return result;
}