#include <iostream>
#include <vector>
#include <string>
using namespace std;

string addStrings(string num1, string num2) {
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	int flag = 0, tmp;
	if (num1.size() < num2.size()) {
		for (int i = 0; i < num1.size(); ++i) {
			tmp = num1[i] - '0' + num2[i] - '0' + flag;
			flag = tmp / 10;
			num2[i] = tmp % 10 + '0';
		}
		if (flag) {
			int tmp = num1.size();
			while (num2[tmp] == '9') {
				num2[tmp] = '0';
				tmp++;
				if (tmp == num2.size()) {
					num2 += '1';
					flag = 0;
					break;
				}
			}
			if (flag)
				num2[tmp] += flag;
		}		
		reverse(num2.begin(), num2.end());
		return num2;
	}
	else {
		if (num1.size() > num2.size()) {
			for (int i = 0; i < num2.size(); ++i) {
				tmp = num2[i] - '0' + num1[i] - '0' + flag;
				flag = tmp / 10;
				num1[i] = tmp % 10 + '0';
			}
			if (flag) {
				int tmp = num2.size();
				while (num1[tmp] == '9') {
					num1[tmp] = '0';
					tmp++;
					if (tmp == num1.size()) {
						num1 += '1';
						flag = 0;
						break;
					}
				}
				if (flag)
					num1[tmp] += flag;
			}
			reverse(num1.begin(), num1.end());
			return num1;
		}
		else {
			for (int i = 0; i < num2.size(); ++i) {
				tmp = num2[i] - '0' + num1[i] - '0' + flag;
				flag = tmp / 10;
				num1[i] = tmp % 10 + '0';
			}
			if (flag) {
				num1 += '1';
			}
			reverse(num1.begin(), num1.end());
			return num1;
		}
	}
	return "";
}
 
int main() {
	string num1("3");
	string num2("990");
	cout << addStrings(num1, num2) << endl;
	return 0;
}