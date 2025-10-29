/*
1x1 크기의 칸들로 이루어진 직사각형 격자 형태의 미로에서 탈출하려고 한다. 
각 칸은 통로 또는 벽으로 구성되어 있으며, 벽으로 된 칸은 지나갈 수 없고 통로로 된 칸으로만 이동할 수 있다.
통로들 중 한칸에는 미로를 빠져나가는 문이 있는데, 이문은 레버를 당겨서만 열 수 있다.
레버 또한 통로들 중 한 칸에 있다. 
따라서, 출발 지점에서 먼저 레버가 있는 칸으로 이동하여 레버를 당긴 후 미로를 빠져나가는 문이 있는 칸으로 이동하면 된다.
이때 아직 레버를 당기지 않았더라도 출구가 있는 칸을 지나갈 수 있다.
미로에서 한 칸을 이동하는데 1초가 걸린다고 할때, 최대한 빠르게 미로를 빠져나가는데 걸리는 시간을 구하려 한다.

미로를 나타낸 문자열 배열 maps가 매개변수로 주어질 때, 미로를 탈출하는데 필요한 최소 시간을 return 하는 solution 함수를 완성하라.

제한 사항
- 5 ≤ maps의 길이 ≤ 100
    - 5 ≤ maps[i]의 길이 ≤ 100
    - maps[i]는 다음 5개의 문자들로만 이루어져 있다.
        - S : 출발 지점
        - E : 출구
        - L : 레버        
        - O : 통로
        - X : 벽
    - 시작 지점과 출구, 레버는 항상 다른 곳에 존재하며 한 개씩만 존재한다.
    - 출구는 레버가 당겨지지 않아도 지나갈 수 있으며, 모든 통로, 출구, 레버, 시작점은 여러번 지나갈 수 있다.

입출력 예: 
    maps                                        result
    {"SOOOL","XXXXO","OOOOO","OXXXXX","OOOOE"}  16
    {"LOOXS","OOOOX","OOOOO","OOOOO","EOOOO"}   -1
*/
#pragma once
#include <iostream>
#include <vector>
#include <queue>
namespace escape_maze_159993{
    struct Point{
        int x;
        int y;
        bool visited;
    };

    Point findStartPoint(std::vector<std::string> &maps){
        for(int i = 0;i<maps.size();i++){
            for(int j = 0;j<maps[i].size();j++){
                std::cout << maps[i][j];
            }
            std::cout << "\n";
        }
        return {3,5,false};
    }

    void bfs(Point start, Point end, std::vector<std::string> &maps){
        std::queue<Point> q;
    }

    int solution(std::vector<std::string>maps){
        findStartPoint(maps);
        return 1;
    }
}
