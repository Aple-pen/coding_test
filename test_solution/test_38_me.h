#pragma once
/*
  주어진 그래프와 시작 노드를 이용하여 다익스트라 알고리즘을 구현하는 solution() 함수를 작성하라.
  시작 노드 start, 노드의 개수 numNodes,[시작노드,도착노드,가중치] 형태로 간선 정보를 담은 배열 edge가 인수로 주어진다.
  edges에 [2,1,9]가 있다면 시작노드2에서 도착노드1까지 가중치가 9인 간선이 있다는 뜻이다.
  시작노드 start부터 각 노드까지 최소 비용을 담은 벡터를 반환하는 solution() 함수를 구현하자.

  제약조건 :
    - 그래프의 노드 개수는 최대 10,000개이다.
    - 각 노드는 0 이상의 정수로 표현한다.
    - 모든 가중치는 0 이상의 정수이며 10,000을 넘지 않는다.

  입출력 예 :
  start       numNodes      edges               result
  0           3             [[0,1,9],[0,2,3],   [0,4,3]
                              [1,0,5],[2,1,1]]
  0           4             [[0,1,1],[1,2,5],   [0,1,6,7]
                                  [2,3,1]]
*/

#include <climits>
#include <cmath>
#include <iostream>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

using namespace std;
vector<int> solution(int start, int numNodes, vector<tuple<int, int, int>> edges) {
    unordered_map<int, vector<pair<int, int>>> adjList;
    unordered_set<int>                         willVisit;
    vector<int>                                result(numNodes,INT_MAX);
    // unordered_map<int, int> min_vertax_struct;  // 만약 경로까지 나타내야한다면 <int,pair<int,int>>로 하는게 맞을듯?
    
    // adjList 생성
    for (auto &edge : edges) {
        adjList[std::get<0>(edge)].push_back(make_pair(std::get<1>(edge), std::get<2>(edge)));
        willVisit.insert(std::get<0>(edge));
    }
    int nextNode                = start;
    result[nextNode] = 0;
    for (int i = 0; i < numNodes; ++i) {
        willVisit.erase(nextNode);  // 갈곳을 지운다.
        for (int j = 0; j < adjList[nextNode].size(); j++) {
            if(result[nextNode] + adjList[nextNode][j].second < result[adjList[nextNode][j].first])
              result[adjList[nextNode][j].first] = result[nextNode] + adjList[nextNode][j].second;
        }
        int minValue = INT_MAX;
        for (auto wv : willVisit) {
            if (result[wv] < minValue) {
                minValue = result[wv];
                nextNode = wv;
            }
        }              
    }
    
    return result;
}
