#include"Career.h"

/////////////////////////////////////////////////////////////////////////////////////////////////

void Career::put_name(string s, int i)
{
    name[i]=s;
    ranking[i]=3;
    total_win[i]=0;
    result[i][0]=0;
    result[i][1]=0;
    total_play[i]=1;
    counter++;
}

/////////////////////////////////////////////////////////////////////////////////////////////////

void Career::SaveAllCareer(const string & fname)
{
    string strFileName="Save_game\\"+fname+".dat";
    ofstream ofsSaveAllCareer(strFileName.c_str());
    ofsSaveAllCareer<<counter<<endl<<user<<endl;
    for(int i=0; i<15; i++)
    ofsSaveAllCareer<<name[i]<<endl;
    for(int i=0; i<15; i++)
    SaveCareer(name[i],i);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

void Career::LoadAllCareer(const string & fname)
{
    string strFileName="Save_game\\"+fname+".dat";
    ifstream ifsLoadAllCareer(strFileName.c_str());
    ifsLoadAllCareer>>counter>>user;
    for(int i=0; i<15; i++)
    ifsLoadAllCareer>>name[i];
    for(int i=0; i<15; i++)
    LoadCareer(name[i],i);
}

/////////////////////////////////////////////////////////////////////////////////////////////////

void Career::SaveCareer(const string & fname,int i)
{
    string strFileName="Save_game\\"+fname+".dat";
    ofstream ofsSaveCareer(strFileName.c_str());
    ofsSaveCareer<<name[i]<<endl<<ranking[i]<<endl<<total_win[i]<<endl<<result[i][0]<<endl<<result[i][1]<<endl<<total_play[i];

}

//////////////////////////////////////////////////////////////////////////////////////////////////

void Career::LoadCareer(const string & fname,int i)
{

    string strFileName="Save_game\\"+fname+".dat";
    ifstream ifsLoadCareer(strFileName.c_str());
    ifsLoadCareer>>name[i]>>ranking[i]>>total_win[i]>>result[i][0]>>result[i][1]>>total_play[i];
}


/////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////

