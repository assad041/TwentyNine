#ifndef _TOOL_BER_H_
#define _TOOL_BER_H_

class tool_ber
{
private:
    char ch;
public:
    int restart_Game()
    {
        Career Cr;
        Cr.put_user_total_play(Cr.get_user_total_play()+1);
        Cr.put_user_result(0);
        Cr.put_computer_result(0);
        Cr.SaveAllCareer("NAME");
        return 1;
    }

////////////////////////////////////////////////////////////////////////////////////////////////////

    char How_to_play(void)
    {
        system("Help.txt");
        ch=asdgraphics::getkey();
        return ch;
    }

    char About(void)
    {
        system("About.txt");
        ch=asdgraphics::getkey();
        return ch;
    }


////////////////////////////////////////////////////////////////////////////////////////////////////

    char Quit(void)
    {
        asdgraphics::locate(1,43);
        asdgraphics::cls();
        exit(0);
    }

//////////////////////////////////////////////////////////////////////////////////////////

    char toolber_menu_option(char ch)
    {
        if(ch=='r' || ch=='R')
        {
            restart_Game();
            return 'r';
        }
        else if(ch=='a' || ch=='A')
        {
            ch=About();
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
        if(ch=='a' || ch=='A')
        {
            ch=About();
        }
        else if(ch=='h' || ch=='H')
        {
            ch=How_to_play();
        }

        return ch;
    }

};


#endif
