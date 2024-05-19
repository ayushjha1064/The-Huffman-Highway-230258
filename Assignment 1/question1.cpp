//AYUSH JHA //

//QUESTION-1 //
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int k=1;
    for(int i=1;i<=n;i++){
        k=1;
        while(k<=n){
            if(k%2==1){
                for(int j=1;j<=i;j++){
                    cout<<j;
                }
                for(int j=1;j<=2*(n-i);j++){
                    cout<<" ";
                }
            }
            else{
                for(int j=i;j>=1;j--){
                cout<<j;
                }
            }
            
            
            
            k++;
        }
        cout<<endl;
    }
}
















