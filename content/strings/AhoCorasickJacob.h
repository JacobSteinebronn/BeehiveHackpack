#pragma once
/**
 * Author: Jacob Steinebronn
 * License: CC0
 * Source: the mind of jacob
 * Description: Aho-Corasick
 * Status: untested
 */
struct node {
    int id, slink = 0, here = 1e8;
    vector<node*> next;
    node(int i): id(i), next(26, nullptr) {}
};
vector<node*> nodes;

node* insert(node* n, string &s, int i = 0) {
    if(i == s.size()) return n;
    int c = s[i] - 'a';
    if(!n->next[c]) nodes.push_back(n->next[c] = new node(nodes.size()));
    return insert(n->next[c], s, i+1);
} 

vector<node*> bfs() {
    vector<node*> qq;
    for(auto rc : root->next) if(rc) qq.push_back(rc);
    for(int c = 0; c < 26; c++) if(!root->next[c]) root->next[c] = root;
    int qi = 0;
    while(qi < qq.size()) {
        auto cur = qq[qi++];
        for(int c = 0; c < 26; c++) {
            node *&ch = cur->next[c], *nxt = nodes[cur->slink]->next[c];
            if(!ch) ch = nxt;
            else ch->slink = nxt->id, qq.push_back(ch);
        }
    }
    return qq;
}