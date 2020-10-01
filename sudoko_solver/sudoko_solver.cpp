#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

vector<int> sudo[9][9],t[9][9];
vector<int> row,col;

void removerow(int i, int k);
void removecol(int j, int k);
void removebox(int i, int j, int k);

void printsudo()
{
    int x=0;
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            for(int k=0; k<sudo[i][j].size(); k++)
            {
                cout<<sudo[i][j][k]<<",";
                x++;
            }
            cout<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
    //getch();
}

int checkrow(int i, int k)
{
    int x=0;
    //cout<<"DEBUG6"<<endl;
    for(int j=0; j<9; j++)
    {
        if(sudo[i][j].size()==1&&sudo[i][j][0]==k)
        {
            x++;
        }
    }
    //if(x!=0) cout<<"checkrow"<<i<<k<<endl;
    return x;
}

int checkcol(int j, int k)
{
    int x=0;
    //cout<<"DEBUG7"<<endl;
    for(int i=0; i<9; i++)
    {
        if(sudo[i][j].size()==1&&sudo[i][j][0]==k)
        {
            x++;;
        }
    }
    //if(x!=0) cout<<"checkcol"<<j<<k<<endl;
    return x;
}

int checkbox(int i,int j,int k)
{
    //cout<<"DEBUG8"<<endl;
    int x,y,p,q;
    int c=0;
    if(i>=0&&i<=2)
        y=0;
    else if(i>=3&&i<=5)
        y=3;
    else if(i>=6&&i<=8)
        y=6;

    if(j>=0&&j<=2)
        x=0;
    else if(j>=3&&j<=5)
        x=3;
    else if(j>=6&&j<=8)
        x=6;

    for(p=y; p<y+3; p++)
    {
        for(q=x; q<x+3; q++)
        {
            if(sudo[p][q].size()==1&&sudo[p][q][0]==k)
            {
                c++;
            }
        }
    }
    //if(c!=0) cout<<"checkbox"<<i<<j<<k<<endl;
    return c;
}

void removerow(int i, int k)
{
    for(int j=0; j<9; j++)
    {
        if(sudo[i][j].size()==1)
        {
            continue;
        }

        else if(sudo[i][j].size()!=1)
        {
            if(find(sudo[i][j].begin(),sudo[i][j].end(),k)!=sudo[i][j].end())
            {
                sudo[i][j].erase(find(sudo[i][j].begin(),sudo[i][j].end(),k));
                //cout<<"removerow"<<i<<" "<<j<<" "<<k<<endl;
            }

            if(sudo[i][j].size()==1)
            {
                removerow(i,sudo[i][j][0]);
                removecol(j,sudo[i][j][0]);
                removebox(i,j,sudo[i][j][0]);
            }
        }
    }
}

void removecol(int j, int k)
{
    for(int i=0; i<9; i++)
    {
        if(sudo[i][j].size()==1)
        {
            continue;
        }

        else if(sudo[i][j].size()!=1)
        {
            if(find(sudo[i][j].begin(),sudo[i][j].end(),k)!=sudo[i][j].end())
            {
                sudo[i][j].erase(find(sudo[i][j].begin(),sudo[i][j].end(),k));
                //cout<<"removecol"<<i<<" "<<j<<" "<<k<<endl;
            }

            if(sudo[i][j].size()==1)
            {
                removerow(i,sudo[i][j][0]);
                removecol(j,sudo[i][j][0]);
                removebox(i,j,sudo[i][j][0]);
            }
        }
    }
}

void removebox(int i, int j, int k)
{
    int x,y,p,q;

    if(i>=0&&i<=2)
        y=0;
    else if(i>=3&&i<=5)
        y=3;
    else if(i>=6&&i<=8)
        y=6;

    if(j>=0&&j<=2)
        x=0;
    else if(j>=3&&j<=5)
        x=3;
    else if(j>=6&&j<=8)
        x=6;

    for(i=y; i<y+3; i++)
    {
        for(j=x; j<x+3; j++)
        {
            if(sudo[i][j].size()==1)
            {
                continue;
            }

            else if(sudo[i][j].size()!=1)
            {
                if(find(sudo[i][j].begin(),sudo[i][j].end(),k)!=sudo[i][j].end())
                {
                    sudo[i][j].erase(find(sudo[i][j].begin(),sudo[i][j].end(),k));
                    //cout<<"removebox"<<i<<" "<<j<<" "<<k<<endl;
                }

                if(sudo[i][j].size()==1)
                {
                    removerow(i,sudo[i][j][0]);
                    removecol(j,sudo[i][j][0]);
                    removebox(i,j,sudo[i][j][0]);
                }
            }
        }
    }
}

int f(int i,int j,int k)
{
    for(int x=0;x<t[i][j].size();x++)
    {
        if(t[i][j][x]>k)
        {
            if(!(checkrow(i,t[i][j][x])||checkcol(j,t[i][j][x])||checkbox(i,j,t[i][j][x])))
            {
                return t[i][j][x];
            }
        }
    }
    return 0;
}

void check()
{
    cout<<"CHECKING"<<endl;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            for(int k=1;k<=9;k++)
            {
                if(checkrow(i,k)!=1||checkcol(j,k)!=1||checkbox(i,j,k)!=1)
                {
                    cout<<"WRONG"<<endl;
                }
            }
        }
    }
    cout<<"CORRECT"<<endl;
}

int main()
{
    int temp;
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            cin>>temp;
            if(temp!=0)
            {
                sudo[i][j].push_back(temp);
            }
        }
    }
    //filling possibilities
    //cout<<"DEBUG1"<<endl;
    int h=1;
    while(h--)
    {
        for(int i=0; i<9; i++)
        {
            //cout<<"DEBUG2"<<endl;
            for(int j=0; j<9; j++)
            {
                //cout<<"DEBUG3"<<endl;
                if(sudo[i][j].size()==1)
                {
                    continue;
                }

                //cout<<"DEBUG4"<<endl;
                for(int k=1; k<=9; k++)
                {
                    if(!(checkrow(i,k)||checkcol(j,k)||checkbox(i,j,k)))
                    {
                        sudo[i][j].push_back(k);
                    }
                }
                //cout<<"DEBUG5"<<endl;
                sort(sudo[i][j].begin(),sudo[i][j].end());

                if(sudo[i][j].size()==1)
                {
                    removerow(i,sudo[i][j][0]);
                    removecol(j,sudo[i][j][0]);
                    removebox(i,j,sudo[i][j][0]);
                }
            }
        }
    }

    //printsudo();

    vector<int>::iterator itr;
    int x=0,y=0,z=0,flag=0;
    while(1)
    {
        //cout<<"DEBUG9"<<endl;
        flag=0;
        for(int i=0;i<9;i++)
        {
            for(int k=1;k<=9;k++)
            {
                x=0;
                for(int j=0;j<9;j++)
                {
                    if(sudo[i][j].size()==1)
                    {
                        continue;
                    }
                    itr=find(sudo[i][j].begin(),sudo[i][j].end(),k);
                    if(itr!=sudo[i][j].end())
                    {
                        x++;
                        y=j;
                        z=k;
                    }
                }
                if(x==1)
                {
                    //cout<<"uniquerow"<<i<<" "<<y<<" "<<k<<endl;
                    sudo[i][y].clear();
                    sudo[i][y].push_back(z);
                    removerow(i,sudo[i][y][0]);
                    removecol(y,sudo[i][y][0]);
                    removebox(i,y,sudo[i][y][0]);
                    flag++;
                }
            }
        }

        for(int j=0;j<9;j++)
        {
            for(int k=1;k<=9;k++)
            {
                x=0;
                for(int i=0;i<9;i++)
                {
                    if(sudo[i][j].size()==1)
                    {
                        continue;
                    }
                    itr=find(sudo[i][j].begin(),sudo[i][j].end(),k);
                    if(itr!=sudo[i][j].end())
                    {
                        x++;
                        y=i;
                        z=k;
                    }
                }
                if(x==1)
                {
                    //cout<<"uniquecol"<<y<<" "<<j<<" "<<k<<endl;
                    sudo[y][j].clear();
                    sudo[y][j].push_back(z);
                    removerow(y,sudo[y][j][0]);
                    removecol(j,sudo[y][j][0]);
                    removebox(y,j,sudo[y][j][0]);
                    flag++;
                }
            }
        }

        for(int a=0;a<3;a++)
        {
            for(int b=0;b<3;b++)
            {
                for(int k=1;k<=9;k++)
                {
                    x=0;
                    for(int i=3*a;i<3*a+3;i++)
                    {
                        for(int j=3*b;j<3*b+3;j++)
                        {
                            if(sudo[i][j].size()==1)
                            {
                                continue;
                            }
                            itr=find(sudo[i][j].begin(),sudo[i][j].end(),k);
                            if(itr!=sudo[i][j].end())
                            {
                                x++;
                                y=i;
                                z=j;
                            }
                        }
                    }
                    if(x==1)
                    {
                        //cout<<"uniquebox"<<y<<" "<<z<<" "<<k<<endl;
                        sudo[y][z].clear();
                        sudo[y][z].push_back(k);
                        removerow(y,sudo[y][z][0]);
                        removecol(z,sudo[y][z][0]);
                        removebox(y,z,sudo[y][z][0]);
                        flag++;
                    }
                }
            }
        }
        //cout<<flag<<endl;
        if(flag==0)
            break;
    }

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            for(int k=0;k<sudo[i][j].size();k++)
            {
                t[i][j].push_back(sudo[i][j][k]);
            }
        }
    }

    //printsudo();

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(sudo[i][j].size()>1)
            {
                col.push_back(j);
                row.push_back(i);
                //cout<<endl;
                sudo[i][j].clear();
                sudo[i][j].push_back(0);
            }
        }
    }

    if(row.size()==0&&col.size()==0)
    {
        printsudo();
        return 0;
    }

    int p=0;
    int i=row[p],j=col[p];
    do
    {
        i=row[p];
        j=col[p];
        sudo[i][j].push_back(f(i,j,sudo[i][j][0]));
        sudo[i][j].erase(sudo[i][j].begin());

        if(sudo[i][j][0]==0)
        {
            p--;
        }
        else
            p++;
    }while(p!=row.size());

    check();
    printsudo();

    return 0;
}
