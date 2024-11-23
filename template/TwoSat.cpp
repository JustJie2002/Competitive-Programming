
// Reminder: Add SCC template
// Credit: neal wu
struct TwoSat {
    int n = 0;
    vector<vector<int>> adj;
    vector<bool> assignment;
    SCC scc;

    int inv(int var) {
        return var ^ 1;
    }

    int new_var() {
        adj.emplace_back();
        adj.emplace_back();
        return 2 * n++;
    }

    void implies(int a, int b) {
        adj[a].push_back(b);
        adj[inv(b)].push_back(inv(a));
    }

    void either(int a, int b) {
        adj[inv(a)].push_back(b);
        adj[inv(b)].push_back(a);
    }

    void set_value(int a) {
        adj[inv(a)].push_back(a);
    }

    void equal(int a, int b) {
        implies(a, b);
        implies(inv(a), inv(b));
    }

    void unequal(int a, int b) {
        implies(a, inv(b));
        implies(inv(a), b);
    }

    // Warning: this only creates an implication in the negative direction. It is still possible for
    // a = b = true with and_var = false. In particular, it does not work to call set_value on inv(and_var).
    int create_and(int a, int b) {
        if (a < 0 || b < 0) return max(a, b);
        int result = new_var();
        implies(result, a);
        implies(result, b);
        return result;
    }

    // Warning: this only creates an implication in the positive direction. It is still possible for
    // a = b = false with or_var = true. In particular, it does not work to call set_value on or_var.
    int create_or(int a, int b) {
        if (a < 0 || b < 0) return max(a, b);
        int result = new_var();
        implies(a, result);
        implies(b, result);
        return result;
    }

    int create_at_most_one(int a, int b) {
        if (a < 0 || b < 0) return max(a, b);
        either(inv(a), inv(b));
        return create_or(a, b);
    }

    template<typename T_iterable>
    int create_at_most_one(const T_iterable &vars) {
        int aux = -1;

        for (int var : vars)
            aux = create_at_most_one(aux, var);

        return aux;
    }

    bool solve() {
        scc.init(adj);
        scc.build();

        for (int i = 0; i < n; i++)
            if (scc.which_component[2 * i] == scc.which_component[2 * i + 1])
                return false;

        assignment.resize(2 * n);
        vector<bool> done(n, false);

        // Tarjan's algorithm provides the SCCs in reverse topological order.
        for (auto &component : scc.components)
            for (int x : component) {
                assignment[x] = !done[x / 2];
                done[x / 2] = true;
            }

        for (int i = 0; i < n; i++)
            assert(assignment[2 * i] ^ assignment[2 * i + 1]);

        return true;
    }
};
