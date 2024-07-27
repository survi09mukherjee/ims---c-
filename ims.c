#include <iostream>
#include <vector>
#include <string>

struct Product {
    std::string name;
    int quantity;
    double price;
};

class Inventory {
private:
    std::vector<Product> products;

public:
    void addProduct(const std::string& name, int quantity, double price) {
        for (auto& product : products) {
            if (product.name == name) {
                product.quantity += quantity;
                product.price = price;
                return;
            }
        }
        products.push_back({name, quantity, price});
    }

    void updateProduct(const std::string& name, int quantity, double price) {
        for (auto& product : products) {
            if (product.name == name) {
                product.quantity = quantity;
                product.price = price;
                return;
            }
        }
        std::cout << "Product not found.\n";
    }

    void checkStock() const {
        std::cout << "Inventory Stock:\n";
        for (const auto& product : products) {
            std::cout << "Product: " << product.name
                      << ", Quantity: " << product.quantity
                      << ", Price: $" << product.price << '\n';
        }
    }

    void generateReport() const {
        std::cout << "\nInventory Report:\n";
        for (const auto& product : products) {
            std::cout << "Product: " << product.name
                      << ", Quantity: " << product.quantity
                      << ", Total Value: $" << product.quantity * product.price << '\n';
        }
    }
};

int main() {
    Inventory inventory;

    inventory.addProduct("Laptop", 10, 999.99);
    inventory.addProduct("Smartphone", 15, 599.99);
    inventory.updateProduct("Laptop", 5, 899.99);
    
    inventory.checkStock();
    inventory.generateReport();

    return 0;
}
