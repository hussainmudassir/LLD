#include <bits/stdc++.h>

using namespace std;

class LRUCache {
    list<int> dq;
    unordered_map<int, list<int>::iterator> m;
    public:
        int size;
        LRUCache(int n){
            size = n;
        }
    
        void insert(int x) {
            if(m.find(x) == m.end()) {
                if(dq.size() == size) {
                    int last = dq.back();
                    dq.pop_back();
                    m.erase(last);
                }
            }
            else 
                dq.erase(m[x]);
            dq.push_front(x);
            m[x] = dq.begin();
        }
        
        void display() {
            for (auto it = dq.begin(); it != dq.end();it++)
                cout << (*it) << " ";
 
            cout << endl;
        }
    
};

int main()
{
    LRUCache ca(3);
    ca.insert(1);
    ca.insert(2);
    ca.insert(3);
    ca.insert(4);
    ca.insert(2);
    
    ca.display();
}
