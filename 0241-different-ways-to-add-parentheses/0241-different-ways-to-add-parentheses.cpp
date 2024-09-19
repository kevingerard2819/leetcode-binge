class Solution {
public:
    vector<int> diffWaysToCompute(string expression)
    {
        vector<int> result;
        
        int t = expression.size();
        
        for(int i = 0; i<t;i++)
        {
            char op = expression[i];
            if(op == '+' || op == '-' || op == '*')
            {
              vector<int> s1 = diffWaysToCompute(expression.substr(0,i));
              
              vector<int> s2 = diffWaysToCompute(expression.substr(i+1));
              for(int a : s1)
              {
                for(int b : s2)
                {
                    if(op == '+')
                    {
                        result.push_back(a+b);

                    }
                    else if(op == '-')
                    {
                        result.push_back(a-b);
                    }
                    else if(op == '*')
                    {
                        result.push_back(a*b);
                    }
                }
              }
              
            }
        }
        if(result.empty())
        {
            result.push_back(stoi(expression));
        }
        return result;
        
    }
};