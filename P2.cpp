#include<iostream>
#include<vector>
#define FIRST_INDEX 0
using namespace std;
int selective_multiplication(vector<int>& numbers,int current_index,int selected_index){
    if(current_index>=numbers.size()){
        return 1;
    }
    if(current_index==selected_index){
        return selective_multiplication(numbers,current_index+1,selected_index);
    }
    return numbers[current_index]*selective_multiplication(numbers,current_index+1,selected_index);
}
void updateArray(vector<int> & numbers,int current_index){
    if(current_index>=numbers.size()){
        return;
    }
    int updated_cell=selective_multiplication(numbers,FIRST_INDEX,current_index);
    updateArray(numbers,current_index+1);
    numbers[current_index]=updated_cell;
    return;
}
void printArray(vector<int> & numbers,int current_index){
    if(current_index>=numbers.size()){
        cout<<endl;
        return;
    }
    cout<< numbers[current_index];
    if(current_index<numbers.size()-1){
        cout<<' ';
    }
    printArray(numbers,current_index + 1);
    return;
}
int main(){
    int number;
    vector<int> numbers;
    while(cin>>number){
        numbers.push_back(number);
    } 
    updateArray(numbers,FIRST_INDEX);
    printArray(numbers,FIRST_INDEX);
    return 0;  
}
