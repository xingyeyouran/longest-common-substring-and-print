#include<iostream>
using namespace std;
#include<vector>

/*
1).Let the input sequences be X[0..m-1] and Y[0..n-1] of lengths m and n respectively. 
create a 2-d matrix(m+1,n+1) and  initialize its entries with 0.	X[m-1] stands subsequence consisted of the first n letters of X 
2).Steps to find length of lcs:
	(a) define result as 0,it is the lcs of 2 sequences.
	(b) create a duex for loop which stands for matching last character of both subsequences (i.e. matching X[i-1]and Y[j-1])
	(c) If last characters of both sequences match (i.e. X[i-1] == Y[j-1]) then
	L(i,j) = 1 + L(i-1], j-1) then compare L(i,j) with result, update the result and mark the coordinates(x,y) if L(i,j) is bigger
	(d)	If last characters of both sequences do not match (or X[m-1] != Y[n-1]) then
	set L(i,j) to 0.

3).After counstructing the L(m+1,n+1) and finding out coordinates,go backward to print lcs:
`	(a) concatenate subquence start from X(x) reversely with length l(x,y)(i.e. if l(x,y) is a,get subsequence X[x-a+1,x])




*/
int lcs(string s1,string s2) {
	vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));
	int result = 0;
	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1]+1;
				result = max(result, dp[i][j]);
			}
			else
			{
				dp[i][j] = 0;
			}
		}
	}
	return result;
}
void print_lcs(string s1, string s2) {
	vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
	int len = 0;
	int row, col = 0;
	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j < s2.size(); j++) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				if (len < dp[i][j]) {
					len = dp[i][j];
					row = i;
					col = j;
				}
			}
			else
			{
				dp[i][j] = 0;
			}
		}
	}
	string res="";
	while (dp[row][col]>0){
		res += s1[row - 1];
		row--, col--;
	}
	reverse(res.begin(), res.end());
	cout << res << endl;
}
int main() {
	string s1 = "OldSite:GeeksforGeeks.org";
	string s2 = "NewSite:GeeksQuiz.com";
	cout << lcs(s1, s2) << endl;
	print_lcs(s1, s2);
}