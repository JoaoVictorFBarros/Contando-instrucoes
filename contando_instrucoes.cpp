#include <iostream>
#include <random>
#include <time.h>
using namespace std;

int main (){
	setlocale (LC_ALL,"portuguese");
	int n;
	
	cout<<"Digite as dimenções da matriz: ";
	cin>>n;
	int matriz[n][n];
	cout<<"\n\n";
	
	//Gerar matriz
	srand (time(NULL));
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			matriz[i][j] = rand()%100;
			if (matriz[i][j]<10){
				cout<<"0"<<matriz[i][j]<<" ";
			}
			else{
				cout<<matriz[i][j]<<" ";
			}
		}
		cout<<endl;
	}

	
	int x=0, y=0, x2=0, y2=0,valor=0;
	bool e=false, d=false;
	
	cout<<"\n"<<matriz[y][x]<<" -> ";
	
	//Tomada de decisão
	
	while ((x2<n-1) or (y2<n-1)){
		
		if ((x==0) and (y<n-1)){
			if (matriz[y][x+1] >=matriz[y+1][x] and !e){
				x2++;
				d = true;
				e = false;
				//cout<<"a";
			}
			else{
				y2++;
				d = false;
				e = false;
				//cout<<"b";
			}
		}
		else if ((x==n-1) and (y<n-1)){
			if (matriz[y][x-1] >= matriz[y+1][x] and not d){
				x2--;
				e = true;
				d = false;
				//cout<<"c";
			}
			else{
				y2++;
				d = false;
				e = false;
				//cout<<"d";
			}
		}
		if (y==(n-1)){
			x2++;
			d = true;
			e = false;
			//cout<<"e";
		}
		if ((x>0) and (x<n-1) and (y<n-1)){
			if ((matriz[y][x+1] >= matriz[y+1][x]) and (not e) and (matriz[y][x+1]>=matriz[y][x-1] or d)){
				x2++;
				d = true;
				e = false;
				//cout<<"f";
			}
			else if ((matriz[y][x-1] >= matriz[y+1][x]) and (not d) and (matriz[y][x-1]>=matriz[y][x+1] or e)){
				x2--;
				e = true;
				d = false;
				//cout<<"g";
			}
			else{
				y2++;
				d = false;
				e = false;
				//cout<<"h";
			}
			
		}
		
		x = x2;
		y = y2;
		valor = valor + matriz[y2][x2];
		
		cout<<matriz[y2][x2];
		if ( not(x2==n-1 and y2==n-1)){
			cout<<" -> ";
		}
		
	}
	cout<<"\n\nTotal do caminho - Valor: "<<valor<<"\n\n";
	system ("pause");
	return 0;
}
