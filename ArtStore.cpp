#include <iostream>
#include <string>
using namespace std;

class Artwork {
    public:
        string name;
        string artist;
        float price;
        void getDetails() {
            cout << "Enter name of artwork: ";
            cin >> name;
            cout << "Enter name of artist: ";
            cin >> artist;
            cout << "Enter price of artwork: ";
            cin >> price;
        }
        void displayDetails() {
            cout << "\nName of artwork: " << name;
            cout << "\nName of artist: " << artist;
            cout << "\nPrice of artwork: Rs. " << price;
        }
};

class User {
    protected:
        string username;
        string password;
    public:
        void login() {
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
        }
};

class Admin : public User {
    public:
        void addItem(Artwork artworks[], int& count) {
            artworks[count].getDetails();
            count++;
            cout << "\nArtwork added successfully!\n";
        }
        void viewItems(Artwork artworks[], int count) {
            if (count == 0) {
                cout << "\nNo artworks available!\n";
            }
            else {
                cout << "\nList of artworks:\n";
                for (int i = 0; i < count; i++) {
                    artworks[i].displayDetails();
                    cout << "\n";
                }
            }
        }
        void login() {
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            if (username != "admin" || password != "pass123") {
                cout << "Invalid username or password\n";
                exit(1);
            }
            cout << "Logged in successfully as an admin!\n";
        }

};

class Customer : public User {
    public:
        void buyItem(Artwork artworks[], int count) {
            if (count == 0) {
                cout << "\nNo artworks available!\n";
            }
            else {
                int choice;
                cout << "\nEnter the index of artwork you want to buy: ";
                cin >> choice;
                choice -= 1;
                if (choice < 0 || choice >= count) {
                    cout << "\nInvalid index!\n";
                }
                else {
                    buyArtwork(artworks[choice]); // call the new buyArtwork function
                }
            }
        }
        void login() {
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            if (username != "user" || password != "pass123") {
                cout << "Invalid username or password\n";
                exit(1);
            }
            cout << "Logged in successfully as a customer!\n";
        }
        void buyArtwork(Artwork artwork) {
            int quantity;
            cout << "\nEnter the quantity you want to buy: ";
            cin >> quantity;
            if (quantity <= 0) {
                cout << "\nInvalid quantity!\n";
            }
            else {
                float total = artwork.price * quantity;
                cout << "\nYou bought the following artwork(s):\n";
                artwork.displayDetails();
                cout << "\nQuantity: " << quantity;
                cout << "\nTotal amount: Rs. " << total;
                cout << "\nThank you for your purchase!\n";
            }
        }
};

int main() {
    int MAX_ITEMS = 10;
    Artwork artworks[MAX_ITEMS];
    int count = 0;
    int choice;
    Admin admin;
    Customer customer;

    do {
        cout << "\nMenu\n";
        cout << "1. Admin\n";
        cout << "2. Customer\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int adminChoice;
                cout << "\nAdmin Menu\n";
                cout << "1. Add artwork\n";
                cout << "2. View artworks\n";
                cout << "3. Back\n";
                cout << "Enter your choice: ";
                cin >> adminChoice;

                switch (adminChoice) {
                    case 1:
                        if (count == MAX_ITEMS) {
                            cout << "\nNo more artworks can be added!\n";
                        }
                        else {
                            admin.login(); // login as an admin
                            admin.addItem(artworks, count);
                        }
                        break;
                    case 2:
                        admin.viewItems(artworks, count);
                        break;
                    case 3:
                        break;
                    default:
                        cout << "\nInvalid choice!\n";
                }
                break;
            case 2:
                int customerChoice;
                cout << "\nCustomer Menu\n";
                cout << "1. View    Artworks\n";
                cout << "2. Buy artwork\n";
                cout << "3. Back\n";
                cout << "Enter your choice: ";
                cin >> customerChoice;
                            switch (customerChoice) {
                case 1:
                    customer.login(); // login as a customer
                    admin.viewItems(artworks, count);
                    break;
                case 2:
                    customer.login(); // login as a customer
                    customer.buyItem(artworks, count);
                    break;
                case 3:
                    break;
                default:
                    cout << "\nInvalid choice!\n";
            }
            break;
        case 3:
            cout << "\nGoodbye!\n";
            break;
        default:
            cout << "\nInvalid choice!\n";
    }
} while (choice != 3);

   return 0;
}
