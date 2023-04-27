#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/simplify-path/


//sool2
string simplifyPath00(string path) {

    stringstream ss(path);
    string part;
    vector<string> parts;
    while (getline(ss, part, '/')) {
        if (!part.empty() && part != ".") {
            parts.push_back(part);
        }
    }

    vector<string> st;

    // Iterate through each part of the path
    for (const string& part : parts) {
        if (part == "..") {
            if (!st.empty()) {
                st.pop_back();
            }
        } else {
            st.push_back(part);
        }
    }
    string simplifiedPath = "";
    for (const string& dir : st) {
        simplifiedPath += "/" + dir;
    }

    if (simplifiedPath.empty()) {
        simplifiedPath = "/";
    }

    return simplifiedPath;
}

string simplifyPath0(string path) {
    // Initialize a stack to simulate directory traversal
    stack<string> st;

    // Split the input path by slashes using a string stream
    stringstream ss(path);
    string dir;
    while (getline(ss, dir, '/')) {
        if (dir == "..") {
            // If encountering "..", pop the last directory from stack if not empty
            if (!st.empty()) {
                st.pop();
            }
        } else if (dir != "." && !dir.empty()) {
            // Ignore ".", and push other directory names into the stack
            st.push(dir);
        }
    }

    // Construct the simplified canonical path from the stack
    string simplifiedPath = "";
    while (!st.empty()) {
        simplifiedPath = '/' + st.top() + simplifiedPath;
        st.pop();
    }

    // If the simplified path is empty, set it to "/"
    if (simplifiedPath.empty()) {
        simplifiedPath = "/";
    }

    return simplifiedPath;
}

//sol1
static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();

string simplifyPath(string path) {

    stack<string> data;
    string ans= "";
    string temp = "";
    int size = path.size();

    for(int i = 0;  i<size; ++i)
    {
        if(path[i] == '/')
            continue;
        temp = "";
        while(i < size && path[i] != '/')
        {
            temp += path[i];
            ++i;
        }
        if(temp == ".")
            continue;
        else if(temp == "..")
        {
            if(!data.empty())
                data.pop();
        }
        else
            data.push(temp);
    }

    while(!data.empty())
    {
        ans = "/" + data.top() + ans;
        data.pop();
    }

    if(ans.size() == 0)
        return "/";

    return ans;
}

int main()
{
    string path = "/home/";
    string path2 = "/home//foo/";
    string path3 = "/a/./b/../../c/";
    string path1 = "/../"; // ../ burda optimizasyon yapilabilinir +3 eklenebilir
    cout << simplifyPath(path1) << endl;
    cout << simplifyPath(path2) << endl;
    cout << simplifyPath(path3) << endl;
    cout << simplifyPath(path) << endl;


}