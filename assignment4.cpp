#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

const int MAX_SIZE = 30; // Define maximum size for stack
char stack[MAX_SIZE];
int top = -1;

void push(char x) {
    if (top == MAX_SIZE - 1) {
        cout << "Stack overflow" << endl;
    } else {
        top++;
        stack[top] = x;
    }
}

char pop() {
    if (top == -1) {
        cout << "Stack underflow" << endl;
        return '\0';
    } else {
        return stack[top--];
    }
}

bool isPalindrome(const char* str) {
    int length = strlen(str);
    int i = 0;
    int j = length - 1;

    while (i < j) {
        if (str[i] != str[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main() {
    char input[40];
    char filtered[40];
    int count = 0;
    int flag = 1; 
    cout << "Enter the statement: ";
    cin.getline(input, 40);

    int length = strlen(input);


    for (int i = 0; i < length; i++) {
        input[i] = tolower(input[i]);
    }

    cout << "Statement after lowercasing is: " << input << endl;


    for (int i = 0; i < length; i++) {
        if (input[i] != ' ' && !ispunct(input[i])) {
            push(input[i]);
            filtered[count] = input[i];
            count++;
        } 
    }

    filtered[count] = '\0';

   
    if (!isPalindrome(filtered)) {
        flag = 0; // Set flag to 0 (false) if not a palindrome
    }

    cout << "Filtered string: " << filtered << endl;
    cout << "Is palindrome: " << (flag ? "Yes" : "No") << endl;

    return 0;
}

