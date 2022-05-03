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
    fbUser(string name){this->name = name;};

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

    void showFriendsOfFriends(){
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

    void showMutualFriends(fbUser &another){
        cout << "Mutual friend of " << name << " and " << another.name << ": ";
        for (fbUser *eachFriend: friends){
            for(fbUser *fof: another.friends){
                if(eachFriend == fof){
                    cout << eachFriend->name << "    ";
                }
            }
        }
    }
};

int main(){
    fbUser harry("Harry"), peter("Peter"), john("John"), luna("Luna");
    harry.addFriend(peter);
    harry.addFriend(john);
    peter.addFriend(luna);
    peter.addFriend(john);

    harry.showFriends();
    luna.showFriends();

    //Qb. Show friends of friends
    harry.showFriendsOfFriends();

    //Qc. Show mutual friends
    harry.showMutualFriends(peter);
    return 0;
}