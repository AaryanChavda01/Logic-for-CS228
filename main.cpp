#include "common.h"
#include "prop.h"

using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        prop F(s);
        cout<<"Formula: "<<F.formula<<'\n';
        cout<<"Validity: "<<F.valid<<'\n';
        cout<<"Variables:\n";
        int k = F.variables.size();
        for(auto j = F.variables.begin(); j != F.variables.end(); j++){
            cout<<*j<<'\n';
        }
    }
    return 0;
}