#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct program{
  string name;
  string airTime;
};

int findProgram(program setBox[], string name, int count){
  for (int i=0;i<=count;i++){
    if (setBox[i].name == name){
      return i;
    }
  }
  return -1;
}

bool validateTimeStamp(string airTime){
  std::size_t index;
  std::string::size_type sz;
  // for (int i=0;i<airTime.length();i++){
  //   if ((airTime[i] <"0" || airTime[i] >"9") || airTime[i] != ":")
  //     return false;
  // }
  index = airTime.find(":");
  if (index == std::string::npos)
    return false;
  else {
    string hour = airTime.substr(0, index);
    int h = std::stoi(hour, &sz);
    if (h>=24)
      return false;
    string minute = airTime.substr(index+1, airTime.length());
    int m = std::stoi(minute, &sz);
    if (m>=60)
      return false;
  }
  return true;
}

// what if time is changed
void addProgram(program setBox[], string name, string airTime, int count){
  int ifExists = findProgram(setBox, name, count);
  if (ifExists > -1){
    cout << "Program " << name << " already exists in set top box" << endl;
    cout << endl;
  } else if (!validateTimeStamp(airTime)){
    cout << "Inavlid air time for program" << endl;
    cout << endl;
  } else {
    setBox[count].name = name;
    setBox[count].airTime = airTime;
  }
  return;
}

void printPorgrams(program setBox[], int count){
  for (int i=0;i<=count;i++){
    cout << "Name:  " << setBox[i].name <<", airTime: " << setBox[i].airTime << endl;
  }
}

int getHour(string airTime){
  std::size_t index;
  std::string::size_type sz;
  string hour = airTime.substr(0, index);
  int h = std::stoi(hour, &sz);
  return h;
}

int getMinute(string airTime){
  std::size_t index;
  std::string::size_type sz;
  index = airTime.find(":");
  string minute = airTime.substr(index+1, airTime.length());
  int m = std::stoi(minute, &sz);
  return m;
}

int getTimeDifference(string airTime, string currentTime){
  int h1 = getHour(airTime);
  int h2 = getHour(currentTime);
  // cout << "h1: " << h1 << ", h2: " << h2 << endl;
  if (h1-h2 <=1 && h1-h2 >=0){
    int m1 = getMinute(airTime);
    int m2 = getMinute(currentTime);
    // cout << "m1: " << m1 << ", m2 " << m2 << endl;
    if (h1-h2 == 0){
      if (m1-m2<=15)
        return m1-m2;
      else return -1;
    } else if (h1-h2 == 1){
      int diff = 60-m2+m1;
      if (diff <=15)
        return diff;
      return -1;
    }
  }
  return -1;
}

void sendAlert(program setBox[], int count, string currentTime, vector<string> subscriptions){
  if (!validateTimeStamp(currentTime)){
    cout << "Invalid time given" << endl;
  } else {
    for (int i=0; i<subscriptions.size();i++){
      int index = findProgram(setBox, subscriptions[i], count);
      string airTime = setBox[index].airTime;
      int diff = getTimeDifference(airTime, currentTime);
      // cout << "diff: " << diff;
      if (diff >=0)
        cout << "Program " << setBox[i].name << ", will be airing in " << diff << " minutes" << endl;
    }
  }
  return;
}

int main(){
  int number, count =0;
  string programName, airTime;
  program setBox[2000];
  vector<string> subscribtions;
  while (1){
    cout << "press 1 to add program, 2 to add subscribtion, 3 to remove subscription, 4: to enter current time" << endl;
    cin >> number;
    if (number == 1){
      cout << endl;
      cout << "Enter program name: ";
      cin >> programName;
      cout << "Enter airTime(HH:MM 24 hour format): ";
      cin >> airTime;
      cout << endl;
      addProgram(setBox, programName, airTime, count);
      count++;
    } else if (number == 2){
      cout << endl;
      cout << "enter program name: ";
      cin >> programName;
      if (findProgram(setBox, programName, count) == -1){
        cout << "Program does not exist in set top box" << endl;
        cout << endl;
      } else if (find(subscribtions.begin(), subscribtions.end(), programName) != subscribtions.end()){
        cout << "You have already subscribed to the program" << endl;
        cout << endl;
      } else {
        subscribtions.push_back(programName);
        cout << "You have subscribed to the program" << endl;
        cout << endl;
      }
    } else if (number == 3){
      cout << "Enter program name to remove subscription for: ";
      cin >> programName;
      vector<string>::iterator index;
      index = find(subscribtions.begin(), subscribtions.end(), programName);
      if (index == subscribtions.end()){
        cout << "You were not subscibed to the program" << endl;
        cout << endl;
      } else {
        subscribtions.erase(index);
        cout << "You have successfully unsubscribed to " << programName << endl;
        cout << endl;
      }
    } else if (number == 4){
      cout << "Enter current time (HH:MM) 24 hour format: ";
      cin >> airTime;
      sendAlert(setBox, count-1, airTime, subscribtions);
    } else {
      cout << "Invalid input" << endl;
      break;
    }
    sendAlert(setBox, count-1, airTime, subscribtions);
  }
  return 0;
}