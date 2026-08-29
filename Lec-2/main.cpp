#include "common.h"
#include "prop.h"
#include "parse.h"

int main(){
    int n;
    cout<<"Enter number of formulae:\n";
    cin>>n;
    for(int i=0; i<n; i++){
        string s;
        cout<<"Enter a formula:\n";
        cin>>s;
        prop F(s);
        if(!F.well_formed){
            cout<<"Formula not well-formed!\n";
        }
        else{
            truthTable F_table(F);
            unordered_set<string> variables = F.getVariables();
            int n = F_table.semantics.size(), m = variables.size();
            for(auto i=variables.begin(); i!=variables.end(); i++){
                cout<<*i<<" | ";
            }
            cout<<F.formula<<'\n';
            for(int i=0; i<n; i++){
                int k = i;
                for(int j=0; j<m; j++){
                    cout<< k%2 << " | ";
                    k = k/2;
                }
                cout<<F_table.semantics[i]<<'\n';
            }
        }
    }
    return 0;
}