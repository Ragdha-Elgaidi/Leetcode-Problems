class RandomizedSet {
    vector<int> data;                
    unordered_map<int,int> pos;      

public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if (pos.count(val)) return false;        
        pos[val] = (int)data.size();             
        data.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        auto it = pos.find(val);
        if (it == pos.end()) return false;        

        int i = it->second;                        
        int lastVal = data.back();                

        data[i] = lastVal;
        pos[lastVal] = i;

        data.pop_back();                          
        pos.erase(it);                           
        return true;
    }
    
    int getRandom() {
        int idx = rand() % data.size();    
        return data[idx];
    }
};
