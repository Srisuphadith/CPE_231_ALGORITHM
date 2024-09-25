#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int findMaxIndex(vector<int> arr,int n){
    int tmp = 0;
    for(int i  = 0; i <=n ;i++){
        if(arr[i] > arr[tmp]){
            tmp = i;
        }
    }
    return tmp;
}
void flip(vector<int> &arr,int i){
    int rev = i;
    for(int j = 0;j<= i/2;j++){
        swap(arr[j],arr[rev]);
        rev--;
    }
}
void pancakeSort(vector<int> &arr,int n){
    for(int i = n-1;i>=1;i--){
        int maxIndex = findMaxIndex(arr,i);
        if(maxIndex != i){
            if(maxIndex != 0){
                flip(arr,maxIndex);
            }
            flip(arr,i);
        }
    }

}
int main(){
vector<int> arr;
int n,tmp;
cin >> n;
for(int i = 0;i<n;i++){
    cin >> tmp;
    arr.push_back(tmp);
}
pancakeSort(arr,n);
for(auto p:arr){
    cout << p <<" ";
}
cout << endl;
}