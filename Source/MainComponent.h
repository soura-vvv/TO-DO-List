/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include <string.h>
#include <vector>
#include <ctime>




//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent   : public Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();
	std::vector<juce::String> tasks;
	std::vector<int> dtSaved;
	std::vector<int>monthSaved;
	std::vector<int> hour;
	std::vector<int> min;
    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
/*	juce::String addTask()
	{
		juce::String s = viewText.getText();
		return s;
	}*/
	int convert(int hh, int shift)
	{
		if (shift == 2 && hh != 12)
			hh += 12;
		if (shift == 1 && hh == 12)
			hh = 0;
		return hh;
	}
	void addTask()
	{
		int i=1;
		juce::String s = taskText.getText();
		juce::String sam = hourBox.getItemText(hourBox.getSelectedItemIndex());
		sam=sam+minuteBox.getItemText(minuteBox.getSelectedItemIndex());
		sam=sam+am_pmBox.getItemText(am_pmBox.getSelectedItemIndex());
		int h = hourBox.getSelectedItemIndex();
		int m = minuteBox.getSelectedItemIndex();
		int sh = am_pmBox.getSelectedItemIndex();
		hour.push_back(convert(h,sh));
		min.push_back(15*(--m));

		/*
		time_t now = time(0);
		tm* ltm = localtime(&now);
		dtSaved.push_back(ltm->tm_mday);
		monthSaved.push_back(ltm->tm_mon);*/
		tasks.push_back(s);
		
		taskList.addColouredItem(i, s, Colours::white);
		taskList.addSubMenu(sam,timeList);
		s = s + sam;
		i++;
		alertUser(s);
		/*cout << "\nEnter time" << endl;
		cout << "\nHours=";
		cin >> hours;
		cout << "\nminutes=";
		cin >> minutes;
		hour.push_back(hours);
		min.push_back(minutes);*/

	}
	void timeCheck()
	{
		std::vector<int>::iterator it;
		time_t now = time(0);
		tm* ltm = localtime(&now);
		if (ltm->tm_min == 0 || ltm->tm_min == 15 || ltm->tm_min == 30 || ltm->tm_min == 45)
		{
			it = std::find(hour.begin(), hour.end(), ltm->tm_hour);
		}
	}
	void displayTask(int z)
	{
		juce::String f= tasks[z];
		
		viewText.setText(f);
	}
	void alertUser(juce::String alertMessage)
	{
		//juce::AlertWindow* w = new juce::AlertWindow("Alert", "", juce::AlertWindow::NoIcon);
		//w->addToDesktop();
		bool complete=AlertWindow::showOkCancelBox(juce::AlertWindow::WarningIcon, "Reminder!", alertMessage, "Mark as Completed!", "Mark as Incomplete!", nullptr, nullptr);
	
		
		
	}
    //==============================================================================
    // Your private member variables go here...
	TextButton addButton{ "Add Task" };
	TextButton viewTasks{ "View TAsks" };
	TextButton viewReport{ "Generate Report" };
	TextEditor taskText,taskDescription;
	int selectedTask;
	Rectangle<int> mainFrame,taskFrame,addFrame,viewFrame;
	TextEditor viewText;
	ComboBox priorityCheck;
	Label priorityLabel,timeLabel;
	ComboBox hourBox, minuteBox, am_pmBox;
	PopupMenu taskList,timeList;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
