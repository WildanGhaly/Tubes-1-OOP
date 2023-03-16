
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

int main(){
    vector<int> abilityId;
    vector<int> selectedAbility;
    srand(time(NULL));
    for (int i = 0; i < 7; i++){
        abilityId.push_back(i+1); 
    }
    for(auto i : abilityId){
        cout << i << " ";
    }
    cout <<endl;


    for (int i = 0; i < 7; i++){
        int index = rand() % abilityId.size();
        cout<<index<<endl;
        selectedAbility.push_back(abilityId[index]);
        abilityId.erase(abilityId.begin()+index);
    }
    cout << "Selected ability: ";
    for(auto i : abilityId){
        cout << i << " ";
    }
    cout <<"Safasdfasfda"<<endl;
    for(auto i : selectedAbility){
        cout << i << " ";
    }
}


