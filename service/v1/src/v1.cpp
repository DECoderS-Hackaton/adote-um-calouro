#include <algorithm>

#include "v1.h"

using namespace adopt_a_freshman;

int Login(const string& username, const string& pasword);

int v1::Subscribe(UserRegistry registy) {
  registy.token = token++;
  users.push_back(registy);
  return registy.token;
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

std::string UpdateProfile(const Profile & profile, int token);

service::Profile& GetProfile(int token); 

list<Profile> GetVeterans(int token);

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

