// https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       int i=0;
       
       stack<pair<int,int>> stk;
       vector<int> ans(n,1);
       
       while(i<n)
       {
           int spani=1;
           
           while(!stk.empty() && stk.top().first <=price[i])
           {  
               spani+=stk.top().second;
               stk.pop();
           }
           
           stk.push({price[i],spani});
           ans[i]=spani;
           
           i++;
       }
       return ans;
    }
    
};
