#include <bits/stdc++.h>
using namespace std;

string itoa(int k) {
    ostringstream out;
    out << k;
    return out.str();
}

struct Tree {
    Tree(){
        left = right = NULL;
        curr = -1;
    }
    Tree(int k) {
        left = right = NULL;
        curr = k;
    }
    Tree *left;
    Tree *right;
    int curr;
    void add(int k) {
        if(curr == -1)
            curr = k;
        else if(k < curr) {
            if(left == NULL)
                left = new Tree(k);
            else
                left->add(k);
        }
        else if(k > curr) {
            if(right == NULL)
                right = new Tree(k);
            else
                right->add(k);
        }
    }
    void preOrderTraverse(string &s) {
        if(curr == -1)
            return;
        if(s != "") {
            s += ',';
        }
        s += itoa(curr);
        if(left != NULL)
            left->preOrderTraverse(s);
        if(right != NULL)
            right->preOrderTraverse(s);
    }
};

int main() {
    int n,k,a;
    cin >> n >> k;
    set<string> uniques;
    for(int i=0;i<n;i++) {
        Tree tree;
        map<int,int> m;
        vector<int> v(k);
        for(int j=0;j<k;j++) {
            cin >> v[j];
        }
        vector<int> vv(v.begin(),v.end());
        sort(vv.begin(),vv.end());
        for(int j = 0; j < k;j++) {
            m[vv[j]] = j;
        }
        for(int j=0;j<k;j++) {
            tree.add(m[v[j]]);
        }
        string s;
        tree.preOrderTraverse(s);
        uniques.insert(s);
    }
    cout << uniques.size() << endl;
    return 0;
}