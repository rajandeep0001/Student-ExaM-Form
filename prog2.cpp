#include <Wt/WApplication>
#include <Wt/WBreak>
#include <Wt/WContainerWidget>
#include <Wt/WLineEdit>
#include <Wt/WPushButton>
using namespace Wt;
class HelloApplication : public WApplication
{
public:
HelloApplication(const WEnvironment& env);

private:
WLineEdit *nameEdit_;
WText *greeting_;
void greet();
};
HelloApplication::HelloApplication(const WEnvironment& env)
: WApplication(env)
{
setTitle("Hello world");                                                           
WPushButton *button1 = new WPushButton("Greet me.", root());
WPushButton *button2 = new WPushButton("Greet me.", root());
WPushButton *button3 = new WPushButton("Greet me.", root());
WPushButton *button4 = new WPushButton("Greet me.", root());
                         
root()->addWidget(new WBreak());                       
                        
(boost::bind(&HelloApplication::greet, this));
}
void HelloApplication::greet()
{
}
WApplication *createApplication(const WEnvironment& env)
{
return new HelloApplication(env);
}
int main(int argc, char **argv)
{
return WRun(argc, argv, &createApplication);
}
