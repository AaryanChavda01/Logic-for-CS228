#include "common.h"
#include "prop.h"

using namespace std;

int main(){
    cout<<"Enter number of formulae\n";
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cout<<"Enter a formula\n";
        string s;
        cin>>s;
        prop F(s);
        cout<<"Formula: "<<F.formula<<'\n';
        cout<<"well-formed: "<<F.well_formed<<'\n';
        cout<<"Variables:\n";
        if(!F.well_formed){
            cout<<"Not well-formed\n";
            continue;
        }
        unordered_set<string> variables = F.getVariables();
        for(auto j = variables.begin(); j != variables.end(); j++){
            cout<<*j<<'\n';
        }
    }
    return 0;
}