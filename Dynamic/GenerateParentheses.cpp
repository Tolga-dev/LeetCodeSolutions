//https://leetcode.com/problems/generate-parentheses/
#include <bits/stdc++.h>
using namespace std;


void generateParenthesisHelper(vector<string>& result, const int& n, int leftCount, int rightCount, string current) {
    if (current.length() == n * 2) {
        result.emplace_back(current);
        cout <<" " << endl;
        return;
    }

    if (leftCount < n) {
        cout << "l " << leftCount+1 << " " << rightCount << endl;
        generateParenthesisHelper(result, n, leftCount + 1, rightCount, current + "(");
    }

    if (rightCount <leftCount  && rightCount < n ) {
        cout <<"r "<< leftCount << " " << rightCount+1 << endl;
        generateParenthesisHelper(result, n, leftCount, rightCount + 1, current + ")");
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    generateParenthesisHelper(res,n,0,0,"");

    return res;
}
/*

void generateParenthesisHelper(vector<string>& result, int n, int leftCount, int rightCount, string& current) {
    if (current.length() == n * 2) {
        result.emplace_back(current);
        return;
    }

    if (leftCount < n) {
        current.push_back('(');
        generateParenthesisHelper(result, n, leftCount + 1, rightCount, current);
        current.pop_back();
    }

    if (rightCount < leftCount && rightCount < n) {
        current.push_back(')');
        generateParenthesisHelper(result, n, leftCount, rightCount + 1, current);
        current.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    result.reserve(1 << (n * 2));
    string current;
    current.reserve(n * 2);
    generateParenthesisHelper(result, n, 0, 0, current);
    return result;
}
*/

int main()
{

    for (const auto& s: generateParenthesis(2)) {
        cout << s << endl;
    }


}
/*
 * 								   	(0, 0, '')
								 	    |
									(1, 0, '(')
								   /           \
							(2, 0, '((')      (1, 1, '()')
							   /                 \
						(2, 1, '(()')           (2, 1, '()(')
						   /                       \
					(2, 2, '(())')                (2, 2, '()()')
						      |	                             |
					res.append('(())')             res.append('()()')

 */