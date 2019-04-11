#include <iostream>
#include <cstring> // strlen
#include <stack>

using namespace std;

bool isIllegal = false;

void evaluate(stack<int>& st, char op)
{
	// �Y�bpop�X��ӼƦr�estack�N�w�g�Ū��ܡA�N��e�ǻy�k���~
	if (st.empty()) {
		isIllegal = true;
		return;
	}
	int num1 = st.top();
	st.pop();

	if (st.empty()) {
		isIllegal = true;
		return;
	}
	int num2 = st.top();
	st.pop();

	int temp;

	if (op == '+')
		temp = num1 + num2;
	else if (op == '-')
		temp = num1 - num2;
	else if (op == '*')
		temp = num1 * num2;
	else if (op == '/')
		temp = num1 / num2;
	else if (op == '%')
		temp = num1 % num2;

	st.push(temp);
}

int main()
{
	char input[1025];

	while (cin.getline(input, sizeof(input)) && input[0] != '.') {
		
		stack<int> s;
		isIllegal = false;
		int operand = 0;

		// �q�᩹�e��
		for (int i = strlen(input) - 1; i >= 0; i--) {

			switch (input[i])
			{
			case '+': // �B��l
			case '-':
			case '*':
			case '/':
			case '%':
				evaluate(s, input[i]);
				break;

			case ' ': // �ťմN���L
				break;

			default: // �B�⤸
				int pow = 1;
				while (input[i] >= '0' && input[i] <= '9') {
					operand += (input[i] - '0') * pow;
					pow *= 10;
					i--;
				}			
				s.push(operand);
				operand = 0;
				break;
			}
		}
		if (!isIllegal)
			cout << s.top() << "\n";
		else
			cout << "illegal\n";
	}
	return 0;
}