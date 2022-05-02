#include <iostream>
#include <vector>

using namespace std;
using std::vector;

class fbUser{
private:
    string name;
    vector <fbUser*> friends;
public:
    fbUser(){};
    fbUser(string name){this->name = name};

    void addFriend(fbUser &another){
        friends.push_back(&another);
        another.friends.push_back(this);
    }

    void showFriends(){
        cout << "\nFriends of " << name << ": ";
        for (fbUser *eachFriend: friends){
            cout << eachFriend->name << "    ";
        }
        cout << "\n";
    }

    void showFriendofFriend(){
        cout << "\nFriends of Friends of " << name  << "\n";
        for (fbUser *eachFriend: friends){
            for (fbUser *fof: eachFriend->friends){
                if(fof != this){
                    cout << fof->name << "    ";
                }
            }
        }
        cout << "\n";
    }

    void showMutualFriend(fbUser &another){
        cout << "Mutual friend"
    }
};

int main(){

    return 0;
}