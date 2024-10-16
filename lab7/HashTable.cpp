#include <algorithm> // for using transform
#include <cctype> // for using toupper
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
int z,n;
cin >> z >> n;

vector<string> hash;
vector<string> txt;
for(int i = 0;i<z;i++){
    hash.push_back("NULL");
}
for(int i = 0;i<n;i++){
    string tmp;
    cin >> tmp;
    transform(tmp.begin(), tmp.end(), tmp.begin(),::toupper);
    txt.push_back(tmp);
}

for(int i = 0;i<n;i++){
    int sum= 0;
    for(auto p: txt[i]){
        int tmp = p;
        tmp -= 64;
        sum += tmp;
    }
    int mod = sum % z;
    if(hash[mod] == "NULL"){
        hash[mod] = txt[i];
    }else{
        int post_mod = mod;
        while(hash[post_mod] != "NULL"){
            post_mod++;
        }
        hash[post_mod] = txt[i];
    }
}

for(auto p:hash){
    cout << p << " ";
}

    
}