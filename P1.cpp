#include<iostream>
#include<string>
#include<algorithm>
#define START 0
using namespace std;
void inverse_message(int start_index,int end_index,string &message){
    if(start_index>=end_index){
        return;
    }
    swap(message[start_index],message[end_index]);
    inverse_message(start_index+1,end_index-1,message);
    return;
}
void encrypt(int start_index,int end_index,string &message){
    if(start_index>=end_index){
        return;
    }
    string first_half=message.substr(start_index,message.length()/2);
    string second_half=message.substr(message.length()/2);
    inverse_message(start_index,first_half.length()-1,first_half);
    inverse_message(start_index,second_half.length()-1,second_half);
    message.clear();
    encrypt(start_index,first_half.length()-1,first_half);
    encrypt(start_index,second_half.length()-1,second_half);
    message+=second_half;
    message+=first_half;
    first_half.clear();
    second_half.clear();
    return;
}
int main(){
    string message;
    cin>>message;
    encrypt(START,message.length()-1,message);
    cout<<message<<endl;
    return 0;
}