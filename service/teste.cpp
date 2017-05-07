#include <iostream>
#include<algorithm>
#include "data.h"

int Subscribe(UserRegistry &user_insert)
{
    if(user_insert.password<6)
        return -1;
    if(user_insert.profile.semester<1)
        return -2;
    user_insert.token=token++;
    if(user_insert.profile.semester<3)
    { 
        users_freshmans.profile.user_status="Calouro";
        users_freshmans.push_back(user_insert);
    }
    if(user_insert.profile.semester>=3)
    {
        users_veterans.profile.user_status="Veterano";
        users_veterans.push_back(user_insert);
    }
    return user_insert.token;
}
int Login(string username, string password)
{ 
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
const UserRegistry& GetProfile(int token) const {
    return GetProfile(token);
}
UserRegistry& GetProfile(int token)
{
    list<UserRegistry>::iterator gigaregis;
    gigaregis=find_if(users_freshmans.begin(),users_freshmans.end(),[token](UserRegistry registoken){return registoken.token==token});
    if(regis==users_freshmans.end())
        gigaregis=find_if(users_veterans.begin(),users_veterans.end(),[token](UserRegistry registoken){return registoken.token==token});
    return gigaregis->profile;
}
UserRegistry GetProfile(string name)
{
    list<UserRegistry>::iterator gigaregis;
    gigaregis=find_if(users_freshmans.begin(),users_freshmans.end(),[name](UserRegistry regisname){return regisname.name==name});
    if(regis==users_freshmans.end())
        gigaregis=find_if(users_veterans.begin(),users_veterans.end(),[name](UserRegistry regisname){return regisname.name==name});
    return gigaregis->profile;
}
UserRegistry UpdateProfile(Profile perfil, int token)
{
    GetProfile(token)=perfil;
}
UserRegistry GetVeterans(int token)
{
    UserRegistry vets;
    vets=GetProfile(token).profile;
    if(vets.profile.user_status="Veterano")
    {

    }
    else
    
}
ostream& operator<<(ostream &out, const UserRegistry &user) {
    cout 
    << "{" << endl
    << "  \"username\" : \""<< user.username << "\"," << endl
    << "  \"password\" : \""<< user.password << "\"," << endl
    << "  \"token\" : "<< user.token << "," << endl
    << "  \"profile\" : {" << endl
    << "    \"name\" : \"" << user.profile.name << "\"," << endl
    << "    \"university\" : \"" << user.profile.university << "\"," << endl
    << "    \"field\" : \"" << user.profile.field << "\"," << endl
    << "    \"telephone\" : \"" << user.profile.telephone << "\"," << endl
    << "    \"avatar\" : \"" << user.profile.avatar << "\"," << endl
    << "    \"user_medias\" :  {" << endl
    << "      \"fbhook\" : \"" << user.profile.user_medias.fbhook << "\"," << endl
    << "      \"fbhook\" : \"" << user.profile.user_medias.gphook << "\"" << endl
    << "    }" << endl
    << "  }" << endl
    << "}" << endl;

    return out;
}

int main(void)
{
    UserRegistry filhote;
    filhote.username = "biscoito@hotmail.com";
    filhote.password = "12345";
    filhote.profile.name = "Biscoito";
    filhote.profile.university = "PUCRio";
    filhote.profile.field = "Exatas";
    filhote.profile.telephone = "2278-9954";
    filhote.profile.avatar = "cookies.jpeg";
    filhote.profile.user_medias.fbhook = "facebook.com/profile123";
    filhote.profile.user_medias.gphook = "googleplus.com/profile321";
    
    cout << "Usuario de token: " << CriaCadastro(filhote) << endl;
    cout << filhote << endl;
    cout << "Usuario de token: " << CriaCadastro(filhote) << endl;
    cout << filhote << endl;
    cout << "Usuario de token: " << CriaCadastro(filhote) << endl;
    cout << filhote << endl;
}