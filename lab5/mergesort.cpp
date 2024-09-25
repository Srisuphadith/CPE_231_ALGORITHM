#include <iostream>
#include <algorithm>
using namespace std;
void merge(int arr[],int k,int m,int n){
    // k > m-1
    // m > n-1
}


int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i<n;i++){
        cin  >> arr[i];
    }
    if(n<2){
        return 0;
    }
    int i = 1;
    while(i < n){
        int j = 0;
        while (j<n-i)
        {
            if(n<j+(2*i)){

            }else{

            }
            j = j+2*i;
        }
        i = i*2;
    }
}