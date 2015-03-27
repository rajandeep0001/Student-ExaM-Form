#include <Wt/WApplication>
#include <Wt/WBreak>
#include <Wt/WContainerWidget>
#include <Wt/WLineEdit>
#include <Wt/WPushButton>
#include <Wt/WMenu>
#include <Wt/WText>
#include <Wt/WStackedWidget>

using namespace Wt;
class HelloApplication : public WApplication
{
public:
HelloApplication(const WEnvironment& env);

};

HelloApplication::HelloApplication(const WEnvironment& env)
	: WApplication(env)
{
setTitle("Hello world");
WContainerWidget *c1 = new WContainerWidget(root());
WContainerWidget *c2 = new WContainerWidget(root());
WText *t=new WText("hello",c1);

WStackedWidget *contents = new WStackedWidget();
WMenu *menu = new WMenu(contents,Horizontal,root());
root()->addWidget(contents);

WPushButton *button1 = new WPushButton("Greet me.", c1);
WPushButton *button2 = new WPushButton("Greet me.", c1);
WPushButton *button3 = new WPushButton("Greet me.", c1);
WPushButton *button4 = new WPushButton("Greet me.", c1);

menu->addItem("introduction",c1);
menu->addItem("home",c2);
root()->addWidget(new WBreak());
}

WApplication *createApplication(const WEnvironment& env)
{
return new HelloApplication(env);
}
int main(int argc, char **argv)
{
return WRun(argc, argv, &createApplication);
}

