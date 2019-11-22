/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include <string.h>
#include <vector>





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
	std::vector<juce::String> description;
	std::vector<juce::String> priorities;
	std::vector<int> hour;
	std::vector<int> min;
	std::vector<juce::String> dtSaved;

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
		
		juce::String s = taskDescription.getText();
		juce::String des = taskText.getText();
		juce::String priority = priorityCheck.getItemText(priorityCheck.getSelectedItemIndex());

		juce::String sam ="";
		sam=sam+" " +hourBox.getItemText(hourBox.getSelectedItemIndex());
		sam=sam+minuteBox.getItemText(minuteBox.getSelectedItemIndex());
		sam=sam+am_pmBox.getItemText(am_pmBox.getSelectedItemIndex());
		sam = sam + " " + priority;
		taskList.addColouredItem(i, s, Colours::white);
		taskList.addSubMenu(sam, timeList);
		i = i + 1;
		int h = hourBox.getSelectedItemIndex();
		int m = minuteBox.getSelectedItemIndex();
		int sh = am_pmBox.getSelectedItemIndex();
		h = convert(h, sh);

		tasks.push_back(s);
		description.push_back(des);
		priorities.push_back(priority);
		hour.push_back(h);
		min.push_back(15*(--m));
		time_t now = time(0);
		tm* ltm = localtime(&now);
		juce::String temp = String(timeobj.getDayOfMonth());
		temp += String(timeobj.getMonth());
		dtSaved.push_back(temp);
		alertUser(s);
		
	}
	void timeCheck()
	{
		viewText.setText("Workinasjdaskjdhslkd");
	}
	void displayTask(int z)
	{
		if (z == 0)
			viewText.setText("Nothing Selected :(");
		else
		{
			juce::String f = tasks[z - 2];
			f = f+"\n"+"Description :  "+description[z - 2];
			
			viewText.setText(f);
		}
				
		
		
		
	}
	void deleteTasks()
	{
		int z = selectedTask;
		if (z == 0)
		{

		}
		else
		{
			tasks.erase(tasks.begin()+z-2);
			description.erase(description.begin() + z - 2);
			priorities.erase(priorities.begin() + z - 2);
			hour.erase(hour.begin() + z - 2);
			min.erase(min.begin() + z - 2);
			dtSaved.erase(dtSaved.begin() + z - 2);
			taskList.clear();
			viewText.setText("Task has Been Deleted :(");
			taskList.addItem(1, "Task", false, false);
			for (int i = 0; i < tasks.size(); i++)
			{
				taskList.addColouredItem(i + 2, tasks[i], Colours::white);
				taskList.addSubMenu(juce::String(hour[i])+":"+String(min[i])+" "+priorities[i], timeList);
			}
		}
	}
	void alertUser(juce::String alertMessage)
	{
		//juce::AlertWindow* w = new juce::AlertWindow("Alert", "", juce::AlertWindow::NoIcon);
		//w->addToDesktop();
		bool complete=AlertWindow::showOkCancelBox(juce::AlertWindow::WarningIcon, "Reminder!", alertMessage, "Mark as Completed!", "Mark as Incomplete!", nullptr, nullptr);
	
		
		
	}
	void displayReport(int daystart, int monthstart, int dayend, int monthend)
	{
		juce::String reportMessage = "Tasks Completed Are  ";
		bool okay = AlertWindow::showOkCancelBox(juce::AlertWindow::NoIcon, "Report", reportMessage, "OK");
	}
    //==============================================================================
    // Your private member variables go here...
	TextButton addButton{ "Add Task" };
	TextButton viewTasks{ "View Tasks" };
	TextButton viewReport{ "Generate Report" };
	TextButton updateTask{ "Update Task" };
	TextButton deleteTask{ "Delete Task" };

	TextEditor taskText,taskDescription;
	int selectedTask;
	Rectangle<int> mainFrame,taskFrame,addFrame,viewFrame;
	TextEditor viewText;
	ComboBox priorityCheck;
	Label priorityLabel,timeLabel;
	ComboBox hourBox, minuteBox, am_pmBox;
	PopupMenu taskList,timeList;
	ComboBox reportDay, reportMonth,reportDayEnd,reportMonthEnd;
	Time timeobj;
	int i = 2;
	
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
