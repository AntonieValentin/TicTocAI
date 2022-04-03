#include <bits/stdc++.h>

using namespace std;

int x,y,t,ad,Min,x2,y2;
char a[5][5];

int reguli(char a[5][5]){
    for(int i=1;i<=3;i++){
        if(a[i][1] == a[i][2] && a[i][1] == a[i][3]){
            if(a[i][1] == 'O')
                return 1;
            if(a[i][1] == 'X')
                return -1;
        }
        if(a[1][i] == a[2][i] && a[1][i] == a[3][i]){
            if(a[1][i] == 'O')
                return 1;
            if(a[1][i] == 'X')
                return -1;
        }
    }
    if(a[1][1] == a[2][2] && a[1][1] == a[3][3]){
        if(a[1][1] == 'O')
            return 1;
        if(a[1][1] == 'X')
            return -1;
    }
    if(a[1][3] == a[2][2] && a[1][3] == a[3][1]){
        if(a[1][3] == 'O')
            return 1;
        if(a[1][3] == 'X')
            return -1;
    }

    return 0;
}



int minimax(char a[5][5], bool playermax, int adancime){

    int scor = reguli(a);
    if(scor == 1 || scor == -1)
        return scor;
    if(adancime == 10)
        return 0;
    if(playermax == true && scor == 0){
        int maxeva = -3;
        int eva = 0;
        for(int i=1;i<=3;i++){
            for(int j=1;j<=3;j++){
                if(a[i][j] == '_'){
                    a[i][j] = 'O';
                    eva = minimax(a,false,adancime+1);
                    if(adancime == ad){
                        if(reguli(a) == 1){
                            x2 = i;
                            y2 = j;
                        }
                        if(eva > maxeva){
                            maxeva = eva;
                            x2 = i;
                            y2 = j;
                        }
                    }
                    maxeva = max(maxeva,eva);
                    a[i][j] = '_';
                }
            }
        }
        return maxeva;
    }
    else{
        int mineva = 3;
        int eva = 0;
        for(int i=1;i<=3;i++){
            for(int j=1;j<=3;j++){
                if(a[i][j] == '_'){
                    a[i][j] = 'X';
                    eva = minimax(a,true,adancime+1);
                    mineva = min(mineva,eva);
                    a[i][j] = '_';
                }
            }
        }
        return mineva;
    }
}




int main()
{
for(int i=1;i<=3;i++){
    for(int j=1;j<=3;j++){
        a[i][j] = '_';
    }
}
while(ad <= 9){
cout << "Please enter the coordinates of X: " << '\n';
cin>>x>>y;
a[x][y] = 'X';
ad++;
Min = 3;
x2 = 0;
y2 = 0;
ad++;
int val = minimax(a,true,ad);
a[x2][y2] = 'O';
if(reguli(a) == 1){
    cout << "You lost!" << '\n';
    ad = 11;
}
if(ad == 10){
    cout << "Draw!" << '\n';
}
for(int i=1;i<=3;i++){
    for(int j=1;j<=3;j++){
        cout << a[i][j] << " ";
    }
    cout << '\n';
}

}
    return 0;
}
