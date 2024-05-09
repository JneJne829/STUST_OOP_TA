#include <iostream>
#include <string>

using namespace std;

// 定義一個常量，用於指定庫存中最大的商品數量。
const int MAX_ITEMS = 100;

// 定義一個結構來存儲商品信息。
struct Product {
    string name;  // 商品名稱
    int id;       // 商品編號
    int stock;    // 商品庫存量
};

// 定義一個類來管理商品庫存。
class Inventory {
private:
    Product products[MAX_ITEMS];  // 商品數組，用於存儲庫存中的商品。
    int productCount;             // 當前庫存中的商品數量。

public:
    // 構造函數，初始化商品數量為0。
    Inventory() {
        productCount = 0;
    }

    // 新增商品到庫存中。
    void addProduct(const string& name, int id, int stock) {
        // 檢查庫存是否已滿。
        if (productCount >= MAX_ITEMS) {
            cout << "Inventory full, cannot add more products!" << endl;
            return;
        }
        // 添加商品到數組中並增加商品數量。
        products[productCount].name = name;
        products[productCount].id = id;
        products[productCount].stock = stock;
        productCount++;
    }

    // 通過商品編號刪除商品。
    void deleteProduct(int id) {
        int index = -1;
        // 尋找指定編號的商品。
        for (int i = 0; i < productCount; i++) {
            if (products[i].id == id) {
                index = i;
                break;
            }
        }
        // 如果找到，從數組中刪除商品。
        if (index != -1) {
            for (int i = index; i < productCount - 1; i++) {
                products[i] = products[i + 1];
            }
            productCount--;
            cout << "Product deleted" << endl;
        } else {
            cout << "Product not found" << endl;
        }
    }

    // 更新指定商品的庫存量。
    void updateStock(int id, int newStock) {
        // 尋找並更新庫存。
        for (int i = 0; i < productCount; i++) {
            if (products[i].id == id) {
                products[i].stock = newStock;
                cout << "Stock updated" << endl;
                return;
            }
        }
        cout << "Product not found" << endl;
    }

    // 查詢指定商品的信息。
    void queryProduct(int id) {
        // 尋找並顯示商品信息。
        for (int i = 0; i < productCount; i++) {
            if (products[i].id == id) {
                cout << "Product Name: " << products[i].name << ", Stock: " << products[i].stock << endl;
                return;
            }
        }
        cout << "Product not found" << endl;
    }

    // 列印所有商品的信息。
    void printAllProducts() {
        // 檢查庫存是否為空。
        if (productCount == 0) {
            cout << "No products in stock." << endl;
            return;
        }
        // 逐個列印商品信息。
        for (int i = 0; i < productCount; i++) {
            cout << "Product Name: " << products[i].name << ", Product ID: " << products[i].id << ", Stock: " << products[i].stock << endl;
        }
    }
};

int main() {
    // 創建庫存管理對象。
    Inventory inventory;
    // 添加幾個商品。
    inventory.addProduct("Apple", 1, 30);
    inventory.addProduct("Orange", 2, 20);

    // 列印所有商品信息。
    inventory.printAllProducts();

    // 更新並查詢商品。
    inventory.updateStock(1, 25);
    inventory.queryProduct(1);

    // 刪除商品並再次列印所有商品信息。
    inventory.deleteProduct(2);
    inventory.printAllProducts();

    return 0;
}
