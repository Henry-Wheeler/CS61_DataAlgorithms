#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;


class GiftList {
private:
    map<string>, set<string> giftLists; 

public:

    void addPerson(const string& person) {
        giftLists[person]; 
    }


    void addGift(const string& person, const string& gift) {
        if (giftLists.find(person) != giftLists.end()) {
            giftLists[person].insert(gift);
        } else {
            cout << "Person not found!" << endl;
        }
    }


    void removePerson(const string& person) {
        giftLists.erase(person);
    }


    void removeGift(const string& person, const string& gift) {
        if (giftLists.find(person) != giftLists.end()) {
            giftLists[person].erase(gift);
        } else {
            cout << "Person not found!" << endl;
        }
    }


    void listAll() const {
        for (const auto& [person, gifts] : giftLists) {
            cout << person << "'s gift list:" << endl;
            for (const auto& gift : gifts) {
                cout << "  - " << gift << endl;
            }
            cout << endl;
        }
    }
};

