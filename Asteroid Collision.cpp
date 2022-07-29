/*class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(auto x:asteroids)
        {
            if(x>=0)st.push(x);
                
            else
            {
                while(st.top()>0 and abs(x)>st.top() and !st.empty())
                {
                    st.pop();
                }
                if(st.empty() or st.top()<0)st.push(x);
                else if(st.top() == -1*x)st.pop();
            }
            
        }
        int n = st.size();
        vector<int>res(n,0);// here we need ot itirate fromlast so useing as ana array we need to declare size
        
      while(!st.empty())
      {
          res[--n]=st.top();
          st.pop();
      }
        return res;
        }
};*/
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        vector<int> s; // use vector to simulate stack
        for (int i : a) {
            if(i > 0) s.push_back(i);
            else{
                while(!s.empty() && s.back() > 0 && s.back() < abs(i)) s.pop_back();
                if(s.empty() || s.back() < 0) s.push_back(i);
                else if(s.back() == -i) s.pop_back();
            }
        }
        return s;
    }
};