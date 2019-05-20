#include<iostream>
#include<vector>

bool hasPathCore(std::string& matric, int rows, int cols, int row, int col, std::string& str, int& pathLength, std::vector<bool>& visited)
{
	if (str[pathLength] == '\0')
		return true;
	bool hashPath = false;
	if (row >= 0 && row < rows && col >= 0 && col < cols && matric[row*cols + col] == str[pathLength] && !visited[row*cols + col])
	{
		++pathLength;
		visited[row*cols + col] = true;

		hashPath = hasPathCore(matric, rows, cols, row, col - 1, str, pathLength, visited)
			|| hasPathCore(matric, rows, cols, row - 1, col, str, pathLength, visited)
			|| hasPathCore(matric, rows, cols, row, col + 1, str, pathLength, visited)
			|| hasPathCore(matric, rows, cols, row + 1, col, str, pathLength, visited);
		if (!hashPath)
		{
			--pathLength;
			visited[row*cols + col] = false;
		}
	}
	return hasPath;
}

bool hasPath(std::string& matrix, int rows, int cols, std::string& str)
{
	if (matrix.empty() || rows < 1 || cols < 1 || str.empty())
		return false;

	std::vector<bool> visited;
	visited.resize(rows*cols);

	int pathLength = 0;
	for (int row = 0; row < rows; ++row)
	{
		for (int col = 0; col < cols; ++col)
		{
			if (hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited))
				return true;
		}
	}
	return false;
}
