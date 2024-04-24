#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

set <string> permutations;

void check_ip(string ip) {
	vector <string> ip_numbers;
	string number = "";
	short count_true_check = 0;
	for (char digit : ip) {
		if (digit != '.') {
			number += digit;
		}
		else {
			if (number.size() >= 1) {
				ip_numbers.push_back(number);
				number = "";
			}
		}
	}
	if (!number.empty()) {
		ip_numbers.push_back(number);
	}
	for (string number : ip_numbers) {
		//cout << number << ' ';
		if ((stoi(number) < 256) and ((number.size() > 1 and number[0] != '0') or (number.size() == 1))) {
			count_true_check += 1;
		}
	}
	//cout << '\n' << ip << '\n';
	if (count_true_check == 4) {
		permutations.insert(ip);
	}
}

void permute(vector <string> arr, short l, short r, string ip) {
	if (l == r) {
		check_ip(ip);
	}
	else {
		for (int i = l; i < r; i++) {
			swap(arr[i], arr[l]);
			permute(arr, l + 1, r, ip + arr[l]);
			swap(arr[i], arr[l]);
		}
	}
}

int main() {
	vector <string> inarr(4);
	string ip_char;
	for (int i = 0; i < 4; i++) {
		fin >> ip_char;
		inarr[i] = ip_char;
	}
	permute(inarr, 0, 4, "");
	for (auto const ip: permutations) {
		fout << ip << '\n';
	}
}