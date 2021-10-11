#include <bits/stdc++.h>
using namespace std;

//helper function 2
bool safe(vector<vector<int>> v, int i, int j, int num){
    for (int x=0; x<9; x++)
	{
		if(v[x][j]==num || v[i][x]==num)
			return false;
	}

	for(int m = (i/3)*3; m < ((i/3)*3)+3; m++)
	{
		for(int n = (j/3)*3; n < ((j/3)*3)+3; n++)
		{
			if(v[m][n] == num)
				return false;
		}
	}
	return true;

    }
//helper function 1
bool solve(vector<vector<int>> &v, int i, int j){
    //base case
    if(i==9){
        return true;
    }
    //recursive case 1
    else if(j==9){
        return solve(v,i+1,0);
    }
    //recursive case 2
    else if(v[i][j]==0){
        for(int num=1; num<=9; num++){
            if(safe(v,i,j,num)){
               v[i][j]=num;
               if(solve(v,i,j+1)){
                   return true;
               }
            }
        }
        v[i][j]=0;
        return false;
    }
    //recursive case 3
    else{
       return solve(v,i,j+1);
    }

}

//template function
vector<vector<int> > solveSudoku(vector<vector<int>> input){
    
    solve(input, 0,0);
    return input;
    
}