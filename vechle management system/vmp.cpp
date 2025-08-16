#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;


const int max_vechiles = 100;
const int max_days = 30;
const int fuel_rate = 275;


char vehicleids[max_vechiles][20];
char vehicletypes[max_vechiles][20];
int capacities[max_vechiles];
char drivernames[max_vechiles][50];
int availability[max_vechiles];
char schedule[max_vechiles][max_days]; 
int vehicleCount = 0; 


int findvehicleindex(char* id)
{
    for (int i = 0; i < vehicleCount; i++)
    {
        if (strcmp(vehicleids[i], id) == 0)
        {
            return i;
        }
    }
    return -1;
}


bool isvehicleidunique(char* id)
{
    for (int i = 0; i < vehicleCount; i++) 
    {
        if (strcmp(vehicleids[i], id) == 0)
            return false; 
    }
    return true; 
}


bool isvehiclefreeOnDay(int index, int day)
{
    if (schedule[index][day - 1] == 'N') 
    {
        return true; 
    }
    else
    {
        return false; 
    }

}


void markvehiclebooked(int index, int day)
{
    schedule[index][day - 1] = 'Y';
}


float calculateFuelCost(float liters)
{
    return liters * fuel_rate;
}

void writevehicletoFile(int index) 
{
    ofstream fout("vehicles.txt", ios::app);
    fout << vehicleids[index] << " " << vehicletypes[index] << " "
        << capacities[index] << " " << drivernames[index] << " "
        << availability[index] << "\n";
    fout.close();
}


void savetrip(char* tripID, char* vehicleID, char* from, char* to, int km, float fuel, int date)
{
    ofstream fout("trips.txt", ios::app);
    fout << tripID << " " << vehicleID << " " << from << " " << to << " "
        << km << " " << fuel << " " << date << "\n";
    fout.close();
}


void loadVehicles()
{
    ifstream fin("vehicles.txt");
    if (!fin) 
    {
        return;
    }

    while (fin >> vehicleids[vehicleCount] >> vehicletypes[vehicleCount]>> capacities[vehicleCount] >> drivernames[vehicleCount]>> availability[vehicleCount]) 
    {
        vehicleCount++;
    }
    fin.close();
}


void addvehicle()
{
    if (vehicleCount >= max_vechiles)
    {
        cout << "fleet full.\n";
        return;
    }

    char id[20], type[20], driver[50];
    int cap;

    cout << "enter vehicle iD: ";
    cin >> id;

    if (!isvehicleidunique(id)) 
    {
        cout << "vehicle id already exists.\n";
        return;
    }

    cout << "enter type: ";
    cin >> type;

    cout << "Enter capacity: ";
    cin >> cap;

    cout << "enter driver: ";
    cin.ignore();
    cin.getline(driver, 50);

    strcpy_s(vehicleids[vehicleCount], id);
    strcpy_s(vehicletypes[vehicleCount], type);
    capacities[vehicleCount] = cap;
    strcpy_s(drivernames[vehicleCount], driver);
    availability[vehicleCount] = 1;

    writevehicletoFile(vehicleCount);
    vehicleCount++;

    cout << "vehicle added successfully!\n";
}

void viewfleetstatus() 
{
    cout << "\nVehicleID\tType\tCapacity\tDriver\t\tAvailable\n";
    for (int i = 0; i < vehicleCount; i++) 
    {
        cout << vehicleids[i] << "\t" << vehicletypes[i] << "\t"
            << capacities[i] << "\t" << drivernames[i] << "\t";

        if (availability[i] == 1)
        {
            cout << "Yes" << "\n";
        }
        else
        {
            cout << "No" << "\n";
        }
    }

    cout << "\n--- Availability Matrix (Y=Trip, N=Free) ---\n";
    cout << "Day: ";
    for (int d = 1; d <= max_days; d++) cout << d << " ";
    cout << "\n";

    for (int i = 0; i < vehicleCount; i++)
    {
        cout << vehicleids[i] << ": ";
        for (int d = 0; d < max_days; d++)
        {
            cout << schedule[i][d] << " ";
        }
        cout << "\n";
    }
}


void scheduletrip()
{
    char tripID[20], vID[20], from[30], to[30];
    int distance, date;
    float fuel;

    cout << "enter trip id: ";
    cin >> tripID;

    cout << "Enter vechile id: ";
    cin >> vID;

    int vIndex = findvehicleindex(vID);
    if (vIndex == -1) 
    {
        cout << "Vehicle not found.\n";
        return;
    }

    cout << "enter source city: ";
    cin >> from;
    cout << "enter destination city: ";
    cin >> to;
    cout << "enter distance: ";
    cin >> distance;
    cout << "enter fuel used: ";
    cin >> fuel;
    cout << "enter trip date: ";
    cin >> date;

    if (date < 1 || date > 30 || distance <= 0 || fuel <= 0) 
    {
        cout << "Invalid trip details.\n";
        return;
    }

    if (!isvehiclefreeOnDay(vIndex, date))
    {
        cout << "vehicle already booked on this day.\n";
        return;
    }

    markvehiclebooked(vIndex, date);

    float cost = calculateFuelCost(fuel);
    cout << "Trip scheduled!\n";
    cout << "Fuel Cost = " << cost << "\n";

    savetrip(tripID, vID, from, to, distance, fuel, date);
}

void viewtriphistory() 
{
    ifstream fin("trips.txt");
    if (!fin)
    {
        cout << "No trip history found.\n";
        return;
    }

    char tripID[20], vID[20], from[30], to[30];
    int km, date;
    float fuel;

    cout << "\n--- Trip History ---\n";
    while (fin >> tripID >> vID >> from >> to >> km >> fuel >> date) {
        cout << "Trip ID: " << tripID << ", Vehicle: " << vID << "\n";
        cout << "From " << from << " to " << to << ", Distance: " << km
            << "km, Fuel: " << fuel << "L, Date: " << date << "\n";
        cout << "Fuel Cost: Rs. " << calculateFuelCost(fuel) << "\n\n";
    }
    fin.close();
}

int main()
{
    loadVehicles();

    
    for (int i = 0; i < max_vechiles; i++) {
        for (int j = 0; j < max_days; j++) {
            schedule[i][j] = 'N';
        }
    }

    int choice;
    do 
    {
        
        cout << "1. add new vehicle\n";
        cout << "2. schedule trip\n";
        cout << "3. view fleet status\n";
        cout << "4. view trip history\n";
        cout << "5. exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
        {
            addvehicle(); 
            break; 
        }
        case 2:
        {
            scheduletrip();
            break;
        }
        case 3:
        {
            viewfleetstatus();
            break; 
        }
        case 4:
        { 
            viewtriphistory();
            break; 
        }
        case 5:
        { 
            cout << "Exiting...\n"; 
            break;
        }
        default:
        {
            cout << "Invalid option. Try again.\n";
            break;
        }
        }
    } while (choice != 5);

   
}
