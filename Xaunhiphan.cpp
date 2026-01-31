#include <iostream>

using namespace std;

int n,B[25];

int print(){
    for(int i=1;i<=n;i++) cout<<B[i]<<" ";
    cout<<endl;
    return 0;
}

int quaylui(int i){
    int j;
    for (j=1;j<=n;j++){
        B[i]=j;
        if(i==n) print();
        else quaylui(i+1);
    }
}

main(){
    cin >> n;
    quaylui(1);
}