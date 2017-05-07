#include <algorithm>

#include "v1.h"

using namespace adopt_a_freshman;

int v1::Login(const string& username, const string& password) {
    list<UserRegistry>::iterator regis;
    regis=find_if(users_freshmans.begin(),users_freshmans.end(),[username](UserRegistry registry){return registry.username==username;});
    if(regis==users_freshmans.end())
    {
        regis=find_if(users_veterans.begin(),users_veterans.end(),[username](UserRegistry registry){return registry.username==username;});
        if(regis==users_veterans.end())
            return -1;
    }
    if(password==regis->password)
        return regis->token;
    else
        return -1;
}

int v1::Subscribe(UserRegistry registry) {
  if(registry.password.length() < 6)
    return -1;
  if(registry.profile.semester<1)
    return -2;
  registry.token=token++;
  if(registry.profile.semester<3) { 
    registry.profile.type = Category::FRESHMAN;
    users_freshmans.push_back(registry);
  }
  if(registry.profile.semester>=3) {
    registry.profile.type = Category::VETERAN;
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
    this->GetProfile(token) = profile;
}

Profile& v1::GetProfile(int token) {
  list<UserRegistry>::iterator gigaregis;
  gigaregis=find_if(users_freshmans.begin(),users_freshmans.end(),[token](UserRegistry registoken){return registoken.token==token;});
  if(gigaregis==users_freshmans.end())
    gigaregis=find_if(users_veterans.begin(),users_veterans.end(),[token](UserRegistry registoken){return registoken.token==token;});
  return gigaregis->profile;
}

list<Profile> v1::GetVeterans(int token) {
  // TODO XXX implements
  return {};
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
  Adoption adoption;
  Profile profile_a = this->GetProfile(username),
         profile_b = this->GetProfile(token);

  list<Adoption>::iterator adoption_iterator;

  const Profile & profile = this->GetProfile(token);
  if (profile.type == Category::FRESHMAN)
    adoption_iterator = std::find_if(adoption_request_by_veteran.begin(),
        adoption_request_by_veteran.end(), 
        [username] (const Adoption & adoption) {
          return adoption.veteran.name == profile_a.username
          && adoption.freshman.username == profileb.username
        });
  else
    adoption_iterator = std::find_if(adoption_request_by_veteran.begin(),
        adoption_request_by_freshman.end(), 
        [username] (const Adoption & adoption) {
          return adoption.veteran.name == profile_b.username
          && adoption.freshman.username == profile_a.username
        });

  // TODO Reject adoption request because of veteran inability.
  
  reutrn true;
}


bool v1::BugReport(const Report & report) {
  bug_report.push_back(report);
}

