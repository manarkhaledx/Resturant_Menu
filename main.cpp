#include <bits/stdc++.h>
using namespace std;
class Menu;
class Meals;
class Sandwiches;
class Drinks_Desserts;
void set_all(Meals m[10], Sandwiches s[10], Drinks_Desserts d[10]);
void pick(Meals m, Sandwiches s, Drinks_Desserts d, Meals me[10], Sandwiches sa[10], Drinks_Desserts dr[10]);
double price();
double tax(double price);
double adding_tax(double price);
void receipt();
void clear();
void intro(Menu client, Meals m, Sandwiches s, Drinks_Desserts d, Meals me[10], Sandwiches sa[10], Drinks_Desserts dr[10]);
class Menu{ //main class
public: //initialization
    double item_price;
    string name_food;
    int orderNO;
    Menu(){} //empty constructor
    Menu(string name, double price, int order){ //parametrized constructor
        name_food=name;
        item_price=price;
        orderNO=order;
    }
    void delivery() { //function delivery to check if the client will take the order here or delivery
        string delivery_user;
        cout << "Do you want to have your meal here or take it away\n "
                "type\"here\" if you want to take it in restaurant \n "
                "or type \"delivery\"\n";
        fstream current_client_data;
        fstream users_data;
        current_client_data.open("current_client_data.txt", ios::out);//we use this file to print the current user date
        users_data.open("users_data.txt",ios::app);//to save all the clients data
        do {
            cin >> delivery_user;
            transform(delivery_user.begin(), delivery_user.end(), delivery_user.begin(), ::tolower);
            if(delivery_user!="here" && delivery_user!="delivery"){
                cout<<"Please Enter a valid option"<<endl;
            }
        }while (delivery_user!="here" && delivery_user!="delivery");
        if (delivery_user == "here") {
            cout << "Please take a seat and wait for your order\n";

        } else if (delivery_user == "delivery") { //take data of client

            cout<<"Please enter your name"<<endl;
            string client_name;
            cin.ignore();//to avoid any problem with the input
            getline(cin,client_name);
            current_client_data << "Name:" << client_name << endl;
            users_data<<"Name:"<<client_name<<endl;
            cout << "Please enter your address" << endl;
            string address;
            getline(cin , address);
            current_client_data << "Address:" << address << endl;
            users_data<<"Address:"<<address<<endl;
            cout << "Please enter your phone number" << endl;
            string phone;
            do {
                cin >> phone;
                if (!(all_of(phone.begin(), phone.end(), ::isdigit)) || phone.length()!=11||phone[0]!='0'||phone[1]!='1'||(phone[2]!='0'&&phone[2]!='1'&& phone[2]!='2'&& phone[2]!='5')){
                    cout<<"please enter a correct phone number"<<endl;
                }
            }while (!(all_of(phone.begin(), phone.end(), ::isdigit)) || phone.length()!=11||phone[0]!='0'||phone[1]!='1'||(phone[2]!='0'&&phone[2]!='1'&& phone[2]!='2'&& phone[2]!='5'));
            current_client_data << "Phone number:" << phone << endl;
            users_data<<"Phone number:"<<phone<<endl;

        }
        current_client_data.close();
        users_data.close();
    }

};

class Meals : public Menu{ //inherited class shows meals menu
public:
    Meals(){} //empty constructor
    Meals(string n , double meal_price , int order_num): Menu(n, meal_price, order_num){} //parametrized constructor
    friend void set_all(Meals m[10], Sandwiches s[10], Drinks_Desserts d[10]);
    void display_meals(){ //to display meals menu
        cout << "======================================================================" << endl;
        cout << "                            Meals Menu                                " << endl;
        cout << "======================================================================" << endl;
        cout << "   1-Fish Fillet combo                                 item_price:$17      " << endl;
        cout << "      (fish fillet sandwich single + regular pepsi + regular fries )  " << endl;
        cout << "                                                                      " << endl;
        cout << "   2-Chicken Fillet combo                              item_price:$14      " << endl;
        cout << "        (chicken fillet sandwich + regular pepsi +regular fries)      " << endl;
        cout << "                                                                      " << endl;
        cout << "   3-chicken nuggets                                   item_price:$8       " << endl;
        cout << "                   (6 Pieces McNuggets + BBQ Sauce )                  " << endl;
        cout << "                                                                      " << endl;
        cout << "   4-cheese burger combo                               item_price:$16      " << endl;
        cout << "                  (cheese burger + regular pepsi + regular fries)     " << endl;
        cout << "                                                                      " << endl;
        cout << "   5-Green salad                                       item_price:$6       " << endl;
        cout << "                                                                      " << endl;
        cout << "   6-Double fish Fillet combo                          item_price:$25      " << endl;
        cout << "        (fish fillet sandwich double + large pepsi + large fries )    " << endl;
        cout << "                                                                      " << endl;
        cout << "   7-Beef burger royal combo                           item_price:$25      " << endl;
        cout << "        (beef & burger royal sandwich + medium pepsi + medium fries ) " << endl;
        cout << "                                                                      " << endl;
        cout << "   8-Twister                                           item_price:$17      " << endl;
        cout << "                   (twister + medium pepsi + medium fries )           " << endl;
        cout << "                                                                      " << endl;
        cout << "   9-Double chicken Fillet combo                       item_price:$14      " << endl;
        cout << "       (double chicken fillet sandwich + large pepsi +large fries)    " << endl;
        cout << "                                                                      " << endl;
        cout << "   10-Double cheese burger combo                       item_price:$19      " << endl;
        cout << "        ( double cheese burger + large pepsi + large fries)           " << endl;
    }

    void pick(Meals m[10]) { //(overloading function)to pick your choice from meals menu
        cout << "Please choose a number of the order you want from the Menu from 1 to 10" << endl;
        int number;
        int quantity;
        fstream receipt;
        fstream price;
        receipt.open("receipt.txt", ios::app);
        price.open("price.txt", ios::app);

        while (!(cin>>number  && number<=10 && number>=1)) { //condition is false when cin is false && number ! smaller
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "please enter a correct pick" << endl;
        }
        cout<<"enter the quantity :\n";
        while (!(cin>>quantity  && quantity>0)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "please enter a valid quantity" << endl;
        }
        if (number == 1 ) {
            receipt << quantity << " * " << m[0].name_food << "\t" << '$' << m[0].item_price << endl;
            price <<quantity*m[0].item_price << endl;
        } else if (number == 2 ) {
            receipt << quantity << " * " << m[1].name_food << "\t" << '$' << m[1].item_price << endl;
            price <<quantity*m[1].item_price << endl;
        } else if (number == 3 ) {
            receipt << quantity << " * " << m[2].name_food << "\t" << '$' << m[2].item_price << endl;
            price <<quantity*m[2].item_price << endl;
        } else if (number == 4 ) {
            receipt << quantity << " * " << m[3].name_food << "\t" << '$' << m[3].item_price << endl;
            price <<quantity*m[3].item_price << endl;
        } else if (number == 5 ) {
            receipt << quantity << " * " << m[4].name_food << "\t" << '$' << m[4].item_price << endl;
            price <<quantity*m[4].item_price << endl;
        } else if (number == 6 ) {
            receipt << quantity << " * " << m[5].name_food << "\t" << '$' << m[5].item_price << endl;
            price <<quantity*m[5].item_price << endl;
        } else if (number == 7 ) {
            receipt << quantity << " * " << m[6].name_food << "\t" << '$' << m[6].item_price << endl;
            price <<quantity*m[6].item_price << endl;
        } else if (number == 8 ) {
            receipt << quantity << " * " << m[7].name_food << "\t" << '$' << m[7].item_price << endl;
            price <<quantity*m[7].item_price << endl;
        } else if (number == 9) {
            receipt << quantity << " * " << m[8].name_food << "\t" << '$' << m[8].item_price << endl;
            price <<quantity*m[8].item_price << endl;
        } else if (number == 10 ) {
            receipt << quantity << " * " << m[9].name_food << "\t" << '$' << m[9].item_price << endl;
            price <<quantity*m[9].item_price << endl;
        }
        receipt.close();
        price.close();
    }
};
class Sandwiches : public Menu { //inherited class shows sandwich menu
public:
    Sandwiches(){}; //empty constructor
    Sandwiches(string n, double p, int o) : Menu(n, p, o) {} //parametrized constructor
    friend void set_all(Meals m[10], Sandwiches s[10], Drinks_Desserts d[10]);
    void display_sandwich() { //to display sandwich menu
        cout << "======================================================================" << endl;
        cout << "                         Sandwiches Menu                                " << endl;
        cout << "======================================================================" << endl;
        cout << "   1-Fish Fillet                                           item_price:$10  " << endl;
        cout << "                  (1-Fish/Milk/Mustard/Soya/Egg)                      " << endl;
        cout << "                                                                      " << endl;
        cout << "   2-Chicken Fillet                                        item_price:$14  " << endl;
        cout << "                 (1-chicken/mustard/mayo/tomatoes/onions)             " << endl;
        cout << "                                                                      " << endl;
        cout << "   3-chicken burger                                        item_price:$8   " << endl;
        cout << "                 (1-chicken/mustard/mayo/tomatoes/onions)             " << endl;
        cout << "                                                                      " << endl;
        cout << "   4-cheese burger                                         item_price:$16  " << endl;
        cout << "                 (1-beef/cheese/tomato/onions/lattice)                " << endl;
        cout << "                                                                      " << endl;
        cout << "   5-beef burger royal                                     item_price:$20  " << endl;
        cout << "                (1-beef/tomato/onions/mustard/mayo)                   " << endl;
        cout << "   6-beef burger                                           item_price:$6   " << endl;
        cout << "                (1-beef/mustard/mayo/tomatoes/onions)                 " << endl;
        cout << "   7-twister                                               item_price:$12  " << endl;
        cout << "                   (chicken/mayo/tortilla/tomato)                     " << endl;
        cout << "   8-Double Fish Fillet                                    item_price:$18  " << endl;
        cout << "                   (2-Fish/Milk/Mustard/Soya/Egg)                     " << endl;
        cout << "   9-Double chicken burger                                 item_price:$15  " << endl;
        cout << "                  (2-chicken/mustard/mayo/tomatoes/onions)            " << endl;
        cout << "   10-Double beef burger                                   item_price:$9   " << endl;
        cout << "                  (2-beef/mustard/mayo/tomatoes/onions)               " << endl;
    }
    void pick(Sandwiches s[10]) { //(overloading function)to pick your choice from sandwich menu
        cout << "Please choose a number of the order you want from the Menu from 1 to 10" << endl;
        int number;
        int quantity;
        fstream receipt;
        fstream price ;
        receipt.open("receipt.txt", ios::app);
        price.open("price.txt", ios::app);
        while (!(cin>>number  && number<=10 && number>=1)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "please enter a correct pick" << endl;
        }
        cout<<"enter the quantity :\n";
        while (!(cin>>quantity  && quantity>0)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "please enter a valid quantity" << endl;
        }
        if (number == 1 ) {
            receipt << quantity << " * " << s[0].name_food << "\t" << '$' << s[0].item_price << endl;//s[n-1]
            price <<quantity*s[0].item_price << endl;
        } else if (number == 2 ) {
            receipt << quantity << " * " << s[1].name_food << "\t" << '$' << s[1].item_price << endl;
            price <<quantity*s[1].item_price << endl;
        } else if (number == 3 ) {
            receipt << quantity << " * " << s[2].name_food << "\t" << '$' << s[2].item_price << endl;
            price <<quantity*s[2].item_price << endl;
        } else if (number == 4 ) {
            receipt << quantity << " * " << s[3].name_food << "\t" << '$' << s[3].item_price << endl;
            price <<quantity*s[3].item_price << endl;
        } else if (number == 5 ) {
            receipt << quantity << " * " << s[4].name_food << "\t" << '$' << s[4].item_price << endl;
            price <<quantity*s[4].item_price << endl;
        } else if (number == 6 ) {
            receipt << quantity << " * " << s[5].name_food << "\t" << '$' << s[5].item_price << endl;
            price <<quantity*s[5].item_price << endl;
        } else if (number == 7 ) {
            receipt << quantity << " * " << s[6].name_food << "\t" << '$' << s[6].item_price << endl;
            price <<quantity*s[6].item_price << endl;
        } else if (number == 8 ) {
            receipt << quantity << " * " << s[7].name_food << "\t" << '$' << s[7].item_price << endl;
            price <<quantity*s[7].item_price << endl;
        } else if (number == 9 ) {
            receipt << quantity << " * " << s[8].name_food << "\t" << '$' << s[8].item_price << endl;
            price <<quantity*s[8].item_price << endl;
        } else if (number == 10 ) {
            receipt << quantity << " * " << s[9].name_food << "\t" << '$' << s[9].item_price << endl;
            price <<quantity*s[9].item_price << endl;
        } receipt.close();
        price.close();
    }
};

class Drinks_Desserts : public Menu { //inherited class shows drinks and desserts menu
public:
    Drinks_Desserts(){}; //empty constructor
    Drinks_Desserts(string n, double p, int o) : Menu(n, p, o) {} //parametrized constructor
    friend void set_all(Meals m[10], Sandwiches s[10], Drinks_Desserts d[10]);
    void display_drinks_desserts() { //to display drinks and desserts menu
        cout << "=======================================================================" << endl;
        cout << "                    Drinks & Desserts Menu                             " << endl;
        cout << "=======================================================================" << endl;
        cout << "            Drinks               |            Desserts                 " << endl;
        cout << " 1- Coca-cola                    | 6- Chocolate sundae                 " << endl;
        cout << "            (price:$3)           |              (item_price:$4)             " << endl;
        cout << " 2- Sprite                       | 7- Caramel sundae                   " << endl;
        cout << "            (price:$3)           |              (item_price:$4)             " << endl;
        cout << " 3- Chocolate Milkshake          | 8- Oreo Mcflurry                    " << endl;
        cout << "            (price:$5)           |              (item_price:$5)             " << endl;
        cout << " 4- Strawberry Milkshake         | 9- Apple pie                        " << endl;
        cout << "            (price:$5)           |              (price:$2)             " << endl;
        cout << " 5- Orange Juice                 | 10- Chocolate muffin                " << endl;
        cout << "            (price:$3)           |              (item_price:$5)             " << endl;
    }
    void pick(Drinks_Desserts d[10]) { //(overloading function)to pick your choice from drinks and desserts menu
        cout << "Please choose a number of the order you want from the Menu from 1 to 10" << endl;
        int number;
        int quantity;
        fstream receipt;
        fstream price;
        receipt.open("receipt.txt", ios::app);
        price.open("price.txt", ios::app);
        while (!(cin>>number  && number<=10 && number>=1)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "please enter a correct pick" << endl;
        }
        cout<<"enter the quantity :\n";
        while (!(cin>>quantity  && quantity>0)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "please enter a valid quantity" << endl;
        }
        if (number == 1 ) {
            receipt << quantity << " * " << d[0].name_food << "\t" << '$' << d[0].item_price << endl;
            price <<quantity*d[0].item_price << endl;
        } else if (number == 2 ) {
            receipt << quantity << " * " << d[1].name_food << "\t" << '$' << d[1].item_price << endl;
            price <<quantity*d[1].item_price << endl;
        } else if (number == 3 ) {
            receipt << quantity << " * " << d[2].name_food << "\t" << '$' << d[2].item_price << endl;
            price <<quantity*d[2].item_price << endl;
        } else if (number == 4 ) {
            receipt << quantity << " * " << d[3].name_food << "\t" << '$' << d[3].item_price << endl;
            price <<quantity*d[3].item_price << endl;
        } else if (number == 5 ) {
            receipt << quantity << " * " << d[4].name_food << "\t" << '$' << d[4].item_price << endl;
            price <<quantity*d[4].item_price << endl;
        } else if (number == 6 ) {
            receipt << quantity << " * " << d[5].name_food << "\t" << '$' << d[5].item_price << endl;
            price <<quantity*d[5].item_price << endl;
        } else if (number == 7 ) {
            receipt << quantity << " * " << d[6].name_food << "\t" << '$' << d[6].item_price << endl;
            price <<quantity*d[6].item_price << endl;
        } else if (number == 8 ) {
            receipt << quantity << " * " << d[7].name_food << "\t" << '$' << d[7].item_price << endl;
            price <<quantity*d[7].item_price << endl;
        } else if (number == 9 ) {
            receipt << quantity << " * " << d[8].name_food << "\t" << '$' << d[8].item_price << endl;
            price <<quantity*d[8].item_price << endl;
        } else if (number == 10 ) {
            receipt << quantity << " * " << d[9].name_food << "\t" << '$' << d[9].item_price << endl;
            price <<quantity*d[9].item_price << endl;
        } receipt.close();
        price.close();
    }
};
void set_all(Meals m[10], Sandwiches s[10], Drinks_Desserts d[10]) {//(array of object)to set all the data of the objects and send them to all classes
    m[0] = Meals("Fish Fillet combo", 17, 1);
    m[1] = Meals("Chicken Fillet combo", 14, 2);
    m[2] = Meals("chicken nuggets", 8, 3);
    m[3] = Meals("cheese burger combo", 16, 4);
    m[4] = Meals("Green salad", 6, 5);
    m[5] = Meals("double fish fillet combo", 25, 6);
    m[6] = Meals("beef burger royal", 25, 7);
    m[7] = Meals("Twister", 17, 8);
    m[8] = Meals("Double chicken Fillet combo", 14, 9);
    m[9] = Meals("Double cheese burger combo", 19, 10);
    s[0] = Sandwiches("Fish Fillet", 10, 1);
    s[1] = Sandwiches("Chicken Fillet", 14, 2);
    s[2] = Sandwiches("chicken burger", 8, 3);
    s[3] = Sandwiches("cheese burger", 16, 4);
    s[4] = Sandwiches("beef burger royal", 20, 5);
    s[5] = Sandwiches("beef burger", 6, 6);
    s[6] = Sandwiches("twister", 12, 7);
    s[7] = Sandwiches("Double Fish Fillet", 18, 8);
    s[8] = Sandwiches("Double chicken burger", 15, 9);
    s[9] = Sandwiches("Double beef burger", 9, 10);
    d[0] = Drinks_Desserts("Coca-cola", 3, 1);
    d[1] = Drinks_Desserts("Sprite", 3, 2);
    d[2] = Drinks_Desserts("Chocolate milkshake", 5,3);
    d[3] = Drinks_Desserts("Strawberry milkshake", 5, 4);
    d[4] = Drinks_Desserts("Orange juice", 3, 5);
    d[5] = Drinks_Desserts("Chocolate sundae", 4, 6);
    d[6] = Drinks_Desserts("Strawberry sundae", 4, 7);
    d[7] = Drinks_Desserts("Oreo Mcflurry", 5, 8);
    d[8] = Drinks_Desserts("Apple pie", 2, 9);
    d[9] = Drinks_Desserts("Chocolate muffin", 5, 10);
}
void pick(Meals m, Sandwiches s, Drinks_Desserts d, Meals me[10], Sandwiches sa[10], Drinks_Desserts dr[10]) { //main pick function to choose your order
    cout << "welcome to Our Restaurant Please choose from Menu what do you want to order:" << endl;
    int pick;
    set_all(me,sa,dr);
    string add;
    do {
        cout << "==============================" << endl;
        cout << "            MENU              " << endl;
        cout << "==============================" << endl;
        cout << "|        1-Sandwiches        |" << endl;
        cout << "|         2-Meals            |" << endl;
        cout << "|     3-Drinks & Desserts    |" << endl;


        do {
            while (!(cin>>pick && pick<=3 && pick>=1 )){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"please enter a correct pick number"<<endl;
            }
        }while (pick!=1 && pick!=2 && pick!=3);

        if (pick == 1) {
            s.display_sandwich(); // display sandwich menu
            s.pick(sa); //PICK [array of obj]
            system("clear");
        } else if (pick == 2) {
            m.display_meals(); //display meals menu
            m.pick(me); //pick
            system("clear");
        } else if (pick == 3) {
            d.display_drinks_desserts(); //display drinks and desserts menu
            d.pick(dr); //pick
            system("clear");
        }
        cout<<"-------------------------------------------------------------------------------"<<endl;
        cout<<   "if you want to add something else please enter yes or enter no to exit      "<< endl;
        cout<<"-------------------------------------------------------------------------------"<<endl;
        do {
            cin >> add;
            transform(add.begin(),add.end(),add.begin(),::tolower);
            if(add!="yes" && add!="no" ){
                cout<<"please enter a valid option"<<endl;
            }
        }while (add!="yes" && add!="no");
    } while (add == "yes");
}
double price(){
    fstream price; //file to include prices in
    double total=0;
    price.open("price.txt",ios::in); //open file
    double n;
    while (price>>n){ //read from file all the data and add it to total
        total=total+n;
    }
    return total;
}

double tax(double price){//take a data type of type double
    double tax=price*0.14; //calculate tax
    return  tax;
}
double adding_tax(double price ){//take a data type of type double
    double after_tax=price+(price*0.14); //calculate total price=price+tax
    return  after_tax;
}
void receipt(){
    fstream receipt;
    fstream current_client_data;
    receipt.open("receipt.txt",ios::in);
    current_client_data.open("current_client_data.txt", ios::in);
    string s;
    cout<<"=========================================================\n";
    cout<<"\t\t\t\e[1mRECEIPT\e[0m"<<endl;
    cout<<"=========================================================\n";
    auto givemetime = chrono::system_clock::to_time_t(chrono::system_clock::now());
    cout <<"The date and time :"<< ctime(&givemetime) ; //to display current date and time
    cout<<"=========================================================\n";
    cout<<"\tyour order is : \n";
    while (getline(receipt,s)){
        cout<<"\t"<<s<<endl; //display all data in receipt file
    }
    receipt.close();
    cout<<"=========================================================\n";
    cout<<"\tyour order price is: $"<<price()<<endl ; //(display price)
    cout<<"\tthe tax amount is : $"<<tax(price())<<endl;//(display tax) take a double from the function double
    cout<<"\ttotal price after adding 14% tax is: $"<<adding_tax(price())<<endl;//(display total price) take a double from the function double
    cout<<"=========================================================\n";
    while (getline(current_client_data, s)){
        cout<<"\t"<<s<<endl; //display current client data if he choose delivery
    }
    current_client_data.close();
}
void clear(){ //to clear data from files
    fstream receipt;
    receipt.open("receipt.txt",ios::out|ios::trunc);//out ==> to edit on the file //trunc ==> to delete the data
    receipt.close();
    fstream price;
    price.open("price.txt",ios::out|ios::trunc);
    price.close();
    fstream current_client_data;
    current_client_data.open("current_client_data.txt", ios::out | ios::trunc);
    current_client_data.close();
}
void intro(Menu client, Meals m, Sandwiches s, Drinks_Desserts d, Meals me[10], Sandwiches sa[10], Drinks_Desserts dr[10]){

    do {
        cout << "=======================================" <<endl;
        cout << "       Welcome to our restaurant       " << endl;
        cout << "=======================================" <<endl;
        cout << "           1-Display Meals             " << endl;
        cout << "         2-Display Sandwiches          " << endl;
        cout << "     3-Display Drinks and Desserts     " << endl;
        cout << "      4-Order from our restaurant      " << endl;
        cout << "Enter your choice : " << endl;

        int choice;
        while (!(cin>>choice  && choice<=4 && choice>=1)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "please enter a correct pick" << endl;
        }
        system("clear");
        switch (choice) {
            case 1:
                m.display_meals();  //display meals menu
                break;
            case 2:
                s.display_sandwich(); //display sandwich menu
                break;
            case 3:
                d.display_drinks_desserts(); //display Drinks and Desserts menu
                break;
            case 4: //to take the client order
                client.delivery(); //delivery function
                pick(m, s, d, me, sa, dr); //pick order
                system("clear");
                receipt(); //display receipt
                clear();
                break;
        }
        string add;
        cout << "\n\n\nenter yes to back to the main Menu or no to exit\n";
        do {
            cin >> add;
            transform(add.begin(),add.end(),add.begin(),::tolower) ;
            if (add!="yes" && add!="no"){cout<<"enter a valid option"<<endl;}
        }while (add!="yes" && add!="no");
        if ( add == "yes")
        {
            system("clear");
            continue;
        }
        else if (add == "no") {
            break;
        }

    } while (true);
}

int main() {
    Menu client;
    Meals m;
    Sandwiches s;
    Drinks_Desserts d;
    Meals me[10];
    Sandwiches sa[10];
    Drinks_Desserts dr[10];
    intro( client,m, s,d,me,sa,dr);
}