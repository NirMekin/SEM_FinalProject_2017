#include <string>
#include "../Panel/Panel.h"
#include "../CheckList/CheckList.h"
#include "../ComboBox/ComboBox.h"
#include "../Graphics/Graphics.h"
#include "../TextBox/TextBox.h"
#include "../RadioList/RadioList.h"
#include "../EventEngine/EventEngine.h"
#include "../NumericBox/NumericBox.h"
#include "../MessegeBox/MsgBox.h"

using namespace std;

struct MyListener : public MouseListener
{
	MyListener(Control &c) : _c(c) { }
	void mousePressed(Control& b, short x, short y, bool isLeft)
	{
		_c.show();
		Control::setFocus(&_c);
	}
private:
	Control &_c;
};


int main(void){
	const int  WIDTH = 20;
	Label lCopyRights(60, "all rights reserved - Shenkar 2017");
	Label lTitle(WIDTH, "Personal information");
	Label lName(WIDTH, "Name: ");
	Label lStar(WIDTH, "Star:");
	Label lGalaxy(WIDTH, "Galaxy:");
	Label lGender(WIDTH, "Sex:");
	Label lHobbies(WIDTH, "Personal Hobbies");
	Label lAge(WIDTH, "Age:");
	TextBox tName(WIDTH);
	lTitle.setForeground(ForegroundColor::Purple);
	lCopyRights.setForeground(ForegroundColor::Purple);
	lHobbies.setForeground(ForegroundColor::Purple);
	tName.setValue("Darth Vader");
	tName.setBorder(BorderType::Single);
	TextBox tStar(WIDTH);
	tStar.setValue("Death Star, Jakku");
	tStar.setBorder(BorderType::Single);
	ComboBox cGalaxy(WIDTH, { "The 7th", "Milky Way", "Galaxy S8" });
	cGalaxy.setSelectedIndex(1);
	cGalaxy.setBorder(BorderType::Single);
	RadioList rGender(14, WIDTH,{ "Male", "Female", "Other" ,"Yes Please"});
	rGender.setBorder(BorderType::Single);
	CheckList cHobbies(11, WIDTH, { "Comics", "Books", "Magic" });
	cHobbies.selectIndex(0);
	cHobbies.setBorder(BorderType::Single);
	NumericBox nAge(WIDTH, 10, 120);
	nAge.setValue(20);
	nAge.setBorder(BorderType::Single);

	MsgBox messageBox(20, 25);
	messageBox.hide();
	messageBox.setBorder(BorderType::Double);
	messageBox.setBackGround(BackgroundColor::Blue);
	messageBox.setForeground(ForegroundColor::White);

	MyListener* listener = new MyListener(messageBox);
	Button bSubmit(15, "   Launch");
	bSubmit.setForeground(ForegroundColor::Red);
	bSubmit.addListener(*listener);
	bSubmit.setBorder(BorderType::Single);


	Panel main(60, 70);

	main.setBorder(BorderType::Single);

	main.addControl(&lTitle, 11, 1);
	
	main.addControl(&messageBox, 15, 15);
	main.addControl(&lName, 4, 4);
	main.addControl(&lStar, 3, 7);
	main.addControl(&lGalaxy, 4, 10);
	main.addControl(&lGender, 3, 15);
	
	main.addControl(&lAge, 3, 29);

	main.addControl(&tName, 28, 4);
	main.addControl(&tStar, 28, 7);
	main.addControl(&cGalaxy, 28, 10);
	main.addControl(&rGender, 28, 15);
	
	main.addControl(&nAge, 28, 29);

	main.addControl(&lHobbies, 9, 35);
	main.addControl(&cHobbies, 28, 38);
	main.addControl(&bSubmit, 30, 50);

	main.addControl(&lCopyRights, 3, 55);

	Control::setFocus(&tName);
	EventEngine engine;
	engine.run(main);
	
	return 0;

}