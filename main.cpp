#include <iostream>
#include <string>
#include <stack>

class solution {
public:
  std::string longestValidParen(const std::string & s) {
    size_t begin, end;
    begin = 0;
    end = begin+1;
    while (end < s.size() && isValid(s.substr(begin, end-begin)))
      end++;
    if (end == s.size() && isValid(s.substr(begin, end-begin)))
      return s.substr(begin, end-begin);
    else
  }

private:
  bool isValid(const std::string & str) {
    std::stack<char> st;
    size_t idx = 0;
    while (idx < str.size()) {
      if (st.empty() || str[idx] == '(')
	st.push(str[idx]);
      else if (str[idx] == ')') {
	if (st.empty())
	  return false;
	else if (st.top() == ')'){
	  st.push(str[idx]);
	}
	else if (st.top() == '(')
	  st.pop();
      }
      idx++;
    }
    if (!st.empty())
      return false;
    return true;
  }
};
