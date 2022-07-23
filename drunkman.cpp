#include<bits/stdc++.h>
#include<cmath>

using namespace std;
#define ll              long long
#define nl              "\n"
#define rep(i,a,b)      for(int i=a;i<b;i++)

void rules()
{
    
    cout << "\n\t\tThe Drunk Man Runs\n";
    cout << "\t- Player has 100 steps.\n";
    cout << "\t- Score is based on the number of steps remaining.\n";
    cout << "\t- Score = Steps remaining * 100.\n";
    cout << "\t- IF you choose to CONTINUE, you lose 200 points each time.\n";
    cout << "\t\tSTARTING........\n\n\n";

}

int drunkmanruns(string x)
{    
  srand(time(0));
   
    char start,choice,decision,again;
    int count=1,stop1=0;
    int score=0;
    int size=30;
  
    int position = size /2;
    
    rules();
    cout<<"Press x to start..."<<nl;
    cin>>start;
    
    if(start=='X'|| start=='x')
    {  
    do
    {   
      
    int stop=100;

    if(decision=='B' || decision=='b' || decision==1)
        {
            position = 15;
            score=0;            
            count=1;
            
        }
        cout<<"ROUND:"<<count<<" Begins..."<<nl<<nl;

    while (stop>0) 
    { 
        
        cout << "Start" ;

        for (int i=0; i<size;i++) 
        {
        if (i == position  ) 
        cout << "*"<<position;

        else cout << " ";
        }
        cout << "Finish" << endl ;
        
        if(stop!=1)
        {
          int move= rand()%3 - 1;
            position = position + move; 
        }

    


    if (position <1) 
    { 
      cout << "\t"<<x <<" could not finish the race!!!" <<nl<<"\t"<<"Still, Thanks for playing."<<"SCORE: 0"<<nl; 
      decision=1;
      cout<<"\t"<<"Do you want to play again (Y for Yes/N for No)";
        cin>>again;
        
       if(again=='Y' || again=='y') 
        {
          
          drunkmanruns(x);
        }  
        else
        {
          return 0;
        } 
    }

    if (position >size-1) 
    {   
        score= stop*100 - count*200;
        cout <<"\t"<< "Yay! "<< x <<" finished the race!!!"<<nl<<"SCORE: "<<score<<nl<<"Thanks for playing."<<nl; 
        cout<<"\t"<<"Do you want to play again (Y for Yes/N for No)"<<nl;
        cin>>again;
        if(again=='Y' || again=='y') 
        { 
          
          drunkmanruns(x);
        }  
        else
        {
          return 0;
        } 
    }

    stop--;

    }
    
    
  
  cout<<nl<<"Do you want to RETRY the run?(Y for Yes/N for No)"<<nl;
  cin>>choice;

  if(choice=='Y' || choice=='y')
  {
    cout<<"Do you want to Start from BEGINNING or CONTINUE from where you left."<<nl;
    cout<<"Type B for BEGINNING"<<nl<<"Type C to CONTINUE"<<nl;
    cin>>decision; 
    rules(); 
  }

  if(decision=='C' || decision=='c' )
  {
    count++;
    
  }


  if(choice=='N' || choice=='n')
  {
    cout<<"Thanks for playing <3";
    return 0;
  }

}while(choice=='Y' || choice=='y');
}



return 0;
}


int main(int argc, char const *argv[])
{   
  
  string x;
  char again; 

  cout << "Enter name to begin:"<<nl;
  cin>> x;
 


  drunkmanruns(x);
  
return 0;
}