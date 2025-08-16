# 🚚 Vehicle Fleet Management and Trip Scheduling System

## 📌 Project Summary
This project is a **C++ based Vehicle Fleet Management and Trip Scheduling System** designed for logistics companies that operate large fleets of transport vehicles for goods delivery across Pakistan.  

The system manages vehicle records, schedules delivery trips, tracks vehicle availability with a **2D calendar**, calculates fuel expenses, and maintains logs of all trips. It uses **file handling** for permanent storage, **pointers** for modifying data, and a **menu-driven interface** for smooth navigation.

---

## 🔑 Features

### 🚛 Vehicle Records Management
- Add new vehicles (Vehicle ID, Type, Capacity, Driver, Availability).  
- Update or mark vehicles as available/unavailable.  
- Prevent duplicate Vehicle IDs.  
- Permanent storage in `vehicles.txt`.

### 📅 Trip Scheduling & Availability Matrix
- 2D array (Vehicles × Days of Month) to track availability.  
- Prevents double booking of vehicles.  
- Schedule trips only if the vehicle is free on the requested date.  
- Save availability status in `calendar.txt`.

### 🛣️ Trip Records & Billing
- Each trip includes Trip ID, Vehicle ID, Source, Destination, Distance, Date, and Fuel Consumption.  
- Calculates fuel cost:  
  Fuel Cost = Liters × Rs. 275

  - Saves trip details to `trips.txt`.  
- View past trip history by Vehicle ID or Trip ID.

---

## 🛠️ Technical Details
- **Language:** C++  
- **Concepts Used:**  
- Functions (modular design)  
- Arrays & 2D arrays (availability tracking)  
- File handling (vehicles, trips, calendar storage)  
- Pointers (dynamic modification of records)  
- Input validation (unique IDs, valid dates, positive values)  
- **Program Type:** Menu-driven application  

---

## 📂 File Structure
- `vehicles.txt` → Stores all vehicle records.  
- `trips.txt` → Stores all trip details.  
- `calendar.txt` → Stores vehicle availability matrix.  

---

## 📋 Program Flow
1. **Main Menu** (Admin interface).  
2. Options:  
 - Add Vehicle  
 - Schedule Trip  
 - View Fleet Status (2D Matrix)  
 - View Trip History  
 - Exit  
3. Validations:  
 - Vehicle ID & Trip ID must be unique and alphanumeric.  
 - Date must be between 1–30.  
 - Fuel & Distance must be positive.  
 - No double booking allowed.  

---

## 📥 Sample Input

**Add New Vehicle**
Vehicle ID: V245
Type: Truck
Capacity: 8 Tons
Driver: Saeed Khan


**Schedule Trip**

Trip ID: T102
Vehicle ID: V245
From: Lahore
To: Islamabad
Distance: 370 KM
Fuel Used: 80 Liters
Date: 15


---

## 📤 Sample Output
Vehicle V245 added successfully.
Vehicle V245 available on Day 15.
Trip T102 scheduled from Lahore to Islamabad.
Fuel Cost = 80 x Rs.275 = Rs. 22000
Trip details saved to file.
