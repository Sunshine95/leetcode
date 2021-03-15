#include<bits/stdc++.h>
using namespace std;

class FreqStack {
public:
    
    unordered_map<int, int> freq;
    vector<stack<int>> group;
    int maxFreq;
    
    FreqStack() {
        group.push_back(stack<int>()); 
    }
    
    void push(int x) {
        
        int f;
        if(freq.find(x) == freq.end()){
            f = 1;
        }
        else{
            f = freq[x] + 1;
        }
        
        freq[x] = f;
        
        if(f > maxFreq){
            maxFreq = f;
            group.push_back(stack<int>());
        }
        
        group[f].push(x);
        
    }
    
    int pop() {
        
        int out = group[maxFreq].top();
        group[maxFreq].pop();
        freq[out]--;
        
        if(group[maxFreq].empty()){
            maxFreq--;
            group.pop_back();
        }
        
        return out;
    }
};

int main(){

    FreqStack* obj = new FreqStack();
    obj->push(1);
    obj->push(4);
    obj->push(0);
    obj->push(9);
    obj->push(3);
    obj->push(4);
    obj->push(2);
    cout << obj->pop() << endl;
    obj->push(6);
    cout << obj->pop() << endl;
    obj->push(1);
    cout << obj->pop() << endl;
    obj->push(1);
    cout << obj->pop() << endl;
    obj->push(4);
    cout << obj->pop() << endl;
    cout << obj->pop() << endl;
    cout << obj->pop() << endl;
    cout << obj->pop() << endl;
    cout << obj->pop() << endl;
    cout << obj->pop() << endl;

    return 0;
}