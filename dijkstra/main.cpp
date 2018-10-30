//
//  main.cpp
//  dijkstra
//
//  Created by Pepe Hdez hdez on 10/29/18.
//  Copyright © 2018 Pepe Hdez hdez. All rights reserved.
//

#include <iostream>
#include <stack>
#include <climits>

using namespace std;

#define N 5

void initMatAdj(int mat[N][N]){
    for (int i=0; i<N; i++){
        mat[i][i]=0;
        for(int j=i+1; j<N; j++){
            mat[j][i] = mat[i][j] = INT_MAX;
        }
    }
}
void leeMatAdj(int mat[N][N], int e){
    int a, b, c;
    for (int i=1; i<e; i++){
        cin >> a >> b >> c;
        mat[a-1][b-1] = mat[b-1][a-1] = c;
    }
}

void print(int mat[N][N]){
    cout << endl;
    for (int i = 0; i<N; i++){
        for (int j = 0; j<N; j++){
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
}

void Dijkstra(int W[N][N], int L[N], int T[N], int v){
    bool encontre[N];
    for (int i=0; i<N; i++){
        encontre[i]=false;
    }
    for (int i=0; i<v; i++){
        L[i]=W[0][i];
        T[i]=0;
    }
    for (int i=1; i<v; i++){
        int min=INT_MAX;
        int imin;
        for (int j=1; j<v; j++){
            if (!encontre[j] && L[j]<min){
                min=L[j];
                imin=j;
            }
        }
        for (int j=1; j<v; j++){
            if (W[imin][j] != INT_MAX && L[imin]+W[imin][j] < L[j]){
                L[j]=L[imin]+W[imin][j];
                T[j]=imin;
            }
        }
            encontre[imin]=true;
        }
}

void printMenor(int L[N], int T[N], int v){
    stack<int> miPila;
    for (int i=1; i<v; i++){
        cout << "path: ";
        int b=1;
        miPila.push(i+1);
        while (T[b] != 0){
            miPila.push(T[b]+1);
            b=T[b];
        }
        miPila.push(i);
        while (miPila.size() > 1){
            cout << miPila.top() << "-";
            miPila.pop();
        }
        cout << miPila.top() << ": " << L[i] << endl;
        miPila.pop();
    }
}

int main(){
    int mat[N][N];
    int L[N];
    int T[N];
    int v, e;
    cin >> v >> e;
    initMatAdj(mat);
    leeMatAdj(mat,e);
    print(mat);
    Dijkstra(mat, L, T, v);
    printMenor(L, T, v);
    return 0;
}


/*
 5 8
 1 2 2
 1 3 12
 1 4 10
 2 3 9
 2 5 5
 3 4 6
 3 5 3
 4 5 7
 */
