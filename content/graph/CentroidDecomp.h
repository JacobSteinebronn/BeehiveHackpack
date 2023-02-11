/**
 * Author: Andy Phan
 * Date: 2023-02-11
 * Description: Computes centroid decomposition on connected tree, and runs callback function
 * Usage: centroidDecomp(adj, [&] (int root, vector<bool>& isIn) { ... });
	all nodes with isIn[i] = true connected to root are part of root's centroid
 * Time: $O(n \log n)$
 * Status: Untested
 */    
template<class G, class F>
void centroidDecomp(G g, F f) {
    vector<int> s(sz(g), 1), par(sz(g));
    auto go = [&] (int u, int p, auto& go) -> void {
        if ((par[u] = p) != -1) g[u].erase(find(all(g[u]), p));
        for (int v : g[u]) go(v, u, go), s[u] += s[v];
    };
    go(0, -1, go);
    vector<bool> is(sz(g), true);
    queue<int> q({0});
    while (sz(q)) {
        int x = q.front(), c, b = x; q.pop();
        do for(int v : g[c = b]) if(s[v] > s[x]/2) b = v;
        while(c != b);
        f(c, is); is[c] = false;
        int ss = s[c];
        for (int v : g[c]) if (s[v] > 0) q.push(v);
        if (c != x) q.push(x);
        do s[c] -= ss; while ((c = par[c]) != par[x]);
    }
}
