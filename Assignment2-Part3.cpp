#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int ROW_COUNT = 3;
const int COL_COUNT = 4;
const int POSSIBLE_MOVES = 4;

int row_delta[POSSIBLE_MOVES] = {1,0,-1,0};
int col_delta[POSSIBLE_MOVES] = {0,-1,0,1};

int board[ROW_COUNT][COL_COUNT];

bool print_board(vector <string>map,int row_num,int col_num) {
    for (int i = 0; i < row_num; i++) {
        for (int j = 0; j < col_num; j++) {
            if (map[i][j] < 10)
                cout << ' ';
            cout << map[i][j] << ' ';
        }
        cout << endl;
    }
    cin.get();
}
void time_left_decrease(vector<int>& time_left_map)
{
    for (int i = 0; i < time_left_map.size(); ++i)
    {
        time_left_map[i]++;
    }
}
void time_left_increase(vector<int>& time_left_map)
{
    for (int i = 0; i < time_left_map.size(); ++i)
        {
            time_left_map[i]--;
        }
}
bool find_tour(vector <string>& map,vector <int> fuel_map,vector<int> time_left_map,int move_no, int current_row, int current_col,int row_num,int col_num,vector <int>& result) {
    // uncomment the following two lines for debugging:
    // cout << move_no << endl;
    // print_board();
      
    for (int move = 0; move < POSSIBLE_MOVES; move++) {
        int new_row = current_row + row_delta[move];
        int new_col = current_col + col_delta[move];
        
        if (new_row < 0 || new_row >= row_num || new_col < 0 || new_col >= col_num)
            continue;
            
        if (map[new_row][new_col] == '#' || map[new_row][new_col] == 'R' || map[new_row][new_col] == 'S' )
            continue;
        
        if (map[new_row][new_col]=='$')
        {
            if (time_left_map[(new_row)*col_num+new_col]>=0)
            {
                move_no=move_no-fuel_map[(new_row)*col_num+new_col];
            }
        }
        
        if (map[new_row][new_col]=='E')
        {
            result.push_back(move_no+1);
            continue;
        }
        map[new_row][new_col] = 'R';
        time_left_decrease(time_left_map);
        find_tour(map,fuel_map,time_left_map,move_no + 1, new_row, new_col,row_num,col_num,result);
        map[new_row][new_col] = '.';
        time_left_increase(time_left_map);
    }
    return false;
}
void read_map (vector <string>& map, int row_num)
{
    string input;
    for (int i=0;i<row_num;i++)
    {
        cin >> input;
        map.push_back(input);
    }
}
void read_fuel (vector <string>& map,vector <int>& fuel_map,vector <int>& time_left_map,int row_num,int col_num)
{
    int num_of_fuels,row,col,energy,time_left;
    cin >> num_of_fuels;
    for (int i=0;i<num_of_fuels;i++)
    {
        cin >> row >> col >> energy >> time_left;
        row--;
        col--;
        fuel_map[row*col_num+col]=energy;
        time_left_map[row*col_num+col]=time_left;
    }
}
void find_init_pose (vector <string>& map,int init_pose[],int row_num,int col_num)
{
    for (int i = 0; i < row_num; i++)
    {
        for (int j = 0; j < col_num; j++)
        {
            if (map[i][j]=='S')
            {
                init_pose[0]=i;
                init_pose[1]=j;
            }
        }
    }
}

int main() {
    
    vector <string> map;
    vector <int> result;
    int row_num,col_num,maximom_fuel=0;
    int init_pose [2];
    cin >> row_num >> col_num;
    vector <int> fuel_map (row_num*col_num) ;
    vector <int> time_left_map(row_num*col_num) ;
    read_map(map,row_num);
    read_fuel(map,fuel_map,time_left_map,row_num,col_num);
    find_init_pose(map,init_pose,row_num,col_num);
    // init_pose[0]=init row , init_pose[1]=init col
    find_tour(map,fuel_map,time_left_map,0, init_pose[0], init_pose[1],row_num,col_num,result);
     for (int i = 0; i <result.size() ; ++i)
    {
        if (result[i]>maximom_fuel)
            maximom_fuel=result[i];
    }
    cout << maximom_fuel << endl;
}