class Solution {
  bool wordExist(int i, int j, int currentIndex, vector<vector<char>> &board,
                 string &word) {
    if (currentIndex == word.size()) {
      return true;
    }
    if (i < 0 || i == board.size() || j < 0 || j == board[0].size() ||
        board[i][j] == '.') {
      return false;
    }
    bool exist = false;
    if (board[i][j] == word[currentIndex]) {
      char prevChar = board[i][j];
      board[i][j] = '.';
      currentIndex++;
      exist = wordExist(i + 1, j, currentIndex, board, word) ||
              wordExist(i, j + 1, currentIndex, board, word) ||
              wordExist(i, j - 1, currentIndex, board, word) ||
              wordExist(i - 1, j, currentIndex, board, word);
      board[i][j] = prevChar;
    }
    return exist;
  }

public:
  bool exist(vector<vector<char>> &board, string word) {
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if (wordExist(i, j, 0, board, word)) {
          return true;
        }
      }
    }
    return false;
  }
};
