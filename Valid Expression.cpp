// https://www.geeksforgeeks.org/problems/valid-expression1025/1?page=2&difficulty%255B%255D=1&category%255B%255D=Stack&sortBy=submissions

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
bool valid(string str);
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string str;
        getline(cin,str);
        cout<<valid(str)<<endl;
    }
    return 0;
}
// } Driver Code Ends


bool valid(string s)
{
    // code here
    int n=s.size();
    stack<char> stk;
    for(int i=0 ;i<n ; i++)
    {
        if(s[i]=='(' || s[i]=='[' || s[i]=='{' )
        {
            stk.push(s[i]);
        }
        else 
        {
            if(s[i]==')' && stk.size()>0 && stk.top()=='(')
            {
                stk.pop();
            }
            else if(s[i]==']' && stk.size()>0 && stk.top()=='[')
            {
                stk.pop();
            }
            else if(s[i]=='}' && stk.size()>0 && stk.top()=='{')
            {
                stk.pop();
            }
            else
                return false;
        }
    }
    
    if(!stk.empty()) return false;
    return true;
}
