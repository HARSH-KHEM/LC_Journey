class Solution {
public:

    struct Node {
        int len;
        int pref;
        int suff;
        int best;
        char left;
        char right;

        Node() {
            len = pref = suff = best = 0;
            left = right = '#';
        }

        Node(char c) {
            len = pref = suff = best = 1;
            left = right = c;
        }
    };

    vector<Node> tree;

    Node merge(Node L, Node R) {

        Node res;

        res.len = L.len + R.len;
        res.left = L.left;
        res.right = R.right;

        // Prefix
        res.pref = L.pref;

        if (L.pref == L.len && L.right == R.left) {
            res.pref = L.len + R.pref;
        }

        // Suffix
        res.suff = R.suff;

        if (R.suff == R.len && L.right == R.left) {
            res.suff = R.len + L.suff;
        }

        // Best
        res.best = max(L.best, R.best);

        if (L.right == R.left) {
            res.best = max(res.best, L.suff + R.pref);
        }

        return res;
    }

    void build(int node, int l, int r, string &s) {

        if (l == r) {
            tree[node] = Node(s[l]);
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid, s);
        build(node * 2 + 1, mid + 1, r, s);

        tree[node] = merge(tree[node * 2],
                           tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, char c) {

        if (l == r) {
            tree[node] = Node(c);
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid) {
            update(node * 2, l, mid, idx, c);
        }
        else {
            update(node * 2 + 1, mid + 1, r, idx, c);
        }

        tree[node] = merge(tree[node * 2],
                           tree[node * 2 + 1]);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        int n = s.size();

        tree.resize(4 * n);

        build(1, 0, n - 1, s);

        vector<int> ans;

        for (int i = 0; i < queryCharacters.size(); i++) {

            update(
                1,
                0,
                n - 1,
                queryIndices[i],
                queryCharacters[i]
            );

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};