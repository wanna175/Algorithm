#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> arr;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	for (int i = 0; i < 9; ++i) {
		cin >> n; arr.push_back(n);
	}
	sort(arr.begin(), arr.end());
	for (int a = 0; a < 9; ++a)
		for (int b = a + 1; b < 9; ++b)
			for (int c = b + 1; c < 9; ++c)
				for (int d = c + 1; d < 9; ++d)
					for (int e = d + 1; e < 9; ++e)
						for (int f = e + 1; f < 9; ++f)
							for (int g = f + 1; g < 9; ++g)
								if (arr[a] + arr[b] + arr[c] + arr[d] + arr[e] + arr[f] + arr[g] == 100) {
									cout << arr[a] << '\n' << arr[b] << '\n' << arr[c] << '\n' << arr[d] << '\n' << arr[e] << '\n' << arr[f] << '\n' << arr[g];
									return 0;
								}

	return 0;
}