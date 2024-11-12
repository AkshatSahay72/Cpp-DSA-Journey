#include<iostream>
#include<vector>
using namespace std;

void magic(string a,vector<string> &ans,string out){
    if(out.length()>= a.length()){
        ans.push_back(out);
        return;
    }

    for (int i = 0; i < a.size();i++){
        out.push_back(a[i]);
        magic(a, ans, out);
        out.pop_back();
    }
}

int main(){
    string a;
    int i;
    cin >> a;
    vector<string> ans;
    string out = "";
    magic(a, ans, out);
    for(i = 0; i < ans.size();i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}