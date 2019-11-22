/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"
#include <string.h>>
//==============================================================================



void displayTasks(PopupMenu listo);




	

/*class propeties :public manager
{
public:
	void add(string s);
	void update();
	void del();
	void display();

	void displayReport();

};*/




MainComponent::MainComponent()
{
	
	addButton.setToggleState(false, NotificationType::dontSendNotification);
	addButton.onClick = [this]() {addTask(); };
	addAndMakeVisible(addButton);
	taskText.setMultiLine(true, true);
	taskText.setReturnKeyStartsNewLine(true);
	taskText.setTextToShowWhenEmpty(" Enter Task Description Here. Hope You Complete This Task :)", Colours::lightgrey);
	taskText.setScrollBarThickness(50);
	addAndMakeVisible(taskText);
	viewText.setMultiLine(true, true);
	viewText.setReturnKeyStartsNewLine(true);
	viewText.setTextToShowWhenEmpty("You Can View Your Tasks Here.", Colours::lightgrey);
	viewText.setReadOnly(true);
	addAndMakeVisible(viewText);
	taskDescription.setMultiLine(false, true);
	taskDescription.setReturnKeyStartsNewLine(false);
	taskDescription.setTextToShowWhenEmpty("Enter Task Name Here !",Colours::lightgrey);
	addAndMakeVisible(taskDescription);
	priorityCheck.addItem("Very Important", 1);
	priorityCheck.addItem("Important", 2);
	priorityCheck.addItem("Moderate", 3);
	priorityCheck.addItem("Low", 4);
	timeLabel.setText("Time  :  ", dontSendNotification);
	addAndMakeVisible(timeLabel);
	addAndMakeVisible(priorityCheck);
	priorityLabel.setText(" Select Priority  :  ",dontSendNotification);
	addAndMakeVisible(priorityLabel);

	hourBox.addItem("01 :", 1);
	hourBox.addItem("02 :", 2);
	hourBox.addItem("03 :", 3);
	hourBox.addItem("04 :", 4);
	hourBox.addItem("05 :", 5);
	hourBox.addItem("06 :", 6);
	hourBox.addItem("07 :", 7);
	hourBox.addItem("08 :", 8);
	hourBox.addItem("09 :", 9);
	hourBox.addItem("10 :", 10);
	hourBox.addItem("11 :", 11);
	hourBox.addItem("12 :", 12);
	addAndMakeVisible(hourBox);

	minuteBox.addItem("00 :", 1);
	minuteBox.addItem("15 :", 2);
	minuteBox.addItem("30 :", 3);
	minuteBox.addItem("45 :", 4);
	addAndMakeVisible(minuteBox);
	
	am_pmBox.addItem("AM .", 1);
	am_pmBox.addItem("PM .", 2);
	addAndMakeVisible(am_pmBox);
	addAndMakeVisible(viewTasks);
	viewTasks.onClick = [this] {selectedTask = taskList.showAt(&viewTasks); displayTask(selectedTask); };
	addAndMakeVisible(viewReport);
	 
	
    setSize (1200, 800);
}

MainComponent::~MainComponent()
{
}

void displayTasks(PopupMenu listo)
{
	listo.show(0, 0, 101, 0, nullptr);
}
//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
	g.fillAll(Colours::transparentBlack);
	g.setColour(Colours::slategrey);
	g.drawRect(mainFrame);
	g.drawRect(taskFrame);
	g.drawRect(addFrame);

}

void MainComponent::resized()
{
	mainFrame.setBounds(1, 1, getWidth()-2,getHeight()-3);
	taskFrame = mainFrame.removeFromLeft(getWidth() / 3 - getWidth()/24);
	addFrame = mainFrame.removeFromLeft(getWidth() / 3+ getWidth()/12 );
	viewFrame = mainFrame;
	taskText.setBounds(getWidth()/3,getHeight()/6,getWidth()/3,getHeight()/4);
	taskDescription.setBounds(getWidth() / 3, getHeight() / 6 - getHeight() / 10, getWidth() / 3, getHeight() / 11);
	viewText.setBounds(getWidth() / 2 + getWidth() / 4, getHeight() / 6,getWidth()/5 +10,getHeight()/3);
	priorityCheck.setBounds(getWidth() / 2, getHeight() / 2-getHeight()/13, getWidth() / 8, getHeight() / 15);
	priorityLabel.setBounds(getWidth() / 3+getWidth()/30, getHeight() / 2 - getHeight() / 13, getWidth() / 6, getHeight() / 15);
	timeLabel.setBounds(getWidth() / 3, getHeight() / 2, getWidth() / 10, getHeight() / 15);
	hourBox.setBounds(getWidth() / 3 + getWidth() / 15, getHeight() / 2, getWidth() / 12, getHeight() / 15);
	minuteBox.setBounds(29 * getWidth() / 60 , getHeight() / 2, getWidth() / 12, getHeight() / 15);
	am_pmBox.setBounds(34*getWidth()/60,getHeight()/2, getWidth() / 12, getHeight() / 15);
	viewTasks.setBounds(getWidth() / 6,getHeight()/2+getHeight()/6,120,60);
	
	addButton.setBounds(600, 600, 70, 30);
	
	
	//priorityList.setBounds(getWidth() / 2 - 250, getHeight() / 2 - 100, 50, 30);

    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}

