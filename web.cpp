#include <Wt/WApplication>
#include <Wt/WContainerWidget>
#include <Wt/WText>
#include <Wt/WImage>
#include <Wt/WMenu>
#include <Wt/WStackedWidget>
#include <Wt/WVideo>
#include <Wt/WBreak>

using namespace Wt;

class webpage : public WApplication
{
public:
 webpage(const WEnvironment &env);
private:
};
webpage::webpage(const WEnvironment& env)
        : WApplication(env)
{ useStyleSheet("wtpage.css");
WContainerWidget *container1=new WContainerWidget(root());
container1->setStyleClass("a1");

WImage *image=new WImage("wtlogo.jpg",container1); //wt logo
image->setStyleClass("he1");

WText *headtxt=new WText("a C++ Website ",container1);
headtxt->setStyleClass("head1");

WStackedWidget *cont = new WStackedWidget();//main menu stack widget declaration
WMenu *menu=new WMenu (cont,Horizontal,container1);//main menu widget
container1->addWidget(cont);//adding stack widget after WMenu
menu->setStyleClass("m1");//style class of main menu
WContainerWidget *introcontainer=new WContainerWidget();
WContainerWidget *tutorialcontainer=new WContainerWidget();
WContainerWidget *contactcontainer=new WContainerWidget();
menu->addItem ("Introduction",introcontainer);//connecting menu items to corresponding container widget
menu->addItem ("Tutorial",tutorialcontainer);
menu->addItem ("Contact",contactcontainer);
introcontainer->addWidget(new WBreak());
introcontainer->addWidget(new WBreak());
introcontainer->addWidget(new WContainerWidget(container1));
WText *text1=new WText("While the web was initially designed as a distributed information storage, quickly it was reshaped to provide basic interactive functionality, through dynamic web pages. At that time, PHP and ASP.net were created as tools for the development of such dynamic pages.",introcontainer);
introcontainer->addWidget(new WBreak());
introcontainer->addWidget(new WBreak());
WText *text2=new WText("With the gradual improvement of web technology, modern web browsers have become capable of providing superior interactivity through the use of AJAX. AJAX is the technology that allows updates to an already rendered web page based on information fetched from the web server in the back-ground. As simple dynamic webpages are evolving into complex interactive web applications, new tools are being developed to more easily create such interactive web applications. Wt (C++) and JWt (Java) are such new tools that take a radically new approach to designing rich web applications.",introcontainer);
introcontainer->setStyleClass("t11");
introcontainer->addWidget(new WBreak());
introcontainer->addWidget(new WBreak());
WText *text5=new WText("How Wt addresses the new needs for web applications ?",introcontainer);
text5->setStyleClass("t12");
introcontainer->addWidget(new WBreak());
introcontainer->addWidget(new WBreak());
WText *text3=new WText("Wt has been designed to bring the desktop programming model to web application development, and at the same time address challenges for modern web applications. Rather than structuring an application as a sequence of pages, a Wt web application runs within a single page, and updates its contents based on user actions.",introcontainer);
introcontainer->addWidget(new WBreak());
WText *text4=new WText("Unlike page-based frameworks, session information is stored in memory in the application server throughout the session life time. This is used to improve server processing load and application interactivity and to eliminate common security problems.",introcontainer);
introcontainer->addWidget(new WBreak());
WText *text=new WText("Whereas PHP was (and still is) a successful tool for developing dynamic web sites, Wt has been designed to simplify the development of maintainable, interactive, secure and accessible web applications.",introcontainer);
 introcontainer->addWidget(new WBreak());
 introcontainer->addWidget(new WBreak());
WText *text7=new WText("Benifits of using Wt",introcontainer);
 introcontainer->addWidget(new WBreak());
 introcontainer->addWidget(new WBreak());
text7->setStyleClass("t13");
WText *text6=new WText("Develop web applications using familiar desktop GUI patterns.",introcontainer);
 introcontainer->addWidget(new WBreak());
WText *text8=new WText("Provides an extensive set of widgets, which work regardless of JavaScript availability (but benefit from JavaScript availability)." ,introcontainer);
 introcontainer->addWidget(new WBreak());
WText *text9=new WText("A single specification for both client- and server-side validation and event handling. ",introcontainer);
 introcontainer->addWidget(new WBreak());
WText *text15=new WText("Optionally, use XHTML and CSS for layout and decoration. ",introcontainer);
 introcontainer->addWidget(new WBreak());
WText *text16=new WText("Generates standards compliant HTML or XHTML code. ",introcontainer);
 introcontainer->addWidget(new WBreak());
WText *text17=new WText("Portable, anti-aliased graphics optimized for web usage (using inline VML, inline SVG, HTML5 canvas or PNG images), which can also be used to render to PDF.",introcontainer);
 introcontainer->addWidget(new WBreak());
WText *text18=new WText("Avoid common security problems since Wt has complete control over the presentation layer and proactively filters out active tags and attributes, does not expose business logic, and simplifies authentication using a stateful design.",introcontainer);
 introcontainer->addWidget(new WBreak());
WText *text19=new WText("Ultra-fast load time and low bandwidth usage, which are affected only by screen complexity, not application size. Wt implements all the common tips and tricks for optimizing application responsiveness and even optimizes per browser. ",introcontainer);
 introcontainer->addWidget(new WBreak());
WText *text20=new WText("A simple API with a robust cross-browser implementation for server-initiated events aka server push (using comet or WebSockets).",introcontainer);
WText *text21=new WText("Use the built-in httpd for easy development and deployment, or use the FastCGI/ISAPI connectors to deploy in existing web servers. ",introcontainer);

tutorialcontainer->addWidget(new WContainerWidget(container1));
WStackedWidget *content = new WStackedWidget();//tutorial menu stack widget declaration
WMenu *secondmenu=new WMenu (content,Horizontal,tutorialcontainer);//tutorial menu widget
tutorialcontainer->addWidget(content);//adding stack widget after WMenu
secondmenu->setStyleClass("menu1");//style class of tutorial menu
WContainerWidget *textcontainer=new WContainerWidget();
WContainerWidget *imagecontainer=new WContainerWidget();
WContainerWidget *videocontainer=new WContainerWidget();
WContainerWidget *menucontainer=new WContainerWidget();

secondmenu->addItem ("Text",textcontainer);
secondmenu->addItem ("Image",imagecontainer);
secondmenu->addItem ("Video",videocontainer);
secondmenu->addItem ("Menu",menucontainer);
textcontainer->addWidget(new WContainerWidget(container1));
textcontainer->addWidget(new WBreak());
WText *e1=new WText("How to add text in website ? ",textcontainer);
e1->setStyleClass("v1");
textcontainer->addWidget(new WBreak());
textcontainer->addWidget(new WBreak());
WText *e1=new WText("How to add text in website ? ",textcontainer);
e1->setStyleClass("v1");
textcontainer->addWidget(new WBreak());
WText *f1=new WText("To add text, WText widget is used. First we include <Wt/WText> header file in our source file and then write the text either on root or in some container widget. ",textcontainer);
f1->setStyleClass("v2");

textcontainer->addWidget(new WBreak());
textcontainer->addWidget(new WBreak());
WText *f2=new WText("Syntax to add text on root: ",textcontainer);
f2->setStyleClass("v3");
textcontainer->addWidget(new WBreak());
WText *f3=new WText("WText *obj=new WText('this is the text',root());",textcontainer);
f3->setStyleClass("v4");
textcontainer->addWidget(new WBreak());
textcontainer->addWidget(new WBreak());
WText *f4=new WText("Syntax to add text in a container widget: ",textcontainer);
f4->setStyleClass("v3");
textcontainer->addWidget(new WBreak());
WText *f5=new WText("WContainerWidget *conatiner=new WContainerWidget(root());",textcontainer);
f5->setStyleClass("v4");
textcontainer->addWidget(new WBreak());
WText *f6=new WText("WText *obj=new WText('this is the text',container);",textcontainer);
f6->setStyleClass("v4");
textcontainer->addWidget(new WBreak());
textcontainer->setStyleClass("b1");

imagecontainer->addWidget(new WContainerWidget(container1));
imagecontainer->setStyleClass("b");
imagecontainer->addWidget(new WBreak());
WText *e2=new WText("How to add Image in the website? ",imagecontainer);
e2->setStyleClass("b2");
imagecontainer->addWidget(new WBreak());
WText *g1=new WText ("To add image in the website, WImage widget is used. First we include <Wt/WImage>",imagecontainer);
WText *g5=new WText (" header file in our source file and then add image either on root on in a container widget.",imagecontainer);
g1->setStyleClass("j1");
g5->setStyleClass("j1");
imagecontainer->addWidget(new WBreak());
imagecontainer->addWidget(new WBreak());
WText *g2=new WText ("Syntax to add image is: ",imagecontainer);
g2->setStyleClass("j2");
imagecontainer->addWidget(new WBreak());
WText *g3=new WText ("WImage *i=new WImage('img1.png',root())",imagecontainer);
g3->setStyleClass("j3");
imagecontainer->addWidget(new WBreak());
imagecontainer->addWidget(new WBreak());
WImage *i=new WImage("img01.png",imagecontainer);
i->setStyleClass("j4");
imagecontainer->addWidget(new WBreak());
imagecontainer->addWidget(new WBreak());

videocontainer->addWidget(new WContainerWidget(container1));
videocontainer->setStyleClass("k10");
videocontainer->addWidget(new WBreak());
WText *e3=new WText("How to add video in the website ? ",videocontainer);
e3->setStyleClass("b3");
videocontainer->addWidget(new WBreak());
WText *k3=new WText("To add video,first include <Wt/WVideo> header file and then add video either in root or in a container widget.",videocontainer);
videocontainer->addWidget(new WBreak());
videocontainer->addWidget(new WBreak());
WText *k5=new WText("Syntax to add video is:",videocontainer);
k5->setStyleClass("b3");
videocontainer->addWidget(new WBreak());
WText *k6=new WText("WVideo *obj=new WVideo(parent)",videocontainer);
videocontainer->addWidget(new WBreak());
WText *k7=new WText("obj->setOptions(WVideo::Autoplay |Wvideo::Controls)",videocontainer);
videocontainer->addWidget(new WBreak());
WText *k8=new WText("obj->addSource('moon.ogg')",videocontainer);
videocontainer->addWidget(new WBreak());
videocontainer->addWidget(new WBreak());
WVideo *k1=new WVideo (videocontainer);
k1->setOptions(WVideo::Autoplay | WVideo::Controls);
k1->addSource("moon.ogg");
k1->setStyleClass("b5");

menucontainer->addWidget(new WContainerWidget(container1));
menucontainer->setStyleClass("k10");
menucontainer->addWidget(new WBreak());
WText *e3=new WText("How to add video in the website ? ",videocontainer);
e3->setStyleClass("b3");
videocontainer->addWidget(new WBreak());
WText *k3=new WText("To add video,first include <Wt/WVideo> header file and then add video either in root or in a container widget.",videocontainer);
videocontainer->addWidget(new WBreak());
videocontainer->addWidget(new WBreak());
WText *k5=new WText("Syntax to add video is:",videocontainer);
k5->setStyleClass("b3");
videocontainer->addWidget(new WBreak());
WText *k6=new WText("WVideo *obj=new WVideo(parent)",videocontainer);
videocontainer->addWidget(new WBreak());
WText *k7=new WText("obj->setOptions(WVideo::Autoplay |Wvideo::Controls)",videocontainer);
videocontainer->addWidget(new WBreak());
WText *k8=new WText("obj->addSource('moon.ogg')",videocontainer);
videocontainer->addWidget(new WBreak());
videocontainer->addWidget(new WBreak());
WVideo *k1=new WVideo (videocontainer);
k1->setOptions(WVideo::Autoplay | WVideo::Controls);
k1->addSource("moon.ogg");
k1->setStyleClass("b5");

menucontainer->addWidget(new WContainerWidget(container1));
menucontainer->setStyleClass("k10");
menucontainer->addWidget(new WBreak());
WText *e4=new WText("How to add Menus or navigation bar in the website ? ",menucontainer);
e4->setStyleClass("v3");
menucontainer->addWidget(new WBreak());
WText *e5=new WText("To add menus or navigation bar in the website, Firstly we hav to include <Wt/WMenu> and <WStackedWidget> header files in the source file and follow the following syntax",menucontainer);
menucontainer->addWidget(new WBreak());
menucontainer->addWidget(new WBreak());
WText *e6=new WText("WStackedWidget *content = new WStackedWidget(parent); WMenu *w1=new WMenu (content,Horizontal,parent);",menucontainer);
menucontainer->addWidget(new WBreak());
WText *e7=new WText("w1->addItem('Itemname',new WText('item contents')",menucontainer);
menucontainer->addWidget(new WBreak());

contactcontainer->addWidget(new WContainerWidget(container1));
contactcontainer->setStyleClass("p1");
WText *q1=new WText("Shaina Sabarwal",contactcontainer);
contactcontainer->addWidget(new WBreak());
WText *q2=new WText("D2 CSE",contactcontainer);
contactcontainer->addWidget(new WBreak());
WText *q3=new WText("mob. +917837091001",contactcontainer);
contactcontainer->addWidget(new WBreak());
WText *q4=new WText ("email id: shainasabarwal@gmail.com",contactcontainer);

}
Wt::WApplication *createApplication(const Wt::WEnvironment& env)
{
    return new webpage(env);
}

int main(int argc, char **argv)
{
    return Wt::WRun(argc, argv, &createApplication);
}
  
