#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("test.txt");
    std::ifstream& f = file;
    if (!f.is_open()) {
        std::cout << "Не удалось открыть файл" << std::endl;
        return 0;
    }
    int a, b;
    if (f >> a >> b) {
        std::cout << "В файле лежат числа "<< a << " и " << b << std::endl;
    } else {
        std::cout << "Что произошло?" << std::endl;
    }
    return 0;
}