#include <bits/stdc++.h>
using namespace std;

/*
Entities: 
1) User
2) Meeting
3) MeetingRoom
4) MeetingScheduler
5) NotificationService
6) Calendar
*/

// User class
class User{
    string name,id,email;
public:
    User(string name, string id, string email) : name(name), id(id), email(email) {}
    string getName() const{
        return name;
    }
};

// Meeting class
class Meeting{
    int startTime, endTime, id, capacity;
    vector<User> attendees;
public:
    Meeting(int startTime, int endTime,int id, int capacity, vector<User> attendees) : startTime(startTime), endTime(endTime), id(id), capacity(capacity), attendees(attendees) {}
    
    int getId() const {
        return id;
    }
    
    int getStartTime() const {
        return startTime;
    }
    
    int getEndTime() const {
        return endTime;
    }
};


// meetingRoom class
class MeetingRoom{
    int id, capacity;
    vector<Meeting> meetings;
public:
    MeetingRoom(int id, int capacity) : id(id), capacity(capacity) {}

    bool isAvailable(int startTime, int endTime){
        for(auto meeting : meetings){
            if(max(meeting.getStartTime(), startTime) < min(meeting.getEndTime(), endTime)){
                return false;
            }
        }
        return true;
    }

    void addMeeting(Meeting meeting){
        meetings.push_back(meeting);
    }
};

// NotificationService class
class NotificationService{
public:
    void sendNotification(vector<User> attendees, Meeting meeting){
        for(auto user : attendees){
            cout << "Sending notification to " << user.getName() << " for meeting " << meeting.getId() << endl;
        }
    }
};

// MeetingScheduler class
class MeetingScheduler{
    vector<MeetingRoom> meetingRooms;
    NotificationService notificationService;
    int meetingId;
public:
    MeetingScheduler() : meetingId(0) {}
    void addMeetingRoom(MeetingRoom meetingRoom){
        meetingRooms.push_back(meetingRoom);
    }
    
    bool scheduleMeeting(int startTime, int endTime, int capacity, vector<User> attendees){
        for(auto meetingRoom : meetingRooms){
            if(meetingRoom.isAvailable(startTime, endTime)){
                Meeting meeting(startTime, endTime, meetingId++, capacity, attendees);
                meetingRoom.addMeeting(meeting);
                notificationService.sendNotification(attendees, meeting);
                return true;
            }
        }
        return false;
    }
};

int main() {
    // Create users
    User user1("John", "1", "john@example.com");
    User user2("Alice", "2", "alice@example.com");
    User user3("Bob", "3", "bob@example.com");
    
    // Create meeting rooms
    MeetingRoom room1(1, 5);  // Room 1 with capacity 5
    MeetingRoom room2(2, 10); // Room 2 with capacity 10
    
    // Create meeting scheduler
    MeetingScheduler scheduler;
    scheduler.addMeetingRoom(room1);
    scheduler.addMeetingRoom(room2);
    
    // Test Case 1: Schedule a meeting with available room
    vector<User> attendees1 = {user1, user2};
    bool result1 = scheduler.scheduleMeeting(9, 10, 2, attendees1); // 9-10 AM meeting
    cout << "Test Case 1 - Schedule Meeting: " << (result1 ? "Success" : "Failed") << endl;
    
    // Test Case 2: Schedule overlapping meeting
    vector<User> attendees2 = {user2, user3};
    bool result2 = scheduler.scheduleMeeting(9, 11, 2, attendees2); // 9-11 AM meeting (should fail due to overlap)
    cout << "Test Case 2 - Schedule Overlapping Meeting: " << (result2 ? "Success" : "Failed") << endl;
    
    // Test Case 3: Schedule meeting in different time slot
    vector<User> attendees3 = {user1, user2, user3};
    bool result3 = scheduler.scheduleMeeting(14, 15, 3, attendees3); // 2-3 PM meeting
    cout << "Test Case 3 - Schedule Different Time Slot: " << (result3 ? "Success" : "Failed") << endl;
    
    return 0;
}