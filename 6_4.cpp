#include <utility> 
#include <vector>
#include <iostream>
#include <string>
#include <algorithm> 

using namespace std;

template <typename T, typename T2>
class KeyedBag {
private:
    vector<pair<T, T2>> items;

public:
   
    void insert(const T& key, const T2& value) {
        items.push_back(make_pair(key, value));
    }

    
    bool erase_one(const T& key) {
        auto it = find_if(items.begin(), items.end(), [&key](const pair<T, T2>& p) {
            return p.first == key;
        });
        if (it != items.end()) {
            items.erase(it);
            return true;
        }
        return false;
    }

   
    bool find(const T& key, T2& value) const {
        auto it = find_if(items.begin(), items.end(), [&key](const pair<T, T2>& p) {
            return p.first == key;
        });
        if (it != items.end()) {
            value = it->second;
            return true;
        }
        return false;
    }

   
    size_t size() const {
        return items.size();
    }

    
    void print() const {
        for (const auto& item : items) {
            cout << "Key: " << item.first << ", Value: " << item.second << endl;
        }
    }
};
