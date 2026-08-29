#include "common.h"
#include "prop.h"
#include "parse.h"

int main(){
    int t;
    cout<<"Enter number of formulae:\n";
    cin>>t;
    for(int i=0; i<t; i++){
        string s;
        cout<<"Enter a formula:\n";
        cin>>s;
        prop F(s);
        if(!F.well_formed){
            cout<<"Formula not well-formed!\n";
        }
        else{
            truthTable F_table(F);
            F_table.print();
            cout<<"Satisfiable: ";
            F_table.satisfiable ? cout<<"YES\n" : cout<<"NO\n";
            cout<<"Valid: ";
            F_table.valid ? cout<<"YES\n" : cout<<"NO\n";
        }
    }
    return 0;
}