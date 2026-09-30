#include <iostream>
#include <string>
#include <vector>
#include <fstream>


/*
====DONE====
1.Save contacts to the file
2.Load contacts from the file
3.Show the menu

====TODO====
1. Add contacts
2. Remove contacts
3. Edit contact
4. Find contact by name, phone, email
5. Find contact by part of the name
============

*/



/*

    Global class for all contact numbers

*/
class Contact{
    public:
    std::string number = "";
    std::string name = "";
    std::string email = "";
};


/*

Function skeletons

*/
void show_menu(std::vector<Contact>& contacts);
void delete_contact(std::vector<Contact>& delete_contact);
void save_contact(std::vector<Contact>& save_contact);
void load_contact(std::vector<Contact>& load_contact);
void show_contact(std::vector<Contact>& show_contact);
void create_contact(std::vector<Contact>& create_contact);
void edit_contact(std::vector<Contact>& edit_contact);
void find_contact(std::vector<Contact>& find_contact);



/*

    Main function to load contacts and show the menu

*/
int main(){
    std::vector<Contact> contacts;

    load_contact(contacts);

    show_menu(contacts);

    return 0;
}


/*

    Function to load contacts from the file contacts.txt

*/
void load_contact(std::vector<Contact>& load_contact){
    Contact contact;
    std::ifstream fin;
    std::string name ="";
    std::string email ="";
    std::string number="";
    
    fin.open("contact.txt");
    while (std::getline(fin, name)) {
        if (name.empty()) {
            continue;
        }
        std::getline(fin, email);
        if (email.empty()){
            continue;
        }
        std::getline(fin, number);
        if (number.empty()){
            continue;
        }
        contact.name = name;
        contact.email = email;
        contact.number = number;
        load_contact.push_back(contact);
    }
    fin.close();
}

/*

    Function to save contacts to the file

*/
void save_contact(std::vector<Contact>& save_contact){
    Contact contact;
    std::ofstream fout;

    fout.open("contacts.txt");
    for (const auto& contact : save_contact) {
        fout << contact.name<< "\n";
        fout << contact.email << "\n";
        fout << contact.number << "\n";
    }
}

/*

    Function to remove contacts from the list

*/
void delete_contact(std::vector<Contact>& delete_contact){
    int choise = 0;
    std::cout << "Please enter contact you want to delete: ";
    std::cin >> choise;
    delete_contact.erase(delete_contact.begin() + (choise - 1));
    save_contact(delete_contact);
}

/*

    Function to create new contact

*/
void create_contact(std::vector<Contact>& create_contact){

}

/*

    Function to edit the contacts

*/
void edit_contact(std::vector<Contact>& edit_contact){

}

/*

    Function to fin the contact by name, phone, email

*/
void find_contact(std::vector<Contact>& find_contact){

}

/*

    Function to show the list of contacts


*/
void show_contact(std::vector<Contact>& show_contact){
    Contact contact;
    int counter = 0;
    char choise = '';

    for(const auto& contact : show_contact){
        ++counter;
        std::cout << counter << ". " << contact.name << "\t" << contact.number << "\t" << contact.email << "\n"; 
    }

    std::cout << "Press any button ENTER to continue";
    std::cin >> choise;
}

/*

    Function to show the menu of contact list

*/
void show_menu(std::vector<Contact>& contacts){
    int choise = 0;

    while (true) {
        std::cout << "=========CONTACT BOOK=========\n";
        std::cout << "1. Create new contact\n"
                  << "2. Show all the contacts\n"
                  << "3. Remove contact\n"
                  << "4. Find contact by name, phone, mail\n"
                  << "5. Edit contact\n"
                  << "6. Save and Quit\n";
        std::cout << "============================\n";

        std::cout << "Select what you want to do: ";
        if (!(std::cin >> choise)) {
            std::cout << "Wrong input!\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        if (choise == 1) {
            create_contact(contacts);
        } 
        
        else if (choise == 2) {
            show_contact(contacts);
        } 
        
        else if (choise == 3) {
            delete_contact(contacts);
        } 

        else if(choise == 4){
            find_contact(contacts);
        }
        
        else if(choise == 5){
            edit_contact(contacts);
        }
        else if (choise == 6) {
            save_contact(contacts);
            break;
        }
        else{
            std::cout<<"Wrong input\n";
        }
    }
}