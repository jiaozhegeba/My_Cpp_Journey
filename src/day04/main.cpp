/*
* C++ is an object-oriented programming language.
* Class
*/

#include <iostream>
#include <string>


/*
* data members: variables that hold the state of the object.
* methods: functions that define the behavior of the object.
*** Same name as class: constructor: a special method that is called when an object is created.
*** Same name as class with a tilde (~) prefix without return type: destructor: a special method that is called when an object is destroyed.
*/


class AirlineTicket
{
    public:   // can be accessed from outside the class
        AirlineTicket();
        ~AirlineTicket();
        double calculatePriceInDollars() const;
        const std::string& getPassengerName() const;
        void setPassengerName(const std::string& name);
        int getNumberOfMiles() const;
        void setNumberOfMiles(int miles);
        bool hasEliteSuperRewardsStatus() const;
        void setHasEliteSuperRewardsStatus(bool status);
    private:  // can only be accessed from within the class
        std::string mPassengerName;
        int mNumberOfMiles;
        bool mHasEliteSuperRewardsStatus;
};

// Constructor initializer
// * This is a constructor initializer list, which initializes the data members of the class.
AirlineTicket::AirlineTicket()
    : mPassengerName("Unknown Passenger")
    , mNumberOfMiles(0)
    , mHasEliteSuperRewardsStatus(false)
{
    // Constructor body (optional)
    // If you need to perform additional setup, you can do it here.
    // For example, open a file, allocate resources, etc.
}

/*
* Another way to initialize data members is to use the constructor body.
* AirlineTicket::AirlineTicket()
* {
*     mPassengerName = "Unknown Passenger";
*     mNumberOfMiles = 0;
*     mHasEliteSuperRewardsStatus = false;
* }
*/

// Of course, you can just initialize the data members directly in the class definition as well.
/*
class AirlineTicket
{
    public:
        AirlineTicket();
        ~AirlineTicket();
        double calculatePriceInDollars() const;
        const std::string& getPassengerName() const;
        void setPassengerName(const std::string& name);
        int getNumberOfMiles() const;
        void setNumberOfMiles(int miles);
        bool hasEliteSuperRewardsStatus() const;
        void setHasEliteSuperRewardsStatus(bool status);
    private:
        std::string mPassengerName = "Unknown Passenger";
        int mNumberOfMiles = 0;
        bool mHasEliteSuperRewardsStatus = false;
};
*/

// Destructor
AirlineTicket::~AirlineTicket()
{
    // Destructor does not need to do anything in this case,
    // but if you need to close files, release resources, etc., you can do it here.
}

// Definition of methods
double AirlineTicket::calculatePriceInDollars() const
{
    // Example logic for calculating price based on miles and elite status
    double basePrice = 100.0; // Base price in dollars
    double pricePerMile = 0.1; // Price per mile in dollars
    double totalPrice = basePrice + (mNumberOfMiles * pricePerMile);
    
    if (mHasEliteSuperRewardsStatus) {
        totalPrice *= 0.9; // 10% discount for elite members
    }
    
    return totalPrice;
}
const std::string& AirlineTicket::getPassengerName() const
{
    return mPassengerName;
}
void AirlineTicket::setPassengerName(const std::string& name)
{
    mPassengerName = name;
}
int AirlineTicket::getNumberOfMiles() const
{
    return mNumberOfMiles;
}
void AirlineTicket::setNumberOfMiles(int miles)
{
    mNumberOfMiles = miles;
}
bool AirlineTicket::hasEliteSuperRewardsStatus() const
{
    return mHasEliteSuperRewardsStatus;
}
void AirlineTicket::setHasEliteSuperRewardsStatus(bool status)
{
    mHasEliteSuperRewardsStatus = status;
}



int main ()
{
    AirlineTicket ticket; // Create an instance of AirlineTicket
    ticket.setPassengerName("John Doe");
    ticket.setNumberOfMiles(1500);
    ticket.setHasEliteSuperRewardsStatus(true);

    // Calculate and display the ticket price
    double price = ticket.calculatePriceInDollars();
    std::cout << "Ticket Price for " << ticket.getPassengerName() << ": $" << price << std::endl;

    // Display the number of miles and elite status
    std::cout << "Number of Miles: " << ticket.getNumberOfMiles() << std::endl;
    std::cout << "Elite Super Rewards Status: " << (ticket.hasEliteSuperRewardsStatus() ? "Yes" : "No") << std::endl;
    // The destructor will be called automatically when the object goes out of scope
    // and the resources will be cleaned up.
    

    return 0;
}