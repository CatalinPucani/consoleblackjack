#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <limits>
#include <algorithm>
#include "cards.h"
using namespace std;
std::vector<int> cards_in_hand;
int bet;

void reinput()
{
    cin.clear();                                                                            ///se sterge input-ul curet pentru recitirea ulterioara a unei valori
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool twentyonecomb()
{
    if(cards_in_hand.size()==2)
        if(strcmp(cards[cards_in_hand[0]].name,"ace")==0 && strcmp(cards[cards_in_hand[1]].name,"10")==0 ||
           strcmp(cards[cards_in_hand[0]].name,"ace")==0 && strcmp(cards[cards_in_hand[1]].name,"jack")==0 ||
           strcmp(cards[cards_in_hand[0]].name,"ace")==0 && strcmp(cards[cards_in_hand[1]].name,"queen")==0 ||
           strcmp(cards[cards_in_hand[0]].name,"ace")==0 && strcmp(cards[cards_in_hand[1]].name,"king")==0 ||               ///se verifica existenta unei combinatii castigatoare
             strcmp(cards[cards_in_hand[0]].name,"ace")==0 && strcmp(cards[cards_in_hand[1]].name,"ace")==0 ||
            strcmp(cards[cards_in_hand[1]].name,"ace")==0 && strcmp(cards[cards_in_hand[0]].name,"10")==0 ||
           strcmp(cards[cards_in_hand[1]].name,"ace")==0 && strcmp(cards[cards_in_hand[0]].name,"jack")==0 ||
           strcmp(cards[cards_in_hand[1]].name,"ace")==0 && strcmp(cards[cards_in_hand[0]].name,"queen")==0 ||
           strcmp(cards[cards_in_hand[1]].name,"ace")==0 && strcmp(cards[cards_in_hand[0]].name,"king")==0  )
            return 1;
    return 0;
}

int sum()
{
    if(twentyonecomb())
    {
        return 21;
    }
    int s=0;
    for(int j=0;j<cards_in_hand.size();j++)
        s+=cards[cards_in_hand[j]].value;
    return s;
}

void display()
{
    system("cls");
    cout<<"Balance:"<<money<<endl;
    for(int j=0;j<cards_in_hand.size();j++)
        cout<<cards[cards_in_hand[j]].name<<" of "<<cards[cards_in_hand[j]].symbol<<endl;               ///afisare
    cout<<"Total:"<<sum()<<endl;
    cout<<"Press h (hit) or s (stand)"<<endl;
}


int main()
{
    srand(time(NULL));
    random_shuffle(cards+1,cards+53);         ///se amesteca pachetul de carti
    char x,stpl='y';
	int i=1,c,ops=0;
	bool p=0;
    fill_cards();
    do
    {
    bet=0;
    cards_in_hand.clear();                  ///se elibereaza vectorul
    do
    {
        system("cls");
        if(cin.fail())
            reinput();
        if(bet>money)
            cout<<"You don't have enough money"<<endl;
     cout<<"You have:"<<money<<"$"<<endl;
     cout<<"Place your bet:"; cin>>bet;
    }while(bet>money || bet==0 || bet<0 || cin.fail());

    money-=bet;
    for(int i=1;i<=2;i++)
    {
         c=rand()%52+1;
    cards_in_hand.push_back(c);
    }
    ops=rand()%8+17;
    while(sum()<21)
    {
    display();
    cin>>x;
    if(x=='s')
        break;
    if(sum()>21)
        {
            display();
            break;
        }
    c=rand()%52+1;
    cards_in_hand.push_back(c);
    if(x=='h' && sum()>21)
        break;
    }

    display();
    if(sum()>21)
        cout<<"You lost!"<<endl;
    else
    {
        if(ops==sum())
        {
            money+=bet;
            display();
            cout<<"Draw!"<<endl;
        }

        else
            if(ops<=21 && ops>sum())
                cout<<"You lost! The dealer's score is "<<ops<<endl;
        else
        {
            money+=2*bet;
            display();
            cout<<"You won! The dealer's score is "<<ops<<endl;
        }

    }
    cout<<"Play again? Y/N"<<endl;
    cin>>stpl;
    }while(stpl=='y' && money>0);
    if(money<=0)
        cout<<"You ran out of money"<<endl;
    return 0;
}

