#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

//===============NABIHA'S CODE==================

// Abstract base class
class AbstractProfile {
public:
    virtual void setInfo() = 0;         // Pure virtual function
    virtual void displayInfo() = 0;      // Pure virtual function
    virtual void updatePhone() = 0;      // Pure virtual function
    virtual string getName() = 0;         // Pure virtual function
};

//Class to store user personal info
class UserProfile : public AbstractProfile {
private:
    string name;
    string email;
    int age;
    string universityID;
    string phoneNumber;
    string learningStyle;
    string motivationLevel;
    string energyLevel;

public:
    UserProfile() {
        name = email = universityID = phoneNumber = learningStyle = motivationLevel = energyLevel = "Not set";
        age = 0;
    }

    void setInfo() override {
        cout << "\nEnter your name: ";
        cin >> name;
        cout << "Enter your email: ";
        cin >> email;
        cout << "Enter your age: ";
        cin >> age;
        cout << "Enter your university ID: ";
        cin >> universityID;
        cout << "Enter your phone number: ";
        cin >> phoneNumber;
        cout << "Enter your learning style (Visual/Auditory/Kinesthetic): ";
        cin >> learningStyle;
        cout << "Enter your motivation level (High/Medium/Low): ";
        cin >> motivationLevel;
        cout << "Enter your energy level (Morning/Afternoon/Night): ";
        cin >> energyLevel;
    }

    void displayInfo() override {
        cout << "\n--- User Profile ---\n";
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "Age: " << age << endl;
        cout << "University ID: " << universityID << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Learning Style: " << learningStyle << endl;
        cout << "Motivation Level: " << motivationLevel << endl;
        cout << "Energy Level: " << energyLevel << endl;
    }

    void updatePhone() override {
        cout << "Enter new phone number for " << name << ": ";
        cin >> phoneNumber;
        cout << "Phone number updated successfully!\n";
    }

    // Getter functions
    string getName() override { return name; }
    string getLearningStyle() { return learningStyle; }
    string getMotivationLevel() { return motivationLevel; }
    string getEnergyLevel() { return energyLevel; }
};

//Class to match users interest 
class PersonalityMatch {
public:
    static bool isCompatible(UserProfile& user1, UserProfile& user2) {
        return (user1.getLearningStyle() == user2.getLearningStyle() &&
                user1.getMotivationLevel() == user2.getMotivationLevel() &&
                user1.getEnergyLevel() == user2.getEnergyLevel());
    }
};

// All main menu work is done inside this function
void Profile() {
    int numberOfUsers;
    cout << "How many user profiles do you want to create? ";
    cin >> numberOfUsers;

    UserProfile users[numberOfUsers];

    // Step 1: Input profiles
    for (int i = 0; i < numberOfUsers; i++) {
        cout << "\nEntering information for User " << i + 1 << ":\n";
        users[i].setInfo();
    }

    // Step 2: Menu system
    int choice;
    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Display all user profiles\n";
        cout << "2. Check personality matches\n";
        cout << "3. Update a user's phone number\n";
        cout << "4. Search for a user by name\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nAll User Profiles:\n";
                for (int i = 0; i < numberOfUsers; i++) {
                    users[i].displayInfo();
                }
                break;

            case 2:
                cout << "\nChecking personality matches:\n";
                for (int i = 0; i < numberOfUsers; i++) {
                    for (int j = i + 1; j < numberOfUsers; j++) {
                        if (PersonalityMatch::isCompatible(users[i], users[j])) {
                            cout << "User " << users[i].getName() << " and User " << users[j].getName() << " are COMPATIBLE!\n";
                        } else {
                            cout << "User " << users[i].getName() << " and User " << users[j].getName() << " are NOT compatible.\n";
                        }
                    }
                }
                break;

            case 3: {
                string searchName;
                cout << "Enter the name of the user to update phone number: ";
                cin >> searchName;

                bool found = false;
                for (int i = 0; i < numberOfUsers; i++) {
                    if (users[i].getName() == searchName) {
                        users[i].updatePhone();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "User not found!\n";
                }
                break;
            }

            case 4: {
                string searchName;
                cout << "Enter the name to search: ";
                cin >> searchName;

                bool found = false;
                for (int i = 0; i < numberOfUsers; i++) {
                    if (users[i].getName() == searchName) {
                        users[i].displayInfo();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "User not found!\n";
                }
                break;
            }

            case 0:
                cout << "Exiting the program...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
}

//===============SEHRISH'S CODE==========

//Student class to store their attributes 
class Student {
private:
    string name;
    string email;
    string personality;
    string availableTime;
    string subject;

public:
	//constructor to initialize student attributes 
    Student(string n, string e, string p, string time, string fav)
        : name(n), email(e), personality(p), availableTime(time), subject(fav) {}

    //getter fir student name 
    string getName() const { return name; }

    //function to display student profile 
    void printProfile() const {
        cout << "\nPROFILE INFO \n";
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "Personality Type: " << personality << endl;
        cout << "Available Time: " << availableTime << endl;
        cout << "Subject: " << subject << endl;
    }
};

// Class to store and display the notes send in the group
class Note {
private:
    string sender;
    string message;

public:
	//constructor to initialize sender and message 
    Note(string typer, string msg) : sender(typer), message(msg) {}
    
    // function to display the note 
    void show() const {
        cout << "\n " << sender << " says: " << message << "\n";
    }
};

//Class to manage the study groups, their members and notes
class GroupFormation {
private:
    string GroupSubject;
    string GroupPersonality;
    string GroupAvailableTime;
    vector<Student> members;
    vector<Note> messages;

public:
	//constructor to initialize group attributes 
    GroupFormation(string s, string p, string t) : GroupSubject(s), GroupPersonality(p), GroupAvailableTime(t) {}

    // add a new student to the group
    void addMember(const Student& s) {
        members.push_back(s);
        cout << s.getName() << " has just entered the " << GroupSubject << " group!\n";
    }

    // leave a note in the group
    void leaveNote(const string& from, const string& what) {
        messages.emplace_back(from, what);
        cout << "Note has been added in " << GroupSubject << " group!\n";
    }

    //display all notes for the group
    void showNotes() const {
        cout << "\nNotes for " << GroupSubject << ":\n";
        for (const auto& m : messages)
            m.show();
    }

    // display all members of the group
    void listMembers() const {
        cout << "\nGroup for " << GroupSubject << " (" << GroupPersonality << ", " << GroupAvailableTime << "):\n";
        for (const auto& m : members)
            m.printProfile();
    }

    // getters for group attributes 
    string getSubject() const { return GroupSubject; }
    string getPersonality() const { return GroupPersonality; }
    string getAvailableTime() const { return GroupAvailableTime; }
};

// function to run the main scheduler interface 
void runScheduler() {
    vector<GroupFormation> groups;
    int choice = 0;

    do {
    	// display the main menu 
        cout << "\n=== Study Group Scheduler Menu ===\n";
        cout << "1. Make a new Group\n";
        cout << "2. Add a Student\n";
        cout << "3. View Groups\n";
        cout << "4. Leave a Note\n";
        cout << "5. Read Notes\n";
        cout << "6. Quit/Exit\n";
        cin >> choice;
        cin.ignore(); // ignore newline after reading choice 

        if (choice == 1) {
        	// create a new group 
            string s, p, t;
            cout << "\nSubject: "; getline(cin, s);
            cout << "Group Personality: "; getline(cin, p);
            cout << "Time Available : "; getline(cin, t);

            groups.emplace_back(s, p, t);
            cout << "Group for " << s << " is ready to roll!\n";

        } else if (choice == 2) {
        	// add a  student to an existing group 
            if (groups.empty()) {
                cout << "\nMake a Group first, no group available!\n";
                continue;
            }
            
            // prompt to locate group
            string s, p, t;
            cout << "\nFind your group!\nSubject: "; getline(cin, s);
            cout << "Group Personality: "; getline(cin, p);
            cout << "Time Available: "; getline(cin, t);

            bool found = false;
            for (auto& c : groups) {
                if (c.getSubject() == s && c.getPersonality() == p && c.getAvailableTime() == t) {
                    string n, e, p, t, sub;
                    // prompt for student details 
                    cout << "Name: "; getline(cin, n);
                    cout << "Email: "; getline(cin, e);
                    cout << "Personality: "; getline(cin, p);
                    cout << "Available Time: "; getline(cin, t);
                    cout << "Subject: "; getline(cin, sub);

                    Student newb(n, e, p, t, sub);
                    c.addMember(newb);
                    found = true;
                    break;
                }
            }
            if (!found) cout << "\nNo matching group has been found. Make a group first!\n";

        } else if (choice == 3) {
        	// view group members 
            if (groups.empty()) cout << "\nNo groups yet.\n";
            else {
                for (const auto& c : groups)
                    c.listMembers();
            }

        } else if (choice == 4) {
        	// leave a note in the group 
            if (groups.empty()) {
                cout << "\nNo groups to leave notes in.\n";
                continue;
            }

            string s, p, t, n, msg;
            cout << "\nFind your group!\nSubject: "; getline(cin, s);
            cout << "Group Personality: "; getline(cin, p);
            cout << "Available Time: "; getline(cin, t);

            bool found = false;
            for (auto& c : groups) {
                if (c.getSubject() == s && c.getPersonality() == p && c.getAvailableTime() == t) {
                    cout << "Your Name: "; getline(cin, n);
                    cout << "Message: "; getline(cin, msg);
                    c.leaveNote(n, msg);
                    found = true;
                    break;
                }
            }
            if (!found) cout << "\nCouldn't spot that group.\n";

        } else if (choice == 5) {
        	// read notes in the group 
            if (groups.empty()) {
                cout << "\nNo groups, no notes.\n";
                continue;
            }

            string s, p, t;
            cout << "\nFind your group!\nSubject: "; getline(cin, s);
            cout << "Group Personality: "; getline(cin, p);
            cout << "Available Time: "; getline(cin, t);

            bool found = false;
            for (const auto& c : groups) {
                if (c.getSubject() == s && c.getPersonality() == p && c.getAvailableTime() == t) {
                    c.showNotes();
                    found = true;
                    break;
                
            }
        }
            if (!found) cout << "\nCouldn't spot that group.\n";
        
		}else if (choice != 6) {
			// invalid input handler 
            cout << "\nPick a valid option!\n";
        }

    } while (choice != 6);

    cout << "\nThank You for using this System! Good luck with your studies!\n";
}

//=================HAMZA'S CODE================

#define Max_q 10
#define Max_a 20
#define maximum_sessions 50
#define maxf 10
#define maxll 200

//Class to store the session timings and date 
class session {
public:
    int session_id;
    string description;   // Use string instead of char array
    string timestamp;     // Use string instead of char array

    session(int id, const string& descrip) : session_id(id), description(descrip) {
        time_t now = time(0);
        char* timeStr = ctime(&now);
        timestamp = string(timeStr);  // Convert to string
    }

    void displayDetails() {
        cout << "=====================================================" << endl;
        cout << "=======  Session ID : " << session_id << endl;
        cout << "=======  Description: " << description << endl;
        cout << "=======  Time       : " << timestamp << endl;
        cout << "=====================================================" << endl;
    }

    void savesessionTofile(const string& filename) {
        ofstream outfile(filename, ios::app);
        if (!outfile) {
            cout << "Error opening file for writing: " << filename << endl;
            return;
        }
        outfile << "=====================================================" << endl;
        outfile << "========  Session ID  : " << session_id << endl;
        outfile << "========  Description : " << description << endl;
        outfile << "========  Time        : " << timestamp << endl;
        outfile << "=====================================================" << endl << endl;
        outfile.close();
    }

    void loadsessionFromfile(const string& filename) {
        ifstream infile(filename);
        if (!infile) {
            cout << "Error opening file for reading: " << filename << endl;
            return;
        }
        string line;
        while (getline(infile, line)) {
            cout << line << endl;
        }
        infile.close();
    }
};

// Class derived from session to generate ice breaker session
class Icebreaker : public session {
private:
    string questions[Max_q];  // Use string instead of char array
    string answers[Max_a];    // Use string instead of char array
    int answerCount;          // Declare the answerCount variable

    void initializeQuestions() {
        string initialQuestions[Max_q] = {
            "What's your favorite hobby and why?",
            "If you could travel anywhere, where would you go?",
            "What's your favorite book or movie?",
            "What's something you're passionate about?",
            "What's your favorite way to spend a weekend?",
            "If you could have dinner with anyone, who would it be?",
            "What's your proudest accomplishment?",
            "What's your favorite food?",
            "Do you have any hidden talents?",
            "What's your favorite season and why?"
        };
        for (int i = 0; i < Max_q; i++) {
            questions[i] = initialQuestions[i];
        }
    }

public:
    Icebreaker(int id) : session(id, "Icebreaker session"), answerCount(0) {  // Initialize answerCount to 0
        initializeQuestions();
    }

    void startsession() {
        cout << "\nStarting Icebreaker session...\n";
        srand(time(0));
        int usedIndexes[6] = {0};
        int usedCount = 0;
        for (int i = 0; i < 6 && i < Max_q; i++) {
            int index;
            do {
                index = rand() % Max_q;
            } while (isQuestionUsed(index, usedIndexes, usedCount));
            usedIndexes[usedCount++] = index;
            askQuestion(questions[index]);
        }
        cout << "\nIcebreaker session completed successfully!\n";
    }

    bool isQuestionUsed(int index, int usedIndexes[], int usedCount) {
        for (int i = 0; i < usedCount; i++) {
            if (usedIndexes[i] == index) {
                return true;
            }
        }
        return false;
    }

    void askQuestion(const string& question) {
        cout << "\nQuestion: " << question << endl;
        string userAnswer;
        cout << "Your answer: ";
        getline(cin, userAnswer);
        answers[answerCount++] = userAnswer;  // Use the answerCount variable
        cout << "Thank you for your answer!\n";
    }
};

//Class derived from session to store the student's feedback 
class Feedback : public session {
private:
    string feedbacks[maxf];  // Use string instead of char array
    int feedbackCount;

public:
    Feedback(int id) : session(id, "Feedback session") {
        feedbackCount = 0;
    }

    void startsession() {
        cout << "=====================================================" << endl;
        cout << "=====================================================" << endl;
        cout << "\nStarting Feedback session...\n";
        cout << "Enter your feedback (type 'done' when finished):\n";
        string response;
        while (feedbackCount < maxf) {
            cout << "> ";
            getline(cin, response);
            if (response == "done") break;
            feedbacks[feedbackCount++] = response;
        }
        cout << "\nThanks for your feedback!";
        cout << "=====================================================" << endl;
        cout << "=====================================================" << endl;
    }
};

//Class to store the student's group history 
class HistoryTracker {
private:
    static HistoryTracker* instance;
    session* sessions[maximum_sessions];
    int sessionCount;

    HistoryTracker() : sessionCount(0) {
        for (int i = 0; i < maximum_sessions; i++) {
            sessions[i] = nullptr;
        }
    }

public:
    static HistoryTracker* getInstance() {
        if (!instance) {
            instance = new HistoryTracker();
        }
        return instance;
    }

    void addsession(session* session) {
        if (sessionCount < maximum_sessions) {
            sessions[sessionCount++] = session;
        }
    }

    void displayHistory() {
        cout << "\n=== Session History ===" << endl;
        for (int i = 0; i < sessionCount; i++) {
            sessions[i]->displayDetails();
        }
    }

    void saveAllsessions(const string& filename) {
        ofstream outfile(filename);
        if (!outfile) {
            cout << "Error opening file for writing: " << filename << endl;
            return;
        }
        for (int i = 0; i < sessionCount; i++) {
            sessions[i]->savesessionTofile(filename);
        }
        outfile.close();
    }

    ~HistoryTracker() {
        for (int i = 0; i < sessionCount; i++) {
            delete sessions[i];
        }
    }
};

HistoryTracker* HistoryTracker::instance = nullptr;

// All the main menu work is done in this function
void IceBreaker() {
    HistoryTracker* tracker = HistoryTracker::getInstance();
    int choice;
    int sessionCounter = 1;
    string filename = "sessions.txt";
    
    while (true) {
        cout << "\n=== Study Group Scheduler ===" << endl;
        cout << "1. Start Icebreaker session" << endl;
        cout << "2. Start Feedback session" << endl;
        cout << "3. View session History" << endl;
        cout << "4. Save All sessions" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                Icebreaker* session = new Icebreaker(sessionCounter++);
                tracker->addsession(session);
                session->displayDetails();
                session->startsession();
                session->savesessionTofile(filename);
                break;
            }
            case 2: {
                Feedback* session = new Feedback(sessionCounter++);
                tracker->addsession(session);
                session->displayDetails();
                session->startsession();
                session->savesessionTofile(filename);
                break;
            }
            case 3:
                tracker->displayHistory();
                cout << "\nPress enter to continue...";
                cin.ignore();
                break;
            case 4:
                tracker->saveAllsessions(filename);
                cout << "All sessions saved to " << filename << endl;
                break;
            case 5:
                delete tracker;
                cout << "Thanks for using. Please come again." << endl << endl;
                return ;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

//===============IRTZA'S CODE===============

//Notification Base Class
class Notification {
public:
    virtual void display() const = 0; // Pure virtual function
    virtual ~Notification() {}
};

//ReminderNotification (Derived Class)
class ReminderNotification : public Notification {
    string message;
public:
    ReminderNotification(string msg) : message(msg) {}
    void display() const override {
        cout << "[Reminder] " << message << endl;
    }
};

//InviteNotification (Derived Class)
class InviteNotification : public Notification {
    string groupName;
public:
    InviteNotification(string name) : groupName(name) {}
    void display() const override {
        cout << "[Invite] You've been invited to group: " << groupName << endl;
    }
};

//StudyGroup Class
class StudyGroup {
    string groupName;
    string subject;
public:
    StudyGroup(string name = "", string sub = "") : groupName(name), subject(sub) {}

    void displayInfo() const {
        cout << "Group: " << groupName << " | Subject: " << subject << endl;
    }
};

//SchedulerSystem Class (Handles all logic)
class SchedulerSystem {
    static const int MAX_GROUPS = 10;
    static const int MAX_NOTIFS = 10;

    StudyGroup groups[MAX_GROUPS];
    Notification* notifications[MAX_NOTIFS];
    int groupCount;
    int notifCount;

public:
    SchedulerSystem() : groupCount(0), notifCount(0) {}

    void displayGroups() const {
        if (groupCount == 0) {
            cout << "No study groups available.\n";
            return;
        }
        cout << "\n--- Study Groups ---\n";
        for (int i = 0; i < groupCount; ++i) {
            groups[i].displayInfo();
        }
    }

    void viewNotifications() const {
        if (notifCount == 0) {
            cout << "No notifications.\n";
            return;
        }
        cout << "\n--- Notifications ---\n";
        for (int i = 0; i < notifCount; ++i) {
            notifications[i]->display();
        }
    }

    void addGroup(string name, string subject) {
        if (groupCount < MAX_GROUPS) {
            groups[groupCount++] = StudyGroup(name, subject);
            cout << "Group added successfully.\n";
        } else {
            cout << "Cannot add more groups.\n";
        }
    }

    void addNotification(Notification* notif) {
        if (notifCount < MAX_NOTIFS) {
            notifications[notifCount++] = notif;
            cout << "Notification added.\n";
        } else {
            cout << "Notification limit reached.\n";
            delete notif;
        }
    }

    ~SchedulerSystem() {
        for (int i = 0; i < notifCount; ++i) {
            delete notifications[i];
        }
    }
};

//Menu Display
void showMenu() {
    cout << "\n=== Study Group Scheduler Menu ===\n";
    cout << "1. View Study Groups\n";
    cout << "2. View Notifications\n";
    cout << "3. Add Group\n";
    cout << "4. Add Reminder Notification\n";
    cout << "5. Add Invite Notification\n";
    cout << "6. Exit\n";
    cout << "Choose an option: ";
}

// Function with main working 
void notifications() {
    SchedulerSystem system;
    int choice;

    do {
        showMenu();
        cin >> choice;
        cin.ignore(); // To clear newline from buffer

        if (choice == 1) {
            system.displayGroups();
        }
        else if (choice == 2) {
            system.viewNotifications();
        }
        else if (choice == 3) {
            string name, subject;
            cout << "Enter group name: ";
            getline(cin, name);
            cout << "Enter subject: ";
            getline(cin, subject);
            system.addGroup(name, subject);
        }
        else if (choice == 4) {
            string message;
            cout << "Enter reminder message: ";
            getline(cin, message);
            system.addNotification(new ReminderNotification(message));
        }
        else if (choice == 5) {
            string group;
            cout << "Enter group name for invite: ";
            getline(cin, group);
            system.addNotification(new InviteNotification(group));
        }
        else if (choice == 6) {
            cout << "Goodbye!\n";
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 6);
}


// ========== MAIN FUNCTION ==========
int main() {
	
	int choiceMake;
	do{
		
	cout<<"\n=======================================\n";
	cout<<"WELCOME TO STUDY GROUP SCHEDULER SYSTEM\n";
	cout<<"=======================================\n";
	cout<<"\n** Enter your choice\n";
	cout<<"\n1. Profile Creation And Group Matching\n";
	cout<<"2. Group Formation And Adding Notes\n";
	cout<<"3. IceBreaker and Feedbacks\n";
	cout<<"4. Notification Reminders and Group Displaying\n";
	cout<<"5. Exit/Quit the system\n";

	cin>> choiceMake;
	
	switch(choiceMake){
		
		case 1:
			Profile();
			break;
		case 2:
			runScheduler();
			break;
		case 3:
			IceBreaker();
			break;
		case 4:
			notifications();
			break;
		case 5:
		    cout<< "THANK YOU FOR USING THE STUDY GROUP SCHEDULER!!" << endl;
			break;	
		default:
			"Invalid Choice!!";
	}
	
   }while(choiceMake != 5);
	
    return 0;
}