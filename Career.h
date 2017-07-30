#ifndef _CAREER_H_
#define _CAREER_H_

#include <fstream>
#include<string>
using namespace std;

class Career
{
private:
    string name[50];
    int ranking[50];
    int total_win[50];
    int result[50][2];
    int total_play[50];
    int counter;
    int user;
public:
    Career(): counter(0)
    {    LoadAllCareer("NAME");   }
    string get_name(int i){return name[i];}
    void put_name(string s, int i);
    int get_counter(){return counter;}
    string get_user_name(){    return name[user];   }
    int get_user_rank(){    return ranking[user];   }
    void put_user_rank(int Rank){    ranking[user]=Rank;    }
    int get_user_total_win(){   return total_win[user];  }
    void put_user_total_win(int win){   total_win[user]=win;    }
    int get_user_result(){   return result[user][0];   }
    void put_user_result(int t_result){  result[user][0]=t_result;  }
    int get_computer_result(){  return result[user][1];     }
    void put_computer_result(int c_result){  result[user][1]=c_result;   }
    int get_user_total_play(){  return total_play[user];    }
    void put_user_total_play(int play){    total_play[user]=play;    }
    int get_fix_user(){    return user; }
    void put_fix_user(int a){    user=a-1;   }
    void SaveCareer(const string & fname,int i);
    void LoadCareer(const string & fname,int i);
    void SaveAllCareer(const string & fname);
    void LoadAllCareer(const string & fname);

};


#endif
