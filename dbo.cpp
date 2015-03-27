#include <Wt/WApplication>
#include <Wt/WBreak>
#include <Wt/WMenu>
#include <Wt/WLineEdit>
#include <Wt/WText>
#include <Wt/WStackedWidget>
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/SqlConnection>
#include <Wt/Dbo/Session>
#include <Wt/Dbo/ptr>
#include <Wt/Dbo/backend/Sqlite3>
namespace dbo=Wt::Dbo;
using namespace Wt;
#include <string>
using namespace std;
class User
{
public:
std::string program;
std::string name;
std::string college;
template<class Action>
void persist(Action& a)
{
dbo::field(a,program,"program");
dbo::field(a,name,"name");
dbo::field(a,college,"college");
}
};
class rajan : public WApplication
{
public:
dbo::Session session;
dbo::backend::Sqlite3 sqlite3;
WLineEdit *programtxt;
WLineEdit *nametxt;
WLineEdit *collegetxt;
rajan(const WEnvironment &env) :WApplication (env),sqlite3("datab3.db")
{
session.setConnection (sqlite3);
session.mapClass<User>("user");
session.createTables();
WText *programtext_=new WText("program",root());
programtxt=new WLineEdit(root());
WText *nametext_=new WText("name",root());
nametxt=new WLineEdit(root());
WText *collegetext_=new WText("college",root());
collegetxt=new WLineEdit(root())
}
{
dbo::Transaction transaction(session);
User *user = new User();
user->program = programtxt->text().toUTF8();
user->name = nametxt->text().toUTF8();
user->college = collegetxt->text().toUTF8();
dbo::ptr<User> userPtr = session.add(user);
transaction.commit();
}
};
WApplication *createApplication(const WEnvironment& env)
{
return new rajan(env);
}
int main(int argc, char **argv)
{
return WRun(argc, argv, &createApplication);
}


