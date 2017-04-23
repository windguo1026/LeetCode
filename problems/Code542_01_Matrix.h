#pragma once
#include "../common/Common.h"

// 03/28
// https://leetcode.com/problems/01-matrix/#/description

namespace Code542
{
class Solution
{
public:
	static void testMain()
	{
		vector<vector<int>> matrix = 
		//{
		//	{0, 1},
		//	{1, 1}
		//};
		{
			{0, 0, 0},
			{0, 1, 0},
			{1, 1, 1}
		};

		cout << "old marix:\n"
			<< LeetHelper::vec2str(matrix, '\n') << "\n";

		Solution so;
		vector<vector<int>> newMatrix = so.updateMatrix(matrix);

		cout << "new marix:\n"
			 << LeetHelper::vec2str(newMatrix, '\n') << "\n";
	}

public:
	struct Position
	{
		int x;
		int y;
		Position() : x(0), y(0) {}
		Position(int _x, int _y) : x(_x), y(_y) {};
	};

	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix)
	{
		if (matrix.empty()) return matrix;

		// 1 表示未计算, 0 已经计算
		vector<vector<int>> iscalc = matrix;

		int maxRow = matrix.size() - 1;
		int maxCol = matrix[0].size() - 1;

		// 把0的周边的都放进去遍历
		queue<Position> qe;
		for (int i = 0; i <= maxRow; ++ i)
		{
			for (int j = 0; j <= maxCol; ++ j)
			{
				if (matrix[i][j] != 0) continue;
				checkPushAdjacents(qe, iscalc, matrix, i, j, maxRow, maxCol);
			}
		}

		while (!qe.empty())
		{
			Position cur = qe.front();
			qe.pop();

			checkPushAdjacents(qe, iscalc, matrix, cur.x, cur.y, maxRow, maxCol);
		}

		return matrix;
	}

private:
	void checkPushAdjacents(queue<Position>& qe, vector<vector<int>>& iscalc,
							vector<vector<int>>& matrix, int x, int y,
							int maxX, int maxY)
	{
		int val = matrix[x][y];
		tryPush(qe, iscalc, matrix, x - 1, y, val, maxX, maxY);
		tryPush(qe, iscalc, matrix, x + 1, y, val, maxX, maxY);
		tryPush(qe, iscalc, matrix, x, y - 1, val, maxX, maxY);
		tryPush(qe, iscalc, matrix, x, y + 1, val, maxX, maxY);
	}

	void tryPush(queue<Position>& qe, vector<vector<int>>& iscalc,
				 vector<vector<int>>& matrix, int x, int y, int val,
				 int maxX, int maxY)
	{
		if (isValid(x, y, maxX, maxY) && iscalc[x][y] == 1)
		{
			matrix[x][y] = val + 1;
			iscalc[x][y] = 0;	// 0 表示已经计算
			qe.emplace(x, y);
		}
	}

	inline bool isValid(int x, int y, int maxX, int maxY)
	{
		return x >= 0 && x <= maxX && y >= 0 && y <= maxY;
	}
};
}