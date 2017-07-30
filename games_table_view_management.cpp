#include"games_table_view_management.h"

/////////////////////////////////////////////////////////////////////////////////////////


void games_table_view_management::constuctor(void)
{
    border[0]=222;
    border[1]=221;
    border[2]=223;
    border[3]=220;
    border[4]=219;
}


///////////////////////////////////////////////////////////////////////////////////////


int games_table_view_management::games_first_view()
{
    asdgraphics::setColor(11);
    for(int up=0; up<110; up++)
    {
         asdgraphics::locate(up+1,1);
         cout<<border[4];
    }
    for(int dw=0; dw<110; dw++)
    {
        asdgraphics::locate(dw+1,40);
        cout<<border[2];
    }
    for(int dw=0; dw<110; dw++)
    {
        asdgraphics::locate(dw+1,42);
        cout<<border[3];
    }
    for(int lft=0; lft<42; lft++)
    {
        asdgraphics::locate(1,lft+1);
        cout<<border[0];
    }
    for(int rt=0; rt<42; rt++)
    {
        asdgraphics::locate(110,rt+1);
        cout<<border[1];
    }

    asdgraphics::locate(2,41);
    cout<<"INSTRUCTIONS: ";
    asdgraphics::locate(90,41);
    return 0;
}


////////////////////////////////////////////////////////////////////////////////////////



int games_table_view_management::view_common_menu()
{
    asdgraphics::setColor(11);  // BODY COLOR//
    ///////////////////////////////////
    for(int up=0; up<110; up++)
    {   asdgraphics::locate(up+1,1);   //MENU BER 1ST ROW//
         cout<<border[2];}
    ///////////////////////////////////
    for(int up=0; up<110; up++)
    {   asdgraphics::locate(up+1,3);   //MENU BER 2ND ROW//
         cout<<border[3];}
    //////////////////////////////////
    for(int dw=0; dw<110; dw++)
    {   asdgraphics::locate(dw+1,40); //INSTRUCTION BER 1ST ROW//
        cout<<border[2];}
    /////////////////////////////////
    for(int dw=0; dw<110; dw++)
    {   asdgraphics::locate(dw+1,42); //INSTRUCTION BER 2ND ROW//
        cout<<border[3];}
    /////////////////////////////////
    for(int lft=0; lft<42; lft++)
    {   asdgraphics::locate(1,lft+1); //MAIN BER LEFT SIDE COLUM//
        cout<<border[4];}
    /////////////////////////////////
    for(int rt=0; rt<42; rt++)
    {   asdgraphics::locate(110,rt+1);//MAIN BER RIGHT SIDE COLUM//
        cout<<border[4];}
    ////////////////////////////////
    for(int up=2; up<16; up++)
    {    asdgraphics::locate(up,6);
         cout<<border[3];
         asdgraphics::locate(up,9);
         cout<<border[3];
         asdgraphics::locate(up,12);//CAREER INFORMATION 1ST COLUM//
         cout<<border[3];
         asdgraphics::locate(up,15);
         cout<<border[3];
         asdgraphics::locate(up,18);
         cout<<border[3];
         asdgraphics::locate(up,21);
         cout<<border[3];
         asdgraphics::locate(up,24);
         cout<<border[3];
         asdgraphics::locate(up,27);
         cout<<border[3];
    }
    ///////////////////////////////////
    for(int mid=4; mid<28; mid++)
    {   asdgraphics::locate(15,mid);//CAREER INFORMATION MID BER//
        cout<<border[4];}
    //////////////////////////////////
    for(int up=16; up<31; up++)
    {    asdgraphics::locate(up,6);
         cout<<border[3];
         asdgraphics::locate(up,9);
         cout<<border[3];
         asdgraphics::locate(up,12);
         cout<<border[3];
         asdgraphics::locate(up,15);//CAREER INFORMATION 2ND COLUM//
         cout<<border[3];
         asdgraphics::locate(up,18);
         cout<<border[3];
         asdgraphics::locate(up,21);
         cout<<border[3];
         asdgraphics::locate(up,24);
         cout<<border[3];
         asdgraphics::locate(up,27);
         cout<<border[3];
    }
    /////////////////////////////////
    for(int up=31; up<110; up+=27)
    {   asdgraphics::locate(up,1);
        cout<<border[4];
        asdgraphics::locate(up,2);//MENU BER DIVIDER//
        cout<<border[4];
        asdgraphics::locate(up,3);
        cout<<border[4];
    }
    //////////////////////////////////
    for(int i=4; i<40; i++)
    {   asdgraphics::locate(31,i);//CAREER INFORMATION RIGHT SIDE COLUM//
        cout<<border[4];}
    /////////////////////////////////
    asdgraphics::locate(8,2);
    cout<<" RESTART GAME [R]";
    asdgraphics::locate(34,2);
    cout<<" READ HOW TO PLAY [H]";
    asdgraphics::locate(60,2);
    cout<<"       ABOUT [A]";
    asdgraphics::locate(92,2);
    cout<<" QUIT [QQ]";
    ////////////////////////////////
    asdgraphics::locate(3,5);
    cout<<"PLAYER NAME";
    asdgraphics::locate(3,8);
    cout<<"TOTAL PLAY";
    asdgraphics::locate(3,11);
    cout<<"TOTAL WIN";
    asdgraphics::locate(3,14);
    cout<<"RANKING";
    asdgraphics::locate(3,17);
    cout<<"BID BY";
    asdgraphics::locate(3,20);
    cout<<"TRUMP CARD";
    asdgraphics::locate(3,23);
    cout<<"E/W RESULT";
    asdgraphics::locate(3,26);
    cout<<"N/S RESULT";
    ////////////////////////////////
    asdgraphics::locate(69,4);
    cout<<"NORTH";
    asdgraphics::locate(69,39);
    cout<<"SOUTH";
    asdgraphics::locate(33,22);
    cout<<"WEST";
    asdgraphics::locate(105,22);
    cout<<"EAST";
    asdgraphics::locate(39,4);
    cout<<"TRUMP";
    asdgraphics::locate(95,4);
    cout<<"DEAL NO-";
    ////////////////////////////////
    asdgraphics::locate(2,41);
    cout<<"INSTRUCTIONS: ";
    ////////////////////////////////
    asdgraphics::locate(99,41);
    return 0;
}


///////////////////////////////////////////////////////////////////////////////////////



int games_table_view_management::main_menu()
{
    asdgraphics::setColor(10);
    asdgraphics::locate(38,8);
    for(int j=0; j<37; j++)
        cout<<border[4];
    asdgraphics::locate(38,32);
    for(int j=0; j<37; j++)
        cout<<border[4];
    for(int j=0; j<23; j++)
    {
        asdgraphics::locate(38,9+j);
        cout<<border[4];
    }
    for(int j=0; j<23; j++)
    {
        asdgraphics::locate(74,9+j);
        cout<<border[4];
    }
    for(int i=0; i<20; i+=4)
    {
        asdgraphics::locate(38,12+i);
        for(int j=0; j<37; j++)
            cout<<border[4];
    }
    asdgraphics::setColor(15);
    asdgraphics::locate(99,41);
    return 0;

}


//////////////////////////////////////////////////////////////////////////////////////


void games_table_view_management::clear_free_space()
{
    asdgraphics::setColor(0);
    for(int i=4; i<40; i++)
    {
        asdgraphics::locate(38,i);
        cout<<border[4]<<border[4]<<border[4]<<border[4]<<border[4]<<border[4]<<border[4]<<border[4]<<border[4]<<border[4]<<border[4]<<border[4]<<border[4]<<border[4]<<border[4]<<border[4]<<border[4]<<border[4]<<border[4]<<border[4]<<border[4]<<border[4]<<border[4]<<border[4]<<border[4]<<border[4]<<border[4]<<border[4]<<border[4]<<border[4]<<border[4]<<border[4]<<border[4]<<border[4]<<border[4]<<border[4]<<border[4];
    }
    asdgraphics::setColor(15);
    asdgraphics::locate(99,41);
}



////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////
