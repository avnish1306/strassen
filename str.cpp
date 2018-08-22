#include<iostream>

typedef struct matrix{
    int n;
    float mat[16][16];
}mati;

using namespace std;

mati MatAdd(mati a,mati b,int n1){
    mati r;
    int i,j;
    r.n=n1;
    int s=n1;
    for(i=0;i<s;i++){
        for(j=0;j<s;j++){
            r.mat[i][j]=a.mat[i][j]+b.mat[i][j];
        }
    }
    return r;

}

mati strassen(mati a,mati b,int n1){
    if(n1==2){
        float m1=(a.mat[0][0]+a.mat[1][0])*(b.mat[0][0]+b.mat[0][1]);
        float m2=(a.mat[0][1]+a.mat[1][1])*(b.mat[1][0]+b.mat[1][1]);
        float m3=(a.mat[0][0]-a.mat[1][1])*(b.mat[0][0]+b.mat[1][1]);
        float m4=a.mat[0][0]*(b.mat[0][1]-b.mat[1][1]);
        float m5=(a.mat[1][0]+a.mat[1][1])*b.mat[0][0];
        float m6=(a.mat[0][0]+a.mat[0][1])*b.mat[1][1];
        float m7=a.mat[1][1]*(b.mat[1][0]-b.mat[0][0]);
        mati r;
        r.n=2;
        r.mat[0][0]=m2+m3-m6-m7;
        r.mat[0][1]=m4+m6;
        r.mat[1][0]=m5+m7;
        r.mat[1][1]=m1-m3-m4-m5;
        return r;

    }
    int k=(a.n)/2;
    int i,j;
    mati A,B,C,D,  E,F,G,H,  I,J,K,L;
    A.n=B.n=C.n=D.n=E.n=F.n=G.n=H.n=k;
    for(i=0;i<k;i++){
        for(j=0;j<k;j++){
            A.mat[i][j]=a.mat[i][j];
            E.mat[i][j]=b.mat[i][j];
            B.mat[i][j]=a.mat[i][k+j];
            F.mat[i][j]=b.mat[i][k+j];
            C.mat[i][j]=a.mat[k+i][j];
            G.mat[i][j]=b.mat[k+i][j];
            D.mat[i][j]=a.mat[k+i][k+j];
            H.mat[i][j]=b.mat[k+i][k+j];
        }
    }
    I=MatAdd(strassen(A,E,k),strassen(B,G,k),k);
    J=MatAdd(strassen(A,F,k),strassen(B,H,k),k);
    K=MatAdd(strassen(C,E,k),strassen(D,G,k),k);
    L=MatAdd(strassen(C,F,k),strassen(D,H,k),k);
    mati res;
    res.n=a.n;
    for(i=0;i<k;i++){
        for(j=0;j<k;j++){
            res.mat[i][j]=I.mat[i][j];
            res.mat[i][k+j]=J.mat[i][j];
            res.mat[k+i][j]=K.mat[i][j];
            res.mat[k+i][k+j]=L.mat[i][j];
        }
    }

    
    
    return res;
    


}

int main()
{
    int r,m,i,j;
    cin>>r;
    cin>>m;
    int k;
    if(r>4||m>4)
        k=8;
    else if(r>2||m>2)
        k=4;
    else
        k=2;
    
    mati a,b;
    a.n=k;
    b.n=k;
    for(i=0;i<k;i++){
        for(j=0;j<k;j++){
            if(j<m&&i<r){
                cin>>a.mat[i][j];
            }else
            a.mat[i][j]=0;
        }
    }
    cout<<"\nmatrix 2"<<endl;
    for(i=0;i<k;i++){
        for(j=0;j<k;j++){
            if(j<m&&i<r){
                cin>>b.mat[i][j];
            }else
            b.mat[i][j]=0;
        }
    }
    mati res=strassen(a,b,k);
    for(i=0;i<k;i++){
        for(j=0;j<k;j++){
            cout<<res.mat[i][j]<<" ";
        }
        cout<<endl;
    }


    


    return 0;
}

