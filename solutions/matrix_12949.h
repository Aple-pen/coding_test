#pragma once
#include <vector>
using namespace std;

namespace matrix_12949 {
	vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
		int arr1_row = arr1.size(), arr1_col = arr1[0].size(), arr2_row = arr2.size(), arr2_col = arr2[0].size();
		vector<vector<int>> answer(arr1_row);
		for (int a1r = 0; a1r < arr1_row; a1r++) {
			int tmpData = 0;
			for (int a2c = 0; a2c < arr2_col; a2c++) {
				int tmpSum = 0;
				for (int a1c = 0; a1c < arr1_col; a1c++) {
					int mul = arr1[a1r][a1c] * arr2[a1c][a2c];
					tmpSum += mul;
					if (a1c == arr1_col - 1) {
						answer[a1r].push_back(tmpSum);
					}
				}
			}
		}
		return answer;
	}
}