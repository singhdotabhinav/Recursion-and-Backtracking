Video Explanation Link
https://www.youtube.com/watch?v=uyetDh-DyDg&list=PL-Jc9J83PIiHO9SQ6lxGuDsZNt2mkHEn0&ab_channel=Pepcoding
#include <bits/stdc++.h>

using namespace std;



const int M = 9;
const int N = 9;
//Check for the position to be valid
bool isValid(int board[M][M], int x, int y, int val){

   //Check for that particular row
   for(int j=0;j<M;j++){
    if(board[x][j]==val)
        return false;
   }
   
   //Check for that particular row
   for(int i=0;i<M;i++){
    if(board[i][y]==val)
        return false;
   }
   
   //Find tip or the sub matrix
   int smi=(x/3)*3;
   int smj=(y/3)*3;
   
   //Check for that particular sub matrix
   for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        if(board[smi+i][smj+j]==val)
            return false;
    }
   }
   //Return true otherwise
   return true;

}


void print(int arr[M][M])
{
    for (int i = 0; i < M; i++)
{
   for (int j = 0; j < M; j++)
   {
      cout << arr[i][j] << " ";
   }

   // Newline for new row
   cout << endl;
}
}

void sudoku(int board[M][M] , int i, int j){

   //If i reaches end of matrix
    if(i==M){
        print(board);
        return;
    }
    
    int ni=0, nj=0;                             //Initialize next i and next j
    
    
    if(j==M-1){                                 //If j reaches end of any row increment i and point j to 0
        ni=i+1;
        nj=0;

    }else{                                      //Else increment j and make i as it is
        //cout<<"jjsd   ";
        ni=i;
        nj=j+1;
    }
    
    if(board[i][j]!=0){                         //If board value is not equal to zero    
        sudoku(board,ni,nj);                    //Solve sudoku for next number
    }else{
        for(int po=1;po<=9;po++){               //Possible outcome may lie between 1 to 9 
         
            if(isValid(board,i,j,po)==true){    //Check for validity of that number 
                board[i][j]=po;                 //Put that number 
                sudoku(board, ni,nj);           //Call for next i and j
                board[i][j]=0;                  //Backtrack
            }
        }
    }
}


int main()
{
    int arr[9][9] = {   {3, 0, 6, 5, 0, 8, 4, 0, 0},
                        {5, 2, 0, 0, 0, 0, 0, 0, 0},
                        {0, 8, 7, 0, 0, 0, 0, 3, 1},
                        {0, 0, 3, 0, 1, 0, 0, 8, 0},
                        {9, 0, 0, 8, 6, 3, 0, 0, 5},
                        {0, 5, 0, 0, 9, 0, 6, 0, 0},
                        {1, 3, 0, 0, 0, 0, 2, 5, 0},
                        {0, 0, 0, 0, 0, 0, 0, 7, 4},
                        {0, 0, 5, 2, 0, 6, 3, 0, 0}
                    };
 
    sudoku(arr,0,0);
    
    return 0;
}
