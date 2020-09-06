#include <bits/stdc++.h>
#include <stdio.h>
#define MAXSIZE 20
using namespace std;

void print(bool board[20][20], int m, int n){

    for(int i=0; i<m; i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j];
        }
        cout<<endl;
    }
}

void solve(bool board[20][20], int m , int n,
        int row,  bool cols[], bool ndiag[], bool rdiag[] ){

            if(row==m){                                                 //Base conditon when row number is equal to size of matrix
                print(board,m,n);
                 cout<<endl;
                return;
           }
            for(int col=0; col<m; col++){                              //We will make a next call row wise, at each row iterate through every column element  

                if( cols[col]==false &&                                //If column array is false
                   ndiag[row+col]==false&&                             //If normal diagonal is false
                   rdiag[row-col+m-1]==false ){                        //If reverse diagonal is false
                     board[row][col]=true;                             //Then place the queen there
                     cols[col]=true;                                   //Make that column value as true
                     ndiag[row+col]=true;                              //Make next diagonal as true
                     rdiag[row-col+m-1]=true;                          //Make reverse diagonal as true
                     solve(board, m, n, row + 1,cols, ndiag, rdiag);   //Make a call to next solve recursion with increased value of row
                     board[row][col]=false;                            //Backtrack 
                     cols[col]=false;                                  //Backtrack
                     ndiag[row+col]=false;                             //Backtrack
                     rdiag[row-col+m-1]=false;                         //Backtrack


                   }
            }


        }

int main()
{


    int m=8,n=8;
    bool cols[n];
    bool board[20][20];
    memset(board,false,sizeof(board));
    bool ndiag[2*n-1];
    bool rdiag[2*n-1];
    string s="";
    solve(board, m, n, 0, cols, ndiag, rdiag);
    //print(board,m,n);
    return 0;
}

