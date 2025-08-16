#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_BOOKS = 100; // Maximum number of books
const int MAX_CART = 100;  // Maximum number of items in the cart

// Arrays to store book details
string titles[MAX_BOOKS];
string authors[MAX_BOOKS];
string genres[MAX_BOOKS];
double prices[MAX_BOOKS];
int quantities[MAX_BOOKS];
int catalogSize = 0;

// Arrays for the cart
string cartTitles[MAX_CART];
double cartPrices[MAX_CART];
int cartQuantities[MAX_CART];
int cartSize = 0;

double totalRevenue = 0.0; // Total revenue from sales

int main() {
    string userType;

    while (true) {
        cout << "\nAre you a manager or a customer? (Enter 'manager', 'customer', or 'exit'): ";
        cin >> userType;

        if (userType == "exit") {
            cout << "Exiting program. Total revenue: " << totalRevenue << "\n";
            break;
        }

        if (userType == "manager") {
            int choice;
            while (true) {
                cout << "\n Manager Menu \n";
                cout << "1. Add a book\n";
                cout << "2. View all books\n";
                cout << "3. Remove a book\n";
                cout << "4. Update book information\n";
                cout << "5. Update book quantity\n";
                cout << "6. Generate sales report\n";
                cout << "7. Exit to main menu\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                case 1: // Add a book
                    if (catalogSize < MAX_BOOKS) {
                        cin.ignore();
                        cout << "Enter book title: ";
                        getline(cin, titles[catalogSize]);
                        cout << "Enter author: ";
                        getline(cin, authors[catalogSize]);
                        cout << "Enter genre: ";
                        getline(cin, genres[catalogSize]);
                        cout << "Enter price: $";
                        cin >> prices[catalogSize];
                        cout << "Enter quantity: ";
                        cin >> quantities[catalogSize];
                        catalogSize++;
                        cout << "Book added successfully.\n";
                    }
                    else {
                        cout << "Catalog is full. Cannot add more books.\n";
                    }
                    break;

                case 2: // View all books
                    if (catalogSize == 0) {
                        cout << "No books available in the catalog.\n";
                    }
                    else {
                        cout << "\n Books in Catalog \n";
                        for (int i = 0; i < catalogSize; ++i) {
                            cout << i + 1 << ". Title: " << titles[i]
                                << " | Author: " << authors[i]
                                << " | Genre: " << genres[i]
                                << " | Price: $" << fixed << setprecision(2) << prices[i]
                                << " | Quantity: " << quantities[i] << "\n";
                        }
                    }
                    break;

                case 3: // Remove a book
                    if (catalogSize == 0) {
                        cout << "No books available to remove.\n";
                    }
                    else {
                        cout << "Enter the number of the book to remove (1 to " << catalogSize << "): ";
                        int bookIndex;
                        cin >> bookIndex;
                        bookIndex -- ; // Convert to zero-based index

                        if (bookIndex >= 0 && bookIndex < catalogSize) {
                            for (int i = bookIndex; i < catalogSize - 1; ++i) {
                                titles[i] = titles[i + 1];
                                authors[i] = authors[i + 1];
                                genres[i] = genres[i + 1];
                                prices[i] = prices[i + 1];
                                quantities[i] = quantities[i + 1];
                            }
                            catalogSize--;
                            cout << "Book removed successfully.\n";
                        }
                        else {
                            cout << "Invalid book number.\n";
                        }
                    }
                    break;

                case 4: // Update book information
                    if (catalogSize == 0) {
                        cout << "No books available to update.\n";
                    }
                    else {
                        cout << "Enter the number of the book to update (1 to " << catalogSize << "): ";
                        int bookIndex;
                        cin >> bookIndex;
                        bookIndex--; // Convert to zero-based index

                        if (bookIndex >= 0 && bookIndex < catalogSize) {
                            cin.ignore();
                            cout << "Enter new title: ";
                            getline(cin, titles[bookIndex]);
                            cout << "Enter new author: ";
                            getline(cin, authors[bookIndex]);
                            cout << "Enter new genre: ";
                            getline(cin, genres[bookIndex]);
                            cout << "Enter new price: $";
                            cin >> prices[bookIndex];
                            cout << "Book information updated successfully.\n";
                        }
                        else {
                            cout << "Invalid book number.\n";
                        }
                    }
                    break;

                case 5: // Update book quantity
                    if (catalogSize == 0) {
                        cout << "No books available to update quantity.\n";
                    }
                    else {
                        cout << "Enter the number of the book to update quantity (1 to " << catalogSize << "): ";
                        int bookIndex;
                        cin >> bookIndex;
                        bookIndex--; // Convert to zero-based index

                        if (bookIndex >= 0 && bookIndex < catalogSize) {
                            int newQuantity;
                            cout << "Enter new quantity for '" << titles[bookIndex] << "': ";
                            cin >> newQuantity;
                            quantities[bookIndex] = newQuantity;
                            cout << "Book quantity updated successfully.\n";
                        }
                        else {
                            cout << "Invalid book number.\n";
                        }
                    }
                    break;

                case 6: // Generate sales report
                    cout << "\n===== Sales Report =====\n";
                    cout << "Total Revenue: $" << fixed << setprecision(2) << totalRevenue << "\n";
                    break;

                case 7: // Exit to main menu
                    goto MainMenu;

                default:
                    cout << "Invalid choice. Please try again.\n";
                    break;
                }
            }
        }

        else if (userType == "customer") {
            int choice;
            while (true) {
                cout << "\n===== Customer Menu =====\n";
                cout << "1. Browse books\n";
                cout << "2. Add to cart\n";
                cout << "3. View cart\n";
                cout << "4. Checkout\n";
                cout << "5. Exit to main menu\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                case 1: // Browse books
                    if (catalogSize == 0) {
                        cout << "No books available in the catalog.\n";
                    }
                    else {
                        cout << "\n===== Books in Catalog =====\n";
                        for (int i = 0; i < catalogSize; ++i) {
                            cout << i + 1 << ". Title: " << titles[i]
                                << " | Author: " << authors[i]
                                << " | Genre: " << genres[i]
                                << " | Price: $" << fixed << setprecision(2) << prices[i]
                                << " | Quantity: " << quantities[i] << "\n";
                        }
                    }
                    break;

                case 2: // Add to cart
                    if (catalogSize == 0) {
                        cout << "No books available in the catalog to add to the cart.\n";
                    }
                    else {
                        cout << "Enter the number of the book to add to the cart (1 to " << catalogSize << "): ";
                        int bookIndex;
                        cin >> bookIndex;
                        bookIndex--; // Convert to zero-based index

                        if (bookIndex >= 0 && bookIndex < catalogSize) {
                            if (quantities[bookIndex] > 0) {
                                cartTitles[cartSize] = titles[bookIndex];
                                cartPrices[cartSize] = prices[bookIndex];
                                cartQuantities[cartSize] = 1;
                                cartSize++;
                                quantities[bookIndex]--;
                                cout << "Book added to cart.\n";
                            }
                            else {
                                cout << "Book is out of stock.\n";
                            }
                        }
                        else {
                            cout << "Invalid book number.\n";
                        }
                    }
                    break;

                case 3: // View cart
                    if (cartSize == 0) {
                        cout << "Your cart is empty.\n";
                    }
                    else {
                        cout << "\n===== Books in Cart =====\n";
                        double total = 0.0;
                        for (int i = 0; i < cartSize; ++i) {
                            cout << i + 1 << ". Title: " << cartTitles[i]
                                << " | Price: $" << fixed << setprecision(2) << cartPrices[i]
                                << " | Quantity: " << cartQuantities[i] << "\n";
                            total += cartPrices[i] * cartQuantities[i];
                        }
                        cout << "Total: $" << total << "\n";
                    }
                    break;

                case 4: // Checkout
                    if (cartSize == 0) {
                        cout << "Your cart is empty. Add books to cart before checkout.\n";
                    }
                    else {
                        double total = 0.0;
                        for (int i = 0; i < cartSize; ++i) {
                            total += cartPrices[i] * cartQuantities[i];
                        }

                        cout << "Total before discount: $" << fixed << setprecision(2) << total << "\n";

                        if (total > 100) {
                            double discount = total * 0.15;
                            total -= discount;
                            cout << "Discount applied: $" << discount << "\n";
                        }

                        cout << "Final total: $" << total << "\n";
                        totalRevenue += total;
                        cartSize = 0; // Clear the cart
                        cout << "Checkout successful. Thank you for your purchase!\n";
                    }
                    break;

                case 5: // Exit to main menu
                    goto MainMenu;

                default:
                    cout << "Invalid choice. Please try again.\n";
                    break;
                }
            }
        }

        else {
            cout << "Invalid input. Please enter 'manager', 'customer', or 'exit'.\n";
        }

    MainMenu:;
    }

    return 0;
}

































































