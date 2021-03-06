#include <Wt/WApplication>
#include <Wt/WBreak>
#include <Wt/WContainerWidget>
#include <Wt/WLineEdit>
#include <Wt/WPushButton>
#include <Wt/WText>
#include <Wt/WHTML5Video>
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
  root()->addWidget(new WText("Your name, please ? "));
  nameEdit_ = new WLineEdit(root());
  nameEdit_->setFocus();
 WHTML5Video *v = new WHTML5Video(root());
 //v->setOptions(WVideo::Autoplay | WVideo::Controls);
 v->addSource("moon.ogg");

  WPushButton *button  = new WPushButton("Greet me.", root());
  button->setMargin(5, Left);

  root()->addWidget(new WBreak());

  greeting_ = new WText(root());
  button->clicked().connect(this, &HelloApplication::greet);
                 nameEdit_->enterPressed().connect
    (boost::bind(&HelloApplication::greet, this));

}

void HelloApplication::greet()
{

 greeting_->setText("Hello there, " + nameEdit_->text());
}

WApplication *createApplication(const WEnvironment& env)
{

  return new HelloApplication(env);
}

int main(int argc, char **argv)
{
   return WRun(argc, argv, &createApplication);
}

