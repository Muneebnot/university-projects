# 🔐 Login & Registration System

## 📖 Problem Statement
A simple **Login & Registration System** that allows users to create accounts, log in securely, and manage their credentials.  
The program ensures **input validation**, **basic authentication**, and **file handling** to store user data.

---

## 🔑 Features

### 📝 Registration:
1. Create a new account with **username & password**.  
2. Store account details securely in a file.

### 🔑 Login:
1. Authenticate users by matching entered credentials with stored data.  
2. Display appropriate messages for **successful**.  

### ⚙ Account Management:
1. Search by name  
2. Delete account.  

---

## 🛠️ Technical Details
- **Language:** C++  
- **Concepts Used:** File handling, arrays, strings, input validation, conditionals.  
- **Type:** Menu-driven program.  

---

## 🧾 Sample Input
- Register new user → `Username: muneeb`, `Password: 12345`  
- Register new user → `Username: ali`, `Password: pass123`  
- Login with → `Username: muneeb`, `Password: 12345`  
- Change password → New password: `muneeb@123`  
- Login again with updated password.  

---

## 🧾 Sample Output

===== Login & Registration System =====

Register

Login

Exist

=======================================

Enter your choice: 1
Enter Username: muneeb
Enter Password: 12345
Registration successful!

Enter your choice: 1
Enter Username: ali
Enter Password: pass123
Registration successful!

Enter your choice: 2
Enter Username: muneeb
Enter Password: 12345
Login successful!

Enter your choice: 2
Enter Username: muneeb
Enter Password: muneeb@123
Login successful! Welcome, muneeb.
