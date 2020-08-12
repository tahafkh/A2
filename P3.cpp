#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;
int max_gold(vector<vector<int>> &map,int i,int j,int max_vert,int max_horiz){
    int cell_value=0,max_value_per_selected_cell=map[i][j];
    for(int delta_i = -1;delta_i<2;delta_i++){
        for(int delta_j = -1;delta_j<2;delta_j++){
            if(abs(delta_i)!=abs(delta_j) && i+delta_i>=0 && j+delta_j>=0){
                if(i+delta_i<max_vert && j+delta_j<max_horiz && map[i+delta_i][j+delta_j]!=0){
                    cell_value=map[i][j];
                    map[i][j]=0;
                    max_value_per_selected_cell=max(max_gold(map,i+delta_i,j+delta_j,max_vert,max_horiz)+cell_value,max_value_per_selected_cell);
                    map[i][j]=cell_value;
                }
            }
        }
    }
    return max_value_per_selected_cell;
}
int main(){
    int m,n,value,max_gold_map=0;
    vector<vector<int>> map;
    vector<int> temp;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>> value;
            temp.push_back(value);
        }
        map.push_back(temp);
        temp.clear();
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            max_gold_map=max(max_gold(map,i,j,m,n),max_gold_map);
        }
    }
    cout<< max_gold_map<<endl;
    return 0;
}
