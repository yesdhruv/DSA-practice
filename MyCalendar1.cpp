class MyCalendar {
private :
    unordered_map<int,int>mp;
public:
//     MyCalendar() {
        
//     }
     bool book(int start, int end) {
        for(auto &[s2,e2]:mp)
        {  
            if( !(start >= e2 || s2 >= end) )// if neither of above condition is satisfied, there exists an intersection 
            return false;
        }
         mp[start]=end; // no intersection found, so insert the new slot and return true
         return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
