#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char username[10];
    char password[10];
    int age;
    char mobilePhone[12];
    union {
        int active;   
        bool isActive;   
    };
} User;

User users[10];
int numUsers = 0;

void registerUser(const char* username, const char* password, int age, const char* mobilePhone, int active) {
    if (numUsers < 10) {
        strcpy(users[numUsers].username, username);
        strcpy(users[numUsers].password, password);
        users[numUsers].age = age;
        strcpy(users[numUsers].mobilePhone, mobilePhone);
        users[numUsers].active = active;
        numUsers++;
        printf("User registered successfully!\n");
    }
}

int loginUser(const char* username, const char* password) {
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 &&
            strcmp(users[i].password, password) == 0) {
            if (users[i].isActive) {
                return i;
            } else {
                return -2;   
            }
        }
    }
    return -1;   
}

void printUser(User user) {
    printf("Username: %s\n", user.username);
    printf("Age: %d\n", user.age);
    printf("Mobile Phone: %s\n", user.mobilePhone);
    printf("Active: %s\n", user.isActive ? "Yes" : "No");
}

int main() {
    char username[10];
    char password[10];
    int age;
    char mobilePhone[12];
    int active;

    printf("Registration\n");
    printf("Enter a username: ");
    scanf("%s", username);
    printf("Enter a password: ");
    scanf("%s", password);
    printf("Enter your age: ");
    scanf(" %d", &age);   
    printf("Enter your mobile phone number: ");
    scanf("%s", mobilePhone);
    printf("Enter 1 for active or 0 for inactive: ");
    scanf("%d", &active);
    registerUser(username, password, age, mobilePhone, active);

    printf("\nLogin\n");
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);
    int logged = loginUser(username, password);
    if (logged >= 0) {
        printf("Login successful!\n");
        printUser(users[logged]);
    } else if (logged == -2) {
        printf("User is inactive.\n");
    } else {
        printf("Invalid username or password!\n");
    }

    return 0;
}