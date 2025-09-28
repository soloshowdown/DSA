class RandomizedSet {
private:
    vector<int> arr; // values store karne ke liye
    unordered_map<int, int> mp; // val -> index

public:
    RandomizedSet() {}

    bool insert(int val) {
        if (mp.find(val) != mp.end()) return false; // already present
        arr.push_back(val);
        mp[val] = arr.size() - 1; // index map karo
        return true;
    }

    bool remove(int val) {
        if (mp.find(val) == mp.end()) return false; // not present
        int idx = mp[val];           // val ka index
        int last = arr.back();       // last element
        arr[idx] = last;             // swap last with val
        mp[last] = idx;              // update last ka index
        arr.pop_back();              // remove last
        mp.erase(val);               // erase from map
        return true;
    }

    int getRandom() {
        int idx = rand() % arr.size(); // random index
        return arr[idx];
    }
};
