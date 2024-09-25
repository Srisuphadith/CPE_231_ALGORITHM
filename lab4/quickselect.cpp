#include <iostream>
#include <algorithm>
using namespace std;

int lomuto(int arr[],int l,int r){
    int p = arr[r] ,i = l;
    for(int j = l;j<r;j++){
        if(arr[j] <= p){
            swap(arr[i],arr[j]);
            i++;
        }
    }
    swap(arr[i],arr[r]);
    return i;
}

int quickSelect(int arr[],int l,int r,int k){
    int s = lomuto(arr,l,r);
    if(s == k-1){
        return arr[s];
    }else if(s > k-1){
        return quickSelect(arr,l,s-1,k);
    }else{
        return quickSelect(arr,s+1,r,k);
    }
}
int main(){
    int n,k;
    cin >> n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin >> arr[i];
    }
    cin >> k;
    cout << quickSelect(arr,0,n-1,k);

}