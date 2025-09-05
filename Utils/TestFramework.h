#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

class TestFramework {
private:
    std::string problemPath;
    std::string inputContent;
    std::string expectedOutput;
    
public:
    TestFramework(const std::string& path) : problemPath(path) {}
    
    // 設定輸入內容（從 uDebug 複製貼上）
    void setInput(const std::string& input) {
        inputContent = input;
        // 寫入到 input.txt
        std::ofstream inputFile(problemPath + "/input.txt");
        inputFile << input;
        inputFile.close();
    }
    
    // 從檔案讀取輸入
    void loadInputFromFile(const std::string& filename = "input1.txt") {
        std::ifstream file(problemPath + "/" + filename);
        if (file.is_open()) {
            std::string line;
            inputContent = "";
            while (std::getline(file, line)) {
                inputContent += line + "\n";
            }
            file.close();
            setInput(inputContent);
        }
    }
    
    // 設定預期輸出（從 uDebug 複製貼上）
    void setExpectedOutput(const std::string& expected) {
        expectedOutput = expected;
        // 寫入到 expected.txt
        std::ofstream expectedFile(problemPath + "/expected.txt");
        expectedFile << expected;
        expectedFile.close();
    }
    
    // 執行解題程式並捕獲輸出
    std::string runSolution() {
        // 重新導向標準輸入輸出
        std::streambuf* cinBackup = std::cin.rdbuf();
        std::streambuf* coutBackup = std::cout.rdbuf();
        
        std::istringstream inputStream(inputContent);
        std::ostringstream outputStream;
        
        std::cin.rdbuf(inputStream.rdbuf());
        std::cout.rdbuf(outputStream.rdbuf());
        
        // 呼叫解題函數
        solveProblem();
        
        // 恢復標準輸入輸出
        std::cin.rdbuf(cinBackup);
        std::cout.rdbuf(coutBackup);
        
        std::string result = outputStream.str();
        
        // 寫入到 output.txt
        std::ofstream outputFile(problemPath + "/output.txt");
        outputFile << result;
        outputFile.close();
        
        return result;
    }
    
    // 比較輸出結果
    bool compareOutput(const std::string& actual, const std::string& expected) {
        // 移除行尾空白和多餘換行
        auto trim = [](std::string str) {
            // 移除尾部空白
            str.erase(str.find_last_not_of(" \t\r\n") + 1);
            return str;
        };
        
        return trim(actual) == trim(expected);
    }
    
    // 執行完整測試
    void runTest() {
        std::cout << "=== Testing Problem ===" << std::endl;
        std::cout << "Input:" << std::endl;
        std::cout << inputContent << std::endl;
        
        std::string actualOutput = runSolution();
        
        std::cout << "Actual Output:" << std::endl;
        std::cout << actualOutput << std::endl;
        
        if (!expectedOutput.empty()) {
            std::cout << "Expected Output:" << std::endl;
            std::cout << expectedOutput << std::endl;
            
            if (compareOutput(actualOutput, expectedOutput)) {
                std::cout << "✓ Test PASSED!" << std::endl;
            } else {
                std::cout << "✗ Test FAILED!" << std::endl;
            }
        }
        
        std::cout << "===================" << std::endl;
    }
    
    // 這個函數需要在 solution.cpp 中實作
    virtual void solveProblem() = 0;
};
