#include <iostream>
#include <bits/stdc++.h>
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(0);
	long long n;
	long long cont = 0;
	std::stack<long long> A;
  int sizeA=A.size();
	std::stack<long long> auxA;
  int axA= auxA.size();
	long long check;
	long long found = 0;
	std::cin >> n;
	std::vector<long long> Sock(2*n);
	for (int i = 0; i < 2*n; i++){
		std::cin >> Sock[i];
	}

	for (int i = 0; i < 2 * n; i++){
		A.push(Sock[i]);
	}

	while (sizeA > 0){
		if (axA && A.top() == auxA.top()){
			
			A.pop();
			auxA.pop();
			found++;
		}
		else{
			auxA.push(A.top());
			A.pop();
		}
		cont++;
	}

	if (found == n){
		std::cout << cont << "\n";
	}
	else{
		std::cout << "impossible\n";
	}
	return 0;
}
