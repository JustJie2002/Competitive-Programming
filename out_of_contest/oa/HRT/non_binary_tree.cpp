/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 09.07.2024 00:47:35
*********************************************/

using i64 = long long;

struct Tree {
    int key, val;
    vector<Tree*> neighbors;
    Tree() {}
};

Tree* construct(const vector<vector<int>>& args) {
    int argc = args.size();
    
    vector<bool> is_root(argc, true);
    vector<Tree*> trees(argc, new Tree());
    for (int which = 0; which < argc; which++) {
        trees[which]->key = args[which][0];
        trees[which]->val = args[which][1];
        int arg_count = args[which].size();
        for (int i = 2; i < arg_count; i++) {
            int nei = args[which][i];
            tree->children.push_back(trees[nei]);
            is_root[nei] = false;
        }
    }

    int root = ranges::find(is_root, true);
    return trees[root];
}

Tree* merge(Tree* cur_left, Tree* cur_right) {
    Tree* merged_tree = new Tree();
    merged_tree->key = cur_left->key;
    merged_tree->val = cur_right->val;
    auto& cur_children = merged_tree->children;

    auto& children_left = cur_left->children;
    int left_children_count = children_left.size();
    auto& children_right = cur_right->children;
    int right_children_count = children_right.size();

    unordered_map<int, int> seen;
    for (int i = 0; i < left_children_count; i++) {
        Tree* cur = children_left[i];
        seen[cur->key] = i;
        cur_children.push_back(cur);
    }
    for (int i = 0; i < right_children_count; i++) {
        Tree* cur = children_right[i];
        if (!seen.contains(cur->key)) {
            cur_children.push_back(cur);
        } else {
            int position = seen[cur->key];
            cur_children[position] = merge(cur_children[position], cur);
        }
    }
    return merged_tree;
}

vector<int> solve(vector<vector<int>>& L, vector<vector<int>>& R) {
    Tree* tree1 = construct(L);
    Tree* tree2 = construct(R);

    vector<int> answer;
    if (tree1->key != tree2->key) {
        return answer;
    }

    Tree* merged_tree = merge(tree1, tree2);

    const auto traverse = [&](auto&& self, Tree* tree) -> void {
        answer.push_back(tree->key);
        answer.push_back(tree->key);
        for (Tree* child : tree->children) {
            self(self, child);
        }
    };

    return answer;
}

// ~ JustJie