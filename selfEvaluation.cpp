#include <bits/stdc++.h>

using namespace std;
void judge(string result, string o){
    // Open the result file
    ifstream result_file(result);
    ifstream real_output(o);
    string expected_output, output;
    cout<<o<<"  : ";
    while(getline(result_file, expected_output)){
        getline(real_output, output);
        if(output != expected_output){
            cout << "Failed" << endl;
            result_file.close();
            real_output.close();
            return;
        }
    }
    cout << "AC" << endl;
    result_file.close();
    real_output.close();
    return;
}
int main() {
    // Define the input and output directories; some of you may need change the \\ to /
    string input_dir = ".\\inputs\\";
    string output_dir = ".\\outputs\\";
    string result_dir = ".\\results\\";
    string code_dir = ".\\code\\";
    // Get a list of all the input files
    vector<string> input_files;
    
    for(const auto & entry : filesystem::directory_iterator(input_dir)){
         if (entry.path().extension() == ".txt"){
            input_files.push_back(entry.path().filename().string());
         }
    }
    // Compile the C++ code
    string command = "gcc -o " + code_dir + "PROGRAM.exe " + code_dir + "*.c";
    system(command.c_str());
    // Loop through the input files
    for (int i = 0; i < input_files.size(); i++) {
        // Run the program with the input file and capture the output
        command = code_dir + "PROGRAM.exe < " + input_dir + input_files[i];
        string output = output_dir + input_files[i];
        command = command + " > " + output;
        system(command.c_str());
        
        // Compare the output with the expected output
        judge(result_dir + input_files[i], output); 
        
    }

    system("pause");
    return 0;
}
