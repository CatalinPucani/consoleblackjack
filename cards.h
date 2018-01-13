#ifndef CARDS_H_INCLUDED
#define CARDS_H_INCLUDED

struct card {
    char name[20];
	char symbol[20];
	int value;
};

card cards[53];
int money=1000;

void diamonds_fill()
{
	for (int i = 1; i <= 10; i++)
	{
	    if((i-1)%10==0)
            strcpy(cards[i].name,"ace");
        else
            if(i==10)
        {
             cards[i].name[0]='1';
             cards[i].name[1]='0';
        }
            else
            cards[i].name[0]=48+i;
		cards[i].value = i;
		strcpy(cards[i].symbol, "diamonds");
	}
}

void clubs_fill()
{
	for (int i = 11; i <= 20; i++)
	{
	    if((i-1)%10==0)
            strcpy(cards[i].name,"ace");
        else
            if(i==20)
        {
             cards[i].name[0]='1';
             cards[i].name[1]='0';
        }
            else
            cards[i].name[0]=38+i;
		cards[i].value = i-10;
		strcpy(cards[i].symbol, "clubs");
	}
}

void hearts_fill()
{

	for (int i = 21; i <= 30; i++)
	{
	    if((i-1)%10==0)
            strcpy(cards[i].name,"ace");
        else
            if(i==30)
        {
             cards[i].name[0]='1';
             cards[i].name[1]='0';
        }
            else
            cards[i].name[0]=28+i;
		cards[i].value = i-20;
		strcpy(cards[i].symbol, "hearts");
	}
}

void spades_fill()
{
	for (int i = 31; i <= 40; i++)
	{
	    if((i-1)%10==0)
            strcpy(cards[i].name,"ace");
        else
            if(i==40)
        {
             cards[i].name[0]='1';
             cards[i].name[1]='0';
        }
            else
            cards[i].name[0]=18+i;
		cards[i].value = i-30;
		strcpy(cards[i].symbol, "spades");
	}
}

void jack_fill()
{
    strcpy(cards[41].name,"jack");
    strcpy(cards[41].symbol,"diamonds");
    cards[41].value=10;

    strcpy(cards[42].name,"jack");
    strcpy(cards[42].symbol,"clubs");
    cards[42].value=10;

    strcpy(cards[43].name,"jack");
    strcpy(cards[43].symbol,"hearts");
    cards[43].value=10;

    strcpy(cards[44].name,"jack");
    strcpy(cards[44].symbol,"spades");
    cards[44].value=10;
}

void queen_fill()
{
    strcpy(cards[45].name,"queen");
    strcpy(cards[45].symbol,"diamonds");
    cards[45].value=10;

    strcpy(cards[46].name,"queen");
    strcpy(cards[46].symbol,"clubs");
    cards[46].value=10;

    strcpy(cards[47].name,"queen");
    strcpy(cards[47].symbol,"hearts");
    cards[47].value=10;

    strcpy(cards[48].name,"queen");
    strcpy(cards[48].symbol,"spades");
    cards[48].value=10;
}

void king_fill()
{
    strcpy(cards[49].name,"king");
    strcpy(cards[49].symbol,"diamonds");
    cards[49].value=10;

    strcpy(cards[50].name,"king");
    strcpy(cards[50].symbol,"clubs");
    cards[50].value=10;

    strcpy(cards[51].name,"king");
    strcpy(cards[51].symbol,"hearts");
    cards[51].value=10;

    strcpy(cards[52].name,"king");
    strcpy(cards[52].symbol,"spades");
    cards[52].value=10;
}

void fill_cards()
{
    diamonds_fill();
    clubs_fill();
    hearts_fill();
    spades_fill();
    jack_fill();
    queen_fill();
    king_fill();
}


#endif // CARDS_H_INCLUDED
