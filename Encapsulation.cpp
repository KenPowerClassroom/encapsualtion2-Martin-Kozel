#include <iostream>
#include <string>

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        balance -= amount;
    }

    void withdraw2(BankAccount account) {
        if (account.getBalance() > 500) {
            account.withdraw(500);
            std::cout << "Withdrawal successful. New balance: $" << account.getBalance() << std::endl;
        }
        else {
            std::cout << "Insufficient funds for withdrawal." << std::endl;
        }
    }
};  

class Boiler {
public:
    void turnOn() {
        std::cout << "Boiler turned on." << std::endl;
    }

    void turnOff() {
        std::cout << "Boiler turned off." << std::endl;
    }

};

class Thermostat {
private:
    double currentTemperature;

public:
    Thermostat(double temperature) : currentTemperature(temperature) {}

    double getCurrentTemperature() const {
        return currentTemperature;
    }

    void boilerOnOff(Thermostat thermostat, Boiler boiler) {
        if (thermostat.getCurrentTemperature() < 20.0) {
            boiler.turnOn();
        }
        else {
            boiler.turnOff();
        }
    }
};


class Library {
private:
    std::string title;
    bool bookIsAvailable;

public:
    Library(const std::string& title) : title(title), bookIsAvailable(true) {}

    bool checkAvailability() const {
        return bookIsAvailable;
    }

    void borrowBook() {
        bookIsAvailable = false;
    }

    void returnBook() {
        bookIsAvailable = true;
    }

    void processBookBorrowing(Library& library) {
        if (library.checkAvailability()) {
            library.borrowBook();
            std::cout << "Book borrowed successfully." << std::endl;
        }
        else {
            std::cout << "Book is not available for borrowing." << std::endl;
        }
    }
};

class Player {
private:
    int health;
    int ammo;

public:
    Player() : health(100), ammo(10) {}

    int getHealth() const {
        return health;
    }

    int getAmmo() const {
        return ammo;
    }

    void takeDamage(int damage) {
        health -= damage;
    }

    void useAmmo() {
        ammo--;
    }
};

class Game {
public:
    void enemyAttack(Player& player) {
        if (player.getHealth() > 0 && player.getAmmo() > 0) {
            player.takeDamage(10);
            player.useAmmo();
            std::cout << "Player attacked and used ammo." << std::endl;
        }
        else {
            std::cout << "Player can't respond to attack." << std::endl;
        }
    }
};


int main() {
    //////////////////////////////////////////////////////////////////
    // Exercise 1
    //////////////////////////////////////////////////////////////////
 
    BankAccount account(1000.0);
    account.withdraw2(account);
   
    //////////////////////////////////////////////////////////////////
    // Exercise 2
    //////////////////////////////////////////////////////////////////

    Thermostat thermostat(18.5);
    Boiler boiler;
    thermostat.boilerOnOff(thermostat, boiler);
    
    //////////////////////////////////////////////////////////////////
    // Exercise 3
    //////////////////////////////////////////////////////////////////

    Library myBook("1984");
    myBook.processBookBorrowing(myBook);  // First borrow should succeed
    myBook.processBookBorrowing(myBook);  // Second attempt should show not available

    //////////////////////////////////////////////////////////////////
    // Exercise 4
    //////////////////////////////////////////////////////////////////
    Player player;
    Game game;

    game.enemyAttack(player); // Player can respond to attack

    return 0;
}
