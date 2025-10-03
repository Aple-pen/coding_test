#pragma once
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
namespace _failRate_42889 {
	//실패율 = 스테이지에 도달했으나 아직 클리어하지 못한 플레이어의 수 / 스테이지에 도달한 플레이어 수
	// N : 전체 스테이지의 개수, 
	// stage : 게임을 이용하는 사용자가 현재 멈춰있는 스테이지의 번호가 담긴 배열.
	// 실패율이 높은 스테이지로부터 내림차순으로 스테이지의 번호를 리턴.

	vector<int> solution(int N, vector<int> stages) {
		std::unordered_map<int, int> stageStatus;
		std::multimap<float, int, greater<float>> failRateMap;
		std::vector<int> answer;
		for (auto s : stages)
			stageStatus[s] += 1;
		int currentPerson = 0;
		for (int i = 0; i < N; i++) {
			float failRate = static_cast<float>(stageStatus[i + 1]) / (stages.size() - currentPerson);
			failRateMap.insert({ failRate,i + 1 });
			currentPerson += stageStatus[i + 1];
		}
		for (auto& it : failRateMap)
			answer.push_back(it.second);

		return answer;
	}
}
