#include"games_table_view_management.cpp"

using namespace std;


class messagess
{
private:
    string messages1;
public:
    void put_messages(string s)
    {
        messages1=s;
    }
    void display_messages(void)
    {
        if(messages1=="/0")
            cout<<"               EMPTY";
        else
        {
            cout<<messages1;
            messages1="/0";
        }
        asdgraphics::locate(99,41);
    }
};


/////////////////////////////////////////////////////////////////////////////////////////////


class instuctions: public messagess
{
private:
    char ch;
public:
    instuctions(): ch(219)
    {        }
    void clear_instuctions_line();

    void display_instuctions(void)
    {
        asdgraphics::locate(16,41);
        asdgraphics::setColor(12);
        display_messages();
        asdgraphics::setColor(15);
    }
};



////////////////////////////////////////////////////////////////////////////////////


void instuctions::clear_instuctions_line()
{
    asdgraphics::setColor(0);
    asdgraphics::locate(16,41);
    for(int j=16; j<108; j++)
         cout<<ch;
    asdgraphics::locate(99,41);
}




///////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////

class menu_LIST
{
private:
    messagess messages1[6];
    void clear_menu_list();
public:
    void put_messages(string s,int i)
    {
        messages1[i].put_messages(s);
    }

    void display_menu(void)
    {
        clear_menu_list();
        for(int i=0, j=0; i<24; j++, i+=4 )
        {
            asdgraphics::setColor(12);
            asdgraphics::locate(39,10+i);
            messages1[j].display_messages();
            asdgraphics::setColor(15);
        }
    }
};


//////////////////////////////////////////////////////////////////////////

void menu_LIST::clear_menu_list()
{
    for(int i=0; i<24; i+=4)
    {
        asdgraphics::setColor(0);
        asdgraphics::locate(39,10+i);
        char ch=219;
        cout<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch;
        asdgraphics::locate(99,41);
    }
}



//////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////


class menu_LIST_maintenance
{
private:
    menu_LIST List;
    Career cr;
    instuctions in;
public:
    void show_main_menu(void);
    void show_new_game(void);
    int show_create_new(void);
    void show_options(void);
    void show_new_game_next(void);
    void show_load_game(void);
    void show_next_load_game(void);
};

//////////////////////////////////////////////////////////////////////////////////////


void menu_LIST_maintenance::show_main_menu(void)
{
    List.put_messages("           NEW GAME [N]",0);
    List.put_messages("          LOAD GAMES [L]",1);
    List.put_messages("           OPTIONS [O]",2);
    List.put_messages("         HOW TO PLAY [H]",3);
    List.put_messages("            ABOUT [A]",4);
    List.put_messages("            QUIT [QQ]",5);
    List.display_menu();
}

//////////////////////////////////////////////////////////////////////////////////////


void menu_LIST_maintenance::show_new_game(void)
{
    List.put_messages("           CREATE NEW [C]",0);
    string str;
    for(int i=0; i<cr.get_counter(); i++)
    {
        if(i==0){   str="             "+cr.get_name(0)+" [1]";
            List.put_messages(str,1);   }
        else if(i==1){  str="             "+cr.get_name(1)+" [2]";
            List.put_messages(str,2);   }
        else if(i==2){  str="             "+cr.get_name(2)+" [3]";
            List.put_messages(str,3);   }
        else if(i==3){  str="             "+cr.get_name(3)+" [4]";
            List.put_messages(str,4);   }
    }
    List.put_messages("             NEXT [N]",5);
    List.display_menu();
}

///////////////////////////////////////////////////////////////////////////////////////


int menu_LIST_maintenance::show_create_new()
{
    List.put_messages("         ENTER YOUR NAME",0);
    List.display_menu();
    in.put_messages("Plz Enter Your Name:");
    in.display_instuctions();
    asdgraphics::setColor(9);
    char s[100];
    asdgraphics::locate(37,41);
    //gets(s);
    scanf("%s",s);
    strupr(s);
    asdgraphics::setColor(15);
    cr.put_fix_user(cr.get_counter()+1);
    cr.put_name(s,cr.get_counter());
    in.clear_instuctions_line();
    cr.SaveAllCareer("NAME");
    return cr.get_fix_user()+1;
}

///////////////////////////////////////////////////////////////////////////////////////


void menu_LIST_maintenance::show_new_game_next(void)
{
    string str;
    for(int i=4; i<cr.get_counter(); i++)
    {
        if(i==4){   str="             "+cr.get_name(4)+" [5]";
            List.put_messages(str,0);   }
        else if(i==5){  str="             "+cr.get_name(5)+" [6]";
            List.put_messages(str,1);   }
        else if(i==6){  str="             "+cr.get_name(6)+" [7]";
            List.put_messages(str,2);   }
        else if(i==7){  str="             "+cr.get_name(7)+" [8]";
            List.put_messages(str,3);   }
        else if(i==8){  str="             "+cr.get_name(8)+" [9]";
            List.put_messages(str,4);   }
    }
    List.put_messages("      BAKE TO MAIN MENU [B]",5);
    List.display_menu();
}

///////////////////////////////////////////////////////////////////////////////////////


void menu_LIST_maintenance::show_load_game(void)
{
    string str;
    for(int i=0; i<cr.get_counter(); i++)
    {
        if(i==0){   str="             "+cr.get_name(0)+" [1]";
            List.put_messages(str,0);   }
        else if(i==1){  str="             "+cr.get_name(1)+" [2]";
            List.put_messages(str,1);   }
        else if(i==2){  str="             "+cr.get_name(2)+" [3]";
            List.put_messages(str,2);   }
        else if(i==3){  str="             "+cr.get_name(3)+" [4]";
            List.put_messages(str,3);   }
        else if(i==4){  str="             "+cr.get_name(4)+" [5]";
            List.put_messages(str,4);   }
    }
    List.put_messages("             NEXT  [N]",5);
    List.display_menu();
}

////////////////////////////////////////////////////////////////////////////////////////


void menu_LIST_maintenance::show_next_load_game(void)
{
    string str;
    for(int i=5; i<cr.get_counter(); i++)
    {
        if(i==5){   str="             "+cr.get_name(5)+" [6]";
            List.put_messages(str,0);   }
        else if(i==6){  str="             "+cr.get_name(6)+" [7]";
            List.put_messages(str,1);   }
        else if(i==7){  str="             "+cr.get_name(7)+" [8]";
            List.put_messages(str,2);   }
        else if(i==8){  str="             "+cr.get_name(8)+" [9]";
            List.put_messages(str,3);   }
        else if(i==9){  str="             "+cr.get_name(9)+" [10]";
            List.put_messages(str,4);   }
    }
    List.put_messages("      BAKE TO MAIN MENU [B]",5);
    List.display_menu();
}

///////////////////////////////////////////////////////////////////////////////////////////

void menu_LIST_maintenance::show_options(void)
{
    List.put_messages("           TRAINEE [T]",0);
    List.put_messages("          BEGINNER  [G]",1);
    List.put_messages("        PROFESSIONAL  [P]",2);
    List.put_messages("           EXPART    [E]",3);
    List.put_messages("           MASTER  [M]",4);
    List.put_messages("      BAKE TO MAIN MENU [B]",5);
    List.display_menu();
}


///////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////

class Total_menu_view_controller
{
private:
    games_table_view_management frame;
    menu_LIST_maintenance mg;
    instuctions ob;
    Career ccr;
    char ch;
    int x;
protected:
    char New_game(void);
    char Load_game(void);
    char Options(void);
    char How_to_play(void);
    char About(void);
    char Quit(void);
    char Wrong_input(void);
public:
    int main_menu_oparetion();
    void Loading_veiw();
};


///////////////////////////////////////////////////////////////////////////////////////

char Total_menu_view_controller::New_game(void)
{
    mg.show_new_game();
    ch=getch();
    while(1){
        if(ch=='C'|| ch=='c')
        {   x=mg.show_create_new();
            return x;}
        else if(ch>'0'&&ch<'5'&& ch<ccr.get_counter()+1+'0')
        {   x=ch-'0'; ccr.put_fix_user(x);
            ccr.put_computer_result(0);
            ccr.put_user_result(0);
            ccr.put_user_total_play(ccr.get_user_total_play()+1);
            ccr.SaveAllCareer("NAME"); return x;}
        else if(ch=='N' || ch=='n')
        {   mg.show_new_game_next();
            ch=getch();
            while(1)
            {
                if(ch=='B' || ch=='b')
                {   mg.show_main_menu();
                ch=getch();
                return ch;}
                else if(ch>'4'&&ch<='9'&& ch< ccr.get_counter()+1+'0')
                {   x=ch-'0'; ccr.put_fix_user(x);
                    ccr.put_computer_result(0);
                    ccr.put_user_result(0);
                    ccr.put_user_total_play(ccr.get_user_total_play()+1);
                    ccr.SaveAllCareer("NAME"); return x; }
                else
                    ch=Wrong_input(); } }
        else
            ch=Wrong_input();
        }
}


///////////////////////////////////////////////////////////////////////////////////////////

char Total_menu_view_controller::Load_game(void)
{
    mg.show_load_game();
    ch=getch();
    while(1)
    {
        if(ch=='N'||ch=='n')
        {   mg.show_next_load_game();
            ch=getch();
            if(ch=='B' || ch=='b')
            {   mg.show_main_menu();
                ch=getch();
                return ch;}
            else if(ch>'5'&&ch<='9'&& ch<ccr.get_counter()+1+'0')
            {   x=ch-'0'; ccr.put_fix_user(x); ccr.SaveAllCareer("NAME"); return x;}
            else
                ch=Wrong_input();
        }
        else if(ch>'0'&&ch<'6'&& ch<ccr.get_counter()+1+'0')
        {   x=ch-'0'; ccr.put_fix_user(x); ccr.SaveAllCareer("NAME"); return x;}
        else
            ch=Wrong_input();

    }
}

////////////////////////////////////////////////////////////////////////////////////////////////

char Total_menu_view_controller::Options(void)
{
    mg.show_options();
    ch=getch();
    while(1){
        if(ch=='B' || ch=='b')
        {   mg.show_main_menu();
            ch=getch();
            return ch;}
        else if(ch=='T' || ch=='t')
        {   ob.put_messages("Games Difficulty Level Change To Trainee Successfully");
            ob.display_instuctions();
            ch=getch();
            ob.clear_instuctions_line();}
        else if(ch=='G' || ch=='g')
        {   ob.put_messages("Games Difficulty Level Change To Beginner Successfully");
            ob.display_instuctions();
            ch=getch();
            ob.clear_instuctions_line();}
        else if(ch=='P' || ch=='p')
        {   ob.put_messages("Games Difficulty Level Change To Professional Successfully");
            ob.display_instuctions();
            ch=getch();
            ob.clear_instuctions_line();}
        else if(ch=='E' || ch=='e')
        {   ob.put_messages("Games Difficulty Level Change To Expart Successfully");
            ob.display_instuctions();
            ch=getch();
            ob.clear_instuctions_line();}
        else if(ch=='M' || ch=='m')
        {   ob.put_messages("Games Difficulty Level Change To Master Successfully");
            ob.display_instuctions();
            ch=getch();
            ob.clear_instuctions_line();}
        else
            ch=Wrong_input();   }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

char Total_menu_view_controller::How_to_play(void)
{
    system("Help.txt");
    ch=getch();
    return ch;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

char Total_menu_view_controller::About(void)
{
    system("About.txt");
    ch=getch();
    return ch;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

char Total_menu_view_controller::Quit(void)
{
    asdgraphics::locate(1,43);
    exit(0);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

char Total_menu_view_controller::Wrong_input(void)
{
    ob.put_messages("You Enter Wrong Command Plz Hit a Character Which is Represent By [ ]");
    ob.display_instuctions();
    ch=getch();
    ob.clear_instuctions_line();
    return ch;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

int Total_menu_view_controller::main_menu_oparetion()
{
    frame.games_first_view();
    frame.main_menu();
    mg.show_main_menu();
    ch=getch();
    while(1)
    {
        if(ch=='N' || ch=='n'){ ch=New_game();  }
        else if(ch=='L' || ch=='l' ){   ch=Load_game(); }
        else if(ch=='O'|| ch=='o') {    ch=Options();   }
        else if(ch=='H' || ch=='h'){    ch=How_to_play();   }
        else if(ch=='A' || ch=='a'){    ch=About(); }
        else if(ch=='Q' || ch=='q'){    ch=Quit();  }
        else if(ch<10 && ch>0 ){   return ch;   }
        else{   ch=Wrong_input();   }
    }
}



void Total_menu_view_controller::Loading_veiw()
{
    asdgraphics::locate(2,41);
    char ch=219;
    asdgraphics::setColor(0);
    for(int i=0;i<15; i++)
    {
        cout<<ch;
    }
    asdgraphics::setColor(11);
    asdgraphics::locate(2,41);
    cout<<" LOADING ";
    for(int i=7; i<=100; i++)
    {
        asdgraphics::locate(11,41);
        asdgraphics::setColor(11);
        cout<<i<<'%';
        asdgraphics::setColor(10);
        if(i==100)
            asdgraphics::setColor(11);

        if(i<66)
        {
            asdgraphics::locate(15+i-7,41);
            cout<<ch;
            asdgraphics::msleep(50);
        }
        else if(i>65&&i<71)
        {
            asdgraphics::locate(15,41);
            for(int j=6; j<i; j++)
            {
                cout<<ch;
            }
            asdgraphics::msleep(100);
        }
        else if(i>70 && i<76)
        {
            asdgraphics::locate(15,41);
            for(int j=6; j<i; j++)
            {
                cout<<ch;
            }
            if(i==75)
                asdgraphics::msleep(200);
            else
                asdgraphics::msleep(100);
        }
        else if(i>75 && i<96)
        {
            asdgraphics::locate(15+i-7,41);
            cout<<ch;
            asdgraphics::msleep(45);
        }
        else if(i>95 && i<97)
        {
            asdgraphics::locate(15,41);
            for(int j=6; j<i; j++)
            {
                cout<<ch;
            }
            asdgraphics::msleep(100);
        }
        else if(i==100)
        {
            asdgraphics::locate(15,41);
            for(int j=6; j<i; j++)
            {
                cout<<ch;
            }
            asdgraphics::msleep(700);
        }
        else
        {
            asdgraphics::locate(15,41);
            for(int j=6; j<i; j++)
            {
                cout<<ch;
            }
            asdgraphics::msleep(150);
        }

    }
    asdgraphics::setColor(15);
}


////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////
