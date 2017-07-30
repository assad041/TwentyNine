#include"playing_card.h"
#include"card_deck.h"
//using namespace std;

//////////////////////////////////////////////////////////////////////////////////

int card_deck::cardcreate()
{
    for(int i=0;i<32;i++)     /*0-7= hearts  8-15 = clubs   16-13 = diamonds   24-31 = spades */
    {
     int n=3+i/8;
     if(n==4)
        n=5;
     else if(n==5)
        n=4;
     if(i==3+(i/8)*8)
        deck[i].put_char(2,n);
     else
        deck[i].put_char(1,n);
    }

    for(int i=0;i<32;i++)
    {
        if(i==3+(i/8)*8)
            deck[i].put_char(3,'\0');
        else
            deck[i].put_char(2,'\0');
    }

    for(int i=0;i<32;i=i+8)
    {
        deck[i+0].put_char(0,'J');
        deck[i+1].put_char(0,'9');
        deck[i+2].put_char(0,'A');
        deck[i+3].put_char(0,'1');
        deck[i+3].put_char(1,'0');
        deck[i+4].put_char(0,'K');
        deck[i+5].put_char(0,'Q');
        deck[i+6].put_char(0,'8');
        deck[i+7].put_char(0,'7');
    }
    return 0;
}






 void card_deck::view_visual_card(int i ,int x, int y)
 {
    asdgraphics::locate(x,y);
    //char ch[4]={221,222,223,220};
    char ch[4];
    ch[0]=221;
    ch[1]=222;
    ch[2]=220;
    ch[3]=223;
    //char ch[4]={219,219,219,219};
    char crd;
    if(i<8)
    {
        color=12;
        crd=3;
    }
    else if(i<16)
    {
        color=15;
        crd=5;
    }
    else if(i<24)
    {
        color=12;
        crd=4;
    }
    else if(i<32)
    {
        color=15;
        crd=6;
    }
    asdgraphics::setColor(15);
    for(int j=0; j<7; j++)
        cout<<ch[2];
    asdgraphics::locate(x,++y);
    cout<<ch[0];
    asdgraphics::setColor(color);
    cout<<deck[i].get_card();
    asdgraphics::setColor(15);
    if(i==3||i==11||i==19||i==27)
        cout<<"  "<<ch[1];
    else
        cout<<"   "<<ch[1];
    asdgraphics::locate(x,++y);
    cout<<ch[0]<<"     "<<ch[1];
    asdgraphics::locate(x,++y);
    cout<<ch[0]<<" ";
    asdgraphics::setColor(color);
    cout<<crd;
    asdgraphics::setColor(15);
    cout<<" ";
    asdgraphics::setColor(color);
    cout<<crd;
    asdgraphics::setColor(15);
    cout<<" "<<ch[1];
    asdgraphics::locate(x,++y);
    cout<<ch[0]<<"     "<<ch[1];
    asdgraphics::locate(x,++y);
    cout<<ch[0]<<" ";
    asdgraphics::setColor(color);
    cout<<crd;
    asdgraphics::setColor(15);
    cout<<" ";
    asdgraphics::setColor(color);
    cout<<crd;
    asdgraphics::setColor(15);
    cout<<" "<<ch[1];
    asdgraphics::locate(x,++y);
    cout<<ch[0]<<"     "<<ch[1];
    asdgraphics::locate(--x,++y);
    if(i==3||i==11||i==19||i==27)
        cout<<" "<<ch[0]<<"  ";
    else
        cout<<" "<<ch[0]<<"   ";
    asdgraphics::setColor(color);
    cout<<deck[i].get_card();
    asdgraphics::setColor(15);
    cout<<ch[1];
    x++;
    asdgraphics::locate(x,++y);
    for(int j=0; j<7; j++)
        cout<<ch[3];
    asdgraphics::locate(99,41);
}

int card_deck::view_hide_card(int i, int x, int y)
{
    char ch=219,ch2=177;
    for(int i=0; i<8; i++)
    {
        asdgraphics::locate(x,y+i);
        cout<<ch;
    }
    for(int c=1; c<7; c++)
    {
        asdgraphics::locate(x+1,y+c);
        for(int i=0; i<6; i++)
            cout<<ch2;
    }
    asdgraphics::locate(x+1,y);
    for(int i=0; i<6; i++)
        cout<<ch;
    asdgraphics::locate(x+1,y+7);
        for(int i=0; i<6; i++)
            cout<<ch;
    for(int i=0; i<8; i++)
    {
        asdgraphics::locate(x+6,y+i);
        cout<<ch;
    }

    return 0;

}

void card_deck::view_visual_trump_card(int t, int x, int y)
{
    asdgraphics::setColor(11);
    char ch[6];
    ch[0]=3;
    ch[1]=5;
    ch[2]=4;
    ch[3]=6;
    ch[4]=219;
    ch[5]=31;
    for(int i=1; i<5; i++)
    {
        asdgraphics::locate(x,y+i);
        cout<<ch[4];
    }

    for(int i=1; i<7; i++)
    {
        asdgraphics::locate(x+i,y+1);
        cout<<ch[4];
        asdgraphics::locate(x+i,y+4);
        cout<<ch[4];
    }
    for(int i=1; i<5; i++)
    {
        asdgraphics::locate(x+6,y+i);
        cout<<ch[4];
    }

    if(t==0 || t==2)
        asdgraphics::setColor(12);
    else if(t==1 || t==3)
        asdgraphics::setColor(15);
    asdgraphics::locate(x+1,y+2);
    cout<<" "<<ch[t]<<ch[t]<<ch[t]<<" ";
    asdgraphics::locate(x+1,y+3);
    cout<<" "<<ch[t]<<ch[t]<<ch[t]<<" ";
    asdgraphics::locate(17,20);
    asdgraphics::setColor(11);
    if(t==0)
        cout<<"   Hearts  ";
    else if(t==1)
        cout<<"    Clubs  ";
    else if(t==2)
        cout<<"  Diamonds ";
    else if(t==3)
        cout<<"   Spades  ";


}



void card_deck::view_hide_trump_card(int t, int x, int y)
{
    asdgraphics::setColor(11);
    char ch[6];
    ch[0]=177;
    ch[1]=177;
    ch[2]=177;
    ch[3]=177;
    ch[4]=219;
    ch[5]=31;
    for(int i=1; i<5; i++)
    {
        asdgraphics::locate(x,y+i);
        cout<<ch[4];
    }

    for(int i=1; i<7; i++)
    {
        asdgraphics::locate(x+i,y+1);
        cout<<ch[4];
        asdgraphics::locate(x+i,y+4);
        cout<<ch[4];
    }
    asdgraphics::setColor(15);
    asdgraphics::locate(x+1,y+2);
    cout<<ch[t]<<ch[t]<<ch[t]<<ch[t]<<ch[t];
    asdgraphics::locate(x+1,y+3);
    cout<<ch[t]<<ch[t]<<ch[t]<<ch[t]<<ch[t];
    asdgraphics::locate(17,20);
    asdgraphics::setColor(11);
    if(t==0)
        cout<<"  Not Shown ";
    else if(t==1)
        cout<<"  Not Shown ";
    else if(t==2)
        cout<<"  Not Shown ";
    else if(t==3)
        cout<<"  Not Shown ";
    for(int i=1; i<5; i++)
    {
        asdgraphics::locate(x+6,y+i);
        cout<<ch[4];
    }
}




void card_deck::display(int i)
{
    if(i<8)
        color=12;
    else if(i<16)
        color=15;
    else if(i<24)
        color=12;
    else if(i<32)
        color=15;

    asdgraphics::setColor(color);
    cout<<deck[i].get_card();
    asdgraphics::setColor(15);
}



/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
