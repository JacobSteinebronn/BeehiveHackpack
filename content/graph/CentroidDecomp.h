/**
 * Author: Andy Phan
 * Date: 2023-02-08
 * Description: Computes the depths in the centroid tree
 * Time: $O(n \log n)$
 * Status: Untested
 */    
	
vi depth(n, -1);
queue<pair<int, int>> q;
q.push({0, 0});
while (sz(q)) {
	auto [x, d] = q.front(); q.pop();
	int targ = subsize[x]/2, curr = x;
	vi pars;
	while (true) {
		bool found = false;
		for (int v : child[curr]) 
			if (depth[v] == -1 && subsize[v] > targ) {
				pars.push_back(curr);
				curr = v, found = true;
				break;
			}
		if (!found) break;
	}
	depth[curr] = d;
	for (int v : child[curr]) 
		if (depth[v] == -1) 
			q.push({v, d+1});
		
	if (curr != x) {
		q.push({x, d+1});
		for (int v : pars) subsize[v] -= subsize[curr];
	}
}