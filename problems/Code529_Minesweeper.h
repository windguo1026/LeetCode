#pragma once
#include "../common/Common.h"

// 03/27
// https://leetcode.com/problems/minesweeper/#/description

namespace Code529
{
class Solution
{
public:
	static void testMain()
	{
		vector<vector<char>> board = 
		{ 
			{ 'E', 'E', 'E', 'E', 'E' },
			{ 'E', 'E', 'M', 'E', 'E' },
			{ 'E', 'E', 'E', 'E', 'E' },
			{ 'E', 'E', 'E', 'E', 'E' } 
		};

		//{ 
		//	{ 'B', '1', 'E', '1', 'B' },
		//	{ 'B', '1', 'M', '1', 'B' },
		//	{ 'B', '1', '1', '1', 'B' },
		//	{ 'B', 'B', 'B', 'B', 'B' }
		//};

		cout << "before click\n"
			<< LeetHelper::vec2str(board, '\n') << "\n";

		Solution so;
		vector<int> click = {3, 0};
		vector<vector<char>> newBoard = so.updateBoard(board, click);

		cout << "after click [" << click[0] << ", " << click[1] << "]\n"
			 << LeetHelper::vec2str(newBoard, '\n') << "\n";
	}

public:
	struct Position
	{
		int x;
		int y;
		Position(): x(0), y(0) { }
		Position(int _x, int _y): x(_x), y(_y) {}
	};

	vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click)
	{
		// 看是否是雷
		if (board[click[0]][click[1]] == 'M')
		{
			board[click[0]][click[1]] = 'X';
			return board;
		}

		// 0 未点，1 已点 2 在堆栈中
		vector<vector<char>> status(board.size(), vector<char>(board[0].size(), 0));
		initStatus(status, board);

		stack<Position> st;
		st.push(Position(click[0], click[1]));
		Position maxPos(board.size() - 1, board[0].size() - 1);

		while (!st.empty())
		{
			Position curPos = st.top();
			st.pop();

			vector<Position> adjPos;
			adjPos.reserve(8);

			getAdjacentPos(adjPos, curPos.x, curPos.y, maxPos.x, maxPos.y);
			int mineCnt = calcMinesCnt(board, adjPos);

			board[curPos.x][curPos.y] = mineCnt ? ('0' + mineCnt) : 'B';
			status[curPos.x][curPos.y] = 1; // 已经点了

			if (mineCnt > 0) continue;

			for (Position& pos : adjPos)
			{
				if (status[pos.x][pos.y] == 0)
				{
					st.push(pos);
					status[pos.x][pos.y] == 2;
				}
			}
		}

 		return board;
	}

private:
	void initStatus(vector<vector<char>>& status, const vector<vector<char>>& board)
	{
		for (int i = 0; i < board.size(); ++i)
		{
			const vector<char>& row = board[i];
			for (int j = 0; j < row.size(); ++j)
			{
				if (row[j] != 'M' && row[j] != 'E')
					status[i][j] = 1;
			}
		}
	}

	int calcMinesCnt(const vector<vector<char>>& board, const vector<Position>& adjPos)
	{
		int cnt = 0;
		for (const Position& pos : adjPos)
		{
			if (board[pos.x][pos.y] == 'M') ++ cnt;
		}
		return cnt;
	}

	void getAdjacentPos(vector<Position>& adjPos, int x, int y, int maxX, int maxY)
	{
		if (isPosValid(x - 1, y - 1, maxX, maxY)) adjPos.push_back(Position(x-1, y-1));
		if (isPosValid(x - 1, y, maxX, maxY)) adjPos.push_back(Position(x - 1, y));
		if (isPosValid(x - 1, y + 1, maxX, maxY)) adjPos.push_back(Position(x - 1, y + 1));
		if (isPosValid(x, y - 1, maxX, maxY)) adjPos.push_back(Position(x, y - 1));
		if (isPosValid(x, y + 1, maxX, maxY)) adjPos.push_back(Position(x, y + 1));
		if (isPosValid(x + 1, y - 1, maxX, maxY)) adjPos.push_back(Position(x + 1, y - 1));
		if (isPosValid(x + 1, y, maxX, maxY)) adjPos.push_back(Position(x + 1, y));
		if (isPosValid(x + 1, y + 1, maxX, maxY)) adjPos.push_back(Position(x + 1, y + 1));
	}

	inline bool isPosValid(int x, int y, int maxX, int maxY)
	{
		return (x >= 0) && (x <= maxX) &&
			   (y >= 0) && (y <= maxY);
	}
};
}