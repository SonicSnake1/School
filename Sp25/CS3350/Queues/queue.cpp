#include <stack>
#include <queue>
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main(){
	stack<char> s;
	queue<char> q;
	string word;
	int i;
	bool areEqual = true;
	ifstream infile;

	infile.open("palindromes.txt");
	if(infile .is_open()) {
		while(!infile
		infile >> word;

	//get user input
	cout << "Enter a word: \n";
	cin >> word;

	//Process the word letter by letter
	for(i = 0; i<word.length(); i++){
		s.push(word[i]);
		q.push(word[i]);
	}

	i = 0;
	while(i<word.length() && areEqual){
		if(s.top() != q.front())
			areEqual = false;
		s.pop();
		q.pop();
		i++;
	}
	if(areEqual)
		cout << word << " is a palindrome\n";
	else
		cout << word << " is not a palindrome\n";


	system("pause");
	return 0;
		}
	infile.close();
	}
	else
}
