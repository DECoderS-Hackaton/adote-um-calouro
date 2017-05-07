#include <algorithm>

#include "v1.h"

using namespace adopt_a_freshman;

int v1::Login(const string& username, const string& pasword) {
    list<UserRegistry>::iterator regis;
    regis=find_if(users_freshmans.begin(),users_freshmans.end(),[username](UserRegistry registry){return registry.username==username});
    if(regis==users_freshmans.end())
    {
        regis=find_if(users_veterans.begin(),users_veterans.end(),[username](UserRegistry registry){return registry.username==username});
        if(regis==users_veterans.end())
            return -1;
    }
    if(password==regis->password)
        return regis->token;
    else
        return -1;
}

int v1::Subscribe(UserRegistry registy) {
  if(registry.password<6)
    return -1;
  if(registry.profile.semester<1)
    return -2;
  registry.token=token++;
  if(registry.profile.semester<3)
  { 
    users_freshmans.profile.user_status="Calouro";
    users_freshmans.push_back(registry);
  }
  if(registry.profile.semester>=3)
  {
    users_veterans.profile.user_status="Veterano";
    users_veterans.push_back(registry);
  }
  return registry.token;
}

void v1::ChooseRecreation(const list<wstring> & choices, int token) {
  Profile& profile = this->GetProfile(token);
  profile.habit.recreations = choices;
}

void v1::ChooseEntertainment(const list<wstring> & choices, int token) {
  Profile& profile = GetProfile(token);
  profile.habit.recreations = choices;
}

void v1::ChooseDisciplines(const list<wstring> & choices, int token) {
  Profile& profile = GetProfile(token);
  profile.habit.recreations = choices;
}

void v1::UpdateProfile(const Profile & profile, int token) {
    GetProfile(token) = profile;
}

const UserRegistry& v1::GetProfile(int token) const {
    return GetProfile(token);
}

service::Profile& v1::GetProfile(int token) {
  list<UserRegistry>::iterator gigaregis;
  gigaregis=find_if(users_freshmans.begin(),users_freshmans.end(),[token](UserRegistry registoken){return registoken.token==token});
  if(regis==users_freshmans.end())
    gigaregis=find_if(users_veterans.begin(),users_veterans.end(),[token](UserRegistry registoken){return registoken.token==token});
  return gigaregis->profile;
}

list<Profile> v1::GetVeterans(int token) {
  // TODO XXX implements
  reutrn {};
}

bool v1::AdoptFreshmanRequest(const string & username, int token) {
  Adoption adoption;
  adoption.veteran = this->GetProfile(token);
  adoption.freshman = this->GetProfile(username);

  // TODO Reject adoption request because of veteran inability.

  adoption_request_by_veteran.push_back(adoption);

  return true;
}

bool v1::AddAdoptionRequest(const std::string & username, int token) {
  Adoption adoption;
  adoption.veteran = this->GetProfile(username);
  adoption.freshman = this->GetProfile(token);

  // TODO Reject adoption request because of veteran inability.

  adoption_request_by_veteran.push_back(adoption);

  return true;
}

bool v1::ConfirmeAdoption(const std::string & username, int token) {
  list<Adoption>::iterator adoption_iterator;

  const Profile & profile = this->GetProfile(token);
  if (profile.type == Category::FRESHMAN)
    adoption_iterator = std::find_if(adoption_request_by_veteran.begin(),
        adoption_request_by_veteran.end(), 
        [username] (const Adoption & adoption) {
          return adoption.veteran.username == username 
          && profile.freshman.username == profile.username;
        });
  else
    adoption_iterator = std::find_if(adoption_request_by_veteran.begin(),
        adoption_request_by_freshman.end(), 
        [username] (const Adoption & adoption) {
          return adoption.freshman.username == username 
          && profile.veteran.username == profile.username;
        });

  // TODO Reject adoption request because of veteran inability.
  
  reutrn true;
}


bool v1::BugReport(const Report & report) {
  bug_report.push_back(report);
}

