//https://leetcode.com/problems/similar-string-groups/
#include <bits/stdc++.h>
using namespace std;


// junk brute force Time limit eiceed
int brute_numSimilarGroups(vector<string>& strs) {
    int size = strs.size();
    vector<int> done(size,0);
    int c = 0;
    int f = 0;
    done[0] = 1;
    string curr_w,comp_w;
    int curr_w_len;
    for (int i = 0; i < size; ++i) {
        if(i != 0 && done[i] == 1) continue;

        for (int j = i+1; j < size; ++j) {
            if(done[j] == 1) continue;
             curr_w = strs[i];
             curr_w_len = (int)curr_w.length();
             comp_w = strs[j];
            if(curr_w == comp_w)
            {
                done[j] = 1;
                c++;
                continue;
            }

            for (int k = 0; k < curr_w_len; ++k) {
                for (int l = k+1; l < curr_w_len; ++l) {
                    swap(curr_w[k],curr_w[l]);
                    if(curr_w == comp_w)
                    {
                        done[j]  = 1;
                        f = 1;
                        c++;
                        break;
                    }
                    else
                    {
                        swap(curr_w[k],curr_w[l]);

                    }
                }
                if(f)
                {
                    f = 0;
                    break;
                }
            }
        }
    }

    return c;
}

int vst[304];

int check(string& first, string& second,int& len){
    vst[303] = 0;
    for(int i=0; i<len; i++)
        if(first[i] != second[i]) vst[303] += 1;

    return (vst[303] == 2 || vst[303] == 0);
}

void loop(int i, vector<string>& strs, int len)
{
    vst[i] = 1;
    for (int j = 0; j < vst[301]; ++j) {
        if(vst[j] == 1) continue;
        if(check(strs[i], strs[j],len))
            loop(j, strs,len);
    }
}
// dfs
int numSimilarGroups_s(vector<string>& strs) {
    int sze = (int)strs.size();
    memset(vst,0,sizeof(vst));

    vst[301] = sze;
    for (int i = 0; i < sze; ++i) {
        if(vst[i] == 1) continue;
        vst[302] += 1;
        loop(i,strs,(int)strs[i].length());
    }

    return vst[302];
}




class UnionFind {
public:
    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        count = n;
    }

    int find(int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    void unite(int i, int y) {
        int pi = find(i);
        int py = find(y);
        if (pi != py) {
            parent[pi] = py;
            count--;
        }
    }

    int getCount() {
        return count;
    }

private:
    vector<int> parent;
    int count;
};

bool isSimilar(string& s1, string& s2) {
    int diff = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) {
            diff++;
            if (diff > 2) {
                return false;
            }
        }
    }
    return true;
}

// union find, parent-> n
int numSimilarGroups_1(vector<string>& strs) {
    int n = strs.size();
    UnionFind uf(n);

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (isSimilar(strs[i], strs[j])) {
                uf.unite(i, j);
            }
        }
    }

    return uf.getCount();
}

int find(int i,vector<int>& pt) {
    if (pt[i] != i) {
        pt[i] = find(pt[i],pt);
    }
    return pt[i];
}

void unite(int i, int j,vector<int>& pt,int& c) {
    int pi = find(i,pt);
    int pj = find(j,pt);
    if (pi != pj) {
        pt[pi] = pj;
        c--;
    }
}
bool isSimilar_2(string& s1, string& s2) {
    if(s1 == s2) return true;
    int diff = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) {
            diff++;
            if (diff > 2) {
                return false;
            }
        }
    }

    return true;
}

// with vector
int numSimilarGroups(vector<string>& strs) {
    int n = strs.size();
    int c = n;

    vector<int> parent(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (isSimilar_2(strs[i], strs[j])) {
                unite(i, j,parent,c);
            }
        }
    }

    return c;
}




int find(int i, int* pt) {
    if (pt[i] != i) {
        pt[i] = find(pt[i], pt);
    }
    return pt[i];
}

void unite(int i, int j, int* pt, int& c) {
    int pi = find(i, pt);
    int pj = find(j, pt);
    if (pi != pj) {
        pt[pi] = pj;
        c--;
    }
}

bool isSimilar_2(string& s1, string& s2) {
    if(s1 == s2) return true;
    int diff = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) {
            diff++;
            if (diff > 2) {
                return false;
            }
        }
    }

    return true;
}

// with array
int numSimilarGroups(vector<string>& strs) {
    int n = strs.size();
    int c = n;

    int* parent = new int[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (isSimilar_2(strs[i], strs[j])) {
                unite(i, j, parent, c);
            }
        }
    }

    delete[] parent;

    return c;
}



int main() {

    vector<string> strs = {"omv","ovm"};
    cout << numSimilarGroups(strs) << endl;
    strs = {"tars","rats","arts","arst","star"};
    cout << numSimilarGroups(strs) << endl;
    strs = {"blw","bwl","wlb"};
    cout << numSimilarGroups(strs) << endl;

}