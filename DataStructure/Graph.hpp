#pragma once

#include <iostream>
#include <vector>

namespace Graph {
template<typename T>
struct nodeInfo {
    int32_t V;
    T W;
};
template<typename T = int32_t>
class ADJ_List {
   public:
    void resize(size_t N) { adjList.resize(N); }
    void addEdge(int32_t u, int32_t v, T w = 0) { adjList[u].push_back({v, w}); }
    void printAdjList() {
        for (size_t i = 0; i < adjList.size(); i++) {
            std::cout << "Node " << i << ":";
            for (const auto &node : adjList[i]) {
                std::cout << "-> (V:" << node.V << ", W:" << node.W << ")";
            }
            std::cout << std::endl;
        }
    }
   private:
    std::vector<std::vector<nodeInfo<T>>> adjList;
};
}  // namespace Graph
