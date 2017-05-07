#pragma once

#include <list>
#include <string>

using std::string;
using std::wstring;
using std::list;

using Level = unsigned int;

namespace adopt_a_freshman {

struct SocialMedia
{
    wstring fbhook;
    wstring gphook;
};

struct Habits {
    list<wstring> recreations;
    list<wstring> entertainments;
    list<wstring> disciplines;
};


struct Profile
{
    wstring name;
    wstring university;
    wstring field;
    string telephone;
    string avatar;
    int semester;
    string user_status;
    SocialMedia user_medias;

    Level level;
    Habits habit;
};

struct UserRegistry
{
    string username;
    string password;
    int token;
    Profile profile;
};

struct Adoption {
  Profile veteran;
  Profile freshman;
};

list<UserRegistry> users_veterans;
list<UserRegistry> users_freshmans;
list<Adoption> adoptions, adoption_requests_by_freshman, adoption_request_by_veteran;
int token=0;

list<wstring> entertainments = { 
  L"Dota", 
  L"LoL", 
  L"GoT" 
};

list<wstring> disciplines = { 
  L"Cálculo", 
  L"Física", 
  L"Geometria", 
  L"Literatura", 
  L"Algebra", 
  L"Programação" 
};

list<wstring> university = {};
list<wstring> fields = {};

struct Report {
  string title;
  string description;
};

list<Report> bug_reports;

} /* adopt_a_freshman */ 
