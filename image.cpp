#include <Wt/WApplication>
#include <Wt/WBreak>
#include <Wt/WContainerWidget>
#include <Wt/WImage>
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
WImage *img = new WImage("raj.png",root());
//img->setAlternateText("compiler");
root()->addWidget(new WBreak());
}
WApplication *createApplication(const WEnvironment& env)
{
return new HelloApplication(env);
}
int main(int argc, char **argv)
{
return WRun(argc, argv,&createApplication);
}
