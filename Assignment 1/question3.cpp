// QUESTION-3 //
#include<iostream>

using namespace std;
double avg;
int above;
int equal_avg;
void Average(int* arr){
    double sum=0;
    for(int i=0;i<10;i++){
        sum+=arr[i];
    }
    avg= sum/10;
    cout<<"Average:"<<sum/10<<endl;
    return;
}
void Highest(int *arr){
    int max= INT_MIN;
    for(int i=0;i<10;i++){
        if(arr[i]>max) max=arr[i];
    }
    cout<<"Highest: "<< max<<endl;
}
void Lowest(int *arr){
    int min= INT_MAX;
    for(int i=0;i<10;i++){
        if(arr[i]<min) min=arr[i];
    }
    cout<<"Lowest: "<< min<<endl;
}

void aboveavg(int* arr){
    int cnt=0;
    int cnt2=0;
    for(int i=0;i<10;i++){
        if(arr[i]>avg){
            cnt++;
        }
        if(arr[i]==avg){
            cnt2++;
        }
    }
    above=cnt;
    equal_avg=cnt2;
    cout<<"above_avg: "<<cnt<<endl;
}
void belowavg(int* arr){
    cout<<"below_avg: "<<10-above-equal_avg<<endl;
}

int main(){
    int arr[10];
    for(int i=0;i<10;i++){
        cin>>arr[i];
    }
    Average(arr);
    Highest(arr);
    Lowest(arr);
    aboveavg(arr);
    belowavg(arr);
}






