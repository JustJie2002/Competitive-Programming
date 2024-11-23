/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 09.07.2024 02:22:00
*********************************************/

using i64 = long long;
using Info = pair<int, bool>;

constexpr int BOARD_SIZE = 4;

string work(const vector<string>& operations) {
    vector board(BOARD_SIZE, vector<int>(BOARD_SIZE));

    const auto perform_move = [&](string direction) -> void {
        if (direction == "L") {
            for (int r = 0; r < BOARD_SIZE; r++) {
                vector<Info> stack;
                for (int c = 0; c < BOARD_SIZE; c++) {
                    int x = board[r][c];
                    if (x == 0) {
                        continue;
                    }
                    if (stack.size() && stack.back().first == x && stack.back().second) {
                        stack.back().first *= 2;
                        stack.back().second = false;
                    } else {
                        stack.emplace_back(x, true);
                    }
                }

                int cnt = stack.size();
                for (int c = 0; c < BOARD_SIZE; c++) {
                    if (c < stack.size()) {
                        const auto& [res, _] = stack[c];
                        board[r][c] = res;
                    }
                }
            }
        } else if (direction == "R") {
            for (int r = 0; r < BOARD_SIZE; r++) {
                vector<Info> stack;
                for (int c = BOARD_SIZE - 1; c >= 0; c--) {
                    int x = board[r][c];
                    if (x == 0) {
                        continue;
                    }
                    if (stack.size() && stack.back().first == x && stack.back().second) {
                        stack.back().first *= 2;
                        stack.back().second = false;
                    } else {
                        stack.emplace_back(x, true);
                    }
                }

                int cnt = stack.size();
                for (int c = 0; c < BOARD_SIZE; c++) {
                    if (c < stack.size()) {
                        const auto& [res, _] = stack[c];
                        board[r][BOARD_SIZE - c - 1] = res;
                    }
                }
            }
        } else if (direction == "U") {
            for (int c = 0; c < BOARD_SIZE; c++) {
                vector<Info> stack;
                for (int r = 0; r < BOARD_SIZE; r++) {
                    int x = board[r][c];
                    if (x == 0) {
                        continue;
                    }
                    if (stack.size() && stack.back().first == x && stack.back().second) {
                        stack.back().first *= 2;
                        stack.back().second = false;
                    } else {
                        stack.emplace_back(x, true);
                    }
                }

                int cnt = stack.size();
                for (int r = 0; r < BOARD_SIZE; r++) {
                    if (r < stack.size()) {
                        const auto& [res, _] = stack[r];
                        board[r][c] = res;
                    }
                }
            }
        } else if (direction == "D") {
            for (int c = 0; c < BOARD_SIZE; c++) {
                vector<Info> stack;
                for (int r = BOARD_SIZE - 1; r >= 0; r--) {
                    int x = board[r][c];
                    if (x == 0) {
                        continue;
                    }
                    if (stack.size() && stack.back().first == x && stack.back().second) {
                        stack.back().first *= 2;
                        stack.back().second = false;
                    } else {
                        stack.emplace_back(x, true);
                    }
                }

                int cnt = stack.size();
                for (int r = 0; r < BOARD_SIZE; r++) {
                    if (r < stack.size()) {
                        const auto& [res, _] = stack[r];
                        board[BOARD_SIZE - r - 1][c] = res;
                    }
                }
            }
        } else assert(false);
    };

    for (const auto& operation : operations) {
        auto args = views::split(word, {" "});
        string direction = args[0];
        int r = stoi(args[1]);
        int c = stoi(args[2]);
        int val = stoi(args[3]);
        perform_move(direction);
        if (board[r][c] != 0) {
            return "Error";
        }
        board[r][c] = val;
    }

    string out;
    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            if (board[r][c] != 0) {
                out += to_string(board[r][c]);
            } else {
                out += ".";
            }
            out += ",\n"[c == BOARD_SIZE - 1];
        }
    }
    return out;
}

// ~ JustJie