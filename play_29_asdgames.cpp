#include"play_29_asdgames.h"
///////////////////////////////////////////////////////////////////////////////////////

int Play_29_ASDgames::send_wining_messege(int win)
{
    start_game game;
    asdgraphics::setColor(11);
    char ch[5];
    ch[0]=223;
    ch[1]=222;
    ch[2]=221;
    ch[3]=220;
    ch[4]=219;
    int x=54;
    int y=16;
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

    if(win==1)
    {
        asdgraphics::locate(56,19);
        cout<<" Congrats! You Win A Games.";
        asdgraphics::locate(56,21);
        cout<<" You Achieve A New Win Point.";
        asdgraphics::locate(56,22);
        cout<<" And Achieve A New Rank Point.";
        asdgraphics::locate(56,23);
        cout<<" Thanks For Staying With Us.";
        asdgraphics::locate(58,25);
        cout<<"         [ENTER]";
    }
    else if(win==0)
    {
        asdgraphics::locate(56,19);
        cout<<" In Sorrow! You Lost A Games.";
        asdgraphics::locate(56,21);
        cout<<" You Lost A New Win Point.";
        asdgraphics::locate(56,22);
        cout<<" And Lost A New Rank Point.";
        asdgraphics::locate(56,23);
        cout<<" Thanks For Stay With Us.";
        asdgraphics::locate(58,25);
        cout<<"         [ENTER]";
    }
    while(1)
    {
        char c;
        c=asdgraphics::getkey();
        if(c==1)
        {
            for(int i=0; i<13; i++)
            {
                asdgraphics::locate(x,y+i);
                cout<<"                                     ";
            }
            return  0;
        }
        else
            cout<<'\a';
    }
    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////

void Play_29_ASDgames::play_asd_29(void)
{
    start_game game[40];
    int step=0,error;
    game[step].playerCareer_setup();
    while(1)
    {
        while(1)
        {
            Career cr;
            if(cr.get_computer_result()>=6 || cr.get_computer_result()<=-6 || cr.get_user_result()>=6 || cr.get_user_result()<=-6)
            {
                if(cr.get_user_result()>=6 || cr.get_computer_result()<=-6)
                {
                    cr.put_user_total_win(cr.get_user_total_win()+1);
                    send_wining_messege(1);
                }
                else
                    send_wining_messege(0);
                cr.put_user_total_play(cr.get_user_total_play()+1);
                cr.put_user_rank(3);
                cr.put_user_result(0);
                cr.put_computer_result(0);
                cr.SaveAllCareer("NAME");
                break;
            }
            else
                error=game[step].start_A_board_circle();
            if(error==0)
            {
                step++;
                break;
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////

void Play_29_ASDgames::restart_A_new_deal(void)
{
    start_game game;
    while(1)
    {
        while(1)
        {
            Career cr;
            if(cr.get_computer_result()==6 || cr.get_computer_result()==-6 || cr.get_user_result()==6 || cr.get_user_result()==-6)
            {
                if(cr.get_user_result()==6 || cr.get_computer_result()==-6)
                {
                    cr.put_user_total_win(cr.get_user_total_win()+1);
                    send_wining_messege(1);
                }
                else
                    send_wining_messege(0);
                cr.put_user_total_play(cr.get_user_total_play()+1);
                cr.put_user_result(0);
                cr.put_computer_result(0);
                cr.SaveAllCareer("NAME");
                break;
            }
            else
                game.start_A_board_circle();
        }

    }
}

////////////////////////////////////////////////////////////////////////////////////////////

void Play_29_ASDgames::restart_Game(void)
{
    start_game game;
    Career Cr;
    Cr.put_user_total_play(Cr.get_user_total_play()+1);
    Cr.put_user_result(0);
    Cr.put_computer_result(0);
    Cr.SaveAllCareer("NAME");
    while(1)
    {
        while(1)
        {
            Career cr;
            if(cr.get_computer_result()==6 || cr.get_computer_result()==-6 || cr.get_user_result()==6 || cr.get_user_result()==-6)
            {
                if(cr.get_user_result()==6 || cr.get_computer_result()==-6)
                {
                    cr.put_user_total_win(cr.get_user_total_win()+1);
                    send_wining_messege(1);
                }
                else
                    send_wining_messege(0);
                cr.put_user_result(0);
                cr.put_computer_result(0);
                cr.SaveAllCareer("NAME");
                break;
            }
            else
                game.start_A_board_circle();
        }

    }
}

////////////////////////////////////////////////////////////////////////////////////////////

char Play_29_ASDgames::How_to_play(void)
{
    system("Help.txt");
    ch=getch();
    return ch;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

char Play_29_ASDgames::Quit(void)
{
    asdgraphics::locate(1,43);
    exit(0);
}

//////////////////////////////////////////////////////////////////////////////////////////

char Play_29_ASDgames::toolber_menu_option(char ch)
{
    if(ch=='r' || ch=='R')
    {
        restart_Game();
    }
    else if(ch=='b' || ch=='B')
    {
        play_asd_29();
    }
    else if(ch=='h' || ch=='H')
    {
        ch=How_to_play();
    }
    else if(ch=='Q' || ch=='q')
    {
        ch=Quit();
    }
    else
        return ch;

}
