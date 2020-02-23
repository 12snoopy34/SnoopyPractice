#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <bitset>
#include <set>
#include <unordered_set>
#include <string>
#include <sstream>

using namespace std;


const int MAX_N = 200000;
int ans[MAX_N + 5];
const int mod = 1e9 + 7;
int countOrders(int n) {
	vector<long long> dp(n + 1, 0);
	dp[1] = 1;
	for (int i = 2; i < n; i++) {
		//两者放在同一抽屉；
		dp[i] = (2 * i - 1) * dp[i - 1] % mod;
		//两者放在不同抽屉；
		dp[i] += (2 * i - 1) * (2 * i - 2) / 2 * dp[i - 1];
		dp[i] %= mod;

	}
	return dp[n];

}
string largestMultipleOfThree(vector<int>  digits) {
	//sort(digits.begin(),digtis.end(),less<int>());
	multiset<int> mod0, mod1, mod2;
	for (auto c : digits) {
		if (c % 3 == 0)
			mod0.insert(c);
		else if (c % 3 == 1)
			mod1.insert(c);
		else if (c % 3 == 2)
			mod2.insert(c);
	}
	multiset<int> ret;
	for (auto c : mod0)
		ret.insert(c);
	for (auto it1 = mod1.rbegin(), it2 = mod2.rbegin(); it1 != mod1.rend() && it2 != mod2.rend(); it1++, it2++) {
		ret.insert(*it1);
		ret.insert(*it2);
	}

	cout << ret.size() << endl;
	string sret = "";

	for (auto it = ret.rbegin(); it != ret.rbegin(); it++) {
		sret += '0' + (*it);
		cout << *it << " " << sret << " ";
	}

	//cout<< sret<<endl;
	while (sret[0] == '0')
		sret = sret.substr(1);
	return sret;

}



int main()
{
	largestMultipleOfThree({ 8,1,9 });
		countOrders(3);
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, i, j;
		string s;
		cin >> n >> s;

		int num = n, last = 0;
		for (i = 0; i < n; i++)
		{
			if (i == n - 1 || s[i] == '>')
			{
				for (j = i; j >= last; j--)
					ans[j] = num--;
				last = i + 1;
			}
		}
		for (i = 0; i < n; i++)
			cout << ans[i] << (i == n - 1 ? '\n' : ' ');

		num = 1, last = 0;
		for (i = 0; i < n; i++)
		{
			if (i == n - 1 || s[i] == '<')
			{
				for (j = i; j >= last; j--)
					ans[j] = num++;
				last = i + 1;
			}
		}
		for (i = 0; i < n; i++)
			cout << ans[i] << (i == n - 1 ? '\n' : ' ');
	}
}