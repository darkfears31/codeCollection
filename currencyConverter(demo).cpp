#include <iostream>
#include <curl/curl.h>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <regex>

using namespace std;

// Write callback used by libcurl. Appends received data to the std::string passed via userdata.
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    size_t realSize = size * nmemb; // Calculate real size of incoming data
    string* out = static_cast<string*>(userp); // Cast user pointer to std::string pointer
    out->append(static_cast<char*>(contents), realSize); // Append received data to the string
    return realSize;
}

int main()
{
    CURL* curl = curl_easy_init();
    if (!curl) {
        cerr << "Failed to initialize CURL\n"; 
        return 1;
    } 

    string response; // will hold the full response body

    // Configure curl
    curl_easy_setopt(curl, CURLOPT_URL, "https://latest.currency-api.pages.dev/v1/currencies/eur.json"); // target URL 
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); // follow redirects
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback); // set write callback
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response); // pass string to write callback

    // Perform the request
    CURLcode res = curl_easy_perform(curl); // Execute the configured request
    if (res != CURLE_OK) { //CURLE_OK is an enumerator within the CURLcode enumeration, representing a success status code with a value of 0. It indicates that a cURL operation completed without errors.
        cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << '\n'; // curl_easy_strerror converts CURLcode to a human-readable string.
        curl_easy_cleanup(curl); // Cleanup before returning
        return 1;
    }

    // Cleanup
    curl_easy_cleanup(curl);

    // At this point `response` contains the fetched data as a single string.

    // Split into lines (std::vector<std::string>)
    vector<string> lines;
    {
        istringstream iss(response);
        string line;
        while (getline(iss, line)) {
            lines.push_back(line);
        }
    }
    // Print the lines
   // for(size_t i = 0; i < lines.size(); ++i) {
   //     cout << (i + 1) << ": " << lines[i] << endl;
   // }
    
    char choice;
    do{
        string currency1;
        string currency2;
        cout<<"Which currency do you want to convert? (write in shortened form, ex: 'usd') : ";
        cin>>currency1;
        cout<<endl;
        cout<<currency1<<" TO: ";
        cin>>currency2;
        cout<<endl;
        regex number_regex(R"([-+]?\d*\.?\d+(?:[eE][-+]?\d+)?)"); //to remove everything from string except numbers
        smatch match;
        for(size_t i=0; i<lines.size(); i++){
        size_t found=lines[i].find(currency1);
        if(found != string::npos){
            cout<<currency1<<" found at: "<<found;
        }
        string a = lines[found+1];
        if(regex_search(a, match, number_regex)){
         string num_str=match.str(); //this is the string containing the number
         double num_value = stod(num_str);  // convert string → double
         cout<<num_value<<endl;
        }
        }
        string a = lines[8];


        cout<<"Want to continue converting? (y/n): ";
        cin>>choice;
    }while(choice=='y' || choice =='Y');
    return 0;
}
