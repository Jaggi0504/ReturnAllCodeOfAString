#include<bits/stdc++.h>
using namespace std;

int getCode(string input, string *output) {
	if(input[0] == '\0') {
		output[0] = "";
		return 1;
	}
	int first, second;
	char firstChar, secondChar;
	first = input[0] - 48;
	firstChar = first + 'a' - 1;
	string smallOutput1[500], smallOutput2[500];
	int size2 = 0;
	int size1 = getCode(input.substr(1), smallOutput1);
	if(input[1] != '\0') {
		second = (first * 10 + input[1]) - 48;
		if(second >= 10 && second <= 26) {
			secondChar = second + 'a' - 1;
			size2 = getCode(input.substr(2), smallOutput2);
		}
	}
	int k = 0;
	for(int i=0;i<size1;i++) {
		output[k++] = firstChar + smallOutput1[i];
	}
	for(int i=0;i<size2;i++) {
		output[k++] = secondChar + smallOutput2[i];
	}
	return k;
}

int main() {
	string input, output[100];
	cin>>input;
	int ans = getCode(input, output);
	for(int i=0;i<ans;i++) {
		cout<<output[i]<<endl;
	}
	return 0;
}
