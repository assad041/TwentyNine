#include"start_game.h"

///////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////

void start_game::View_Calculated_Rating()
{
    Career Cr;
    asdgraphics::locate(17,14);
    asdgraphics::setColor(15);
    cout<<"* * * * * * *";
    int r=Cr.get_user_total_win()/2;
    if(r<8)
    {
        asdgraphics::locate(17,14);
        asdgraphics::setColor(14);
        for(int i=0; i<r; i++)
            cout<<"* ";
    }
    else if(r<15)
    {
        asdgraphics::locate(17,14);
        asdgraphics::setColor(14);
        cout<<"* * * * * * *";
        asdgraphics::locate(17,14);
        asdgraphics::setColor(10);
        for(int i=7; i<r; i++)
            cout<<"* ";
    }
    else if(r<22)
    {
        asdgraphics::locate(17,14);
        asdgraphics::setColor(10);
        cout<<"* * * * * * *";
        asdgraphics::locate(17,14);
        asdgraphics::setColor(12);
        for(int i=14; i<r; i++)
            cout<<"* ";
    }
    else
    {
        asdgraphics::locate(17,14);
        asdgraphics::setColor(12);
        cout<<" GAME OVER";
    }
    asdgraphics::setColor(11);
}

///////////////////////////////////////////////////////////////////////////////////////

void start_game::View_Calculated_Result(void)
{
    Career Cr;
    char ch[5];
    ch[0]=176;
    ch[1]=3;
    ch[2]=4;
    ch[3]=5;
    ch[4]=6;
    asdgraphics::locate(17,23);
    cout<<" "<<ch[0]<<" "<<ch[0]<<" "<<ch[0]<<" "<<ch[0]<<" "<<ch[0]<<" "<<ch[0];
    asdgraphics::locate(17,26);
    cout<<" "<<ch[0]<<" "<<ch[0]<<" "<<ch[0]<<" "<<ch[0]<<" "<<ch[0]<<" "<<ch[0];
    asdgraphics::locate(17,23);
    if(Cr.get_computer_result()>0)
    {
        asdgraphics::setColor(12);
        for(int i=0; i<Cr.get_computer_result(); i++)
        {
            if(i<=6)
                cout<<" "<<ch[1];
        }
    }
    else if(Cr.get_computer_result()<0)
    {
        asdgraphics::setColor(15);
        for(int i=0; i>Cr.get_computer_result(); i--)
        {
            if(i>=-6)
                cout<<" "<<ch[3];
        }
    }
    asdgraphics::locate(17,26);
    if(Cr.get_user_result()>0)
    {
        asdgraphics::setColor(12);
        for(int i=0; i<Cr.get_user_result(); i++)
        {
            if(i<=6)
                cout<<" "<<ch[2];
        }
    }
    else if(Cr.get_user_result()<0)
    {
        asdgraphics::setColor(15);
        for(int i=0; i>Cr.get_user_result(); i--)
        {
            if(i>=-6)
                cout<<" "<<ch[4];
        }
    }
    asdgraphics::setColor(11);

}

//////////////////////////////////////////////////////////////////////////////////////

void start_game::Update_Score_Board()
{
    Career Cr;
    asdgraphics::setColor(11);
    asdgraphics::locate(103,4);
    cout<<"   ";
    asdgraphics::locate(103,4);
    cout<<Cr.get_user_rank()-2;
    asdgraphics::locate(17,5);
    cout<<Cr.get_user_name();
    asdgraphics::locate(20,8);
    cout<<Cr.get_user_total_play()<<" times";
    asdgraphics::locate(20,11);
    cout<<Cr.get_user_total_win()<<" times";
    View_Calculated_Rating();
    asdgraphics::locate(16,17);
    cout<<"      N/A      ";
    asdgraphics::locate(17,20);
    cout<<"     N/A     ";
    View_Calculated_Result();
}

///////////////////////////////////////////////////////////////////////////////////////

void start_game::playerCareer_setup()
{
    system("mode 110, 43");
    asdgraphics::hidecursor();
    menu.main_menu_oparetion();
    frame.clear_free_space();
    Let.show_AllPlayingCard();
    menu.Loading_veiw();
    asdgraphics::cls();
    frame.view_common_menu();
}

///////////////////////////////////////////////////////////////////////////////////////

void start_game::serve_card_among_AllPlayer()
{
    Career cr;
    int w=cr.get_user_rank()%4;
    asdgraphics::setColor(15);
    if(w==0)
    {
        Let.view_west_card();
        Let.view_south_card();
        Let.view_east_card();
        Let.view_north_card();
    }
    else if(w==1)
    {
        Let.view_south_card();
        Let.view_east_card();
        Let.view_north_card();
        Let.view_west_card();
    }
    else if(w==2)
    {
        Let.view_east_card();
        Let.view_north_card();
        Let.view_west_card();
        Let.view_south_card();
    }
    else if(w==3)
    {
        Let.view_north_card();
        Let.view_west_card();
        Let.view_south_card();
        Let.view_east_card();
    }

}

////////////////////////////////////////////////////////////////////////////////////////

int start_game::start_A_board_circle()
{
    Let.constructor();
    Let.clear_recent_history();
    Let.clear_pot_and_pot_table();
    Update_Score_Board();
    int error=Let.ask_about_starting_A_new_deal();
    if(error==0)
    {
        asdgraphics::cls();
        frame.view_common_menu();
        return 0;
    }
    Let.card_provider_1st();
    serve_card_among_AllPlayer();
    int err=Let.make_board_bid_and_trump();
    if(err==100)
    {
        asdgraphics::cls();
        frame.view_common_menu();
        return 0;
    }
    asdgraphics::msleep(1000);
    serve_card_among_AllPlayer();
    Let.set_card();
    error=Let.Play_eight_lead();
    if(error==0)    return 0;
    Update_Score_Board();
    return 1;
}

