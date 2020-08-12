#include<functional>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
int find_password(int remaining_chars,unsigned long int &password_hash,string &password,string &allowed_chars){
    if(remaining_chars<=0){
        if(hash<string>()(password)==password_hash){
            return 1;
        }
        return 0;
    }
    for(int i=0;i<allowed_chars.length();i++){
        password.push_back(allowed_chars[i]);
        if(find_password(remaining_chars-1,password_hash,password,allowed_chars)==1){
            return 1;
        }
        password.pop_back();
    }
    return 0;
}
int main(){
    string allowed_chars,password;
    int password_length;
    unsigned long int password_hash;
    cin>>password_length>>allowed_chars>>password_hash;
    if(find_password(password_length,password_hash,password,allowed_chars)==1){
        cout<<password;
    }
    else{
        cout<<"NOT_FOUND";
    }
    cout<<endl;
    return 0;
}