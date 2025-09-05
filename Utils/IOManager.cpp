#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class IOManager {
private:
    string problemPath;
    
public:
    IOManager(const string& path) : problemPath(path) {}
    
    // 從 console 讀取輸入並儲存到檔案
    void captureInput() {
        cout << "=== Input Capture ===" << endl;
        cout << "Paste your input from uDebug (press Ctrl+Z then Enter to finish on Windows):" << endl;
        
        string input, line;
        while (getline(cin, line)) {
            input += line + "\n";
        }
        
        // 清除 EOF 狀態
        cin.clear();
        
        // 儲存到 input.txt
        ofstream inputFile(problemPath + "/input.txt");
        inputFile << input;
        inputFile.close();
        
        cout << "Input saved to " << problemPath << "/input.txt" << endl;
    }
    
    // 從 console 讀取預期輸出並儲存到檔案
    void captureExpectedOutput() {
        cout << "\n=== Expected Output Capture ===" << endl;
        cout << "Paste expected output from uDebug (press Ctrl+Z then Enter to finish):" << endl;
        
        string expected, line;
        while (getline(cin, line)) {
            expected += line + "\n";
        }
        
        // 清除 EOF 狀態
        cin.clear();
        
        // 儲存到 expected.txt
        ofstream expectedFile(problemPath + "/expected.txt");
        expectedFile << expected;
        expectedFile.close();
        
        cout << "Expected output saved to " << problemPath << "/expected.txt" << endl;
    }
    
    // 顯示輸出結果
    void showOutput() {
        cout << "\n=== Actual Output ===" << endl;
        ifstream outputFile(problemPath + "/output.txt");
        if (outputFile.is_open()) {
            string line;
            while (getline(outputFile, line)) {
                cout << line << endl;
            }
            outputFile.close();
        } else {
            cout << "No output file found. Run the solution first." << endl;
        }
    }
    
    // 比較輸出
    void compareOutputs() {
        ifstream actualFile(problemPath + "/output.txt");
        ifstream expectedFile(problemPath + "/expected.txt");
        
        if (!actualFile.is_open()) {
            cout << "No actual output file found." << endl;
            return;
        }
        
        if (!expectedFile.is_open()) {
            cout << "No expected output file found." << endl;
            return;
        }
        
        string actualContent, expectedContent, line;
        
        while (getline(actualFile, line)) {
            actualContent += line + "\n";
        }
        
        while (getline(expectedFile, line)) {
            expectedContent += line + "\n";
        }
        
        // 移除尾部空白
        auto trim = [](string str) {
            str.erase(str.find_last_not_of(" \t\r\n") + 1);
            return str;
        };
        
        if (trim(actualContent) == trim(expectedContent)) {
            cout << "\n✓ Output matches expected result!" << endl;
        } else {
            cout << "\n✗ Output does not match expected result!" << endl;
            cout << "\nActual:" << endl;
            cout << actualContent << endl;
            cout << "Expected:" << endl;
            cout << expectedContent << endl;
        }
    }
};

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: IOManager <problem_path>" << endl;
        cout << "Example: IOManager Problems/UVA_100" << endl;
        return 1;
    }
    
    IOManager manager(argv[1]);
    
    int choice;
    do {
        cout << "\n=== IO Manager ===" << endl;
        cout << "1. Capture Input (from uDebug)" << endl;
        cout << "2. Capture Expected Output (from uDebug)" << endl;
        cout << "3. Show Actual Output" << endl;
        cout << "4. Compare Outputs" << endl;
        cout << "0. Exit" << endl;
        cout << "Choice: ";
        
        cin >> choice;
        cin.ignore(); // 忽略換行符
        
        switch (choice) {
            case 1:
                manager.captureInput();
                break;
            case 2:
                manager.captureExpectedOutput();
                break;
            case 3:
                manager.showOutput();
                break;
            case 4:
                manager.compareOutputs();
                break;
            case 0:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);
    
    return 0;
}
