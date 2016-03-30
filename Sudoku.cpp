#include<iostream>
#include<ctime>
#include<stdlib.h>
#include"Sudoku.h"
using namespace std;

int data[9][9];
void Sudoku::giveQuestion(){
	int array[9][9]={{0,2,1,0,6,0,5,9,0},
					{0,0,0,0,0,0,0,0,2},
					{4,0,0,2,0,5,0,6,3},
					{3,0,7,6,0,0,0,0,0},
					{0,9,5,0,0,0,3,2,0},
					{0,0,0,0,0,3,7,0,1},
					{9,3,0,4,0,2,0,0,7},
					{5,0,0,0,0,0,0,0,0},
					{0,1,2,0,9,0,6,3,0}};
}

void Sudoku::readIn(){
	int i,j;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			cin>>data[i][j];
		}
	}
	cout<<endl;
}



void Sudoku::change(){
	srand(time(NULL));
	changeNum(rand()%9 + 1, rand()%9 + 1);
    changeRow(rand()%3,rand()%3);
	changeCol(rand()%3,rand()%3);
	rotate(rand()%101);
	flip(rand()%2);
}

void Sudoku::changeNum(int a, int b){
	int i,j;
	int data[9][9]={{0,2,1,0,6,0,5,9,0},
					{0,0,0,0,0,0,0,0,2},
					{4,0,0,2,0,5,0,6,3},
					{3,0,7,6,0,0,0,0,0},
					{0,9,5,0,0,0,3,2,0},
					{0,0,0,0,0,3,7,0,1},
					{9,3,0,4,0,2,0,0,7},
					{5,0,0,0,0,0,0,0,0},
					{0,1,2,0,9,0,6,3,0}};
					
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			if(data[i][j] == a){
				data[i][j] = b;
			}
			else if(data[i][j] == b){
				data[i][j] = a;
			}
			cout<<data[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

void Sudoku::changeRow(int a, int b){
	int i,j;
	int data1[9][9]={{0,2,1,0,6,0,5,9,0},{0,0,0,0,0,0,0,0,2},{4,0,0,2,0,5,0,6,3},{3,0,7,6,0,0,0,0,0},{0,9,5,0,0,0,3,2,0},{0,0,0,0,0,3,7,0,1},{9,3,0,4,0,2,0,0,7},{5,0,0,0,0,0,0,0,0},{0,1,2,0,9,0,6,3,0}};
	int data2[9][9]={{0,2,1,0,6,0,5,9,0},{0,0,0,0,0,0,0,0,2},{4,0,0,2,0,5,0,6,3},{3,0,7,6,0,0,0,0,0},{0,9,5,0,0,0,3,2,0},{0,0,0,0,0,3,7,0,1},{9,3,0,4,0,2,0,0,7},{5,0,0,0,0,0,0,0,0},{0,1,2,0,9,0,6,3,0}};
	
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			if((a == 0 && b == 1 ) || ( b == 0 && a == 1)){
				data1[0][j] = data2[3][j];
				data1[3][j] = data2[0][j];
				
				data1[1][j] = data2[4][j];
				data1[4][j] = data2[1][j];
				
				data1[2][j] = data2[5][j];
				data1[5][j] = data2[2][j];
			}
			else if((a == 0 && b == 2) || (a == 2 && b == 0)){
				data1[0][j] = data2[6][j];
				data1[6][j] = data2[0][j];
				
				data1[1][j] = data2[7][j];
				data1[7][j] = data2[1][j];
				
				data1[2][j] = data2[8][j];
				data1[8][j] = data2[2][j];
			}
			else if((a == 1 && b == 2) || (a == 2 && b == 1)){
				data1[3][j] = data2[6][j];
				data1[6][j] = data2[3][j];
				
				data1[4][j] = data2[7][j];
				data1[7][j] = data2[4][j];
				
				data1[5][j] = data2[8][j];
				data1[8][j] = data2[5][j];
			}
			cout<<data1[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	
} 

void Sudoku::changeCol(int a, int b){
	int i,j;
	int data1[9][9]={{0,2,1,0,6,0,5,9,0},{0,0,0,0,0,0,0,0,2},{4,0,0,2,0,5,0,6,3},{3,0,7,6,0,0,0,0,0},{0,9,5,0,0,0,3,2,0},{0,0,0,0,0,3,7,0,1},{9,3,0,4,0,2,0,0,7},{5,0,0,0,0,0,0,0,0},{0,1,2,0,9,0,6,3,0}};
	int data2[9][9]={{0,2,1,0,6,0,5,9,0},{0,0,0,0,0,0,0,0,2},{4,0,0,2,0,5,0,6,3},{3,0,7,6,0,0,0,0,0},{0,9,5,0,0,0,3,2,0},{0,0,0,0,0,3,7,0,1},{9,3,0,4,0,2,0,0,7},{5,0,0,0,0,0,0,0,0},{0,1,2,0,9,0,6,3,0}};
	
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			if((a == 0 && b == 1) || (b == 0 && a == 1)){
				data1[i][0] = data2[i][3];
				data1[i][3] = data2[i][0];
				
				data1[i][1] = data2[i][4];
				data1[i][4] = data2[i][1];
				
				data1[i][2] = data2[i][5];
				data1[i][5] = data2[i][2];
			}
			else if((a == 0 && b == 2) || (a == 2 && b == 0)){
				data1[i][0] = data2[i][6];
				data1[i][6] = data2[i][0];
				
				data1[i][1] = data2[i][7];
				data1[i][7] = data2[i][1];
				
				data1[i][2] = data2[i][8];
				data1[i][8] = data2[i][2];
			}
			else if((a == 1 && b == 2) || (a == 2 && b == 1)){
				data1[i][3] = data2[i][6];
				data1[i][6] = data2[i][3];
				
				data1[i][4] = data2[i][7];
				data1[i][7] = data2[i][4];
				
				data1[i][5] = data2[i][8];
				data1[i][8] = data2[i][5];
			}
			cout<<data1[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
	 

void Sudoku::rotate(int n){
	int i,j;
	int data1[9][9]={{0,2,1,0,6,0,5,9,0},{0,0,0,0,0,0,0,0,2},{4,0,0,2,0,5,0,6,3},{3,0,7,6,0,0,0,0,0},{0,9,5,0,0,0,3,2,0},{0,0,0,0,0,3,7,0,1},{9,3,0,4,0,2,0,0,7},{5,0,0,0,0,0,0,0,0},{0,1,2,0,9,0,6,3,0}};
	
	if(n%4 == 0){
		for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				cout<<data1[i][j]<<" ";
			}
		cout<<endl;
		}
	}
	else if(n%4 == 1){
		for(j=0;j<9;j++){
			for(i=8;i>=0;i--){
				cout<<data1[i][j]<<" ";
			}
		cout<<endl;
		}
	}
	else if(n%4 == 2){
		for(i=8;i>=0;i--){
			for(j=8;j>=0;j--){
				cout<<data1[i][j]<<" ";
			}
		cout<<endl;
		}
	}
	else if(n%4 == 3){
		for(j=8;j>=0;j--){
			for(i=0;i<9;i++){
				cout<<data1[i][j]<<" ";
			}
		cout<<endl;
		}
	}
	cout<<endl;
	
} 

void Sudoku::flip(int n){
	int i,j;
	int data1[9][9]={{0,2,1,0,6,0,5,9,0},{0,0,0,0,0,0,0,0,2},{4,0,0,2,0,5,0,6,3},{3,0,7,6,0,0,0,0,0},{0,9,5,0,0,0,3,2,0},{0,0,0,0,0,3,7,0,1},{9,3,0,4,0,2,0,0,7},{5,0,0,0,0,0,0,0,0},{0,1,2,0,9,0,6,3,0}};
	int data2[9][9]={{0,2,1,0,6,0,5,9,0},{0,0,0,0,0,0,0,0,2},{4,0,0,2,0,5,0,6,3},{3,0,7,6,0,0,0,0,0},{0,9,5,0,0,0,3,2,0},{0,0,0,0,0,3,7,0,1},{9,3,0,4,0,2,0,0,7},{5,0,0,0,0,0,0,0,0},{0,1,2,0,9,0,6,3,0}};
	
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			if(n == 0){
				data1[0][j] = data2[8][j];
				data1[8][j] = data2[0][j];
				
				data1[1][j] = data2[7][j];
				data1[7][j] = data2[1][j];
				
				data1[2][j] = data2[6][j];
				data1[6][j] = data2[2][j];
				
				data1[3][j] = data2[5][j];
				data1[5][j] = data2[3][j];
			}
			else if(n == 1){
				data1[i][0] = data2[i][8];
				data1[i][8] = data2[i][0];
				
				data1[i][1] = data2[i][7];
				data1[i][7] = data2[i][1];
				
				data1[i][2] = data2[i][6];
				data1[i][6] = data2[i][2];
				
				data1[i][3] = data2[i][5];
				data1[i][5] = data2[i][3];
			}
			cout<<data1[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
} 




void Sudoku::transform(){
	readIn();
	change();
}




int map[90][10];

void Sudoku::solve(){
	int i,j,m,s,k,g,check,limit=0,count,error,go,num,t;
	int alt[90][10]={0};
	int array[9];
	
	for(i=1;i<90;i++){
		for(j=0;j<10;j++){
			map[i][j]=j;
		}
	}
	for(i=0;i<9;i++){//刪掉題目有的數字 
		for(j=0;j<9;j++){
			if(data[i][j]!=0){
				map[10*i+j+1][0]=data[i][j];
				for(m=1;m<10;m++){
					map[10*i+j+1][m]=0;
				}
			}
		}
	}
	for(go=0;go<10000;go++){
		for(k=0;k<30;k++){
			for(i=1;i<90;i++){//刪掉列 
				if(map[i][0]!=0){
					for(j=i/10*10+1;j<i/10*10+10;j++){
						map[j][map[i][0]]=0;
					}
				}
			}
			for(i=1;i<90;i++){//刪掉行 
				if(map[i][0]!=0){
					for(j=i%10;j<i%10+81;j+=10){
						map[j][map[i][0]]=0;
					}
				}
			}
			for(i=0;i<21;i+=10){//刪掉方格 1 
				for(j=i+1;j<i+4;j++){
					if(map[j][0]!=0){
						for(m=0;m<21;m+=10){
							for(s=m+1;s<m+4;s++){
								map[s][map[j][0]]=0;
							}
						}
					}
				}
			}
			for(i=3;i<24;i+=10){//刪掉方格 2 
				for(j=i+1;j<i+4;j++){
					if(map[j][0]!=0){
						for(m=3;m<24;m+=10){
							for(s=m+1;s<m+4;s++){
								map[s][map[j][0]]=0;
							}
						}
					}
				}
			}
			for(i=6;i<27;i+=10){//刪掉方格 3 
				for(j=i+1;j<i+4;j++){
					if(map[j][0]!=0){
						for(m=6;m<27;m+=10){
							for(s=m+1;s<m+4;s++){
								map[s][map[j][0]]=0;
							}
						}
					}
				}
			}
			for(i=30;i<51;i+=10){//刪掉方格 4 
				for(j=i+1;j<i+4;j++){
					if(map[j][0]!=0){
						for(m=30;m<51;m+=10){
							for(s=m+1;s<m+4;s++){
								map[s][map[j][0]]=0;
							}
						}
					}
				}
			}
			for(i=33;i<54;i+=10){//刪掉方格 5 
				for(j=i+1;j<i+4;j++){
					if(map[j][0]!=0){
						for(m=33;m<54;m+=10){
							for(s=m+1;s<m+4;s++){
								map[s][map[j][0]]=0;
							}
						}
					}
				}
			}
			for(i=36;i<57;i+=10){//刪掉方格 6 
				for(j=i+1;j<i+4;j++){
					if(map[j][0]!=0){
						for(m=36;m<57;m+=10){
							for(s=m+1;s<m+4;s++){
								map[s][map[j][0]]=0;
							}
						}
					}
				}
			}
			for(i=60;i<81;i+=10){//刪掉方格 7 
				for(j=i+1;j<i+4;j++){
					if(map[j][0]!=0){
						for(m=60;m<81;m+=10){
							for(s=m+1;s<m+4;s++){
								map[s][map[j][0]]=0;
							}
						}
					}
				}
			}
			for(i=63;i<84;i+=10){//刪掉方格 8 
				for(j=i+1;j<i+4;j++){
					if(map[j][0]!=0){
						for(m=63;m<84;m+=10){
							for(s=m+1;s<m+4;s++){
								map[s][map[j][0]]=0;
							}
						}
					}
				}
			}
			for(i=66;i<87;i+=10){//刪掉方格 9 
				for(j=i+1;j<i+4;j++){
					if(map[j][0]!=0){
						for(m=66;m<87;m+=10){
							for(s=m+1;s<m+4;s++){
								map[s][map[j][0]]=0;
							}
						}
					}
				}
			}
					
			for(m=0;m<90;m+=10){//把唯一解填入 
				for(j=1;j<10;j++){
					check=0;
					for(i=m+1;i<m+10;i++){
						if(map[i][j]==j){
							check++;
						}
					}
					if(check==1){
						for(i=m+1;i<m+10;i++){
							if(map[i][j]!=0){
								map[i][0]=j;
								for(g=1;g<10;g++){
									map[i][g]=0;
								}	
							}
						}
					}
				}	
			}
			for(m=1;m<90;m++){//把唯一解填入 
				if(m%10==0)continue;
				check=0;
				for(i=1;i<10;i++){
					if(map[m][i]==0){
						check++;
					}
				}
				if(check==8)
				for(i=1;i<10;i++){
					if(map[m][i]!=0){
						map[m][0]=i;
						map[m][i]=0;
					}
				}
			}
			for(m=1;m<90;m++){//已確定 削掉 
				if(m%10==0)continue;
				if(map[m][0]!=0){
					for(i=1;i<10;i++){
						map[m][i]=0;
					}
				}
			}
		}
		error=0;
		for(i=0;i<81;i+=10){//重新判斷列 
			for(m=0;m<9;m++){
				array[m]=0;
			}
			for(j=i+1;j<i+10;j++){
				if(map[j][0]==1)array[0]++;	
				if(map[j][0]==2)array[1]++;	
				if(map[j][0]==3)array[2]++;	
				if(map[j][0]==4)array[3]++;	
				if(map[j][0]==5)array[4]++;	
				if(map[j][0]==6)array[5]++;	
				if(map[j][0]==7)array[6]++;	
				if(map[j][0]==8)array[7]++;	
				if(map[j][0]==9)array[8]++;	
			}
			for(s=0;s<9;s++){
				if(array[s]>1){
					error=1;
				}
			}
		}
		for(i=1;i<10;i++){//重新判斷行 
			for(m=0;m<9;m++){
				array[m]=0;
			}
			for(j=i;j<81+i;j+=10){
				if(map[j][0]==1)array[0]++;	
				if(map[j][0]==2)array[1]++;	
				if(map[j][0]==3)array[2]++;	
				if(map[j][0]==4)array[3]++;	
				if(map[j][0]==5)array[4]++;	
				if(map[j][0]==6)array[5]++;	
				if(map[j][0]==7)array[6]++;	
				if(map[j][0]==8)array[7]++;	
				if(map[j][0]==9)array[8]++;	
			}
			for(s=0;s<9;s++){
				if(array[s]>1){
					error=1;
				}
			}
		}
		for(m=0;m<9;m++){
				array[m]=0;
		}
		for(i=1;i<90;i++){//判斷每個數字是否都有九個 
			
			if(i%10==0)continue;
			if(map[i][0]==1)array[0]++;	
			if(map[i][0]==2)array[1]++;	
			if(map[i][0]==3)array[2]++;	
			if(map[i][0]==4)array[3]++;	
			if(map[i][0]==5)array[4]++;	
			if(map[i][0]==6)array[5]++;	
			if(map[i][0]==7)array[6]++;	
			if(map[i][0]==8)array[7]++;	
			if(map[i][0]==9)array[8]++;	
			
		}
		for(s=0;s<9;s++){
				if(array[s]>9){
					error=1;
				}
			}
		for(i=1;i<90;i++)
			{
				if(i%10==0)continue;
				if(map[i][0]==0 && map[i][1]==0 && map[i][2]==0 && map[i][3]==0 && map[i][4]==0 && map[i][5]==0 && map[i][6]==0 && map[i][7]==0 && map[i][8]==0 && map[i][9]==0)
				{
					error=1;
					break;
				}
			}
		if(go==0)
			{
				for(i=1;i<90;i++)
				{
					for(j=0;j<10;j++)
					{
						alt[i][j]=map[i][j];
					}
				}
			}
		if(error==1){
			alt[limit/10][limit%10]=0;
			limit=0;
			for(g=1;g<90;g++){
				if(g%10==0)continue;
				for(s=0;s<10;s++){
					map[g][s]=alt[g][s];
				}
			}
		}
			for(g=1;g<90;g++){
				if(g%10==0)continue;
				for(s=0;s<10;s++){
					map[g][s]=alt[g][s];
				}
			}
		
		count=0;
		for(m=1;m<90;m++){//有兩解 猜測 
			if(m%10==0)continue;
			for(j=1;j<10;j++){
				if(map[m][j]==j){
					if(limit<10*m+j){
						map[m][0]=j;
						limit=10*m+j;
						count=1;
						for(g=1;g<10;g++){
							map[m][g]=0;
						}
						break;
					}
				}
				if(count==1)break;
			}
			if(count==1)break;
		}
		
		for(m=1;m<90;m++){//把唯一解填入 
			if(m%10==0)continue;
			check=0;
			for(i=1;i<10;i++){
				if(map[m][i]==0){
					check++;
				}
			}
			if(check==8)
			for(i=1;i<10;i++){
				if(map[m][i]!=0){
					map[m][0]=i;
					map[m][i]=0;
				}
			}
		}
		for(m=1;m<90;m++){//已確定 削掉 
			if(m%10==0)continue;
			if(map[m][0]!=0){
				for(i=1;i<10;i++){
					map[m][i]=0;
				}
			}
		}
	}
	if(error==1){
		cout<<"0"<<endl;
	}
	if(error==0){
		cout<<"1"<<endl;
	}
	for(m=0;m<90;m+=10){
		for(j=m+1;j<m+10;j++){
			cout<<map[j][0]<<" ";
		}
		cout<<endl;
	}
}


