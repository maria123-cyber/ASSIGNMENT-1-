#include <iostream>
#include <string>

using namespace std;

struct Task {
	 // unique task id 
    int id; 
	// task description               
    string description;
	// task priority        
    int priority;             
    Task* next;       // Pointer to the next task in the linked list
};

// Function to create a new task
Task* createTask(int id, string description, int priority) {
    //  memory allocated(dynamic) for a new task
    Task* newTask = new Task;
	// assign a task ID      
    newTask->id = id;    
	// assign the task description          
    newTask->description = description;  
    // assign the task priority
    newTask->priority = priority; 
	 //  next pointer to null (i.e.,end of the list for now) 
    newTask->next = NULL;   
	// return the pointer to the newly task that is created      
    return newTask;                
}

// function to add a new task 
void addTask(Task*& head, int id, string description, int priority) {
    Task* newTask = createTask(id, description, priority); 
    // check if the list is empty or if the new task has higher priority than the current head
    if (head == NULL || head->priority < priority) { 
    
     // insert the new task before the current head
        newTask->next = head; 
        head = newTask;        // update head to point to the new task
    } else {
    	// start from the head to find the correct insertion point
        Task* current = head;  
        // traverse the list until you find the correct position for the new task based on priority
        while (current->next != NULL && current->next->priority >= priority) {  
            current = current->next;
        }
        // insert the new task in the correct position
        newTask->next = current->next;
        current->next = newTask;
    }
    cout << "Task added successfully.\n"; 
}

// Function to remove the task with the highest priority
void removeHighestPriorityTask(Task*& head) {
    // if the list is empty
    if (head == NULL) {  
        cout << "No tasks available to remove.\n";
        return;
    }
    // remove the head (highest priority task) and update the head to the next task
    Task* temp = head;
    head = head->next;
    cout << "Removed task with ID: " << temp->id << "\n"; 
    // free the memory allocated for the removed task
    delete temp;  
}

// Function to remove a specific task by its ID
void removeTaskById(Task*& head, int id) {
    // if the list is empty
    if (head == NULL) {  
        cout << "No tasks available.\n";
        return;
    }
    // if the task to be removed is the head, update the head
    if (head->id == id) {
        Task* temp = head;
        head = head->next;
        cout << "Removed task with ID: " << temp->id << "\n";  
        delete temp; 
        return;
    }
    // Traverse the list to find the task to be removed
    Task* current = head;
    while (current->next != NULL && current->next->id != id) {  
        current = current->next;
    }
    // if the task with the specific ID was not found
    if (current->next == NULL) { 
        cout << "Task with ID " << id << " not found.\n";
    } else {
        // Remove the task by adjusting pointers and freeing memory
        Task* temp = current->next;
        current->next = temp->next;
        cout << "Removed task with ID: " << temp->id << "\n";  
        delete temp;  
    }
}

// Function to view all tasks
void viewTasks(Task* head) {
    // if the list is empty
    if (head == NULL) {  
        cout << "No tasks available.\n";
        return;
    }
    // Traverse the list and display each task information
    Task* current = head;
    while (current != NULL) {  
        cout << "ID: " << current->id << ", Description: " << current->description << ", Priority: " << current->priority << "\n";
             //go to the next task
        current = current->next;  
    }
}
// Main function
int main() {
	// initialize the head of the task list to NULL
    Task* head = NULL;
    
	// variables for user input  
    int choice, id, priority;  
    string description;
    //while loop until the user exit
    while (true) {
       
        cout << "\nTask Manager Menu:\n";
        cout << "1. Add a new task\n";
        cout << "2. View all tasks\n";
        cout << "3. Remove the highest priority task\n";
        cout << "4. Remove a task by ID\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        
        cin >> choice;  

        switch (choice) {
            case 1:
                // add a new task
                cout << "Enter task ID: ";
                cin >> id;
                cin.ignore();
                
                cout << "Enter task description: ";
               // Get the task description
                getline(cin, description); 
                
                cout << "Enter task priority: ";
                cin >> priority;
                
                // Call the function to add the task
                addTask(head, id, description, priority);  
                break;
            case 2:
                viewTasks(head);  
                break;
            case 3:
                removeHighestPriorityTask(head); 
                break;
            case 4:
                cout << "Enter task ID to remove: ";
                cin >> id;
                removeTaskById(head, id);  
                break;
            case 5:
            	// free memory before exit the program
               cin.ignore() ;
                cout << "Exiting...\n";
                return 0;  
            default:
                cout << "Invalid choice. Try again.\n";  
        }
    }

    return 0;
}




