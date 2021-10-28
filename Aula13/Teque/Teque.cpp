#include <bits/stdc++.h>
void solution(std::deque<int> &A, std::deque<int> &B)
{
	int n=A.size(),m=B.size();
	int diff =n-m;
	int val;
	if (diff < 0) {
		double d = (double)diff / -2;
		for (int i = 0; i < ceil(d); i++) {
			val = B.front();
			B.pop_front();
			A.push_back(val);
		}
	}
	else if (diff > 1) {
		double d = (double)diff / 2;
		for (int i = 0; i < floor(d); i++) {
			val = A.back();
			A.pop_back();
			B.push_front(val);
		}
	}
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::deque<int> A;
	std::deque<int> B;
	char arr[12];
	int num;
	for (int i = 0; i < n; i++) {
		scanf("%s %d", arr, &num);
		if (arr[0] == 'g') {
			if (A.size() > num) {
				std::cout << A[num] << '\n';
			}
			else {
				std::cout << B[num - A.size()] << '\n';
			}
		}
		else if (arr[5] == 'b') {
			B.push_back(num);
			solution(A, B);
		}
		else if (arr[5] == 'f') {
			A.push_front(num);
			solution(A, B);
		}
		else {
			A.push_back(num);
			solution(A, B);
		}
	}
	return 0;
}
