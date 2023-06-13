#include<bits/stdc++.h>
using namespace std;

bool isValidParenthesis(string expression)
{
    stack<char> s;
    int n = expression.length();

    for(int i = 0; i<n; i++)
    {
        if(s.size() == 0)
        {
            s.push(expression[i]);
            continue;
        }

        if(expression[i] == '(' || expression[i] == '[' || expression[i] == '{')
            s.push(expression[i]);
        else if(expression[i] == ')' && s.top() == '(')
        { 
                s.pop();
        } else if (expression[i] == ']' && s.top() == '[') {
          s.pop();
        } else if (expression[i] == '}' && s.top() == '{')
            s.pop();
        else{
            return false;
        }
    }

    if(s.size() > 0)
        return false;
    else{
        return true;
    }
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string s;
        cin>>s;

        if(isValidParenthesis(s) == true)
            cout<<"Balanced\n";
        else{
            cout<<"Not Balanced\n";
        }
    }
}