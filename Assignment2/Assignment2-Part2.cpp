#include <vector>
#include <iostream>
using namespace std;
void perm(vector<vector<int> >* perms,int stage, int index, vector<int> n_perm,vector<int> numbers){
    if (stage == 0){
        (*perms).push_back(n_perm);
        return;
    }
    for (int i = index; i <numbers.size(); i++){
        n_perm.push_back(numbers[i]);
        perm(perms,stage- 1, i + 1,n_perm,numbers);
        n_perm.pop_back();
    }
    return;
}
void print_perms(vector<vector<int> >perms,int n){
    for (int i=0; i < perms.size(); i++){
        for (int j=0;j<n;j++){
            cout <<perms[i][j];
        }
        cout<<endl;
    }
}
int main()
{
    string number;
    int n;
    while (cin>>number)
    {
    cin>>n;
    vector<int> numbers;
    vector<vector<int> > perms; 
    for(int i=0;i<number.size();i++){
        numbers.push_back(number[i]-48);
    }
    vector<int> n_perm;
    perm(&perms,n, 0, n_perm,numbers);
    print_perms(perms,n);
    }
    return 0;
}
