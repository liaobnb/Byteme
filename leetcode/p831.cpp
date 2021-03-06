#include <bits/stdc++.h>
using namespace std;

string lower(string s) {
  string res = "";
  fora(c, s) res += tolower(c);
  return res;
}

string maskEmailSimple(string s) {
  stringstream ss;
  fori(i, 0, sz(s))
  if (s[i] == '@') {
    ss << tolower(s[0]);
    ss << "*****";
    ss << tolower(s[i-1]);
    fori(j, i, sz(s)) ss << s[j];
    break;
  }
  return ss.str();
}

string maskEmail(string s) {
  string one, two, three, part;
  int idx = s.find("@");
  one = s.substr(0, idx);
  part = s.substr(idx+1);
  idx = part.find(".");
  two = part.substr(0, idx);
  three = part.substr(idx + 1);
  // cout << one << " " <<  two << " " << three << endl;
  one = lower(one);

  string res = "";
  res += one[0];
  res += "*****";
  res += one[sz(one) - 1];

  return res + "@" + lower(two) + "." + lower(three);
}

string strip(string s) {
  string res = "";
  fora(c, s)
  if (c != '(' && c != ')' && c != '{' && c != '}' &&
    c != '-' && c != ' ')
    res += c;
  return res;
}

string maskPhone(string aa) {
  string s = strip(aa);

  int n = sz(s);
  string sign = "";
  string code = "";
  string num = "";
  if (n == 10) {
    num = s;
  } else {
    int idx = 0;
    if (s[0] == '+') {
      sign = "+";
      ++idx;
    } else if (s[0] >= '0' && s[0] <= '9') {
      sign = "+";
    } else if (s[0] == '-') {
      sign = "-";
      ++idx;
    }
    code = s.substr(idx, n-10-idx);
    num = s.substr(n-10, 10);
  }

  int nc = sz(code);
  code = "";
  fori(i, 0, nc) code += "*";

  if (code == "")
  return code + "***" + "-" + "***" + "-" + num.substr(6, 4);

  return sign + code + "-" + "***" + "-" + "***" + "-" + num.substr(6, 4);
}

class Solution {
public:
  string maskPII(string S) {
    if (S.find("@") != string::npos) return maskEmail(S);
    else return maskPhone(S);
  }
};

int main() {
  return 0;
}
