#include <Wt/WApplication>
#include <Wt/WContainerWidget>
#include <Wt/WEnvironment>
#include <Wt/WLineEdit>
#include <Wt/WPushButton>
#include <Wt/WText>
#include <Wt/WMenu>
#include <Wt/WComboBox>
#include <Wt/StackedWidget>
#include <Wt/Dbo/SqlTraits>
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/backend/Sqlite3>
#include <Wt/Dbo/Session>
#include <Wt/Dbo/Transaction>
#include <Wt/Dbo/QueryModel>
#include <Wt/Dbo/SqlConnection>
using namespace Wt;
namespace dbo = Wt::Dbo;
#include <string>
using namespace std;
class User
{
public:
std::string program;
std::string name;
std::string fathername;
std::string mothername;
std::string dobirth;
std::string rollno;
std::string stream;
std::string department;
std::string semester;
template <class Action>
void persist(Action& a)
{
dbo::field(a, program,   "program");
dbo::field(a, name,       "name");
dbo::field(a, fathername, "fathername");
dbo::field(a, mothername,   "mothername");
dbo::field(a, dobirth,  "dobirth");
dbo::field(a, rollno,    "rollno");
dbo::field(a, stream,     "stream");
dbo::field(a, department, "department");
dbo::field(a, semester,   "semester");
}
};
class Myform : public WApplication
{
public:
dbo::Session session;
dbo::backend::Sqlite3 sqlite3;
WLineEdit *nametxt;
WLineEdit *fathernametxt;
WLineEdit *mothernametxt;
WLineEdit *dobirthtxt;
WLineEdit *rollnotxt;
WComboBox *programbox;
WComboBox *streambox;
WComboBox *departmentbox;
WComboBox *semesterbox;
Myform (const WEnvironment &env) :WApplication (env), sqlite3 ("datab3.db")
{
session.setConnection (sqlite3);
session.mapClass<User>("User");
setTitle("Databaseform");
WText *formtxt=new WText("Examination Form",root());
WStackedWidget *stack=new WStackedWidget();
WMenu *mainmenu=new WMenu(stack,Vertical,root());
root()->addWidget(stack);
c=new WContainerWidget();
c1=new WContainerWidget();
mainmenu->addItem("new user",c);
mainmenu->addItem("exit account",c1);
c->addWidget(new WBreak());
c->addWidget(new WBreak());
c->addWidget(new WBreak());
WText *programtext_=new WText ("Program",c);
programbox=new WComboBox(c);
programbox->addItem("new");
programbox->addItem("Under graduate section");
programbox->addItem("Post graduate section");
c->addWidget(new WBreak());
c->addWidget(new WBreak());
c->addWidget(new WBreak());

WText *nametext_=new WText("Name   ",c);
nametxt=new WLineEdit(c);
c->addWidget(new WBreak());
c->addWidget(new WBreak());
c->addWidget(new WBreak());

WText *fathernametext_=new WText("fathername",c);
fathernametxt=new WLineEdit(c);
c->addWidget(new WBreak());
c->addWidget(new WBreak());
c->addWidget(new WBreak());

WText *mothernametext_=new WText("mothername",c);
mothernametxt=new WLineEdit(c);
c->addWidget(new WBreak());
c->addWidget(new WBreak());
c->addWidget(new WBreak());

WText *dobirthtext_=new WText("dobirth",c);
dobirthtxt=new WLineEdit(c);
c->addWidget(new WBreak());
c->addWidget(new WBreak());
c->addWidget(new WBreak());

WText *rollnotext_=new WText("rollno",c);
rollnotxt=new WLineEdit(C);
c->addWidget(new WBreak());
c->addWidget(new WBreak());
c->addWidget(new WBreak());

WText *streamtext_=new WText("stream",c);
streambox=new WComboBox(c);
streambox->addItem("");
streambox->addItem("B.tech");
streambox->addItem("M.tech");
streambox->addItem("M.B.A");
c->addWidget(new WBreak());
c->addWidget(new WBreak());
c->addWidget(new WBreak());

WText *departmenttext_=new WText("Department",c);
departmentbox=new WComboBox(c);
departmentbox->addItem("");
departmentbox->addItem("Computer Engineering");
departmentbox->addItem("Civil Engineering");
departmentbox->addItem("Electronics and Communication Engineering");
departmentbox->addItem("Information Technology");
departmentbox->addItem("Mechnical Engineering");
departmentbox->addItem("Production Engineering");
departmentbox->addItem("M.B.A");
c->addWidget(new WBreak());
c->addWidget(new WBreak());
c->addWidget(new WBreak());

WText *semestertext_=new WText("semester",c)
semesterbox=new WComboBox(c);
semester->addItem("");
semester->addItem("1");
semester->addItem("2");
semester->addItem("3");
semester->addItem("4");
semester->addItem("5");
semester->addItem("6");
semester->addItem("7");
semester->addItem("8");
c->addWidget(new WBreak());
c->addWidget(new WBreak());
c->addWidget(new WBreak());

WPushButton *button=new WPushButton("Submit",c);
button->clicked().connect(this, &Myform::enterdata);
c->addWidget(new WBreak());
c->addWidget(new WBreak());

WText *retrievetext_=new WText("enter name to retrieve data",c1);
retrievetext=new WLineEdit(c1);
WPushButton *retrievebutton=new WPushButton("enter",c1);
retrievebutton->clicked().connect(this, &Myform::retrievedata);
c1->addWidget(new WBreak());
c1->addWidget(new WBreak());
}
Myform (void)
{
cout<<"Myform dead"<<endl;}
void enterdata();
void retrievedata();
};
void Myform::enterdata()
{
{
dbo::Transaction transaction(session);

    
User *user = new User();
user->name = nametxt->text().toUTF8();
user->fathername = fathernametxt->text().toUTF8();
user->mothername = mothernametxt->text().toUTF8();
user->dobirth = dobirthtxt->text().toUTF8();
user->rollno = rollnotxt->text().toUTF8();
user->program = programbox->currentText().toUTF8();
user->stream = streambox->currentText().toUTF8();
user->department = departmentbox->currentText().toUTF8();
user->semester = semesterbox->currentText().toUTF8();
dbo::ptr<User> userPtr = session.add(user);
transaction.commit();
}}
void Myform::retrievetxt->text();
std::string  b=a.toUTF8();

{
dbo::Transaction transaction(session);
typedef dbo::collection< dbo::ptr<User> >Users;
Users users = session.find<User>().where("name=?").bind(b);
int i;
for (Users::const_iterator i = users.being(); i !=users.end(); ++i)
{
c1->addWidget(new WText("name:"));
WText *nameout=new Wtext ((*i)->name,c1);
c1->addWidget(new WBreak());
c1->addWidget(new WBreak());

c1->addWidget(new WText("father name:"));
WText *fathernameout=new WText ((*i)->fathername,c1);
c1->addWidget(new WBreak());
c1->addWidget(new WBreak());

c1->addWidget(new WText("mother name:"));
WText *mothernameout=new WText ((*i)->mothername,c1);
c1->addWidget(new WBreak());
c1->addWidget(new WBreak());

c1->addWidget(new WText("dobirth:"));
WText *dobirthout=new WText ((*i)->dobirth,c1);
c1->addWidget(new WBreak());
c1->addWidget(new WBreak());

c1->addWidget(new WText("rollno"));
WText *rollnoout=new WText ((i)->rollno,c1);
c1->addWidget(new WBreak());
c1->addWidget(new WBreak());

c1->addWidget(new WText("stream:"));
WText *streamout=new WText ((*i)->stream,c1);
c1->addWidget(new WBreak());
c1->addWidget(new WBreak());

c1-addWidget(new WText("department:"));
WText *departmentout=new WText ((*i)->department,c1);
c1->addWidget(new WBreak());
c1->addWidget(new WBreak());

c1-addWidget(new WText("semester:"));
WText *semesterout=new WText ((*i)->semester,c1);
c1->addWidget(new WBreak());
c1->addWidget(new WBreak());
}
transaction.commit();
}}
WApplication * createApplication (WEnvironment const & env)
{ return new Myform (env); }

int main(int argc, char **argv)
{
  return WRun (argc, argv, & createApplication);
}










