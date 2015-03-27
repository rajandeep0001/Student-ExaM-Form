#include<Wt/WApplication>
#include<Wt/WText>
#include<Wt/WBreak>
#include<Wt/Dbo/Dbo>
#include<string>
#include<Wt/Dbo/backend/Sqlite3>
#include<Wt/Dbo/SqlConnection>
#include<Wt/Dbo/Transaction>
#include<Wt/WEnvironment>
#include<Wt/WString>
#include<Wt/WPushButton>
#include<Wt/WLineEdit>
#include<stdlib.h>
//#include<Wt/Auth/HashFunction>
#include<Wt/Auth/HashFunction>
//#define null ((void *)0)
namespace dbo=Wt::Dbo;
using namespace std;
class User
{
public:
std::string name;
std::string pass;
template<class Action>
void persist(Action& a)
{
dbo::field(a,name,"name");
dbo::field(a,pass,"pass");
}
};
using namespace Wt;
class programme:public WApplication 
{
public:
void run();
programme(const WEnvironment& env);
WText *name,*pass;
WLineEdit *lname,*lpass;
WPushButton *button;

};
programme::programme(const WEnvironment& env):WApplication(env)
 {
 name=new WText("Username",root());
// root()->addWidget(new WLineEdit()); 
 lname=new WLineEdit(root());
// lname->setFocous();
//Wt::Auth::BCryptHashFunction::compute(pass,MD5HashFunction);
pass=new WText("password",root());
//Wt::Auth::MD5HashFunction::name();
lpass=new WLineEdit(root());
button=new WPushButton("submit",root());
button->clicked().connect(this,&programme::run);
  }

void programme::run()
{
dbo::backend::Sqlite3 sqlite3("blog.db");
dbo::Session session;
session.setConnection(sqlite3);
session.mapClass<User>("programme");
session.createTables();
dbo::Transaction transaction(session);
User *usr=new User();
usr->name=lname->text().toUTF8();
usr->pass=lpass->text().toUTF8();
dbo::ptr<User> userPtr=session.add(usr);
transaction.commit();
//dbo::ptr<User> Qname=session.find<User>("where name=?").bind("amitoj");
//transaction.commit();
//Qname->name;
/*if(Qname==lname->text().toUTF8());
{
std::cout<<"not found";
}
else
{
std::cout<<"element found";
}*/

}
WApplication *createApplication(const WEnvironment& env)
{
return new programme(env);
}
int main(int argc, char **argv)
{
return WRun(argc, argv, &createApplication);
}
