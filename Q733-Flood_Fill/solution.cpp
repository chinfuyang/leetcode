#include <vector>
#include <queue>

class Solution {
public:
	std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int color) {
		int height = image.size(), wight = image[0].size();
		std::queue<std::pair<int, int>> st;

		st.push({ sr, sc });
		int origin_color = image[sr][sc];
		while (!st.empty()) {
			auto front = st.front();
			st.pop();
			image[front.first][front.second] = color;

			if (is_same_color(image, front.first + 1, front.second, origin_color, color))
				st.push({ front.first + 1, front.second });

			if (is_same_color(image, front.first - 1, front.second, origin_color, color))
				st.push({ front.first - 1, front.second });

			if (is_same_color(image, front.first, front.second + 1, origin_color, color))
				st.push({ front.first, front.second + 1 });

			if (is_same_color(image, front.first, front.second - 1, origin_color, color))
				st.push({ front.first, front.second - 1 });
		}

		return image;
	}

	bool is_same_color(std::vector<std::vector<int>>& image, int row, int col, int source_colr, int target_color)
	{
		if (row < 0 || col < 0) return false;
		if (row >= image.size() || col >= image[0].size()) return false;
		if (source_colr == target_color) return false;

		return image[row][col] == source_colr;
	}

	std::vector<std::vector<int>> floodFill2(std::vector<std::vector<int>>& image, int sr, int sc, int color) {
		dfs(image, sr, sc, image[sr][sc], color);
		return image;
	}

	void dfs(std::vector<std::vector<int>> &image, int row, int col, int origin_color, int new_color) {
		if (row < 0 || col < 0 || row >= image.size() || col >= image[0].size() || origin_color == new_color || image[row][col] != origin_color) {
			return;
		}
		image[row][col] = new_color;

		dfs(image, row + 1, col, origin_color, new_color);
		dfs(image, row - 1, col, origin_color, new_color);
		dfs(image, row, col + 1, origin_color, new_color);
		dfs(image, row, col - 1, origin_color, new_color);
	}
};