#include"board_setup_and_view_setup.h"
#include"tool_ber.h"

////////////////////////////////////////////////////////////////////////////////////////////
void board_setup_and_view_setup::Constructor()
{
    for(int i=0; i<4; i++)
        Marriage[i]=0;
    Double=0;
    Show_Trump=0;
    trump=0;
}

////////////////////////////////////////////////////////////////////////////////////////////

void board_setup_and_view_setup::set_card()
{
    for(int i=0; i<4; i++)
    {
        int c=0;
        for(int j=0; j<4; j++)
        {
            int p=0;
            for(int k=0; k<8; k++)
            {
                int q=0;
                for(int l=0; l<8; l++)
                {
                    if(player[i].get_card(l)==c)
                    {
                        q++;
                        break;
                    }
                }
                if(q==0)
                {
                    Hand_card[i][j].push_card(p,c);
                    p++;
                }
                c++;
            }
        }
    }
}
///////////////////////////////////////////////////////////////////////////////////////////

void board_setup_and_view_setup::remove_A_Hand_card(int player, int card)
{
    int type;
    if(card>=0 && card<8)
    {
        type=0;
    }
    else if(card>=8 && card<16)
    {
        type=1;
    }
    else if(card>=16  && card<24)
    {
        type=2;
    }
    else if(card>=24 && card<32)
    {
        type=3;
    }
    for(int i=0; i<Hand_card[player][type].get_top(); i++)
    {
        if(Hand_card[player][type].get_card(i)==card)
        {
            Hand_card[player][type].play_card(i);
            break;
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////

void board_setup_and_view_setup::clear_south_card(void)
{
    for(int c=0; c<9; c++)
    {
        asdgraphics::locate(57,30+c);
        for(int i=0;i<28;i++)
        cout<<" ";

    }
}
///////////////////////////////////////////////////////////////////////////////////////////

void board_setup_and_view_setup::clear_east_card(void)
{

    for(int c=0; c<23; c++)
    {
        asdgraphics::locate(97,11+c);
        for(int i=0;i<8;i++)
        cout<<" ";

    }
}
///////////////////////////////////////////////////////////////////////////////////////////

void board_setup_and_view_setup::clear_north_card(void)
{
    for(int c=0; c<9; c++)
    {
        asdgraphics::locate(57,5+c);
        for(int i=0;i<28;i++)
        cout<<" ";

    }
}
///////////////////////////////////////////////////////////////////////////////////////////

void board_setup_and_view_setup::clear_west_card(void)
{
    for(int c=0; c<23; c++)
    {
        asdgraphics::locate(38,11+c);
        for(int i=0;i<8;i++)
        cout<<" ";

    }
}
///////////////////////////////////////////////////////////////////////////////////////////

void board_setup_and_view_setup::view_east_card(void)
{
    clear_east_card();
    x=97;
    y=22-(player[2].get_top()+3);
    for(int i=0; i<player[2].get_top(); i++)
    {
        cardBoy.view_hide_card(player[2].get_card(i),x,y);
        y+=2;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////

void board_setup_and_view_setup::view_west_card(void)
{
    clear_west_card();
    x=38;
    y=22-(player[0].get_top()+3);
    for(int i=0; i<player[0].get_top(); i++)
    {
        cardBoy.view_hide_card(player[0].get_card(i),x,y);
        y+=2;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////

void board_setup_and_view_setup::view_north_card(void)
{
    clear_north_card();
    y=5;
    x=71-(((player[1].get_top()*3)/2)+2);
    for(int i=0; i<player[1].get_top(); i++)
    {
        cardBoy.view_hide_card(player[1].get_card(i),x,y);
        x+=3;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////

void board_setup_and_view_setup::view_south_card(void)
{
    clear_south_card();
    y=30;
    x=71-(((player[3].get_top()*3)/2)+2);
    for(int i=0; i<player[3].get_top(); i++)
    {
        cardBoy.view_visual_card(player[3].get_card(i),x,y);
        x+=3;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////

void board_setup_and_view_setup::show_AllPlayingCard(void)
{
    int x=7;
    int y=3;
    for(int i=0; i<32; i++)
    {
        cardBoy.view_visual_card(i,x,y);
        x+=13;
        if((i+1)%8==0)
        {
            x=7;
            y+=9;
        }
        asdgraphics::msleep(60);
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////

void board_setup_and_view_setup::clear_user_bid_box()
{
    for(int i=0; i<12; i++)
    {
        asdgraphics::locate(54,17+i);
        cout<<"                                  ";
    }
}
////////////////////////////////////////////////////////////////////////////////////////////

int board_setup_and_view_setup::show_user_bid_box_Make_bid()
{
    asdgraphics::setColor(11);
    char ch[5];
    ch[0]=223;
    ch[1]=222;
    ch[2]=221;
    ch[3]=220;
    ch[4]=219;
    x=54;
    y=16;
    for(int i=1; i<12; i++)
    {
        asdgraphics::locate(x,y+i);
        cout<<ch[1];
    }
    for(int i=1; i<33; i++)
    {
        asdgraphics::locate(x+i,y+1);
        cout<<ch[0];
        asdgraphics::locate(x+i,y+11);
        cout<<ch[3];
    }
    for(int i=1; i<12; i++)
    {
        asdgraphics::locate(x+33,y+i);
        cout<<ch[2];
    }
     for(int i=4; i<7; i++)
    {
        asdgraphics::locate(x+13,y+i);
        cout<<ch[1];
    }

    asdgraphics::locate(x+14,y+4);
    for(int i=0; i<7; i++)
        cout<<ch[0];

    asdgraphics::locate(x+14,y+6);
    for(int i=0; i<7; i++)
        cout<<ch[3];

    for(int i=4; i<7; i++)
    {
        asdgraphics::locate(x+20,y+i);
        cout<<ch[2];
    }
    for(int i=8; i<11; i++)
    {
        asdgraphics::locate(x+2,y+i);
        cout<<ch[1];
    }
    asdgraphics::locate(x+3,y+8);
    for(int i=0; i<9; i++)
        cout<<ch[0];

    asdgraphics::locate(x+3,y+10);
    for(int i=0; i<9; i++)
        cout<<ch[3];

    for(int i=8; i<11; i++)
    {
        asdgraphics::locate(x+11,y+i);
        cout<<ch[2];
    }
    for(int i=8; i<11; i++)
    {
        asdgraphics::locate(x+22,y+i);
        cout<<ch[1];
    }
    asdgraphics::locate(x+23,y+8);
    for(int i=0; i<9; i++)
        cout<<ch[0];

    asdgraphics::locate(x+23,y+10);
    for(int i=0; i<9; i++)
        cout<<ch[3];

    for(int i=8; i<11; i++)
    {
        asdgraphics::locate(x+31,y+i);
        cout<<ch[2];
    }
    asdgraphics::locate(57,18);
    cout<<"Enter bid here. Min 15 Max 28";
    asdgraphics::locate(58,25);
    cout<<"ENTER";
    asdgraphics::locate(77,25);
    cout<<" PASS[P]";
    asdgraphics::locate(69,21);
    asdgraphics::showcursor();
    char c;
    int x=0;
    tool_ber go;
    while(1)
    {
        c=asdgraphics::getkey();
        c=go.toolber_menu_option(c);
        if(c=='r')
        {
            asdgraphics::hidecursor();
            return 100;
        }
        if(c=='P'||c=='p')
        {
            asdgraphics::hidecursor();
            clear_user_bid_box();
            return 0;
        }
        else if(c-'0'>-1  && c-'0'<10)
        {
            x=x*10+c-'0';
            cout<<c;
        }
        else if(c==1)
        {
            if(x<29 && x>14)
            {
                asdgraphics::hidecursor();
                clear_user_bid_box();
                return x;
            }
            else
            {
                asdgraphics::locate(69,21);
                cout<<"   ";
                asdgraphics::locate(69,21);
                cout<<'\a';
                x=0;
                continue;
            }
        }
        else if(c==8)
        {
            asdgraphics::locate(69,21);
            cout<<"   ";
            asdgraphics::locate(69,21);
            x=0;
            continue;
        }
        else
            cout<<'\a';
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////

int board_setup_and_view_setup::make_user_trump(void)
{
    asdgraphics::setColor(11);
    char ch[6];
    ch[0]=3;
    ch[1]=5;
    ch[2]=4;
    ch[3]=6;
    ch[4]=219;
    ch[5]=31;
    x=59;
    y=20;
    for(int i=1; i<5; i++)
    {
        asdgraphics::locate(x,y+i);
        cout<<ch[4];
        asdgraphics::locate(x+6,y+i);
        cout<<ch[4];
        asdgraphics::locate(x+12,y+i);
        cout<<ch[4];
        asdgraphics::locate(x+18,y+i);
        cout<<ch[4];
        asdgraphics::locate(x+24,y+i);
        cout<<ch[4];
    }

    for(int i=1; i<24; i++)
    {
        asdgraphics::locate(x+i,y+1);
        cout<<ch[4];
        asdgraphics::locate(x+i,y+4);
        cout<<ch[4];
    }
    for(int i=1; i<5; i++)
    {
        asdgraphics::locate(x+24,y+i);
        cout<<ch[4];
    }

    asdgraphics::setColor(12);
    asdgraphics::locate(x+2,y+2);
    cout<<ch[0]<<ch[0]<<ch[0];
     asdgraphics::locate(x+2,y+3);
    cout<<ch[0]<<ch[0]<<ch[0];
    asdgraphics::setColor(15);
    asdgraphics::locate(x+8,y+2);
    cout<<ch[1]<<ch[1]<<ch[1];
    asdgraphics::locate(x+8,y+3);
    cout<<ch[1]<<ch[1]<<ch[1];
    asdgraphics::setColor(12);
    asdgraphics::locate(x+14,y+2);
    cout<<ch[2]<<ch[2]<<ch[2];
    asdgraphics::locate(x+14,y+3);
    cout<<ch[2]<<ch[2]<<ch[2];
    asdgraphics::setColor(15);
    asdgraphics::locate(x+20,y+2);
    cout<<ch[3]<<ch[3]<<ch[3];
    asdgraphics::locate(x+20,y+3);
    cout<<ch[3]<<ch[3]<<ch[3];
    asdgraphics::setColor(11);
    int p=0;
    while(1)
    {
        if(p==0)
        {
            asdgraphics::locate(x+3,y-1);
            cout<<ch[5];
        }
        else if(p==1)
        {
            asdgraphics::locate(x+9,y-1);
            cout<<ch[5];
        }
        else if(p==2)
        {
            asdgraphics::locate(x+15,y-1);
            cout<<ch[5];
        }
        else if(p==3)
        {
            asdgraphics::locate(x+21,y-1);
            cout<<ch[5];
        }
        int k=asdgraphics::getkey();
        if(k==17 && p<3)
        {
            p++;
        }
        else if(k==16 && p>0)
        {
            p--;
        }
        else if(k==1)
        {
            for(int i=0; i<7; i++)
            {
                asdgraphics::locate(x,y-1+i);
                cout<<"                              ";
            }
            asdgraphics::locate(x,y-1);
            cout<<"                              ";
            return p;
        }
        else
        {
            if(k==17)
                p=0;
            else if(k==16)
                p=3;
            else
                cout<<'\a';
        }
        asdgraphics::locate(x,y-1);
        cout<<"                              ";
    }
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////

int board_setup_and_view_setup::user_trump_options()
{
    asdgraphics::setColor(11);
    char ch[6];
    ch[0]=3;
    ch[1]=5;
    ch[2]=4;
    ch[3]=6;
    ch[4]=219;
    ch[5]=31;
    x=59;
    y=20;
    for(int i=0; i<5; i++)
    {
        asdgraphics::locate(x,y+i);
        cout<<ch[4];
        asdgraphics::locate(x+8,y+i);
        cout<<ch[4];
        asdgraphics::locate(x+16,y+i);
        cout<<ch[4];
    }

    for(int i=1; i<24; i++)
    {
        asdgraphics::locate(x+i,y);
        cout<<ch[4];
        asdgraphics::locate(x+i,y+4);
        cout<<ch[4];
    }
    for(int i=0; i<5; i++)
    {
        asdgraphics::locate(x+24,y+i);
        cout<<ch[4];
    }


    asdgraphics::locate(x+2,y+2);
    cout<<"SEVEN";
    asdgraphics::locate(x+10,y+2);
    cout<<" SIX";
    asdgraphics::locate(x+17,y+2);
    cout<<"MANUAL";

    asdgraphics::setColor(11);
    int p=0;
    while(1)
    {
        if(p==0)
        {
            asdgraphics::locate(x+4,y-1);
            cout<<ch[5];
        }
        else if(p==1)
        {
            asdgraphics::locate(x+12,y-1);
            cout<<ch[5];
        }
        else if(p==2)
        {
            asdgraphics::locate(x+20,y-1);
            cout<<ch[5];
        }
        int k=asdgraphics::getkey();
        if(k==17 && p<2)
        {
            p++;
        }
        else if(k==16 && p>0)
        {
            p--;
        }
        else if(k==1)
        {
            for(int i=0; i<7; i++)
            {
                asdgraphics::locate(x,y-1+i);
                cout<<"                              ";
            }
            asdgraphics::locate(x,y-1);
            cout<<"                              ";
            return p;
        }
        else
        {
            if(k==17)
                p=0;
            else if(k==16)
                p=2;
            else
                cout<<'\a';
        }
        asdgraphics::locate(x,y-1);
        cout<<"                              ";
    }
}
////////////////////////////////////////////////////////////////////////////////////////////

int board_setup_and_view_setup::ask_about_double()
{
    asdgraphics::setColor(11);
    char ch[6];
    ch[0]=3;
    ch[1]=5;
    ch[2]=4;
    ch[3]=6;
    ch[4]=219;
    ch[5]=31;
    x=54;
    y=18;
    for(int i=0; i<7; i++)
    {
        asdgraphics::locate(x,y+i);
        cout<<ch[4];
    }

    for(int i=1; i<32; i++)
    {
        asdgraphics::locate(x+i,y);
        cout<<ch[4];
        asdgraphics::locate(x+i,y+6);
        cout<<ch[4];
    }

    for(int i=0; i<7; i++)
    {
        asdgraphics::locate(x+32,y+i);
        cout<<ch[4];
    }
    cout<<'\a';
    asdgraphics::setColor(12);
    asdgraphics::locate(x+2,y+2);
    cout<<"WOULD YOU LIKE TO SAY DOUBLE?";
    asdgraphics::locate(x+2,y+4);
    cout<<"     YES[Y]      NO[N]";
    asdgraphics::setColor(11);
    while(1)
    {
        char c;
        c=getch();
        if(c=='y' || c=='Y')
        {
            for(int i=0; i<7; i++)
            {
                asdgraphics::locate(x,y+i);
                cout<<"                                 ";
            }
            return 1;
        }
        else if(c=='n' || c=='N')
        {
            for(int i=0; i<7; i++)
            {
                asdgraphics::locate(x,y+i);
                cout<<"                                 ";
            }
            return 0;
        }
        else
            cout<<'\a';
    }

}
////////////////////////////////////////////////////////////////////////////////////////////

int board_setup_and_view_setup::make_board_bid_and_trump()
{
    Career cr;
    instuctions info;
    int w=cr.get_user_rank()%4;
    char sm[4]={16,17,30,31};
    if(w==0)
    {
        asdgraphics::setColor(11);
        info.put_messages("West is thinking.");
        info.display_instuctions();
        asdgraphics::locate(46,22);
        asdgraphics::setColor(14);
        cout<<sm[1];
        asdgraphics::msleep(1500);
        asdgraphics::locate(46,22);
        cout<<" ";
        info.clear_instuctions_line();
        asdgraphics::setColor(11);

        asdgraphics::locate(4,29);
        cout<<"Bid 15 By West";
        bid_player=0;
        target_bid=15;
        //////////////////////////////////////////////

        asdgraphics::locate(70,29);
        asdgraphics::setColor(14);
        cout<<sm[3];
        asdgraphics::setColor(11);
        temp=show_user_bid_box_Make_bid();
        if(temp==100)
            return 100;
        put_user_max_bid(temp);
        asdgraphics::locate(4,30);
        if(target_bid<temp)
        {
            cout<<"Bid "<<temp<<" By South";
            bid_player=3;
            target_bid=temp;
        }
        else
            cout<<"Bid Pass By South";
        asdgraphics::locate(70,29);
        cout<<" ";
        /////////////////////////////////////////////////

        info.put_messages("East is thinking.");
        info.display_instuctions();
        asdgraphics::locate(95,22);
        asdgraphics::setColor(14);
        cout<<sm[0];
        asdgraphics::msleep(1500);
        asdgraphics::locate(95,22);
        cout<<" ";
        info.clear_instuctions_line();
        asdgraphics::setColor(11);
        asdgraphics::locate(4,31);
        if(target_bid<get_max_bit(2))
        {
            cout<<"Bid "<<target_bid+1<<" By East";
            bid_player=2;
            target_bid++;
        }
        else
            cout<<"Bid Pass By East";

        /////////////////////////////////////////////////

        info.put_messages("North is thinking.");
        info.display_instuctions();
        asdgraphics::locate(70,14);
        asdgraphics::setColor(14);
        cout<<sm[2];
        asdgraphics::msleep(1500);
        asdgraphics::locate(70,14);
        cout<<" ";
        info.clear_instuctions_line();
        asdgraphics::setColor(11);
        asdgraphics::locate(4,32);
        if(target_bid<get_max_bit(1))
        {
            cout<<"Bid "<<target_bid+1<<" By North";
            bid_player=1;
            target_bid++;
        }
        else
            cout<<"Bid Pass By North";

        ////////////////////////////////////////////////

        info.put_messages("West is thinking.");
        info.display_instuctions();
        asdgraphics::locate(46,22);
        asdgraphics::setColor(12);
        cout<<sm[1];
        asdgraphics::msleep(1500);
        asdgraphics::locate(46,22);
        cout<<" ";
        info.clear_instuctions_line();
        asdgraphics::setColor(11);
        asdgraphics::locate(4,33);
        if(target_bid<get_max_bit(0) && bid_player!=0)
        {
            cout<<"Bid "<<target_bid+1<<" By  West";
            bid_player=0;
            target_bid++;
        }
        else
            cout<<"Bid Pass By West";


        ///////////////////////////////////////////////

        asdgraphics::locate(70,29);
        asdgraphics::setColor(12);
        cout<<sm[3];
        asdgraphics::setColor(11);
        asdgraphics::locate(4,34);
        if(bid_player!=3)
        {
            temp=show_user_bid_box_Make_bid();
            if(temp==100)
                return 100;
            asdgraphics::locate(4,34);
            if(temp>target_bid)
            {
                put_user_max_bid(temp);
                cout<<"Bid "<<temp<<" By South";
                bid_player=3;
                target_bid=temp;
            }
            else
                cout<<"Bid Pass By South";
        }
        else
            cout<<"Bid Pass By South";
        asdgraphics::locate(70,29);
        cout<<" ";
        //////////////////////////////////////////

        info.put_messages("East is thinking.");
        info.display_instuctions();
        asdgraphics::locate(95,22);
        asdgraphics::setColor(12);
        cout<<sm[0];
        asdgraphics::msleep(1500);
        asdgraphics::locate(95,22);
        cout<<" ";
        info.clear_instuctions_line();
        asdgraphics::setColor(11);
        asdgraphics::locate(4,35);
        if(target_bid<get_max_bit(2) && bid_player!=2)
        {
            cout<<"Bid "<<target_bid+1<<" By East";
            bid_player=2;
            target_bid++;
        }
        else
            cout<<"Bid Pass By East";

        /////////////////////////////////////

        info.put_messages("North is thinking.");
        info.display_instuctions();
        asdgraphics::locate(70,14);
        asdgraphics::setColor(12);
        cout<<sm[2];
        asdgraphics::msleep(1500);
        asdgraphics::locate(70,14);
        cout<<" ";
        info.clear_instuctions_line();
        asdgraphics::setColor(11);
        asdgraphics::locate(4,36);
        if(target_bid<get_max_bit(1) && bid_player!=1)
        {
            cout<<"Bid "<<target_bid+1<<" By North";
            bid_player=1;
            target_bid++;
        }
        else
            cout<<"Bid Pass By North";


        trump=get_trump_card(bid_player);
    }
    /////////////////////////////////////////////////////////////////////////////
    if(w==1)
    {
        asdgraphics::locate(70,29);
        asdgraphics::setColor(14);
        cout<<sm[3];
        asdgraphics::setColor(11);
        temp=show_user_bid_box_Make_bid();
        if(temp==100)
            return 100;
        put_user_max_bid(temp);
        asdgraphics::locate(4,29);
        if(temp!=0)
        {
            cout<<"Bid "<<temp<<" By South";
            bid_player=3;
            target_bid=temp;
        }
        else
        {
            cout<<"Bid Pass By South";
            target_bid=14;
        }

        asdgraphics::locate(70,29);
        cout<<" ";
        //////////////////////////////////////

        info.put_messages("East is thinking.");
        info.display_instuctions();
        asdgraphics::locate(95,22);
        asdgraphics::setColor(14);
        cout<<sm[0];
        asdgraphics::msleep(1500);
        asdgraphics::locate(95,22);
        cout<<" ";
        info.clear_instuctions_line();
        asdgraphics::setColor(11);
        asdgraphics::locate(4,30);
        if(target_bid<get_max_bit(2))
        {
            cout<<"Bid "<<target_bid+1<<" By East";
            bid_player=2;
            target_bid++;
        }
        else
            cout<<"Bid Pass By East";
        ////////////////////////////////////////////////

        info.put_messages("North is thinking.");
        info.display_instuctions();
        asdgraphics::locate(70,14);
        asdgraphics::setColor(14);
        cout<<sm[2];
        asdgraphics::msleep(1500);
        asdgraphics::locate(70,14);
        cout<<" ";
        info.clear_instuctions_line();
        asdgraphics::setColor(11);
        asdgraphics::locate(4,31);
        if(target_bid<get_max_bit(1))
        {
            cout<<"Bid "<<target_bid+1<<" By North";
            bid_player=1;
            target_bid++;
        }
        else
            cout<<"Bid Pass By North";
        ///////////////////////////////////////////////

        info.put_messages("West is thinking.");
        info.display_instuctions();
        asdgraphics::locate(46,22);
        asdgraphics::setColor(14);
        cout<<sm[1];
        asdgraphics::msleep(1500);
        asdgraphics::locate(46,22);
        cout<<" ";
        info.clear_instuctions_line();
        asdgraphics::setColor(11);
        asdgraphics::locate(4,32);
        if(target_bid<get_max_bit(0))
        {
             cout<<"Bid "<<target_bid+1<<" By West";
             bid_player=0;
             target_bid++;
        }
        else
            cout<<"Bid Pass By West";
        /////////////////////////////////////////////

        asdgraphics::locate(70,29);
        asdgraphics::setColor(12);
        cout<<sm[3];
        asdgraphics::setColor(11);
        asdgraphics::locate(4,33);
        if(bid_player!=3)
        {
            temp=show_user_bid_box_Make_bid();
            if(temp==100)
                return 100;
            asdgraphics::locate(4,33);
            if(temp>target_bid)
            {
                put_user_max_bid(temp);
                cout<<"Bid "<<temp<<" By South";
                bid_player=3;
                target_bid=temp;
            }
            else
                cout<<"Bid Pass By South";
        }
        else
            cout<<"Bid Pass By South";
        asdgraphics::locate(70,29);
        cout<<" ";
        ////////////////////////////////////

        info.put_messages("East is thinking.");
        info.display_instuctions();
        asdgraphics::locate(95,22);
        asdgraphics::setColor(12);
        cout<<sm[0];
        asdgraphics::msleep(1500);
        asdgraphics::locate(95,22);
        cout<<" ";
        info.clear_instuctions_line();
        asdgraphics::setColor(11);
        asdgraphics::locate(4,34);
        if(target_bid<get_max_bit(2) && bid_player!=2)
        {
            cout<<"Bid "<<target_bid+1<<" By East";
            bid_player=2;
            target_bid++;
        }
        else
            cout<<"Bid Pass By East";
        ////////////////////////////////////

        info.put_messages("North is thinking.");
        info.display_instuctions();
        asdgraphics::locate(70,14);
        asdgraphics::setColor(12);
        cout<<sm[2];
        asdgraphics::msleep(1500);
        asdgraphics::locate(70,14);
        cout<<" ";
        info.clear_instuctions_line();
        asdgraphics::setColor(11);
        asdgraphics::locate(4,35);
        if(target_bid<get_max_bit(1) && bid_player!=1)
        {
            cout<<"Bid "<<target_bid+1<<" By North";
            bid_player=1;
            target_bid++;
        }
        else
            cout<<"Bid Pass By North";
        ////////////////////////////////////////

        info.put_messages("West is thinking.");
        info.display_instuctions();
        asdgraphics::locate(46,22);
        asdgraphics::setColor(12);
        cout<<sm[1];
        asdgraphics::msleep(1500);
        asdgraphics::locate(46,22);
        cout<<" ";
        info.clear_instuctions_line();
        asdgraphics::setColor(11);
        asdgraphics::locate(4,36);
        if(target_bid<get_max_bit(0) && bid_player!=0)
        {
             cout<<"Bid "<<target_bid+1<<" By West";
             bid_player=0;
             target_bid++;
        }
        else
            cout<<"Bid Pass By West";


        trump=get_trump_card(bid_player);
    }
    /////////////////////////////////////////////////////////////////////
    if(w==2)
    {
        asdgraphics::setColor(11);
        info.put_messages("East is thinking.");
        info.display_instuctions();
        asdgraphics::locate(95,22);
        asdgraphics::setColor(14);
        cout<<sm[0];
        asdgraphics::msleep(1500);
        asdgraphics::locate(95,22);
        cout<<" ";
        info.clear_instuctions_line();
        asdgraphics::setColor(11);
        asdgraphics::locate(4,29);
        cout<<"Bid 15 By East";
        bid_player=2;
        target_bid=15;
        ///////////////////////////////////

        info.put_messages("North is thinking.");
        info.display_instuctions();
        asdgraphics::locate(70,14);
        asdgraphics::setColor(14);
        cout<<sm[2];
        asdgraphics::msleep(1500);
        asdgraphics::locate(70,14);
        cout<<" ";
        info.clear_instuctions_line();
        asdgraphics::setColor(11);
        asdgraphics::locate(4,30);
        if(target_bid<get_max_bit(1))
        {
            cout<<"Bid "<<target_bid+1<<" By North";
            bid_player=1;
            target_bid++;
        }
        else
            cout<<"Bid Pass By North";
        /////////////////////////////////////////

        info.put_messages("West is thinking.");
        info.display_instuctions();
        asdgraphics::locate(46,22);
        asdgraphics::setColor(14);
        cout<<sm[1];
        asdgraphics::msleep(1500);
        asdgraphics::locate(46,22);
        cout<<" ";
        info.clear_instuctions_line();
        asdgraphics::setColor(11);
        asdgraphics::locate(4,31);
        if(target_bid<get_max_bit(0))
        {
             cout<<"Bid "<<target_bid+1<<" By West";
             bid_player=0;
             target_bid++;
        }
        else
            cout<<"Bid Pass By West";
        ////////////////////////////////////////////

        asdgraphics::locate(70,29);
        asdgraphics::setColor(14);
        cout<<sm[3];
        asdgraphics::setColor(11);
        temp=show_user_bid_box_Make_bid();
        if(temp==100)
            return 100;
        put_user_max_bid(temp);
        asdgraphics::locate(4,32);
        if(target_bid<temp)
        {
            cout<<"Bid "<<temp<<" By South";
            bid_player=3;
            target_bid=temp;
        }
        else
            cout<<"Bid Pass By South";
        asdgraphics::locate(70,29);
        cout<<" ";
        ////////////////////////////////////

        asdgraphics::setColor(11);
        info.put_messages("East is thinking.");
        info.display_instuctions();
        asdgraphics::locate(95,22);
        asdgraphics::setColor(12);
        cout<<sm[0];
        asdgraphics::msleep(1500);
        asdgraphics::locate(95,22);
        cout<<" ";
        info.clear_instuctions_line();
        asdgraphics::setColor(11);
        asdgraphics::locate(4,33);
        if(target_bid<get_max_bit(2) && bid_player!=2)
        {
            cout<<"Bid "<<target_bid+1<<" By East";
            bid_player=2;
            target_bid++;
        }
        else
            cout<<"Bid Pass By East";
        ////////////////////////////////

        info.put_messages("North is thinking.");
        info.display_instuctions();
        asdgraphics::locate(70,14);
        asdgraphics::setColor(12);
        cout<<sm[2];
        asdgraphics::msleep(1500);
        asdgraphics::locate(70,14);
        cout<<" ";
        info.clear_instuctions_line();
        asdgraphics::setColor(11);
        asdgraphics::locate(4,34);
        if(target_bid<get_max_bit(1) && bid_player!=1)
        {
            cout<<"Bid "<<target_bid+1<<" By North";
            bid_player=1;
            target_bid++;
        }
        else
            cout<<"Bid Pass By North";
        //////////////////////////////////////

        info.put_messages("West is thinking.");
        info.display_instuctions();
        asdgraphics::locate(46,22);
        asdgraphics::setColor(12);
        cout<<sm[1];
        asdgraphics::msleep(1500);
        asdgraphics::locate(46,22);
        cout<<" ";
        info.clear_instuctions_line();
        asdgraphics::setColor(11);
        asdgraphics::locate(4,35);
        if(target_bid<get_max_bit(0) && bid_player!=0)
        {
             cout<<"Bid "<<target_bid+1<<" By West";
             bid_player=0;
             target_bid++;
        }
        else
            cout<<"Bid Pass By West";
        //////////////////////////////////

        asdgraphics::locate(70,29);
        asdgraphics::setColor(12);
        cout<<sm[3];
        asdgraphics::setColor(11);
        asdgraphics::locate(4,36);
        if(bid_player!=3)
        {
            temp=show_user_bid_box_Make_bid();
            if(temp==100)
                return 100;
            asdgraphics::locate(4,36);
            if(temp>target_bid)
            {
                put_user_max_bid(temp);
                cout<<"Bid "<<temp<<" By South";
                bid_player=3;
                target_bid=temp;
            }
            else
                cout<<"Bid Pass By South";
        }
        else
            cout<<"Bid Pass By South";
        asdgraphics::locate(70,29);
        cout<<" ";
        trump=get_trump_card(bid_player);
    }
    ////////////////////////////////////////////////////////////////////////
    if(w==3)
    {
        asdgraphics::setColor(11);
        info.put_messages("North is thinking.");
        info.display_instuctions();
        asdgraphics::locate(70,14);
        asdgraphics::setColor(14);
        cout<<sm[2];
        asdgraphics::msleep(1500);
        asdgraphics::locate(70,14);
        cout<<" ";
        info.clear_instuctions_line();
        asdgraphics::setColor(11);
        asdgraphics::locate(4,29);
        cout<<"Bid 15 By North";
        bid_player=1;
        target_bid=15;
        ///////////////////////////////////////

        info.put_messages("West is thinking.");
        info.display_instuctions();
        asdgraphics::locate(46,22);
        asdgraphics::setColor(14);
        cout<<sm[1];
        asdgraphics::msleep(1500);
        asdgraphics::locate(46,22);
        cout<<" ";
        info.clear_instuctions_line();
        asdgraphics::setColor(11);
        asdgraphics::locate(4,30);
        if(target_bid<get_max_bit(0))
        {
             cout<<"Bid "<<target_bid+1<<" By West";
             bid_player=0;
             target_bid++;
        }
        else
            cout<<"Bid Pass By West";
        ////////////////////////////////////

        asdgraphics::locate(70,29);
        asdgraphics::setColor(14);
        cout<<sm[3];
        asdgraphics::setColor(11);
        temp=show_user_bid_box_Make_bid();
        if(temp==100)
            return 100;
        put_user_max_bid(temp);
        asdgraphics::locate(4,31);
        if(target_bid<temp)
        {
            cout<<"Bid "<<temp<<" By South";
            bid_player=3;
            target_bid=temp;
        }
        else
            cout<<"Bid Pass By South";
        asdgraphics::locate(70,29);
        cout<<" ";
        ////////////////////////////////////////

        asdgraphics::setColor(11);
        info.put_messages("East is thinking.");
        info.display_instuctions();
        asdgraphics::locate(95,22);
        asdgraphics::setColor(14);
        cout<<sm[0];
        asdgraphics::msleep(1500);
        asdgraphics::locate(95,22);
        cout<<" ";
        info.clear_instuctions_line();
        asdgraphics::setColor(11);
        asdgraphics::locate(4,32);
        if(target_bid<get_max_bit(2))
        {
            cout<<"Bid "<<target_bid+1<<" By East";
            bid_player=2;
            target_bid++;
        }
        else
            cout<<"Bid Pass By East";
        //////////////////////////////////////////

        asdgraphics::setColor(11);
        info.put_messages("North is thinking.");
        info.display_instuctions();
        asdgraphics::locate(70,14);
        asdgraphics::setColor(12);
        cout<<sm[2];
        asdgraphics::msleep(1500);
        asdgraphics::locate(70,14);
        cout<<" ";
        info.clear_instuctions_line();
        asdgraphics::setColor(11);
        asdgraphics::locate(4,33);
        if(target_bid<get_max_bit(1) && bid_player!=1)
        {
            cout<<"Bid "<<target_bid+1<<" By North";
            bid_player=1;
            target_bid++;
        }
        else
            cout<<"Bid Pass By North";
        /////////////////////////////////

        info.put_messages("West is thinking.");
        info.display_instuctions();
        asdgraphics::locate(46,22);
        asdgraphics::setColor(12);
        cout<<sm[1];
        asdgraphics::msleep(1500);
        asdgraphics::locate(46,22);
        cout<<" ";
        info.clear_instuctions_line();
        asdgraphics::setColor(11);
        asdgraphics::locate(4,34);
        if(target_bid<get_max_bit(0) && bid_player!=0)
        {
             cout<<"Bid "<<target_bid+1<<" By West";
             bid_player=0;
             target_bid++;
        }
        else
            cout<<"Bid Pass By West";
        ///////////////////////////////////////

        asdgraphics::locate(70,29);
        asdgraphics::setColor(12);
        cout<<sm[3];
        asdgraphics::setColor(11);
        asdgraphics::locate(4,35);
        if(bid_player!=3)
        {
            temp=show_user_bid_box_Make_bid();
            if(temp==100)
                return 100;
            asdgraphics::locate(4,35);
            if(temp>target_bid)
            {
                put_user_max_bid(temp);
                cout<<"Bid "<<temp<<" By South";
                bid_player=3;
                target_bid=temp;
            }
            else
                cout<<"Bid Pass By South";
        }
        else
            cout<<"Bid Pass By South";
        asdgraphics::locate(70,29);
        cout<<" ";
        /////////////////////////////////

        info.put_messages("East is thinking.");
        info.display_instuctions();
        asdgraphics::locate(95,22);
        asdgraphics::setColor(12);
        cout<<sm[0];
        asdgraphics::msleep(1500);
        asdgraphics::locate(95,22);
        cout<<" ";
        info.clear_instuctions_line();
        asdgraphics::setColor(11);
        asdgraphics::locate(4,36);
        if(target_bid<get_max_bit(2) && bid_player!=2)
        {
            cout<<"Bid "<<target_bid+1<<" By East";
            bid_player=2;
            target_bid++;
        }
        else
            cout<<"Bid Pass By East";
        trump=get_trump_card(bid_player);
    }


    asdgraphics::locate(16,17);
    if(bid_player==0)
    {
        cout<<"Bid "<<target_bid<<" By West";
    }
    else if(bid_player==1)
    {
        cout<<"Bid "<<target_bid<<" By North";
    }
    else if(bid_player==2)
    {
        cout<<"Bid "<<target_bid<<" By East";
    }
    else if(bid_player==3)
    {
        cout<<"Bid "<<target_bid<<" By South";
        int op=user_trump_options();
        if(op==0)
        {
            card_provider_2nd();
            trump=player[3].which_type_card(player[3].get_card(6));
        }
        else if(op==1)
        {
            card_provider_2nd();
            trump=player[3].which_type_card(player[3].get_card(5));
        }
        else if(op==2)
        {
            info.put_messages("Choose a card which one you want to make trump.");
            info.display_instuctions();
            trump=make_user_trump();
            info.clear_instuctions_line();
            card_provider_2nd();
        }
    }
    if(bid_player!=3)
    {

        if(bid_player!=1)
            Double=ask_about_double();
        card_provider_2nd();
        cardBoy.view_hide_trump_card(trump,38,4);
    }
    else
        cardBoy.view_visual_trump_card(trump,38,4);

    assembling_card();
    return 1;
}
/////////////////////////////////////////////////////////////////////////////////////////////

int board_setup_and_view_setup::search_marriage()
{
    for(int i=0; i<3; i++)
    {
        Marriage[i]=0;
        for(int j=0; j<player[i].get_top(); j++)
        {
            if(trump*8+4==player[i].get_card(j))
                Marriage[i]++;
            else if(trump*8+5==player[i].get_card(j))
                Marriage[i]++;
        }
        if(Marriage[i]==2)
            Marriage[i]=1;
        else
            Marriage[i]=0;
    }
    return 0;
}

