#include<iostream>
#include<string>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
using namespace std;


struct Coordinates{
    int position;
    char symbol;
//initialize to 0 and ' '
    Coordinates(){
        position = 0;
        symbol = ' ';
    }
};

class Player;
class Game{
    static Coordinates c[9];
    static int play_count;
    public:
    void set_comp_pos(Player&);
    void check_comp_pos(Player&);
    void display() const;
    void input(Player&, Player&);
    void displayGraphics(Player&, Player&);
    void checkWinner(Player&);
};

class Player{
    string name;
    char symbol;
    bool is_my_turn,is_winner,is_comp;
    static int count;
    static char sym;
    friend class Game;
    public:
    Player(){
        is_winner = false;
        is_comp = false;
    }
    void input_player_detail();
    void display_detail(){
        cout<<"Name:"<<name<<'\n';
        cout<<"Symbol:"<<symbol<<'\n';
    }
    void  make_comp(){
        is_comp = !is_comp;
    }
};

void Game::display() const{
    cout<<"This is Tic Tac Toe By Abhilekh Gautam\n";
    cout<<"Enter any Key to continue to game\n";
    getch();
    system("CLS");
}

void Game::displayGraphics(Player& p1,Player& p2){
    for(int i = 0 ; i < 9 ; i++)
    {
        play_count++;
    //select the current player 
    Player& curr_player = p1.is_my_turn?p1:p2;
    Player& next_player = p1.is_my_turn?p2:p1;

    //display's game board
    cout<<c[0].symbol<<'\t'<<"|"<<c[1].symbol<<'\t'<<"|"<<c[2].symbol<<'\n';
    cout<<"\t"<<"|"<<"\t"<<"|"<<'\n';
    cout<<"-----------------------\n";
    cout<<c[3].symbol<<'\t'<<"|"<<c[4].symbol<<'\t'<<"|"<<c[5].symbol<<'\n';
    cout<<"\t"<<"|"<<"\t"<<"|"<<'\n';
    cout<<"-----------------------\n";
    cout<<c[6].symbol<<'\t'<<"|"<<c[7].symbol<<'\t'<<"|"<<c[8].symbol<<'\n';
    cout<<"\t"<<"|"<<"\t"<<"|"<<'\n';

//Take input for position 
    if(!curr_player.is_comp){
    cout<<curr_player.name<<" Choose position (1-9)"<<'\n';
    int choice;
    cin>>choice;
    //check for range input by the user
    while(choice<1 || choice>9){
        cout<<"OOps !Choose in between 1-9\n";
        cin>>choice;
    }
    //check if input position is already occupied
    while(c[choice - 1].symbol == curr_player.symbol||c[choice - 1].symbol == next_player.symbol){
      cout<<"OOPs! Position "<<choice<<" is already Occupied. Select another Position\n";
      cin>>choice;
      while(choice<1 || choice>9){
        cout<<"OOps !Choose in between 1-9\n";
        cin>>choice;
       }
     }
    //assigning symbol to the designated position
    c[choice-1].symbol = curr_player.symbol;
    }
    else{
        set_comp_pos(curr_player);
    }

    checkWinner(curr_player);
    system("CLS");

    if(curr_player.is_winner){
        if(curr_player.is_comp){
            cout<<"Computer won\n";
        }
        else{
            cout<<curr_player.name<<" is winner\n";
        }
        cout<<c[0].symbol<<'\t'<<"|"<<c[1].symbol<<'\t'<<"|"<<c[2].symbol<<'\n';
        cout<<"\t"<<"|"<<"\t"<<"|"<<'\n';
        cout<<"-----------------------\n";
        cout<<c[3].symbol<<'\t'<<"|"<<c[4].symbol<<'\t'<<"|"<<c[5].symbol<<'\n';
        cout<<"\t"<<"|"<<"\t"<<"|"<<'\n';
        cout<<"-----------------------\n";
        cout<<c[6].symbol<<'\t'<<"|"<<c[7].symbol<<'\t'<<"|"<<c[8].symbol<<'\n';
        cout<<"\t"<<"|"<<"\t"<<"|"<<'\n';
        break;
    }
    if(play_count == 9){
        if(!curr_player.is_winner){
            cout<<"Game drawn\n";
            cout<<c[0].symbol<<'\t'<<"|"<<c[1].symbol<<'\t'<<"|"<<c[2].symbol<<'\n';
            cout<<"\t"<<"|"<<"\t"<<"|"<<'\n';
            cout<<"-----------------------\n";
            cout<<c[3].symbol<<'\t'<<"|"<<c[4].symbol<<'\t'<<"|"<<c[5].symbol<<'\n';
            cout<<"\t"<<"|"<<"\t"<<"|"<<'\n';
            cout<<"-----------------------\n";
            cout<<c[6].symbol<<'\t'<<"|"<<c[7].symbol<<'\t'<<"|"<<c[8].symbol<<'\n';
            cout<<"\t"<<"|"<<"\t"<<"|"<<'\n';

            break;
        }
    }

   //setting up the turn for player
    curr_player.is_my_turn = false;
    next_player.is_my_turn = true;
   }
}

void Game::set_comp_pos(Player& P){
  cout<<"Computers Turn...\n";
  cout<<"Thinking...\n";
  Sleep(1800);

    if((c[0].symbol ==' ' || c[1].symbol == ' ' || c[2].symbol == ' ') && (((c[0].symbol == c[2].symbol) && c[0].symbol != ' ') || ((c[0].symbol == c[1].symbol) && (c[0].symbol != ' ')) || ((c[1].symbol == c[2].symbol) && c[1].symbol!=' '))){
       if(c[0].symbol == ' '){
          if(c[1].symbol != P.symbol){
            check_comp_pos(P);
          }
          else{
              c[0].symbol = P.symbol;
          }
       }
        else if(c[1].symbol == ' '){
            if(c[0].symbol != P.symbol){
            check_comp_pos(P);
          }
          else{
              c[1].symbol = P.symbol;
          }
        }
        else if(c[2].symbol == ' '){
            if(c[0].symbol != P.symbol){
            check_comp_pos(P);
          }
          else{
              c[2].symbol = P.symbol;
          }
       }
    }
   else if((c[3].symbol ==' ' || c[4].symbol ==' ' || c[5].symbol == ' ') && (((c[3].symbol == c[5].symbol) && c[3].symbol !=' ') || ((c[3].symbol == c[4].symbol) && (c[3].symbol !=' '))|| ((c[4].symbol == c[5].symbol) && c[4].symbol !=' '))){
     if(c[3].symbol == ' '){
         if(c[4].symbol != P.symbol){
            check_comp_pos(P);
          }
          else{
           c[3].symbol = P.symbol; 
          }
     }

      else if(c[4].symbol == ' '){
            if(c[3].symbol != P.symbol){
            check_comp_pos(P);
          }
          else{
           c[4].symbol = P.symbol; 
          }
        }

      else if(c[5].symbol == ' '){
          if(c[3].symbol != P.symbol){
            check_comp_pos(P);
          }
          else{
           c[5].symbol = P.symbol; 
          }
        }
   }
   else if((c[6].symbol ==' ' || c[7].symbol ==' '|| c[8].symbol == ' ') && (((c[6].symbol == c[8].symbol) && c[6].symbol !=' ') || ((c[6].symbol == c[7].symbol) && (c[6].symbol !=' ')) || ((c[7].symbol == c[8].symbol) && c[7].symbol !=' '))){
       if(c[6].symbol == ' '){
           if(c[7].symbol != P.symbol){
            check_comp_pos(P);
          }
          else{
           c[6].symbol = P.symbol; 
          }
       }

        else if(c[7].symbol == ' '){
            if(c[6].symbol != P.symbol){
            check_comp_pos(P);
          }
          else{
           c[7].symbol = P.symbol; 
          }
        }

        else if(c[8].symbol == ' '){
            if(c[7].symbol != P.symbol){
            check_comp_pos(P);
          }
          else{
        c[8].symbol = P.symbol; 
          }
        }
   }
   else if((c[0].symbol ==' ' || c[3].symbol==' '|| c[6].symbol == ' ') && (((c[0].symbol==c[6].symbol) && c[0].symbol !=' ') ||  ((c[0].symbol == c[3].symbol) && (c[0].symbol !=' ')) || ((c[3].symbol == c[6].symbol) && c[3].symbol != ' '))){
       if(c[0].symbol == ' '){
           if(c[3].symbol != P.symbol){
            check_comp_pos(P);
          }
          else{
              c[0].symbol = P.symbol;
          }
       }

        else if(c[3].symbol == ' '){
            if(c[0].symbol != P.symbol){
            check_comp_pos(P);
          }
          else{
        c[3].symbol = P.symbol; 
          }
        }

    else if(c[6].symbol == ' '){
        if(c[0].symbol != P.symbol){
            check_comp_pos(P);
          }
          else{
        c[6].symbol = P.symbol; 
          }
       } 
   }
   else if((c[1].symbol ==' ' || c[4].symbol == ' '|| c[7].symbol == ' ') && (((c[1].symbol==c[7].symbol)&& c[1].symbol !=' ') ||  ((c[1].symbol == c[4].symbol)&&(c[1].symbol!=' ')) || ((c[4].symbol== c[7].symbol) && c[4].symbol !=' '))){
       if(c[1].symbol == ' '){
           if(c[4].symbol != P.symbol){
            check_comp_pos(P);
          }
          else{
        c[1].symbol = P.symbol; 
          }
       }

        else if(c[4].symbol == ' '){
            if(c[1].symbol != P.symbol){
            check_comp_pos(P);
          }
          else{
        c[4].symbol = P.symbol; 
          }
        }

        else if(c[7].symbol == ' '){
            if(c[1].symbol != P.symbol){
            check_comp_pos(P);
          }
          else{
        c[7].symbol = P.symbol; 
          }
        }
   }
   else if((c[2].symbol ==' ' || c[5].symbol == ' '|| c[8].symbol == ' ') && (((c[2].symbol==c[8].symbol)&&c[2].symbol !=' ') || ((c[2].symbol == c[5].symbol)&& (c[2].symbol !=' ')) || ((c[5].symbol== c[8].symbol) && c[5].symbol !=' '))){
       if(c[2].symbol == ' '){
           if(c[5].symbol != P.symbol){
            check_comp_pos(P);
          }
          else{
        c[2].symbol = P.symbol; 
          }
       }

        else if(c[5].symbol == ' '){
            if(c[2].symbol != P.symbol){
            check_comp_pos(P);
          }
          else{
        c[5].symbol = P.symbol; 
          }
        }

        else if(c[8].symbol == ' '){
            if(c[2].symbol != P.symbol){
            check_comp_pos(P);
          }
          else{
        c[8].symbol = P.symbol; 
          }
        }
   }
   else if((c[0].symbol ==' ' || c[4].symbol ==' '|| c[8].symbol == ' ') && (((c[0].symbol == c[8].symbol) && c[0].symbol !=' ') || ((c[0].symbol == c[4].symbol)&&(c[0].symbol!=' ')) || ((c[4].symbol== c[8].symbol) && c[4].symbol !=' '))){
       if(c[0].symbol == ' '){
           if(c[4].symbol != P.symbol){
            check_comp_pos(P);
          }
          else{
              c[0].symbol = P.symbol;
          }
       }

        else if(c[4].symbol == ' '){
            if(c[0].symbol != P.symbol){
            check_comp_pos(P);
          }
          else{
        c[4].symbol = P.symbol; 
          }
        }

        else if(c[8].symbol == ' '){
            if(c[0].symbol != P.symbol){
            check_comp_pos(P);
          }
          else{
        c[8].symbol = P.symbol; 
          }
        }
   }
   else if((c[2].symbol ==' ' || c[4].symbol==' ' || c[6].symbol==' ') && (((c[2].symbol == c[6].symbol) && c[2].symbol !=' ') || ((c[2].symbol == c[4].symbol)&& (c[2].symbol !=' ')) || ((c[4].symbol == c[6].symbol) && c[4].symbol!=' '))){
       if(c[2].symbol == ' '){
           if(c[4].symbol != P.symbol){
            check_comp_pos(P);
          }
          else{
        c[2].symbol = P.symbol; 
          }
       }
        else if(c[4].symbol == ' '){
            if(c[2].symbol != P.symbol){
            check_comp_pos(P);
          }
          else{
        c[4].symbol = P.symbol; 
          }
        }

        else if(c[6].symbol == ' '){
            if(c[2].symbol != P.symbol){
            check_comp_pos(P);
          }
          else{
        c[6].symbol = P.symbol; 
          }
        }
     }
   else{
       
       //target bottom left corner
        if(c[6].symbol == ' '){
            c[6].symbol = P.symbol;
       }
       //target top right corner
       else if(c[2].symbol == ' '){
           c[2].symbol = P.symbol;
       }
       //top left
       else if(c[0].symbol == ' '){
           c[0].symbol = P.symbol;
       }
       //Always target the center first
       else if(c[4].symbol == ' '){
           c[4].symbol = P.symbol;
       }

       else{
           for(int i = 8 ; i >= 0 ; i--){
               if(c[i].symbol ==' '){
                   c[i].symbol = P.symbol;
                   break;
               }
           }
       }
  }
}

void Game::check_comp_pos(Player& P){
  if((c[2].symbol ==' ' || c[4].symbol==' ' || c[6].symbol==' ') && (((c[2].symbol == c[6].symbol) && c[2].symbol !=' ') || ((c[2].symbol == c[4].symbol)&& (c[2].symbol !=' ')) || ((c[4].symbol == c[6].symbol) && c[4].symbol!=' '))){
       if(c[2].symbol == ' ')
        c[2].symbol = P.symbol; 

        else if(c[4].symbol == ' ')
        c[4].symbol = P.symbol; 

        else if(c[6].symbol == ' ')
        c[6].symbol = P.symbol; 
   }
   else if((c[0].symbol ==' ' || c[4].symbol ==' '|| c[8].symbol == ' ') && (((c[0].symbol == c[8].symbol) && c[0].symbol !=' ') || ((c[0].symbol == c[4].symbol)&&(c[0].symbol!=' ')) || ((c[4].symbol== c[8].symbol) && c[4].symbol !=' '))){
       if(c[0].symbol == ' ')
        c[0].symbol = P.symbol; 

        else if(c[4].symbol == ' ')
        c[4].symbol = P.symbol; 

        else if(c[8].symbol == ' ')
        c[8].symbol = P.symbol; 
   }
   else if((c[2].symbol ==' ' || c[5].symbol == ' '|| c[8].symbol == ' ') && (((c[2].symbol==c[8].symbol)&&c[2].symbol !=' ') || ((c[2].symbol == c[5].symbol)&& (c[2].symbol !=' ')) || ((c[5].symbol== c[8].symbol) && c[5].symbol !=' '))){
       if(c[2].symbol == ' ')
        c[2].symbol = P.symbol; 

        else if(c[5].symbol == ' ')
        c[5].symbol = P.symbol; 

        else if(c[8].symbol == ' ')
        c[8].symbol = P.symbol; 
   }
   else if((c[1].symbol ==' ' || c[4].symbol == ' '|| c[7].symbol == ' ') && (((c[1].symbol==c[7].symbol)&& c[1].symbol !=' ') ||  ((c[1].symbol == c[4].symbol)&&(c[1].symbol!=' ')) || ((c[4].symbol== c[7].symbol) && c[4].symbol !=' '))){
       if(c[1].symbol == ' ')
        c[1].symbol = P.symbol; 

        else if(c[4].symbol == ' ')
        c[4].symbol = P.symbol; 

        else if(c[7].symbol == ' ')
        c[7].symbol = P.symbol; 
   }
   else if((c[0].symbol ==' ' || c[3].symbol==' '|| c[6].symbol == ' ') && (((c[0].symbol==c[6].symbol) && c[0].symbol !=' ') ||  ((c[0].symbol == c[3].symbol) && (c[0].symbol !=' ')) || ((c[3].symbol == c[6].symbol) && c[3].symbol != ' '))){
       if(c[0].symbol == ' ')
        c[0].symbol = P.symbol; 

        else if(c[3].symbol == ' ')
        c[3].symbol = P.symbol; 

        else if(c[6].symbol == ' ')
        c[6].symbol = P.symbol; 
   }
   else if((c[6].symbol ==' ' || c[7].symbol ==' '|| c[8].symbol == ' ') && (((c[6].symbol == c[8].symbol) && c[6].symbol !=' ') || ((c[6].symbol == c[7].symbol) && (c[6].symbol !=' ')) || ((c[7].symbol == c[8].symbol) && c[7].symbol !=' '))){
       if(c[6].symbol == ' ')
        c[6].symbol = P.symbol; 

        else if(c[7].symbol == ' ')
        c[7].symbol = P.symbol; 

        else if(c[8].symbol == ' ')
        c[8].symbol = P.symbol; 
   }
   else if((c[3].symbol ==' ' || c[4].symbol ==' ' || c[5].symbol == ' ') && (((c[3].symbol == c[5].symbol) && c[3].symbol !=' ') || ((c[3].symbol == c[4].symbol) && (c[3].symbol !=' '))|| ((c[4].symbol == c[5].symbol) && c[4].symbol !=' '))){
     if(c[3].symbol == ' ')
        c[3].symbol = P.symbol; 

        else if(c[4].symbol == ' ')
        c[4].symbol = P.symbol; 

        else if(c[5].symbol == ' ')
        c[5].symbol = P.symbol; 
   }
    else if((c[0].symbol ==' ' || c[1].symbol == ' ' || c[2].symbol == ' ') && (((c[0].symbol == c[2].symbol) && c[0].symbol != ' ') || ((c[0].symbol == c[1].symbol) && (c[0].symbol != ' ')) || ((c[1].symbol == c[2].symbol)&&c[1].symbol!=' '))){
       if(c[0].symbol == ' '){
          c[0].symbol = P.symbol;
       }

        else if(c[1].symbol == ' '){
              c[1].symbol = P.symbol;
          
        }
        else if(c[2].symbol == ' '){
              c[2].symbol = P.symbol;
        }
   }
       
}


void Game::checkWinner(Player& P){
 
   if(c[0].symbol !=' ' && c[0].symbol == c[1].symbol && c[1].symbol == c[2].symbol){
       P.is_winner = true;
   }
   else if(c[3].symbol !=' ' && c[3].symbol == c[4].symbol && c[4].symbol == c[5].symbol){
     P.is_winner = true;
   }
   else if(c[6].symbol !=' ' && c[6].symbol == c[7].symbol && c[7].symbol == c[8].symbol){
       P.is_winner = true;
   }
   else if(c[0].symbol !=' ' && c[0].symbol == c[3].symbol && c[3].symbol == c[6].symbol){
       P.is_winner = true;
   }
   else if(c[1].symbol !=' ' && c[1].symbol == c[4].symbol && c[4].symbol== c[7].symbol){
       P.is_winner = true;
   }
   else if(c[2].symbol !=' ' && c[2].symbol == c[5].symbol && c[5].symbol== c[8].symbol){
       P.is_winner = true;
   }
   else if(c[0].symbol !=' ' && c[0].symbol == c[4].symbol && c[4].symbol== c[8].symbol){
       P.is_winner = true;
   }
   else if(c[2].symbol !=' ' && c[2].symbol == c[4].symbol && c[4].symbol == c[6].symbol){
       P.is_winner = true;
   }
}

void Player::input_player_detail(){
if(!is_comp){
 if(count == 0)
 {
    cout<<"Enter Player1 Name\n";
    cin>>name;
      cout<<"Choose a symbol 'X' or 'O'\n";
    char ch = getch();
    if(ch == 'X'||ch == 'x')
    {
        symbol= 'X';
        cout<<"X selected as symbol for "<<this->name<<'\n';
        count++;
        sym = symbol;
        is_my_turn = true;
    }
    else if(ch == 'O'||ch =='o')
    {
        symbol= 'O';
        cout<<"O selected as symbol for "<<this->name<<'\n';
        count++;
        sym = symbol;
    }

    else{
        cout<<"Invalid Input\n";
        cout<<"X selected as symbol for "<<this->name<<" by default"<<'\n';
        count++;
        symbol= 'X';
        sym = symbol;

        is_my_turn = true;
       }

   }

    else
    {
        cout<<"Enter Player2 Name\n";
        cin>>name;
        if(sym == 'X')
        {
         symbol = 'O';
         cout<<"O is the symbol for "<<this->name<<'\n';
        }

        else
        {
            symbol = 'X';
            cout<<"X is the symbol for "<<this->name<<'\n';
        }
    }
 
    
Sleep(1000);
system("CLS");
 }
 else
 {
     if(sym == 'X'){
         symbol = 'O';
         cout<<"O is the symbol for Computer\n";
        }

        else{
            symbol = 'X';
            cout<<"X is the symbol for Computer\n";
        }
   }
Sleep(1000);
system("CLS");
}

void Game::input(Player& p1, Player& p2){
p1.input_player_detail();
p2.input_player_detail();
p1.display_detail();
p2.display_detail();
system("CLS");
displayGraphics(p1,p2);
}

int Player::count;
char Player::sym;
Coordinates Game::c[9];
int Game::play_count;

int main(){
    int choice;
    cout<<"Select Game Mode\n";
    cout<<"1.Single Player(vs Com)\n";
    cout<<"2.Multiplayer\n";
    cin>>choice;
    while(choice!=1 && choice!=2){
        cout<<"Choose In Between 1 and 2\n";
        cin>>choice;
    }
    Game G;
    Player p1,p2;
    if(choice == 1){
        p2.make_comp();
    }
    G.display();
    G.input(p1,p2);
    return 0;
}