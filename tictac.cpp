#include<iostream>
#include<string>
using namespace std;
void initializearr(string arr[][3],int len)
{
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            arr[i][j]="-";
        }
    }
}
void gamerules()
{
    cout<<"Hello Welcome to the tic-tac game,"
    "you will be playing a simple tic-tac game\n"
    "where player 1 will use X and player 2 will use O\n";
}
void printarr(string arr[][3],int len)
{
    for(int i=0;i<len;i++)
    {
        //cout<<" ";
        for(int j=0;j<len;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
void assignandcheck(string arr[][3],int len,int x)
{
    while(x>9)
    {
        cout<<"Number must be in the range of 1 to 9: ";
        cin>>x;
    }

    bool test=false;
    int y;
    x--;
    if(x>=0 && x<=2){
     y=0;
    }
    else if(x>=3 && x<=5)
    y=1;
    else if(x>=6 && x<=8)
    y=2;

    while(test!=true)
    {
        if(arr[y][x%3]=="-")
        {
            arr[y][x%3]="X";
            test=true;
        }
        else
        {
            cout<<"Position already assigned by player,"
            "please enter another position: ";
            cin>>x;
            x--;
            if(x>=0 && x<=2)
                y=0;
        else if(x>=3 && x<=5)
              y=1;
       else if(x>=6 && x<=8)
             y=2;
        }
    }
}
void assignandcheck2(string arr[][3],int len,int x)
{
    while(x>9)
    {
        cout<<"Number must be in the range of 1 to 9: ";
        cin>>x;
    }

    bool test=false;
    int y;
    x--;
    if(x>=0 && x<=2){
     y=0;
    }
    else if(x>=3 && x<=5)
    y=1;
    else if(x>=6 && x<=8)
    y=2;

    while(test!=true)
    {
        if(arr[y][x%3]=="-")
        {
            arr[y][x%3]="O";
            test=true;
        }
        else
        {
            cout<<"Position already assigned by player,"
            "please enter another position: ";
            cin>>x;
            x--;
            if(x>=0 && x<=2)
                y=0;
        else if(x>=3 && x<=5)
              y=1;
       else if(x>=6 && x<=8)
             y=2;
        }
    }
}
bool  checkplayer1win(string arr[][3],int len)
{
    //if(arr[0][0]=="X" && arr[0][1]=="X" && arr[0][2]=="X")
        //return true;

    bool checker=true;

    if(arr[0][0]=="X" && arr[1][1]=="X" && arr[2][2]=="X")
        return true;

    if(arr[0][2]=="X" && arr[1][1]=="X" && arr[2][0]=="X")
        return true;

    for(int i=0;i<len;i++)
    {
        checker=true;
        for(int j=0;j<len;j++)
        {
            if(arr[i][j]!="X"){
                checker=false;

            }


        }
        if(checker==true)
            break;

    }

    if(checker==true)
        return checker;

    for(int i=0;i<len;i++)
    {
        checker=true;
        for(int j=0;j<len;j++)
        {
            if(arr[j][i]!="X"){
                checker=false;

            }


        }
        if(checker==true)
            break;

    }
    //cout<<checker<<endl;

    return checker;

}
bool  checkplayer2win(string arr[][3],int len)
{
    //if(arr[0][0]=="X" && arr[0][1]=="X" && arr[0][2]=="X")
        //return true;

    bool checker=true;

    if(arr[0][0]=="O" && arr[1][1]=="O" && arr[2][2]=="O")
        return true;

    if(arr[0][2]=="O" && arr[1][1]=="O" && arr[2][0]=="O")
        return true;

    for(int i=0;i<len;i++)
    {
        checker=true;
        for(int j=0;j<len;j++)
        {
            if(arr[i][j]!="O"){
                checker=false;

            }


        }
        if(checker==true)
            break;

    }

    if(checker==true)
        return checker;

    for(int i=0;i<len;i++)
    {
        checker=true;
        for(int j=0;j<len;j++)
        {
            if(arr[j][i]!="O"){
                checker=false;

            }


        }
        if(checker==true)
            break;

    }
    //cout<<checker<<endl;

    return checker;

}
bool drawcheck(int count,bool player1win,bool player2win)
{
    if(count==8 && player1win==false && player2win==false)
            return true;

    return false;
}
int main()
{

    string arr[3][3];
    int len=sizeof(arr)/sizeof(arr[0]);

    //Initialize
    initializearr(arr,len);

    gamerules();
    printarr(arr,len);

    int count=0;
    int totalgame=1;
    int totaldraws=0;
    int x;
    bool player1win=false;
    bool player2win=false;
    bool draw=false;
    int player1wincount=0;
    int player2wincount=0;

    while(count<9 && player1win!=true && player2win!=true)
    {
      if(count%2==0){
        cout<<"Enter player 1, choose your assigned position: ";
        cin>>x;

       assignandcheck(arr,len,x);
        }
      else{
        cout<<"Enter player 2, choose your assigned position: ";
        cin>>x;

       assignandcheck2(arr,len,x);
      }

       player1win=checkplayer1win(arr,len);
       player2win=checkplayer2win(arr,len);
       if(player1win){
        cout<<"-----Player1 wins-------"<<endl;
        player1wincount++;
       }

       if(player2win){
        cout<<"-----Player2 wins-------"<<endl;
        player2wincount++;
       }

      draw=drawcheck(count,player1win,player2win);

      if(draw)
      {
          cout<<"----DRAW----"<<endl;
          totaldraws++;
      }


       printarr(arr,len);

       if(draw || player1win || player2win)
       {
           string answer;
           cout<<"Would you like to play another game? Type yes or y to play another game: ";
           cin.ignore();//get rid of those extra characters before using getline().
           getline(cin,answer);

           if(answer=="yes" || answer=="y"){
            cout<<"Lets GOOOO!!"<<endl;
            draw=false;
            player1win=false;
            player2win=false;
            count=-1;//needs to be -1 since the count++ will make it zero
            initializearr(arr,len);// Need to initialize the array again to all "-" sign
            totalgame++;
           }
       }

        count++;


    }

    cout<<endl;
    cout<<"----GAME STATS----"<<endl;
    cout<<"Total games played: "<<totalgame<<endl;
    cout<<"Total number of times player 1 won: "<<player1wincount<<endl;
    cout<<"Total number of times player 2 won: "<<player2wincount<<endl;
    cout<<"Total number of draws: "<<totaldraws<<endl;
    cout<<"Percantage of player 1 win: "<<(float(player1wincount)/totalgame)*100<<endl;
    cout<<"Percantage of player 2 win: "<<(float(player2wincount)/totalgame)*100<<endl;


}
