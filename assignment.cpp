#include <iostream>
#include <queue>

class Concert {
private:
    int capacity;                      // Total seating capacity of the theater
    std::queue<int> queue;             // Queue to store student IDs in the order they arrive
    int seated_students;               // Counter for the number of students seated

public:
    // Constructor to initialize the concert with a given seating capacity
    Concert(int capacity) {
        this->capacity = capacity;
        this->seated_students = 0;
    }

    // Method to add a student to the queue if there are available seats
    void addStudent(int studentID) {
        if (seated_students < capacity) {
            queue.push(studentID);      // Add student to the queue
            seated_students++;          // Increment the seated student count
            std::cout << "Student " << studentID << " has been seated." << std::endl;
        } else {
            std::cout << "The theater is full! Student " << studentID << " cannot be seated." << std::endl;
        }
    }

    // Method to remove the student at the front of the queue and free up their seat
    void removeStudent() {
        if (seated_students > 0) {
            int removed_student = queue.front(); // Get the student at the front of the queue
            queue.pop();                         // Remove the student from the queue
            seated_students--;                   // Decrease the seated student count
            std::cout << "Student " << removed_student << " has left the theater." << std::endl;
        } else {
            std::cout << "The theater is empty! No students to remove." << std::endl;
        }
    }

    // Method to get the number of remaining seats in the theater
    int getRemainingSeats() {
        return capacity - seated_students;
    }

    // Method to check if the theater is full
    bool isTheaterFull() {
        return seated_students == capacity;
    }
};

// Example usage
int main() {
    Concert concert(5);  // Let's assume the theater has 5 seats

    // Add students
    concert.addStudent(101);
    concert.addStudent(102);
    concert.addStudent(103);
    concert.addStudent(104);
    concert.addStudent(105);
    concert.addStudent(106);  // This should print "The theater is full!"

    // Check remaining seats
    std::cout << "Remaining seats: " << concert.getRemainingSeats() << std::endl;

    // Remove a student and check remaining seats
    concert.removeStudent();
    std::cout << "Remaining seats after removing one student: " << concert.getRemainingSeats() << std::endl;

    // Check if the theater is full
    std::cout << "Is the theater full? " << (concert.isTheaterFull() ? "Yes" : "No") << std::endl;

    // Remove all students
    concert.removeStudent();
    concert.removeStudent();
    concert.removeStudent();
    concert.removeStudent();
    concert.removeStudent();  // This should print "The theater is empty!"

    return 0;
}
