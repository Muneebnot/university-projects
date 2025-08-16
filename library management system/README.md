# 📚 Library Management System

## 📖 Problem Statement
A comprehensive **Library Management System** for managing both physical and e-books.  
The system allows managers to handle library records and customers to browse and borrow/purchase books.

---

## 🔑 Features

### 👨‍💼 For the Manager:
1. Add new books (title, author, genre, price, quantity, type – physical or e-book).
2. Update book information, including stock quantity.
3. Remove books from the library catalog.
4. View a list of all books (sorted by **price, title, or author**).
5. Generate sales/borrowing reports (daily, weekly, monthly revenue & books issued).

### 👤 For the Customer:
1. Browse catalog by **genre, author, or title**.
2. Add books to the cart and view cart details.
3. Checkout and receive a borrowing/purchase summary.
4. Discounts applied for large purchases (e.g., **15% off above $100**).

---

## 🛠️ Technical Details
- **Language:** C++  
- **Concepts Used:** Arrays, loops, file handling, `switch-case`, `if-else`, input validation.  
- **Type:** Menu-driven program.  

---

## 🧾 Sample Input & Output

**Sample Input:**
- Add a book  
  Title: *The Great Gatsby*  
  Author: *F. Scott Fitzgerald*  
  Genre: *Fiction*  
  Price: 15  
  Quantity: 100  

- Add another book  
  Title: *1984*  
  Author: *George Orwell*  
  Genre: *Dystopian*  
  Price: 12  
  Quantity: 50  

- Browse books by genre → *Fiction*  
- Add *The Great Gatsby* x 2 to cart  
- Proceed to checkout  

**Sample Output:**
===== Library Management System =====

Add New Book

Update Book

Remove Book

View Catalog

Generate Sales Report

Browse Books

Add to Cart

View Cart

Checkout

Exist

=====================================

Enter your choice: 1
Enter Book Title: The Great Gatsby
Enter Author: F. Scott Fitzgerald
Enter Genre: Fiction
Enter Price: 15
Enter Quantity: 100
Book added successfully!

Enter your choice: 1
Enter Book Title: 1984
Enter Author: George Orwell
Enter Genre: Dystopian
Enter Price: 12
Enter Quantity: 50
Book added successfully!

Enter your choice: 4
--- Books in Catalog ---

Title: The Great Gatsby | Author: F. Scott Fitzgerald | Genre: Fiction | Price: $15 | Quantity: 100

Title: 1984 | Author: George Orwell | Genre: Dystopian | Price: $12 | Quantity: 50

Enter your choice: 6
Search by Genre: Fiction
Found Book → The Great Gatsby | Price: $15 | Quantity: 100

Enter your choice: 7
Enter Book Title to Add to Cart: The Great Gatsby
Enter Quantity: 2
Added to cart successfully!

Enter your choice: 9
--- Checkout ---
Books in Cart:

The Great Gatsby x 2 → $30
Total: $30
Discount Applied: 10%
Final Total: $27

Checkout successful. Thank you for using the Library Management System!

