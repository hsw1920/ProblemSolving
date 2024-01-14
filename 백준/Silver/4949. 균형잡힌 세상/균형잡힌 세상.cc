#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	while (1)
	{
		string str;
		getline(cin, str);
		if (str == ".")
			break;
		stack<char> st;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '('  || str[i] == '['
				|| str[i] == ')' || str[i] == ']') {

				if (str[i] == '(' || str[i] == '[')
					st.push(str[i]);
				else if (!st.empty()) {
					if (st.top() == '(' && str[i] == ')') {
						st.pop();
					}
					else if (st.top() == '[' && str[i] == ']') {
						st.pop();
					}
					else st.push(str[i]);
				}
				else st.push(str[i]);
			}
		}
		if (st.empty())
			cout << "yes" << "\n";
		else
			cout << "no" << "\n";
	}

	return 0;
}