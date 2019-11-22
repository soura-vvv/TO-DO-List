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
	updateTask.onClick = [this] {};
	deleteTask.onClick = [this] {deleteTasks(); };
	viewReport.onClick = [this] {displayReport(reportDay.getSelectedItemIndex(),reportMonth.getSelectedItemIndex(),reportDayEnd.getSelectedItemIndex(),reportMonthEnd.getSelectedItemIndex()); };
	addAndMakeVisible(updateTask);
	addAndMakeVisible(deleteTask);

	taskText.setMultiLine(true, true);
	taskText.setReturnKeyStartsNewLine(true);
	taskText.setTextToShowWhenEmpty(" Enter Task Description Here. Hope You Complete This Task :)", Colours::lightgrey);
	taskText.setScrollBarThickness(50);
	addAndMakeVisible(taskText);
	viewText.setMultiLine(true, true);
	viewText.setReturnKeyStartsNewLine(true);
	viewText.setTextToShowWhenEmpty("You Can View Your Tasks Here.", Colours::lightgrey);
	viewText.setReadOnly(false);
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
	taskList.addItem(1, "Task", false, false);
	viewTasks.onClick = [this] {selectedTask = taskList.showAt(&viewTasks); displayTask(selectedTask); };
	addAndMakeVisible(viewReport);
	
	reportDay.addItem("1", 1);
	reportDay.addItem("2", 2);
	reportDay.addItem("3", 3);
	reportDay.addItem("4", 4);
	reportDay.addItem("5", 5);
	reportDay.addItem("6", 6);
	reportDay.addItem("7", 7);
	reportDay.addItem("8", 8);
	reportDay.addItem("9", 9);
	reportDay.addItem("10", 10);
	reportDay.addItem("11", 11);
	reportDay.addItem("12", 12);
	reportDay.addItem("13", 13);
	reportDay.addItem("14", 14);
	reportDay.addItem("15", 15);
	reportDay.addItem("16", 16);
	reportDay.addItem("17", 17);
	reportDay.addItem("18", 18);
	reportDay.addItem("19", 19);
	reportDay.addItem("20", 20);
	reportDay.addItem("21", 21);
	reportDay.addItem("22", 22);
	reportDay.addItem("23", 23);
	reportDay.addItem("24", 24);
	reportDay.addItem("25", 25);
	reportDay.addItem("26", 26);
	reportDay.addItem("27", 27);
	reportDay.addItem("28", 28);
	reportDay.addItem("29", 29);
	reportDay.addItem("30", 30);
	reportDay.addItem("31", 31);
	addAndMakeVisible(reportDay);
	
	reportMonth.addItem("1", 1);
	reportMonth.addItem("2", 2);
	reportMonth.addItem("3", 3);
	reportMonth.addItem("4", 4);
	reportMonth.addItem("5", 5);
	reportMonth.addItem("6", 6);
	reportMonth.addItem("7", 7);
	reportMonth.addItem("8", 8);
	reportMonth.addItem("9", 9);
	reportMonth.addItem("10", 10);
	reportMonth.addItem("11", 11);
	reportMonth.addItem("12", 12);
	addAndMakeVisible(reportMonth);

	reportDayEnd.addItem("1", 1);
	reportDayEnd.addItem("2", 2);
	reportDayEnd.addItem("3", 3);
	reportDayEnd.addItem("4", 4);
	reportDayEnd.addItem("5", 5);
	reportDayEnd.addItem("6", 6);
	reportDayEnd.addItem("7", 7);
	reportDayEnd.addItem("8", 8);
	reportDayEnd.addItem("9", 9);
	reportDayEnd.addItem("10", 10);
	reportDayEnd.addItem("11", 11);
	reportDayEnd.addItem("12", 12);
	reportDayEnd.addItem("13", 13);
	reportDayEnd.addItem("14", 14);
	reportDayEnd.addItem("15", 15);
	reportDayEnd.addItem("16", 16);
	reportDayEnd.addItem("17", 17);
	reportDayEnd.addItem("18", 18);
	reportDayEnd.addItem("19", 19);
	reportDayEnd.addItem("20", 20);
	reportDayEnd.addItem("21", 21);
	reportDayEnd.addItem("22", 22);
	reportDayEnd.addItem("23", 23);
	reportDayEnd.addItem("24", 24);
	reportDayEnd.addItem("25", 25);
	reportDayEnd.addItem("26", 26);
	reportDayEnd.addItem("27", 27);
	reportDayEnd.addItem("28", 28);
	reportDayEnd.addItem("29", 29);
	reportDayEnd.addItem("30", 30);
	reportDayEnd.addItem("31", 31);
	addAndMakeVisible(reportDayEnd);

	reportMonthEnd.addItem("1", 1);
	reportMonthEnd.addItem("2", 2);
	reportMonthEnd.addItem("3", 3);
	reportMonthEnd.addItem("4", 4);
	reportMonthEnd.addItem("5", 5);
	reportMonthEnd.addItem("6", 6);
	reportMonthEnd.addItem("7", 7);
	reportMonthEnd.addItem("8", 8);
	reportMonthEnd.addItem("9", 9);
	reportMonthEnd.addItem("10", 10);
	reportMonthEnd.addItem("11", 11);
	reportMonthEnd.addItem("12", 12);
	addAndMakeVisible(reportMonthEnd);
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
	viewTasks.setBounds(getWidth() / 6-getWidth()/7,getHeight()/2-getHeight()/6,getWidth()/3-getWidth()/10,getHeight()/12);
	
	addButton.setBounds(getWidth() / 3 ,getHeight()/2+getHeight()/8, getWidth() / 3, getHeight() / 12);
	reportDay.setBounds(29 * getWidth() / 60, getHeight() / 2+getHeight()/4, getWidth() / 12, getHeight() / 15);
	reportMonth.setBounds(34 * getWidth() / 60, getHeight() / 2+getHeight()/4, getWidth() / 12, getHeight() / 15);
	viewReport.setBounds(getWidth() / 3, getHeight() / 2 + getHeight() / 4, getWidth() / 12+getWidth()/15, getHeight() / 15);
	reportDayEnd.setBounds(29 * getWidth() / 60, getHeight() / 2 + getHeight() / 3, getWidth() / 12, getHeight() / 15);
	reportMonthEnd.setBounds(34 * getWidth() / 60, getHeight() / 2 + getHeight() / 3, getWidth() / 12, getHeight() / 15);

	updateTask.setBounds(getWidth() / 2 + getWidth() / 4+getWidth()/24, getHeight() / 2 + getHeight() / 8, getWidth() / 15, getHeight() / 15);
	deleteTask.setBounds(getWidth() / 2 + getWidth() / 4+getWidth()/14+getWidth()/24, getHeight() / 2 + getHeight() / 8, getWidth() / 15, getHeight() / 15);
	/*reportMonthEnd.setBounds(34 * getWidth() / 60, getHeight() / 2 + getHeight() / 4, getWidth() / 12, getHeight() / 15);
	reportDayEnd.setBounds(getWidth() / 3, getHeight() / 2 + getHeight() / 3, getWidth() / 12 + getWidth() / 15, getHeight() / 15);*/
	//priorityList.setBounds(getWidth() / 2 - 250, getHeight() / 2 - 100, 50, 30);

    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}

