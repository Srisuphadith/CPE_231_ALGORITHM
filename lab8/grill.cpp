#include <iostream>
using namespace std;

const int MAX_X = 1000;
bool dp[MAX_X + 1];   

int maxImpossible(int x, int boxes[], int n) {
    fill(dp, dp + x + 1, false); 
    dp[0] = true;                

    for (int i = 0; i < n; i++) {
        int box = boxes[i];
        for (int j = box; j <= x; j++) {
            if (dp[j - box]) {
                //cout <<"j = " << j << " box = " << box  << endl;
                dp[j] = true;  
            }
        }
    }
    for (int i = x; i >= 0; --i) {
        if (!dp[i]) {
            return i;  
        }
    }
    return -1;  
}
int main(){
    int x,n;
    cin >> x >> n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
    cout << maxImpossible(x, arr, n) << endl;
}