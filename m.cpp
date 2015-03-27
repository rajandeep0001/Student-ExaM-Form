#include <Wt/WApplication>
#include <Wt/WText>
#include <Wt/WMenu>
#include <Wt/WStackedWidget>

using namespace Wt;

class helloapp : public WApplication
{
public:
helloapp(const WEnvironment &env) :WApplication (env)
{
WText *t = new WText("hello",root());
WContainerWidget *cont = new WContainerWidget(root());
WText *text = new WText("hi hello",cont);

WContainerWidget *cont2 = new WContainerWidget(root());
WText *text2 = new WText(" hi, hi hello",cont2);

WStackedWidget *stack = new WStackedWidget();
WMenu *menu = new WMenu (stack, Vertical, root());
root()->addWidget(stack);
menu->addItem ("home", cont);
menu->addItem ("intro",cont2);
}
};

WApplication *createApplication(const WEnvironment& env)
{
return new helloapp(env);
}
int main(int argc, char **argv)
{
return WRun(argc, argv, &createApplication);
}

