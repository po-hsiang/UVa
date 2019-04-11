#include <iostream>
#include <stdio.h> // getchar()
#include <string>

using namespace std;

struct Node { // linked list
	string word;
	Node *next;
};

bool isNumber(char ch) // 確認是否為數字
{
	return ('0' <= ch && ch <= '9');
}

bool isAlphabet(char ch) // 確認是否為字母
{
	return ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z');
}

int main()
{
	Node *head = NULL;
	char ch;
	ch = getchar();

	while (true) {

		if (isAlphabet(ch)) { // 若為字母
			string word;
			while (isAlphabet(ch)) {
				word += ch;
				ch = getchar();
			}
			cout << word;
			Node *temp = new Node;
			temp->word = word;
			temp->next = head; // next其實是往前指
			head = temp;
		}
		else if (isNumber(ch)) { // 若為數字
			if (ch == '0')
				break;

			int num = 0;
			while (isNumber(ch)) {
				num = num * 10 + (ch - '0');
				ch = getchar();
			}
			Node *now = head, *prev = NULL;
			for (int i = 1; i < num; i++) {
				prev = now;
				now = now->next; // 一直往前找
			}
			cout << now->word;

			if (now != head) {
				prev->next = now->next;
				now->next = head;
				head = now;
			}
		}
		else { // 若為符號
			putchar(ch);
			ch = getchar();
		}
	}
	return 0;
}