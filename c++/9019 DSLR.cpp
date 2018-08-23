#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
using namespace std;


int visited[10005];
int bef[10005];
char ch[10005];

char c[4] = { 'D','S','L','R' };
int D(int x) {
	return ((2 * x) % 10000);
}
int S(int x) {
	if (x == 0) return(10000 - 1);
	else return (x - 1);
}
int L(int x) {
	int f = x / 1000;
	int l = x % 1000;
	return (l * 10 + f);
}
int R(int x) {
	int f = x / 10;
	int l = x % 10;
	return (l * 1000 + f);
}

void search(int num, int cmp) {
	queue<int> q;
	q.push(num);
	visited[num] = 1;

	while (q.front() != cmp && !q.empty()) {
		int x = q.front(); q.pop();
		int dslr[4];
		dslr[0] = D(x);
		dslr[1] = S(x);
		dslr[2] = L(x);
		dslr[3] = R(x);
		for (int i = 0; i<4; i++) {
			if (visited[dslr[i]] == 0) {
				q.push(dslr[i]);
				visited[dslr[i]] = 1;
				ch[dslr[i]] = c[i];
				bef[dslr[i]] = x;
			}
		}
	}

	return;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i<n; i++) {
		memset(visited, 0, sizeof(visited));
		memset(bef, 0, sizeof(bef));
		memset(ch, 0, sizeof(ch));
		int a, b;
		cin >> a >> b;
		search(a, b);
		string s = "";
		while (a != b) {
			s.push_back(ch[b]);
			b = bef[b];
		}
		reverse(s.begin(), s.end());
		cout << s << "\n";
	}

	return 0;
}
