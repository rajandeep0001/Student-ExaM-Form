#include <Wt/WApplication>
#include <Wt/WBreak>
#include <Wt/WContainerWidget>
#include <Wt/WText>

using namespace Wt;

class HelloApplication : public WApplication
{
public:
HelloApplication(const WEnvironment& env);
private:
WText *text;
WText *rajan;
WText *bajwa;
};
HelloApplication::HelloApplication(const WEnvironment& env)
: WApplication(env)
{
setTitle("Hello world");
useStyleSheet("text.css");
WContainerWidget *container2=new WContainerWidget(root());
text=new WText("this is widget-centric and uses well-tested patterns of desktop GUI development tailored to the web.To the developer offers abstraction of webspecific implementation detailsincluding client-server protocols.");
container2->addWidget(text);
container2->setStyleClass("a");                        
root()->addWidget(new WBreak());
root()->addWidget(new WBreak());
root()->addWidget(new WBreak());

rajan=new WText("Supports major browsers (Firefox/Gecko, Internet Explorer, Safari, Chrome, Konqueror, and Opera) but also plain HTML browsers (Links, LynxDevelop and deploy on Unix/GNU Linux or Microsoft Windows (Visual Studio) environments.Equal behavior with or without support for JavaScript or Ajax, as far as possible, by using graceful degradation or progressive enhancement.Integrated Unicode support and pervasive localization.Efficient rendering and (very) low latency.Support for browser history navigation (back/forward buttons and bookmarks), pretty URLs with HTML5 History if available, and search engine optimization with a unified behavior for plain HTML or Ajax sessions.",root());
rajan->setStyleClass("c");
root()->addWidget(new WBreak());
root()->addWidget(new WBreak());
root()->addWidget(new WBreak());
WContainerWidget *container1=new WContainerWidget(root());
bajwa=new WText(" Supports major browsers (Firefox/Gecko, Internet Explorer, Safari, Chrome, Konqueror, and Opera) but also plain HTML browsers (Links, Lynx).Develop and deploy on Unix/GNU Linux or Microsoft Windows (Visual Studio) environments.Equal behavior with or without support for JavaScript or Ajax, as far as possible, by using graceful degradation or progressive enhancement.Integrated Unicode support and pervasive localization.Efficient rendering and (very) low latency.Support for browser history navigation (back/forward buttons and bookmarks), pretty URLs with HTML5 History if available, and search engine optimization with a unified behavior for plain HTML or Ajax sessions.");
container1->addWidget(bajwa);
container1->setStyleClass("b");
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

