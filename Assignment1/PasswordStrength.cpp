#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isSpecialChar(char c) {
    string specialChars = "!@#$%^&*?_~";
    return specialChars.find(c) != string::npos;
}

bool isInvalidChar(char c) {
    string invalidChars = "./\\'\",";
    return invalidChars.find(c) != string::npos;
}

string evaluatePasswordStrength(const string& password) {
    int length = password.length();
    if (length < 8) return "KhongHopLe";
    
    int numUpper = 0, numNumbers = 0, numSymbols = 0;
    for (char c : password) {
        if (isupper(c)) numUpper++;
        else if (isdigit(c)) numNumbers++;
        else if (isSpecialChar(c)) numSymbols++;
        else if (isInvalidChar(c)) return "KhongHopLe";
    }
    
    int numExcess = length - 8;
    int score = 40 + (numExcess * 3) + (numUpper * 4) + (numNumbers * 5) + (numSymbols * 5);
    
    if (numUpper > 0 && numNumbers > 0 && numSymbols > 0) score += 25;
    else if ((numUpper > 0 && numNumbers > 0) || (numUpper > 0 && numSymbols > 0) || (numNumbers > 0 && numSymbols > 0)) score += 15;
    
    if (numUpper == 0 && numNumbers == 0 && numSymbols == 0) score -= 15;
    if (numUpper == 0 && numSymbols == 0 && numNumbers == length) score -= 35;
    
    if (score < 50) return "Yeu";
    else if (score < 75) return "Vua";
    else if (score < 100) return "Manh";
    else return "RatManh";
}

int main() {
    string password;
    cin >> password;
    cout << evaluatePasswordStrength(password) << endl;
    return 0;
}
